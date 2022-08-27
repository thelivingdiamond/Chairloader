Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkAnimSlave = {
  Properties = {
    object_Model = "",
    bDisallowGrenades = true,
    Animation = {anim_SlaveAnim = ""},
    Physics = {
      bPhysicalize = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    IconOnTop = true,
    Icon = "switch.bmp",
    ShowBounds = 0,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkAnimSlave)
ArkMakeSaveable(ArkAnimSlave)
SetupCollisionFiltering(ArkAnimSlave)
ArkAnimSlaveInstanceVars = {
  m_bInit = false,
  m_bVerbose = false,
  m_lastUpdatedTime = 0,
  m_referenceTable = false
}
function CreateArkAnimSlave(A0_3437)
  mergef(A0_3437, ArkAnimSlaveInstanceVars, 1)
  A0_3437.m_referenceTable = ArkAnimSlaveInstanceVars
end
function ArkAnimSlave.Init(A0_3438)
  if not A0_3438.m_bInit then
    A0_3438.m_bInit = true
    A0_3438:StartAnimation(0, A0_3438.Properties.Animation.anim_SlaveAnim, 0, 0, 0)
  end
end
function ArkAnimSlave.SetFromProperties(A0_3439)
  A0_3439:SetupModelAndPhysics()
end
function ArkAnimSlave.OnPostLoad(A0_3440)
  A0_3440:SetAnimationTime(0, 0, A0_3440.m_lastUpdatedTime)
end
function ArkAnimSlave.OnPropertyChange(A0_3441)
  A0_3441:Log("OnPropertyChange")
  A0_3441:SetFromProperties()
  A0_3441:Init()
end
function ArkAnimSlave.OnReset(A0_3442)
  A0_3442.m_bInit = false
  A0_3442:SetFromProperties()
  A0_3442:Init()
  A0_3442:Log("OnReset")
end
function ArkAnimSlave.OnSpawn(A0_3443)
  CreateArkAnimSlave(A0_3443)
  A0_3443:SetFromProperties()
  A0_3443:Init()
  A0_3443:Log("OnSpawn")
end
function ArkAnimSlave.Event_SetAnimationTime(A0_3444, A1_3445, A2_3446)
  Ark.HandleGooOverlappingEntity(A0_3444.id, true)
  A0_3444:SetAnimationTime(0, 0, A2_3446)
  A0_3444.m_lastUpdatedTime = A2_3446
end
ArkAnimSlave.FlowEvents = {
  Inputs = {
    SetAnimationTime = {
      ArkAnimSlave.Event_SetAnimationTime,
      "float"
    }
  },
  Outputs = {}
}
