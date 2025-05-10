#pragma once

struct IChairServiceProvider;
struct IChairloader;
struct IChairloaderImGui;
struct IChairloaderGui;
struct IChairloaderConfigManager;
class EntityUtils;
struct IRenderAuxGeomEx;
struct IChairRender;
struct IChairXmlUtils;
struct IChairSteamAPI;
struct IChairSceneEditor;

struct ChairloaderGlobalEnvironment {
	IChairloader* cl;
	IChairloaderImGui* pImGui;
	IChairloaderGui* gui;
	IRenderAuxGeomEx* pAuxGeomEx;
	IChairRender* pRender;
	IChairXmlUtils* pXmlUtils;
	IChairSteamAPI* pSteamAPI; //!< NULL if not Steam version
	IChairSceneEditor* pSceneEditor; //!< NULL if editor not enabled
	IChairServiceProvider* pServiceProvider;
};

extern ChairloaderGlobalEnvironment* gCL;
