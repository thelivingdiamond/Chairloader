Script.ReloadScript("Scripts/Entities/Ark/ArkNote.lua")
FlowgraphEntity = {
  Editor = {
    Icon = "FlowgraphEntity.bmp"
  },
  bForceHideInEditorGame = 1
}
MakeDerivedEntityOverride(FlowgraphEntity, ArkNote)
