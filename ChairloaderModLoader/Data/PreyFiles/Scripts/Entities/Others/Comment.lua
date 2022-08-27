Script.ReloadScript("scripts/entities/items/itemsystemmath.lua")
Comment = {
  Properties = {
    Text = "This is a comment",
    fSize = 1.2,
    bHidden = 0,
    fMaxDist = 100,
    nCharsPerLine = 30,
    bFixed = 0,
    clrDiffuse = {
      x = 1,
      y = 0.5,
      z = 0
    }
  },
  Editor = {
    Model = "Editor/Objects/comment.cgf",
    Icon = "Comment.bmp"
  },
  hidden = 0,
  lines = {},
  lineCount = 0,
  fMaxDistSquared = 0,
  bNoUpdateInGame = 1
}
function Comment.OnLoad(A0_6627, A1_6628)
  A0_6627.hidden = A1_6628.hidden
end
function Comment.OnSave(A0_6629, A1_6630)
  A1_6630.hidden = A0_6629.hidden
end
function Comment.OnInit(A0_6631)
  if not System.IsDevModeEnable() then
    A0_6631:DeleteThis()
    return
  end
  A0_6631:OnReset()
end
function Comment.OnSpawn(A0_6632)
  local L1_6633
end
function Comment.OnPropertyChange(A0_6634)
  A0_6634:OnReset()
end
function Comment.OnReset(A0_6635)
  local L1_6636, L2_6637, L3_6638, L4_6639, L5_6640, L6_6641, L7_6642, L8_6643, L9_6644
  L1_6636 = System
  L1_6636 = L1_6636.GetCVar
  L2_6637 = "cl_comment"
  L1_6636 = L1_6636(L2_6637)
  L2_6637 = System
  L2_6637 = L2_6637.IsEditor
  L2_6637 = L2_6637()
  if L2_6637 or L1_6636 > 0 then
    L3_6638 = A0_6635
    L2_6637 = A0_6635.SetUpdatePolicy
    L4_6639 = ENTITY_UPDATE_VISIBLE
    L2_6637(L3_6638, L4_6639)
    L3_6638 = A0_6635
    L2_6637 = A0_6635.Activate
    L4_6639 = 1
    L2_6637(L3_6638, L4_6639)
  else
    L3_6638 = A0_6635
    L2_6637 = A0_6635.Activate
    L4_6639 = 0
    L2_6637(L3_6638, L4_6639)
  end
  if L1_6636 == 0 then
    A0_6635.bNoUpdateInGame = 1
  else
    A0_6635.bNoUpdateInGame = 0
  end
  L2_6637 = A0_6635.Properties
  L2_6637 = L2_6637.fMaxDist
  L3_6638 = A0_6635.Properties
  L3_6638 = L3_6638.fMaxDist
  L2_6637 = L2_6637 * L3_6638
  A0_6635.fMaxDistSquared = L2_6637
  L2_6637 = A0_6635.Properties
  L2_6637 = L2_6637.bHidden
  A0_6635.hidden = L2_6637
  L2_6637 = {}
  A0_6635.lines = L2_6637
  L2_6637 = A0_6635.Properties
  L2_6637 = L2_6637.nCharsPerLine
  L3_6638 = 0
  L4_6639 = ""
  L5_6640 = 1
  for L9_6644 in L6_6641(L7_6642, L8_6643) do
    if L9_6644 == " " and L2_6637 < L3_6638 then
      A0_6635.lines[L5_6640] = L4_6639
      L5_6640 = L5_6640 + 1
      L4_6639 = ""
      L3_6638 = 0
      L9_6644 = ""
    end
    if L9_6644 ~= "" then
      L4_6639 = L4_6639 .. L9_6644
      L3_6638 = L3_6638 + 1
    end
  end
  L6_6641[L5_6640] = L4_6639
  A0_6635.lineCount = L5_6640
  L6_6641(L7_6642, L8_6643)
end
function Comment.OnUpdate(A0_6645, A1_6646)
  local L2_6647, L3_6648, L4_6649, L5_6650, L6_6651, L7_6652, L8_6653, L9_6654, L10_6655, L11_6656, L12_6657
  L2_6647 = A0_6645.hidden
  if L2_6647 == 0 then
    L3_6648 = A0_6645
    L2_6647 = A0_6645.IsHidden
    L2_6647 = L2_6647(L3_6648)
    if not L2_6647 then
      L2_6647 = A0_6645.Properties
      L2_6647 = L2_6647.Text
      if L2_6647 ~= "" then
        L2_6647 = A0_6645.bNoUpdateInGame
        if L2_6647 == 1 then
          L2_6647 = System
          L2_6647 = L2_6647.IsEditing
          L2_6647 = L2_6647()
        end
      end
    end
  elseif not L2_6647 then
    return
  end
  L2_6647 = 0
  L3_6648 = 0
  L4_6649 = A0_6645.fMaxDistSquared
  if L4_6649 > 0 then
    L4_6649 = g_Vectors
    L4_6649 = L4_6649.temp_v1
    L6_6651 = A0_6645
    L5_6650 = A0_6645.GetWorldPos
    L7_6652 = L4_6649
    L5_6650(L6_6651, L7_6652)
    L5_6650 = SubVectors
    L6_6651 = L4_6649
    L7_6652 = L4_6649
    L12_6657 = L8_6653()
    L5_6650(L6_6651, L7_6652, L8_6653, L9_6654, L10_6655, L11_6656, L12_6657, L8_6653())
    L5_6650 = LengthSqVector
    L6_6651 = L4_6649
    L5_6650 = L5_6650(L6_6651)
    L3_6648 = L5_6650
    L6_6651 = A0_6645.Properties
    L6_6651 = L6_6651.fMaxDist
    if L6_6651 >= 255 then
      L2_6647 = 1
    else
      L6_6651 = A0_6645.fMaxDistSquared
      if L5_6650 < L6_6651 then
        L6_6651 = A0_6645.fMaxDistSquared
        L2_6647 = L5_6650 / L6_6651
        L6_6651 = L2_6647 * L2_6647
        L2_6647 = 1 - L6_6651
      end
    end
  end
  L4_6649 = System
  L4_6649 = L4_6649.GetViewCameraUpDir
  L4_6649 = L4_6649()
  if L2_6647 > 0.001 then
    L6_6651 = A0_6645
    L5_6650 = A0_6645.GetWorldPos
    L7_6652 = g_Vectors
    L7_6652 = L7_6652.temp_v1
    L5_6650 = L5_6650(L6_6651, L7_6652)
    L6_6651 = math
    L6_6651 = L6_6651.sqrt
    L7_6652 = L3_6648
    L6_6651 = L6_6651(L7_6652)
    L3_6648 = L6_6651
    L6_6651 = A0_6645.Properties
    L6_6651 = L6_6651.fSize
    L6_6651 = L6_6651 / 60
    L6_6651 = L6_6651 * L3_6648
    L7_6652 = System
    L7_6652 = L7_6652.GetViewCameraFov
    L7_6652 = L7_6652()
    L3_6648 = L6_6651 * L7_6652
    L6_6651 = g_Vectors
    L6_6651 = L6_6651.temp_v4
    L7_6652 = FastScaleVector
    L7_6652(L8_6653, L9_6654, L10_6655)
    L7_6652 = FastScaleVector
    L7_6652(L8_6653, L9_6654, L10_6655)
    L7_6652 = FastSumVectors
    L7_6652(L8_6653, L9_6654, L10_6655)
    L7_6652 = {}
    L7_6652.x = 0
    L7_6652.y = 1
    L7_6652.z = 0
    if L8_6653 ~= 1 then
      L8_6653.x = L9_6654
      L8_6653.y = L9_6654
      L8_6653.z = L9_6654
      L7_6652 = L8_6653
    end
    for L11_6656, L12_6657 in L8_6653(L9_6654) do
      System.DrawLabel(L5_6650, A0_6645.Properties.fSize, L12_6657, L7_6652.x, L7_6652.y, L7_6652.z, L2_6647)
      FastDifferenceVectors(L5_6650, L5_6650, L4_6649)
    end
  end
end
function Comment.Event_UnHide(A0_6658, A1_6659)
  BroadcastEvent(A0_6658, "UnHide")
  A0_6658.hidden = 0
end
function Comment.Event_Hide(A0_6660, A1_6661)
  BroadcastEvent(A0_6660, "Hide")
  A0_6660.hidden = 1
end
Comment.FlowEvents = {
  Inputs = {
    Hide = {
      Comment.Event_Hide,
      "bool"
    },
    UnHide = {
      Comment.Event_UnHide,
      "bool"
    }
  },
  Outputs = {Hide = "bool", UnHide = "bool"}
}
