#pragma once

class CD3D9Renderer;

enum EChairRenderFlags
{
	eCRF_None = 0,
	eCRF_InitRenderer	= BIT(0),
	eCRF_BeginFrame		= BIT(1),
	eCRF_EndFrame		= BIT(2),
	eCRF_RT_BeginFrame	= BIT(3),
	eCRF_RT_EndFrame	= BIT(4),
	eCRF_RT_Present		= BIT(5),
};

struct IChairRenderListener
{
	//! Called once when the listener is added. See EChairRenderFlags.
	//! @returns which callbacks need to be called for this callback.
	virtual int GetFlags() = 0;

	//! Called after CD3D9Renderer::InitRenderer.
	virtual void InitRenderer(CD3D9Renderer* pRenderer) {}

	//! Called after CD3D9Renderer::BeginFrame on the main thread.
	virtual void BeginFrame() {}

	//! Called before CD3D9Renderer::EndFrame on the main thread. Called in reverse order.
	virtual void EndFrame() {}

	//! Called after CD3D9Renderer::RT_BeginFrame on the render thread.
	virtual void RT_BeginFrame() {}

	//! Called before CD3D9Renderer::RT_EndFrame on the render thread. Called in reverse order.
	virtual void RT_EndFrame() {}

	//! Called during CD3D9Renderer::RT_EndFrame before IDXGISwapChain::Present.
	virtual void RT_Present() {}
};

struct IChairRender
{
	//! Adds a listener. Callbacks in listeners are called in the order of AddListener calls.
	//! Listener must exist for as long as the game does. Call RemoveListener before destruction.
	virtual void AddListener(IChairRenderListener* listener) = 0;

	//! Removes a listener added by AddListener. If AddListener was called multiple times
	//! for the same listener, RemoveListener must be called the same count of times.
	//! @returns whether the listener was removed.
	virtual bool RemoveListener(IChairRenderListener* listener) = 0;
};
