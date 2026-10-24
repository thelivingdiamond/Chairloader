// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>

class IScope;
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
struct CArkAttachmentEventParams;
#endif
namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/ark/arkattachmentclipevent.h
struct CArkAttachmentEventParams : public IProceduralParams // Id=8018FC4 Size=24
{
	CCryName m_pTargetScopeName;
	CCryName m_pBoneAttachmentName;
	
	virtual void Serialize(Serialization::IArchive &ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char> &extraInfoOut) const;
	virtual ~CArkAttachmentEventParams();
	
#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(CArkAttachmentEventParams *const _this, Serialization::IArchive &ar)>(0x114C130);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(CArkAttachmentEventParams const *const _this, IProceduralParams::StringWrapperImpl<char> &extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(CArkAttachmentEventParams* const _this, Serialization::IArchive& ar)>(0x1192FB0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const CArkAttachmentEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkattachmentclipevent.h
class CArkAttachmentClipEvent : public TProceduralClip<CArkAttachmentEventParams> // Id=8018FC2 Size=72
{
public:
	unsigned m_targetEntityId;
	float m_blendTimeRemaining;
	
	virtual void OnEnter(float blendTime, float duration, CArkAttachmentEventParams const &params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	IScope *GetTargetScope() const { return FGetTargetScope(this); }
	virtual ~CArkAttachmentClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkAttachmentClipEvent *const _this, float blendTime, float duration, CArkAttachmentEventParams const &params)>(0x114B910);
	static inline auto FOnExit = PreyFunction<void(CArkAttachmentClipEvent *const _this, float blendTime)>(0x114B940);
	static inline auto FUpdate = PreyFunction<void(CArkAttachmentClipEvent *const _this, float timePassed)>(0x114BC40);
	static inline auto FGetTargetScope = PreyFunction<IScope *(CArkAttachmentClipEvent const *const _this)>(0x114C080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkAttachmentClipEvent* const _this, float blendTime, float duration, const CArkAttachmentEventParams& params)>(0x1192700);
	static inline auto FOnExit = PreyFunction<void(CArkAttachmentClipEvent* const _this, float blendTime)>(0x1192730);
	static inline auto FUpdate = PreyFunction<void(CArkAttachmentClipEvent* const _this, float timePassed)>(0x1192A30);
	static inline auto FGetTargetScope = PreyFunction<IScope* (const CArkAttachmentClipEvent* const _this)>(0x1192F00);
#endif
};
