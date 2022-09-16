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
	void SetCanChangeRenderCmds(bool state) { m_bCanChangeCmds = state; }

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
	RenderCmdId RegisterRenderCommand(const char* name, const CmdHandler& handler) override;
	bool UnregisterRenderCommand(RenderCmdId nCustomCmdId) override;
	CustomCommandBuffer QueueCommand(RenderCmdId nCustomCmdId, size_t nParamBytes) override;

private:
	using TListenerList = std::vector<IChairRenderListener*>;

	struct CustomCommand
	{
#ifdef DEBUG_BUILD
		std::string name;
#endif
		CmdHandler handler;

		inline bool IsRegistered() { return !!handler; }

		void Fill(const char* name, const CmdHandler& handler);
	};

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

	std::vector<CustomCommand> m_CustomCommands;
	TArray<byte> m_CmdBuffer[RT_COMMAND_BUF_COUNT];
	bool m_bHaveUnregisteredCmds = false;
	bool m_bCanChangeCmds = false;
};

} // namespace RenderDll