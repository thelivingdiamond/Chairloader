// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ArkPasswordProtected.h
class ArkPasswordProtected // Id=80193FF Size=16
{
public:
	uint64_t m_characterId;
	string m_proxyPassword;
	
	ArkPasswordProtected();
	static bool IsTouristMode() { return FIsTouristMode(); }
	bool IsHackOnly() const { return FIsHackOnly(this); }
	bool PlayerHasPassword() const { return FPlayerHasPassword(this); }
	void ResetProxyPassword() { FResetProxyPassword(this); }
	void SetCharacterId(const uint64_t _characterId) { FSetCharacterId(this,_characterId); }
	std::pair<string,string> GetCharacterInfo() const { return FGetCharacterInfo(this); }
	
#if 0
	string const &GetProxyPassword() const;
#endif
	
	static inline auto FIsTouristMode = PreyFunction<bool()>(0x13A2980);
	static inline auto FIsHackOnly = PreyFunction<bool(ArkPasswordProtected const *const _this)>(0x13A2960);
	static inline auto FPlayerHasPassword = PreyFunction<bool(ArkPasswordProtected const *const _this)>(0x13A2AA0);
	static inline auto FResetProxyPassword = PreyFunction<void(ArkPasswordProtected *const _this)>(0x13A2C00);
	static inline auto FSetCharacterId = PreyFunction<void(ArkPasswordProtected *const _this, const uint64_t _characterId)>(0x10BE320);
	static inline auto FGetCharacterInfo = PreyFunction<std::pair<string,string>(ArkPasswordProtected const *const _this)>(0x13A2740);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkPasswordProtected
// Header:  Prey/GameDll/ark/ArkPasswordProtected.h
class ArkPasswordProtected
{ // Size=16 (0x10)
public:
	uint64_t m_characterId;
	string m_proxyPassword;

	ArkPasswordProtected();
	static bool IsTouristMode() { return FIsTouristMode(); }
	bool IsHackOnly() const { return FIsHackOnly(this); }
	bool PlayerHasPassword() const { return FPlayerHasPassword(this); }
	void ResetProxyPassword() { FResetProxyPassword(this); }
	void SetCharacterId(const uint64_t _characterId) { FSetCharacterId(this, _characterId); }
	std::pair<string, string> GetCharacterInfo() const { alignas(std::pair<string, string>) std::byte _return_buf_[sizeof(std::pair<string, string>)]; return *FGetCharacterInfo(this, reinterpret_cast<std::pair<string, string>*>(_return_buf_)); }

#if 0
	const string& GetProxyPassword() const;
#endif

	static inline auto FArkPasswordProtectedOv2 = PreyFunction<void(ArkPasswordProtected* const _this)>(0x14ACDC0);
	static inline auto FIsTouristMode = PreyFunction<bool()>(0x14AD020);
	static inline auto FIsHackOnly = PreyFunction<bool(const ArkPasswordProtected* const _this)>(0x14AD000);
	static inline auto FPlayerHasPassword = PreyFunction<bool(const ArkPasswordProtected* const _this)>(0x14AD030);
	static inline auto FResetProxyPassword = PreyFunction<void(ArkPasswordProtected* const _this)>(0x14AD080);
	static inline auto FSetCharacterId = PreyFunction<void(ArkPasswordProtected* const _this, const uint64_t _characterId)>(0x14AD1A0);
	static inline auto FGetCharacterInfo = PreyFunction<std::pair<string, string>*(const ArkPasswordProtected* const _this, std::pair<string, string>* _return_value_)>(0x14ACDE0);
};
#endif // !MOONCRASH
