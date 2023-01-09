// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDataComponentBase.h>

class ArkEmail;

// ArkEmailComponent
// Header:  Prey/GameDll/ark/player/pda/ArkEmailComponent.h
class ArkEmailComponent : public ArkDataComponentBase
{ // Size=184 (0xB8)
public:
	// ArkEmailComponent::SEmailUIContent
	// Header:  Prey/GameDll/ark/player/pda/ArkEmailComponent.h
	struct SEmailUIContent
	{ // Size=48 (0x30)
		const char* subject;
		const char* date;
		wstring body;
		wstring from;
		wstring to;
		wstring cc;
	};

	std::vector<uint64_t> m_downloads;
	std::unordered_map<uint64_t, bool> m_downloadHidden;
	std::unordered_map<uint64_t, bool> m_sentEmails;

	void GiveData(const uint64_t _id) { FGiveData(this, _id); }
	void GiveDownload(const uint64_t _downloadId) { FGiveDownload(this, _downloadId); }
	bool HasDownload(const uint64_t _id) const { return FHasDownload(this, _id); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SetEmailSent(const uint64_t _id, bool _bSent) { FSetEmailSent(this, _id, _bSent); }
	bool IsEmailSent(uint64_t _id) const { return FIsEmailSent(this, _id); }
	static bool FormatStringWithFrom(wstring& _input, const uint64_t _id) { return FFormatStringWithFrom(_input, _id); }
	static ArkEmailComponent::SEmailUIContent GetContentForUI(uint64_t _emailId) { return FGetContentForUI(_emailId); }
	bool IsDownloadHidden(uint64_t _id) const { return FIsDownloadHidden(this, _id); }
	void SetDownloadHidden(uint64_t _id, bool _bHidden) { FSetDownloadHidden(this, _id, _bHidden); }
	virtual bool IsValidData(const uint64_t _id) const;

#if 0
	void CollectAll();
	static wstring GetFormattedBody(const ArkEmail* _arg0_);
	void ResetCollected();
	void Reset();
	bool GetDefaultEmailSentState(uint64_t _arg0_) const;
	bool GetDefaultDownloadHiddenState(uint64_t _arg0_) const;
#endif

	static inline auto FGiveData = PreyFunction<void(ArkEmailComponent* const _this, const uint64_t _id)>(0x15B35E0);
	static inline auto FGiveDownload = PreyFunction<void(ArkEmailComponent* const _this, const uint64_t _downloadId)>(0x15B3770);
	static inline auto FHasDownload = PreyFunction<bool(const ArkEmailComponent* const _this, const uint64_t _id)>(0x15B37D0);
	static inline auto FSerialize = PreyFunction<void(ArkEmailComponent* const _this, TSerialize _ser)>(0x15B3A40);
	static inline auto FSetEmailSent = PreyFunction<void(ArkEmailComponent* const _this, const uint64_t _id, bool _bSent)>(0x15B3B50);
	static inline auto FIsEmailSent = PreyFunction<bool(const ArkEmailComponent* const _this, uint64_t _id)>(0x15B3970);
	static inline auto FFormatStringWithFrom = PreyFunction<bool(wstring& _input, const uint64_t _id)>(0x15B3170);
	static inline auto FGetContentForUI = PreyFunction<ArkEmailComponent::SEmailUIContent(uint64_t _emailId)>(0x15B3340);
	static inline auto FIsDownloadHidden = PreyFunction<bool(const ArkEmailComponent* const _this, uint64_t _id)>(0x15B3800);
	static inline auto FSetDownloadHidden = PreyFunction<void(ArkEmailComponent* const _this, uint64_t _id, bool _bHidden)>(0x15B3AC0);
	static inline auto FIsValidData = PreyFunction<bool(const ArkEmailComponent* const _this, const uint64_t _id)>(0x15B3A00);
};

