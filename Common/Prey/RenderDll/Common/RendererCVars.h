#pragma once
struct ICVar;
struct IConsole;
struct IConsoleCmdArgs;

// Header: FromCpp
// CryEngine/renderdll/common/renderercvars.h
class CRendererCVars // Id=80106E2 Size=88
{
	ICVar* CV_capture_frames;
	ICVar* CV_capture_folder;
	ICVar* CV_capture_file_format;
	ICVar* CV_capture_frame_once;
	ICVar* CV_capture_file_name;
	ICVar* CV_capture_file_prefix;
	ICVar* m_CVWidth;
	ICVar* m_CVHeight;
	ICVar* m_CVFullScreen;
	ICVar* m_CVColorBits;
	ICVar* m_CVDisplayInfo;
};

static_assert(sizeof(CRendererCVars) == 88);
