Script.ReloadScript("Scripts/Entities/AlienTech/AlienTech.lua")
CrashSiteLocation = new(AlienTech)
CrashSiteLocation.Properties.ControlRadius = 8
CrashSiteLocation.Properties.ControlHeight = 5
CrashSiteLocation.Properties.ControlOffsetZ = 0
CrashSiteLocation.Properties.UseFlowGraph = 0
CrashSiteLocation.Properties.DebugDraw = 0
CrashSiteLocation.Properties.radiusEffectScale = 1
CrashSiteLocation.SmokeSlot = -1
CrashSiteLocation.AlertActive = false
CrashSiteLocation.IsActive = false
CrashSiteLocation.StartPos = nil
CrashSiteLocation.Velocity = nil
CrashSiteLocation.Falling = false
CrashSiteLocation.Acceleration = nil
CrashSiteLocation.DropPos = nil
CrashSiteLocation.PreviousColour = {
  x = 0,
  y = 0,
  z = 0
}
CrashSiteLocation.TargetColour = {
  x = 0,
  y = 0,
  z = 0
}
CrashSiteLocation.ColourChangePerc = 1
CrashSiteLocation.InDeathAnim = false
CrashSiteLocation.TimeToDeath = 0
CrashSiteLocation.InFlowGraph = false
CrashSiteLocation.HasReceivedIconEvent = false
CrashSiteLocation.NumTimesLanded = 0
CrashSiteLocation.START_FALL_HEIGHT = 300
CrashSiteLocation.ICON_HEIGHT = 0.15
CrashSiteLocation.PARTICLE_EFFECT_TRAIL = "cw2_gameplay.crash_site.drop_pod_trail"
CrashSiteLocation.PARTICLE_EFFECT_CRASH = "cw2_gameplay.crash_site.drop_pod_impact"
CrashSiteLocation.PARTICLE_EFFECT_EXPLOSION = "cw2_gameplay.crash_site.drop_pod_explode"
CrashSiteLocation.PARTICLE_EFFECT_DEATH_ANIM = "cw2_gameplay.crash_site.drop_pod_explode_builup"
CrashSiteLocation.DEATH_ANIM_LENGTH = 5
CrashSiteLocation.AUDIO_START = GameAudio.GetSignal("Crashsite_Start")
CrashSiteLocation.AUDIO_LAND = GameAudio.GetSignal("Crashsite_Land")
CrashSiteLocation.AUDIO_VOLATILE = GameAudio.GetSignal("Crashsite_Volatile")
CrashSiteLocation.AUDIO_EXPLODE = GameAudio.GetSignal("Crashsite_Explode")
CrashSiteLocation.NEUTRAL_GAMESTATE_STRING = "@ui_msg_cs_status_0"
CrashSiteLocation.EXPLOSION_INFO = {
  damage = 1000,
  pressure = 2000,
  hole_size = 3,
  type = "alienDropPodBounce",
  min_radius = 2,
  max_radius = 5,
  min_phys_radius = 2.2,
  max_phys_radius = 4
}
CrashSiteLocation.EXPLOSION_INFO_2 = {
  damage = 100,
  pressure = 1000,
  hole_size = 1,
  type = "alienDropPodBounce",
  min_radius = 1,
  max_radius = 2.5,
  min_phys_radius = 1.2,
  max_phys_radius = 3
}
function CrashSiteLocation.Server.OnInit(A0_6244)
  if not A0_6244.bInitialized then
    A0_6244:OnReset()
    A0_6244.bInitialized = 1
  end
end
function CrashSiteLocation.Client.OnInit(A0_6245)
  if not A0_6245.bInitialized then
    A0_6245:OnReset()
    A0_6245.bInitialized = 1
  end
end
function CrashSiteLocation.OnReset(A0_6246)
  local L1_6247, L2_6248, L3_6249, L4_6250, L5_6251
  L2_6248 = A0_6246
  L1_6247 = A0_6246.CreateRenderProxy
  L1_6247(L2_6248)
  L2_6248 = A0_6246
  L1_6247 = A0_6246.ClearSmoke
  L1_6247(L2_6248)
  L2_6248 = A0_6246
  L1_6247 = A0_6246.PreLoadParticleEffect
  L3_6249 = A0_6246.PARTICLE_EFFECT_TRAIL
  L1_6247(L2_6248, L3_6249)
  L2_6248 = A0_6246
  L1_6247 = A0_6246.PreLoadParticleEffect
  L3_6249 = A0_6246.PARTICLE_EFFECT_CRASH
  L1_6247(L2_6248, L3_6249)
  L2_6248 = A0_6246
  L1_6247 = A0_6246.PreLoadParticleEffect
  L3_6249 = A0_6246.PARTICLE_EFFECT_EXPLOSION
  L1_6247(L2_6248, L3_6249)
  L2_6248 = A0_6246
  L1_6247 = A0_6246.PreLoadParticleEffect
  L3_6249 = A0_6246.PARTICLE_EFFECT_DEATH_ANIM
  L1_6247(L2_6248, L3_6249)
  L1_6247 = A0_6246.StartPos
  if L1_6247 == nil then
    L2_6248 = A0_6246
    L1_6247 = A0_6246.GetPos
    L1_6247 = L1_6247(L2_6248)
    A0_6246.StartPos = L1_6247
    L2_6248 = A0_6246
    L1_6247 = A0_6246.GetAngles
    L1_6247 = L1_6247(L2_6248)
    L2_6248 = {}
    L2_6248.x = 0
    L2_6248.y = 0
    L2_6248.z = -9.81
    A0_6246.Acceleration = L2_6248
    L2_6248 = RotateVectorAroundR
    L3_6249 = A0_6246.Acceleration
    L4_6250 = A0_6246.Acceleration
    L5_6251 = g_Vectors
    L5_6251 = L5_6251.v100
    L2_6248(L3_6249, L4_6250, L5_6251, L1_6247.x)
    L2_6248 = RotateVectorAroundR
    L3_6249 = A0_6246.Acceleration
    L4_6250 = A0_6246.Acceleration
    L5_6251 = g_Vectors
    L5_6251 = L5_6251.v010
    L2_6248(L3_6249, L4_6250, L5_6251, L1_6247.y)
    L2_6248 = RotateVectorAroundR
    L3_6249 = A0_6246.Acceleration
    L4_6250 = A0_6246.Acceleration
    L5_6251 = g_Vectors
    L5_6251 = L5_6251.v001
    L2_6248(L3_6249, L4_6250, L5_6251, L1_6247.z)
    L2_6248 = A0_6246.Acceleration
    L2_6248 = L2_6248.z
    if L2_6248 > 0 then
      L2_6248 = A0_6246.Acceleration
      L3_6249 = A0_6246.Acceleration
      L3_6249 = L3_6249.x
      L3_6249 = -L3_6249
      L2_6248.x = L3_6249
      L2_6248 = A0_6246.Acceleration
      L3_6249 = A0_6246.Acceleration
      L3_6249 = L3_6249.y
      L3_6249 = -L3_6249
      L2_6248.y = L3_6249
      L2_6248 = A0_6246.Acceleration
      L3_6249 = A0_6246.Acceleration
      L3_6249 = L3_6249.z
      L3_6249 = -L3_6249
      L2_6248.z = L3_6249
    end
    L2_6248 = {}
    L3_6249 = CopyVector
    L4_6250 = L2_6248
    L5_6251 = A0_6246.Acceleration
    L3_6249(L4_6250, L5_6251)
    L3_6249 = NormalizeVector
    L4_6250 = L2_6248
    L3_6249(L4_6250)
    L3_6249 = ScaleVector
    L4_6250 = L2_6248
    L5_6251 = A0_6246.START_FALL_HEIGHT
    L5_6251 = -L5_6251
    L3_6249 = L3_6249(L4_6250, L5_6251)
    A0_6246.DropPos = L3_6249
    L3_6249 = FastSumVectors
    L4_6250 = A0_6246.DropPos
    L5_6251 = A0_6246.DropPos
    L3_6249(L4_6250, L5_6251, A0_6246.StartPos)
  end
  L1_6247 = A0_6246.IsActive
  if not L1_6247 then
    L1_6247 = System
    L1_6247 = L1_6247.IsEditor
    L1_6247 = L1_6247()
  elseif L1_6247 then
    L2_6248 = A0_6246
    L1_6247 = A0_6246.ActivateCapturePoint
    L3_6249 = false
    L1_6247(L2_6248, L3_6249)
  end
  L1_6247 = A0_6246.Properties
  L1_6247 = L1_6247.ControlRadius
  L2_6248 = A0_6246.Properties
  L2_6248 = L2_6248.ControlOffsetZ
  L3_6249 = A0_6246.Properties
  L3_6249 = L3_6249.ControlHeight
  L4_6250 = {}
  L5_6251 = -L1_6247
  L4_6250.x = L5_6251
  L5_6251 = -L1_6247
  L4_6250.y = L5_6251
  L4_6250.z = L2_6248
  L5_6251 = {}
  L5_6251.x = L1_6247
  L5_6251.y = L1_6247
  L5_6251.z = L3_6249 + L2_6248
  A0_6246:SetTriggerBBox(L4_6250, L5_6251)
  if System.IsEditor() then
    if A0_6246.Properties.DebugDraw ~= 0 then
      A0_6246:Activate(1)
    else
      A0_6246:Activate(0)
    end
  else
    A0_6246:Hide(1)
  end
end
function CrashSiteLocation.OnPropertyChange(A0_6252)
  A0_6252:OnReset()
end
function CrashSiteLocation.ShouldShowHudIcon(A0_6253)
  local L1_6254, L2_6255
  L1_6254 = A0_6253.Falling
  if L1_6254 then
    L1_6254 = A0_6253.StartPos
    L1_6254 = L1_6254.z
    L2_6255 = A0_6253.DropPos
    L2_6255 = L2_6255.z
    if (A0_6253:GetPos().z - L1_6254) / (L2_6255 - L1_6254) > CrashSiteLocation.ICON_HEIGHT then
      return false
    end
  else
    L1_6254 = A0_6253.InFlowGraph
    if L1_6254 == true then
      L1_6254 = A0_6253.HasReceivedIconEvent
      return L1_6254
    end
  end
  L1_6254 = true
  return L1_6254
end
function CrashSiteLocation.ShouldDoPulseEffect(A0_6256)
  local L1_6257
  L1_6257 = A0_6256.Falling
  if not L1_6257 then
    L1_6257 = A0_6256.InFlowGraph
  else
    if L1_6257 then
      L1_6257 = false
      return L1_6257
  end
  else
    L1_6257 = true
    return L1_6257
  end
end
function CrashSiteLocation.Update(A0_6258, A1_6259)
  local L2_6260, L3_6261
  L2_6260 = A0_6258.Falling
  if L2_6260 then
    L2_6260 = ScaleVector
    L3_6261 = A0_6258.Acceleration
    L2_6260 = L2_6260(L3_6261, A1_6259)
    L3_6261 = FastSumVectors
    L3_6261(A0_6258.Velocity, A0_6258.Velocity, L2_6260)
    L3_6261 = A0_6258.GetPos
    L3_6261 = L3_6261(A0_6258)
    FastSumVectors(L3_6261, L3_6261, ScaleVector(A0_6258.Velocity, A1_6259))
    if L3_6261.z < A0_6258.StartPos.z then
      L3_6261 = A0_6258.StartPos
      A0_6258.Falling = false
      A0_6258:Event_Landed()
    end
    A0_6258:SetPos(L3_6261)
  else
    L2_6260 = A0_6258.InDeathAnim
    if L2_6260 == true then
      L2_6260 = A0_6258.TimeToDeath
      L2_6260 = L2_6260 - A1_6259
      A0_6258.TimeToDeath = L2_6260
      L2_6260 = A0_6258.TimeToDeath
      if L2_6260 < 0 then
        L3_6261 = A0_6258
        L2_6260 = A0_6258.OnFinished
        L2_6260(L3_6261, true)
        A0_6258.InDeathAnim = false
        L2_6260 = BroadcastEvent
        L3_6261 = A0_6258
        L2_6260(L3_6261, "DeActivated")
      end
    end
  end
  L2_6260 = A0_6258.ColourChangePerc
  if L2_6260 < 1 then
    L2_6260 = A0_6258.ColourChangePerc
    L2_6260 = L2_6260 + A1_6259
    A0_6258.ColourChangePerc = L2_6260
    L2_6260 = A0_6258.ColourChangePerc
    if L2_6260 > 1 then
      A0_6258.ColourChangePerc = 1
    end
    L2_6260 = A0_6258.ColourChangePerc
    L2_6260 = 1 - L2_6260
    L3_6261 = {}
    L3_6261.x = A0_6258.PreviousColour.x * L2_6260 + A0_6258.TargetColour.x * A0_6258.ColourChangePerc
    L3_6261.y = A0_6258.PreviousColour.y * L2_6260 + A0_6258.TargetColour.y * A0_6258.ColourChangePerc
    L3_6261.z = A0_6258.PreviousColour.z * L2_6260 + A0_6258.TargetColour.z * A0_6258.ColourChangePerc
    A0_6258:SetMaterialVec3(0, 1, MaterialVec3Params.diffuse_color, L3_6261)
  end
  L2_6260 = A0_6258.InFlowGraph
  if L2_6260 == true then
    L2_6260 = A0_6258.SmokeSlot
    if L2_6260 == -1 then
      L3_6261 = A0_6258
      L2_6260 = A0_6258.IsHidden
      L2_6260 = L2_6260(L3_6261)
      if L2_6260 == false then
        L3_6261 = A0_6258
        L2_6260 = A0_6258.StartSmoke
        L2_6260(L3_6261)
      end
    end
  end
end
function CrashSiteLocation.Server.OnUpdate(A0_6262, A1_6263)
  local L2_6264, L3_6265, L4_6266
  L2_6264 = A0_6262.Properties
  L2_6264 = L2_6264.DebugDraw
  if L2_6264 ~= 0 then
    L3_6265 = A0_6262
    L2_6264 = A0_6262.GetWorldPos
    L2_6264 = L2_6264(L3_6265)
    L3_6265 = A0_6262.Properties
    L3_6265 = L3_6265.ControlRadius
    L4_6266 = A0_6262.Properties
    L4_6266 = L4_6266.ControlHeight
    L2_6264.z = L2_6264.z + L4_6266 * 0.5 + A0_6262.Properties.ControlOffsetZ
    Game.DebugDrawCylinder(L2_6264.x, L2_6264.y, L2_6264.z, L3_6265, L4_6266, 60, 60, 255, 100)
  end
end
function CrashSiteLocation.ActivateCapturePoint(A0_6267, A1_6268)
  if A0_6267.InDeathAnim == true or A0_6267.IsActive == true then
    A0_6267.InDeathAnim = false
    BroadcastEvent(A0_6267, "DeActivated")
  end
  A0_6267.IsActive = true
  A0_6267:SetFlags(ENTITY_FLAG_ON_RADAR, 0)
  if A1_6268 then
    if A0_6267.Properties.UseFlowGraph == 0 then
      A0_6267.Velocity = {
        x = 0,
        y = 0,
        z = 0
      }
      A0_6267:SetPos(A0_6267.DropPos)
      A0_6267.Falling = true
      A0_6267:StartSmoke()
      A0_6267:Hide(0)
    else
      BroadcastEvent(A0_6267, "Activated")
      A0_6267.InFlowGraph = true
      A0_6267.HasReceivedIconEvent = false
    end
  else
    A0_6267:SetPos(A0_6267.StartPos)
    A0_6267:DoLandingFlowgraphEvent()
  end
  A0_6267:SetViewDistRatio(255)
  A0_6267:SetTargetColour(g_gameRules.game:GetTeam(A0_6267.id))
  if CryAction.IsServer() then
    g_gameRules.game:ResetAlienTech(A0_6267.id)
  end
end
function CrashSiteLocation.StartSmoke(A0_6269)
  A0_6269.SmokeSlot = A0_6269:LoadParticleEffect(A0_6269.SmokeSlot, A0_6269.PARTICLE_EFFECT_TRAIL, {})
  GameAudio.PlayEntitySignal(A0_6269.AUDIO_START, A0_6269.id)
end
function CrashSiteLocation.IsAlertActive(A0_6270)
  if A0_6270.AlertActive then
    return 1
  else
    return 0
  end
end
function CrashSiteLocation.DeactivateCapturePoint(A0_6271, A1_6272)
  local L2_6273, L3_6274
  A0_6271.IsActive = false
  L3_6274 = A0_6271
  L2_6273 = A0_6271.SetFlags
  L2_6273(L3_6274, ENTITY_FLAG_ON_RADAR, 2)
  L2_6273 = A0_6271.Falling
  if L2_6273 then
    A0_6271.Falling = false
    A0_6271.TimeToDeath = 0
  end
  if A1_6272 then
    L2_6273 = A0_6271.Falling
    if L2_6273 then
      A0_6271.Falling = false
      A0_6271.TimeToDeath = 0
    else
      L3_6274 = A0_6271
      L2_6273 = A0_6271.LoadParticleEffect
      L2_6273 = L2_6273(L3_6274, A0_6271.SmokeSlot, A0_6271.PARTICLE_EFFECT_DEATH_ANIM, {})
      A0_6271.SmokeSlot = L2_6273
      A0_6271.InDeathAnim = true
      L2_6273 = A0_6271.DEATH_ANIM_LENGTH
      A0_6271.TimeToDeath = L2_6273
      L2_6273 = GameAudio
      L2_6273 = L2_6273.PlayEntitySignal
      L3_6274 = A0_6271.AUDIO_VOLATILE
      L2_6273(L3_6274, A0_6271.id)
      L3_6274 = A0_6271
      L2_6273 = A0_6271.GetChildCount
      L2_6273 = L2_6273(L3_6274)
      L3_6274 = 0
      while L2_6273 > L3_6274 do
        if A0_6271:GetChild(L3_6274) ~= nil and A0_6271:GetChild(L3_6274).bCurrentlyPickable == 1 then
          A0_6271:GetChild(L3_6274).bCurrentlyPickable = 0
        end
        L3_6274 = L3_6274 + 1
      end
    end
  else
    L3_6274 = A0_6271
    L2_6273 = A0_6271.OnFinished
    L2_6273(L3_6274, A1_6272)
    L2_6273 = BroadcastEvent
    L3_6274 = A0_6271
    L2_6273(L3_6274, "DeActivated")
  end
end
function CrashSiteLocation.OnFinished(A0_6275, A1_6276)
  local L2_6277, L3_6278, L4_6279, L5_6280, L6_6281
  L2_6277 = {}
  L3_6278 = pef_always_notify_on_deletion
  L2_6277.flags_mask = L3_6278
  L3_6278 = pef_always_notify_on_deletion
  L2_6277.flags = L3_6278
  L4_6279 = A0_6275
  L3_6278 = A0_6275.SetPhysicParams
  L5_6280 = PHYSICPARAM_FLAGS
  L6_6281 = L2_6277
  L3_6278(L4_6279, L5_6280, L6_6281)
  A0_6275.AlertActive = false
  L4_6279 = A0_6275
  L3_6278 = A0_6275.ClearSmoke
  L3_6278(L4_6279)
  L4_6279 = A0_6275
  L3_6278 = A0_6275.Hide
  L5_6280 = 1
  L3_6278(L4_6279, L5_6280)
  if A1_6276 then
    L3_6278 = A0_6275.Falling
    if not L3_6278 then
      L3_6278 = Particle
      L3_6278 = L3_6278.SpawnEffect
      L4_6279 = A0_6275.PARTICLE_EFFECT_EXPLOSION
      L6_6281 = A0_6275
      L5_6280 = A0_6275.GetPos
      L5_6280 = L5_6280(L6_6281)
      L6_6281 = g_Vectors
      L6_6281 = L6_6281.v000
      L3_6278(L4_6279, L5_6280, L6_6281)
      L3_6278 = GameAudio
      L3_6278 = L3_6278.PlayEntitySignal
      L4_6279 = A0_6275.AUDIO_EXPLODE
      L5_6280 = A0_6275.id
      L3_6278(L4_6279, L5_6280)
    end
  end
  L3_6278 = g_gameRules
  if L3_6278 then
    L3_6278 = CryAction
    L3_6278 = L3_6278.IsServer
    L3_6278 = L3_6278()
    if L3_6278 then
      L4_6279 = A0_6275
      L3_6278 = A0_6275.GetPos
      L3_6278 = L3_6278(L4_6279)
      L4_6279 = L3_6278.z
      L4_6279 = L4_6279 + 1.5
      L3_6278.z = L4_6279
      L4_6279 = {}
      L4_6279.x = 0
      L4_6279.y = 0
      L4_6279.z = 1
      L5_6280 = A0_6275.EXPLOSION_INFO_2
      L6_6281 = g_gameRules
      L6_6281 = L6_6281.game
      L6_6281 = L6_6281.GetHitTypeId
      L6_6281 = L6_6281(L6_6281, L5_6280.type)
      g_gameRules.game:ServerExplosion(NULL_ENTITY, A0_6275.id, L5_6280.damage, L3_6278, L4_6279, L5_6280.max_radius, 0, L5_6280.pressure, L5_6280.hole_size, "", 0, L6_6281, L5_6280.min_radius, L5_6280.min_phys_radius, L5_6280.max_phys_radius)
    end
  end
end
function CrashSiteLocation.ClearSmoke(A0_6282)
  if A0_6282.SmokeSlot ~= -1 then
    A0_6282:DeleteParticleEmitter(A0_6282.SmokeSlot)
    A0_6282:FreeSlot(A0_6282.SmokeSlot)
    A0_6282.SmokeSlot = -1
  end
end
function CrashSiteLocation.OnSetTeam(A0_6283, A1_6284)
  A0_6283:SetTargetColour(A1_6284)
end
function CrashSiteLocation.LocalPlayerChangedTeam(A0_6285)
  local L1_6286, L2_6287
  L2_6287 = A0_6285
  L1_6286 = A0_6285.SetTargetColour
  L1_6286(L2_6287, g_gameRules.game:GetTeam(A0_6285.id))
end
function CrashSiteLocation.SetTargetColour(A0_6288, A1_6289)
  local L2_6290
  L2_6290 = -1
  if g_localActorId then
    L2_6290 = g_gameRules.game:GetTeam(g_localActorId)
  end
  CopyVector(A0_6288.PreviousColour, A0_6288.TargetColour)
  if A1_6289 == 0 then
    A0_6288.TargetColour.x = 0.3019
    A0_6288.TargetColour.y = 0.3019
    A0_6288.TargetColour.z = 0.3019
  elseif A1_6289 == L2_6290 then
    A0_6288.TargetColour.x = 0.0784
    A0_6288.TargetColour.y = 0.2588
    A0_6288.TargetColour.z = 0.6784
  else
    A0_6288.TargetColour.x = 0.7019
    A0_6288.TargetColour.y = 0.0705
    A0_6288.TargetColour.z = 0
  end
  A0_6288.ColourChangePerc = 0
end
function CrashSiteLocation.Event_Landed(A0_6291)
  local L1_6292, L2_6293, L3_6294, L4_6295
  L1_6292 = GameAudio
  L1_6292 = L1_6292.PlayEntitySignal
  L2_6293 = A0_6291.AUDIO_LAND
  L3_6294 = A0_6291.id
  L1_6292(L2_6293, L3_6294)
  L1_6292 = GameAudio
  L1_6292 = L1_6292.Announce
  L2_6293 = "Landed"
  L3_6294 = 0
  L1_6292(L2_6293, L3_6294)
  L1_6292 = Particle
  L1_6292 = L1_6292.SpawnEffect
  L2_6293 = A0_6291.PARTICLE_EFFECT_CRASH
  L4_6295 = A0_6291
  L3_6294 = A0_6291.GetPos
  L3_6294 = L3_6294(L4_6295)
  L4_6295 = g_Vectors
  L4_6295 = L4_6295.v000
  L1_6292(L2_6293, L3_6294, L4_6295)
  L1_6292 = A0_6291.SmokeSlot
  if L1_6292 ~= -1 then
    L2_6293 = A0_6291
    L1_6292 = A0_6291.DeleteParticleEmitter
    L3_6294 = A0_6291.SmokeSlot
    L1_6292(L2_6293, L3_6294)
    L2_6293 = A0_6291
    L1_6292 = A0_6291.FreeSlot
    L3_6294 = A0_6291.SmokeSlot
    L1_6292(L2_6293, L3_6294)
    A0_6291.SmokeSlot = -1
  end
  A0_6291.InFlowGraph = false
  L1_6292 = g_gameRules
  if L1_6292 then
    L1_6292 = CryAction
    L1_6292 = L1_6292.IsServer
    L1_6292 = L1_6292()
    if L1_6292 then
      L2_6293 = A0_6291
      L1_6292 = A0_6291.GetPos
      L1_6292 = L1_6292(L2_6293)
      L2_6293 = L1_6292.z
      L2_6293 = L2_6293 + 1.5
      L1_6292.z = L2_6293
      L2_6293 = {}
      L2_6293.x = 0
      L2_6293.y = 0
      L2_6293.z = 1
      L3_6294 = A0_6291.EXPLOSION_INFO
      L4_6295 = g_gameRules
      L4_6295 = L4_6295.game
      L4_6295 = L4_6295.GetHitTypeId
      L4_6295 = L4_6295(L4_6295, L3_6294.type)
      g_gameRules.game:ServerExplosion(NULL_ENTITY, A0_6291.id, L3_6294.damage, L1_6292, L2_6293, L3_6294.max_radius, 0, L3_6294.pressure, L3_6294.hole_size, "", 0, L4_6295, L3_6294.min_radius, L3_6294.min_phys_radius, L3_6294.max_phys_radius)
    end
  end
  L2_6293 = A0_6291
  L1_6292 = A0_6291.DoLandingFlowgraphEvent
  L1_6292(L2_6293)
end
function CrashSiteLocation.Event_Show(A0_6296)
  A0_6296:Hide(0)
end
function CrashSiteLocation.DoLandingFlowgraphEvent(A0_6297)
  if A0_6297.NumTimesLanded == 0 then
    BroadcastEvent(A0_6297, "OnFirstLanding")
  else
    BroadcastEvent(A0_6297, "OnRepeatLanding")
  end
  BroadcastEvent(A0_6297, "OnAnyLanding")
  A0_6297.NumTimesLanded = A0_6297.NumTimesLanded + 1
  if g_gameRules.game:GetTeam(A0_6297.id) == 0 then
    HUD.OnGameStatusUpdate(0, A0_6297.NEUTRAL_GAMESTATE_STRING)
  end
end
function CrashSiteLocation.Event_ShowIcon(A0_6298)
  local L1_6299
  A0_6298.HasReceivedIconEvent = true
end
function CrashSiteLocation.TestFlowGraph(A0_6300)
  A0_6300:ActivateCapturePoint(true)
end
function CrashSiteLocation.TestPulseEffect(A0_6301)
  Particle.SpawnEffect("cw2_gameplay.crash_site.drop_pod_capture_area", A0_6301:GetPos(), {
    x = 0,
    y = 0,
    z = 1
  }, A0_6301.Properties.radiusEffectScale)
end
CrashSiteLocation.FlowEvents = {
  Inputs = {
    Landed = {
      CrashSiteLocation.Event_Landed,
      "any"
    },
    ShowIcon = {
      CrashSiteLocation.Event_ShowIcon,
      "any"
    },
    Show = {
      CrashSiteLocation.Event_Show,
      "any"
    }
  },
  Outputs = {
    Activated = "bool",
    OnFirstLanding = "bool",
    OnRepeatLanding = "bool",
    OnAnyLanding = "bool",
    DeActivated = "bool"
  }
}
