// Header file automatically created from a PDB.

#pragma once
#include <Chairloader/PreyFunction.h>
#include <Prey/CryCore/StdAfx.h>
//#include <Prey/GameDll/ark/npc/desires/arknpcdesiretarget.h>
#include <boost/variant.hpp>
#include <Prey/CryEntitySystem/IEntity.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcNoDesireTargetImpl.h>
#include <boost/optional.hpp>
#include "ArkNpcPositionDesireTargetImpl.h"
#include "ArkNpcDirectionDesireTargetImpl.h"
#include "ArkNpcEntityOffsetTargetImpl.h"
#include "ArkNpcAttackPositionDesireTargetImpl.h"

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/arknpcdesiretarget.h
#ifdef MOONCRASH
enum class EArkNpcDesireTargetRefreshResult;
enum class EArkNpcDesireTargetType;
#endif
class ArkNpcEntityDesireTargetImpl // Id=80140AD Size=20
{
public:
    unsigned m_entityId;
    float m_tolerance;
    Vec3 m_position;

    EArkNpcDesireTargetRefreshResult Refresh() { return FRefresh(this); }

#if 0
    bool operator==(ArkNpcEntityDesireTargetImpl const &arg0) const;
	bool IsValid() const;
	bool HasPosition() const;
	bool IsStatic() const;
	Vec3 GetPosition() const;
	bool HasDirection() const;
	Vec3 GetDirection() const;
	unsigned GetEntityId() const;
	float GetTolerance() const;
	void SetTolerance(float arg0);
#endif

#ifndef MOONCRASH
    static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcEntityDesireTargetImpl *const _this)>(0x1525BF0);
#else
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcEntityDesireTargetImpl* const _this)>(0x1645580);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/arknpcdesiretarget.h
class ArkNpcEntityBoneDesireTargetImpl // Id=80140AF Size=24
{
public:
    unsigned m_entityId;
    float m_tolerance;
    int m_boneId;
    Vec3 m_position;

    EArkNpcDesireTargetRefreshResult Refresh() { return FRefresh(this); }

#if 0
    bool operator==(ArkNpcEntityBoneDesireTargetImpl const &arg0) const;
	bool IsValid() const;
	bool HasPosition() const;
	bool IsStatic() const;
	Vec3 GetPosition() const;
	bool HasDirection() const;
	Vec3 GetDirection() const;
	unsigned GetEntityId() const;
	float GetTolerance() const;
	void SetTolerance(float arg0);
#endif

#ifndef MOONCRASH
    static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcEntityBoneDesireTargetImpl *const _this)>(0x15259A0);
#else
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcEntityBoneDesireTargetImpl* const _this)>(0x1645330);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/arknpcdesiretarget.h
class ArkNpcEntityBoundsCenterTargetImpl // Id=80140B3 Size=20
{
public:
    unsigned m_entityId;
    float m_tolerance;
    Vec3 m_position;

    EArkNpcDesireTargetRefreshResult Refresh() { return FRefresh(this); }

#if 0
    bool operator==(ArkNpcEntityBoundsCenterTargetImpl const &arg0) const;
	bool IsValid() const;
	bool HasPosition() const;
	bool IsStatic() const;
	Vec3 GetPosition() const;
	bool HasDirection() const;
	Vec3 GetDirection() const;
	unsigned GetEntityId() const;
	float GetTolerance() const;
	void SetTolerance(float arg0);
#endif

#ifndef MOONCRASH
    static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcEntityBoundsCenterTargetImpl *const _this)>(0x1525B10);
#else
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcEntityBoundsCenterTargetImpl* const _this)>(0x16454A0);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/arknpcdesiretarget.h
class ArkNpcAttentionProxyDesireTargetImpl // Id=80140B5 Size=28
{
public:
    float m_tolerance;
    unsigned m_npcEntityId;
    unsigned m_targetEntityId;
    boost::optional<Vec3> m_maybePosition;

    EArkNpcDesireTargetRefreshResult Refresh() { return FRefresh(this); }

#if 0
    bool operator==(ArkNpcAttentionProxyDesireTargetImpl const &arg0) const;
	bool IsValid() const;
	bool HasPosition() const;
	bool IsStatic() const;
	Vec3 GetPosition() const;
	bool HasDirection() const;
	Vec3 GetDirection() const;
	unsigned GetEntityId() const;
	float GetTolerance() const;
	void SetTolerance(float arg0);
#endif

#ifndef MOONCRASH
    static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcAttentionProxyDesireTargetImpl *const _this)>(0x15257C0);
#else
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcAttentionProxyDesireTargetImpl* const _this)>(0x1645150);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/arknpcdesiretarget.h
class ArkNpcCameraDesireTargetImpl // Id=80140B7 Size=16
{
public:
    float m_tolerance;
    Vec3 m_position;

    EArkNpcDesireTargetRefreshResult Refresh() { return FRefresh(this); }

#if 0
    bool operator==(ArkNpcCameraDesireTargetImpl const &arg0) const;
	bool IsValid() const;
	bool HasPosition() const;
	bool IsStatic() const;
	Vec3 GetPosition() const;
	bool HasDirection() const;
	Vec3 GetDirection() const;
	unsigned GetEntityId() const;
	float GetTolerance() const;
	void SetTolerance(float arg0);
#endif

#ifndef MOONCRASH
    static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcCameraDesireTargetImpl *const _this)>(0x15258B0);
#else
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcCameraDesireTargetImpl* const _this)>(0x1645240);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h
class ArkNpcDesireTarget // Id=80140A3 Size=36
{
public:
	using ArkNpcDesireTargetVariant = boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end> > > > > > > > > > > >;
	
	ArkNpcDesireTargetVariant m_target;
	
	static ArkNpcDesireTarget None() { return FNone(); }
	static ArkNpcDesireTarget LookAtPos(IEntity const &_entity) { return FLookAtPos(_entity); }
	static ArkNpcDesireTarget AttentionProxy(unsigned _npcEntityId, unsigned _targetEntityId) { return FAttentionProxyOv1(_npcEntityId,_targetEntityId); }
	static ArkNpcDesireTarget AttentionProxy(IEntity const &_npcEntity, IEntity const &_targetEntity) { return FAttentionProxyOv0(_npcEntity,_targetEntity); }
	static ArkNpcDesireTarget AttackPosition(IEntity const &_entity) { return FAttackPosition(_entity); }
	static ArkNpcDesireTarget Direction(Vec3 const &_dir) { return FDirection(_dir); }
	ArkNpcDesireTarget();
	ArkNpcDesireTarget(Vec3 const &_position);
	ArkNpcDesireTarget(IEntity const &_entity);
	ArkNpcDesireTarget(IEntity const &_entity, float _tolerance);
	bool operator!=(ArkNpcDesireTarget const &_other) const { return FoperatorNotEq(this,_other); }
	EArkNpcDesireTargetType GetTargetType() const { return FGetTargetType(this); }
	bool IsValid() const { return FIsValid(this); }
	bool HasPosition() const { return FHasPosition(this); }
	bool HasDirection() const { return FHasDirection(this); }
#ifndef MOONCRASH
	Vec3 GetPosition() const { return FGetPosition(this); }
	Vec3 GetDirection() const { return FGetDirection(this); }
#else
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetDirection() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetDirection(this, reinterpret_cast<Vec3*>(_return_buf_)); }
#endif
	unsigned GetEntityId() const { return FGetEntityId(this); }
	float GetTolerance() const { return FGetTolerance(this); }
	void SetTolerance(float _tolerance) { FSetTolerance(this,_tolerance); }
	EArkNpcDesireTargetRefreshResult Refresh() { return FRefresh(this); }
	
#if 0
	static ArkNpcDesireTarget Player();
	static ArkNpcDesireTarget BoundsCenter(IEntity const &arg0);
	static ArkNpcDesireTarget EntityOffset(IEntity const &arg0, Vec3 const &arg1);
	bool operator==(ArkNpcDesireTarget const &arg0) const;
	bool IsStatic() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FNone = PreyFunction<ArkNpcDesireTarget()>(0x1524620);
	static inline auto FLookAtPos = PreyFunction<ArkNpcDesireTarget(IEntity const &_entity)>(0x15254A0);
	static inline auto FAttentionProxyOv1 = PreyFunction<ArkNpcDesireTarget(unsigned _npcEntityId, unsigned _targetEntityId)>(0x1524F20);
	static inline auto FAttentionProxyOv0 = PreyFunction<ArkNpcDesireTarget(IEntity const &_npcEntity, IEntity const &_targetEntity)>(0x1524DD0);
	static inline auto FAttackPosition = PreyFunction<ArkNpcDesireTarget(IEntity const &_entity)>(0x1524CD0);
	static inline auto FDirection = PreyFunction<ArkNpcDesireTarget(Vec3 const &_dir)>(0x1525050);
	static inline auto FoperatorNotEq = PreyFunction<bool(ArkNpcDesireTarget const *const _this, ArkNpcDesireTarget const &_other)>(0x1524630);
	static inline auto FGetTargetType = PreyFunction<EArkNpcDesireTargetType(ArkNpcDesireTarget const *const _this)>(0x15252F0);
	static inline auto FIsValid = PreyFunction<bool(ArkNpcDesireTarget const *const _this)>(0x1525440);
	static inline auto FHasPosition = PreyFunction<bool(ArkNpcDesireTarget const *const _this)>(0x15253E0);
	static inline auto FHasDirection = PreyFunction<bool(ArkNpcDesireTarget const *const _this)>(0x1525390);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkNpcDesireTarget const *const _this)>(0x1525290);
	static inline auto FGetDirection = PreyFunction<Vec3(ArkNpcDesireTarget const *const _this)>(0x15251E0);
	static inline auto FGetEntityId = PreyFunction<unsigned(ArkNpcDesireTarget const *const _this)>(0x1525240);
	static inline auto FGetTolerance = PreyFunction<float(ArkNpcDesireTarget const *const _this)>(0x1525340);
	static inline auto FSetTolerance = PreyFunction<void(ArkNpcDesireTarget *const _this, float _tolerance)>(0x1525CA0);
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcDesireTarget *const _this)>(0x1525940);
#else
	static inline auto FNone = PreyFunction<ArkNpcDesireTarget()>(0x1643FB0);
	static inline auto FLookAtPos = PreyFunction<ArkNpcDesireTarget(const IEntity& _entity)>(0x1644E30);
	static inline auto FAttentionProxyOv1 = PreyFunction<ArkNpcDesireTarget(unsigned _npcEntityId, unsigned _targetEntityId)>(0x16448B0);
	static inline auto FAttentionProxyOv0 = PreyFunction<ArkNpcDesireTarget(const IEntity& _npcEntity, const IEntity& _targetEntity)>(0x1644760);
	static inline auto FAttackPosition = PreyFunction<ArkNpcDesireTarget(const IEntity& _entity)>(0x1644660);
	static inline auto FDirection = PreyFunction<ArkNpcDesireTarget(const Vec3& _dir)>(0x16449E0);
	static inline auto FArkNpcDesireTargetOv8 = PreyFunction<void(ArkNpcDesireTarget* const _this)>(0x1643FB0);
	static inline auto FArkNpcDesireTargetOv7 = PreyFunction<void(ArkNpcDesireTarget* const _this, const Vec3& _position)>(0x1643EC0);
	static inline auto FArkNpcDesireTargetOv5 = PreyFunction<void(ArkNpcDesireTarget* const _this, const IEntity& _entity)>(0x1643EF0);
	static inline auto FArkNpcDesireTargetOv4 = PreyFunction<void(ArkNpcDesireTarget* const _this, const IEntity& _entity, float _tolerance)>(0x1643F40);
	static inline auto FoperatorNotEq = PreyFunction<bool(const ArkNpcDesireTarget* const _this, const ArkNpcDesireTarget& _other)>(0x1643FC0);
	static inline auto FGetTargetType = PreyFunction<EArkNpcDesireTargetType(const ArkNpcDesireTarget* const _this)>(0x1644C80);
	static inline auto FIsValid = PreyFunction<bool(const ArkNpcDesireTarget* const _this)>(0x1644DD0);
	static inline auto FHasPosition = PreyFunction<bool(const ArkNpcDesireTarget* const _this)>(0x1644D70);
	static inline auto FHasDirection = PreyFunction<bool(const ArkNpcDesireTarget* const _this)>(0x1644D20);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkNpcDesireTarget* const _this, Vec3* _return_value_)>(0x1644C20);
	static inline auto FGetDirection = PreyFunction<Vec3*(const ArkNpcDesireTarget* const _this, Vec3* _return_value_)>(0x1644B70);
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkNpcDesireTarget* const _this)>(0x1644BD0);
	static inline auto FGetTolerance = PreyFunction<float(const ArkNpcDesireTarget* const _this)>(0x1644CD0);
	static inline auto FSetTolerance = PreyFunction<void(ArkNpcDesireTarget* const _this, float _tolerance)>(0x1645630);
	static inline auto FRefresh = PreyFunction<EArkNpcDesireTargetRefreshResult(ArkNpcDesireTarget* const _this)>(0x16452D0);
#endif
};
