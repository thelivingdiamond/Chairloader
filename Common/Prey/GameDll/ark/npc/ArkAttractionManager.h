// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CArkAreaContainer;
class CArkAttraction;

// ArkAttractionManager
// Header:  Prey/GameDll/ark/npc/ArkAttractionManager.h
class ArkAttractionManager
{ // Size=88 (0x58)
public:
	using Attractors = std::vector<unsigned int>;
	using AreaContainerToContainedAttractors = std::unordered_map<unsigned int, std::vector<unsigned int>>;

	std::vector<unsigned int> m_attractors;
	std::unordered_map<unsigned int, std::vector<unsigned int>> m_containerToContainedAttractors;

	ArkAttractionManager();
	~ArkAttractionManager();
	void RegisterAttractor(const CArkAttraction& _attractor) { FRegisterAttractor(this, _attractor); }
	void UnRegisterAttractor(const CArkAttraction& _attractor) { FUnRegisterAttractor(this, _attractor); }
	void RegisterRoomContainer(const CArkAreaContainer& _roomContainer) { FRegisterRoomContainer(this, _roomContainer); }
	CArkAttraction* AcquireAttractor(const CArkAreaContainer& _areaContainer, const Vec3& _requesterPos) { return FAcquireAttractorOv2(this, _areaContainer, _requesterPos); }
	CArkAttraction* AcquireAttractor(const Vec3& _requesterPos, float _radius) { return FAcquireAttractorOv1(this, _requesterPos, _radius); }
	CArkAttraction* AcquireAttractor(unsigned _attractorId) { return FAcquireAttractorOv0(this, _attractorId); }
	void RelinquishAttractor(CArkAttraction& _attractor) { FRelinquishAttractor(this, _attractor); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _dt) { FUpdate(this, _dt); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }

#if 0
	ArkAttractionManager(const ArkAttractionManager& _arg0_);
	ArkAttractionManager& operator=(const ArkAttractionManager& _arg0_);
	const std::vector<unsigned int>* GetAttractorsInContainer(const CArkAreaContainer& _arg0_) const;
#endif

	static inline auto FArkAttractionManagerOv1 = PreyFunction<void(ArkAttractionManager* const _this)>(0x16020C0);
	static inline auto FBitNotArkAttractionManager = PreyFunction<void(ArkAttractionManager* const _this)>(0x1602140);
	static inline auto FRegisterAttractor = PreyFunction<void(ArkAttractionManager* const _this, const CArkAttraction& _attractor)>(0x16028C0);
	static inline auto FUnRegisterAttractor = PreyFunction<void(ArkAttractionManager* const _this, const CArkAttraction& _attractor)>(0x1602CE0);
	static inline auto FRegisterRoomContainer = PreyFunction<void(ArkAttractionManager* const _this, const CArkAreaContainer& _roomContainer)>(0x1602940);
	static inline auto FAcquireAttractorOv2 = PreyFunction<CArkAttraction* (ArkAttractionManager* const _this, const CArkAreaContainer& _areaContainer, const Vec3& _requesterPos)>(0x1602410);
	static inline auto FAcquireAttractorOv1 = PreyFunction<CArkAttraction* (ArkAttractionManager* const _this, const Vec3& _requesterPos, float _radius)>(0x1602170);
	static inline auto FAcquireAttractorOv0 = PreyFunction<CArkAttraction* (ArkAttractionManager* const _this, unsigned _attractorId)>(0x1602790);
	static inline auto FRelinquishAttractor = PreyFunction<void(ArkAttractionManager* const _this, CArkAttraction& _attractor)>(0x1602C50);
	static inline auto FReset = PreyFunction<void(ArkAttractionManager* const _this, bool _bEnteringGameMode)>(0x1602C60);
	static inline auto FUpdate = PreyFunction<void(ArkAttractionManager* const _this, float _dt)>(0x1333E90);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkAttractionManager* const _this)>(0x1333E90);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkAttractionManager* const _this)>(0x1602C60);
};
#endif // MOONCRASH
