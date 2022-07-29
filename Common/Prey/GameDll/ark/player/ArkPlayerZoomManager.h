// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerZoomManager.h
class ArkPlayerZoomManager // Id=801749C Size=48
{
public:
	class ZoomData // Id=801749D Size=12
	{
	public:
		int m_handle;
		float m_desiredHFOV;
		EArkZoomPriority m_priority;
		
#if 0
		bool operator==(const int arg0) const;
#endif
	};

	std::vector<ArkPlayerZoomManager::ZoomData> m_zoomStack;
	float m_currentHFOV;
	float m_prevDesiredHFOV;
	float m_interpTime;
	bool m_bUseUITime;
	int m_nearFOVLockedCount;
	int m_handleGenerator;
	
	ArkPlayerZoomManager();
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	int SetDesiredHFOV(float _hfov, float _interpTime, bool _bUseUITime, EArkZoomPriority _priority) { return FSetDesiredHFOV(this,_hfov,_interpTime,_bUseUITime,_priority); }
	void UpdateDesiredHFOV(int _handle, float _hfov, float _interpTime, bool _bUseUITime) { FUpdateDesiredHFOV(this,_handle,_hfov,_interpTime,_bUseUITime); }
	void ClearDesiredHFOV(int _handle, float _interpTime, bool _bUseUITime) { FClearDesiredHFOV(this,_handle,_interpTime,_bUseUITime); }
	float GetCurrentHFOV() const { return FGetCurrentHFOV(this); }
	float GetAdjustedCurrentHFOV() const { return FGetAdjustedCurrentHFOV(this); }
	float GetDesiredHFOV(const int _handle) const { return FGetDesiredHFOVOv0(this,_handle); }
	float GetHFOVDependentMultiplier(float _currentMultiplier, float _zoomedMultiplier) const { return FGetHFOVDependentMultiplier(this,_currentMultiplier,_zoomedMultiplier); }
	void SetNearFOVUnlocked(bool _bUnlocked) { FSetNearFOVUnlocked(this,_bUnlocked); }
	~ArkPlayerZoomManager();
	
#if 0
	float GetDesiredHFOV() const;
	bool IsZoomingIn() const;
	bool IsInterpolating() const;
	bool IsNearFOVLocked() const;
#endif
	
	static inline auto FReset = PreyFunction<void(ArkPlayerZoomManager *const _this)>(0x1464270);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerZoomManager *const _this, float _frameTime)>(0x1464450);
	static inline auto FSetDesiredHFOV = PreyFunction<int(ArkPlayerZoomManager *const _this, float _hfov, float _interpTime, bool _bUseUITime, EArkZoomPriority _priority)>(0x1464330);
	static inline auto FUpdateDesiredHFOV = PreyFunction<void(ArkPlayerZoomManager *const _this, int _handle, float _hfov, float _interpTime, bool _bUseUITime)>(0x14645E0);
	static inline auto FClearDesiredHFOV = PreyFunction<void(ArkPlayerZoomManager *const _this, int _handle, float _interpTime, bool _bUseUITime)>(0x1464060);
	static inline auto FGetCurrentHFOV = PreyFunction<float(ArkPlayerZoomManager const *const _this)>(0x1464110);
	static inline auto FGetAdjustedCurrentHFOV = PreyFunction<float(ArkPlayerZoomManager const *const _this)>(0x14640D0);
	static inline auto FGetDesiredHFOVOv0 = PreyFunction<float(ArkPlayerZoomManager const *const _this, const int _handle)>(0x1464120);
	static inline auto FGetHFOVDependentMultiplier = PreyFunction<float(ArkPlayerZoomManager const *const _this, float _currentMultiplier, float _zoomedMultiplier)>(0x1464150);
	static inline auto FSetNearFOVUnlocked = PreyFunction<void(ArkPlayerZoomManager *const _this, bool _bUnlocked)>(0x14643D0);
	static inline auto FBitNotArkPlayerZoomManager = PreyFunction<void(ArkPlayerZoomManager *const _this)>(0x1F09C0);
};

