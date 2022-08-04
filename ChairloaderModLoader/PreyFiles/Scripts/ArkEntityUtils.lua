local L0_10088, L1_10089
L0_10088 = {}
L1_10089 = Sound
L1_10089 = L1_10089.GetAudioTriggerID
L0_10088.audioTrigger = L1_10089
L1_10089 = Sound
L1_10089 = L1_10089.GetAudioSwitchID
L0_10088.audioSwitch = L1_10089
L1_10089 = Sound
L1_10089 = L1_10089.GetAudioSwitchStateID
L0_10088.audioSwitchState = L1_10089
L1_10089 = Sound
L1_10089 = L1_10089.GetAudioRtpcID
L0_10088.audioRTPC = L1_10089
L1_10089 = Sound
L1_10089 = L1_10089.GetAudioEnvironmentID
L0_10088.audioEnvironment = L1_10089
AudioGettersByPrefix = L0_10088
function L0_10088(A0_10090, A1_10091)
  local L2_10092, L3_10093, L4_10094, L5_10095, L6_10096, L7_10097, L8_10098, L9_10099
  L2_10092 = A1_10091 or {}
  L3_10093 = AudioGettersByPrefix
  for L7_10097, L8_10098 in L4_10094(L5_10095) do
    if L8_10098 ~= "" then
      L9_10099 = string
      L9_10099 = L9_10099.find
      L9_10099 = L9_10099(L7_10097, "_")
      if L9_10099 ~= nil then
        L9_10099 = L9_10099 - 1
        if L3_10093[string.sub(L7_10097, 1, L9_10099)] then
          L2_10092[L7_10097] = L3_10093[string.sub(L7_10097, 1, L9_10099)](L8_10098)
        end
      else
      end
    else
    end
  end
  return L2_10092
end
GetAudioIds = L0_10088
function L0_10088(A0_10100)
  local L1_10101, L2_10102
  L1_10101 = {}
  L2_10102 = A0_10100.x
  L1_10101.x = L2_10102
  L2_10102 = A0_10100.y
  L1_10101.y = L2_10102
  L2_10102 = A0_10100.z
  L1_10101.z = L2_10102
  return L1_10101
end
NewVector = L0_10088
function L0_10088(A0_10103, A1_10104, A2_10105)
  local L3_10106
  L3_10106 = mergef
  L3_10106(A0_10103, A1_10104, true)
  A0_10103.__super = A1_10104
  if A2_10105 then
    L3_10106 = {}
    mergef(L3_10106, A1_10104.Properties.Physics, false)
    A0_10103.Properties.Physics = L3_10106
  end
  return A0_10103
end
ArkMakeDerivedEntityOverride = L0_10088
function L0_10088(A0_10107)
  local L1_10108, L2_10109
  function L1_10108(A0_10110, A1_10111)
    if A0_10110.m_bVerbose then
      if A1_10111 ~= nil then
        System.Log(A0_10110:GetName() .. " with entityId " .. tostring(A0_10110:GetRawId()) .. ":: " .. tostring(A1_10111))
      else
        LogWarning(A0_10110:GetName() .. " with entityId " .. tostring(A0_10110:GetRawId()) .. ":: Log request rejected due to nil string parameter.")
      end
    end
  end
  A0_10107.Log = L1_10108
  function L1_10108(A0_10112, A1_10113)
    A0_10112:Log("Init not overridden")
  end
  A0_10107.Init = L1_10108
  function L1_10108(A0_10114, A1_10115)
    return A0_10114:ToGlobal(0, (SumVectors(A0_10114:ToLocal(0, A0_10114:GetCenterOfMassPos()), A1_10115)))
  end
  A0_10107.CreateOffsetPos = L1_10108
  function L1_10108(A0_10116, A1_10117)
    if A1_10117 then
      Script.KillTimer(A1_10117)
    end
  end
  A0_10107.KillTimer = L1_10108
  function L1_10108(A0_10118, A1_10119)
    local L2_10120, L3_10121
    L2_10120 = A0_10118.Properties
    L3_10121 = A1_10119 or L2_10120.object_Model
    if L3_10121 ~= nil then
      A0_10118:LoadObject(0, L3_10121)
    else
      LogError(A0_10118:GetName() .. " is missing a model!")
    end
    if L2_10120.Physics ~= nil and L2_10120.Physics.bPhysicalize == 1 then
      A0_10118:PhysicalizeThis()
    end
  end
  A0_10107.SetupModelAndPhysics = L1_10108
  function L1_10108(A0_10122)
    local L1_10123
    L1_10123 = A0_10122.Properties
    L1_10123 = L1_10123.Physics
    if L1_10123 ~= nil then
      L1_10123 = A0_10122.Properties
      L1_10123 = L1_10123.Physics
      EntityCommon.PhysicalizeRigid(A0_10122, 0, L1_10123, A0_10122.bRigidBodyActive)
    end
  end
  A0_10107.PhysicalizeThis = L1_10108
  function L1_10108(A0_10124)
    local L1_10125
    L1_10125 = A0_10124.Properties
    if L1_10125.object_Model == "" then
      return
    end
    A0_10124:SetupModelAndPhysics()
    if L1_10125.bCanTriggerAreas == 1 then
      A0_10124:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
    else
      A0_10124:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
    end
  end
  A0_10107.SetFromProperties = L1_10108
  function L1_10108(A0_10126)
    local L1_10127
    L1_10127 = A0_10126.Properties
    L1_10127 = L1_10127.Effects
    L1_10127 = L1_10127.particleeffect_Camera
    L1_10127 = L1_10127 ~= ""
    return L1_10127
  end
  A0_10107.IsCameraVfxEnabled = L1_10108
  function L1_10108(A0_10128, A1_10129, A2_10130, A3_10131, A4_10132, A5_10133)
    Particle.SpawnEffect(A3_10131, g_Vectors.v000, g_Vectors.v000, 1)
    A0_10128[A1_10129] = false
    A0_10128[A2_10130] = Script.SetTimer(A4_10132, A5_10133)
  end
  A0_10107.DoCameraFX = L1_10108
  function L1_10108(A0_10134, A1_10135)
    return string.sub(A1_10135, 5)
  end
  A0_10107.GetGUIDString = L1_10108
  function L1_10108(A0_10136)
    A0_10136:Log("OnSpawn not overridden")
    A0_10136:SetFromProperties()
  end
  A0_10107.OnSpawn = L1_10108
  function L1_10108(A0_10137)
    A0_10137:Log("OnInit not overridden")
    if System.IsEditor() then
      A0_10137:Init()
      if A0_10137.States then
        A0_10137:GotoState("")
      end
    end
  end
  A0_10107.OnInit = L1_10108
  function L1_10108(A0_10138, A1_10139)
    A0_10138:Log("OnReset not overridden")
    if A0_10138.Properties.Physics ~= nil and A0_10138.Properties.Physics.bPhysicalize == 1 then
      A0_10138:PhysicalizeThis()
      A0_10138:AwakePhysics(0)
    end
  end
  A0_10107.OnReset = L1_10108
  function L1_10108(A0_10140)
    A0_10140:Log("OnStartGame" .. A0_10140:GetState() or "")
    if System.IsEditor() then
      A0_10140:Init(true)
    end
  end
  A0_10107.OnStartGame = L1_10108
  function L1_10108(A0_10141)
    A0_10141:Log("OnStartLevel " .. A0_10141:GetState() or "")
    if not System.IsEditor() then
      A0_10141:Init(true)
    end
  end
  A0_10107.OnStartLevel = L1_10108
  function L1_10108(A0_10142)
    A0_10142:Log("OnPropertyChange not overridden")
    A0_10142:SetFromProperties()
  end
  A0_10107.OnPropertyChange = L1_10108
  function L1_10108(A0_10143)
    A0_10143:Log("OnUsed not overridden")
  end
  A0_10107.OnUsed = L1_10108
  function L1_10108(A0_10144, A1_10145)
  end
  A0_10107.OnCollision = L1_10108
  function L1_10108(A0_10146, A1_10147)
    A0_10146:Log("OnHit. Hit by " .. tostring(A1_10147.shooter.id) .. " not overridden")
  end
  A0_10107.OnHit = L1_10108
  function L1_10108(A0_10148)
    A0_10148:Log("OnDestroy not overridden")
  end
  A0_10107.OnDestroy = L1_10108
  function L1_10108(A0_10149)
    A0_10149:Log("OnShutDown not overridden")
  end
  A0_10107.OnShutDown = L1_10108
  function L1_10108(A0_10150)
    A0_10150:PhysicalizeThis()
  end
  A0_10107.OnUnHidden = L1_10108
  L1_10108 = A0_10107.Properties
  L1_10108 = L1_10108.ei_ObjectMapIcon
  if L1_10108 ~= nil then
    function L1_10108(A0_10151)
      return tonumber(A0_10151.Properties.ei_ObjectMapIcon)
    end
    A0_10107.GetMapIconId = L1_10108
  end
  L1_10108 = A0_10107.Server
  if L1_10108 ~= nil then
    L1_10108 = A0_10107.Server
    L2_10109 = A0_10107.OnStartLevel
    L1_10108.OnStartLevel = L2_10109
    L1_10108 = A0_10107.Server
    L2_10109 = A0_10107.OnStartGame
    L1_10108.OnStartGame = L2_10109
    L1_10108 = A0_10107.Server
    L2_10109 = A0_10107.OnHit
    L1_10108.OnHit = L2_10109
    L1_10108 = A0_10107.Server
    L2_10109 = A0_10107.OnInit
    L1_10108.OnInit = L2_10109
    L1_10108 = A0_10107.Server
    L2_10109 = A0_10107.OnUpdate
    L1_10108.OnUpdate = L2_10109
  end
end
GetArkEntityUtils = L0_10088
function L0_10088(A0_10152)
  local L1_10153
  function L1_10153(A0_10154, A1_10155)
    if A0_10154.m_savedState ~= nil then
      A0_10154.m_savedState = A0_10154:GetState()
    end
    if A0_10154.m_referenceTable then
      for _FORV_5_, _FORV_6_ in pairs(A0_10154.m_referenceTable) do
        A1_10155[_FORV_5_] = A0_10154[_FORV_5_]
      end
    end
  end
  A0_10152.OnSave = L1_10153
  function L1_10153(A0_10156, A1_10157)
    for _FORV_5_, _FORV_6_ in pairs(A1_10157) do
      A0_10156[_FORV_5_] = _FORV_6_
    end
  end
  A0_10152.OnLoad = L1_10153
  function L1_10153(A0_10158)
    A0_10158:Log("OnPostLoad not overriden")
  end
  A0_10152.OnPostLoad = L1_10153
end
ArkMakeSaveable = L0_10088
function L0_10088(A0_10159)
  local L1_10160
  function L1_10160(A0_10161, A1_10162)
    A1_10162.PropertiesInstance = {}
    for _FORV_5_, _FORV_6_ in pairs(A0_10161.PropertiesInstance) do
      A1_10162.PropertiesInstance[_FORV_5_] = _FORV_6_
    end
  end
  A0_10159.OnSave = L1_10160
  function L1_10160(A0_10163, A1_10164)
    A0_10163:Log("OnLoad()")
    for _FORV_5_, _FORV_6_ in pairs(A1_10164) do
      A0_10163[_FORV_5_] = _FORV_6_
    end
  end
  A0_10159.OnLoad = L1_10160
end
ArkMakeInstanceObjectSaveable = L0_10088
function L0_10088(A0_10165)
  local L1_10166
  function L1_10166(A0_10167, A1_10168, A2_10169, A3_10170, A4_10171, A5_10172)
    local L6_10173, L7_10174, L8_10175, L9_10176, L10_10177, L11_10178, L12_10179
    L7_10174 = A0_10167
    L6_10173 = A0_10167.GetBoneTable
    L8_10175 = A3_10170
    L6_10173 = L6_10173(L7_10174, L8_10175)
    L7_10174 = A0_10167.Properties
    L7_10174 = L7_10174.archetype_Keypad
    L8_10175 = "ArkKeypad"
    L9_10176 = System
    L9_10176 = L9_10176.GetEntityLayer
    L10_10177 = A0_10167.id
    L9_10176 = L9_10176(L10_10177)
    if A1_10168 then
      L10_10177 = A0_10167.Properties
      L7_10174 = L10_10177.archetype_KeycardReader
      L8_10175 = "ArkKeycardReader"
    end
    if A2_10169 >= 1 then
      L11_10178 = A0_10167
      L10_10177 = A0_10167.GetBonePos
      L12_10179 = L6_10173.outside
      L10_10177 = L10_10177(L11_10178, L12_10179)
      L12_10179 = A0_10167
      L11_10178 = A0_10167.GetBoneDir
      L11_10178 = L11_10178(L12_10179, L6_10173.outside)
      L12_10179 = A0_10167.GetBoneUp
      L12_10179 = L12_10179(A0_10167, L6_10173.outside)
      if L10_10177 then
        A0_10167.m_outsideController = A0_10167:SpawnAccessController(L7_10174, L8_10175, L9_10176, L10_10177, L11_10178, L12_10179)
        A0_10167:AttachChild(A0_10167.m_outsideController.id, 1)
        A0_10167.m_outsideController:InitDoorAccessController(A0_10167)
      else
        LogError(A0_10167:GetName() .. " wants to attach a keypad to missing bone " .. L6_10173.outside)
      end
    end
    if A4_10171 then
      L10_10177 = A0_10167.Properties
      L7_10174 = L10_10177.archetype_FreeExitButton
      L8_10175 = "ArkInteractiveObject"
    end
    if A2_10169 > 1 or A4_10171 then
      L11_10178 = A0_10167
      L10_10177 = A0_10167.GetBonePos
      L12_10179 = L6_10173.inside
      L10_10177 = L10_10177(L11_10178, L12_10179)
      L12_10179 = A0_10167
      L11_10178 = A0_10167.GetBoneDir
      L11_10178 = L11_10178(L12_10179, L6_10173.inside)
      L12_10179 = A0_10167.GetBoneUp
      L12_10179 = L12_10179(A0_10167, L6_10173.inside)
      if L10_10177 then
        if A5_10172 ~= nil then
          L10_10177 = A0_10167:ToGlobal(0, (SumVectors(A0_10167:ToLocal(0, L10_10177), A5_10172)))
        else
          LogError(A0_10167:GetName() .. " trying to load a Free Exit Offset with value NIL. Entity instance in level needs to be fixed.")
        end
        A0_10167.m_insideController = A0_10167:SpawnAccessController(L7_10174, L8_10175, L9_10176, L10_10177, L11_10178, L12_10179)
        A0_10167:AttachChild(A0_10167.m_insideController.id, 1)
        A0_10167.m_insideController:InitDoorAccessController(A0_10167)
      else
        LogError(A0_10167:GetName() .. " wants to attach a keypad or free exit button to missing bone " .. L6_10173.inside)
      end
    end
  end
  A0_10165.SetupAccessControl = L1_10166
  function L1_10166(A0_10180, A1_10181)
    local L2_10182
    if A1_10181 then
      L2_10182 = A0_10180.Properties
      L2_10182 = L2_10182.KeypadBoneNames
      L2_10182 = L2_10182.left
      return L2_10182
    else
      L2_10182 = A0_10180.Properties
      L2_10182 = L2_10182.KeypadBoneNames
      L2_10182 = L2_10182.right
      return L2_10182
    end
  end
  A0_10165.GetBoneTable = L1_10166
  function L1_10166(A0_10183, A1_10184, A2_10185, A3_10186, A4_10187, A5_10188, A6_10189)
    local L7_10190
    L7_10190 = A0_10183.Log
    L7_10190(A0_10183, "Spawning Access Controller")
    L7_10190 = {}
    L7_10190.class = A2_10185
    L7_10190.archetype = A1_10184
    L7_10190.name = A0_10183:GetName() .. A2_10185
    L7_10190.layer = A3_10186
    L7_10190.position = A4_10187
    L7_10190.orientation = A5_10188
    System.SpawnEntity(L7_10190):SetWorldPos(A4_10187)
    System.SpawnEntity(L7_10190):SetDirectionVector(A5_10188, A6_10189)
    return (System.SpawnEntity(L7_10190))
  end
  A0_10165.SpawnAccessController = L1_10166
  function L1_10166(A0_10191, A1_10192, A2_10193, A3_10194, A4_10195)
    local L5_10196, L6_10197, L7_10198, L8_10199
    L5_10196 = System
    L5_10196 = L5_10196.IsEditor
    L5_10196 = L5_10196()
    if L5_10196 then
      L5_10196 = A0_10191.Properties
      L5_10196 = L5_10196.object_KeypadModel
      L7_10198 = A0_10191
      L6_10197 = A0_10191.GetBoneTable
      L8_10199 = A2_10193
      L6_10197 = L6_10197(L7_10198, L8_10199)
      if A1_10192 >= 1 then
        L8_10199 = A0_10191
        L7_10198 = A0_10191.GetBonePos
        L7_10198 = L7_10198(L8_10199, L6_10197.outside)
        L8_10199 = A0_10191.GetBoneDir
        L8_10199 = L8_10199(A0_10191, L6_10197.outside)
        if L7_10198 then
          A0_10191:LoadObject(1, L5_10196)
          A0_10191:SetSlotWorldTM(1, L7_10198, L8_10199)
        else
          LogError(A0_10191:GetName() .. " wants to attach a keypad to missing bone " .. L6_10197.outside)
          A0_10191:FreeSlot(1)
        end
      else
        L8_10199 = A0_10191
        L7_10198 = A0_10191.FreeSlot
        L7_10198(L8_10199, 1)
      end
      if A3_10194 then
        L7_10198 = A0_10191.Properties
        L5_10196 = L7_10198.object_FreeExitModel
      end
      if A1_10192 > 1 or A3_10194 then
        L8_10199 = A0_10191
        L7_10198 = A0_10191.GetBonePos
        L7_10198 = L7_10198(L8_10199, L6_10197.inside)
        vecBonePos = L7_10198
        L8_10199 = A0_10191
        L7_10198 = A0_10191.GetBoneDir
        L7_10198 = L7_10198(L8_10199, L6_10197.inside)
        vecKeypadDir = L7_10198
        L7_10198 = vecBonePos
        if L7_10198 then
          if A4_10195 ~= nil then
            L8_10199 = A0_10191
            L7_10198 = A0_10191.ToGlobal
            L7_10198 = L7_10198(L8_10199, 0, (SumVectors(A0_10191:ToLocal(0, vecBonePos), A4_10195)))
            vecBonePos = L7_10198
          else
            L7_10198 = LogError
            L8_10199 = A0_10191.GetName
            L8_10199 = L8_10199(A0_10191)
            L8_10199 = L8_10199 .. " trying to load a Free Exit Offset with value NIL. Entity instance in level needs to be fixed."
            L7_10198(L8_10199)
          end
          L8_10199 = A0_10191
          L7_10198 = A0_10191.LoadObject
          L7_10198(L8_10199, 2, L5_10196)
          L8_10199 = A0_10191
          L7_10198 = A0_10191.SetSlotWorldTM
          L7_10198(L8_10199, 2, vecBonePos, vecKeypadDir)
        else
          L7_10198 = LogError
          L8_10199 = A0_10191.GetName
          L8_10199 = L8_10199(A0_10191)
          L8_10199 = L8_10199 .. " wants to attach a keypad or free exit button to missing bone " .. L6_10197.inside
          L7_10198(L8_10199)
          L8_10199 = A0_10191
          L7_10198 = A0_10191.FreeSlot
          L7_10198(L8_10199, 2)
        end
      else
        L8_10199 = A0_10191
        L7_10198 = A0_10191.FreeSlot
        L7_10198(L8_10199, 2)
      end
    else
      L6_10197 = A0_10191
      L5_10196 = A0_10191.FreeSlot
      L7_10198 = 1
      L5_10196(L6_10197, L7_10198)
      L6_10197 = A0_10191
      L5_10196 = A0_10191.FreeSlot
      L7_10198 = 2
      L5_10196(L6_10197, L7_10198)
    end
  end
  A0_10165.LoadAccessControllersForEditor = L1_10166
end
ArkMakeLockable = L0_10088
function L0_10088(A0_10200)
  local L1_10201, L2_10202
  function L1_10201(A0_10203)
    A0_10203:Log("_entity:HackSuccess() not overridden")
  end
  A0_10200.HackSuccess = L1_10201
  function L1_10201(A0_10204)
    A0_10204:Log("_entity:HackFail() not overridden")
  end
  A0_10200.HackFail = L1_10201
  function L1_10201(A0_10205)
    local L1_10206
    L1_10206 = A0_10205.Properties
    L1_10206 = L1_10206.nHackDifficulty
    if A0_10205.PropertiesInstance.nHackDifficultyOverride ~= -1 then
      L1_10206 = A0_10205.PropertiesInstance.nHackDifficultyOverride
    end
    L1_10206 = L1_10206 + 1
    A0_10205:CallUIElementFunction("setHackingLevel", L1_10206)
  end
  A0_10200.UpdateHackLevelDisplay = L1_10201
  L1_10201 = A0_10200.FlowEvents
  if not L1_10201 then
    L1_10201 = {}
    A0_10200.FlowEvents = L1_10201
  end
  L1_10201 = A0_10200.FlowEvents
  L2_10202 = L1_10201.Inputs
  L2_10202 = L2_10202 or {}
  L1_10201.Inputs = L2_10202
  L2_10202 = L1_10201.Outputs
  L2_10202 = L2_10202 or {}
  L1_10201.Outputs = L2_10202
  L2_10202 = L1_10201.Outputs
  L2_10202.HackSuccess = "bool"
  L2_10202 = L1_10201.Outputs
  L2_10202.HackFail = "bool"
end
ArkMakeHackable = L0_10088
function L0_10088(A0_10207)
  local L1_10208, L2_10209, L3_10210
  L1_10208 = A0_10207.Properties
  L2_10209 = {}
  L2_10209.es_ContainerSize = ""
  L2_10209.bPreventStorage = false
  L3_10210 = {}
  L3_10210.anim_open = ""
  L3_10210.anim_close = ""
  L2_10209.Animation = L3_10210
  L3_10210 = {}
  L3_10210.audioTrigger_Open = ""
  L3_10210.audioTrigger_Close = ""
  L2_10209.Sound = L3_10210
  L1_10208.ContainerInfo = L2_10209
  L1_10208 = {}
  L2_10209 = {}
  L1_10208.listeners = L2_10209
  L1_10208.m_bSearched = false
  L1_10208.m_bEmpty = false
  L1_10208.m_lastState = false
  A0_10207.Container = L1_10208
  L1_10208 = A0_10207.PropertiesInstance
  if not L1_10208 then
    L1_10208 = {}
    A0_10207.PropertiesInstance = L1_10208
  end
  L1_10208 = A0_10207.PropertiesInstance
  L1_10208.loottable_ContainerLootTable = ""
  function L1_10208(A0_10211)
    local L1_10212
    L1_10212 = A0_10211.inventory
    if L1_10212 == nil then
      L1_10212 = CryAction
      L1_10212 = L1_10212.AcquireExtensionForGameObject
      L1_10212(A0_10211.id, "ArkInventory")
      L1_10212 = CryAction
      L1_10212 = L1_10212.ActivateExtensionForGameObject
      L1_10212(A0_10211.id, "ArkInventory", true)
      L1_10212 = INVENTORY_SIZE_MEDIUM
      if A0_10211.Properties.ContainerInfo.es_ContainerSize == "LARGE" then
        L1_10212 = INVENTORY_SIZE_LARGE
      elseif A0_10211.Properties.ContainerInfo.es_ContainerSize == "SMALL" then
        L1_10212 = INVENTORY_SIZE_SMALL
      elseif A0_10211.Properties.ContainerInfo.es_ContainerSize == "TINY" then
        L1_10212 = INVENTORY_SIZE_TINY
      end
      A0_10211.inventory:SetDimensions(L1_10212)
      A0_10211.inventory:SetPreventStorage(A0_10211.Properties.ContainerInfo.bPreventStorage)
      A0_10211.Container.m_bSearched = false
    end
  end
  A0_10207.InitInventory = L1_10208
  function L1_10208(A0_10213, A1_10214, A2_10215, A3_10216)
    local L4_10217
    L4_10217 = math
    L4_10217 = L4_10217.random
    L4_10217 = L4_10217(A2_10215, A3_10216)
    if L4_10217 > 0 then
      ItemSystem.GiveItem(A1_10214, A0_10213:GetRawId(), L4_10217)
    end
  end
  A0_10207.SpawnLootInside = L1_10208
  function L1_10208(A0_10218)
    Ark.SpawnLootFromTable(A0_10218.PropertiesInstance.loottable_ContainerLootTable, A0_10218.id)
  end
  A0_10207.SpawnLootFromTable = L1_10208
  function L1_10208(A0_10219)
    A0_10219:PlaySFX(A0_10219.Properties.ContainerInfo.Sound.audioTrigger_Open)
    Ark.OpenExternalInventory(A0_10219.id)
    A0_10219.Container.m_bSearched = true
    BroadcastEvent(A0_10219, "OnOpen")
  end
  A0_10207.OpenExternalInventory = L1_10208
  function L1_10208(A0_10220)
    A0_10220.Container.m_bEmpty = A0_10220.inventory:IsEmpty()
    A0_10220:PlaySFX(A0_10220.Properties.ContainerInfo.Sound.audioTrigger_Close)
    for _FORV_4_, _FORV_5_ in pairs(A0_10220.Container.listeners) do
      _FORV_5_:OnMyContainerClose()
    end
    A0_10220.Container.listeners = {}
  end
  A0_10207.OnCloseInventory = L1_10208
  function L1_10208(A0_10221, A1_10222)
  end
  A0_10207.OnQuickLooted = L1_10208
  function L1_10208(A0_10223, A1_10224)
    table.insert(A0_10223.Container.listeners, A1_10224)
  end
  A0_10207.RegisterListenerForOnMyContainerClose = L1_10208
  function L1_10208(A0_10225)
    return A0_10225.Container.m_bSearched
  end
  A0_10207.IsSearched = L1_10208
  function L1_10208(A0_10226)
    local L1_10227
    L1_10227 = A0_10226.Container
    L1_10227 = L1_10227.m_bEmpty
    if L1_10227 then
      L1_10227 = A0_10226.Container
      L1_10227 = L1_10227.m_bSearched
    end
    return L1_10227
  end
  A0_10207.IsEmpty = L1_10208
  function L1_10208(A0_10228)
    local L1_10229
    L1_10229 = A0_10228.Container
    L1_10229.m_bSearched = false
    L1_10229 = A0_10228.Container
    L1_10229.m_bEmpty = false
  end
  A0_10207.ResetContainer = L1_10208
  function L1_10208(A0_10230, A1_10231)
    local L2_10232
    if A1_10231 ~= "" then
      L2_10232 = Sound
      L2_10232 = L2_10232.GetAudioTriggerID
      L2_10232 = L2_10232(A1_10231)
      g_localActor:ExecuteAudioTrigger(L2_10232, A0_10230:GetDefaultAuxAudioProxyID())
    end
  end
  A0_10207.PlaySFX = L1_10208
end
ArkMakeContainer = L0_10088
function L0_10088(A0_10233)
  local L1_10234
  L1_10234 = {}
  A0_10233.ShadowCasterTypeFilter = L1_10234
  L1_10234 = A0_10233.ShadowCasterTypeFilter
  for _FORV_5_, _FORV_6_ in pairs(g_ShadowCasterTypeFilters) do
    L1_10234[_FORV_5_] = 1
  end
end
SetupShadowCasterTypeFiltering = L0_10088
function L0_10088(A0_10235)
  local L1_10236, L2_10237
  L1_10236 = 0
  L2_10237 = A0_10235.ShadowCasterTypeFilter
  for _FORV_6_, _FORV_7_ in pairs(L2_10237) do
    if g_ShadowCasterTypeFilters[_FORV_6_] ~= nil and _FORV_7_ == 1 then
      L1_10236 = L1_10236 + g_ShadowCasterTypeFilters[_FORV_6_]
    end
  end
  return L1_10236
end
GetShadowCasterTypeFiltering = L0_10088
