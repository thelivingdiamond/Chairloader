Script.ReloadScript("scripts/Entities/Sound/Shared/AudioUtils.lua")
Door = {
  Properties = {
    soclasses_SmartObjectClass = "Door",
    fileModel = "engine/engineassets/objects/default.cgf",
    Audio = {
      audioTriggerOnMoveOpenTrigger = "",
      audioTriggerOnMoveCloseTrigger = "",
      audioTriggerOnStopTrigger = "",
      audioTriggerOnClosedTrigger = "",
      eiSoundObstructionType = 1
    },
    Rotation = {
      fSpeed = 200,
      fAcceleration = 500,
      fStopTime = 0.125,
      fRange = 90,
      sAxis = "z",
      bRelativeToUser = 1,
      sFrontAxis = "y"
    },
    Slide = {
      fSpeed = 2,
      fAcceleration = 3,
      fStopTime = 0.5,
      fRange = 0,
      sAxis = "x"
    },
    fUseDistance = 2.5,
    bLocked = 0,
    bSquashPlayers = 0,
    bActivatePortal = 0,
    bUsable = 1,
    UseMessage = "@use_door"
  },
  PhysParams = {mass = 0, density = 0},
  Server = {},
  Client = {},
  Editor = {Icon = "door.bmp", IconOnTop = 1},
  hOnMoveOpenTriggerID = nil,
  hOnMoveCloseTriggerID = nil,
  hOnStopTriggerID = nil,
  hOnClosedTriggerID = nil,
  tObstructionType = {},
  bIsActive = 0
}
DoorVars = {
  goalAngle = {
    x = 0,
    y = 0,
    z = 0
  },
  currAngle = {
    x = 0,
    y = 0,
    z = 0
  },
  modelAngle = {
    x = 0,
    y = 0,
    z = 0
  },
  goalPos = {
    x = 0,
    y = 0,
    z = 0
  },
  currPos = {
    x = 0,
    y = 0,
    z = 0
  },
  modelPos = {
    x = 0,
    y = 0,
    z = 0
  },
  locked = false
}
function CreateDoor(A0_4943)
  mergef(A0_4943, DoorVars, 1)
end
DOOR_TOGGLE = 0
DOOR_OPEN = 1
DOOR_CLOSE = 2
Net.Expose({
  Class = Door,
  ClientMethods = {
    ClSlide = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      BOOL
    },
    ClRotate = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      BOOL,
      BOOL
    }
  },
  ServerMethods = {
    SvRequestOpen = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      ENTITYID,
      BOOL
    }
  },
  ServerProperties = {}
})
function Door._LookupTriggerIDs(A0_4944)
  A0_4944.hOnMoveOpenTriggerID = AudioUtils.LookupTriggerID(A0_4944.Properties.Audio.audioTriggerOnMoveOpenTrigger)
  A0_4944.hOnMoveCloseTriggerID = AudioUtils.LookupTriggerID(A0_4944.Properties.Audio.audioTriggerOnMoveCloseTrigger)
  A0_4944.hOnStopTriggerID = AudioUtils.LookupTriggerID(A0_4944.Properties.Audio.audioTriggerOnStopTrigger)
  A0_4944.hOnClosedTriggerID = AudioUtils.LookupTriggerID(A0_4944.Properties.Audio.audioTriggerOnClosedTrigger)
end
function Door._LookupObstructionSwitchIDs(A0_4945)
  A0_4945.tObstructionType = AudioUtils.LookupObstructionSwitchAndStates()
end
function Door._SetObstruction(A0_4946)
  local L1_4947, L2_4948, L3_4949, L5_4950
  L1_4947 = A0_4946.Properties
  L1_4947 = L1_4947.Audio
  L1_4947 = L1_4947.eiSoundObstructionType
  L1_4947 = L1_4947 + 1
  L2_4948 = A0_4946.tObstructionType
  L2_4948 = L2_4948.hSwitchID
  if L2_4948 ~= nil then
    L2_4948 = A0_4946.tObstructionType
    L2_4948 = L2_4948.tStateIDs
    L2_4948 = L2_4948[L1_4947]
    if L2_4948 ~= nil then
      L3_4949 = A0_4946
      L2_4948 = A0_4946.SetAudioSwitchState
      L5_4950 = A0_4946.tObstructionType
      L5_4950 = L5_4950.hSwitchID
      L2_4948(L3_4949, L5_4950, A0_4946.tObstructionType.tStateIDs[L1_4947], A0_4946:GetDefaultAuxAudioProxyID())
    end
  end
end
function Door._Activate(A0_4951, A1_4952)
  A0_4951.bIsActive = A1_4952
  A0_4951:Activate(A1_4952)
end
function Door.OnLoad(A0_4953, A1_4954)
  local L2_4955
  L2_4955 = A1_4954.rotationUpdate
  A0_4953.rotationUpdate = L2_4955
  L2_4955 = A1_4954.slideUpdate
  A0_4953.slideUpdate = L2_4955
  L2_4955 = A1_4954.goalAngle
  A0_4953.goalAngle = L2_4955
  L2_4955 = A1_4954.currAngle
  A0_4953.currAngle = L2_4955
  L2_4955 = A1_4954.modelAngle
  A0_4953.modelAngle = L2_4955
  L2_4955 = A1_4954.goalPos
  A0_4953.goalPos = L2_4955
  L2_4955 = A1_4954.currPos
  A0_4953.currPos = L2_4955
  L2_4955 = A1_4954.modelPos
  A0_4953.modelPos = L2_4955
  L2_4955 = A1_4954.locked
  A0_4953.locked = L2_4955
  L2_4955 = A1_4954.bIsActive
  A0_4953.bIsActive = L2_4955
  L2_4955 = A1_4954.action
  A0_4953.action = L2_4955
end
function Door.OnSave(A0_4956, A1_4957)
  local L2_4958
  L2_4958 = A0_4956.rotationUpdate
  A1_4957.rotationUpdate = L2_4958
  L2_4958 = A0_4956.slideUpdate
  A1_4957.slideUpdate = L2_4958
  L2_4958 = A0_4956.goalAngle
  A1_4957.goalAngle = L2_4958
  L2_4958 = A0_4956.currAngle
  A1_4957.currAngle = L2_4958
  L2_4958 = A0_4956.modelAngle
  A1_4957.modelAngle = L2_4958
  L2_4958 = A0_4956.goalPos
  A1_4957.goalPos = L2_4958
  L2_4958 = A0_4956.currPos
  A1_4957.currPos = L2_4958
  L2_4958 = A0_4956.modelPos
  A1_4957.modelPos = L2_4958
  L2_4958 = A0_4956.locked
  A1_4957.locked = L2_4958
  L2_4958 = A0_4956.bIsActive
  A1_4957.bIsActive = L2_4958
  L2_4958 = A0_4956.action
  A1_4957.action = L2_4958
end
function Door.OnPropertyChange(A0_4959)
  A0_4959:Reset()
end
function Door.OnReset(A0_4960)
  A0_4960:Reset()
end
function Door.OnTransformFromEditorDone(A0_4961)
  A0_4961:Reset()
end
function Door.OnSpawn(A0_4962)
  CryAction.CreateGameObjectForEntity(A0_4962.id)
  CryAction.BindGameObjectToNetwork(A0_4962.id)
  CryAction.ForceGameObjectUpdate(A0_4962.id, true)
  A0_4962.isServer = CryAction.IsServer()
  A0_4962.isClient = CryAction.IsClient()
  A0_4962:Reset(1)
end
function Door.OnDestroy(A0_4963)
  local L1_4964
end
function Door.DoPhysicalize(A0_4965)
  if A0_4965.currModel ~= A0_4965.Properties.fileModel then
    CryAction.ActivateExtensionForGameObject(A0_4965.id, "ScriptControlledPhysics", false)
    A0_4965:LoadObject(0, A0_4965.Properties.fileModel)
    A0_4965:Physicalize(0, PE_RIGID, A0_4965.PhysParams)
    CryAction.ActivateExtensionForGameObject(A0_4965.id, "ScriptControlledPhysics", true)
  end
  if tonumber(A0_4965.Properties.bSquashPlayers) == 0 then
    A0_4965:SetPhysicParams(PHYSICPARAM_FLAGS, {flags_mask = pef_cannot_squash_players, flags = pef_cannot_squash_players})
  end
  A0_4965.currModel = A0_4965.Properties.fileModel
end
function Door.ResetAction(A0_4966)
  A0_4966.action = DOOR_CLOSE
  A0_4966.rotationUpdate = nil
  A0_4966.slideUpdate = nil
  if AI then
    AI.ModifySmartObjectStates(A0_4966.id, "Closed-Open")
  end
end
function Door.Reset(A0_4967, A1_4968)
  local L2_4969
  if A1_4968 then
    L2_4969 = CreateDoor
    L2_4969(A0_4967)
  end
  L2_4969 = A0_4967._Activate
  L2_4969(A0_4967, 0)
  if A1_4968 then
    L2_4969 = A0_4967.ResetAction
    L2_4969(A0_4967)
  end
  L2_4969 = A0_4967.DoPhysicalize
  L2_4969(A0_4967)
  L2_4969 = A0_4967.action
  if L2_4969 == DOOR_CLOSE then
    L2_4969 = A0_4967.rotationUpdate
    if not L2_4969 then
      L2_4969 = A0_4967.slideUpdate
      if not L2_4969 then
        L2_4969 = A0_4967.GetWorldAngles
        L2_4969(A0_4967, A0_4967.modelAngle)
        L2_4969 = A0_4967.GetWorldPos
        L2_4969(A0_4967, A0_4967.modelPos)
      end
    end
  end
  L2_4969 = A0_4967.ResetAction
  L2_4969(A0_4967)
  L2_4969 = CopyVector
  L2_4969(A0_4967.currAngle, A0_4967.modelAngle)
  L2_4969 = CopyVector
  L2_4969(A0_4967.goalAngle, A0_4967.modelAngle)
  L2_4969 = CopyVector
  L2_4969(A0_4967.currPos, A0_4967.modelPos)
  L2_4969 = CopyVector
  L2_4969(A0_4967.goalPos, A0_4967.modelPos)
  L2_4969 = A0_4967.portal
  if L2_4969 then
    L2_4969 = System
    L2_4969 = L2_4969.ActivatePortal
    L2_4969(A0_4967:GetWorldPos(), 0, A0_4967.id)
  end
  L2_4969 = A0_4967.UpdateRotation
  L2_4969(A0_4967, 0)
  L2_4969 = A0_4967.UpdateSlide
  L2_4969(A0_4967, 0)
  L2_4969 = A0_4967.AwakePhysics
  L2_4969(A0_4967, 1)
  L2_4969 = A0_4967.Properties
  L2_4969 = L2_4969.bLocked
  L2_4969 = L2_4969 ~= 0
  A0_4967.locked = L2_4969
  L2_4969 = A0_4967.Properties
  L2_4969 = L2_4969.bActivatePortal
  L2_4969 = L2_4969 ~= 0
  A0_4967.portal = L2_4969
  L2_4969 = string
  L2_4969 = L2_4969.lower
  L2_4969 = L2_4969(A0_4967.Properties.Rotation.sFrontAxis)
  if string.find(L2_4969, "x") then
    A0_4967.frontAxis = A0_4967:GetDirectionVector(0)
  elseif string.find(L2_4969, "y") then
    A0_4967.frontAxis = A0_4967:GetDirectionVector(1)
  else
    A0_4967.frontAxis = A0_4967:GetDirectionVector(2)
  end
  if L2_4969 == "-x" or L2_4969 == "-y" or L2_4969 == "-z" then
    A0_4967.frontAxis.x = -A0_4967.frontAxis.x
    A0_4967.frontAxis.y = -A0_4967.frontAxis.y
    A0_4967.frontAxis.z = -A0_4967.frontAxis.z
  end
  if AI then
    if A0_4967.locked == true then
      AI.SetSmartObjectState(A0_4967.id, "Locked,Closed")
    else
      AI.SetSmartObjectState(A0_4967.id, "Closed")
    end
  end
  if 0 > A0_4967.Properties.Audio.eiSoundObstructionType then
    A0_4967.Properties.Audio.eiSoundObstructionType = 0
  elseif 1 < A0_4967.Properties.Audio.eiSoundObstructionType then
    A0_4967.Properties.Audio.eiSoundObstructionType = 2
  end
  A0_4967:_LookupTriggerIDs()
  A0_4967:_LookupObstructionSwitchIDs()
  A0_4967:_SetObstruction()
end
function Door.UpdateRotation(A0_4970, A1_4971)
  local L2_4972, L3_4973
  L3_4973 = A0_4970
  L2_4972 = A0_4970.GetWorldAngles
  L2_4972 = L2_4972(L3_4973, g_Vectors.temp_v1)
  L3_4973 = A0_4970.goalAngle
  if L2_4972.x < 0 and L3_4973.x > 0 then
    L2_4972.x = L2_4972.x + 2 * math.pi
  end
  if L2_4972.x > 0 and L3_4973.x < 0 then
    L2_4972.x = L2_4972.x - 2 * math.pi
  end
  if 0 > L2_4972.y and 0 < L3_4973.y then
    L2_4972.y = L2_4972.y + 2 * math.pi
  end
  if 0 < L2_4972.y and 0 > L3_4973.y then
    L2_4972.y = L2_4972.y - 2 * math.pi
  end
  if 0 > L2_4972.z and 0 < L3_4973.z then
    L2_4972.z = L2_4972.z + 2 * math.pi
  end
  if 0 < L2_4972.z and 0 > L3_4973.z then
    L2_4972.z = L2_4972.z - 2 * math.pi
  end
  if vecLenSq(vecSub(L3_4973, L2_4972)) < 1.0E-4 then
    A0_4970.rotationUpdate = nil
    if A0_4970.action == DOOR_CLOSE and not A0_4970.slideUpdate and A0_4970.portal then
      System.ActivatePortal(A0_4970:GetWorldPos(), 0, A0_4970.id)
    end
  end
end
function Door.UpdateSlide(A0_4974, A1_4975)
  local L2_4976, L3_4977
  L3_4977 = A0_4974
  L2_4976 = A0_4974.GetWorldPos
  L2_4976 = L2_4976(L3_4977, g_Vectors.temp_v1)
  L3_4977 = A0_4974.goalPos
  if vecLenSq(vecSub(L3_4977, L2_4976)) < 1.0E-4 then
    A0_4974.slideUpdate = nil
    if A0_4974.action == DOOR_CLOSE and not A0_4974.rotationUpdate and A0_4974.portal then
      System.ActivatePortal(A0_4974:GetWorldPos(), 0, A0_4974.id)
    end
  end
end
function Door.IsUsable(A0_4978, A1_4979)
  local L2_4980
  L2_4980 = 0
  return L2_4980
end
function Door.GetUsableMessage(A0_4981, A1_4982)
  local L2_4983
  L2_4983 = ""
  return L2_4983
end
function Door.Server.OnCollision(A0_4984, A1_4985)
  if A1_4985.target_id ~= nil then
    if System.GetEntityClass(A1_4985.target_id) == "ArkProjectileGoo" then
      BroadcastEvent(A0_4984, "_Gooed")
    elseif System.GetEntityClass(A1_4985.target_id) == "ArkAmberProjectile" then
      BroadcastEvent(A0_4984, "_Gooed")
    end
  end
end
function Door.OnUsed(A0_4986, A1_4987)
  if A0_4986:IsUsable(A1_4987) ~= 1 then
    return nil
  end
  A0_4986.server:SvRequestOpen(A1_4987.id, A0_4986.action ~= DOOR_OPEN)
end
function Door.Server.OnUpdate(A0_4988, A1_4989)
  A0_4988:Update(A1_4989)
end
function Door.Client.OnUpdate(A0_4990, A1_4991)
  if not A0_4990.isServer then
    A0_4990:Update(A1_4991)
  end
end
function Door.Update(A0_4992, A1_4993)
  if A0_4992.rotationUpdate then
    A0_4992:UpdateRotation(A1_4993)
  end
  if A0_4992.slideUpdate then
    A0_4992:UpdateSlide(A1_4993)
  end
  if not A0_4992.slideUpdate and not A0_4992.rotationUpdate and A0_4992.bIsActive == 1 then
    A0_4992:_Activate(0)
  end
  if true then
    if A0_4992.action == DOOR_CLOSE then
      if A0_4992.hOnClosedTriggerID ~= nil then
        A0_4992:ExecuteAudioTrigger(A0_4992.hOnClosedTriggerID, A0_4992:GetDefaultAuxAudioProxyID())
      end
    elseif A0_4992.hOnStopTriggerID ~= nil then
      A0_4992:ExecuteAudioTrigger(A0_4992.hOnStopTriggerID, A0_4992:GetDefaultAuxAudioProxyID())
    end
  end
end
function Door.Server.OnInitClient(A0_4994, A1_4995)
  local L2_4996
  L2_4996 = A0_4994.Properties
  L2_4996 = L2_4996.Rotation
  L2_4996 = L2_4996.fRange
  if L2_4996 ~= 0 then
    L2_4996 = A0_4994.action
    L2_4996 = L2_4996 == DOOR_OPEN
    A0_4994.onClient:ClRotate(A1_4995, L2_4996, A0_4994.fwd or false)
  end
  L2_4996 = A0_4994.Properties
  L2_4996 = L2_4996.Slide
  L2_4996 = L2_4996.fRange
  if L2_4996 ~= 0 then
    L2_4996 = A0_4994.action
    L2_4996 = L2_4996 == DOOR_OPEN
    A0_4994.onClient:ClSlide(A1_4995, L2_4996)
  end
  L2_4996 = A0_4994._LookupTriggerIDs
  L2_4996(A0_4994)
  L2_4996 = A0_4994._LookupObstructionSwitchIDs
  L2_4996(A0_4994)
  L2_4996 = A0_4994._SetObstruction
  L2_4996(A0_4994)
end
function Door.Server.SvRequestOpen(A0_4997, A1_4998, A2_4999)
  local L3_5000, L4_5001
  L3_5000 = DOOR_TOGGGLE
  if A2_4999 then
    L3_5000 = DOOR_OPEN
  else
    L3_5000 = DOOR_CLOSE
  end
  L4_5001 = System
  L4_5001 = L4_5001.GetEntity
  L4_5001 = L4_5001(A1_4998)
  A0_4997:Open(L4_5001, L3_5000)
end
function Door.Client.ClRotate(A0_5002, A1_5003, A2_5004)
  if not A0_5002.isServer or g_gameRules.game:IsDemoMode() ~= 0 then
    if A1_5003 then
      A0_5002.action = DOOR_OPEN
    else
      A0_5002.action = DOOR_CLOSE
    end
    A0_5002:Rotate(A1_5003, A2_5004)
  end
end
function Door.Client.ClSlide(A0_5005, A1_5006)
  if not A0_5005.isServer or g_gameRules.game:IsDemoMode() ~= 0 then
    if A1_5006 then
      A0_5005.action = DOOR_OPEN
    else
      A0_5005.action = DOOR_CLOSE
    end
    A0_5005:Slide(A1_5006)
  end
end
function Door.Slide(A0_5007, A1_5008)
  local L2_5009, L3_5010, L4_5011
  if A1_5008 then
    L2_5009 = A0_5007.Properties
    L2_5009 = L2_5009.Slide
    L2_5009 = L2_5009.sAxis
    L3_5010 = A0_5007.Properties
    L3_5010 = L3_5010.Slide
    L3_5010 = L3_5010.fRange
    L4_5011 = g_Vectors
    L4_5011 = L4_5011.temp_v1
    if L2_5009 == "X" or L2_5009 == "x" then
      L4_5011 = A0_5007:GetDirectionVector(0)
    elseif L2_5009 == "Y" or L2_5009 == "y" then
      L4_5011 = A0_5007:GetDirectionVector(1)
    else
      L4_5011 = A0_5007:GetDirectionVector(2)
    end
    A0_5007.goalPos.x = A0_5007.modelPos.x + L4_5011.x * L3_5010
    A0_5007.goalPos.y = A0_5007.modelPos.y + L4_5011.y * L3_5010
    A0_5007.goalPos.z = A0_5007.modelPos.z + L4_5011.z * L3_5010
  else
    L2_5009 = CopyVector
    L3_5010 = A0_5007.goalPos
    L4_5011 = A0_5007.modelPos
    L2_5009(L3_5010, L4_5011)
  end
  L2_5009 = A0_5007.scp
  L3_5010 = L2_5009
  L2_5009 = L2_5009.MoveTo
  L4_5011 = A0_5007.goalPos
  L2_5009(L3_5010, L4_5011, A0_5007:GetSpeed(), A0_5007.Properties.Slide.fSpeed, A0_5007.Properties.Slide.fAcceleration, A0_5007.Properties.Slide.fStopTime)
  L2_5009 = A0_5007.portal
  if L2_5009 then
    L2_5009 = System
    L2_5009 = L2_5009.ActivatePortal
    L4_5011 = A0_5007
    L3_5010 = A0_5007.GetWorldPos
    L3_5010 = L3_5010(L4_5011)
    L4_5011 = 1
    L2_5009(L3_5010, L4_5011, A0_5007.id)
  end
  A0_5007.slideUpdate = 1
  L3_5010 = A0_5007
  L2_5009 = A0_5007._Activate
  L4_5011 = 1
  L2_5009(L3_5010, L4_5011)
  L3_5010 = A0_5007
  L2_5009 = A0_5007.Sound
  L4_5011 = A1_5008
  L2_5009(L3_5010, L4_5011)
end
function Door.Rotate(A0_5012, A1_5013, A2_5014)
  if A1_5013 then
    if not A2_5014 then
    end
    if A0_5012.Properties.Rotation.sAxis == "X" or A0_5012.Properties.Rotation.sAxis == "x" then
      A0_5012.goalAngle.x = A0_5012.modelAngle.x + -math.rad(A0_5012.Properties.Rotation.fRange)
    elseif A0_5012.Properties.Rotation.sAxis == "Y" or A0_5012.Properties.Rotation.sAxis == "y" then
      A0_5012.goalAngle.y = A0_5012.modelAngle.y + -math.rad(A0_5012.Properties.Rotation.fRange)
    else
      A0_5012.goalAngle.z = A0_5012.modelAngle.z + -math.rad(A0_5012.Properties.Rotation.fRange)
    end
  else
    CopyVector(A0_5012.goalAngle, A0_5012.modelAngle)
  end
  if A0_5012.portal then
    System.ActivatePortal(A0_5012:GetWorldPos(), 1, A0_5012.id)
  end
  A0_5012.scp:RotateToAngles(A0_5012.goalAngle, A0_5012.scp:GetAngularSpeed(), A0_5012.Properties.Rotation.fSpeed, A0_5012.Properties.Rotation.fAcceleration, A0_5012.Properties.Rotation.fStopTime)
  A0_5012.rotationUpdate = 1
  A0_5012:_Activate(1)
  A0_5012:Sound(A1_5013)
end
function Door.Sound(A0_5015, A1_5016)
  local L2_5017, L3_5018, L4_5019
  if A1_5016 then
    L2_5017 = A0_5015.hOnMoveOpenTriggerID
    if L2_5017 ~= nil then
      L3_5018 = A0_5015
      L2_5017 = A0_5015.ExecuteAudioTrigger
      L4_5019 = A0_5015.hOnMoveOpenTriggerID
      L2_5017(L3_5018, L4_5019, A0_5015:GetDefaultAuxAudioProxyID())
    end
  else
    L2_5017 = A0_5015.hOnMoveCloseTriggerID
    if L2_5017 ~= nil then
      L3_5018 = A0_5015
      L2_5017 = A0_5015.ExecuteAudioTrigger
      L4_5019 = A0_5015.hOnMoveCloseTriggerID
      L2_5017(L3_5018, L4_5019, A0_5015:GetDefaultAuxAudioProxyID())
    end
  end
end
function Door.Open(A0_5020, A1_5021, A2_5022)
  local L3_5023, L4_5024, L5_5025, L6_5026, L7_5027, L8_5028
  L3_5023 = A0_5020.action
  L4_5024 = A0_5020.locked
  if L4_5024 then
    L4_5024 = 0
    return L4_5024
  end
  L4_5024 = DOOR_TOGGLE
  if A2_5022 == L4_5024 then
    L4_5024 = A0_5020.action
    L5_5025 = DOOR_OPEN
    if L4_5024 == L5_5025 then
      L4_5024 = DOOR_CLOSE
      A0_5020.action = L4_5024
    else
      L4_5024 = DOOR_OPEN
      A0_5020.action = L4_5024
    end
  else
    A0_5020.action = A2_5022
  end
  L4_5024 = A0_5020.action
  if L3_5023 == L4_5024 then
    L4_5024 = 0
    return L4_5024
  end
  L4_5024 = A0_5020.Properties
  L4_5024 = L4_5024.Rotation
  L4_5024 = L4_5024.fRange
  if L4_5024 ~= 0 then
    L4_5024 = false
    L5_5025 = true
    L6_5026 = A0_5020.action
    L7_5027 = DOOR_OPEN
    if L6_5026 == L7_5027 then
      if A1_5021 then
        L6_5026 = tonumber
        L7_5027 = A0_5020.Properties
        L7_5027 = L7_5027.Rotation
        L7_5027 = L7_5027.bRelativeToUser
        L6_5026 = L6_5026(L7_5027)
        if L6_5026 ~= 0 then
          L6_5026 = g_Vectors
          L6_5026 = L6_5026.temp_v2
          L8_5028 = A0_5020
          L7_5027 = A0_5020.GetWorldPos
          L7_5027 = L7_5027(L8_5028, g_Vectors.temp_v3)
          L8_5028 = A1_5021.GetWorldPos
          L8_5028 = L8_5028(A1_5021, g_Vectors.temp_v4)
          SubVectors(L6_5026, L7_5027, L8_5028)
          NormalizeVector(L6_5026)
          if 0 > dotproduct3d(A0_5020.frontAxis, L6_5026) then
            L5_5025 = false
          end
        end
      end
      L4_5024 = true
    end
    A0_5020.fwd = L5_5025
    L7_5027 = A0_5020
    L6_5026 = A0_5020.Rotate
    L8_5028 = L4_5024
    L6_5026(L7_5027, L8_5028, L5_5025)
    L6_5026 = A0_5020.allClients
    L7_5027 = L6_5026
    L6_5026 = L6_5026.ClRotate
    L8_5028 = L4_5024
    L6_5026(L7_5027, L8_5028, L5_5025)
  end
  L4_5024 = A0_5020.Properties
  L4_5024 = L4_5024.Slide
  L4_5024 = L4_5024.fRange
  if L4_5024 ~= 0 then
    L4_5024 = A0_5020.action
    L5_5025 = DOOR_OPEN
    L4_5024 = L4_5024 == L5_5025
    L6_5026 = A0_5020
    L5_5025 = A0_5020.Slide
    L7_5027 = L4_5024
    L5_5025(L6_5026, L7_5027)
    L5_5025 = A0_5020.allClients
    L6_5026 = L5_5025
    L5_5025 = L5_5025.ClSlide
    L7_5027 = L4_5024
    L5_5025(L6_5026, L7_5027)
  end
  L4_5024 = AI
  if L4_5024 then
    L4_5024 = A0_5020.action
    L5_5025 = DOOR_OPEN
    if L4_5024 == L5_5025 then
      L4_5024 = AI
      L4_5024 = L4_5024.ModifySmartObjectStates
      L5_5025 = A0_5020.id
      L6_5026 = "Open-Closed"
      L4_5024(L5_5025, L6_5026)
      L4_5024 = BroadcastEvent
      L5_5025 = A0_5020
      L6_5026 = "Open"
      L4_5024(L5_5025, L6_5026)
    else
      L4_5024 = A0_5020.action
      L5_5025 = DOOR_CLOSE
      if L4_5024 == L5_5025 then
        L4_5024 = AI
        L4_5024 = L4_5024.ModifySmartObjectStates
        L5_5025 = A0_5020.id
        L6_5026 = "Closed-Open"
        L4_5024(L5_5025, L6_5026)
        L4_5024 = BroadcastEvent
        L5_5025 = A0_5020
        L6_5026 = "Close"
        L4_5024(L5_5025, L6_5026)
      end
    end
  end
  L4_5024 = 1
  return L4_5024
end
function Door.Event_Open(A0_5029, A1_5030)
  if A1_5030 == A0_5029 then
    return
  end
  A0_5029:Open(A1_5030, DOOR_OPEN)
end
function Door.Event_Close(A0_5031, A1_5032)
  if A1_5032 == A0_5031 then
    return
  end
  A0_5031:Open(A1_5032, DOOR_CLOSE)
end
function Door.Event_UnLock(A0_5033, A1_5034)
  A0_5033.locked = false
  if AI then
    AI.ModifySmartObjectStates(A0_5033.id, "-Locked")
  end
end
function Door.Event_Lock(A0_5035, A1_5036)
  A0_5035.locked = true
  if AI then
    AI.ModifySmartObjectStates(A0_5035.id, "Locked")
  end
end
Door.FlowEvents = {
  Inputs = {
    Close = {
      Door.Event_Close,
      "bool"
    },
    Open = {
      Door.Event_Open,
      "bool"
    },
    Lock = {
      Door.Event_Lock,
      "bool"
    },
    UnLock = {
      Door.Event_UnLock,
      "bool"
    }
  },
  Outputs = {
    Close = "bool",
    Open = "bool",
    Lock = "bool",
    UnLock = "bool",
    _Gooed = "bool"
  }
}
