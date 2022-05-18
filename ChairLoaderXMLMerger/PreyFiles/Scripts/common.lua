g_SignalData_point = {
  x = 0,
  y = 0,
  z = 0
}
g_SignalData_point2 = {
  x = 0,
  y = 0,
  z = 0
}
g_SignalData = {
  point = g_SignalData_point,
  point2 = g_SignalData_point2,
  ObjectName = "",
  id = NULL_ENTITY,
  fValue = 0,
  iValue = 0,
  iValue2 = 0
}
g_StringTemp1 = "                                            "
g_HitTable = {
  {},
  {},
  {},
  {},
  {},
  {},
  {},
  {},
  {},
  {}
}
function ShowTime()
  System.Log(string.format("%d/%d/%d, %02d:%02d", System.GetLocalOSTime().mday, System.GetLocalOSTime().mon + 1, System.GetLocalOSTime().year + 1900, System.GetLocalOSTime().hour, System.GetLocalOSTime().min))
end
function count(A0_10238)
  if A0_10238 then
    for _FORV_5_, _FORV_6_ in pairs(A0_10238) do
    end
  end
  return 0 + 1
end
function new(A0_10239, A1_10240)
  local L2_10241, L3_10242, L4_10243, L5_10244, L6_10245, L7_10246
  L2_10241 = type
  L2_10241 = L2_10241(L3_10242)
  if L2_10241 == "table" then
    L2_10241 = {}
    if A1_10240 then
      for L6_10245, L7_10246 in L3_10242(L4_10243) do
        L2_10241[L6_10245] = L7_10246
      end
    else
      for L6_10245, L7_10246 in L3_10242(L4_10243) do
        if type(L7_10246) == "table" and A0_10239 ~= L7_10246 then
          L2_10241[L6_10245] = new(L7_10246)
        else
          L2_10241[L6_10245] = L7_10246
        end
      end
    end
    return L2_10241
  else
    return A0_10239
  end
end
function merge(A0_10247, A1_10248, A2_10249)
  local L3_10250, L4_10251, L5_10252, L6_10253, L7_10254
  for L6_10253, L7_10254 in L3_10250(L4_10251) do
    if type(L7_10254) ~= "function" then
      if A2_10249 then
        if type(L7_10254) == "table" and L7_10254 ~= A1_10248 then
          if A0_10247[L6_10253] == nil then
            A0_10247[L6_10253] = {}
          end
          merge(A0_10247[L6_10253], L7_10254, A2_10249)
        elseif A0_10247[L6_10253] == nil then
          A0_10247[L6_10253] = L7_10254
        end
      elseif A0_10247[L6_10253] == nil then
        A0_10247[L6_10253] = L7_10254
      end
    end
  end
  return A0_10247
end
function mergef(A0_10255, A1_10256, A2_10257)
  local L3_10258, L4_10259, L5_10260, L6_10261, L7_10262
  for L6_10261, L7_10262 in L3_10258(L4_10259) do
    if A2_10257 then
      if type(L7_10262) == "table" and L7_10262 ~= A1_10256 then
        if A0_10255[L6_10261] == nil then
          A0_10255[L6_10261] = {}
        end
        mergef(A0_10255[L6_10261], L7_10262, A2_10257)
      elseif A0_10255[L6_10261] == nil then
        A0_10255[L6_10261] = L7_10262
      end
    elseif A0_10255[L6_10261] == nil then
      A0_10255[L6_10261] = L7_10262
    end
  end
  return A0_10255
end
function Vec2Str(A0_10263)
  return string.format("(x: %.3f y: %.3f z: %.3f)", A0_10263.x, A0_10263.y, A0_10263.z)
end
function LogError(A0_10264, ...)
  System.LogError("$4" .. string.format(A0_10264, ...))
end
function LogWarning(A0_10266, ...)
  System.LogWarning("$6" .. string.format(A0_10266, ...))
end
function LogComment(A0_10268, ...)
  System.LogComment("$3" .. string.format(A0_10268, ...))
end
function Log(A0_10270, ...)
  local L4_10272, L5_10273
  L4_10272 = System
  L4_10272 = L4_10272.Log
  L5_10273 = string
  L5_10273 = L5_10273.format
  L5_10273 = L5_10273(A0_10270, ...)
  L4_10272(L5_10273, L5_10273(A0_10270, ...))
end
g_dump_tabs = 0
function dump(A0_10274, A1_10275, A2_10276)
  local L3_10277, L4_10278, L5_10279, L6_10280, L7_10281, L8_10282
  if not A0_10274 then
    L3_10277 = System
    L3_10277 = L3_10277.Log
    L3_10277(L4_10278)
  else
    A2_10276 = A2_10276 or 8
    L3_10277 = ""
    for L7_10281 = 0, g_dump_tabs do
      L8_10282 = L3_10277
      L3_10277 = L8_10282 .. "  "
    end
    for L7_10281, L8_10282 in L4_10278(L5_10279) do
      if type(L8_10282) == "table" then
        if A2_10276 > g_dump_tabs then
          g_dump_tabs = g_dump_tabs + 1
          System.Log(L3_10277 .. "$4" .. tostring(L7_10281) .. "$1= {")
          dump(L8_10282, A1_10275, A2_10276)
          System.Log(L3_10277 .. "$1}")
          g_dump_tabs = g_dump_tabs - 1
        else
          System.Log(L3_10277 .. "$4" .. tostring(L7_10281) .. "$1= { $4...$1 }")
        end
      elseif type(L8_10282) == "number" then
        System.Log("$2" .. L3_10277 .. "$6" .. tostring(L7_10281) .. "$1=$8" .. L8_10282)
      elseif type(L8_10282) == "string" then
        System.Log("$2" .. L3_10277 .. "$6" .. tostring(L7_10281) .. "$1=$8" .. "\"" .. L8_10282 .. "\"")
      elseif type(L8_10282) == "boolean" then
        System.Log("$2" .. L3_10277 .. "$6" .. tostring(L7_10281) .. "$1=$8" .. "\"" .. tostring(L8_10282) .. "\"")
      elseif not A1_10275 then
        if type(L8_10282) == "function" then
          System.Log("$2" .. L3_10277 .. "$5" .. tostring(L7_10281) .. "()")
        else
          System.Log("$2" .. L3_10277 .. "$7" .. tostring(L7_10281) .. "$8<userdata>")
        end
      end
    end
  end
end
function EmptyString(A0_10283)
  if A0_10283 and string.len(A0_10283) > 0 then
    return false
  end
  return true
end
function NumberToBool(A0_10284)
  if A0_10284 and tonumber(A0_10284) ~= 0 then
    return true
  else
    return false
  end
end
function EntityName(A0_10285)
  if type(A0_10285) == "userdata" then
    if System.GetEntity(A0_10285) then
      return System.GetEntity(A0_10285):GetName()
    end
  elseif type(A0_10285) == "table" then
    return A0_10285:GetName()
  end
  return ""
end
function EntityNamed(A0_10286)
  return System.GetEntityByName(A0_10286)
end
function SafeTableGet(A0_10287, A1_10288)
  local L2_10289
  if A0_10287 then
    L2_10289 = A0_10287[A1_10288]
    return L2_10289
  else
    L2_10289 = nil
    return L2_10289
  end
end
Script.ReloadScript("scripts/Utils/Containers.lua")
Script.ReloadScript("scripts/Utils/Math.lua")
Script.ReloadScript("scripts/Utils/EntityUtils.lua")
Script.ReloadScript("scripts/Utils/ZeroG.lua")
g_AIDebugToggleOn = 0
function AIDebugToggle()
  if g_AIDebugToggleOn == 0 then
    g_AIDebugToggleOn = 1
    System.SetCVar("ai_DebugDraw", 1)
  else
    System.SetCVar("ai_DebugDraw", 0)
    g_AIDebugToggleOn = 0
  end
end
Script.ReloadScript("scripts/entities/items/itemsystemmath.lua")
function RemoveFromTable(A0_10290, A1_10291)
  local L2_10292, L3_10293, L4_10294, L5_10295
  for L5_10295, _FORV_6_ in L2_10292(L3_10293) do
    if _FORV_6_ == A1_10291 then
      table.remove(A0_10290, L5_10295)
      break
    end
  end
end
function InsertIntoTable(A0_10296, A1_10297)
  for _FORV_6_, _FORV_7_ in ipairs(A0_10296) do
    if _FORV_7_ == A1_10297 then
      break
    end
  end
  if not true then
    table.insert(A0_10296, A1_10297)
  end
end
function IsInsideTable(A0_10298, A1_10299)
  for _FORV_5_, _FORV_6_ in ipairs(A0_10298) do
    if _FORV_6_ == A1_10299 then
      return true
    end
  end
  return false
end
function SafeKillTimer(A0_10300)
  if A0_10300 then
    Script.KillTimer(A0_10300)
  end
end
