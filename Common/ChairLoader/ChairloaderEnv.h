#pragma once

struct IChairloader;
struct IChairloaderImGui;
struct IChairloaderGui;
struct IChairloaderConfigManager;
class EntityUtils;
struct IRenderAuxGeomEx;
struct IChairRender;

struct ChairloaderGlobalEnvironment {
	IChairloader* cl;
	IChairloaderImGui* pImGui;
	IChairloaderGui* gui;
	IChairloaderConfigManager* conf;
	EntityUtils* entUtils;
	IRenderAuxGeomEx* pAuxGeomEx;
	IChairRender* pRender;
};

extern ChairloaderGlobalEnvironment* gCL;
