#pragma once
#include <LibD3D11.h>
#include "ImGuiDoubleBuffering.h"

//! An ImGui renderer that uses direct D3D11 calls. Uses CryEngine's ITexture* as ImTextureID.
class ImGuiRendererD3D11
{
public:
	//! Draws the specified draw buffer into currently attached framebuffer. Must be called on the render thread.
	void RT_Render(ImRendDrawBuffer& buffer, const wchar_t* eventName);

private:
	//! The GPU buffers will be incremented by this many elements on resize.
	static constexpr int BUFFER_SIZE_INCREMENT = 5000;

	struct VertexConstantBuffer
	{
		float   mvp[4][4];
	};

	bool m_bInitialized = false;
	ID3DUserDefinedAnnotation* m_pAnnot = nullptr;
	ID3D11Buffer* m_pVB = nullptr;
	ID3D11Buffer* m_pIB = nullptr;
	ID3D11VertexShader* m_pVertexShader = nullptr;
	ID3D11InputLayout* m_pInputLayout = nullptr;
	ID3D11Buffer* m_pVertexConstantBuffer = nullptr;
	ID3D11PixelShader* m_pPixelShader = nullptr;
	ID3D11SamplerState* m_pFontSampler = nullptr;
	ID3D11ShaderResourceView* m_pFontTextureView = nullptr;
	ID3D11RasterizerState* m_pRasterizerState = nullptr;
	ID3D11BlendState* m_pBlendState = nullptr;
	ID3D11DepthStencilState* m_pDepthStencilState = nullptr;
	int m_VertexBufferSize = BUFFER_SIZE_INCREMENT;
	int m_IndexBufferSize = BUFFER_SIZE_INCREMENT;

	bool RT_Initialize();
	void RT_SetupRenderState(ImRendDrawBuffer& buffer);
};
