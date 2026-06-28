// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

enum class EArkTitleStorageSlot;

// ArkFakeCatalogLoader
// Header:  Prey/GameDll/ark/ui/store/ArkFakeCatalogLoader.h
class ArkFakeCatalogLoader
{ // Size=8 (0x8)
public:
	ArkSimpleTimer m_timer;

	ArkFakeCatalogLoader(EArkTitleStorageSlot _slot);
	bool Update(float _dt) { return FUpdate(this, _dt); }
	bool RequestResource() { return FRequestResource(this); }
	boost::optional<XmlNodeRef> GetXml() const { alignas(boost::optional<XmlNodeRef>) std::byte _return_buf_[sizeof(boost::optional<XmlNodeRef>)]; return *FGetXml(this, reinterpret_cast<boost::optional<XmlNodeRef>*>(_return_buf_)); }

#if 0
	void ReleaseResource();
#endif

	static inline auto FArkFakeCatalogLoader = PreyFunction<void(ArkFakeCatalogLoader* const _this, EArkTitleStorageSlot _slot)>(0x142D500);
	static inline auto FUpdate = PreyFunction<bool(ArkFakeCatalogLoader* const _this, float _dt)>(0x142D5B0);
	static inline auto FRequestResource = PreyFunction<bool(ArkFakeCatalogLoader* const _this)>(0x142D5A0);
	static inline auto FGetXml = PreyFunction<boost::optional<XmlNodeRef>*(const ArkFakeCatalogLoader* const _this, boost::optional<XmlNodeRef>* _return_value_)>(0x142D530);
};
#endif // MOONCRASH
