Script.ReloadScript("Scripts/Entities/Physics/BasicEntity.lua")
PROP_SPEAKER = 0
ArkAnimSpeakerObject = {
  Properties = {
    ArkCharacter = {character_Character = "", bMuteVO = 0},
    ArkSpeakerExtension = {nSpeakerType = PROP_SPEAKER}
  }
}
MakeDerivedEntityOverride(ArkAnimSpeakerObject, AnimObject)
function ArkAnimSpeakerObject.LoadAndPhysicalizeModel(A0_3447)
  if not A0_3447.isModelLoaded then
    A0_3447:LoadObject(0, A0_3447.Properties.object_Model)
    A0_3447:RenderAlways(A0_3447.Properties.Cinematic.bRenderAlways)
    if A0_3447.Properties.Physics.bPhysicalize == 1 then
      A0_3447:PhysicalizeThis()
    end
    A0_3447.isModelLoaded = true
    CryAction.CreateGameObjectForEntity(A0_3447.id)
    CryAction.ActivateExtensionForGameObject(A0_3447.id, "ArkSpeakerExtension", true)
    return 1
  end
  return 0
end
