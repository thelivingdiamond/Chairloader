// Header test file for path Prey/CryAction/

#include "ICryMannequinDefs.h"
static_assert(sizeof(SCRCRef<1, SCRCRefHash_CRC32Lowercase>) == 16);
static_assert(sizeof(SCRCRef<0, SCRCRefHash_CRC32Lowercase>) == 4);
static_assert(sizeof(SCRCRef<0, SCRCRefHash_CRC32>) == 4);
static_assert(sizeof(SCRCRefHash_CRC32Lowercase) == 1);
static_assert(sizeof(SCRCRefHash_CRC32) == 1);
static_assert(sizeof(SWeightData) == 16);

#include "ICryMannequinTagDefs.h"
static_assert(sizeof(STagMask) == 2);
static_assert(sizeof(STagStateBase) == 16);
static_assert(sizeof(STagState<1>) == 1);
static_assert(sizeof(STagState<4>) == 4);
static_assert(sizeof(STagState<12>) == 12);
static_assert(sizeof(CTagDefinition) == 64);
static_assert(sizeof(CTagDefinition::SPriorityCount) == 8);
static_assert(sizeof(CTagDefinition::STagDefData) == 24);
static_assert(sizeof(CTagDefinition::STagGroup) == 16);
static_assert(sizeof(CTagDefinition::STag) == 32);
static_assert(sizeof(SFragTagState) == 24);
static_assert(sizeof(CTagState) == 24);
static_assert(sizeof(TTagSortedList<unsigned int>) == 16);
static_assert(sizeof(TOptimisedTagSortedList<unsigned int>) == 56);

#include "ICryMannequinProceduralClipFactory.h"
static_assert(sizeof(SProceduralClipFactoryRegistrationInfo) == 16);
static_assert(sizeof(IProceduralClipFactory) == 8);
static_assert(sizeof(SProceduralClipRegistrationHelperBase) == 16);

#include "ICryMannequin.h"
static_assert(sizeof(SAnimationEntry) == 48);
static_assert(sizeof(IProceduralParamsComparer) == 8);
static_assert(sizeof(IProceduralParamsEditor) == 8);
static_assert(sizeof(IProceduralParamsEditor::SEditorCreateTransformGizmoResult) == 56);
static_assert(sizeof(IProceduralParams) == 8);
static_assert(sizeof(IProceduralParams::StringWrapper) == 8);
static_assert(sizeof(SNoProceduralParams) == 8);
static_assert(sizeof(SMannParameter) == 32);
static_assert(sizeof(SAnimBlend) == 20);
static_assert(sizeof(SAnimClip) == 80);
static_assert(sizeof(SProceduralEntry) == 48);
static_assert(sizeof(SFragmentData) == 56);
static_assert(sizeof(CFragment) == 32);
static_assert(sizeof(SFragmentBlendUid) == 4);
static_assert(sizeof(SFragmentBlend) == 32);
static_assert(sizeof(SFragmentDef) == 24);
static_assert(sizeof(SScopeDef) == 28);
static_assert(sizeof(SScopeContextDef) == 28);
static_assert(sizeof(SSubContext) == 16);
static_assert(sizeof(SControllerDef) == 256);
static_assert(sizeof(SAnimationContext) == 2544);
static_assert(sizeof(SMannHistoryItem) == 32);
static_assert(sizeof(IMannequinListener) == 8);
static_assert(sizeof(IMannequinGameListener) == 8);
static_assert(sizeof(SMannequinErrorReport) == 1088);
static_assert(sizeof(SAnimAssetReport) == 80);
static_assert(sizeof(SBlendQueryResult) == 80);
static_assert(sizeof(SBlendQuery) == 88);
static_assert(sizeof(SFragmentQuery) == 44);
static_assert(sizeof(SFragmentSelection) == 32);
static_assert(sizeof(SMiniSubADB) == 48);
static_assert(sizeof(IAnimationDatabase) == 8);
static_assert(sizeof(IAnimationDatabaseManager) == 8);
static_assert(sizeof(IScope) == 8);
static_assert(sizeof(CMannequinParams) == 24);
static_assert(sizeof(IActionController) == 8);
static_assert(sizeof(IAction) == 128);
static_assert(sizeof(TAction<SAnimationContext>) == 128);
static_assert(sizeof(IMannequin) == 8);
static_assert(sizeof(IProceduralClip) == 40);
static_assert(sizeof(IProceduralContext) == 24);
static_assert(sizeof(TProceduralClip<SNoProceduralParams>) == 48);
struct SHeaderTestProcContext { static const char* GetContextName() { return ""; } };
static_assert(sizeof(TProceduralContextualClip<SHeaderTestProcContext, SNoProceduralParams>) == 56);
static_assert(sizeof(CFragmentCache) == 72);
static_assert(sizeof(CFragmentCache::SCacheAnims) == 4);

#include "ICryMannequinUserParams.h"
static_assert(sizeof(IMannequinUserParams) == 8);
static_assert(sizeof(CMannequinUserParamId) == 8);
static_assert(sizeof(CMannequinUserParamsManager) == 40);
static_assert(sizeof(CMannequinUserParamsManager::SMannequinParamEntry) == 16);
static_assert(sizeof(TMannequinAutoInit<int, -1>) == 4);

#include "IAction.h"

#include "PlayerProfiles/PlayerProfileManager.h"
static_assert(sizeof(CPlayerProfileManager::IPlatformImpl) == 8);
static_assert(sizeof(CPlayerProfileManager::SThumbnail) == 24);

#include "FlashUI/FlashUI.h"
static_assert(sizeof(CFlashUI) == 480);
static_assert(sizeof(IFlashUI) == 8);
