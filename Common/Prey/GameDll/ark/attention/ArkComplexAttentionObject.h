// Auto-merged (base-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
struct ArkAttentionLevelChange;

// Header: FromCpp
// Prey/GameDll/ark/attention/arkcomplexattentionobject.h
class ArkSimpleAttentionObject : private boost::noncopyable_::noncopyable // Id=8014318 Size=8
{
public:
	Vec3 GetSimpleAttentionObjectWorldPos() const { return FGetSimpleAttentionObjectWorldPos(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const = 0;
	
#if 0
	unsigned GetEntityId() const;
#endif

	static inline auto FGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3(ArkSimpleAttentionObject const *const _this)>(0x13EF180);
};

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkComplexAttentionObject.h
class ArkComplexAttentionObject : private boost::noncopyable_::noncopyable // Id=8014DAE Size=8
{
public:
	Vec3 GetAttentionPosition() const { return FGetAttentionPosition(this); }
	void OnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange) { FOnAttentionLevelsChanged(this,_pFirstChange,_pLastChange); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetAttentionPosition() const = 0;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *arg0, ArkAttentionLevelChange const *arg1) = 0;
	
#if 0
	unsigned GetEntityId() const;
#endif
	
	static inline auto FGetAttentionPosition = PreyFunction<Vec3(ArkComplexAttentionObject const *const _this)>(0x13EF180);
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkComplexAttentionObject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x15AAEA0);
};
#else
// Header file automatically created from a PDB.
#pragma once
struct ArkAttentionLevelChange;

// ArkSimpleAttentionObject
// Header:  _unknown/ArkSimpleAttentionObject.h
class ArkSimpleAttentionObject : private boost::noncopyable_::noncopyable
{ // Size=8 (0x8)
public:
	Vec3 GetSimpleAttentionObjectWorldPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetSimpleAttentionObjectWorldPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	bool GetIsGlood() const { return FGetIsGlood(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const = 0;
	virtual bool DoGetIsGlood() const = 0;

#if 0
	unsigned GetEntityId() const;
	~ArkSimpleAttentionObject();
#endif

	static inline auto FGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3*(const ArkSimpleAttentionObject* const _this, Vec3* _return_value_)>(0x12B5850);
	static inline auto FGetIsGlood = PreyFunction<bool(const ArkSimpleAttentionObject* const _this)>(0x6CBC30);
};

// ArkComplexAttentionObject
// Header:  _unknown/ArkComplexAttentionObject.h
class ArkComplexAttentionObject : private boost::noncopyable_::noncopyable
{ // Size=8 (0x8)
public:
	Vec3 GetAttentionPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetAttentionPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	void OnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange) { FOnAttentionLevelsChanged(this, _pFirstChange, _pLastChange); }
	bool GetIsGlood() const { return FGetIsGlood(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetAttentionPosition() const = 0;
	virtual void DoOnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange) = 0;
	virtual bool DoGetIsGlood() const = 0;

#if 0
	unsigned GetEntityId() const;
	~ArkComplexAttentionObject();
#endif

	static inline auto FGetAttentionPosition = PreyFunction<Vec3*(const ArkComplexAttentionObject* const _this, Vec3* _return_value_)>(0x12B5850);
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkComplexAttentionObject* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x6CBC30);
	static inline auto FGetIsGlood = PreyFunction<bool(const ArkComplexAttentionObject* const _this)>(0x1338520);
};
#endif // !MOONCRASH
