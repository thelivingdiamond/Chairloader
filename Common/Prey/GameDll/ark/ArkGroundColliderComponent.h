// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/ArkGroundColliderComponent.h
class ArkGroundColliderComponent // Id=80164C4 Size=16
{
public:
	IEntity const *m_pOwner;
	unsigned m_groundEntity;
	
	void Update() { FUpdate(this); }
	
#if 0
	void Init(IEntity const &arg0);
	unsigned GetGroundEntity() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkGroundColliderComponent *const _this)>(0x13C26B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkGroundColliderComponent
// Header:  Prey/GameDll/ark/ArkGroundColliderComponent.h
class ArkGroundColliderComponent
{ // Size=16 (0x10)
public:
	const IEntity* m_pOwner;
	unsigned m_groundEntity;

	void Update() { FUpdate(this); }

#if 0
	ArkGroundColliderComponent();
	void Init(const IEntity& _arg0_);
	unsigned GetGroundEntity() const;
#endif

	static inline auto FUpdate = PreyFunction<void(ArkGroundColliderComponent* const _this)>(0x14CE750);
};
#endif // !MOONCRASH
