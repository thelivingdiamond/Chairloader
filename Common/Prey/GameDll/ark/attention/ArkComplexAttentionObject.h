// Header file automatically created from a PDB.

#pragma once
struct ArkAttentionLevelChange;

// Header: FromCpp
// Prey/GameDll/ark/attention/arkcomplexattentionobject.h
class ArkSimpleAttentionObject : private boost::noncopyable_::noncopyable // Id=8014318 Size=8
{
public:
#ifndef MOONCRASH
	Vec3 GetSimpleAttentionObjectWorldPos() const { return FGetSimpleAttentionObjectWorldPos(this); }
#else
	Vec3 GetSimpleAttentionObjectWorldPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetSimpleAttentionObjectWorldPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	bool GetIsGlood() const { return FGetIsGlood(this); }
#endif
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const = 0;
#ifdef MOONCRASH
	virtual bool DoGetIsGlood() const = 0;
#endif

#if 0
	unsigned GetEntityId() const;
	~ArkSimpleAttentionObject();
#endif

#ifndef MOONCRASH
	static inline auto FGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3(ArkSimpleAttentionObject const *const _this)>(0x13EF180);
#else
	static inline auto FGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3*(const ArkSimpleAttentionObject* const _this, Vec3* _return_value_)>(0x12B5850);
	static inline auto FGetIsGlood = PreyFunction<bool(const ArkSimpleAttentionObject* const _this)>(0x6CBC30);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkComplexAttentionObject.h
class ArkComplexAttentionObject : private boost::noncopyable_::noncopyable // Id=8014DAE Size=8
{
public:
#ifndef MOONCRASH
	Vec3 GetAttentionPosition() const { return FGetAttentionPosition(this); }
#else
	Vec3 GetAttentionPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetAttentionPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
#endif
	void OnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange) { FOnAttentionLevelsChanged(this,_pFirstChange,_pLastChange); }
#ifdef MOONCRASH
	bool GetIsGlood() const { return FGetIsGlood(this); }
#endif
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetAttentionPosition() const = 0;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *arg0, ArkAttentionLevelChange const *arg1) = 0;
#ifdef MOONCRASH
	virtual bool DoGetIsGlood() const = 0;
#endif

#if 0
	unsigned GetEntityId() const;
	~ArkComplexAttentionObject();
#endif

#ifndef MOONCRASH
	static inline auto FGetAttentionPosition = PreyFunction<Vec3(ArkComplexAttentionObject const *const _this)>(0x13EF180);
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkComplexAttentionObject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x15AAEA0);
#else
	static inline auto FGetAttentionPosition = PreyFunction<Vec3*(const ArkComplexAttentionObject* const _this, Vec3* _return_value_)>(0x12B5850);
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkComplexAttentionObject* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x6CBC30);
	static inline auto FGetIsGlood = PreyFunction<bool(const ArkComplexAttentionObject* const _this)>(0x1338520);
#endif
};
