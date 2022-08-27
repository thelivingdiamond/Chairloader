local L0_462, L1_463, L2_464, L3_465
L0_462 = {}
L1_463 = {}
L1_463.bPhysicalize = 0
L1_463.Animation = "default"
L1_463.fileModel = "Objects/characters/story_characters/valerie/valeri.cgf"
L1_463.bPlaying = 0
L1_463.bAlwaysUpdate = 0
L2_464 = {}
L2_464.boneName = "weapon_bone"
L2_464.fileObject = "Objects/Weapons/M4/M4_bind.cgf"
L1_463.attachmet1 = L2_464
L2_464 = {}
L2_464.boneName = ""
L2_464.fileObject = ""
L1_463.attachmet2 = L2_464
L2_464 = {}
L2_464.boneName = ""
L2_464.fileObject = ""
L1_463.attachmet3 = L2_464
L2_464 = {}
L2_464.boneName = ""
L2_464.fileObject = ""
L1_463.attachmet4 = L2_464
L0_462.Properties = L1_463
AnimObject = L0_462
L0_462 = AnimObject
function L1_463(A0_466, A1_467)
  A0_466:StartAnimation(0, A0_466.Properties.Animation)
end
L0_462.Event_StartAnimation = L1_463
L0_462 = AnimObject
function L1_463(A0_468, A1_469)
  A0_468:ResetAnimation(0, -1)
end
L0_462.Event_StopAnimtion = L1_463
L0_462 = AnimObject
function L1_463(A0_470)
  if A0_470.Properties.fileModel ~= "" then
    A0_470:LoadCharacter(A0_470.Properties.fileModel, 0)
    if A0_470.Properties.bPhysicalize == 1 then
      A0_470:CreateStaticEntity(200, 0)
      A0_470:PhysicalizeCharacter(200, 0, 73, 0)
    end
  end
  if A0_470.Properties.attachmet1.fileObject ~= "" then
    A0_470:LoadObject(A0_470.Properties.attachmet1.fileObject, 0, 1)
    A0_470:AttachObjectToBone(0, A0_470.Properties.attachmet1.boneName)
  end
  if A0_470.Properties.attachmet2.fileObject ~= "" then
    A0_470:LoadObject(A0_470.Properties.attachmet2.fileObject, 1, 1)
    A0_470:AttachObjectToBone(1, A0_470.Properties.attachmet2.boneName)
  end
  if A0_470.Properties.attachmet3.fileObject ~= "" then
    A0_470:LoadObject(A0_470.Properties.attachmet3.fileObject, 2, 1)
    A0_470:AttachObjectToBone(2, A0_470.Properties.attachmet3.boneName)
  end
  if A0_470.Properties.attachmet4.fileObject ~= "" then
    A0_470:LoadObject(A0_470.Properties.attachmet4.fileObject, 3, 1)
    A0_470:AttachObjectToBone(3, A0_470.Properties.attachmet4.boneName)
  end
  if A0_470.Properties.bPlaying == 1 then
    A0_470:StartAnimation(0, A0_470.Properties.Animation)
  else
    A0_470:ResetAnimation(0, -1)
  end
  if A0_470.Properties.bAlwaysUpdate == 1 then
    A0_470:Activate(1)
    A0_470:SetUpdateType(eUT_Unconditional)
  else
    A0_470:Activate(0)
    A0_470:SetUpdateType(eUT_Visible)
  end
end
L0_462.OnReset = L1_463
L0_462 = AnimObject
function L1_463(A0_471, A1_472)
  A0_471:DetachObjectToBone(A0_471.Properties.attachmet1.boneName)
end
L0_462.Event_HideAttached = L1_463
L0_462 = AnimObject
function L1_463(A0_473, A1_474)
  A0_473:AttachObjectToBone(0, A0_473.Properties.attachmet1.boneName)
end
L0_462.Event_ShowAttached = L1_463
L0_462 = AnimObject
function L1_463(A0_475)
  A0_475:OnReset()
end
L0_462.OnPropertyChange = L1_463
L0_462 = AnimObject
function L1_463(A0_476)
  A0_476:OnReset()
end
L0_462.OnInit = L1_463
L0_462 = AnimObject
function L1_463(A0_477)
  local L1_478
end
L0_462.OnShutDown = L1_463
L0_462 = AnimObject
function L1_463(A0_479, A1_480)
end
L0_462.OnSave = L1_463
L0_462 = AnimObject
function L1_463(A0_481, A1_482)
end
L0_462.OnLoad = L1_463
L0_462 = AnimObject
L1_463 = {}
L2_464 = {}
L3_465 = {
  AnimObject.Event_HideAttached,
  "bool"
}
L2_464.HideAttached = L3_465
L3_465 = {
  AnimObject.Event_ShowAttached,
  "bool"
}
L2_464.ShowAttached = L3_465
L3_465 = {
  AnimObject.Event_StartAnimation,
  "bool"
}
L2_464.StartAnimation = L3_465
L3_465 = {
  AnimObject.Event_StopAnimation,
  "bool"
}
L2_464.StopAnimation = L3_465
L1_463.Inputs = L2_464
L2_464 = {}
L2_464.HideAttached = "bool"
L2_464.ShowAttached = "bool"
L2_464.StartAnimation = "bool"
L2_464.StopAnimation = "bool"
L1_463.Outputs = L2_464
L0_462.FlowEvents = L1_463
