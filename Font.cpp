#include "Font.h"
using namespace std;

/* Font */
Font::Font(IDirect3DDevice9 *d3d9_device, std::wstring font_name, int font_size, DWORD font_flags)
{
	this->d3d9_device = d3d9_device;
	this->d3dx9_font = NULL;
	
	this->font_name = font_name;
	this->font_size = font_size;
	this->font_flags = font_flags;
}

Font::~Font()
{
	if (d3dx9_font) {
		d3dx9_font->Release();
		d3dx9_font = NULL;
	}
}

void Font::on_reset()
{
	if (d3dx9_font) {
		d3dx9_font->OnLostDevice();
		d3dx9_font->OnResetDevice();
	}
}

void Font::pre_frame()
{
 	if (!d3d9_device)
		return;

	if (!d3dx9_font) {
		UINT weight = (font_flags & FONT_STYLE_BOLD) ? FW_BOLD : FW_NORMAL;
		BOOL italic = (font_flags & FONT_STYLE_ITALIC) ? TRUE : FALSE;

		D3DXCreateFont(d3d9_device,
			font_size,
			NULL,
			weight,
			NULL,
			italic,
			DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			font_name.c_str(),
			&d3dx9_font);
	}
}

void Font::post_frame()
{
	if (!d3d9_device)
		return;
}

void Font::draw_text(wstring text, int x, int y, Color color)
{
	if (!d3d9_device)
		return;
	if (!d3dx9_font)
		return;
	if (text.empty())
		return;

	RECT rect = { x, y, 0, 0 };
	d3dx9_font->DrawText(0, text.c_str(), -1, &rect, DT_NOCLIP, color.RGBA());
}