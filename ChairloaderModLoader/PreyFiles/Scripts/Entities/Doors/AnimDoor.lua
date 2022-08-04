local L0_4848, L1_4849, L2_4850, L3_4851
L0_4848 = {}
L1_4849 = {}
L0_4848.Server = L1_4849
L1_4849 = {}
L0_4848.Client = L1_4849
L1_4849 = {}
L1_4849.soclasses_SmartObjectClass = "Door"
L1_4849.object_Model = ""
L2_4850 = {}
L2_4850.snd_Open = ""
L2_4850.snd_Close = ""
L1_4849.Sounds = L2_4850
L2_4850 = {}
L2_4850.anim_Open = "Default"
L2_4850.anim_Close = ""
L1_4849.Animation = L2_4850
L2_4850 = {}
L2_4850.bPhysicalize = 1
L2_4850.bRigidBody = 1
L2_4850.bPushableByPlayers = 1
L2_4850.bPushableByAI = 1
L2_4850.Density = -1
L2_4850.Mass = -1
L1_4849.Physics = L2_4850
L1_4849.fUseDistance = 2.5
L1_4849.bLocked = 0
L1_4849.bActivatePortal = 0
L1_4849.bNoFriendlyFire = 0
L0_4848.Properties = L1_4849
L1_4849 = {}
L1_4849.Icon = "Door.bmp"
L1_4849.ShowBounds = 1
L0_4848.Editor = L1_4849
L0_4848.nDirection = -1
L0_4848.bUseSameAnim = 0
L0_4848.bNoAnims = 0
L0_4848.nSoundId = 0
L0_4848.bLocked = false
L0_4848.bNeedUpdate = 0
AnimDoor = L0_4848
L0_4848 = AnimDoor
function L1_4849(A0_4852, A1_4853)
  local L2_4854, L3_4855
  L2_4854 = A1_4853.bLocked
  A0_4852.bLocked = L2_4854
  A0_4852.bNeedUpdate = 0
  L3_4855 = A0_4852
  L2_4854 = A0_4852.ResetAnimation
  L2_4854(L3_4855, 0, -1)
  L3_4855 = A0_4852
  L2_4854 = A0_4852.DoStopSound
  L2_4854(L3_4855)
  A0_4852.curAnim = ""
  A0_4852.nDirection = 0
  L2_4854 = AI
  if L2_4854 then
    L2_4854 = AI
    L2_4854 = L2_4854.SetSmartObjectState
    L3_4855 = A0_4852.id
    L2_4854(L3_4855, "Closed")
  end
  L2_4854 = A0_4852.bLocked
  if L2_4854 then
    L2_4854 = AI
    if L2_4854 then
      L3_4855 = A0_4852
      L2_4854 = A0_4852.Lock
      L2_4854(L3_4855)
    end
  end
  L2_4854 = A0_4852.portal
  if L2_4854 then
    L2_4854 = System
    L2_4854 = L2_4854.ActivatePortal
    L3_4855 = A0_4852.GetWorldPos
    L3_4855 = L3_4855(A0_4852)
    L2_4854(L3_4855, 0, A0_4852.id)
  end
  L2_4854 = A1_4853.nDirection
  L3_4855 = A1_4853.doPlay
  if L3_4855 == 1 then
    L3_4855 = A0_4852.DoPlayAnimation
    L3_4855(A0_4852, L2_4854, A1_4853.animTime)
  elseif L2_4854 == 1 then
    L3_4855 = A0_4852.GetAnimationLength
    L3_4855 = L3_4855(A0_4852, 0, A0_4852.Properties.Animation.anim_Open)
    A0_4852:DoPlayAnimation(L2_4854, L3_4855, false)
    A0_4852.curAnim = ""
    if AI then
      AI.ModifySmartObjectStates(A0_4852.id, "Open-Closed")
    end
  end
end
L0_4848.OnLoad = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4856, A1_4857)
  A1_4857.bLocked = A0_4856.bLocked
  if A0_4856.curAnim ~= "" and A0_4856.nDirection ~= 0 and A0_4856:IsAnimationRunning(0, 0) then
    A1_4857.doPlay = 1
    A1_4857.nDirection = A0_4856.nDirection
    A1_4857.animTime = A0_4856:GetAnimationTime(0, 0)
  else
    A1_4857.doPlay = 0
    A1_4857.nDirection = A0_4856.nDirection
  end
end
L0_4848.OnSave = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4858)
  A0_4858:Reset()
end
L0_4848.OnPropertyChange = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4859)
  A0_4859:Reset()
end
L0_4848.OnReset = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4860)
  A0_4860:Reset()
end
L0_4848.OnSpawn = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4861)
  if A0_4861.portal then
    System.ActivatePortal(A0_4861:GetWorldPos(), 0, A0_4861.id)
  end
  A0_4861.bLocked = false
  A0_4861.portal = A0_4861.Properties.bActivatePortal ~= 0
  A0_4861.bUseSameAnim = A0_4861.Properties.Animation.anim_Close == ""
  if A0_4861.Properties.object_Model ~= "" then
    A0_4861:LoadObject(0, A0_4861.Properties.object_Model)
  end
  A0_4861.bNoAnims = A0_4861.Properties.Animation.anim_Open == "" and A0_4861.Properties.Animation.anim_Close == ""
  A0_4861:PhysicalizeThis()
  A0_4861:DoStopSound()
  A0_4861.nDirection = -1
  A0_4861.curAnim = ""
  if AI then
    AI.SetSmartObjectState(A0_4861.id, "Closed")
  end
  if A0_4861.Properties.bLocked ~= 0 then
    A0_4861:Lock()
  end
end
L0_4848.Reset = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4862)
  local L1_4863
  L1_4863 = A0_4862.Properties
  L1_4863 = L1_4863.Physics
  EntityCommon.PhysicalizeRigid(A0_4862, 0, L1_4863, 1)
end
L0_4848.PhysicalizeThis = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4864, A1_4865)
  local L2_4866, L3_4867, L4_4868, L5_4869, L6_4870, L7_4871
  if not A1_4865 then
    L2_4866 = 0
    return L2_4866
  end
  L2_4866 = A0_4864.bLocked
  if L2_4866 then
    L2_4866 = A0_4864.nDirection
    if L2_4866 == -1 then
      L2_4866 = 0
      return L2_4866
    end
  end
  L2_4866 = A0_4864.Properties
  L2_4866 = L2_4866.fUseDistance
  if L2_4866 <= 0 then
    L3_4867 = 0
    return L3_4867
  end
  L3_4867 = g_Vectors
  L3_4867 = L3_4867.temp_v1
  L5_4869 = A0_4864
  L4_4868 = A0_4864.GetWorldBBox
  L5_4869 = L4_4868(L5_4869)
  L6_4870 = FastSumVectors
  L7_4871 = L4_4868
  L6_4870(L7_4871, L4_4868, L5_4869)
  L6_4870 = ScaleVectorInPlace
  L7_4871 = L4_4868
  L6_4870(L7_4871, 0.5)
  L7_4871 = A1_4865
  L6_4870 = A1_4865.GetWorldPos
  L6_4870(L7_4871, L3_4867)
  L6_4870 = SubVectors
  L7_4871 = L3_4867
  L6_4870(L7_4871, L3_4867, L4_4868)
  L6_4870 = A0_4864.Properties
  L6_4870 = L6_4870.fUseDistance
  L7_4871 = LengthSqVector
  L7_4871 = L7_4871(L3_4867)
  if L7_4871 < L6_4870 * L6_4870 then
    L7_4871 = 1
    return L7_4871
  else
    L7_4871 = 0
    return L7_4871
  end
end
L0_4848.IsUsable = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4872, A1_4873)
  local L2_4874
  L2_4874 = "@use_door"
  return L2_4874
end
L0_4848.GetUsableMessage = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4875, A1_4876)
  local L2_4877
  L2_4877 = A0_4875.nDirection
  if L2_4877 == 0 then
    return
  end
  L2_4877 = A0_4875.nDirection
  L2_4877 = -L2_4877
  if L2_4877 == 1 then
    A0_4875:Event_Open()
  else
    A0_4875:Event_Close()
  end
end
L0_4848.OnUsed = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4878)
  if AI then
    AI.ModifySmartObjectStates(A0_4878.id, "Locked")
  end
  A0_4878.bLocked = true
end
L0_4848.Lock = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4879)
  if AI then
    AI.ModifySmartObjectStates(A0_4879.id, "-Locked")
  end
  A0_4879.bLocked = false
end
L0_4848.Unlock = L1_4849
L0_4848 = AnimDoor
L0_4848 = L0_4848.Server
function L1_4849(A0_4880, A1_4881)
  if A0_4880.bNeedUpdate == 0 then
    return
  end
  if (A0_4880.bNoAnims ~= 0 or A0_4880.curAnim ~= "" and A0_4880.nDirection ~= 0) and not A0_4880:IsAnimationRunning(0, 0) then
    A0_4880.curAnim = ""
    if A0_4880.nDirection == -1 then
      if AI then
        AI.ModifySmartObjectStates(A0_4880.id, "Closed-Open")
      end
      if A0_4880.portal then
        System.ActivatePortal(A0_4880:GetWorldPos(), 0, A0_4880.id)
      end
      A0_4880:Activate(0)
      A0_4880.bNeedUpdate = 0
      BroadcastEvent(A0_4880, "Close")
    else
      if AI then
        AI.ModifySmartObjectStates(A0_4880.id, "Open-Closed")
      end
      A0_4880:Activate(0)
      A0_4880.bNeedUpdate = 0
      BroadcastEvent(A0_4880, "Open")
    end
  end
end
L0_4848.OnUpdate = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4882, A1_4883)
end
L0_4848.DoPlaySound = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4884)
  local L1_4885
end
L0_4848.DoStopSound = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4886, A1_4887, A2_4888, A3_4889)
  local L4_4890, L5_4891, L6_4892, L7_4893, L8_4894
  L4_4890 = A0_4886.nDirection
  if L4_4890 == A1_4887 then
    return
  end
  L4_4890 = 0
  L5_4891 = 0
  L6_4892 = 1
  L7_4893 = A0_4886.curAnim
  if L7_4893 ~= "" then
    L8_4894 = A0_4886
    L7_4893 = A0_4886.IsAnimationRunning
    L7_4893 = L7_4893(L8_4894, 0, 0)
    if L7_4893 then
      L8_4894 = A0_4886
      L7_4893 = A0_4886.GetAnimationTime
      L7_4893 = L7_4893(L8_4894, 0, 0)
      L4_4890 = L7_4893
      L8_4894 = A0_4886
      L7_4893 = A0_4886.GetAnimationLength
      L7_4893 = L7_4893(L8_4894, 0, A0_4886.curAnim)
      L5_4891 = L7_4893
      L7_4893 = A0_4886.bUseSameAnim
      L6_4892 = not L7_4893
    end
  end
  if L6_4892 then
    L7_4893 = A1_4887
    L8_4894 = A0_4886.Properties
    L8_4894 = L8_4894.Animation
    L8_4894 = L8_4894.anim_Open
    if A1_4887 == -1 and not A0_4886.bUseSameAnim then
      L8_4894 = A0_4886.Properties.Animation.anim_Close
      L7_4893 = -L7_4893
    end
    if not A0_4886.bNoAnims then
      A0_4886:StopAnimation(0, 0)
      A0_4886:StartAnimation(0, L8_4894)
      A0_4886:SetAnimationSpeed(0, 0, L7_4893)
      if A2_4888 then
        A0_4886:SetAnimationTime(0, 0, A2_4888)
      else
        L4_4890 = A0_4886:GetAnimationLength(0, L8_4894) * (1 - 1)
        A0_4886:SetAnimationTime(0, 0, L4_4890)
      end
    end
    A0_4886.curAnim = L8_4894
  else
    L8_4894 = A0_4886
    L7_4893 = A0_4886.SetAnimationSpeed
    L7_4893(L8_4894, 0, 0, A1_4887)
  end
  A0_4886.nDirection = A1_4887
  L8_4894 = A0_4886
  L7_4893 = A0_4886.ForceCharacterUpdate
  L7_4893(L8_4894, 0, true)
  L8_4894 = A0_4886
  L7_4893 = A0_4886.Activate
  L7_4893(L8_4894, 1)
  A0_4886.bNeedUpdate = 1
  L7_4893 = A0_4886.portal
  if L7_4893 then
    L7_4893 = System
    L7_4893 = L7_4893.ActivatePortal
    L8_4894 = A0_4886.GetWorldPos
    L8_4894 = L8_4894(A0_4886)
    L7_4893(L8_4894, 1, A0_4886.id)
  end
  L7_4893 = A0_4886.Properties
  L7_4893 = L7_4893.Sounds
  L7_4893 = L7_4893.snd_Open
  if A1_4887 == -1 then
    L8_4894 = A0_4886.Properties
    L8_4894 = L8_4894.Sounds
    L7_4893 = L8_4894.snd_Close
  end
  if A3_4889 == nil or A3_4889 then
    L8_4894 = A0_4886.DoPlaySound
    L8_4894(A0_4886, L7_4893)
  end
end
L0_4848.DoPlayAnimation = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4895)
  A0_4895:Unlock()
  BroadcastEvent(A0_4895, "Unlock")
end
L0_4848.Event_Unlock = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4896)
  A0_4896:Lock()
  BroadcastEvent(A0_4896, "Lock")
end
L0_4848.Event_Lock = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4897)
  A0_4897:DoPlayAnimation(1)
end
L0_4848.Event_Open = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4898)
  A0_4898:DoPlayAnimation(-1)
end
L0_4848.Event_Close = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4899)
  A0_4899:Hide(1)
  A0_4899:ActivateOutput("Hide", true)
end
L0_4848.Event_Hide = L1_4849
L0_4848 = AnimDoor
function L1_4849(A0_4900)
  A0_4900:Hide(0)
  A0_4900:ActivateOutput("UnHide", true)
end
L0_4848.Event_UnHide = L1_4849
L0_4848 = AnimDoor
L1_4849 = {}
L2_4850 = {}
L3_4851 = {
  AnimDoor.Event_Close,
  "bool"
}
L2_4850.Close = L3_4851
L3_4851 = {
  AnimDoor.Event_Open,
  "bool"
}
L2_4850.Open = L3_4851
L3_4851 = {
  AnimDoor.Event_Lock,
  "bool"
}
L2_4850.Lock = L3_4851
L3_4851 = {
  AnimDoor.Event_Unlock,
  "bool"
}
L2_4850.Unlock = L3_4851
L3_4851 = {
  AnimDoor.Event_Hide,
  "bool"
}
L2_4850.Hide = L3_4851
L3_4851 = {
  AnimDoor.Event_UnHide,
  "bool"
}
L2_4850.UnHide = L3_4851
L1_4849.Inputs = L2_4850
L2_4850 = {}
L2_4850.Close = "bool"
L2_4850.Open = "bool"
L2_4850.Lock = "bool"
L2_4850.Unlock = "bool"
L2_4850.Hide = "bool"
L2_4850.UnHide = "bool"
L1_4849.Outputs = L2_4850
L0_4848.FlowEvents = L1_4849
