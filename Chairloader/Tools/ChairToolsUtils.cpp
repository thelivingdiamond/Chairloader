#include <Chairloader/IChairloaderDll.h>
#include "ChairToolsUtils.h"

#ifdef PREDITOR
#include <Chairloader/IChairToPreditor.h>
#include "ChairloaderToolsPreditor.h"
#else
#include "ChairloaderTools.h"
#endif

#ifdef PREDITOR
IChairToPreditor* s_pChair = nullptr;
#endif

Internal::IChairloaderDll* ChairToolsUtils::GetDll()
{
#ifdef PREDITOR
	return s_pChair->GetIChairloaderDll();
#else
	return gChair;
#endif
}

ImFont* ChairToolsUtils::GetFont(IChairloaderImGui::EFont font)
{
#ifdef PREDITOR
	switch (font)
	{
	case IChairloaderImGui::EFont::Default:
		return gPreditor->pFonts->pDefault;
	case IChairloaderImGui::EFont::Monospace:
		return gPreditor->pFonts->pMonospace;
	}

	return nullptr;
#else
	return gCL->pImGui->GetFont(font);
#endif
}

#ifdef PREDITOR
void ChairToolsUtils::SetIChairToPreditor(IChairToPreditor* pChair)
{
	s_pChair = pChair;
}
#endif
