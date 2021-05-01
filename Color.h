#ifndef __COLOR_H__
#define __COLOR_H__

/** INCLUDES **/
#include <d3d9.h>

/** DEFINES **/

/** CLASSES **/
/* Color */
class Color
{
public:
	Color()
	{
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->a = 0;
		this->rgba = 0;
	}

	Color(byte r, byte g, byte b, byte a = 255)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
		this->rgba = D3DCOLOR_RGBA(r, g, b, a);
	}

	Color(D3DCOLOR rgba) { this->rgba = rgba; }

	byte R() const { return r; }
	byte G() const { return g; }
	byte B() const { return b; }
	byte A() const { return a; }
	D3DCOLOR RGBA() const { return rgba; }

	static Color Black() { return Color(0, 0, 0); }
	static Color White() { return Color(255, 255, 255); }
	static Color Purple() { return Color(153, 50, 204); }

private:
	byte r, g, b, a;
	D3DCOLOR rgba;
};

#endif