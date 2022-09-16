#pragma once
#include <ChairLoader/IChairRender.h>

namespace RenderDll
{

class ChairRender : public IChairRender, NoCopy
{
public:
	static ChairRender& Get();

	ChairRender();
	~ChairRender();

	void Init();
	void Shutdown();

	void InitRenderer(CD3D9Renderer* pRenderer);
	void RT_InitRenderer();
	void ShutdownRenderer();
	void RT_ShutdownRenderer();
	void BeginFrame();
	void EndFrame();
	void RT_BeginFrame();
	void RT_EndFrame();
	void RT_Present();

	// IChairRender
	void AddListener(IChairRenderListener* listener) override;
	bool RemoveListener(IChairRenderListener* listener) override;

private:
	using TListenerList = std::vector<IChairRenderListener*>;

	std::vector<TListenerList*> m_AllLists;
	TListenerList m_InitRenderer;
	TListenerList m_RT_InitRenderer;
	TListenerList m_Shutdown;
	TListenerList m_RT_Shutdown;
	TListenerList m_BeginFrame;
	TListenerList m_EndFrame;
	TListenerList m_RT_BeginFrame;
	TListenerList m_RT_EndFrame;
	TListenerList m_RT_Present;
};

} // namespace RenderDll