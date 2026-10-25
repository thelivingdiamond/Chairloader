#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkSeismicBounds.h>

struct ArkSeismicBounds;

// ArkSeismicPerceivable
// Header:  _unknown/ArkSeismicPerceivable.h
class ArkSeismicPerceivable
{ // Size=8 (0x8)
public:
    ArkSeismicBounds GetSeismicBounds() const { alignas(ArkSeismicBounds) std::byte _return_buf_[sizeof(ArkSeismicBounds)]; return *FGetSeismicBounds(this, reinterpret_cast<ArkSeismicBounds*>(_return_buf_)); }
    virtual unsigned DoGetEntityId() const = 0;
    virtual ArkSeismicBounds DoGetSeismicBounds() const = 0;

#if 0
    unsigned GetEntityId() const;
    ~ArkSeismicPerceivable();
    ArkSeismicPerceivable& operator=(const ArkSeismicPerceivable& _arg0_);
#endif

    static inline auto FGetSeismicBounds = PreyFunction<ArkSeismicBounds*(const ArkSeismicPerceivable* const _this, ArkSeismicBounds* _return_value_)>(0x12B5850);
};
#endif


