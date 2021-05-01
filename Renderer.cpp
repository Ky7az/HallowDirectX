#include "Renderer.h"
using namespace std;

/* Renderer */
Renderer::Renderer() 
{
	d3d9_device = NULL;
	d3d9_line = NULL;
	font = NULL;
}

Renderer::~Renderer()
{
}

IDirect3DDevice9* Renderer::get_d3d9_device() const { return d3d9_device; }

void Renderer::on_setup(IDirect3DDevice9 *d3d9_device)
{
	this->d3d9_device = d3d9_device;
	D3DXCreateLine(d3d9_device, &d3d9_line);
}

void Renderer::on_reset()
{
	if (font)
		font->on_reset();
}

void Renderer::pre_frame()
{
	if (font)
		font->pre_frame();
}

void Renderer::post_frame()
{
	if (font)
		font->post_frame();
}

void Renderer::register_font(wstring font_name, int font_size, DWORD font_flags)
{
	if (d3d9_device == NULL)
		return;

	font = new Font(d3d9_device, font_name, font_size, font_flags);
}

void Renderer::draw_text(wstring text, int x, int y, Color color)
{
 	if (font)
		font->draw_text(text, x, y, color);
}

void Renderer::draw_line(int x, int y, int w, Color color)
{
	if (d3d9_device == NULL)
		return;

	D3DRECT rect_bar = { x - w, y, x + w, y + 1 };
	d3d9_device->Clear(1, &rect_bar, D3DCLEAR_TARGET, color.RGBA(), 0, 0);
}

void Renderer::draw_rect1(int x, int y, int w, int h, Color color)
{
	if (d3d9_device == NULL)
		return;

	D3DRECT rect_bar = { x, y, x + w, y + h };
	d3d9_device->Clear(1, &rect_bar, D3DCLEAR_TARGET, color.RGBA(), 0, 0);
}

void Renderer::draw_rect2(int x1, int y1, int x2, int y2, Color color)
{
	if (d3d9_device == NULL)
		return;

	D3DRECT rect_bar = { x1, y1, x2, y2 };
	d3d9_device->Clear(1, &rect_bar, D3DCLEAR_TARGET, color.RGBA(), 0, 0);
}

void Renderer::draw_rect3(int x, int y, int w, int h, Color color)
{
	if (d3d9_device == NULL)
		return;

	CustomVertex vertices[4] = {
		{ x, y + h, 0.0f, 1.0f, color.RGBA() },
		{ x, y, 0.0f, 1.0f, color.RGBA() },
		{ x + w, y + h, 0.0f, 1.0f, color.RGBA() },
		{ x + w, y, 0.0f, 1.0f, color.RGBA() }
	};

	d3d9_device->GetFVF(&old_fvf);

	d3d9_device->SetFVF(D3DFVF_CUSTOMVERTEX);
	d3d9_device->SetTexture(0, NULL);
	d3d9_device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertices, sizeof(CustomVertex));

	d3d9_device->SetFVF(old_fvf);
}

void Renderer::draw_circle(int x, int y, int radius, int num_sides, Color color) // ID3DXLine *d3d9_line, 
{
	if (d3d9_device == NULL)
		return;

	if (d3d9_line == NULL)
		return;

	D3DXVECTOR2 line[128];
	float smthness = M_PI*2.0 / num_sides;
	int cnt = 0;

	for (float ang = 0.f; ang <= M_PI*2.0f; ang += smthness)
	{
		float x1 = radius * cos(ang) + x;
		float y1 = radius * sin(ang) + y;
		float x2 = radius * cos(ang + smthness) + x;
		float y2 = radius * sin(ang + smthness) + y;

		line[cnt].x = x1;
		line[cnt].y = y1;
		line[cnt + 1].x = x2;
		line[cnt + 1].y = y2;

		cnt += 2;
	}

	d3d9_line->Begin();
	d3d9_line->Draw(line, cnt, color.RGBA());
	d3d9_line->End();
}

void Renderer::draw_crosshair(int screen_w, int screen_h, Color color)
{
	if (d3d9_device == NULL)
		return;

	int x = (screen_w / 2) - 1;
	int y = (screen_h / 2) - 1;

	D3DRECT rect1 = { x - 10, y, x + 10, y + 1 };
	D3DRECT rect2 = { x, y - 10, x + 1, y + 10 };

	d3d9_device->Clear(1, &rect1, D3DCLEAR_TARGET, color.RGBA(), 0, 0);
	d3d9_device->Clear(1, &rect2, D3DCLEAR_TARGET, color.RGBA(), 0, 0);
}

int Renderer::frame_rate()
{
	static int fps, last_fps;
	static float last_tick_count, tick_count;

	tick_count = clock() * 0.001f;
	fps++;

	if ((tick_count - last_tick_count) >= 1.0f) {
		last_tick_count = tick_count;
		last_fps = fps;
		fps = 0;
	}

	return last_fps;
}