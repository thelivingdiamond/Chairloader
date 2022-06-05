HealthPack = {
  Properties = {
    soclasses_SmartObjectClass = "HealthPack",
    fileModel = "Objects/Weapons/equipment/medical_Kit/medical_kit_bag_tp.cgf",
    fUseDistance = 2.5,
    fRespawnTime = 5,
    fHealth = 20
  },
  PhysParams = {mass = 0, density = 0},
  Server = {},
  Client = {},
  Editor = {Icon = "Item.bmp", IconOnTop = 1}
}
Net.Expose({
  Class = HealthPack,
  ClientMethods = {
    ClHide = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      INT8
    }
  },
  ServerMethods = {
    SvRequestHidePack = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      INT8
    },
    SvRequestHeal = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      ENTITYID,
      FLOAT
    }
  },
  ServerProperties = {}
})
function HealthPack.Client.ClHide(A0_5544, A1_5545)
  A0_5544:Hide(A1_5545)
end
function HealthPack.Server.SvRequestHidePack(A0_5546, A1_5547)
  A0_5546:Hide(A1_5547)
  A0_5546.allClients:ClHide(A1_5547)
end
function HealthPack.Server.SvRequestHeal(A0_5548, A1_5549, A2_5550)
  System.GetEntity(A1_5549).actor:SetHealth(System.GetEntity(A1_5549).actor:GetHealth() + A0_5548.Properties.fHealth)
end
function HealthPack.OnReset(A0_5551)
  A0_5551:Reset()
end
function HealthPack.OnSpawn(A0_5552)
  CryAction.CreateGameObjectForEntity(A0_5552.id)
  CryAction.BindGameObjectToNetwork(A0_5552.id)
  CryAction.ForceGameObjectUpdate(A0_5552.id, true)
  A0_5552.isServer = CryAction.IsServer()
  A0_5552.isClient = CryAction.IsClient()
  A0_5552:Reset(1)
end
function HealthPack.OnDestroy(A0_5553)
  local L1_5554
end
function HealthPack.DoPhysicalize(A0_5555)
  if A0_5555.currModel ~= A0_5555.Properties.fileModel then
    CryAction.ActivateExtensionForGameObject(A0_5555.id, "ScriptControlledPhysics", false)
    A0_5555:LoadObject(0, A0_5555.Properties.fileModel)
    A0_5555:Physicalize(0, PE_RIGID, A0_5555.PhysParams)
    CryAction.ActivateExtensionForGameObject(A0_5555.id, "ScriptControlledPhysics", true)
  end
  A0_5555:SetPhysicParams(PHYSICPARAM_FLAGS, {flags_mask = pef_cannot_squash_players, flags = pef_cannot_squash_players})
  A0_5555.currModel = A0_5555.Properties.fileModel
end
function HealthPack.Reset(A0_5556, A1_5557)
  A0_5556:DoPhysicalize()
end
function HealthPack.UnHide(A0_5558)
  A0_5558.server:SvRequestHidePack(0)
end
function HealthPack.IsUsable(A0_5559, A1_5560)
  local L2_5561, L3_5562, L4_5563, L5_5564, L6_5565
  if not A1_5560 then
    L2_5561 = 0
    return L2_5561
  end
  L2_5561 = g_Vectors
  L2_5561 = L2_5561.temp_v1
  L4_5563 = A0_5559
  L3_5562 = A0_5559.GetWorldBBox
  L4_5563 = L3_5562(L4_5563)
  L5_5564 = FastSumVectors
  L6_5565 = L3_5562
  L5_5564(L6_5565, L3_5562, L4_5563)
  L5_5564 = ScaleVectorInPlace
  L6_5565 = L3_5562
  L5_5564(L6_5565, 0.5)
  L6_5565 = A1_5560
  L5_5564 = A1_5560.GetWorldPos
  L5_5564(L6_5565, L2_5561)
  L5_5564 = SubVectors
  L6_5565 = L2_5561
  L5_5564(L6_5565, L2_5561, L3_5562)
  L5_5564 = A0_5559.Properties
  L5_5564 = L5_5564.fUseDistance
  L6_5565 = LengthSqVector
  L6_5565 = L6_5565(L2_5561)
  if L6_5565 < L5_5564 * L5_5564 then
    L6_5565 = 1
    return L6_5565
  else
    L6_5565 = 0
    return L6_5565
  end
end
function HealthPack.GetUsableMessage(A0_5566, A1_5567)
  local L2_5568
  L2_5568 = "@use_HealthPack"
  return L2_5568
end
function HealthPack.OnUsed(A0_5569, A1_5570)
  Script.SetTimerForFunction(A0_5569.Properties.fRespawnTime * 1000, "HealthPack.UnHide", A0_5569)
  A0_5569.server:SvRequestHidePack(1)
  A0_5569.server:SvRequestHeal(A1_5570.id, 1)
end
