#ifndef __FONT_H__
#define __FONT_H__

/** INCLUDES **/
#include <string>
#include <d3d9.h>
#include <d3dx9core.h>
#include "Color.h"

/** DEFINES **/
enum FontStyle
{
	FONT_STYLE_NORMAL = 0,
	FONT_STYLE_BOLD = 1,
	FONT_STYLE_ITALIC = 2
};

/** CLASSES **/
/* Font */
class Font
{
public:
	Font(IDirect3DDevice9 *d3d9_device, std::wstring font_name, int font_size, DWORD font_flags);
	~Font();

	void on_reset();

	void pre_frame();
	void post_frame();

	void draw_text(std::wstring text, int x, int y, Color color);

private:
	IDirect3DDevice9 *d3d9_device;
	ID3DXFont *d3dx9_font;

	std::wstring font_name;
	int font_size;
	DWORD font_flags;
};

#endif