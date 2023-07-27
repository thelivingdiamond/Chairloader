#pragma once

// TODO 2023-07-24: Better ArkName handling
#define DECLARE_ARK_NAME_GLOBAL(offset, name) inline PreyGlobal<CCryName> ARKNAME_##name(offset)

//! Declares a new ArkName.
#define DECLARE_ARK_NAME(name) inline CCryName ARKNAME_##name

//! Initializes an ArkName.
#define INIT_ARK_NAME(name) ARKNAME_##name = CCryName(#name)

DECLARE_ARK_NAME_GLOBAL(0x2BC98A0, WeaponCriticalHitChance);
