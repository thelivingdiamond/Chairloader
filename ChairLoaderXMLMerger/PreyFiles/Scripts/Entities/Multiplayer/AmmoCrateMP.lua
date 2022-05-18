AmmoCrateMP = {
  type = "AmmoCrateMP",
  Client = {},
  Server = {},
  Properties = {
    fileModelOverride = "",
    teamId = 0,
    bEnabled = 0,
    NumUsagesPerPlayer = 1,
    GroupId = "",
    audioSignal = -1,
    Ammo = {
      GiveClips = 1,
      bRefillWeaponAmmo = 0,
      FragGrenades = 0,
      bRefillWithCurrentGrenades = 1
    }
  },
  OPEN_SLOT = 0,
  Editor = {Icon = "item.bmp", IconOnTop = 1}
}
AmmoCrateMP.DEFAULT_FILE_MODEL = "engine/engineassets/objects/default.cgf"
Net.Expose({
  Class = AmmoCrateMP,
  ClientMethods = {
    ClRefillAmmoResult = {
      RELIABLE_UNORDERED,
      NO_ATTACH,
      BOOL,
      INT8
    }
  },
  ServerMethods = {
    SvRequestRefillAmmo = {
      RELIABLE_UNORDERED,
      NO_ATTACH,
      ENTITYID
    }
  },
  ServerProperties = {}
})
function AmmoCrateMP.Server.SvRequestRefillAmmo(A0_6052, A1_6053)
  local L2_6054, L3_6055, L4_6056
  L2_6054 = System
  L2_6054 = L2_6054.GetEntity
  L3_6055 = A1_6053
  L2_6054 = L2_6054(L3_6055)
  L3_6055 = 0
  L4_6056 = A0_6052.playerUsages
  L4_6056 = L4_6056[A1_6053]
  if L4_6056 == nil then
    L4_6056 = A0_6052.playerUsages
    L4_6056[A1_6053] = 0
  end
  L4_6056 = -1
  if 0 < A0_6052.Properties.NumUsagesPerPlayer then
    L4_6056 = A0_6052.Properties.NumUsagesPerPlayer - A0_6052.playerUsages[A1_6053]
  end
  if L4_6056 ~= 0 then
    if A0_6052.Properties.Ammo.GiveClips ~= 0 then
      L3_6055 = L2_6054.actor:SvGiveAmmoClips(A0_6052.Properties.Ammo.GiveClips)
    end
    if A0_6052.Properties.Ammo.bRefillWeaponAmmo ~= 0 or A0_6052.Properties.Ammo.FragGrenades ~= 0 then
      L3_6055 = L2_6054.actor:SvRefillAllAmmo("", A0_6052.Properties.Ammo.bRefillWeaponAmmo, A0_6052.Properties.Ammo.FragGrenades, A0_6052.Properties.Ammo.bRefillWithCurrentGrenades) + L3_6055
    end
    if L3_6055 ~= 0 then
      A0_6052.playerUsages[A1_6053] = A0_6052.playerUsages[A1_6053] + 1
      L4_6056 = L4_6056 - 1
    end
  end
  A0_6052.onClient:ClRefillAmmoResult(L2_6054.actor:GetChannel(), L3_6055 ~= 0, L4_6056)
end
function AmmoCrateMP.Client.ClRefillAmmoResult(A0_6057, A1_6058, A2_6059)
  g_localActor.actor:ClRefillAmmoResult(A1_6058)
  if A2_6059 == 0 then
    A0_6057.bLocalUsesLeft = false
    GameAudio.StopEntitySignal(A0_6057.audioSignal, A0_6057.id)
    BroadcastEvent(A0_6057, "NoUsesRemaining")
    if HUD then
      HUD.RemoveObjective(A0_6057.id)
    end
  end
end
MakeUsable(AmmoCrateMP)
AmmoCrateMP.Properties.bUsable = 1
AmmoCrateMP.Properties.UseMessage = "@ui_prompt_interact_ammo_cache"
function AmmoCrateMP.Server.OnInit(A0_6060)
  if not CryAction.IsClient() then
    A0_6060:OnInit()
  end
end
function AmmoCrateMP.Client.OnInit(A0_6061)
  A0_6061:OnInit()
end
function AmmoCrateMP.OnInit(A0_6062)
  local L1_6063
  L1_6063 = {}
  A0_6062.ammoRechargesModels = L1_6063
  L1_6063 = A0_6062.OnReset
  L1_6063(A0_6062)
  L1_6063 = Game
  L1_6063 = L1_6063.AddTacticalEntity
  L1_6063(A0_6062.id, eTacticalEntity_Ammo)
  L1_6063 = A0_6062.Properties
  L1_6063 = L1_6063.Ammo
  L1_6063 = L1_6063.FragGrenades
  L1_6063 = L1_6063 > 0
  Game.OnAmmoCrateSpawned(L1_6063)
end
function AmmoCrateMP.OnPropertyChange(A0_6064)
  A0_6064:OnReset()
end
function AmmoCrateMP.OnReset(A0_6065)
  A0_6065:ResetMainBoxModel()
  A0_6065.bUsable = A0_6065.Properties.bUsable
  A0_6065.audioSignal = GameAudio.GetSignal("AmmoCrate")
  A0_6065.bLocalUsesLeft = true
  A0_6065.playerUsages = {}
  A0_6065:Enabled(A0_6065.Properties.bEnabled)
  BroadcastEvent(A0_6065, "Disabled")
end
function AmmoCrateMP.ResetMainBoxModel(A0_6066)
  local L1_6067
  L1_6067 = A0_6066.DEFAULT_FILE_MODEL
  if A0_6066.Properties.fileModelOverride and A0_6066.Properties.fileModelOverride ~= "" then
    L1_6067 = A0_6066.Properties.fileModelOverride
  end
  A0_6066:LoadObject(A0_6066.OPEN_SLOT, L1_6067)
  A0_6066:Physicalize(A0_6066.OPEN_SLOT, PE_STATIC, {mass = 0, density = 0})
end
function AmmoCrateMP.OnShutDown(A0_6068)
  Game.RemoveTacticalEntity(A0_6068.id, eTacticalEntity_Ammo)
end
function AmmoCrateMP.IsUsable(A0_6069, A1_6070)
  local L2_6071
  L2_6071 = A0_6069.Properties
  L2_6071 = L2_6071.teamId
  if L2_6071 then
    L2_6071 = A0_6069.Properties
    L2_6071 = L2_6071.teamId
    L2_6071 = L2_6071 == g_gameRules.game:GetTeam(A1_6070.id)
  end
  if A0_6069.bUsable and L2_6071 and A1_6070.actor:IsLocalClient() and A0_6069.Properties.bEnabled ~= 0 and A0_6069.bLocalUsesLeft then
    return 1
  end
  return 0
end
function AmmoCrateMP.OnUsed(A0_6072, A1_6073, A2_6074)
  A0_6072.server:SvRequestRefillAmmo(A1_6073.id)
end
function AmmoCrateMP.StopUse(A0_6075, A1_6076, A2_6077)
end
function AmmoCrateMP.Enabled(A0_6078, A1_6079)
  A0_6078.Properties.bEnabled = A1_6079
  A0_6078.bLocalUsesLeft = true
  A0_6078.playerUsages = {}
  if not System.IsEditor() then
    if A1_6079 ~= 0 then
      A0_6078:Hide(0)
      BroadcastEvent(A0_6078, "Enabled")
      GameAudio.PlayEntitySignal(A0_6078.audioSignal, A0_6078.id)
    else
      A0_6078:Hide(1)
      BroadcastEvent(A0_6078, "Disabled")
      GameAudio.StopEntitySignal(A0_6078.audioSignal, A0_6078.id)
    end
  end
end
AmmoCrateMP.FlowEvents = {
  Inputs = {},
  Outputs = {
    Enabled = "bool",
    Disabled = "bool",
    NoUsesRemaining = "bool"
  }
}
