AmmoCrate = {
  type = "AmmoCrate",
  Properties = {
    object_BoxModel = "engine/engineassets/objects/default.cgf",
    object_Ammo4Recharges = "engine/engineassets/objects/default.cgf",
    object_Ammo3Recharges = "engine/engineassets/objects/default.cgf",
    object_Ammo2Recharges = "engine/engineassets/objects/default.cgf",
    object_Ammo1Recharges = "engine/engineassets/objects/default.cgf",
    object_Ammo0Recharges = "engine/engineassets/objects/default.cgf",
    numberOfRecharges = 0,
    Ammo = {AmmoCategory = "Regular", FragGrenades = 2}
  },
  Editor = {Icon = "item.bmp", IconOnTop = 1}
}
function AmmoCrate.OnInit(A0_5511)
  local L1_5512
  L1_5512 = {}
  A0_5511.ammoRechargesModels = L1_5512
  L1_5512 = A0_5511.OnReset
  L1_5512(A0_5511)
  L1_5512 = Game
  L1_5512 = L1_5512.AddTacticalEntity
  L1_5512(A0_5511.id, eTacticalEntity_Ammo)
  L1_5512 = A0_5511.Properties
  L1_5512 = L1_5512.Ammo
  L1_5512 = L1_5512.FragGrenades
  L1_5512 = L1_5512 > 0
  Game.OnAmmoCrateSpawned(L1_5512)
end
function AmmoCrate.OnPropertyChange(A0_5513)
  A0_5513:OnReset()
end
function AmmoCrate.OnReset(A0_5514)
  A0_5514:ResetMainBoxModel()
  A0_5514:ResetAmmoAttachmentModels()
  A0_5514.remaingRecharges = math.min(4, math.max(0, A0_5514.Properties.numberOfRecharges))
  A0_5514.infiniteRecharges = A0_5514.remaingRecharges == 0
  A0_5514.bUsable = A0_5514.Properties.bUsable
  A0_5514:SetUpAmmoAttachmentsVisibility()
end
function AmmoCrate.ResetMainBoxModel(A0_5515)
  if A0_5515.currentModel ~= A0_5515.Properties.object_BoxModel and not EmptyString(A0_5515.Properties.object_BoxModel) then
    A0_5515:LoadObject(0, A0_5515.Properties.object_BoxModel)
    A0_5515:Physicalize(0, PE_STATIC, {mass = 0, density = 0})
  end
  A0_5515.currentModel = A0_5515.Properties.object_BoxModel
end
function AmmoCrate.ResetAmmoAttachmentModels(A0_5516)
  if A0_5516.ammoRechargesModels[1] ~= A0_5516.Properties.object_Ammo0Recharges and not EmptyString(A0_5516.Properties.object_Ammo0Recharges) then
    A0_5516:LoadObject(1, A0_5516.Properties.object_Ammo0Recharges)
  end
  A0_5516:DrawSlot(1, 0)
  A0_5516.ammoRechargesModels[1] = A0_5516.Properties.object_Ammo0Recharges
  if A0_5516.ammoRechargesModels[2] ~= A0_5516.Properties.object_Ammo1Recharges and not EmptyString(A0_5516.Properties.object_Ammo1Recharges) then
    A0_5516:LoadObject(2, A0_5516.Properties.object_Ammo1Recharges)
  end
  A0_5516:DrawSlot(2, 0)
  A0_5516.ammoRechargesModels[2] = A0_5516.Properties.object_Ammo1Recharges
  if A0_5516.ammoRechargesModels[3] ~= A0_5516.Properties.object_Ammo2Recharges and not EmptyString(A0_5516.Properties.object_Ammo2Recharges) then
    A0_5516:LoadObject(3, A0_5516.Properties.object_Ammo2Recharges)
  end
  A0_5516:DrawSlot(3, 0)
  A0_5516.ammoRechargesModels[3] = A0_5516.Properties.object_Ammo2Recharges
  if A0_5516.ammoRechargesModels[4] ~= A0_5516.Properties.object_Ammo3Recharges and not EmptyString(A0_5516.Properties.object_Ammo3Recharges) then
    A0_5516:LoadObject(4, A0_5516.Properties.object_Ammo3Recharges)
  end
  A0_5516:DrawSlot(4, 0)
  A0_5516.ammoRechargesModels[4] = A0_5516.Properties.object_Ammo3Recharges
  if A0_5516.ammoRechargesModels[5] ~= A0_5516.Properties.object_Ammo4Recharges and not EmptyString(A0_5516.Properties.object_Ammo4Recharges) then
    A0_5516:LoadObject(5, A0_5516.Properties.object_Ammo4Recharges)
  end
  A0_5516:DrawSlot(5, 0)
  A0_5516.ammoRechargesModels[5] = A0_5516.Properties.object_Ammo4Recharges
end
function AmmoCrate.SetUpAmmoAttachmentsVisibility(A0_5517)
  if A0_5517.infiniteRecharges then
    A0_5517:DrawSlot(5, 1)
  else
    A0_5517:DrawSlot(A0_5517.remaingRecharges + 1, 1)
  end
end
function AmmoCrate.OnSave(A0_5518, A1_5519)
  local L2_5520
  L2_5520 = A0_5518.bUsable
  A1_5519.bUsable = L2_5520
  L2_5520 = A0_5518.infiniteRecharges
  A1_5519.infiniteRecharges = L2_5520
  L2_5520 = A0_5518.remaingRecharges
  A1_5519.remaingRecharges = L2_5520
end
function AmmoCrate.OnLoad(A0_5521, A1_5522)
  A0_5521.bUsable = A1_5522.bUsable
  A0_5521.infiniteRecharges = A1_5522.infiniteRecharges
  A0_5521.remaingRecharges = A1_5522.remaingRecharges
  A0_5521:ResetAmmoAttachmentModels()
  A0_5521:SetUpAmmoAttachmentsVisibility()
end
function AmmoCrate.OnShutDown(A0_5523)
  Game.RemoveTacticalEntity(A0_5523.id, eTacticalEntity_Ammo)
end
function AmmoCrate.HasRecharges(A0_5524)
  local L1_5525
  L1_5525 = A0_5524.infiniteRecharges
  if not L1_5525 then
    L1_5525 = A0_5524.remaingRecharges
    L1_5525 = L1_5525 > 0
  end
  return L1_5525
end
function AmmoCrate.DecreaseRecharges(A0_5526)
  if not A0_5526.infiniteRecharges then
    A0_5526:DrawSlot(A0_5526.remaingRecharges + 1, 0)
    A0_5526.remaingRecharges = A0_5526.remaingRecharges - 1
    A0_5526:DrawSlot(A0_5526.remaingRecharges + 1, 1)
    if not A0_5526:HasRecharges() then
      Game.RemoveTacticalEntity(A0_5526.id, eTacticalEntity_Ammo)
    end
  end
end
function AmmoCrate.Event_Hide(A0_5527)
  Game.RemoveTacticalEntity(A0_5527.id, eTacticalEntity_Ammo)
  A0_5527:Hide(1)
  A0_5527:ActivateOutput("Hide", true)
end
function AmmoCrate.Event_UnHide(A0_5528)
  A0_5528:Hide(0)
  A0_5528:ActivateOutput("UnHide", true)
  Game.AddTacticalEntity(A0_5528.id, eTacticalEntity_Ammo)
end
MakeUsable(AmmoCrate)
AmmoCrate.FlowEvents = {
  Inputs = {
    Hide = {
      AmmoCrate.Event_Hide,
      "bool"
    },
    UnHide = {
      AmmoCrate.Event_UnHide,
      "bool"
    },
    Used = {
      AmmoCrate.Event_Used,
      "bool"
    },
    EnableUsable = {
      AmmoCrate.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      AmmoCrate.Event_DisableUsable,
      "bool"
    }
  },
  Outputs = {
    Hide = "bool",
    UnHide = "bool",
    Used = "bool",
    EnableUsable = "bool",
    DisableUsable = "bool"
  }
}
function AmmoCrate.StopUse(A0_5529, A1_5530, A2_5531)
end
function AmmoCrate.OnUsed(A0_5532, A1_5533, A2_5534)
  local L3_5535
  L3_5535 = A1_5533.actor
  L3_5535 = L3_5535.SvRefillAllAmmo
  L3_5535 = L3_5535(L3_5535, A0_5532.Properties.Ammo.AmmoCategory, false, A0_5532.Properties.Ammo.FragGrenades, false)
  if L3_5535 ~= 0 then
    A0_5532:DecreaseRecharges()
  end
  A1_5533.actor:ClRefillAmmoResult(L3_5535)
  A0_5532:ActivateOutput("Used", true)
end
function AmmoCrate.IsUsable(A0_5536, A1_5537)
  if A0_5536.bUsable and A1_5537.actor:IsLocalClient() and not A1_5537.actor:IsCurrentItemHeavy() and A0_5536:HasRecharges() then
    return 1
  end
  return 0
end
