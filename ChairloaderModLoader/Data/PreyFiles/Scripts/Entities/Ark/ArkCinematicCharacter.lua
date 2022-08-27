Script.ReloadScript("Scripts/Entities/Physics/BasicEntity.lua")
SEQUENCE_NOT_STARTED = 0
SEQUENCE_PLAYING = 1
SEQUENCE_STOPPED = 2
NPC_SPEAKER = 1
ArkCinematicCharacter = {
  Properties = {
    ActionController = "Animations/Mannequin/ADB/Ai_Human_ControllerDefs.xml",
    AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Human_Database.adb",
    metaTags_ArkMetaTags = "",
    Animation = {
      Animation = "Default",
      Speed = 1,
      bLoop = 1,
      bPlaying = 1,
      bAlwaysUpdate = 0,
      playerAnimationState = "",
      bPhysicalizeAfterAnimation = 0
    },
    Physics = {
      bArticulated = 0,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bBulletCollisionEnabled = 1
    },
    Rendering = {bWrinkleMap = 0},
    Cinematic = {bOnDemandModelLoad = 0, bRenderAlways = 0},
    ActivatePhysicsThreshold = 0,
    ActivatePhysicsDist = 50,
    bNoFriendlyFire = 0,
    object_Model = "objects/props/maritime/windsock/windsock.cga",
    MultiplayerOptions = {bNetworked = 0},
    ArkCharacter = {character_Character = "", bMuteVO = 0},
    ArkDialog = {audioProxyJointName = "head_jnt"},
    ArkSpeakerExtension = {nSpeakerType = NPC_SPEAKER},
    LipSync = {
      TransitionQueueSettings = {
        nCharacterSlot = 0,
        nAnimLayer = 12,
        sDefaultAnimName = "MissingLipSyncAnim"
      }
    }
  },
  ArkEmotionExtension = {nAnimLayer = 7},
  PHYSICALIZEAFTER_TIMER = 1,
  POSTQL_TIMER = 2,
  Client = {},
  Server = {},
  Editor = {
    Icon = "animobject.bmp",
    IconOnTop = 0
  }
}
Net.Expose({
  Class = ArkCinematicCharacter,
  ClientMethods = {
    ClEvent_StartAnimation = {
      RELIABLE_ORDERED,
      NO_ATTACH,
      FLOAT
    },
    ClEvent_ResetAnimation = {RELIABLE_ORDERED, NO_ATTACH},
    ClSync = {
      RELIABLE_ORDERED,
      NO_ATTACH,
      FLOAT,
      FLOAT,
      FLOAT
    }
  },
  ServerMethods = {
    SVSync = {RELIABLE_ORDERED, NO_ATTACH}
  },
  ServerProperties = {}
})
MakeDerivedEntityOverride(ArkCinematicCharacter, BasicEntity)
function ArkCinematicCharacter.LoadModelOnDemand(A0_3534)
  local L1_3535
  L1_3535 = A0_3534.Properties
  L1_3535 = L1_3535.Cinematic
  L1_3535 = L1_3535.bOnDemandModelLoad
  return L1_3535
end
function ArkCinematicCharacter.SetFromProperties(A0_3536)
  local L1_3537, L2_3538
  A0_3536.controllingAnimHere = true
  A0_3536.isModelLoaded = false
  A0_3536.isRagdollized = false
  L1_3537 = BasicEntity
  L1_3537 = L1_3537.SetFromProperties
  L2_3538 = A0_3536
  L1_3537(L2_3538)
  A0_3536.touchedByFlownode = false
  A0_3536.animstarted = 0
  L1_3537 = SEQUENCE_NOT_STARTED
  A0_3536.sequenceStatus = L1_3537
  L1_3537 = A0_3536.Properties
  L2_3538 = L1_3537.Animation
  L2_3538 = L2_3538.bPlaying
  A0_3536.bAnimPlaying = L2_3538
  L2_3538 = L1_3537.Animation
  L2_3538 = L2_3538.bLoop
  A0_3536.bAnimLoop = L2_3538
  L2_3538 = L1_3537.Animation
  L2_3538 = L2_3538.Animation
  A0_3536.animName = L2_3538
  L2_3538 = L1_3537.Animation
  L2_3538 = L2_3538.bPlaying
  if L2_3538 == 1 then
    L2_3538 = A0_3536.DoStartAnimation
    L2_3538(A0_3536)
  else
    L2_3538 = A0_3536.ResetAnimation
    L2_3538(A0_3536, 0, -1)
  end
  L2_3538 = L1_3537.Animation
  L2_3538 = L2_3538.bAlwaysUpdate
  if L2_3538 == 1 then
    L2_3538 = A0_3536.Activate
    L2_3538(A0_3536, 1)
  end
  L2_3538 = A0_3536.SetAnimationSpeed
  L2_3538(A0_3536, 0, 0, L1_3537.Animation.Speed)
  L2_3538 = L1_3537.Animation
  L2_3538 = L2_3538.Speed
  A0_3536.animationSpeed = L2_3538
  A0_3536.curAnimTime = 0
  L2_3538 = A0_3536.Properties
  L2_3538 = L2_3538.ActivatePhysicsThreshold
  if L2_3538 > 0 then
    L2_3538 = {}
    L2_3538.threshold = A0_3536.Properties.ActivatePhysicsThreshold
    L2_3538.detach_distance = A0_3536.Properties.ActivatePhysicsDist
    A0_3536:SetPhysicParams(PHYSICPARAM_AUTO_DETACHMENT, L2_3538)
  end
  L2_3538 = A0_3536.CheckShaderParamCallbacks
  L2_3538(A0_3536)
end
function ArkCinematicCharacter.SetupModel(A0_3539)
  if A0_3539:LoadModelOnDemand() == 0 or System.IsEditor() then
    A0_3539:LoadAndPhysicalizeModel()
  else
    Game.CacheResource("ArkCinematicCharacter.lua", A0_3539.Properties.object_Model, eGameCacheResourceType_StaticObject, 0)
  end
end
function ArkCinematicCharacter.LoadAndPhysicalizeModel(A0_3540)
  if not A0_3540.isModelLoaded then
    A0_3540:LoadObject(0, A0_3540.Properties.object_Model)
    A0_3540:RenderAlways(A0_3540.Properties.Cinematic.bRenderAlways)
    if A0_3540.Properties.Physics.bPhysicalize == 1 then
      A0_3540:PhysicalizeThis()
    end
    A0_3540.isModelLoaded = true
    CryAction.CreateGameObjectForEntity(A0_3540.id)
    CryAction.ActivateExtensionForGameObject(A0_3540.id, "ArkSpeakerExtension", true)
    CryAction.ActivateExtensionForGameObject(A0_3540.id, "ArkEmotionExtension", true)
    return 1
  end
  return 0
end
function ArkCinematicCharacter.UnloadModel(A0_3541)
  if A0_3541.isModelLoaded then
    A0_3541:DestroyPhysics()
    A0_3541:FreeSlot(0)
    A0_3541.isModelLoaded = false
  end
end
function ArkCinematicCharacter.OnSpawn(A0_3542)
  if A0_3542.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_3542:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  A0_3542.isRagdollized = false
  BasicEntity.OnSpawn(A0_3542)
  if A0_3542.Properties.Animation.bAlwaysUpdate == 1 then
    CryAction.CreateGameObjectForEntity(A0_3542.id)
    CryAction.BindGameObjectToNetwork(A0_3542.id)
    CryAction.ForceGameObjectUpdate(A0_3542.id, true)
    A0_3542:Activate(1)
  end
end
function ArkCinematicCharacter.OnReset(A0_3543)
  BasicEntity.OnReset(A0_3543)
  A0_3543.bAnimPlaying = 0
  A0_3543:SetFromProperties()
  A0_3543.sequenceStatus = SEQUENCE_NOT_STARTED
end
function ArkCinematicCharacter.Event_ResetAnimation(A0_3544)
  A0_3544.controllingAnimHere = true
  A0_3544:ResetAnimation(0, -1)
  A0_3544.animstarted = 0
  if 0 < A0_3544.Properties.Physics.Mass then
    A0_3544:OnReset()
  else
    A0_3544.animName = A0_3544.Properties.Animation.Animation
    A0_3544:StartAnimation(0, A0_3544.Properties.Animation.Animation, 0, 0, 0, false)
  end
  if CryAction.IsServer() and A0_3544.allClients then
    A0_3544.allClients:ClEvent_ResetAnimation()
  end
end
function ArkCinematicCharacter.Event_StartAnimation(A0_3545, A1_3546)
  A0_3545.controllingAnimHere = true
  A0_3545:StartEntityAnimation()
  A0_3545.animstarted = 1
  if CryAction.IsServer() and A0_3545.allClients then
    A0_3545.allClients:ClEvent_StartAnimation(CryAction.GetServerTime())
  end
end
function ArkCinematicCharacter.Event_StopAnimation(A0_3547, A1_3548)
  A0_3547.controllingAnimHere = true
  if A0_3547.animstarted == 1 and A0_3547:IsAnimationRunning(0, 0) then
    A0_3547.curAnimTime = A0_3547:GetAnimationTime(0, 0)
  else
    A0_3547.curAnimTime = 0
  end
  A0_3547:StopAnimation(0, -1)
  A0_3547.animstarted = 0
end
function ArkCinematicCharacter.Event_RagdollizeDerived(A0_3549)
  local L1_3550
  A0_3549.isRagdollized = true
end
function ArkCinematicCharacter.Event_ModelLoad(A0_3551)
  if A0_3551:LoadAndPhysicalizeModel() ~= 0 then
    A0_3551:RelinkAllEntities()
  end
end
function ArkCinematicCharacter.Event_ModelUnload(A0_3552)
  if not System.IsEditor() then
    A0_3552:UnloadModel()
  end
end
function ArkCinematicCharacter.Event_RenderAlwaysEnable(A0_3553)
  A0_3553:RenderAlways(1)
end
function ArkCinematicCharacter.Event_RenderAlwaysDisable(A0_3554)
  A0_3554:RenderAlways(0)
end
function ArkCinematicCharacter.DoStartAnimation(A0_3555)
  A0_3555.animName = A0_3555.Properties.Animation.Animation
  A0_3555:StartAnimation(0, A0_3555.Properties.Animation.Animation, 0, 0, A0_3555.Properties.Animation.Speed, A0_3555.Properties.Animation.bLoop, 1)
  A0_3555:ForceCharacterUpdate(0, true)
  A0_3555.animstarted = 1
  if 0 > A0_3555.Properties.Animation.Speed then
    A0_3555.curAnimTime = 0
  else
    A0_3555.curAnimTime = A0_3555:GetAnimationLength(0, A0_3555.Properties.Animation.Animation)
  end
  A0_3555.startTime = CryAction.GetServerTime()
  if A0_3555.timeDiff then
    A0_3555.startTime = A0_3555.startTime - A0_3555.timeDiff
  end
end
function ArkCinematicCharacter.StartEntityAnimation(A0_3556)
  local L1_3557, L2_3558
  L2_3558 = A0_3556
  L1_3557 = A0_3556.StopAnimation
  L1_3557(L2_3558, 0, -1)
  L2_3558 = A0_3556
  L1_3557 = A0_3556.DoStartAnimation
  L1_3557(L2_3558)
  A0_3556.bStopAnimAfterQL = false
  L2_3558 = A0_3556
  L1_3557 = A0_3556.KillTimer
  L1_3557(L2_3558, A0_3556.POSTQL_TIMER)
  L1_3557 = A0_3556.Properties
  L1_3557 = L1_3557.Animation
  L1_3557 = L1_3557.playerAnimationState
  L2_3558 = g_localActor
  if L2_3558 and L1_3557 ~= "" then
    L2_3558 = g_localActor
    L2_3558 = L2_3558.actor
    L2_3558 = L2_3558.CreateCodeEvent
    L2_3558(L2_3558, {
      event = "animationControl",
      pos = A0_3556:GetWorldPos(),
      angle = A0_3556:GetWorldAngles()
    })
    L2_3558 = g_localActor
    L2_3558 = L2_3558.actor
    L2_3558 = L2_3558.QueueAnimationState
    L2_3558(L2_3558, L1_3557)
    L2_3558 = A0_3556.Properties
    L2_3558 = L2_3558.Animation
    L2_3558 = L2_3558.bPhysicalizeAfterAnimation
    if L2_3558 == 1 then
      L2_3558 = A0_3556.GetAnimationLength
      L2_3558 = L2_3558(A0_3556, 0, A0_3556.Properties.Animation.Animation)
      L2_3558 = L2_3558 * 1000
      L2_3558 = L2_3558 / A0_3556.Properties.Animation.Speed
      A0_3556:SetTimer(A0_3556.PHYSICALIZEAFTER_TIMER, L2_3558)
    end
  end
end
function ArkCinematicCharacter.Client.OnTimer(A0_3559, A1_3560, A2_3561)
  if A1_3560 == A0_3559.PHYSICALIZEAFTER_TIMER then
    A0_3559.Properties.Physics.bRigidBodyActive = 1
    A0_3559.Properties.Physics.bPhysicalize = 1
    A0_3559.Properties.Physics.bRigidBody = 1
    A0_3559.Properties.Physics.bResting = 0
    if A0_3559.bRigidBodyActive ~= A0_3559.Properties.Physics.bRigidBodyActive then
      A0_3559.bRigidBodyActive = A0_3559.Properties.Physics.bRigidBodyActive
      A0_3559:PhysicalizeThis()
    end
    if A0_3559.Properties.Physics.bRigidBody == 1 then
      A0_3559:AwakePhysics(1 - A0_3559.Properties.Physics.bResting)
      A0_3559.bRigidBodyActive = A0_3559.Properties.Physics.bRigidBodyActive
    end
  end
  if A1_3560 == A0_3559.POSTQL_TIMER and A0_3559.sequenceStatus == SEQUENCE_NOT_STARTED then
    A0_3559:StopAnimation(0, -1)
  end
end
function ArkCinematicCharacter.Client.OnUpdate(A0_3562, A1_3563)
  if A0_3562.bStopAnimAfterQL then
    A0_3562.bStopAnimAfterQL = false
    A0_3562:SetTimer(A0_3562.POSTQL_TIMER, 0.2)
    if A0_3562.Properties.Animation.bAlwaysUpdate ~= 1 then
      A0_3562:Activate(0)
    end
  end
end
function ArkCinematicCharacter.OnLoad(A0_3564, A1_3565)
  local L2_3566
  L2_3566 = A1_3565.isRagdollized
  if A0_3564.isRagdollized and not wasRagdollized then
    A0_3564:OnReset()
  end
  A0_3564.bAnimPlaying = A1_3565.bAnimPlaying
  A0_3564.bAnimLoop = A1_3565.bAnimLoop
  A0_3564.animName = A1_3565.animName
  A0_3564.animstarted = A1_3565.animstarted
  A0_3564.health = A1_3565.health
  A0_3564.dead = A1_3565.dead
  A0_3564.controllingAnimHere = A1_3565.bControllingAnimHere
  if A0_3564.controllingAnimHere then
    if A0_3564.animstarted == 1 then
      A0_3564:StartEntityAnimation()
      A0_3564:SetAnimationTime(0, 0, A1_3565.animTime)
    else
      if 0 < A1_3565.animTime then
        if A0_3564.animName ~= A0_3564.Properties.Animation.Animation then
          A0_3564:StartAnimation(0, A0_3564.animName, 0, 0, A0_3564.Properties.Animation.Speed, A0_3564.Properties.Animation.bLoop, 1)
          A0_3564:SetAnimationTime(0, 0, A1_3565.animTime)
        else
          A0_3564:StartEntityAnimation()
        end
        A0_3564:SetAnimationTime(0, 0, A1_3565.animTime)
        A0_3564.bStopAnimAfterQL = true
        A0_3564:Activate(1)
        A0_3564.curAnimTime = A1_3565.animTime
      end
      if A1_3565.animTime == 0 then
        if A1_3565.sequenceStatus == SEQUENCE_NOT_STARTED and A0_3564.sequenceStatus ~= SEQUENCE_NOT_STARTED or A0_3564.touchedByFlownode then
          A0_3564:ResetAnimation(0, -1)
          A0_3564:StartEntityAnimation()
          A0_3564:SetAnimationTime(0, 0, 0)
          A0_3564.bStopAnimAfterQL = true
          A0_3564:Activate(1)
          A0_3564.curAnimTime = 0
        end
      end
    end
  else
    A0_3564.externalAnim_anim = A1_3565.externalAnim_anim
    A0_3564.externalAnim_layer = A1_3565.externalAnim_layer
    A0_3564.externalAnim_loop = A1_3565.externalAnim_loop
    A0_3564:StartAnimation(0, A0_3564.externalAnim_anim, A0_3564.externalAnim_layer, 0, 1, A0_3564.externalAnim_loop)
    A0_3564:SetAnimationTime(0, A0_3564.externalAnim_layer, A1_3565.animTime)
  end
  A0_3564.touchedByFlownode = false
  if A0_3564.Properties.Physics.bArticulated == 0 and A0_3564.Properties.Physics.bRigidBody == 0 and A0_3564.Properties.Physics.bPhysicalize == 1 then
    A0_3564:PhysicalizeThis()
  end
  A0_3564.sequenceStatus = A1_3565.sequenceStatus
end
function ArkCinematicCharacter.OnSave(A0_3567, A1_3568)
  A1_3568.isRagdollized = A0_3567.isRagdollized
  A1_3568.bAnimPlaying = A0_3567.bAnimPlaying
  A1_3568.bAnimLoop = A0_3567.bAnimLoop
  A1_3568.animName = A0_3567.animName
  A1_3568.sequenceStatus = A0_3567.sequenceStatus
  A1_3568.health = A0_3567.health
  A1_3568.dead = A0_3567.dead
  A1_3568.bControllingAnimHere = A0_3567.controllingAnimHere
  if A0_3567.controllingAnimHere then
    if A0_3567.animstarted == 1 and A0_3567:IsAnimationRunning(0, 0) then
      A1_3568.animTime = A0_3567:GetAnimationTime(0, 0)
      A1_3568.animstarted = 1
    else
      A1_3568.animstarted = 0
      if A0_3567.curAnimTime then
        A1_3568.animTime = A0_3567.curAnimTime
      else
        A1_3568.animTime = 0
      end
    end
  else
    A1_3568.externalAnim_anim = A0_3567.externalAnim_anim
    A1_3568.externalAnim_layer = A0_3567.externalAnim_layer
    A1_3568.externalAnim_loop = A0_3567.externalAnim_loop
    A1_3568.animTime = A0_3567:GetAnimationTime(0, A0_3567.externalAnim_layer)
  end
end
ArkCinematicCharacter.FlowEvents.Inputs.ResetAnimation = {
  ArkCinematicCharacter.Event_ResetAnimation,
  "bool"
}
ArkCinematicCharacter.FlowEvents.Inputs.StartAnimation = {
  ArkCinematicCharacter.Event_StartAnimation,
  "bool"
}
ArkCinematicCharacter.FlowEvents.Inputs.StopAnimation = {
  ArkCinematicCharacter.Event_StopAnimation,
  "bool"
}
ArkCinematicCharacter.FlowEvents.Inputs.ModelLoad = {
  ArkCinematicCharacter.Event_ModelLoad,
  "bool"
}
ArkCinematicCharacter.FlowEvents.Inputs.ModelUnload = {
  ArkCinematicCharacter.Event_ModelUnload,
  "bool"
}
function ArkCinematicCharacter.Client.ClEvent_StartAnimation(A0_3569, A1_3570)
  A0_3569.timeDiff = CryAction.GetServerTime() - A1_3570
  if not CryAction.IsServer() then
    A0_3569:Event_StartAnimation()
  end
end
function ArkCinematicCharacter.Client.ClEvent_ResetAnimation(A0_3571)
  if not CryAction.IsServer() then
    A0_3571:Event_ResetAnimation()
  end
end
function ArkCinematicCharacter.SavePhysicalState(A0_3572)
  A0_3572.initPos = A0_3572:GetPos()
  A0_3572.initRot = A0_3572:GetWorldAngles()
  A0_3572.initScale = A0_3572:GetScale()
end
function ArkCinematicCharacter.RestorePhysicalState(A0_3573)
  A0_3573:SetPos(A0_3573.initPos)
  A0_3573:SetWorldAngles(A0_3573.initRot)
  A0_3573:SetScale(A0_3573.initScale)
  A0_3573:ResetAnimation(0, -1)
  A0_3573.animstarted = 0
  if 0 < A0_3573.Properties.Physics.Mass then
    A0_3573:OnReset()
  else
    A0_3573.animName = A0_3573.Properties.Animation.Animation
    A0_3573:StartAnimation(0, A0_3573.Properties.Animation.Animation, 0, 0, 0, false)
  end
end
function ArkCinematicCharacter.PhysicalizeThis(A0_3574)
  local L1_3575, L2_3576
  L1_3575 = BasicEntity
  L1_3575 = L1_3575.PhysicalizeThis
  L2_3576 = A0_3574
  L1_3575(L2_3576)
  L1_3575 = A0_3574.Properties
  L1_3575 = L1_3575.Physics
  L2_3576 = L1_3575.bBulletCollisionEnabled
  if L2_3576 == 0 then
    L2_3576 = {}
    L2_3576.flags_mask = geom_colltype_ray + geom_colltype_foliage_proxy
    L2_3576.flags = geom_colltype_player * L1_3575.bPushableByPlayers
    A0_3574:SetPhysicParams(PHYSICPARAM_PART_FLAGS, L2_3576)
  end
end
function ArkCinematicCharacter.SendSyncToClient(A0_3577, A1_3578)
  if A0_3577.animstarted == 1 then
    animTime = A0_3577:GetAnimationTime(0, 0)
    A0_3577.onClient:ClSync(A1_3578, animTime, A0_3577.startTime, CryAction.GetServerTime())
  end
end
function ArkCinematicCharacter.Server.OnPostInitClient(A0_3579, A1_3580)
  A0_3579:SendSyncToClient(A1_3580)
end
function ArkCinematicCharacter.Server.SVSync(A0_3581, A1_3582)
  A0_3581:SendSyncToClient(A1_3582)
end
function ArkCinematicCharacter.Client.ClSync(A0_3583, A1_3584, A2_3585, A3_3586)
  A0_3583:StartEntityAnimation()
  A0_3583.startTime = A2_3585
  A0_3583:SetAnimationTime(0, 0, A1_3584)
end
function ArkCinematicCharacter.UpdateFromServer(A0_3587)
  A0_3587.server:SVSync()
end
function ArkCinematicCharacter.OnSequenceStart(A0_3588)
  A0_3588.sequenceStatus = SEQUENCE_PLAYING
end
function ArkCinematicCharacter.OnSequenceStop(A0_3589)
  A0_3589.sequenceStatus = SEQUENCE_STOPPED
end
function ArkCinematicCharacter.OnSequenceAnimationStart(A0_3590, A1_3591)
  A0_3590.sequenceStatus = SEQUENCE_PLAYING
  A0_3590.animName = A1_3591
end
function ArkCinematicCharacter.OnSequenceAnimationStop(A0_3592)
  A0_3592.sequenceStatus = SEQUENCE_STOPPED
end
function ArkCinematicCharacter.OnFlowGraphAnimationStart(A0_3593, A1_3594, A2_3595, A3_3596)
  A0_3593.animName = A1_3594
  A0_3593.externalAnim_anim = A1_3594
  A0_3593.controllingAnimHere = false
  A0_3593.externalAnim_layer = A2_3595
  A0_3593.externalAnim_loop = A3_3596
  A0_3593.touchedByFlownode = true
end
function ArkCinematicCharacter.OnFlowGraphAnimationStop(A0_3597)
  if A0_3597.externalAnim_layer then
    A0_3597.curAnimTime = A0_3597:GetAnimationTime(0, A0_3597.externalAnim_layer)
  end
  A0_3597.controllingAnimHere = true
end
function ArkCinematicCharacter.OnFlowGraphAnimationEnd(A0_3598)
  local L1_3599
  A0_3598.curAnimTime = 1
  A0_3598.controllingAnimHere = true
end
