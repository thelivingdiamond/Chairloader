// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct IAttachmentObject;
struct IAttachmentSkin;
class ICrySizer;
struct ISkin;
struct SimulationParams;

// IAttachment
// Header:  _unknown/IAttachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct IAttachment
{ // Size=8 (0x8)
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual const char* GetName() const = 0;
	virtual unsigned GetNameCRC() const = 0;
	virtual unsigned ReName(const char* szSocketName, unsigned crc) = 0;
	virtual unsigned GetType() const = 0;
	virtual unsigned SetJointName(const char* szJointName) = 0;
	virtual void SetFlags(unsigned flags) = 0;
	virtual unsigned GetFlags() const = 0;
	virtual void SetAttAbsoluteDefault(const QuatT& qt) = 0;
	virtual const QuatT& GetAttAbsoluteDefault() const = 0;
	virtual void SetAttRelativeDefault(const QuatT& qt) = 0;
	virtual const QuatT& GetAttRelativeDefault() const = 0;
	virtual const QuatT& GetAttModelRelative() const = 0;
	virtual const QuatTS GetAttWorldAbsolute() const = 0;
	virtual void UpdateAttModelRelative() = 0;
	virtual unsigned ProjectAttachment() = 0;
	virtual void HideAttachment(unsigned x) = 0;
	virtual unsigned IsAttachmentHidden() const = 0;
	virtual void HideInRecursion(unsigned x) = 0;
	virtual unsigned IsAttachmentHiddenInRecursion() const = 0;
	virtual void HideInShadow(unsigned x) = 0;
	virtual unsigned IsAttachmentHiddenInShadow() const = 0;
	virtual void AlignJointAttachment() = 0;
	virtual unsigned GetJointID() const = 0;
	virtual IAttachmentObject* GetIAttachmentObject() const = 0;
	virtual IAttachmentSkin* GetIAttachmentSkin() = 0;
	virtual unsigned AddBinding(IAttachmentObject* pIAttachmentObject, ISkin* pISkin, unsigned nLoadingFlags) = 0;
	virtual void ClearBinding(unsigned nLoadingFlags) = 0;
	virtual unsigned SwapBinding(IAttachment* pNewAttachment) = 0;
	virtual SimulationParams GetSimulationParams() const = 0;
	virtual void SetSimulationParams(const SimulationParams& ap) = 0;
	virtual uint64_t SizeOfThis() const = 0;
	virtual void Serialize(TSerialize ser) = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	virtual ~IAttachment();
};

