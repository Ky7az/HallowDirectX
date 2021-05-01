#ifndef __RENDERER_H__
#define __RENDERER_H__

/** INCLUDES **/
#include <iostream>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <time.h> 
#include <d3d9.h>
#pragma comment (lib, "d3dx9")
#include <d3dx9core.h>
#include <DirectXMath.h>
#include "Color.h"
#include "Font.h"

/** DEFINES **/
struct CustomVertex
{
	float x, y, z, rhw;
	D3DCOLOR color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

/** CLASSES **/
/* Renderer */
class Renderer
{
public:
	Renderer();
	~Renderer();

	IDirect3DDevice9* get_d3d9_device() const;

	void on_setup(IDirect3DDevice9 *d3d9_device);
	void on_reset();

	void pre_frame();
	void post_frame();

	void register_font(std::wstring font_name, int font_size, DWORD font_flags = FONT_STYLE_NORMAL);

	void draw_text(std::wstring text, int x, int y, Color color);
	void draw_line(int x, int y, int w, Color color);
	void draw_rect1(int x, int y, int w, int h, Color color);
	void draw_rect2(int x1, int y1, int x2, int y2, Color color);
	void draw_rect3(int x, int y, int w, int h, Color color);
	void draw_circle(int x, int y, int radius, int num_sides, Color color);
	void draw_crosshair(int screen_w, int screen_h, Color color);

	int frame_rate();

private:
	IDirect3DDevice9 *d3d9_device;
	ID3DXLine *d3d9_line;
	Font *font;
	DWORD old_fvf;
};

#endif