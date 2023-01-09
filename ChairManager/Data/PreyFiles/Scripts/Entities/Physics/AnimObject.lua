Script.ReloadScript("Scripts/Entities/Physics/BasicEntity.lua")
SEQUENCE_NOT_STARTED = 0
SEQUENCE_PLAYING = 1
SEQUENCE_STOPPED = 2
AnimObject = {
  Properties = {
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
    Rendering = {bWrinkleMap = 0, bIsArkSceneWindow = 0},
    Cinematic = {bOnDemandModelLoad = 0, bRenderAlways = 0},
    ActivatePhysicsThreshold = 0,
    ActivatePhysicsDist = 50,
    bNoFriendlyFire = 0,
    object_Model = "objects/props/maritime/windsock/windsock.cga",
    MultiplayerOptions = {bNetworked = 0}
  },
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
  Class = AnimObject,
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
MakeDerivedEntityOverride(AnimObject, BasicEntity)
function AnimObject.LoadModelOnDemand(A0_7389)
  local L1_7390
  L1_7390 = A0_7389.Properties
  L1_7390 = L1_7390.Cinematic
  L1_7390 = L1_7390.bOnDemandModelLoad
  return L1_7390
end
function AnimObject.SetFromProperties(A0_7391)
  local L1_7392, L2_7393
  A0_7391.controllingAnimHere = true
  A0_7391.isModelLoaded = false
  A0_7391.isRagdollized = false
  L1_7392 = BasicEntity
  L1_7392 = L1_7392.SetFromProperties
  L2_7393 = A0_7391
  L1_7392(L2_7393)
  A0_7391.touchedByFlownode = false
  A0_7391.animstarted = 0
  L1_7392 = SEQUENCE_NOT_STARTED
  A0_7391.sequenceStatus = L1_7392
  L1_7392 = A0_7391.Properties
  L2_7393 = L1_7392.Animation
  L2_7393 = L2_7393.bPlaying
  A0_7391.bAnimPlaying = L2_7393
  L2_7393 = L1_7392.Animation
  L2_7393 = L2_7393.bLoop
  A0_7391.bAnimLoop = L2_7393
  L2_7393 = L1_7392.Animation
  L2_7393 = L2_7393.Animation
  A0_7391.animName = L2_7393
  L2_7393 = L1_7392.Animation
  L2_7393 = L2_7393.bPlaying
  if L2_7393 == 1 then
    L2_7393 = A0_7391.DoStartAnimation
    L2_7393(A0_7391)
  else
    L2_7393 = A0_7391.ResetAnimation
    L2_7393(A0_7391, 0, -1)
  end
  L2_7393 = L1_7392.Animation
  L2_7393 = L2_7393.bAlwaysUpdate
  if L2_7393 == 1 then
    L2_7393 = A0_7391.Activate
    L2_7393(A0_7391, 1)
  end
  L2_7393 = A0_7391.SetAnimationSpeed
  L2_7393(A0_7391, 0, 0, L1_7392.Animation.Speed)
  L2_7393 = L1_7392.Animation
  L2_7393 = L2_7393.Speed
  A0_7391.animationSpeed = L2_7393
  A0_7391.curAnimTime = 0
  L2_7393 = A0_7391.Properties
  L2_7393 = L2_7393.ActivatePhysicsThreshold
  if L2_7393 > 0 then
    L2_7393 = {}
    L2_7393.threshold = A0_7391.Properties.ActivatePhysicsThreshold
    L2_7393.detach_distance = A0_7391.Properties.ActivatePhysicsDist
    A0_7391:SetPhysicParams(PHYSICPARAM_AUTO_DETACHMENT, L2_7393)
  end
  L2_7393 = A0_7391.CheckShaderParamCallbacks
  L2_7393(A0_7391)
  L2_7393 = A0_7391.SetAsSceneWindow
  L2_7393(A0_7391, L1_7392.Rendering.bIsArkSceneWindow)
end
function AnimObject.SetupModel(A0_7394)
  if A0_7394:LoadModelOnDemand() == 0 or System.IsEditor() then
    A0_7394:LoadAndPhysicalizeModel()
  else
    Game.CacheResource("AnimObject.lua", A0_7394.Properties.object_Model, eGameCacheResourceType_StaticObject, 0)
  end
end
function AnimObject.LoadAndPhysicalizeModel(A0_7395)
  if not A0_7395.isModelLoaded then
    A0_7395:LoadObject(0, A0_7395.Properties.object_Model)
    A0_7395:RenderAlways(A0_7395.Properties.Cinematic.bRenderAlways)
    if A0_7395.Properties.Physics.bPhysicalize == 1 then
      A0_7395:PhysicalizeThis()
    end
    A0_7395.isModelLoaded = true
    return 1
  end
  return 0
end
function AnimObject.UnloadModel(A0_7396)
  if A0_7396.isModelLoaded then
    A0_7396:DestroyPhysics()
    A0_7396:FreeSlot(0)
    A0_7396.isModelLoaded = false
  end
end
function AnimObject.OnSpawn(A0_7397)
  if A0_7397.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_7397:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  A0_7397.isRagdollized = false
  BasicEntity.OnSpawn(A0_7397)
  if A0_7397.Properties.Animation.bAlwaysUpdate == 1 then
    CryAction.CreateGameObjectForEntity(A0_7397.id)
    CryAction.BindGameObjectToNetwork(A0_7397.id)
    CryAction.ForceGameObjectUpdate(A0_7397.id, true)
    A0_7397:Activate(1)
  end
end
function AnimObject.OnReset(A0_7398)
  BasicEntity.OnReset(A0_7398)
  A0_7398.bAnimPlaying = 0
  A0_7398:SetFromProperties()
  A0_7398.sequenceStatus = SEQUENCE_NOT_STARTED
end
function AnimObject.Event_ResetAnimation(A0_7399)
  A0_7399.controllingAnimHere = true
  A0_7399:ResetAnimation(0, -1)
  A0_7399.animstarted = 0
  if 0 < A0_7399.Properties.Physics.Mass then
    A0_7399:OnReset()
  else
    A0_7399.animName = A0_7399.Properties.Animation.Animation
    A0_7399:StartAnimation(0, A0_7399.Properties.Animation.Animation, 0, 0, 0, false)
  end
  if CryAction.IsServer() and A0_7399.allClients then
    A0_7399.allClients:ClEvent_ResetAnimation()
  end
end
function AnimObject.Event_StartAnimation(A0_7400, A1_7401)
  A0_7400.controllingAnimHere = true
  A0_7400:StartEntityAnimation()
  A0_7400.animstarted = 1
  if CryAction.IsServer() and A0_7400.allClients then
    A0_7400.allClients:ClEvent_StartAnimation(CryAction.GetServerTime())
  end
end
function AnimObject.Event_StopAnimation(A0_7402, A1_7403)
  A0_7402.controllingAnimHere = true
  if A0_7402.animstarted == 1 and A0_7402:IsAnimationRunning(0, 0) then
    A0_7402.curAnimTime = A0_7402:GetAnimationTime(0, 0)
  else
    A0_7402.curAnimTime = 0
  end
  A0_7402:StopAnimation(0, -1)
  A0_7402.animstarted = 0
end
function AnimObject.Event_RagdollizeDerived(A0_7404)
  local L1_7405
  A0_7404.isRagdollized = true
end
function AnimObject.Event_ModelLoad(A0_7406)
  if A0_7406:LoadAndPhysicalizeModel() ~= 0 then
    A0_7406:RelinkAllEntities()
  end
end
function AnimObject.Event_ModelUnload(A0_7407)
  if not System.IsEditor() then
    A0_7407:UnloadModel()
  end
end
function AnimObject.Event_RenderAlwaysEnable(A0_7408)
  A0_7408:RenderAlways(1)
end
function AnimObject.Event_RenderAlwaysDisable(A0_7409)
  A0_7409:RenderAlways(0)
end
function AnimObject.DoStartAnimation(A0_7410)
  A0_7410.animName = A0_7410.Properties.Animation.Animation
  A0_7410:StartAnimation(0, A0_7410.Properties.Animation.Animation, 0, 0, A0_7410.Properties.Animation.Speed, A0_7410.Properties.Animation.bLoop, 1)
  A0_7410:ForceCharacterUpdate(0, true)
  A0_7410.animstarted = 1
  if 0 > A0_7410.Properties.Animation.Speed then
    A0_7410.curAnimTime = 0
  else
    A0_7410.curAnimTime = A0_7410:GetAnimationLength(0, A0_7410.Properties.Animation.Animation)
  end
  A0_7410.startTime = CryAction.GetServerTime()
  if A0_7410.timeDiff then
    A0_7410.startTime = A0_7410.startTime - A0_7410.timeDiff
  end
end
function AnimObject.StartEntityAnimation(A0_7411)
  local L1_7412, L2_7413
  L2_7413 = A0_7411
  L1_7412 = A0_7411.StopAnimation
  L1_7412(L2_7413, 0, -1)
  L2_7413 = A0_7411
  L1_7412 = A0_7411.DoStartAnimation
  L1_7412(L2_7413)
  A0_7411.bStopAnimAfterQL = false
  L2_7413 = A0_7411
  L1_7412 = A0_7411.KillTimer
  L1_7412(L2_7413, A0_7411.POSTQL_TIMER)
  L1_7412 = A0_7411.Properties
  L1_7412 = L1_7412.Animation
  L1_7412 = L1_7412.playerAnimationState
  L2_7413 = g_localActor
  if L2_7413 and L1_7412 ~= "" then
    L2_7413 = g_localActor
    L2_7413 = L2_7413.actor
    L2_7413 = L2_7413.CreateCodeEvent
    L2_7413(L2_7413, {
      event = "animationControl",
      pos = A0_7411:GetWorldPos(),
      angle = A0_7411:GetWorldAngles()
    })
    L2_7413 = g_localActor
    L2_7413 = L2_7413.actor
    L2_7413 = L2_7413.QueueAnimationState
    L2_7413(L2_7413, L1_7412)
    L2_7413 = A0_7411.Properties
    L2_7413 = L2_7413.Animation
    L2_7413 = L2_7413.bPhysicalizeAfterAnimation
    if L2_7413 == 1 then
      L2_7413 = A0_7411.GetAnimationLength
      L2_7413 = L2_7413(A0_7411, 0, A0_7411.Properties.Animation.Animation)
      L2_7413 = L2_7413 * 1000
      L2_7413 = L2_7413 / A0_7411.Properties.Animation.Speed
      A0_7411:SetTimer(A0_7411.PHYSICALIZEAFTER_TIMER, L2_7413)
    end
  end
end
function AnimObject.Client.OnTimer(A0_7414, A1_7415, A2_7416)
  if A1_7415 == A0_7414.PHYSICALIZEAFTER_TIMER then
    A0_7414.Properties.Physics.bRigidBodyActive = 1
    A0_7414.Properties.Physics.bPhysicalize = 1
    A0_7414.Properties.Physics.bRigidBody = 1
    A0_7414.Properties.Physics.bResting = 0
    if A0_7414.bRigidBodyActive ~= A0_7414.Properties.Physics.bRigidBodyActive then
      A0_7414.bRigidBodyActive = A0_7414.Properties.Physics.bRigidBodyActive
      A0_7414:PhysicalizeThis()
    end
    if A0_7414.Properties.Physics.bRigidBody == 1 then
      A0_7414:AwakePhysics(1 - A0_7414.Properties.Physics.bResting)
      A0_7414.bRigidBodyActive = A0_7414.Properties.Physics.bRigidBodyActive
    end
  end
  if A1_7415 == A0_7414.POSTQL_TIMER and A0_7414.sequenceStatus == SEQUENCE_NOT_STARTED then
    A0_7414:StopAnimation(0, -1)
  end
end
function AnimObject.Client.OnUpdate(A0_7417, A1_7418)
  if A0_7417.bStopAnimAfterQL then
    A0_7417.bStopAnimAfterQL = false
    A0_7417:SetTimer(A0_7417.POSTQL_TIMER, 0.2)
    if A0_7417.Properties.Animation.bAlwaysUpdate ~= 1 then
      A0_7417:Activate(0)
    end
  end
end
function AnimObject.OnLoad(A0_7419, A1_7420)
  local L2_7421
  L2_7421 = A1_7420.isRagdollized
  if A0_7419.isRagdollized and not wasRagdollized then
    A0_7419:OnReset()
  end
  A0_7419.bAnimPlaying = A1_7420.bAnimPlaying
  A0_7419.bAnimLoop = A1_7420.bAnimLoop
  A0_7419.animName = A1_7420.animName
  A0_7419.animstarted = A1_7420.animstarted
  A0_7419.health = A1_7420.health
  A0_7419.dead = A1_7420.dead
  A0_7419.controllingAnimHere = A1_7420.bControllingAnimHere
  if A0_7419.controllingAnimHere then
    if A0_7419.animstarted == 1 then
      A0_7419:StartEntityAnimation()
      A0_7419:SetAnimationTime(0, 0, A1_7420.animTime)
    else
      if 0 < A1_7420.animTime then
        if A0_7419.animName ~= A0_7419.Properties.Animation.Animation then
          A0_7419:StartAnimation(0, A0_7419.animName, 0, 0, A0_7419.Properties.Animation.Speed, A0_7419.Properties.Animation.bLoop, 1)
          A0_7419:SetAnimationTime(0, 0, A1_7420.animTime)
        else
          A0_7419:StartEntityAnimation()
        end
        A0_7419:SetAnimationTime(0, 0, A1_7420.animTime)
        A0_7419.bStopAnimAfterQL = true
        A0_7419:Activate(1)
        A0_7419.curAnimTime = A1_7420.animTime
      end
      if A1_7420.animTime == 0 then
        if A1_7420.sequenceStatus == SEQUENCE_NOT_STARTED and A0_7419.sequenceStatus ~= SEQUENCE_NOT_STARTED or A0_7419.touchedByFlownode then
          A0_7419:ResetAnimation(0, -1)
          A0_7419:StartEntityAnimation()
          A0_7419:SetAnimationTime(0, 0, 0)
          A0_7419.bStopAnimAfterQL = true
          A0_7419:Activate(1)
          A0_7419.curAnimTime = 0
        end
      end
    end
  else
    A0_7419.externalAnim_anim = A1_7420.externalAnim_anim
    A0_7419.externalAnim_layer = A1_7420.externalAnim_layer
    A0_7419.externalAnim_loop = A1_7420.externalAnim_loop
    A0_7419:StartAnimation(0, A0_7419.externalAnim_anim, A0_7419.externalAnim_layer, 0, 1, A0_7419.externalAnim_loop)
    A0_7419:SetAnimationTime(0, A0_7419.externalAnim_layer, A1_7420.animTime)
  end
  A0_7419.touchedByFlownode = false
  if A0_7419.Properties.Physics.bArticulated == 0 and A0_7419.Properties.Physics.bRigidBody == 0 and A0_7419.Properties.Physics.bPhysicalize == 1 then
    A0_7419:PhysicalizeThis()
  end
  A0_7419.sequenceStatus = A1_7420.sequenceStatus
end
function AnimObject.OnSave(A0_7422, A1_7423)
  A1_7423.isRagdollized = A0_7422.isRagdollized
  A1_7423.bAnimPlaying = A0_7422.bAnimPlaying
  A1_7423.bAnimLoop = A0_7422.bAnimLoop
  A1_7423.animName = A0_7422.animName
  A1_7423.sequenceStatus = A0_7422.sequenceStatus
  A1_7423.health = A0_7422.health
  A1_7423.dead = A0_7422.dead
  A1_7423.bControllingAnimHere = A0_7422.controllingAnimHere
  if A0_7422.controllingAnimHere then
    if A0_7422.animstarted == 1 and A0_7422:IsAnimationRunning(0, 0) then
      A1_7423.animTime = A0_7422:GetAnimationTime(0, 0)
      A1_7423.animstarted = 1
    else
      A1_7423.animstarted = 0
      if A0_7422.curAnimTime then
        A1_7423.animTime = A0_7422.curAnimTime
      else
        A1_7423.animTime = 0
      end
    end
  else
    A1_7423.externalAnim_anim = A0_7422.externalAnim_anim
    A1_7423.externalAnim_layer = A0_7422.externalAnim_layer
    A1_7423.externalAnim_loop = A0_7422.externalAnim_loop
    A1_7423.animTime = A0_7422:GetAnimationTime(0, A0_7422.externalAnim_layer)
  end
end
AnimObject.FlowEvents.Inputs.ResetAnimation = {
  AnimObject.Event_ResetAnimation,
  "bool"
}
AnimObject.FlowEvents.Inputs.StartAnimation = {
  AnimObject.Event_StartAnimation,
  "bool"
}
AnimObject.FlowEvents.Inputs.StopAnimation = {
  AnimObject.Event_StopAnimation,
  "bool"
}
AnimObject.FlowEvents.Inputs.ModelLoad = {
  AnimObject.Event_ModelLoad,
  "bool"
}
AnimObject.FlowEvents.Inputs.ModelUnload = {
  AnimObject.Event_ModelUnload,
  "bool"
}
function AnimObject.Client.ClEvent_StartAnimation(A0_7424, A1_7425)
  A0_7424.timeDiff = CryAction.GetServerTime() - A1_7425
  if not CryAction.IsServer() then
    A0_7424:Event_StartAnimation()
  end
end
function AnimObject.Client.ClEvent_ResetAnimation(A0_7426)
  if not CryAction.IsServer() then
    A0_7426:Event_ResetAnimation()
  end
end
function AnimObject.SavePhysicalState(A0_7427)
  A0_7427.initPos = A0_7427:GetPos()
  A0_7427.initRot = A0_7427:GetWorldAngles()
  A0_7427.initScale = A0_7427:GetScale()
end
function AnimObject.RestorePhysicalState(A0_7428)
  A0_7428:SetPos(A0_7428.initPos)
  A0_7428:SetWorldAngles(A0_7428.initRot)
  A0_7428:SetScale(A0_7428.initScale)
  A0_7428:ResetAnimation(0, -1)
  A0_7428.animstarted = 0
  if 0 < A0_7428.Properties.Physics.Mass then
    A0_7428:OnReset()
  else
    A0_7428.animName = A0_7428.Properties.Animation.Animation
    A0_7428:StartAnimation(0, A0_7428.Properties.Animation.Animation, 0, 0, 0, false)
  end
end
function AnimObject.PhysicalizeThis(A0_7429)
  local L1_7430, L2_7431
  L1_7430 = BasicEntity
  L1_7430 = L1_7430.PhysicalizeThis
  L2_7431 = A0_7429
  L1_7430(L2_7431)
  L1_7430 = A0_7429.Properties
  L1_7430 = L1_7430.Physics
  L2_7431 = L1_7430.bBulletCollisionEnabled
  if L2_7431 == 0 then
    L2_7431 = {}
    L2_7431.flags_mask = geom_colltype_ray + geom_colltype_foliage_proxy
    L2_7431.flags = geom_colltype_player * L1_7430.bPushableByPlayers
    A0_7429:SetPhysicParams(PHYSICPARAM_PART_FLAGS, L2_7431)
  end
end
function AnimObject.SendSyncToClient(A0_7432, A1_7433)
  if A0_7432.animstarted == 1 then
    animTime = A0_7432:GetAnimationTime(0, 0)
    A0_7432.onClient:ClSync(A1_7433, animTime, A0_7432.startTime, CryAction.GetServerTime())
  end
end
function AnimObject.Server.OnPostInitClient(A0_7434, A1_7435)
  A0_7434:SendSyncToClient(A1_7435)
end
function AnimObject.Server.SVSync(A0_7436, A1_7437)
  A0_7436:SendSyncToClient(A1_7437)
end
function AnimObject.Client.ClSync(A0_7438, A1_7439, A2_7440, A3_7441)
  A0_7438:StartEntityAnimation()
  A0_7438.startTime = A2_7440
  A0_7438:SetAnimationTime(0, 0, A1_7439)
end
function AnimObject.UpdateFromServer(A0_7442)
  A0_7442.server:SVSync()
end
function AnimObject.OnSequenceStart(A0_7443)
  A0_7443.sequenceStatus = SEQUENCE_PLAYING
end
function AnimObject.OnSequenceStop(A0_7444)
  A0_7444.sequenceStatus = SEQUENCE_STOPPED
end
function AnimObject.OnSequenceAnimationStart(A0_7445, A1_7446)
  A0_7445.sequenceStatus = SEQUENCE_PLAYING
  A0_7445.animName = A1_7446
end
function AnimObject.OnSequenceAnimationStop(A0_7447)
  A0_7447.sequenceStatus = SEQUENCE_STOPPED
end
function AnimObject.OnFlowGraphAnimationStart(A0_7448, A1_7449, A2_7450, A3_7451)
  A0_7448.animName = A1_7449
  A0_7448.externalAnim_anim = A1_7449
  A0_7448.controllingAnimHere = false
  A0_7448.externalAnim_layer = A2_7450
  A0_7448.externalAnim_loop = A3_7451
  A0_7448.touchedByFlownode = true
end
function AnimObject.OnFlowGraphAnimationStop(A0_7452)
  if A0_7452.externalAnim_layer then
    A0_7452.curAnimTime = A0_7452:GetAnimationTime(0, A0_7452.externalAnim_layer)
  end
  A0_7452.controllingAnimHere = true
end
function AnimObject.OnFlowGraphAnimationEnd(A0_7453)
  local L1_7454
  A0_7453.curAnimTime = 1
  A0_7453.controllingAnimHere = true
end
