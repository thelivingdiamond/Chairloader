// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
//
// Created by theli on 4/22/2026.
//

#ifndef CHAIRLOADER_FLASHPLAYERINSTANCE_H
#define CHAIRLOADER_FLASHPLAYERINSTANCE_H
#include "IFlashPlayer.h"

#endif //CHAIRLOADER_FLASHPLAYERINSTANCE_H



class CFlashPlayer : public IFlashPlayer, public IFlashPlayer_RenderProxy
{
public:
    virtual void AddRef();
    virtual void Release();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CrySystem/Scaleform/IFlashPlayer.h>
#include <Prey/CryThreading/CryThread_win32.h>
#include <_unknown/CrySimpleThread.h>
#include <_unknown/FlashHelpers__LinkedResourceList.h>
#include <_unknown/FlashHelpers__LinkedResourceList__Node.h>
#include <_unknown/GFxActionControl.h>
#include <_unknown/GFxFunctionHandler.h>
#include <_unknown/GFxRenderConfig.h>
#include <_unknown/GPtr.h>
#include <_unknown/IActionScriptFunction.h>
#include <_unknown/IFlashPlayer.h>
#include <_unknown/IFlashVariableObject.h>
#include <e:/_perforce/danielle/preydlcbnet/code/sdks/scaleform/include/gfxplayer.h>

enum class EFlashVariableArrayType;
class GFxMovieDef;
class GFxMovieView;
class GMemoryHeap;
struct GRendererCommandBuffer;
struct IActionScriptFunction;
struct IExternalInterfaceHandler;
struct IFSCommandHandler;
struct IFlashLoadMovieHandler;
class ITexture;
struct SFlashCharEvent;
struct SFlashCursorEvent;
struct SFlashCxform;
struct SFlashDisplayInfo;
struct SFlashKeyEvent;
struct SFlashVarValue;

// CFlashPlayer
// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
class CFlashPlayer : public IFlashPlayer, public IFlashPlayer_RenderProxy
{ // Size=400 (0x190)
public:
	enum class ELogOptions
	{
		LO_LOADING = 1,
		LO_ACTIONSCRIPT = 2,
		LO_PEAKS = 4,
	};

	// CFlashPlayer::PlayerListNodeType
	// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
	struct PlayerListNodeType
	{ // Size=24 (0x18)
		FlashHelpers::LinkedResourceList<CFlashPlayer>::Node<CFlashPlayer>* m_pPrev;
		FlashHelpers::LinkedResourceList<CFlashPlayer>::Node<CFlashPlayer>* m_pNext;
		CFlashPlayer* m_pHandle;

	#if 0
		void Node<CFlashPlayer>();
	#endif
	};

	// CFlashPlayer::GRendererCommandBufferProxy
	// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
	struct GRendererCommandBufferProxy
	{ // Size=120 (0x78)
		// CFlashPlayer::GRendererCommandBufferProxy::GRendererCommandDoubleBuffer
		// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
		struct GRendererCommandDoubleBuffer
		{ // Size=112 (0x70)
			char m_storage[112];

		#if 0
			GRendererCommandDoubleBuffer(GMemoryHeap* _arg0_);
			~GRendererCommandDoubleBuffer();
			GRendererCommandBuffer& operator[](uint64_t _arg0_);
			uint64_t GetBufferSize() const;
		#endif
		};

		static constexpr const uint64_t NumCommandBuffers = 2;
		CFlashPlayer::GRendererCommandBufferProxy::GRendererCommandDoubleBuffer* m_pCmdDB;
		char m_storage[112];

	#if 0
		GRendererCommandBufferProxy();
		~GRendererCommandBufferProxy();
		void Release();
		bool IsInitialized() const;
		void Init(GMemoryHeap* _arg0_);
		uint64_t GetBufferSize() const;
		GRendererCommandBuffer& operator[](uint64_t _arg0_);
		const GRendererCommandBuffer& operator[](uint64_t _arg0_) const;
	#endif
	};

	using PlayerList = FlashHelpers::LinkedResourceList<CFlashPlayer>;

	static inline auto ms_playerList = PreyGlobal<FlashHelpers::LinkedResourceList<CFlashPlayer>>(0x23D8380);
	static inline auto ms_sys_flash = PreyGlobal<int>(0x23D8360);
	static inline auto ms_sys_flash_edgeaa = PreyGlobal<int>(0x23D8364);
	static inline auto ms_sys_flash_log_options = PreyGlobal<int>(0x2C7ACF8);
	static inline auto ms_sys_flash_curve_tess_error = PreyGlobal<float>(0x23D8368);
	static inline auto ms_sys_flash_warning_level = PreyGlobal<int>(0x23D836C);
	static inline auto ms_sys_flash_static_pool_size = PreyGlobal<int>(0x2C7ACFC);
	static inline auto ms_sys_flash_address_space_kb = PreyGlobal<int>(0x23D8370);
	static inline auto ms_sys_flash_allow_mesh_cache_reset = PreyGlobal<int>(0x23D8374);
	static inline auto ms_sys_flash_reset_mesh_cache = PreyGlobal<int>(0x2C7AD00);
	static inline auto ms_sys_flash_check_filemodtime = PreyGlobal<int>(0x2C7AD04);
	static inline auto ms_pLoadMovieHandler = PreyGlobal<IFlashLoadMovieHandler*>(0x2C7AD08);
	volatile int m_refCount;
	volatile int m_releaseGuardCount;
	float m_compDepth;
	bool m_allowEgdeAA : 1;
	bool m_avoidStencilClear : 1;
	bool m_maskedRendering : 1;
	bool m_allowWireframeRendering : 1;
	uint8_t m_memArenaID : 5;
	bool m_extendCanvasToVP : 1;
	GFxRenderConfig m_renderConfig;
	GFxActionControl m_asVerbosity;
	const unsigned m_frameCount;
	const float m_frameRate;
	const int m_width;
	const int m_height;
	IFSCommandHandler* m_pFSCmdHandler;
	void* m_pFSCmdHandlerUserData;
	IExternalInterfaceHandler* m_pEIHandler;
	void* m_pEIHandlerUserData;
	GPtr<GFxMovieDef> m_pMovieDef;
	GPtr<GFxMovieView> m_pMovieView;
	GPtr<GFxLoader2> m_pLoader;
	GPtr<GRendererXRender> m_pRenderer;
	const std::shared_ptr<string> m_filePath;
	FlashHelpers::LinkedResourceList<CFlashPlayer>::Node<CFlashPlayer> m_node;
	const std::shared_ptr<CryCriticalSection> m_lock;
	GFxValue m_retValRefHolder;
	CFlashPlayer::GRendererCommandBufferProxy m_cmdBuf;

	virtual void AddRef();
	virtual void Release();
	virtual bool Load(const char* pFilePath, unsigned options, unsigned cat);
	virtual void SetBackgroundColor(const ColorB& color);
	virtual void SetBackgroundAlpha(float alpha);
	virtual float GetBackgroundAlpha() const;
	virtual void SetViewport(int x0, int y0, int width, int height, float aspectRatio);
	virtual void GetViewport(int& x0, int& y0, int& width, int& height, float& aspectRatio) const;
	virtual void SetViewScaleMode(IFlashPlayer::EScaleModeType scaleMode);
	virtual IFlashPlayer::EScaleModeType GetViewScaleMode() const;
	virtual void SetViewAlignment(IFlashPlayer::EAlignType viewAlignment);
	virtual IFlashPlayer::EAlignType GetViewAlignment() const;
	virtual void SetScissorRect(int x0, int y0, int width, int height);
	virtual void GetScissorRect(int& x0, int& y0, int& width, int& height) const;
	virtual void Advance(float deltaTime);
	virtual void Render();
	virtual void SetCompositingDepth(float depth);
	virtual void AvoidStencilClear(bool avoid);
	virtual void EnableMaskedRendering(bool enable);
	virtual void ExtendCanvasToViewport(bool extend);
	virtual void AllowWireframeRendering(bool _allow);
	virtual void Restart();
	virtual bool IsPaused() const;
	virtual void Pause(bool pause);
	virtual void GotoFrame(unsigned frameNumber);
	virtual bool GotoLabeledFrame(const char* pLabel, int offset);
	virtual unsigned GetCurrentFrame() const;
	virtual bool HasLooped() const;
	virtual void SetFSCommandHandler(IFSCommandHandler* pHandler, void* pUserData);
	virtual void SetExternalInterfaceHandler(IExternalInterfaceHandler* pHandler, void* pUserData);
	virtual void SendCursorEvent(const SFlashCursorEvent& cursorEvent);
	virtual void SendKeyEvent(const SFlashKeyEvent& keyEvent);
	virtual void SendCharEvent(const SFlashCharEvent& charEvent);
	virtual void SetVisible(bool visible);
	virtual bool GetVisible() const;
	virtual bool SetOverrideTexture(const char* pResourceName, ITexture* pTexture, bool resize);
	virtual bool SetVariable(const char* pPathToVar, const SFlashVarValue& value);
	virtual bool SetVariable(const char* pPathToVar, const IFlashVariableObject* pVarObj);
	virtual bool GetVariable(const char* pPathToVar, SFlashVarValue& value) const;
	virtual bool GetVariable(const char* pPathToVar, IFlashVariableObject* & pVarObj) const;
	virtual bool IsAvailable(const char* pPathToVar) const;
	virtual bool SetVariableArray(EFlashVariableArrayType type, const char* pPathToVar, unsigned index, const void* pData, unsigned count);
	virtual unsigned GetVariableArraySize(const char* pPathToVar) const;
	virtual bool GetVariableArray(EFlashVariableArrayType type, const char* pPathToVar, unsigned index, void* pData, unsigned count) const;
	virtual bool Invoke(const char* pMethodName, const SFlashVarValue* pArgs, unsigned numArgs, SFlashVarValue* pResult);
	virtual bool CreateString(const char* pString, IFlashVariableObject* & pVarObj);
	virtual bool CreateStringW(const wchar_t* pString, IFlashVariableObject* & pVarObj);
	virtual bool CreateObject(const char* pClassName, const SFlashVarValue* pArgs, unsigned numArgs, IFlashVariableObject* & pVarObj);
	virtual bool CreateArray(IFlashVariableObject* & pVarObj);
	virtual bool CreateFunction(IFlashVariableObject* & pFuncVarObj, IActionScriptFunction* pFunc, void* pUserData);
	virtual unsigned GetFrameCount() const;
	virtual float GetFrameRate() const;
	virtual int GetWidth() const;
	virtual int GetHeight() const;
	virtual uint64_t GetMetadata(char* pBuff, unsigned buffSize) const;
	virtual const char* GetFilePath() const;
	virtual void ResetDirtyFlags();
	virtual void ScreenToClient(int& x, int& y) const;
	virtual void ClientToScreen(int& x, int& y) const;
	virtual void RenderCallback(bool releaseOnExit);
	virtual void RenderPlaybackLocklessCallback(int cbIdx, bool finalPlayback, bool releaseOnExit);
	virtual void DummyRenderCallback(bool releaseOnExit);
	CFlashPlayer();
	virtual ~CFlashPlayer();
	void DelegateFSCommandCallback(const char* pCommand, const char* pArgs) { FDelegateFSCommandCallback(this, pCommand, pArgs); }
	void DelegateExternalInterfaceCallback(const char* pMethodName, const GFxValue* pArgs, unsigned numArgs) { FDelegateExternalInterfaceCallback(this, pMethodName, pArgs, numArgs); }
	static IFlashLoadMovieHandler* GetFlashLoadMovieHandler() { return FGetFlashLoadMovieHandler(); }
	static void InitCVars() { FInitCVars(); }
	static bool CheckFileModTimeEnabled() { return FCheckFileModTimeEnabled(); }
	static uint64_t GetStaticPoolSize() { return FGetStaticPoolSize(); }
	static uint64_t GetAddressSpaceSize() { return FGetAddressSpaceSize(); }
	static void DumpAndFixLeaks() { FDumpAndFixLeaks(); }
	static unsigned GetLogOptions() { return FGetLogOptions(); }
	bool ConstructInternal(const char* pFilePath, GFxMovieDef* pMovieDef, unsigned options, unsigned cat) { return FConstructInternal(this, pFilePath, pMovieDef, options, cat); }

#if 0
	static void RenderFlashInfo(bool _arg0_);
	static void SetFlashLoadMovieHandler(IFlashLoadMovieHandler* _arg0_);
	static int GetWarningLevel();
	static void GetFlashProfileResults(float& _arg0_);
	static bool AllowMeshCacheReset();
	static CFlashPlayer* CreateBootstrapped(GFxMovieDef* _arg0_, unsigned _arg1_, unsigned _arg2_);
	bool IsEdgeAaAllowed() const;
	void UpdateRenderFlags();
	void UpdateASVerbosity();
	uint64_t GetCommandBufferSize() const;
	bool Bootstrap(GFxMovieDef* _arg0_, unsigned _arg1_, unsigned _arg2_);
	static bool IsFlashEnabled();
	static FlashHelpers::LinkedResourceList<CFlashPlayer>& GetList();
	static FlashHelpers::LinkedResourceList<CFlashPlayer>::Node<CFlashPlayer>& GetListRoot();
#endif

	static inline auto FAddRef = PreyFunction<void(CFlashPlayer* const _this)>(0xE78980);
	static inline auto FRelease = PreyFunction<void(CFlashPlayer* const _this)>(0xE7CF50);
	static inline auto FLoad = PreyFunction<bool(CFlashPlayer* const _this, const char* pFilePath, unsigned options, unsigned cat)>(0xE7CAB0);
	static inline auto FSetBackgroundColor = PreyFunction<void(CFlashPlayer* const _this, const ColorB& color)>(0xE7DA10);
	static inline auto FSetBackgroundAlpha = PreyFunction<void(CFlashPlayer* const _this, float alpha)>(0xE7D9B0);
	static inline auto FGetBackgroundAlpha = PreyFunction<float(const CFlashPlayer* const _this)>(0xE7A660);
	static inline auto FSetViewport = PreyFunction<void(CFlashPlayer* const _this, int x0, int y0, int width, int height, float aspectRatio)>(0xE7EAD0);
	static inline auto FGetViewport = PreyFunction<void(const CFlashPlayer* const _this, int& x0, int& y0, int& width, int& height, float& aspectRatio)>(0xE7BC10);
	static inline auto FSetViewScaleMode = PreyFunction<void(CFlashPlayer* const _this, IFlashPlayer::EScaleModeType scaleMode)>(0xE7EA50);
	static inline auto FGetViewScaleMode = PreyFunction<IFlashPlayer::EScaleModeType(const CFlashPlayer* const _this)>(0xE7BB90);
	static inline auto FSetViewAlignment = PreyFunction<void(CFlashPlayer* const _this, IFlashPlayer::EAlignType viewAlignment)>(0xE7E980);
	static inline auto FGetViewAlignment = PreyFunction<IFlashPlayer::EAlignType(const CFlashPlayer* const _this)>(0xE7BAC0);
	static inline auto FSetScissorRect = PreyFunction<void(CFlashPlayer* const _this, int x0, int y0, int width, int height)>(0xE7E410);
	static inline auto FGetScissorRect = PreyFunction<void(const CFlashPlayer* const _this, int& x0, int& y0, int& width, int& height)>(0xE7B220);
	static inline auto FAdvance = PreyFunction<void(CFlashPlayer* const _this, float deltaTime)>(0xE78990);
	static inline auto FRender = PreyFunction<void(CFlashPlayer* const _this)>(0xE7D020);
	static inline auto FSetCompositingDepth = PreyFunction<void(CFlashPlayer* const _this, float depth)>(0xA5FE00);
	static inline auto FAvoidStencilClear = PreyFunction<void(CFlashPlayer* const _this, bool avoid)>(0xE78B20);
	static inline auto FEnableMaskedRendering = PreyFunction<void(CFlashPlayer* const _this, bool enable)>(0xE7A4A0);
	static inline auto FExtendCanvasToViewport = PreyFunction<void(CFlashPlayer* const _this, bool extend)>(0xE7A4B0);
	static inline auto FAllowWireframeRendering = PreyFunction<void(CFlashPlayer* const _this, bool _allow)>(0xE78A00);
	static inline auto FRestart = PreyFunction<void(CFlashPlayer* const _this)>(0xE7D380);
	static inline auto FIsPaused = PreyFunction<bool(const CFlashPlayer* const _this)>(0xE7CA50);
	static inline auto FPause = PreyFunction<void(CFlashPlayer* const _this, bool pause)>(0xE7CCD0);
	static inline auto FGotoFrame = PreyFunction<void(CFlashPlayer* const _this, unsigned frameNumber)>(0xE7BF40);
	static inline auto FGotoLabeledFrame = PreyFunction<bool(CFlashPlayer* const _this, const char* pLabel, int offset)>(0xE7BF90);
	static inline auto FGetCurrentFrame = PreyFunction<unsigned(const CFlashPlayer* const _this)>(0xE7A790);
	static inline auto FHasLooped = PreyFunction<bool(const CFlashPlayer* const _this)>(0xE7C010);
	static inline auto FSetFSCommandHandler = PreyFunction<void(CFlashPlayer* const _this, IFSCommandHandler* pHandler, void* pUserData)>(0xE7E0D0);
	static inline auto FSetExternalInterfaceHandler = PreyFunction<void(CFlashPlayer* const _this, IExternalInterfaceHandler* pHandler, void* pUserData)>(0xE7E0C0);
	static inline auto FSendCursorEvent = PreyFunction<void(CFlashPlayer* const _this, const SFlashCursorEvent& cursorEvent)>(0xE7D5B0);
	static inline auto FSendKeyEvent = PreyFunction<void(CFlashPlayer* const _this, const SFlashKeyEvent& keyEvent)>(0xE7D6B0);
	static inline auto FSendCharEvent = PreyFunction<void(CFlashPlayer* const _this, const SFlashCharEvent& charEvent)>(0xE7D540);
	static inline auto FSetVisible = PreyFunction<void(CFlashPlayer* const _this, bool visible)>(0xE7EBA0);
	static inline auto FGetVisible = PreyFunction<bool(const CFlashPlayer* const _this)>(0xE7BD20);
	static inline auto FSetOverrideTexture = PreyFunction<bool(CFlashPlayer* const _this, const char* pResourceName, ITexture* pTexture, bool resize)>(0xE7E2F0);
	static inline auto FSetVariableOv1 = PreyFunction<bool(CFlashPlayer* const _this, const char* pPathToVar, const SFlashVarValue& value)>(0xE7E6B0);
	static inline auto FSetVariableOv0 = PreyFunction<bool(CFlashPlayer* const _this, const char* pPathToVar, const IFlashVariableObject* pVarObj)>(0xE7E770);
	static inline auto FGetVariableOv1 = PreyFunction<bool(const CFlashPlayer* const _this, const char* pPathToVar, SFlashVarValue& value)>(0xE7B7D0);
	static inline auto FGetVariableOv0 = PreyFunction<bool(const CFlashPlayer* const _this, const char* pPathToVar, IFlashVariableObject* & pVarObj)>(0xE7B680);
	static inline auto FIsAvailable = PreyFunction<bool(const CFlashPlayer* const _this, const char* pPathToVar)>(0xE7C9B0);
	static inline auto FSetVariableArray = PreyFunction<bool(CFlashPlayer* const _this, EFlashVariableArrayType type, const char* pPathToVar, unsigned index, const void* pData, unsigned count)>(0xE7E8B0);
	static inline auto FGetVariableArraySize = PreyFunction<unsigned(const CFlashPlayer* const _this, const char* pPathToVar)>(0xE7BA50);
	static inline auto FGetVariableArray = PreyFunction<bool(const CFlashPlayer* const _this, EFlashVariableArrayType type, const char* pPathToVar, unsigned index, void* pData, unsigned count)>(0xE7B980);
	static inline auto FInvoke = PreyFunction<bool(CFlashPlayer* const _this, const char* pMethodName, const SFlashVarValue* pArgs, unsigned numArgs, SFlashVarValue* pResult)>(0xE7C4A0);
	static inline auto FCreateString = PreyFunction<bool(CFlashPlayer* const _this, const char* pString, IFlashVariableObject* & pVarObj)>(0xE79E70);
	static inline auto FCreateStringW = PreyFunction<bool(CFlashPlayer* const _this, const wchar_t* pString, IFlashVariableObject* & pVarObj)>(0xE79FC0);
	static inline auto FCreateObject = PreyFunction<bool(CFlashPlayer* const _this, const char* pClassName, const SFlashVarValue* pArgs, unsigned numArgs, IFlashVariableObject* & pVarObj)>(0xE79B90);
	static inline auto FCreateArray = PreyFunction<bool(CFlashPlayer* const _this, IFlashVariableObject* & pVarObj)>(0xE79670);
	static inline auto FCreateFunction = PreyFunction<bool(CFlashPlayer* const _this, IFlashVariableObject* & pFuncVarObj, IActionScriptFunction* pFunc, void* pUserData)>(0xE799B0);
	static inline auto FGetFrameCount = PreyFunction<unsigned(const CFlashPlayer* const _this)>(0xE7AED0);
	static inline auto FGetFrameRate = PreyFunction<float(const CFlashPlayer* const _this)>(0xE7AEE0);
	static inline auto FGetWidth = PreyFunction<int(const CFlashPlayer* const _this)>(0x36AC60);
	static inline auto FGetHeight = PreyFunction<int(const CFlashPlayer* const _this)>(0xE7AEF0);
	static inline auto FGetMetadata = PreyFunction<uint64_t(const CFlashPlayer* const _this, char* pBuff, unsigned buffSize)>(0xE7B1C0);
	static inline auto FGetFilePath = PreyFunction<const char* (const CFlashPlayer* const _this)>(0xE7AE60);
	static inline auto FResetDirtyFlags = PreyFunction<void(CFlashPlayer* const _this)>(0xE7D340);
	static inline auto FScreenToClient = PreyFunction<void(const CFlashPlayer* const _this, int& x, int& y)>(0xE7D480);
	static inline auto FClientToScreen = PreyFunction<void(const CFlashPlayer* const _this, int& x, int& y)>(0xE78DE0);
	static inline auto FRenderCallback = PreyFunction<void(IFlashPlayer_RenderProxy* const _this, bool releaseOnExit)>(0xE7D070);
	static inline auto FRenderPlaybackLocklessCallback = PreyFunction<void(IFlashPlayer_RenderProxy* const _this, int cbIdx, bool finalPlayback, bool releaseOnExit)>(0xE7D200);
	static inline auto FDummyRenderCallback = PreyFunction<void(IFlashPlayer_RenderProxy* const _this, bool releaseOnExit)>(0xE7A3B0);
	static inline auto FCFlashPlayerOv1 = PreyFunction<void(CFlashPlayer* const _this)>(0xE77E00);
	static inline auto FBitNotCFlashPlayer = PreyFunction<void(CFlashPlayer* const _this)>(0xE78110);
	static inline auto FDelegateFSCommandCallback = PreyFunction<void(CFlashPlayer* const _this, const char* pCommand, const char* pArgs)>(0xE7A2F0);
	static inline auto FDelegateExternalInterfaceCallback = PreyFunction<void(CFlashPlayer* const _this, const char* pMethodName, const GFxValue* pArgs, unsigned numArgs)>(0xE7A120);
	static inline auto FGetFlashLoadMovieHandler = PreyFunction<IFlashLoadMovieHandler* ()>(0xE7AE90);
	static inline auto FInitCVars = PreyFunction<void()>(0xE7C1D0);
	static inline auto FCheckFileModTimeEnabled = PreyFunction<bool()>(0xE78DD0);
	static inline auto FGetStaticPoolSize = PreyFunction<uint64_t()>(0xE7B310);
	static inline auto FGetAddressSpaceSize = PreyFunction<uint64_t()>(0xE7A5F0);
	static inline auto FDumpAndFixLeaks = PreyFunction<void()>(0xE7A3D0);
	static inline auto FGetLogOptions = PreyFunction<unsigned()>(0xE7AF00);
	static inline auto FConstructInternal = PreyFunction<bool(CFlashPlayer* const _this, const char* pFilePath, GFxMovieDef* pMovieDef, unsigned options, unsigned cat)>(0xE78FB0);
};

// CFlashPlayerBootStrapper
// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
// Include: Prey/CrySystem/Scaleform/FlashPlayerInstance.cpp
class CFlashPlayerBootStrapper : public IFlashPlayerBootStrapper
{ // Size=48 (0x30)
public:
	// CFlashPlayerBootStrapper::BootStrapperListNodeType
	// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
	struct BootStrapperListNodeType
	{ // Size=24 (0x18)
		FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>::Node<CFlashPlayerBootStrapper>* m_pPrev;
		FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>::Node<CFlashPlayerBootStrapper>* m_pNext;
		CFlashPlayerBootStrapper* m_pHandle;

	#if 0
		static void Node<CFlashPlayerBootStrapper>();
	#endif
	};

	using BootStrapperList = FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>;

	static inline auto ms_bootstrapperList = PreyGlobal<FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>>(0x23D8400);
	GPtr<GFxMovieDef> m_pMovieDef;
	GPtr<GFxLoader2> m_pLoader;
	FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>::Node<CFlashPlayerBootStrapper> m_node;

	virtual void Release();
	virtual bool Load(const char* pFilePath);
	virtual IFlashPlayer* CreatePlayerInstance(unsigned options, unsigned cat);
	virtual const char* GetFilePath() const;
	virtual uint64_t GetMetadata(char* pBuff, unsigned buffSize) const;
	virtual bool HasMetadata(const char* pTag) const;
	virtual ~CFlashPlayerBootStrapper();

#if 0
	CFlashPlayerBootStrapper();
	const GFxMovieDef* GetMovieDef() const;
	static FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>& GetList();
	static FlashHelpers::LinkedResourceList<CFlashPlayerBootStrapper>::Node<CFlashPlayerBootStrapper>& GetListRoot();
#endif

	static inline auto FRelease = PreyFunction<void(CFlashPlayerBootStrapper* const _this)>(0xDD0880);
	static inline auto FLoad = PreyFunction<bool(CFlashPlayerBootStrapper* const _this, const char* pFilePath)>(0xE7CC10);
	static inline auto FCreatePlayerInstance = PreyFunction<IFlashPlayer* (CFlashPlayerBootStrapper* const _this, unsigned options, unsigned cat)>(0xE79DC0);
	static inline auto FGetFilePath = PreyFunction<const char* (const CFlashPlayerBootStrapper* const _this)>(0xE7AE70);
	static inline auto FGetMetadata = PreyFunction<uint64_t(const CFlashPlayerBootStrapper* const _this, char* pBuff, unsigned buffSize)>(0xE7B1F0);
	static inline auto FHasMetadata = PreyFunction<bool(const CFlashPlayerBootStrapper* const _this, const char* pTag)>(0xE7C0F0);
};

// CFlashVariableObject
// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
// Include: Prey/CrySystem/Scaleform/FlashPlayerInstance.cpp
class CFlashVariableObject : public IFlashVariableObject
{ // Size=112 (0x70)
public:
	// CFlashVariableObject::VariableListNodeType
	// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
	struct VariableListNodeType
	{ // Size=24 (0x18)
		FlashHelpers::LinkedResourceList<CFlashVariableObject>::Node<CFlashVariableObject>* m_pPrev;
		FlashHelpers::LinkedResourceList<CFlashVariableObject>::Node<CFlashVariableObject>* m_pNext;
		CFlashVariableObject* m_pHandle;

	#if 0
		static void Node<CFlashVariableObject>();
	#endif
	};

	using VariableList = FlashHelpers::LinkedResourceList<CFlashVariableObject>;

	static inline auto ms_variableList = PreyGlobal<FlashHelpers::LinkedResourceList<CFlashVariableObject>>(0x23D83C0);
	GFxValue m_value;
	const std::shared_ptr<const string> m_refFilePath;
	GFxValue m_retValRefHolder;
	const std::shared_ptr<CryCriticalSection> m_lock;
	FlashHelpers::LinkedResourceList<CFlashVariableObject>::Node<CFlashVariableObject> m_node;

	virtual void Release();
	virtual IFlashVariableObject* Clone() const;
	virtual bool IsObject() const;
	virtual bool IsArray() const;
	virtual bool IsDisplayObject() const;
	virtual SFlashVarValue ToVarValue() const;
	virtual bool HasMember(const char* pMemberName) const;
	virtual bool SetMember(const char* pMemberName, const SFlashVarValue& value);
	virtual bool SetMember(const char* pMemberName, const IFlashVariableObject* pVarObj);
	virtual bool GetMember(const char* pMemberName, SFlashVarValue& value) const;
	virtual bool GetMember(const char* pMemberName, IFlashVariableObject* & pVarObj) const;
	virtual void VisitMembers(IFlashVariableObject::ObjectVisitor* pVisitor) const;
	virtual bool DeleteMember(const char* pMemberName);
	virtual bool Invoke(const char* pMethodName, const SFlashVarValue* pArgs, unsigned numArgs, SFlashVarValue* pResult);
	virtual unsigned GetArraySize() const;
	virtual bool SetArraySize(unsigned size);
	virtual bool SetElement(unsigned idx, const SFlashVarValue& value);
	virtual bool SetElement(unsigned idx, const IFlashVariableObject* pVarObj);
	virtual bool GetElement(unsigned idx, SFlashVarValue& value) const;
	virtual bool GetElement(unsigned idx, IFlashVariableObject* & pVarObj) const;
	virtual bool PushBack(const SFlashVarValue& value);
	virtual bool PushBack(const IFlashVariableObject* pVarObj);
	virtual bool PopBack();
	virtual bool RemoveElements(unsigned idx, int count);
	virtual bool SetDisplayInfo(const SFlashDisplayInfo& info);
	virtual bool GetDisplayInfo(SFlashDisplayInfo& info) const;
	virtual bool SetDisplayMatrix(const Matrix33& mat);
	virtual bool GetDisplayMatrix(Matrix33& mat) const;
	virtual bool Set3DMatrix(const Matrix44& mat);
	virtual bool Get3DMatrix(Matrix44& mat) const;
	virtual bool SetColorTransform(const SFlashCxform& cx);
	virtual bool GetColorTransform(SFlashCxform& cx) const;
	virtual bool SetText(const char* pText);
	virtual bool SetText(const wchar_t* pText);
	virtual bool SetTextHTML(const char* pHtml);
	virtual bool SetTextHTML(const wchar_t* pHtml);
	virtual bool GetText(SFlashVarValue& text) const;
	virtual bool GetTextHTML(SFlashVarValue& html) const;
	virtual bool CreateEmptyMovieClip(IFlashVariableObject* & pVarObjMC, const char* pInstanceName, int depth);
	virtual bool AttachMovie(IFlashVariableObject* & pVarObjMC, const char* pSymbolName, const char* pInstanceName, int depth, const IFlashVariableObject* pInitObj);
	virtual bool GotoAndPlay(const char* pFrame);
	virtual bool GotoAndPlay(unsigned frame);
	virtual bool GotoAndStop(const char* pFrame);
	virtual bool GotoAndStop(unsigned frame);
	virtual bool SetVisible(bool visible);
	CFlashVariableObject(const GFxValue& value, const std::shared_ptr<const string>& refFilePath, const std::shared_ptr<CryCriticalSection>& lock);
	virtual ~CFlashVariableObject();

#if 0
	CFlashVariableObject(const CFlashVariableObject& _arg0_);
	const GFxValue& GetGFxValue() const;
	const std::shared_ptr<const string>& GetRefFilePath() const;
	static FlashHelpers::LinkedResourceList<CFlashVariableObject>& GetList();
	static FlashHelpers::LinkedResourceList<CFlashVariableObject>::Node<CFlashVariableObject>& GetListRoot();
#endif

	static inline auto FRelease = PreyFunction<void(CFlashVariableObject* const _this)>(0xE7CF80);
	static inline auto FClone = PreyFunction<IFlashVariableObject* (const CFlashVariableObject* const _this)>(0xE78E90);
	static inline auto FIsObject = PreyFunction<bool(const CFlashVariableObject* const _this)>(0xE7CA30);
	static inline auto FIsArray = PreyFunction<bool(const CFlashVariableObject* const _this)>(0xE7C9A0);
	static inline auto FIsDisplayObject = PreyFunction<bool(const CFlashVariableObject* const _this)>(0xE7CA20);
	static inline auto FToVarValue = PreyFunction<SFlashVarValue*(const CFlashVariableObject* const _this, SFlashVarValue* _return_value_)>(0xE7ECD0);
	static inline auto FHasMember = PreyFunction<bool(const CFlashVariableObject* const _this, const char* pMemberName)>(0xE7C070);
	static inline auto FSetMemberOv1 = PreyFunction<bool(CFlashVariableObject* const _this, const char* pMemberName, const SFlashVarValue& value)>(0xE7E0F0);
	static inline auto FSetMemberOv0 = PreyFunction<bool(CFlashVariableObject* const _this, const char* pMemberName, const IFlashVariableObject* pVarObj)>(0xE7E1B0);
	static inline auto FGetMemberOv1 = PreyFunction<bool(const CFlashVariableObject* const _this, const char* pMemberName, SFlashVarValue& value)>(0xE7B000);
	static inline auto FGetMemberOv0 = PreyFunction<bool(const CFlashVariableObject* const _this, const char* pMemberName, IFlashVariableObject* & pVarObj)>(0xE7AF10);
	static inline auto FVisitMembers = PreyFunction<void(const CFlashVariableObject* const _this, IFlashVariableObject::ObjectVisitor* pVisitor)>(0xE7ED00);
	static inline auto FDeleteMember = PreyFunction<bool(CFlashVariableObject* const _this, const char* pMemberName)>(0xE7A330);
	static inline auto FInvoke = PreyFunction<bool(CFlashVariableObject* const _this, const char* pMethodName, const SFlashVarValue* pArgs, unsigned numArgs, SFlashVarValue* pResult)>(0xE7C720);
	static inline auto FGetArraySize = PreyFunction<unsigned(const CFlashVariableObject* const _this)>(0xE7A600);
	static inline auto FSetArraySize = PreyFunction<bool(CFlashVariableObject* const _this, unsigned size)>(0xE7D940);
	static inline auto FSetElementOv1 = PreyFunction<bool(CFlashVariableObject* const _this, unsigned idx, const SFlashVarValue& value)>(0xE7DEE0);
	static inline auto FSetElementOv0 = PreyFunction<bool(CFlashVariableObject* const _this, unsigned idx, const IFlashVariableObject* pVarObj)>(0xE7DF90);
	static inline auto FGetElementOv1 = PreyFunction<bool(const CFlashVariableObject* const _this, unsigned idx, SFlashVarValue& value)>(0xE7ACB0);
	static inline auto FGetElementOv0 = PreyFunction<bool(const CFlashVariableObject* const _this, unsigned idx, IFlashVariableObject* & pVarObj)>(0xE7ABD0);
	static inline auto FPushBackOv1 = PreyFunction<bool(CFlashVariableObject* const _this, const SFlashVarValue& value)>(0xE7CD90);
	static inline auto FPushBackOv0 = PreyFunction<bool(CFlashVariableObject* const _this, const IFlashVariableObject* pVarObj)>(0xE7CE30);
	static inline auto FPopBack = PreyFunction<bool(CFlashVariableObject* const _this)>(0xE7CD30);
	static inline auto FRemoveElements = PreyFunction<bool(CFlashVariableObject* const _this, unsigned idx, int count)>(0xE7CFA0);
	static inline auto FSetDisplayInfo = PreyFunction<bool(CFlashVariableObject* const _this, const SFlashDisplayInfo& info)>(0xE7DB60);
	static inline auto FGetDisplayInfo = PreyFunction<bool(const CFlashVariableObject* const _this, SFlashDisplayInfo& info)>(0xE7A7F0);
	static inline auto FSetDisplayMatrix = PreyFunction<bool(CFlashVariableObject* const _this, const Matrix33& mat)>(0xE7DE50);
	static inline auto FGetDisplayMatrix = PreyFunction<bool(const CFlashVariableObject* const _this, Matrix33& mat)>(0xE7AB20);
	static inline auto FSet3DMatrix = PreyFunction<bool(CFlashVariableObject* const _this, const Matrix44& mat)>(0xE7D780);
	static inline auto FGet3DMatrix = PreyFunction<bool(const CFlashVariableObject* const _this, Matrix44& mat)>(0xE7A4C0);
	static inline auto FSetColorTransform = PreyFunction<bool(CFlashVariableObject* const _this, const SFlashCxform& cx)>(0xE7DA90);
	static inline auto FGetColorTransform = PreyFunction<bool(const CFlashVariableObject* const _this, SFlashCxform& cx)>(0xE7A6C0);
	static inline auto FSetTextOv1 = PreyFunction<bool(CFlashVariableObject* const _this, const char* pText)>(0xE7E4F0);
	static inline auto FSetTextOv0 = PreyFunction<bool(CFlashVariableObject* const _this, const wchar_t* pText)>(0xE7E560);
	static inline auto FSetTextHTMLOv1 = PreyFunction<bool(CFlashVariableObject* const _this, const char* pHtml)>(0xE7E5D0);
	static inline auto FSetTextHTMLOv0 = PreyFunction<bool(CFlashVariableObject* const _this, const wchar_t* pHtml)>(0xE7E640);
	static inline auto FGetText = PreyFunction<bool(const CFlashVariableObject* const _this, SFlashVarValue& text)>(0xE7B320);
	static inline auto FGetTextHTML = PreyFunction<bool(const CFlashVariableObject* const _this, SFlashVarValue& html)>(0xE7B4D0);
	static inline auto FCreateEmptyMovieClip = PreyFunction<bool(CFlashVariableObject* const _this, IFlashVariableObject* & pVarObjMC, const char* pInstanceName, int depth)>(0xE797C0);
	static inline auto FAttachMovie = PreyFunction<bool(CFlashVariableObject* const _this, IFlashVariableObject* & pVarObjMC, const char* pSymbolName, const char* pInstanceName, int depth, const IFlashVariableObject* pInitObj)>(0xE78A10);
	static inline auto FGotoAndPlayOv1 = PreyFunction<bool(CFlashVariableObject* const _this, const char* pFrame)>(0xE7BDF0);
	static inline auto FGotoAndPlayOv0 = PreyFunction<bool(CFlashVariableObject* const _this, unsigned frame)>(0xE7BD80);
	static inline auto FGotoAndStopOv1 = PreyFunction<bool(CFlashVariableObject* const _this, const char* pFrame)>(0xE7BED0);
	static inline auto FGotoAndStopOv0 = PreyFunction<bool(CFlashVariableObject* const _this, unsigned frame)>(0xE7BE60);
	static inline auto FSetVisible = PreyFunction<bool(CFlashVariableObject* const _this, bool visible)>(0xE7EC00);
	static inline auto FCFlashVariableObjectOv1 = PreyFunction<void(CFlashVariableObject* const _this, const GFxValue& value, const std::shared_ptr<const string>& refFilePath, const std::shared_ptr<CryCriticalSection>& lock)>(0xE78000);
};

// FunctionHandlerAdaptor
// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
// Include: Prey/CrySystem/Scaleform/FlashPlayerInstance.cpp
struct FunctionHandlerAdaptor : public GFxFunctionHandler
{ // Size=32 (0x20)
	// FunctionHandlerAdaptor::ReturnValue
	// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
	struct ReturnValue : public IActionScriptFunction::IReturnValue
	{ // Size=40 (0x28)
		GFxMovieView* m_pMovieView;
		GFxValue m_value;

		virtual ~ReturnValue();
		virtual void Set(const SFlashVarValue& value, bool createManagedValue);

	#if 0
		ReturnValue(GFxMovieView* _arg0_);
	#endif

		static inline auto FBitNotReturnValue = PreyFunction<void(FunctionHandlerAdaptor::ReturnValue* const _this)>(0xE78420);
		static inline auto FSet = PreyFunction<void(FunctionHandlerAdaptor::ReturnValue* const _this, const SFlashVarValue& value, bool createManagedValue)>(0xE7D8B0);
	};

	IActionScriptFunction* m_pFunc;
	CFlashPlayer* m_pPlayer;

	virtual ~FunctionHandlerAdaptor();
	virtual void Call(const GFxFunctionHandler::Params& params);

#if 0
	FunctionHandlerAdaptor(IActionScriptFunction* _arg0_, CFlashPlayer* _arg1_);
#endif

	static inline auto FCall = PreyFunction<void(FunctionHandlerAdaptor* const _this, const GFxFunctionHandler::Params& params)>(0xE78B30);
};

// MeshCacheResetThread
// Header:  CryEngine/crysystem/scaleform/flashplayerinstance.h
class MeshCacheResetThread : public CrySimpleThread<CryRunnable>
{ // Size=72 (0x48)
public:
	volatile bool m_cancelRequestSent;
	CryEvent m_awakeThread;

	virtual void Run();
	virtual void Cancel();
	virtual ~MeshCacheResetThread();

#if 0
	MeshCacheResetThread();
	void IssueReset();
#endif

	static inline auto FRun = PreyFunction<void(MeshCacheResetThread* const _this)>(0xE7D3D0);
	static inline auto FCancel = PreyFunction<void(MeshCacheResetThread* const _this)>(0xE802C0);
};
#endif // !MOONCRASH
