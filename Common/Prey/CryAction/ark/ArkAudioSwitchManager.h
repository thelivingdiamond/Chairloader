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
	
	static inline auto FUpdateSwitchState = PreyFunction<void(ArkAudioSwitchManager *const _this, unsigned _entityId, const unsigned _switch, const unsigned _state)>(0x2A33B0);
	static inline auto FSerialize = PreyFunction<void(ArkAudioSwitchManager *const _this, TSerialize _ser)>(0x2A3390);
	static inline auto FPostSerialize = PreyFunction<void(ArkAudioSwitchManager *const _this)>(0x2A31E0);
	static inline auto FReset = PreyFunction<void(ArkAudioSwitchManager *const _this)>(0x2A3380);
};

