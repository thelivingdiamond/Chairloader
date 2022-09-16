#pragma once
#include <functional>
#include <Prey/CryCore/AlignmentTools.h>

class CD3D9Renderer;

using RenderCmdId = uint32;
constexpr RenderCmdId INVALID_RENDER_CMD_ID = -1;

enum EChairRenderFlags
{
	eCRF_None = 0,
	eCRF_InitRenderer		= BIT(0),
	eCRF_RT_InitRenderer	= BIT(1),
	eCRF_Shutdown			= BIT(2),
	eCRF_RT_Shutdown		= BIT(3),
	eCRF_BeginFrame			= BIT(4),
	eCRF_EndFrame			= BIT(5),
	eCRF_RT_BeginFrame		= BIT(6),
	eCRF_RT_EndFrame		= BIT(7),
	eCRF_RT_Present			= BIT(8),
};

struct CustomCommandBuffer
{
	// Do not change fields - will break mods!
	byte* pBuffer;
	byte* pBufferEnd;

	//-------------------------------------------------------------------------------------

	//! Reads a value of type T from the current command buffer.
	template<class T>
	inline T ReadCommand()
	{
		T Res;
		LoadUnaligned((uint32*)pBuffer, Res);
		pBuffer += (sizeof(T) + 3) & ~((size_t)3);
		return Res;
	}

	//! Reads a value of type T into an uninitialized storage.
	template<class T>
	inline void ReadCommand(SUninitialized<T>& value)
	{
		LoadUnaligned((uint32*)pBuffer, value);
		pBuffer += (sizeof(T) + 3) & ~((size_t)3);
	}

	//-------------------------------------------------------------------------------------

	inline void AddDWORD(uint32 nVal)
	{
		*(uint32*)pBuffer = nVal;
		pBuffer += sizeof(uint32);
	}

	inline void AddPointer(const void* pVal)
	{
		StoreUnaligned((uint32*)pBuffer, pVal); // uint32 because command list maintains 4-byte alignment
		pBuffer += sizeof(void*);
	}

	inline void EndCommand()
	{
#if DEBUG_BUILD
		if (pBuffer != pBufferEnd)
		{
			long long delta = pBufferEnd - pBuffer;
			CryFatalError("Bad render command size - check the parameters and round each up to 4-byte boundaries\n"
				"Queue is %lld bytes short.", delta);
		}
#endif
	}
};

struct IChairRenderListener
{
	virtual ~IChairRenderListener() {}

	//! Called once when the listener is added. See EChairRenderFlags.
	//! @returns which callbacks need to be called for this callback.
	virtual int GetFlags() = 0;

	//! Called after CD3D9Renderer::Init.
	virtual void InitRenderer(CD3D9Renderer* pRenderer) {}

	//! Called after CD3D9Renderer::RT_Init on the render thread.
	virtual void RT_InitRenderer() {}

	//! Called before CD3D9Renderer::ShutDown.
	virtual void ShutdownRenderer() {}

	//! Called before CD3D9Renderer::RT_ShutDown on the render thread.
	virtual void RT_ShutdownRenderer() {}

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
	virtual ~IChairRender() {}

	//! The custom render command handler.
	//! @param	nCustomCmdId	The id of the current command
	//! @param	cmdBuf			The command buffer to read from.
	using CmdHandler = std::function<void(int nCustomCmdId, CustomCommandBuffer& cmdBuf)>;

	//! Adds a listener. Callbacks in listeners are called in the order of AddListener calls.
	//! Listener must exist for as long as the game does. Call RemoveListener before destruction.
	virtual void AddListener(IChairRenderListener* listener) = 0;

	//! Removes a listener added by AddListener. If AddListener was called multiple times
	//! for the same listener, RemoveListener must be called the same count of times.
	//! @returns whether the listener was removed.
	virtual bool RemoveListener(IChairRenderListener* listener) = 0;

	//! Registers a custom rendering command.
	//! @param	name	Name of the command (for debugging).
	//! @param	handler	The command handler.
	//! @returns the id of the command
	virtual RenderCmdId RegisterRenderCommand(const char* name, const CmdHandler& handler) = 0;

	//! Unregisters the command.
	//! @param	nCustomCmdId	The id of the command.
	//! @returns true if the command was found.
	virtual bool UnregisterRenderCommand(RenderCmdId nCustomCmdId) = 0;

	//! Queues a new rendering command. Must be called from the main thread.
	//! @param	nCustomCmdId	The id returned by RegisterRenderCommand.
	//! @param	nParamBytes		Size of the command data.
	virtual CustomCommandBuffer QueueCommand(RenderCmdId nCustomCmdId, size_t nParamBytes) = 0;
};
