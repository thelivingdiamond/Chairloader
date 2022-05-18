local L0_8856
L0_8856 = {}
L0_8856.Properties = {
  fileModel = "Objects/Weapons/equipment/medical_Kit/medical_kit_bag_tp.cgf",
  fileXmlDef = "Scripts/Entities/User/sshain/LogQuestDefinitions.xml",
  fileXmlData = "Scripts/Entities/User/sshain/LogQuestData_Test.xml",
  fUseDistance = 2.5,
  sUsableMessage = "Ark_sshain_LogQuestClue",
  sQuestName = "TestQuest",
  sThisLocationName = "TestLocation"
}
L0_8856.PhysParams = {mass = 10, density = 0}
L0_8856.Editor = {
  Icon = "TagPoint.bmp",
  IconOnTop = 1
}
L0_8856.nRandomSeed = os.time()
L0_8856.bVerbose = true
L0_8856.bQuestVerified = false
L0_8856.bUsed = false
L0_8856.player = {}
Ark_sshain_LogQuest = L0_8856
L0_8856 = Ark_sshain_LogQuest
function L0_8856.Log(A0_8857, A1_8858)
  if A0_8857.bVerbose then
    System.Log(A1_8858)
  end
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.ResetQuest(A0_8859, A1_8860)
  local L2_8861
  L2_8861 = A0_8859.Properties
  L2_8861 = L2_8861.sQuestName
  A1_8860[L2_8861] = {}
  L2_8861 = A0_8859.Properties
  L2_8861 = L2_8861.sQuestName
  L2_8861 = A1_8860[L2_8861]
  L2_8861.bQuestStarted = false
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.StartQuest(A0_8862, A1_8863)
  A1_8863[A0_8862.Properties.sQuestName] = {
    bQuestStarted = true,
    nCluesDiscovered = 0,
    objectiveLocations = A0_8862:GenerateObjectiveLocations(),
    objectiveTexts = A0_8862:GenerateObjectiveTexts()
  }
  A0_8862:ContinueQuest(A1_8863)
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.ContinueQuest(A0_8864, A1_8865)
  local L2_8866, L3_8867, L4_8868, L5_8869, L6_8870, L7_8871, L8_8872, L9_8873, L10_8874, L11_8875, L12_8876, L13_8877, L14_8878, L15_8879
  L3_8867 = A0_8864
  L2_8866 = A0_8864.GetQuestLocations
  L4_8868 = A1_8865
  L2_8866 = L2_8866(L3_8867, L4_8868)
  L4_8868 = A0_8864
  L3_8867 = A0_8864.GetQuestTexts
  L3_8867 = L3_8867(L4_8868, L5_8869)
  L4_8868 = {}
  for L8_8872, L9_8873 in L5_8869(L6_8870) do
    if L10_8874 == L11_8875 then
      for L13_8877, L14_8878 in L10_8874(L11_8875) do
        L15_8879 = L14_8878
        if L15_8879 == "THIS_LOCATION" then
          L15_8879 = L2_8866[L8_8872]
        elseif L15_8879 == "NEXT_LOCATION" then
          if L8_8872 + 1 <= #L2_8866 then
            L15_8879 = L2_8866[L8_8872 + 1]
          else
            L15_8879 = "INVALID NEXT_LOCATION CALL AT " .. tostring(L8_8872) .. "-" .. tostring(L13_8877)
          end
        end
        table.insert(L4_8868, L15_8879)
      end
      for L14_8878, L15_8879 in L11_8875(L12_8876) do
      end
      L11_8875(L12_8876, L13_8877)
      L14_8878 = L10_8874
      L11_8875(L12_8876, L13_8877, L14_8878)
    end
  end
  L8_8872 = A1_8865
  L5_8869.nCluesDiscovered = L6_8870
  L5_8869(L6_8870, L7_8871)
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.EvaluateQuest(A0_8880, A1_8881)
  if A0_8880:GetCluesRemaining(A1_8881) == 0 then
    BroadcastEvent(A0_8880, "QuestComplete")
  end
  if A0_8880:GetCluesDiscovered(A1_8881) == 1 then
    BroadcastEvent(A0_8880, "FirstClueFound")
  end
  if A0_8880:GetQuestLocations(A1_8881)[#A0_8880:GetQuestLocations(A1_8881)] == A0_8880.Properties.sThisLocationName then
    BroadcastEvent(A0_8880, "LastClueFound")
  end
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GetQuestLocations(A0_8882, A1_8883)
  local L2_8884
  L2_8884 = A0_8882.Properties
  L2_8884 = L2_8884.sQuestName
  L2_8884 = A1_8883[L2_8884]
  L2_8884 = L2_8884.objectiveLocations
  return L2_8884
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GetCluesDiscovered(A0_8885, A1_8886)
  local L2_8887
  L2_8887 = A0_8885.Properties
  L2_8887 = L2_8887.sQuestName
  L2_8887 = A1_8886[L2_8887]
  L2_8887 = L2_8887.nCluesDiscovered
  return L2_8887
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GetQuestTexts(A0_8888, A1_8889)
  local L2_8890
  L2_8890 = A0_8888.Properties
  L2_8890 = L2_8890.sQuestName
  L2_8890 = A1_8889[L2_8890]
  L2_8890 = L2_8890.objectiveTexts
  return L2_8890
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GetCluesRemaining(A0_8891, A1_8892)
  return #A0_8891:GetQuestLocations(A1_8892) - A0_8891:GetCluesDiscovered(A1_8892)
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.IsQuestStarted(A0_8893, A1_8894)
  local L2_8895
  L2_8895 = A0_8893.Properties
  L2_8895 = L2_8895.sQuestName
  L2_8895 = A1_8894[L2_8895]
  if L2_8895 then
    L2_8895 = A0_8893.Properties
    L2_8895 = L2_8895.sQuestName
    L2_8895 = A1_8894[L2_8895]
    L2_8895 = L2_8895.bQuestStarted
    return L2_8895
  else
    L2_8895 = 0
    return L2_8895
  end
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.IsValidQuestItem(A0_8896, A1_8897)
  if A0_8896:IsQuestStarted(A1_8897) then
    for _FORV_5_, _FORV_6_ in ipairs(A0_8896:GetQuestLocations(A1_8897)) do
      if A0_8896.Properties.sThisLocationName == _FORV_6_ then
        return 1
      end
    end
    return 0
  else
    return 1
  end
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GenerateObjectiveTexts(A0_8898)
  local L1_8899, L2_8900
  L1_8899 = A0_8898.player
  L1_8899 = L1_8899.xmlLogQuestData
  L2_8900 = A0_8898.Properties
  L2_8900 = L2_8900.sQuestName
  L1_8899 = L1_8899[L2_8900]
  L1_8899 = L1_8899.quest
  L1_8899 = L1_8899.objectives
  L2_8900 = {}
  for _FORV_6_, _FORV_7_ in ipairs(L1_8899) do
    table.insert(L2_8900, _FORV_7_.objectiveTexts)
  end
  return L2_8900
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GenerateObjectiveLocations(A0_8901)
  local L1_8902, L2_8903, L3_8904, L4_8905, L5_8906
  function L1_8902()
    local L0_8907, L1_8908, L2_8909, L3_8910, L4_8911, L5_8912, L6_8913
    L0_8907 = _UPVALUE0_
    L0_8907 = L0_8907.player
    L0_8907 = L0_8907.xmlLogQuestData
    L1_8908 = _UPVALUE0_
    L1_8908 = L1_8908.Properties
    L1_8908 = L1_8908.sQuestName
    L0_8907 = L0_8907[L1_8908]
    L0_8907 = L0_8907.quest
    L0_8907 = L0_8907.locations
    L1_8908 = {}
    for L5_8912, L6_8913 in L2_8909(L3_8910) do
      if L6_8913 == _UPVALUE0_.Properties.sThisLocationName then
        _UPVALUE0_.bQuestVerified = true
      else
        table.insert(L1_8908, L6_8913)
      end
    end
    if not L2_8909 then
      L5_8912 = _UPVALUE0_
      L5_8912 = L5_8912.Properties
      L5_8912 = L5_8912.sThisLocationName
      L6_8913 = " is missing from quest locations."
      L2_8909(L3_8910, L4_8911)
    end
    return L1_8908
  end
  L2_8903 = L1_8902
  L2_8903 = L2_8903()
  function L3_8904()
    local L0_8914, L1_8915
    L0_8914 = _UPVALUE0_
    L0_8914 = L0_8914.player
    L0_8914 = L0_8914.xmlLogQuestData
    L1_8915 = _UPVALUE0_
    L1_8915 = L1_8915.Properties
    L1_8915 = L1_8915.sQuestName
    L0_8914 = L0_8914[L1_8915]
    L0_8914 = L0_8914.quest
    L0_8914 = L0_8914.questLength
    return L0_8914
  end
  function L4_8905()
    local L0_8916
    L0_8916 = random
    L0_8916 = L0_8916(1, #_UPVALUE0_)
    table.remove(_UPVALUE0_, L0_8916)
    return _UPVALUE0_[L0_8916]
  end
  function L5_8906(A0_8917)
    local L1_8918
    L1_8918 = {
      _UPVALUE0_.Properties.sThisLocationName
    }
    while A0_8917 > #L1_8918 do
      table.insert(L1_8918, _UPVALUE1_())
    end
    return L1_8918
  end
  return L5_8906(L3_8904())
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.DoPhysicalize(A0_8919)
  if A0_8919.currModel ~= A0_8919.Properties.fileModel then
    CryAction.ActivateExtensionForGameObject(A0_8919.id, "ScriptControlledPhysics", false)
    A0_8919:LoadObject(0, A0_8919.Properties.fileModel)
    A0_8919:Physicalize(0, PE_RIGID, A0_8919.PhysParams)
    CryAction.ActivateExtensionForGameObject(A0_8919.id, "ScriptControlledPhysics", true)
  end
  A0_8919:SetPhysicParams(PHYSICPARAM_FLAGS, {flags_mask = pef_cannot_squash_players, flags = pef_cannot_squash_players})
  A0_8919.currModel = A0_8919.Properties.fileModel
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.Reset(A0_8920, A1_8921)
  A0_8920:DoPhysicalize()
  A0_8920.player = g_localActor
  A0_8920.bUsed = false
  if A0_8920.player and A0_8920.player[A0_8920.Properties.sQuestName] then
    A0_8920.player[A0_8920.Properties.sQuestName] = nil
  end
  if A0_8920.player.xmlLogQuestData ~= nil then
    if A0_8920.player.xmlLogQuestData[A0_8920.Properties.sQuestName] ~= nil then
      A0_8920.player.xmlLogQuestData[A0_8920.Properties.sQuestName] = nil
    end
  else
    A0_8920.player.xmlLogQuestData = {}
    A0_8920.player.xmlLogQuestData[A0_8920.Properties.sQuestName] = {}
  end
  A0_8920.player.xmlLogQuestData[A0_8920.Properties.sQuestName] = CryAction.LoadXML(A0_8920.Properties.fileXmlDef, A0_8920.Properties.fileXmlData)
  A0_8920:ResetQuest(A0_8920.player)
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.UnHide(A0_8922)
  local L1_8923
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.IsUsable(A0_8924, A1_8925)
  local L2_8926, L3_8927, L4_8928, L5_8929, L6_8930, L7_8931
  if not A1_8925 then
    L2_8926 = 0
    return L2_8926
  end
  L2_8926 = A0_8924.Properties
  L2_8926 = L2_8926.fUseDistance
  L3_8927 = g_Vectors
  L3_8927 = L3_8927.temp_v1
  L5_8929 = A0_8924
  L4_8928 = A0_8924.GetWorldBBox
  L5_8929 = L4_8928(L5_8929)
  L6_8930 = FastSumVectors
  L7_8931 = L4_8928
  L6_8930(L7_8931, L4_8928, L5_8929)
  L6_8930 = ScaleVectorInPlace
  L7_8931 = L4_8928
  L6_8930(L7_8931, 0.5)
  L7_8931 = A1_8925
  L6_8930 = A1_8925.GetWorldPos
  L6_8930(L7_8931, L3_8927)
  L6_8930 = SubVectors
  L7_8931 = L3_8927
  L6_8930(L7_8931, L3_8927, L4_8928)
  L6_8930 = LengthSqVector
  L7_8931 = L3_8927
  L6_8930 = L6_8930(L7_8931)
  L7_8931 = sqr
  L7_8931 = L7_8931(L2_8926)
  if L6_8930 < L7_8931 then
    L6_8930 = A0_8924.bUsed
    if L6_8930 then
      L6_8930 = 0
      return L6_8930
    else
      L7_8931 = A0_8924
      L6_8930 = A0_8924.IsValidQuestItem
      return L6_8930(L7_8931, A1_8925)
    end
  else
    L6_8930 = 0
    return L6_8930
  end
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.GetUsableMessage(A0_8932, A1_8933)
  return A0_8932.Properties.sUsableMessage .. ": " .. A0_8932.Properties.sThisLocationName
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.OnUsed(A0_8934, A1_8935)
  if not A0_8934.bUsed then
    if A0_8934:IsQuestStarted(A1_8935) then
      A0_8934:ContinueQuest(A1_8935)
    else
      A0_8934:StartQuest(A1_8935)
    end
    A0_8934:ActivateOutput("PickedUp", A0_8934.Properties.sThisLocationName)
    A0_8934:ActivateOutput("CluesFound", A0_8934:GetCluesDiscovered(A1_8935))
    A0_8934:ActivateOutput("CluesRemaining", A0_8934:GetCluesRemaining(A1_8935))
  end
  A0_8934.bUsed = true
  A0_8934:Hide(1)
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.OnPropertyChange(A0_8936)
  A0_8936:Reset()
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.OnReset(A0_8937)
  A0_8937:Reset()
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.OnSpawn(A0_8938)
  A0_8938:Reset(1)
end
L0_8856 = Ark_sshain_LogQuest
function L0_8856.OnDestroy(A0_8939)
  local L1_8940
end
L0_8856 = Ark_sshain_LogQuest
L0_8856.FlowEvents = {
  Inputs = {},
  Outputs = {
    QuestComplete = "bool",
    FirstClueFound = "bool",
    LastClueFound = "bool",
    PickedUp = "string",
    Objective = "string",
    CluesFound = "int",
    CluesRemaining = "int"
  }
}
