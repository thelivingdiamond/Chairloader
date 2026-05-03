#pragma once
#include <string>

namespace ReferenceCatalog
{

//! A single (id, name) record for a category of in-game reference.
//! Examples: GameToken "WorldState.ApexIsHere" → "659909599",
//!           ArkRemoteEvent "FoundFionaVoiceSample10" → "844024417280406867".
struct Entry
{
    std::string id;          //!< Canonical string form. Decimal for 32/64-bit ints, hex for guid strings.
    std::string name;        //!< Human-readable label.
    std::string sourceLabel; //!< Where it came from — e.g. "GT_Global.xml". Used for tooltips / disambiguation.
};

} // namespace ReferenceCatalog
