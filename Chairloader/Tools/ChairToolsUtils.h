#pragma once
#include <Chairloader/IChairloaderImGui.h>

namespace Internal
{
struct IChairloaderDll;
}

struct IChairToPreditor;

class ChairToolsUtils
{
public:
	static Internal::IChairloaderDll* GetDll();
	static ImFont* GetFont(IChairloaderImGui::EFont font);

#ifdef PREDITOR
	static void SetIChairToPreditor(IChairToPreditor* pChair);
#endif
};
