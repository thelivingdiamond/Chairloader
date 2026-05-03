#include <atomic>
#include <WindowManager/WindowManager.h>
#include <Preditor/ReferenceCatalog/Catalog.h>
#include <Preditor/ReferenceCatalog/IReferenceCatalogUI.h>
#include <Preditor/ReferenceCatalog/KindRegistry.h>
#include <Preditor/ReferenceCatalog/Providers/XmlFileProvider.h>

#include "Preditor/ReferenceCatalog/Providers/FunctionProvider.h"
#include "UI/CatalogBrowserWindow.h"

namespace
{
    std::atomic<bool> s_DefaultsRegistered{false};

    void RegisterPreyProviders()
    {
        using namespace ReferenceCatalog;

        // === XML-backed library providers ===

        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Libs/GameTokens"};
            spec.elementName = "GameToken";
            spec.idAttr = "Id";
            spec.nameAttr = "Name";
            spec.description = "Game tokens (Libs/GameTokens/*.xml)";
            Catalog::Get().RegisterProvider("GameToken",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/RemoteEventLibrary.xml"};
            spec.elementName = "ArkRemoteEvent";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Ark remote events (Ark/RemoteEventLibrary.xml)";
            Catalog::Get().RegisterProvider("RemoteEvent",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            // Lowercase id/name — schemas vary across Ark libraries.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/ArkFactions.xml"};
            spec.elementName = "Faction";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "NPC factions (Ark/ArkFactions.xml)";
            Catalog::Get().RegisterProvider("Faction",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Libs/GameAudio"};
            spec.elementName = "ATLTrigger";
            spec.idAttr = "atl_name";
            spec.nameAttr = "atl_name";
            spec.recursive = true;
            spec.description = "Audio triggers (Libs/GameAudio/**/*.xml)";
            Catalog::Get().RegisterProvider("AudioTrigger",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            // Flowgraph ports reference archetypes by Name ("Phantoms.BasePhantom"),
            // not by the CryGUID Id attribute — expose Name for both fields.
            XmlFileProvider::Spec spec;
            spec.roots = {"Libs/EntityArchetypes"};
            spec.elementName = "EntityPrototype";
            spec.idAttr = "Name";
            spec.nameAttr = "Name";
            spec.recursive = true;
            spec.description = "Entity archetypes (Libs/EntityArchetypes/**/*.xml)";
            Catalog::Get().RegisterProvider("EntityArchetype",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            // Objective text ships as @loc keys; localizeName resolves them
            // through ILocalizationManager so pickers show real mission text.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Objectives"};
            spec.elementName = "Objective";
            spec.idAttr = "id";
            spec.nameAttr = "title";
            spec.recursive = true;
            spec.localizeName = true;
            spec.description = "Objectives (Ark/Campaign/Objectives/**/*.xml)";
            Catalog::Get().RegisterProvider("Objective",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Objectives"};
            spec.elementName = "Desc";
            spec.idAttr = "id";
            spec.nameAttr = "text";
            spec.recursive = true;
            spec.localizeName = true;
            spec.description = "Objective Description (Ark/Campaign/Objectives/**/*.xml)";
            Catalog::Get().RegisterProvider("ObjectiveDescription",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Objectives"};
            spec.elementName = "Task";
            spec.idAttr = "id";
            spec.nameAttr = "text";
            spec.recursive = true;
            spec.localizeName = true;
            spec.description = "Objective Task (Ark/Campaign/Objectives/**/*.xml)";
            Catalog::Get().RegisterProvider("ObjectiveTask",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Objectives"};
            spec.elementName = "Clue";
            spec.idAttr = "id";
            spec.nameAttr = "text";
            spec.recursive = true;
            spec.localizeName = true;
            spec.description = "Objective Clue (Ark/Campaign/Objectives/**/*.xml)";
            Catalog::Get().RegisterProvider("ObjectiveClue",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/SignalSystem/Signals.xml"};
            spec.elementName = "signal";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "Signal (Ark/SignalSystem/Signals.xml)";
            Catalog::Get().RegisterProvider("Signal",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/SignalSystem/Modifiers.xml"};
            spec.elementName = "modifier";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "Modifier (Ark/SignalSystem/Modifiers.xml)";
            Catalog::Get().RegisterProvider("SignalModifier",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/SignalSystem/Packages.xml"};
            spec.elementName = "package";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "Package (Ark/SignalSystem/Packages.xml)";
            Catalog::Get().RegisterProvider("SignalPackage",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/SignalSystem/SignalGroups.xml"};
            spec.elementName = "Group";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "Signal Group (Ark/SignalSystem/SignalGroups.xml)";
            Catalog::Get().RegisterProvider("SignalGroup",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Dialog/DialogLogic"};
            spec.elementName = "ResponseRule";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.recursive = true;
            spec.description = "Conversation (Ark/Dialog/DialogLogic)";
            Catalog::Get().RegisterProvider("Conversation",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Locations.xml"};
            spec.elementName = "ArkLocation";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Location (Ark/Campaign/Locations.xml)";
            Catalog::Get().RegisterProvider("Location",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/WorkstationLibrary.xml"};
            spec.elementName = "Button";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Button (Ark/Campaign/WorkstationLibrary.xml)";
            Catalog::Get().RegisterProvider("UtilityButton",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/WorkstationLibrary.xml"};
            spec.elementName = "Download";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Downloads (Ark/Campaign/WorkstationLibrary.xml)";
            Catalog::Get().RegisterProvider("Download",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Libs/UI/UIElements"};
            spec.elementName = "UIElement";
            spec.idAttr = "name";
            spec.nameAttr = "name";
            spec.description = "UI Element (Libs/UI/UIElements)";
            Catalog::Get().RegisterProvider("UIElement",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }

        // === Ark/Campaign root libraries ===
        // Display uses the engineering Name field rather than the localized
        // Label/Subject/Title — distinctive and English-readable. To switch a
        // kind to its localized form, dupe the provider with localizeName=true
        // and the appropriate nameAttr.

        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/AudioLogs.xml"};
            spec.elementName = "ArkAudioLog";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Audio logs (Ark/Campaign/AudioLogs.xml)";
            Catalog::Get().RegisterProvider("AudioLog",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            // Books and Notes share the <ArkNote> shape across separate files;
            // register two kinds so the picker doesn't mix them.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Books.xml"};
            spec.elementName = "ArkNote";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Books (Ark/Campaign/Books.xml)";
            Catalog::Get().RegisterProvider("Book",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/CharacterLibrary.xml"};
            spec.elementName = "ArkCharacter";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Characters (Ark/Campaign/CharacterLibrary.xml)";
            Catalog::Get().RegisterProvider("Character",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/EmailLibrary.xml"};
            spec.elementName = "ArkEmail";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Emails (Ark/Campaign/EmailLibrary.xml)";
            Catalog::Get().RegisterProvider("Email",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/GameStateConditionLibrary.xml"};
            spec.elementName = "ArkGameStateCondition";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Game state conditions (Ark/Campaign/GameStateConditionLibrary.xml)";
            Catalog::Get().RegisterProvider("GameStateCondition",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/GroupLibrary.xml"};
            spec.elementName = "ArkCharacterGroup";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Character groups (Ark/Campaign/GroupLibrary.xml)";
            Catalog::Get().RegisterProvider("CharacterGroup",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/KeycardLibrary.xml"};
            spec.elementName = "ArkKeyCard";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Keycards (Ark/Campaign/KeycardLibrary.xml)";
            Catalog::Get().RegisterProvider("KeyCard",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/KeycodeLibrary.xml"};
            spec.elementName = "ArkKeyCode";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Keycodes (Ark/Campaign/KeycodeLibrary.xml)";
            Catalog::Get().RegisterProvider("KeyCode",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/LoreLibrary.xml"};
            spec.elementName = "ArkLoreEntry";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Lore entries (Ark/Campaign/LoreLibrary.xml)";
            Catalog::Get().RegisterProvider("LoreEntry",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/Notes.xml"};
            spec.elementName = "ArkNote";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Notes (Ark/Campaign/Notes.xml)";
            Catalog::Get().RegisterProvider("Note",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/POILibrary.xml"};
            spec.elementName = "ArkPointOfInterest";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Points of interest (Ark/Campaign/POILibrary.xml)";
            Catalog::Get().RegisterProvider("POI",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/SecurityStationLibrary.xml"};
            spec.elementName = "ArkSecurityStation";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Security stations (Ark/Campaign/SecurityStationLibrary.xml)";
            Catalog::Get().RegisterProvider("SecurityStation",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/StationAccessLibrary.xml"};
            spec.elementName = "ArkStationPath";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Station access paths (Ark/Campaign/StationAccessLibrary.xml)";
            Catalog::Get().RegisterProvider("StationAccess",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            // Only ArkCardTutorial here; sibling classes (ArkContextualTutorial
            // etc.) need their own providers if they get referenced.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Campaign/TutorialLibrary.xml"};
            spec.elementName = "ArkCardTutorial";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Tutorials (Ark/Campaign/TutorialLibrary.xml)";
            Catalog::Get().RegisterProvider("Tutorial",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }

        // === Ark/ top-level libraries ===

        {
            // Only the procedural variant ships in vanilla.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/ArkCameraShakes.xml"};
            spec.elementName = "ArkCameraShake_Procedural";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Camera shakes (Ark/ArkCameraShakes.xml)";
            Catalog::Get().RegisterProvider("CameraShake",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/ArkMetaTags.xml"};
            spec.elementName = "ArkMetaTag";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "Meta tags (Ark/ArkMetaTags.xml)";
            Catalog::Get().RegisterProvider("MetaTag",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/ArkEventDrivenAchievements.xml"};
            spec.elementName = "ArkEventDrivenAchievement";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Achievements (Ark/ArkEventDrivenAchievements.xml)";
            Catalog::Get().RegisterProvider("Achievement",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/EmotionLibrary.xml"};
            spec.elementName = "ArkEmotion";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Emotions (Ark/EmotionLibrary.xml)";
            Catalog::Get().RegisterProvider("Emotion",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            // GameNoises bundles two enum libraries; one provider per element.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/GameNoises.xml"};
            spec.elementName = "ArkGameNoiseType";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Game noise types (Ark/GameNoises.xml)";
            Catalog::Get().RegisterProvider("GameNoiseType",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/GameNoises.xml"};
            spec.elementName = "ArkGameNoiseLoudness";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Game noise loudnesses (Ark/GameNoises.xml)";
            Catalog::Get().RegisterProvider("GameNoiseLoudness",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/TipLibrary.xml"};
            spec.elementName = "ArkTip";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Tips (Ark/TipLibrary.xml)";
            Catalog::Get().RegisterProvider("Tip",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/ArkRewards.xml"};
            spec.elementName = "Trackable";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Rewards / trackables (Ark/ArkRewards.xml)";
            Catalog::Get().RegisterProvider("Reward",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/EntitlementLibrary.xml"};
            spec.elementName = "ArkEntitlement";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Entitlements (Ark/EntitlementLibrary.xml)";
            Catalog::Get().RegisterProvider("Entitlement",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/EntitlementUnlockLibrary.xml"};
            spec.elementName = "ArkEntitlementUnlock";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Entitlement unlocks (Ark/EntitlementUnlockLibrary.xml)";
            Catalog::Get().RegisterProvider("EntitlementUnlock",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }

        // === Ark/Player/ libraries ===

        {
            // Name is the engineering id ("Backlash I"); Label is the loc key.
            // Name disambiguates tiers, so prefer it for the picker.
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Player/Abilities.xml"};
            spec.elementName = "ArkAbility";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Abilities (Ark/Player/Abilities.xml)";
            Catalog::Get().RegisterProvider("Ability",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Player/Traumas.xml"};
            spec.elementName = "ArkTrauma";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Traumas (Ark/Player/Traumas.xml)";
            Catalog::Get().RegisterProvider("Trauma",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Player/ResearchTopics.xml"};
            spec.elementName = "ArkResearchTopic";
            spec.idAttr = "id";
            spec.nameAttr = "name";
            spec.description = "Research topics (Ark/Player/ResearchTopics.xml)";
            Catalog::Get().RegisterProvider("ResearchTopic",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Player/GameMetrics.xml"};
            spec.elementName = "ArkGameMetricProperties";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Game metrics (Ark/Player/GameMetrics.xml)";
            Catalog::Get().RegisterProvider("GameMetric",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Player/StatPackages.xml"};
            spec.elementName = "ArkStatModifierPackage";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Stat modifier packages (Ark/Player/StatPackages.xml)";
            Catalog::Get().RegisterProvider("StatPackage",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }
        {
            XmlFileProvider::Spec spec;
            spec.roots = {"Ark/Player/SignalFXLibrary.xml"};
            spec.elementName = "ArkSignalFX";
            spec.idAttr = "ID";
            spec.nameAttr = "Name";
            spec.description = "Signal FX (Ark/Player/SignalFXLibrary.xml)";
            Catalog::Get().RegisterProvider("SignalFX",
                                            std::make_unique<XmlFileProvider>(std::move(spec)));
        }

        // === Engine-runtime providers ===

        {
            Catalog::Get().RegisterProvider("EntityClass",
                                            std::make_unique<FunctionProvider>(
                                                []
                                                {
                                                    std::vector<Entry> out;
                                                    auto* reg = gEnv->pEntitySystem->
                                                        GetClassRegistry();
                                                    reg->IteratorMoveFirst();
                                                    while (IEntityClass* c = reg->IteratorNext())
                                                        out.push_back({
                                                            c->GetName(), c->GetName(), "EntitySystem"
                                                        });
                                                    return out;
                                                },
                                                "Entity classes (gEnv->pEntitySystem)"));
        }
    }

    // Rules are matched first-wins; specific suffixes before generic ones.
    // Format: { uiConfigPrefix, portSuffix, nodeClassPrefix, kind }.
    void RegisterFlowgraphRules()
    {
        using namespace ReferenceCatalog;
        KindRegistry& kr = KindRegistry::Get();

        // --- Mission / GameToken ---
        kr.AddRule({"", "gametokenid_Token",                "", "GameToken"});

        // --- Ark events / dialog ---
        kr.AddRule({"", "remoteEvent_Event",                "", "RemoteEvent"});
        kr.AddRule({"", "conversation_Conversation",        "", "Conversation"});
        kr.AddRule({"", "dialogRule_Conversation",          "", "Conversation"});
        kr.AddRule({"", "announcement_Conversation",        "", "Conversation"});

        // --- Locations / patrols / objectives ---
        kr.AddRule({"", "location_Location",                "", "Location"});
        kr.AddRule({"", "patrol_Patrol",                    "", "Patrol"});
        kr.AddRule({"", "objective_Objective",              "", "Objective"});
        kr.AddRule({"", "objectiveDescription_Description", "", "ObjectiveDescription"});
        kr.AddRule({"", "objectiveclue_Clue",               "", "ObjectiveClue"});
        kr.AddRule({"", "task_Task",                        "", "ObjectiveTask"});

        // --- Factions / signals ---
        kr.AddRule({"", "faction_Faction",                  "", "Faction"});
        kr.AddRule({"", "faction_ToFaction",                "", "Faction"});
        kr.AddRule({"", "signal_Signal",                    "", "Signal"});
        kr.AddRule({"", "signalPackage_Package",            "", "SignalPackage"});
        kr.AddRule({"", "signalModifier_Modifier",          "", "SignalModifier"});
        kr.AddRule({"", "signalgroup_SignalGroup",          "", "SignalGroup"});

        // --- Workstation / utilities ---
        kr.AddRule({"", "utilityButton_UtilityButton",      "", "UtilityButton"});
        kr.AddRule({"", "utilityButton_CompareTo",          "", "UtilityButton"});
        kr.AddRule({"", "utility_Utility",                  "", "UtilityButton"});
        kr.AddRule({"", "download_Download",                "", "Download"});

        // --- PDA / collectibles ---
        kr.AddRule({"", "character_Character",              "", "Character"});
        kr.AddRule({"", "email_Email",                      "", "Email"});
        kr.AddRule({"", "keycard_Keycard",                  "", "KeyCard"});
        kr.AddRule({"", "keycard_UnlockKeycard",            "", "KeyCard"});
        kr.AddRule({"", "keycard_UnlockCode",               "", "KeyCard"});
        kr.AddRule({"", "keycode_Keycode",                  "", "KeyCode"});
        kr.AddRule({"", "note_Note",                        "", "Note"});
        kr.AddRule({"", "note_OnRead",                      "", "Note"});
        kr.AddRule({"", "poi_POI",                          "", "POI"});
        kr.AddRule({"", "securityStation_SecurityStation",  "", "SecurityStation"});
        kr.AddRule({"", "stationAccess_Access",             "", "StationAccess"});
        kr.AddRule({"", "tutorial_Tutorial",                "", "Tutorial"});
        kr.AddRule({"", "tutorial_ContextualTutorial",      "", "Tutorial"});

        // --- Ark/ top-level libraries ---
        kr.AddRule({"", "cameraShake_CameraShake",          "", "CameraShake"});
        kr.AddRule({"", "metaTags_ArkMetaTags",             "", "MetaTag"});
        kr.AddRule({"", "achievement_Achievement",          "", "Achievement"});
        kr.AddRule({"", "gameNoiseType_NoiseType",          "", "GameNoiseType"});
        kr.AddRule({"", "gameNoiseLoudness_NoiseLoudness",  "", "GameNoiseLoudness"});

        // --- Player ---
        kr.AddRule({"", "ability_Ability",                  "", "Ability"});
        kr.AddRule({"", "trauma_Trauma",                    "", "Trauma"});
        kr.AddRule({"", "researchTopic_ResearchTopic",      "", "ResearchTopic"});
        kr.AddRule({"", "gameMetric_Metric",                "", "GameMetric"});
        kr.AddRule({"", "gamemetric_Metric",                "", "GameMetric"}); // casing variant

        // --- Entity archetype aliases — npc/mimic/robot/chipset all resolve here ---
        kr.AddRule({"", "npcArchetype_name",                "", "EntityArchetype"});
        kr.AddRule({"", "npcRobotArchetype_name",           "", "EntityArchetype"});
        kr.AddRule({"", "mimicArchetype_Archetype",         "", "EntityArchetype"});
        kr.AddRule({"", "chipsetArchetypes_Archetype",      "", "EntityArchetype"});

        // --- Name-string kinds (id == name; no numeric resolution) ---
        kr.AddRule({"", "audioTrigger_PlayTrigger",         "", "AudioTrigger"});
        kr.AddRule({"", "audioTrigger_StopTrigger",         "", "AudioTrigger"});
        kr.AddRule({"", "uiElements_Element",               "", "UIElement"});
    }
} // namespace

void IReferenceCatalogUI::EnsureDefaults()
{
    bool expected = false;
    if (!s_DefaultsRegistered.compare_exchange_strong(expected, true))
        return;
    RegisterPreyProviders();
    RegisterFlowgraphRules();
}

std::shared_ptr<ManagedWindow> IReferenceCatalogUI::CreateBrowserWindow()
{
    EnsureDefaults();
    return WindowManager::Get().Create<ReferenceCatalog::CatalogBrowserWindow>();
}
