// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Chairloader/pch.h>
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// CryEngine/cryaction/ark/ArkAudioSwitchManager.h
class ArkAudioSwitchManager // Id=800460A Size=24
{
public:
	class SwitchState // Id=800460B Size=12
	{
	public:
		unsigned m_entityId;
		unsigned m_switch;
		unsigned m_state;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(ArkAudioSwitchManager::SwitchState const &arg0) const;
#endif
	};

	std::vector<ArkAudioSwitchManager::SwitchState> m_switchStates;
	
	void UpdateSwitchState(unsigned _entityId, const unsigned _switch, const unsigned _state) { FUpdateSwitchState(this,_entityId,_switch,_state); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }

#ifndef MOONCRASH
	static inline auto FUpdateSwitchState = PreyFunction<void(ArkAudioSwitchManager *const _this, unsigned _entityId, const unsigned _switch, const unsigned _state)>(0x2A33B0);
	static inline auto FSerialize = PreyFunction<void(ArkAudioSwitchManager *const _this, TSerialize _ser)>(0x2A3390);
	static inline auto FPostSerialize = PreyFunction<void(ArkAudioSwitchManager *const _this)>(0x2A31E0);
	static inline auto FReset = PreyFunction<void(ArkAudioSwitchManager *const _this)>(0x2A3380);
#else
	static inline auto FUpdateSwitchState = PreyFunction<void(ArkAudioSwitchManager* const _this, unsigned _entityId, const unsigned _switch, const unsigned _state)>(0x2BB910);
	static inline auto FSerialize = PreyFunction<void(ArkAudioSwitchManager* const _this, TSerialize _ser)>(0x2BB8F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkAudioSwitchManager* const _this)>(0x2BB750);
	static inline auto FReset = PreyFunction<void(ArkAudioSwitchManager* const _this)>(0x13E7040);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkAudioSwitchManager
// Header:  CryEngine/cryaction/ark/ArkAudioSwitchManager.h
class ArkAudioSwitchManager
{ // Size=24 (0x18)
public:
	// ArkAudioSwitchManager::SwitchState
	// Header:  CryEngine/cryaction/ark/ArkAudioSwitchManager.h
	class SwitchState
	{ // Size=12 (0xC)
	public:
		unsigned m_entityId;
		unsigned m_switch;
		unsigned m_state;

	#if 0
		SwitchState();
		SwitchState(unsigned _arg0_, const unsigned _arg1_);
		SwitchState(unsigned _arg0_, const unsigned _arg1_, const unsigned _arg2_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const ArkAudioSwitchManager::SwitchState& _arg0_) const;
	#endif
	};

	std::vector<ArkAudioSwitchManager::SwitchState> m_switchStates;

	void UpdateSwitchState(unsigned _entityId, const unsigned _switch, const unsigned _state) { FUpdateSwitchState(this, _entityId, _switch, _state); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }

	static inline auto FUpdateSwitchState = PreyFunction<void(ArkAudioSwitchManager* const _this, unsigned _entityId, const unsigned _switch, const unsigned _state)>(0x2BB910);
	static inline auto FSerialize = PreyFunction<void(ArkAudioSwitchManager* const _this, TSerialize _ser)>(0x2BB8F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkAudioSwitchManager* const _this)>(0x2BB750);
	static inline auto FReset = PreyFunction<void(ArkAudioSwitchManager* const _this)>(0x13E7040);
};
#endif // !MOONCRASH
