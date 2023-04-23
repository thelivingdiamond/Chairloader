#pragma once

struct IChairloader;
struct IChairloaderImGui;
struct IChairloaderGui;
struct IChairloaderConfigManager;
class EntityUtils;
struct IRenderAuxGeomEx;
struct IChairRender;
struct IChairXmlUtils;

struct ChairloaderGlobalEnvironment {
	IChairloader* cl;
	IChairloaderImGui* pImGui;
	IChairloaderGui* gui;
	IChairloaderConfigManager* conf;
	IRenderAuxGeomEx* pAuxGeomEx;
	IChairRender* pRender;
	IChairXmlUtils* pXmlUtils;
};

extern ChairloaderGlobalEnvironment* gCL;
