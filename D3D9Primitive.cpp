#include "D3D9Primitive.h"
using namespace std;

D3D9Primitive::D3D9Primitive()
{
	d3d9_device = NULL;
	vb = NULL;
	ib = NULL;
}

D3D9Primitive::~D3D9Primitive()
{
}

IDirect3DDevice9* D3D9Primitive::get_d3d9_device() const { return d3d9_device; }

void D3D9Primitive::on_setup(IDirect3DDevice9 *d3d9_device)
{
	this->d3d9_device = d3d9_device;
	d3d9_device->CreateVertexBuffer(4 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_MANAGED, &vb, NULL);
	//d3d9_device->CreateIndexBuffer(4 * sizeof(short), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &ib, NULL);
	init();
}

void D3D9Primitive::init()
{
	if (d3d9_device == NULL)
		return;

	CUSTOMVERTEX vertices[] = {
		{ -3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 3.0f, 3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ -3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(255, 0, 0), },
		{ 3.0f, -3.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 255), }
	};

	//short indices[] = { 0, 1, 2, 3 };

	CUSTOMVERTEX *vb_data;
	vb->Lock(0, 0, (void**)&vb_data, 0);
	memcpy(vb_data, vertices, sizeof(vertices));
	vb->Unlock();

	/*short *ib_data = NULL;
	ib->Lock(0, 0, (void**)&ib_data, 0);
	memcpy(ib_data, indices, sizeof(indices));
	ib->Unlock();*/
}

void D3D9Primitive::render()
{
	if (d3d9_device == NULL)
		return;

	//d3d9_device->SetPixelShader(NULL);
	//d3d9_device->SetVertexShader(NULL);
	//d3d9_device->SetFVF(D3DFVF_CUSTOMVERTEX);

	d3d9_device->SetStreamSource(0, vb, 0, sizeof(CUSTOMVERTEX));
	//d3d9_device->SetIndices(ib);

	d3d9_device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	//d3d9_device->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, 4, 0, 2);
}