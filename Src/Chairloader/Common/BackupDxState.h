#pragma once
#include <LibD3D11.h>

struct BackupDxState
{
	UINT                        ScissorRectsCount, ViewportsCount;
	D3D11_RECT                  ScissorRects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
	D3D11_VIEWPORT              Viewports[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
	ID3D11RasterizerState* RS;
	ID3D11BlendState* BlendState;
	FLOAT                       BlendFactor[4];
	UINT                        SampleMask;
	UINT                        StencilRef;
	ID3D11DepthStencilState* DepthStencilState;
	ID3D11ShaderResourceView* PSShaderResource;
	ID3D11SamplerState* PSSampler;
	ID3D11PixelShader* PS;
	ID3D11VertexShader* VS;
	ID3D11GeometryShader* GS;
	UINT                        PSInstancesCount, VSInstancesCount, GSInstancesCount;
	ID3D11ClassInstance* PSInstances[256], * VSInstances[256], * GSInstances[256];   // 256 is max according to PSSetShader documentation
	D3D11_PRIMITIVE_TOPOLOGY    PrimitiveTopology;
	ID3D11Buffer* IndexBuffer, * VertexBuffer, * VSConstantBuffer;
	UINT                        IndexBufferOffset, VertexBufferStride, VertexBufferOffset;
	DXGI_FORMAT                 IndexBufferFormat;
	ID3D11InputLayout* InputLayout;

	void Backup(ID3D11DeviceContext* ctx);
	void Restore(ID3D11DeviceContext* ctx);
};
