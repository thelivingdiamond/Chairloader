Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkBook = {
  Properties = {
    object_Model = "",
    textDisplayText = "@i_defaultBook",
    glintconfig_GlintConfig = "16934642289625103724",
    note_OnRead = "",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bResting = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = 100,
      Mass = -1
    },
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    }
  },
  Editor = {
    Icon = "Seed.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    note_OnRead = "",
    bVerbose = 0,
    bUsable = 1
  }
}
GetArkEntityUtils(ArkBook)
SetupCollisionFiltering(ArkBook)
function ArkBook.Init(A0_3487, A1_3488)
  A0_3487:Log("Init()")
  A0_3487:Log("ArkBook:Init")
  Ark.SetGlintConfig(A0_3487.id, A0_3487.Properties.glintconfig_GlintConfig)
  A0_3487:SetFromProperties()
  A0_3487:SetupBook()
  if A1_3488 then
    Ark.SetShouldGlint(A0_3487.id, true)
  end
end
function ArkBook.SetupBook(A0_3489)
  local L1_3490
  L1_3490 = A0_3489.PropertiesInstance
  L1_3490 = L1_3490.note_OnRead
  if L1_3490 ~= "" then
    L1_3490 = A0_3489.PropertiesInstance
    L1_3490 = L1_3490.note_OnRead
    A0_3489.m_note = L1_3490
  else
    L1_3490 = A0_3489.Properties
    L1_3490 = L1_3490.note_OnRead
    if L1_3490 ~= "" then
      L1_3490 = A0_3489.Properties
      L1_3490 = L1_3490.note_OnRead
      A0_3489.m_note = L1_3490
    else
      L1_3490 = LogError
      L1_3490(A0_3489:GetName() .. " no note data assigned.")
    end
  end
  L1_3490 = Ark
  L1_3490 = L1_3490.GetNoteSubject
  L1_3490 = L1_3490(A0_3489.m_note)
  if L1_3490 ~= nil and L1_3490 ~= "" then
    A0_3489:SetDisplayName(L1_3490)
  else
    LogError(A0_3489:GetName() .. " note data is invalid or empty.")
  end
end
function ArkBook.SetFromProperties(A0_3491)
  A0_3491:Log("SetFromProperties")
  A0_3491:SetupModelAndPhysics()
  A0_3491.m_bVerbose = A0_3491.PropertiesInstance.bVerbose == 1
end
function ArkBook.GetUsable(A0_3492)
  local L2_3493, L3_3494
  L2_3493 = {}
  L3_3494 = A0_3492.PropertiesInstance
  L3_3494 = L3_3494.bUsable
  if L3_3494 == 1 then
    L3_3494 = {}
    L3_3494.ActionType = "ScriptDefined"
    L3_3494.DisplayText = A0_3492.Properties.textDisplayText
    L2_3493.Use = L3_3494
  end
  return L2_3493
end
function ArkBook.GetRemoteManipulationInteraction(A0_3495)
  local L1_3496, L2_3497
  L1_3496 = {}
  L2_3497 = A0_3495.PropertiesInstance
  L2_3497 = L2_3497.bUsable
  if L2_3497 == 1 then
    L1_3496.ActionType = "ScriptDefined"
    L2_3497 = A0_3495.Properties
    L2_3497 = L2_3497.textDisplayText
    L1_3496.DisplayText = L2_3497
  end
  L1_3496.CouldChange = false
  return L1_3496
end
function ArkBook.OnUsed(A0_3498)
  if A0_3498.m_note ~= "" then
    g_localActor.arkPlayer:GiveNote(A0_3498.m_note)
  else
    LogWarning(A0_3498:GetName() .. " attempted to add a note to player, but no note was specified.")
  end
  BroadcastEvent(A0_3498, "OnUsed")
end
function ArkBook.OnRemoteManipulation(A0_3499)
  A0_3499:OnUsed()
end
function ArkBook.OnReset(A0_3500)
  A0_3500:SetFromProperties()
  Ark.SetShouldGlint(A0_3500.id, false)
end
function ArkBook.OnDestroy(A0_3501)
  Ark.SetShouldGlint(A0_3501.id, false)
end
ArkBook.FlowEvents = {
  Inputs = {},
  Outputs = {Used = "bool"}
}
