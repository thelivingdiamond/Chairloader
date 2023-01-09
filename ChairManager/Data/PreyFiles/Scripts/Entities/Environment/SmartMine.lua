local L0_5247, L1_5248, L2_5249, L3_5250
L0_5247 = {}
L0_5247.type = "SmartMine"
L1_5248 = {}
L1_5248.object_Model = "engine/engineassets/objects/default.cgf"
L1_5248.MaterialArmed = "Materials/basecolors/base_red_firebrick"
L1_5248.MaterialDisarmed = "Materials/basecolors/base_green_bright"
L2_5249 = {}
L2_5249.x = 5
L2_5249.y = 5
L2_5249.z = 3
L1_5248.vTriggerBox = L2_5249
L1_5248.fTriggerToDetonateDelay = 0.75
L1_5248.fDetonationRadius = 2.5
L1_5248.ExplosionType = "SmartMineExplosive"
L1_5248.Damage = 980
L2_5249 = {}
L2_5249.bStatic = 0
L2_5249.fJumpImpulse = 5000
L1_5248.Physics = L2_5249
L2_5249 = {}
L3_5250 = {}
L3_5250.x = 1
L3_5250.y = 0
L3_5250.z = 0
L2_5249.clrDiffuse = L3_5250
L2_5249.fDiffuseMultiplier = 1
L2_5249.fSpecularMultiplier = 1
L2_5249.fHDRDynamic = 0
L1_5248.LightArmed = L2_5249
L2_5249 = {}
L3_5250 = {}
L3_5250.x = 0
L3_5250.y = 1
L3_5250.z = 0
L2_5249.clrDiffuse = L3_5250
L2_5249.fDiffuseMultiplier = 1
L2_5249.fSpecularMultiplier = 1
L2_5249.fHDRDynamic = 0
L1_5248.LightDisarmed = L2_5249
L2_5249 = {}
L2_5249.esSmartMineType = "Cell"
L1_5248.Audio = L2_5249
L0_5247.Properties = L1_5248
L1_5248 = {}
L1_5248.Icon = "mine.bmp"
L0_5247.Editor = L1_5248
L1_5248 = {}
L0_5247.Client = L1_5248
L1_5248 = {}
L0_5247.Server = L1_5248
SmartMine = L0_5247
L0_5247 = SmartMine
function L1_5248(A0_5251)
  local L1_5252
end
L0_5247.OnPropertyChange = L1_5248
L0_5247 = SmartMine
L0_5247 = L0_5247.Server
function L1_5248(A0_5253, A1_5254)
  if A1_5254.type ~= "collision" and A1_5254.damage > 0 then
    Game.SendEventToGameObject(A0_5253.id, "detonate")
    BroadcastEvent(A0_5253, "Exploded")
    if A1_5254.shooterId then
      A0_5253.detonatedByEntity = A1_5254.shooterId
    end
  end
end
L0_5247.OnHit = L1_5248
L0_5247 = SmartMine
function L1_5248(A0_5255)
  Game.SendEventToGameObject(A0_5255.id, "enable")
end
L0_5247.Event_Enable = L1_5248
L0_5247 = SmartMine
function L1_5248(A0_5256)
  Game.SendEventToGameObject(A0_5256.id, "disable")
end
L0_5247.Event_Disable = L1_5248
L0_5247 = SmartMine
function L1_5248(A0_5257)
  BroadcastEvent(A0_5257, "Exploded")
end
L0_5247.OnExploded = L1_5248
L0_5247 = SmartMine
L1_5248 = {}
L2_5249 = {}
L3_5250 = {
  SmartMine.Event_Enable,
  "any"
}
L2_5249.Enable = L3_5250
L3_5250 = {
  SmartMine.Event_Disable,
  "any"
}
L2_5249.Disable = L3_5250
L1_5248.Inputs = L2_5249
L2_5249 = {}
L2_5249.Exploded = "bool"
L1_5248.Outputs = L2_5249
L0_5247.FlowEvents = L1_5248
