Script.ReloadScript("scripts/entities/items/itemsystemmath.lua")
ArkNote = {
  Properties = {
    SummaryText = "",
    clrSummaryColor = {
      x = 1,
      y = 0.5,
      z = 0
    },
    nSummaryDist = 20,
    MainText = "",
    clrMainColor = {
      x = 1,
      y = 0.5,
      z = 0
    },
    nMainDist = 100,
    nMaxNoteWidth = 30,
    nMaxNoteHeight = 0,
    bHideInEditor = 0,
    bHideInGame = 0,
    fSize = 1.2,
    bDrawThroughWalls = 0
  },
  Editor = {
    Model = "Editor/Objects/comment.cgf",
    Icon = "Comment.bmp"
  },
  hidden = 0,
  bForceHideInEditorGame = 0,
  summaryLines = {},
  summaryLineCount = 0,
  mainLines = {},
  mainLineCount = 0
}
bIsNoteCCRegistered = bIsNoteCCRegistered
if not bIsNoteCCRegistered then
  g_cl_note = 1
  g_cl_notesInGame = 1
  System.AddCCommand("cl_note", "g_cl_note=tonumber(%1)", "Hide/Unhide notes")
  System.AddCCommand("cl_notesInGame", "g_cl_notesInGame=tonumber(%1)", "Hide/Unhide notes in game")
  bIsNoteCCRegistered = true
end
function ArkNote.OnLoad(A0_4353, A1_4354)
  A0_4353.hidden = A1_4354.hidden
end
function ArkNote.OnSave(A0_4355, A1_4356)
  A1_4356.hidden = A0_4355.hidden
end
function ArkNote.OnInit(A0_4357)
  if System.IsDevModeEnable() then
    A0_4357:SetUpdatePolicy(ENTITY_UPDATE_VISIBLE)
    A0_4357:Activate(1)
  end
  A0_4357:OnReset()
end
function ArkNote.OnPropertyChange(A0_4358)
  A0_4358:OnReset()
end
function ArkNote.SplitLines(A0_4359, A1_4360, A2_4361, A3_4362)
  local L4_4363, L5_4364, L6_4365, L7_4366, L8_4367, L9_4368, L10_4369, L11_4370
  L4_4363 = 0
  L5_4364 = ""
  L6_4365 = 1
  L7_4366 = {}
  for L11_4370 in L8_4367(L9_4368, L10_4369) do
    if L11_4370 == " " and A2_4361 < L4_4363 then
      L7_4366[L6_4365] = L5_4364
      L6_4365 = L6_4365 + 1
      L5_4364 = ""
      L4_4363 = 0
      L11_4370 = ""
    end
    if L11_4370 ~= "" then
      L5_4364 = L5_4364 .. L11_4370
      L4_4363 = L4_4363 + 1
    end
    if A3_4362 > 0 and A3_4362 < L6_4365 then
      break
    end
  end
  L7_4366[L6_4365] = L5_4364
  return L9_4368, L10_4369
end
function ArkNote.OnReset(A0_4371)
  A0_4371.lines = {}
  A0_4371.summaryLines, A0_4371.summaryLineCount = A0_4371:SplitLines(A0_4371.Properties.SummaryText, A0_4371.Properties.nMaxNoteWidth, A0_4371.Properties.nMaxNoteHeight)
  A0_4371.mainLines, A0_4371.mainLineCount = A0_4371:SplitLines(A0_4371.Properties.MainText, A0_4371.Properties.nMaxNoteWidth, A0_4371.Properties.nMaxNoteHeight)
end
function ArkNote.OnUpdate(A0_4372, A1_4373)
  local L2_4374, L3_4375, L4_4376, L5_4377, L6_4378, L7_4379, L8_4380, L9_4381, L10_4382, L11_4383, L12_4384, L13_4385, L14_4386, L15_4387, L16_4388
  L2_4374 = A0_4372.hidden
  if L2_4374 == 0 then
    L3_4375 = A0_4372
    L2_4374 = A0_4372.IsHidden
    L2_4374 = L2_4374(L3_4375)
  elseif L2_4374 then
    return
  end
  L2_4374 = A0_4372.bForceHideInEditorGame
  if L2_4374 == 1 then
    L2_4374 = System
    L2_4374 = L2_4374.IsEditing
    L2_4374 = L2_4374()
    if not L2_4374 then
      return
    end
  end
  L2_4374 = A0_4372.Properties
  L2_4374 = L2_4374.bHideInEditor
  L2_4374 = L2_4374 == 1 or L2_4374 ~= 1
  L3_4375 = A0_4372.Properties
  L3_4375 = L3_4375.bHideInGame
  L3_4375 = L3_4375 == 1 or L3_4375 ~= 1 or L3_4375 ~= 1
  if L2_4374 then
    L4_4376 = System
    L4_4376 = L4_4376.IsEditing
    L4_4376 = L4_4376()
  else
    if not L4_4376 then
      if L3_4375 then
        L4_4376 = System
        L4_4376 = L4_4376.IsEditing
        L4_4376 = L4_4376()
      end
  end
  elseif not L4_4376 then
    return
  end
  L4_4376 = A0_4372.Properties
  L4_4376 = L4_4376.SummaryText
  L5_4377 = A0_4372.Properties
  L5_4377 = L5_4377.MainText
  if L4_4376 == "" and L5_4377 == "" then
    return
  end
  L6_4378 = A0_4372.Properties
  L6_4378 = L6_4378.nSummaryDist
  L7_4379 = A0_4372.Properties
  L7_4379 = L7_4379.nMainDist
  L8_4380 = __max
  L9_4381 = L6_4378
  L10_4382 = L7_4379
  L8_4380 = L8_4380(L9_4381, L10_4382)
  L9_4381 = L8_4380 * L8_4380
  L10_4382 = 1
  L11_4383 = 0
  L12_4384 = g_localActor
  if L12_4384 and L8_4380 > 0 then
    L12_4384 = g_Vectors
    L12_4384 = L12_4384.temp_v1
    L13_4385 = g_Vectors
    L13_4385 = L13_4385.temp_v2
    L15_4387 = A0_4372
    L14_4386 = A0_4372.GetWorldPos
    L16_4388 = L12_4384
    L14_4386(L15_4387, L16_4388)
    L14_4386 = g_localActor
    L15_4387 = L14_4386
    L14_4386 = L14_4386.GetWorldPos
    L16_4388 = L13_4385
    L14_4386(L15_4387, L16_4388)
    L14_4386 = SubVectors
    L15_4387 = L12_4384
    L16_4388 = L12_4384
    L14_4386(L15_4387, L16_4388, L13_4385)
    L14_4386 = LengthSqVector
    L15_4387 = L12_4384
    L14_4386 = L14_4386(L15_4387)
    L15_4387 = L6_4378 * L6_4378
    L11_4383 = L14_4386 < L15_4387
    if L9_4381 > L14_4386 then
      L10_4382 = L14_4386 / L9_4381
      L15_4387 = L10_4382 * L10_4382
      L10_4382 = 1 - L15_4387
    else
      L10_4382 = 0
    end
  end
  L12_4384 = {}
  L13_4385 = 0
  L14_4386 = {}
  if L11_4383 and L4_4376 ~= "" or L5_4377 == "" then
    L12_4384 = A0_4372.summaryLines
    L13_4385 = A0_4372.summaryLineCount
    L15_4387 = A0_4372.Properties
    L14_4386 = L15_4387.clrSummaryColor
  else
    L12_4384 = A0_4372.mainLines
    L13_4385 = A0_4372.mainLineCount
    L15_4387 = A0_4372.Properties
    L14_4386 = L15_4387.clrMainColor
  end
  if L10_4382 > 0.001 then
    L16_4388 = A0_4372
    L15_4387 = A0_4372.GetWorldPos
    L15_4387 = L15_4387(L16_4388, g_Vectors.temp_v1)
    L16_4388 = table
    L16_4388 = L16_4388.concat
    L16_4388 = L16_4388(L12_4384, "\n")
    Ark.DrawNote(L15_4387, A0_4372.Properties.fSize, L16_4388, L13_4385, L14_4386.x, L14_4386.y, L14_4386.z, L10_4382, A0_4372.Properties.bDrawThroughWalls)
  end
end
function ArkNote.Event_UnHide(A0_4389)
  A0_4389:Hide(0)
  A0_4389.hidden = 0
  BroadcastEvent(A0_4389, "UnHide")
end
function ArkNote.Event_Hide(A0_4390)
  A0_4390:Hide(1)
  A0_4390.hidden = 1
  BroadcastEvent(A0_4390, "Hide")
end
ArkNote.FlowEvents = {
  Inputs = {
    Hide = {
      ArkNote.Event_Hide,
      "void"
    },
    UnHide = {
      ArkNote.Event_UnHide,
      "void"
    }
  },
  Outputs = {Hide = "bool", UnHide = "bool"}
}
