#include "BackupDxState.h"

void BackupDxState::Backup(ID3D11DeviceContext* ctx)
{
	this->ScissorRectsCount = this->ViewportsCount = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
	ctx->RSGetScissorRects(&this->ScissorRectsCount, this->ScissorRects);
	ctx->RSGetViewports(&this->ViewportsCount, this->Viewports);
	ctx->RSGetState(&this->RS);
	ctx->OMGetBlendState(&this->BlendState, this->BlendFactor, &this->SampleMask);
	ctx->OMGetDepthStencilState(&this->DepthStencilState, &this->StencilRef);
	ctx->PSGetShaderResources(0, 1, &this->PSShaderResource);
	ctx->PSGetSamplers(0, 1, &this->PSSampler);
	this->PSInstancesCount = this->VSInstancesCount = this->GSInstancesCount = 256;
	ctx->PSGetShader(&this->PS, this->PSInstances, &this->PSInstancesCount);
	ctx->VSGetShader(&this->VS, this->VSInstances, &this->VSInstancesCount);
	ctx->VSGetConstantBuffers(0, 1, &this->VSConstantBuffer);
	ctx->GSGetShader(&this->GS, this->GSInstances, &this->GSInstancesCount);

	ctx->IAGetPrimitiveTopology(&this->PrimitiveTopology);
	ctx->IAGetIndexBuffer(&this->IndexBuffer, &this->IndexBufferFormat, &this->IndexBufferOffset);
	ctx->IAGetVertexBuffers(0, 1, &this->VertexBuffer, &this->VertexBufferStride, &this->VertexBufferOffset);
	ctx->IAGetInputLayout(&this->InputLayout);
}

void BackupDxState::Restore(ID3D11DeviceContext* ctx)
{
	ctx->RSSetScissorRects(this->ScissorRectsCount, this->ScissorRects);
	ctx->RSSetViewports(this->ViewportsCount, this->Viewports);
	ctx->RSSetState(this->RS); if (this->RS) this->RS->Release();
	ctx->OMSetBlendState(this->BlendState, this->BlendFactor, this->SampleMask); if (this->BlendState) this->BlendState->Release();
	ctx->OMSetDepthStencilState(this->DepthStencilState, this->StencilRef); if (this->DepthStencilState) this->DepthStencilState->Release();
	ctx->PSSetShaderResources(0, 1, &this->PSShaderResource); if (this->PSShaderResource) this->PSShaderResource->Release();
	ctx->PSSetSamplers(0, 1, &this->PSSampler); if (this->PSSampler) this->PSSampler->Release();
	ctx->PSSetShader(this->PS, this->PSInstances, this->PSInstancesCount); if (this->PS) this->PS->Release();
	for (UINT i = 0; i < this->PSInstancesCount; i++) if (this->PSInstances[i]) this->PSInstances[i]->Release();
	ctx->VSSetShader(this->VS, this->VSInstances, this->VSInstancesCount); if (this->VS) this->VS->Release();
	ctx->VSSetConstantBuffers(0, 1, &this->VSConstantBuffer); if (this->VSConstantBuffer) this->VSConstantBuffer->Release();
	ctx->GSSetShader(this->GS, this->GSInstances, this->GSInstancesCount); if (this->GS) this->GS->Release();
	for (UINT i = 0; i < this->VSInstancesCount; i++) if (this->VSInstances[i]) this->VSInstances[i]->Release();
	ctx->IASetPrimitiveTopology(this->PrimitiveTopology);
	ctx->IASetIndexBuffer(this->IndexBuffer, this->IndexBufferFormat, this->IndexBufferOffset); if (this->IndexBuffer) this->IndexBuffer->Release();
	ctx->IASetVertexBuffers(0, 1, &this->VertexBuffer, &this->VertexBufferStride, &this->VertexBufferOffset); if (this->VertexBuffer) this->VertexBuffer->Release();
	ctx->IASetInputLayout(this->InputLayout); if (this->InputLayout) this->InputLayout->Release();
}
