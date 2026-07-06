// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/DownloadMgr.h>

class CDownloadableResource;
struct IDataPatcherListener;

// CDataPatchDownloader
// Header:  Prey/GameDll/DataPatchDownloader.h
class CDataPatchDownloader : public IDataListener
{ // Size=48 (0x30)
public:
	IDataPatcherListener* m_pListener;
	unsigned m_patchCRC;
	int m_patchId;
	XmlNodeRef m_patchXML;
	const char* m_pFileBeingPatched;
	bool m_patchingEnabled;
	bool m_bNeedWeaponSystemReload;

	virtual void DataDownloaded(_smart_ptr<CDownloadableResource> inResource);
	virtual void DataFailedToDownload(_smart_ptr<CDownloadableResource> inResource);
	CDataPatchDownloader();
	virtual ~CDataPatchDownloader();
	_smart_ptr<CDownloadableResource> GetDownloadableResource() { alignas(_smart_ptr<CDownloadableResource>) std::byte _return_buf_[sizeof(_smart_ptr<CDownloadableResource>)]; return *FGetDownloadableResource(this, reinterpret_cast<_smart_ptr<CDownloadableResource>*>(_return_buf_)); }
	void SetPatchingEnabled(bool inEnable) { FSetPatchingEnabled(this, inEnable); }
	void CancelDownload() { FCancelDownload(this); }

#if 0
	void PatchFail(const char* _arg0_);
	void AssertPatchDownloaded();
	bool IsPatchingEnabled() const;
	void AddListener(IDataPatcherListener* _arg0_);
	void RemoveListener(IDataPatcherListener* _arg0_);
	int GetPatchId();
	unsigned GetDataPatchHash();
	bool NeedsWeaponSystemReload();
	void DoneWeaponSystemReload();
	void ApplyCVarPatch();
#endif

	static inline auto FDataDownloaded = PreyFunction<void(CDataPatchDownloader* const _this, _smart_ptr<CDownloadableResource> inResource)>(0x17D5B30);
	static inline auto FDataFailedToDownload = PreyFunction<void(CDataPatchDownloader* const _this, _smart_ptr<CDownloadableResource> inResource)>(0x17D5D80);
	static inline auto FCDataPatchDownloaderOv1 = PreyFunction<void(CDataPatchDownloader* const _this)>(0x17D5920);
	static inline auto FGetDownloadableResource = PreyFunction<_smart_ptr<CDownloadableResource>*(CDataPatchDownloader* const _this, _smart_ptr<CDownloadableResource>* _return_value_)>(0x17D5DF0);
	static inline auto FSetPatchingEnabled = PreyFunction<void(CDataPatchDownloader* const _this, bool inEnable)>(0x17D5ED0);
	static inline auto FCancelDownload = PreyFunction<void(CDataPatchDownloader* const _this)>(0x17D5AD0);
};
#endif // MOONCRASH
