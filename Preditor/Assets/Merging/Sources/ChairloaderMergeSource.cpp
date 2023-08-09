#include "Merging/Sources/ChairloaderMergeSource.h"

Assets::ChairloaderMergeSource::ChairloaderMergeSource()
    : DirectoryAssetMergeSource("chairloader", gPreditor->pConfig->GetPreditorRoot() / "ChairloaderPatch")
{
}

Assets::ChairloaderMergeSource::~ChairloaderMergeSource()
{
}
