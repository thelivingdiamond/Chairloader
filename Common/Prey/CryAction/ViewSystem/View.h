// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IViewSystem.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMath/Cry_Camera.h>
#include <Prey/CryNetwork/ISerialize.h>

class CGameObject;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct ISystem;
struct SEntityEvent;

// CView
// Header:  CryEngine/cryaction/viewsystem/View.h
class CView : public IView, public IEntityEventListener
{ // Size=872 (0x368)
public:
	// CView::SShake
	// Header:  CryEngine/cryaction/viewsystem/View.h
	struct SShake
	{ // Size=212 (0xD4)
		bool updating;
		bool flip;
		bool doFlip;
		bool groundOnly;
		bool permanent;
		bool interrupted;
		bool isSmooth;
		const int ID;
		float nextShake;
		float timeDone;
		float sustainDuration;
		float fadeInDuration;
		float fadeOutDuration;
		float speed;
		float frequency;
		float ratio;
		float randomness;
		Quat startShake;
		Quat startShakeSpeed;
		Vec3 startShakeVector;
		Vec3 startShakeVectorSpeed;
		Quat goalShake;
		Quat goalShakeSpeed;
		Vec3 goalShakeVector;
		Vec3 goalShakeVectorSpeed;
		Ang3 amount;
		Vec3 amountVector;
		Quat shakeQuat;
		Vec3 shakeVector;

	#if 0
		SShake(const int _arg0_);
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	unsigned m_linkedTo;
	SViewParams m_viewParams;
	CCamera m_camera;
	ISystem* const m_pSystem;
	std::vector<CView::SShake> m_shakes;
	IEntity* m_pAudioListener;
	Ang3 m_frameAdditiveAngles;
	float m_scale;
	float m_zoomedScale;

	CView(ISystem* const pSystem);
	virtual ~CView();
	virtual void Release();
	virtual void Update(float frameTime, bool isActive);
	virtual void ProcessShaking(float frameTime);
	virtual void ProcessShake(CView::SShake* pShake, float frameTime);
	virtual void ResetShaking();
	virtual void ResetBlending();
	virtual void LinkTo(IGameObject* follow);
	virtual void LinkTo(IEntity* follow);
	virtual unsigned GetLinkedId();
	virtual void SetCurrentParams(SViewParams& params);
	virtual const SViewParams* GetCurrentParams();
	virtual void SetViewShake(Ang3 shakeAngle, Vec3 shakeShift, float duration, float frequency, float randomness, int shakeID, bool bFlipVec, bool bUpdateOnly, bool bGroundOnly);
	virtual void SetViewShakeEx(const IView::SShakeParams& params);
	virtual void StopShake(int shakeID);
	virtual void SetFrameAdditiveCameraAngles(const Ang3& addFrameAngles);
	virtual void SetScale(const float scale);
	virtual void SetZoomedScale(const float scale);
	virtual void SetActive(const bool bActive);
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	void PostSerialize() { FPostSerialize(this); }
	void UpdateAudioListener(const Matrix34& rMatrix, bool bInvalidateListener) { FUpdateAudioListener(this, rMatrix, bInvalidateListener); }
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }
	void ProcessShakeNormal(CView::SShake* pShake, float frameTime) { FProcessShakeNormal(this, pShake, frameTime); }
	void ProcessShakeNormal_FinalDamping(CView::SShake* pShake, float frameTime) { FProcessShakeNormal_FinalDamping(this, pShake, frameTime); }
	void ProcessShakeNormal_DoShaking(CView::SShake* pShake, float frameTime) { FProcessShakeNormal_DoShaking(this, pShake, frameTime); }
	void ProcessShakeSmooth(CView::SShake* pShake, float frameTime) { FProcessShakeSmooth(this, pShake, frameTime); }
	void ProcessShakeSmooth_DoShaking(CView::SShake* pShake, float frameTime) { FProcessShakeSmooth_DoShaking(this, pShake, frameTime); }
	void ApplyFrameAdditiveAngles(Quat& cameraOrientation) { FApplyFrameAdditiveAngles(this, cameraOrientation); }
	void GetRandomQuat(Quat& quat, CView::SShake* pShake) { FGetRandomQuat(this, quat, pShake); }
	void GetRandomVector(Vec3& vec, CView::SShake* pShake) { FGetRandomVector(this, vec, pShake); }
	void CubeInterpolateQuat(float t, CView::SShake* pShake) { FCubeInterpolateQuat(this, t, pShake); }
	void CubeInterpolateVector(float t, CView::SShake* pShake) { FCubeInterpolateVector(this, t, pShake); }
	void CreateAudioListener() { FCreateAudioListener(this); }

#if 0
	CCamera& GetCamera();
	CGameObject* GetLinkedGameObject();
	IEntity* GetLinkedEntity();
	void ProcessShakeNormal_CalcRatio(CView::SShake* _arg0_, float _arg1_, float _arg2_);
	const float GetScale();
#endif

	static inline auto FCViewOv1 = PreyFunction<void(CView* const _this, ISystem* const pSystem)>(0x3D5840);
	static inline auto FRelease = PreyFunction<void(CView* const _this)>(0xA97D40);
	static inline auto FUpdate = PreyFunction<void(CView* const _this, float frameTime, bool isActive)>(0x3D9390);
	static inline auto FProcessShaking = PreyFunction<void(CView* const _this, float frameTime)>(0x3D8C30);
	static inline auto FProcessShake = PreyFunction<void(CView* const _this, CView::SShake* pShake, float frameTime)>(0x3D7180);
	static inline auto FResetShaking = PreyFunction<void(CView* const _this)>(0x3D8D10);
	static inline auto FResetBlending = PreyFunction<void(CView* const _this)>(0x3D8CE0);
	static inline auto FLinkToOv1 = PreyFunction<void(CView* const _this, IGameObject* follow)>(0x3D7090);
	static inline auto FLinkToOv0 = PreyFunction<void(CView* const _this, IEntity* follow)>(0x3D7040);
	static inline auto FGetLinkedId = PreyFunction<unsigned(CView* const _this)>(0x985E40);
	static inline auto FSetCurrentParams = PreyFunction<void(CView* const _this, SViewParams& params)>(0x3D8D90);
	static inline auto FGetCurrentParams = PreyFunction<const SViewParams* (CView* const _this)>(0x12BDAA0);
	static inline auto FSetViewShake = PreyFunction<void(CView* const _this, Ang3 shakeAngle, Vec3 shakeShift, float duration, float frequency, float randomness, int shakeID, bool bFlipVec, bool bUpdateOnly, bool bGroundOnly)>(0x3D8F80);
	static inline auto FSetViewShakeEx = PreyFunction<void(CView* const _this, const IView::SShakeParams& params)>(0x3D9030);
	static inline auto FStopShake = PreyFunction<void(CView* const _this, int shakeID)>(0x3D9320);
	static inline auto FSetFrameAdditiveCameraAngles = PreyFunction<void(CView* const _this, const Ang3& addFrameAngles)>(0x3D8F50);
	static inline auto FSetScale = PreyFunction<void(CView* const _this, const float scale)>(0x3D8F70);
	static inline auto FSetZoomedScale = PreyFunction<void(CView* const _this, const float scale)>(0x3D9310);
	static inline auto FSetActive = PreyFunction<void(CView* const _this, const bool bActive)>(0x3D8D80);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x3D70D0);
	static inline auto FSerialize = PreyFunction<void(CView* const _this, TSerialize ser)>(0x3D8D50);
	static inline auto FPostSerialize = PreyFunction<void(CView* const _this)>(0x3D7170);
	static inline auto FUpdateAudioListener = PreyFunction<void(CView* const _this, const Matrix34& rMatrix, bool bInvalidateListener)>(0x3D9F50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CView* const _this, ICrySizer* s)>(0x3D6A40);
	static inline auto FProcessShakeNormal = PreyFunction<void(CView* const _this, CView::SShake* pShake, float frameTime)>(0x3D71B0);
	static inline auto FProcessShakeNormal_FinalDamping = PreyFunction<void(CView* const _this, CView::SShake* pShake, float frameTime)>(0x3D80C0);
	static inline auto FProcessShakeNormal_DoShaking = PreyFunction<void(CView* const _this, CView::SShake* pShake, float frameTime)>(0x3D7480);
	static inline auto FProcessShakeSmooth = PreyFunction<void(CView* const _this, CView::SShake* pShake, float frameTime)>(0x3D85D0);
	static inline auto FProcessShakeSmooth_DoShaking = PreyFunction<void(CView* const _this, CView::SShake* pShake, float frameTime)>(0x3D8A00);
	static inline auto FApplyFrameAdditiveAngles = PreyFunction<void(CView* const _this, Quat& cameraOrientation)>(0x3D5E10);
	static inline auto FGetRandomQuat = PreyFunction<void(CView* const _this, Quat& quat, CView::SShake* pShake)>(0x3D6AE0);
	static inline auto FGetRandomVector = PreyFunction<void(CView* const _this, Vec3& vec, CView::SShake* pShake)>(0x3D6EA0);
	static inline auto FCubeInterpolateQuat = PreyFunction<void(CView* const _this, float t, CView::SShake* pShake)>(0x3D63A0);
	static inline auto FCubeInterpolateVector = PreyFunction<void(CView* const _this, float t, CView::SShake* pShake)>(0x3D67A0);
	static inline auto FCreateAudioListener = PreyFunction<void(CView* const _this)>(0x3D6110);
};

