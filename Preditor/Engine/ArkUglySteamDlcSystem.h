#pragma once
#include <Prey/CryString/StringUtils.h>

struct IArkDlcSystem;
struct IArkDlcListener;

// A really ugly hack to instantiate CArkDlcSystem without implementing any virtual methods.
class CArkUglySteamDlcSystem
{
public:
	static IArkDlcSystem* Instantiate();

private:
	CArkUglySteamDlcSystem();
	~CArkUglySteamDlcSystem();

	struct ArkDlcInfo // Id=8002F96 Size=72
	{
		unsigned dlcId;
		string Name;
		bool bUnlocked;
		bool bMounted;
		string mountPoint;
		string folderPath;
		string SteamId;
		string PS4ContentLabel;
		string XB1ProductId;
		unsigned NpServiceLabel;
	};

	// This may be different from what the game uses.
	// Doesn't matter because it won't be called.
	struct hash_string
	{
		std::size_t operator()(const string& k) const
		{
			return CryStringUtils::HashString(k.c_str());
		}
	};

	// Virtual function table
	void* vftable = nullptr;

	// CArkDlcSystem
	bool m_bRequestRefresh;
	std::vector<IArkDlcListener*> m_listeners;
	std::unordered_map<unsigned int, string> m_dlcIdMap;
	std::unordered_map<string, ArkDlcInfo, hash_string> m_dlcPlatformIdMap;

	// CArkSteamDlcSystem
	std::unordered_map<uint64_t, string, hash_string> m_appIds;
};
