PickableAmmo = {
  type = "PickableAmmo",
  Client = {},
  Server = {},
  Properties = {
    bUsable = 1,
    bAutoPickable = 0,
    AmmoType = "Bullet",
    SoundSignal = "Player_GrabAmmo",
    UseMessage = ""
  },
  Editor = {Icon = "item.bmp", IconOnTop = 1},
  bUsed = false,
  bInitialized = false,
  fAliveTime = 0,
  bDestroyOnUse = 0
}
MakeUsable(PickableAmmo)
function PickableAmmo.Server.OnInit(A0_5733)
  if not A0_5733.bInitialized then
    A0_5733:OnReset()
    A0_5733.bInitialized = true
  end
end
function PickableAmmo.Client.OnInit(A0_5734)
  if not A0_5734.bInitialized then
    A0_5734:OnReset()
    A0_5734.bInitialized = true
  end
end
function PickableAmmo.OnReset(A0_5735, A1_5736, A2_5737)
  local L3_5738
  L3_5738 = {}
  L3_5738.bPhysicalize = 1
  L3_5738.bPushableByPlayers = 0
  L3_5738.bPushableByAI = 0
  L3_5738.Density = -1
  L3_5738.Mass = -1
  EntityCommon.PhysicalizeRigid(A0_5735, 0, L3_5738, 1)
  A0_5735.bUsed = false
end
function PickableAmmo.OnUsed(A0_5739, A1_5740, A2_5741)
  A0_5739:PickAmmo(A1_5740)
end
function PickableAmmo.IsUsable(A0_5742, A1_5743)
  bIsUsable = A0_5742.Properties.bUsable == 1 and not A0_5742.bUsed and A0_5742.Properties.bAutoPickable ~= 1
  bCanPickupAmmo = A0_5742:CanPickUpAmmo(A1_5743)
  if bIsUsable and bCanPickupAmmo then
    return 1
  else
    return 0
  end
end
function PickableAmmo.CanPickUpAmmo(A0_5744, A1_5745)
  return A1_5745.inventory:GetAmmoCapacity(A0_5744.Properties.AmmoType) > A1_5745.inventory:GetAmmoCount(A0_5744.Properties.AmmoType)
end
function PickableAmmo.OnUnhidden(A0_5746)
  CryAction.ForceGameObjectUpdate(A0_5746.id, true)
end
function PickableAmmo.PickAmmo(A0_5747, A1_5748)
  bCanPickupAmmo = A0_5747:CanPickUpAmmo(A1_5748)
  if bCanPickupAmmo then
    A1_5748.actor:PickUpPickableAmmo(A0_5747.Properties.AmmoType, 1)
    audio = GameAudio.GetSignal(A0_5747.Properties.SoundSignal)
    GameAudio.JustPlayEntitySignal(audio, A1_5748.id)
  end
  A0_5747.bUsed = true
  if A0_5747.bDestroyOnUse == 1 then
    System.RemoveEntity(A0_5747.id)
  end
  A0_5747:Activate(0)
end
