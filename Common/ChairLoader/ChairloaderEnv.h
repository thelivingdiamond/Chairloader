#pragma once

struct IChairloader;
struct IChairloaderImGui;
struct IChairloaderGui;
struct IChairloaderConfigManager;
class EntityUtils;

struct ChairloaderGlobalEnvironment {
	IChairloader* cl;
	IChairloaderImGui* pImGui;
	IChairloaderGui* gui;
	IChairloaderConfigManager* conf;
	EntityUtils* entUtils;
};
