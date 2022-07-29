// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IUIModule.h
struct IUIModule // Id=8002304 Size=8
{
	virtual ~IUIModule();
	virtual void Init();
	virtual void Shutdown();
	virtual void Reload();
	virtual void Reset();
	virtual void UpdateModule(float fDelta);
	virtual bool EditorAllowReload();
	virtual void EditorReload();
	
	static inline auto FInit = PreyFunction<void(IUIModule *const _this)>(0xA13080);
	static inline auto FShutdown = PreyFunction<void(IUIModule *const _this)>(0xA13080);
	static inline auto FReload = PreyFunction<void(IUIModule *const _this)>(0xA13080);
	static inline auto FReset = PreyFunction<void(IUIModule *const _this)>(0xA13080);
	static inline auto FUpdateModule = PreyFunction<void(IUIModule *const _this, float fDelta)>(0xA13080);
	static inline auto FEditorAllowReload = PreyFunction<bool(IUIModule *const _this)>(0x1B933B0);
	static inline auto FEditorReload = PreyFunction<void(IUIModule *const _this)>(0xA13080);
};

