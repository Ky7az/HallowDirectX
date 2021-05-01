#ifndef __D3D9PRIMITIVE_H__
#define __D3D9PRIMITIVE_H__

/** INCLUDES **/
#include <d3d9.h>
#include <d3dx9core.h>

/** DEFINES **/
typedef struct _CUSTOMVERTEX
{
	float x, y, z;
	DWORD color;

} CUSTOMVERTEX;

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)

/** CLASSES **/
/* D3D9Primitive */
class D3D9Primitive
{
public:
	D3D9Primitive();
	~D3D9Primitive();

	IDirect3DDevice9* get_d3d9_device() const;

	void on_setup(IDirect3DDevice9 *d3d9_device);

	void init();
	void render();

private:
	IDirect3DDevice9 *d3d9_device;
	IDirect3DVertexBuffer9 *vb;
	IDirect3DIndexBuffer9 *ib;
};

#endif