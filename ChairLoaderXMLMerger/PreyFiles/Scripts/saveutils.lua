CI_NEWTABLE = 1
CI_ENDTABLE = 2
CI_STRING = 3
CI_NUMBER = 4
function WriteIndex(A0_10307, A1_10308)
  if type(A1_10308) == "number" then
    A0_10307:WriteBool(1)
    A0_10307:WriteInt(A1_10308)
  elseif type(A1_10308) == "string" then
    A0_10307:WriteBool(nil)
    A0_10307:WriteString(A1_10308)
  else
    System.Log("Unrecognized idx type")
  end
end
function ReadIndex(A0_10309)
  if A0_10309:ReadBool() then
    return A0_10309:ReadInt()
  else
    return A0_10309:ReadString()
  end
end
function WriteToStream(A0_10310, A1_10311, A2_10312)
  local L3_10313, L4_10314, L5_10315, L6_10316, L7_10317
  if A2_10312 == nil then
    A2_10312 = "__root__"
  end
  if L3_10313 == "table" then
    L3_10313(L4_10314, L5_10315)
    L3_10313(L4_10314, L5_10315)
    for L6_10316, L7_10317 in L3_10313(L4_10314) do
      WriteToStream(A0_10310, L7_10317, L6_10316)
    end
    L3_10313(L4_10314, L5_10315)
  elseif L3_10313 == "string" then
    L6_10316 = CI_STRING
    L4_10314(L5_10315, L6_10316)
    L6_10316 = A2_10312
    L4_10314(L5_10315, L6_10316)
    L6_10316 = A1_10311
    L4_10314(L5_10315, L6_10316)
  elseif L3_10313 == "number" then
    L6_10316 = CI_NUMBER
    L4_10314(L5_10315, L6_10316)
    L6_10316 = A2_10312
    L4_10314(L5_10315, L6_10316)
    L6_10316 = A1_10311
    L4_10314(L5_10315, L6_10316)
  end
end
function ReadFromStream(A0_10318, A1_10319)
  local L2_10320, L3_10321, L4_10322
  L3_10321 = A0_10318
  L2_10320 = A0_10318.ReadByte
  L2_10320 = L2_10320(L3_10321)
  L3_10321, L4_10322 = nil, nil
  if L2_10320 ~= CI_ENDTABLE then
    L3_10321 = ReadIndex(A0_10318)
    if L2_10320 == CI_NEWTABLE then
      L4_10322 = {}
      while true do
        if ReadFromStream(A0_10318, L4_10322) ~= CI_ENDTABLE then
        end
      end
      if A1_10319 then
        A1_10319[L3_10321] = L4_10322
      end
    elseif L2_10320 == CI_STRING then
      A1_10319[L3_10321] = A0_10318:ReadString()
    elseif L2_10320 == CI_NUMBER then
      A1_10319[L3_10321] = A0_10318:ReadFloat()
    end
  end
  if A1_10319 == nil then
    return L4_10322
  else
    return L2_10320
  end
end
StringStream = {
  buffer = "",
  New = function()
    local L0_10323
    L0_10323 = {}
    for _FORV_4_, _FORV_5_ in pairs(StringStream) do
      L0_10323[_FORV_4_] = _FORV_5_
    end
    L0_10323.buffer = ""
    return L0_10323
  end,
  Write = function(A0_10324, A1_10325)
    A0_10324.buffer = A0_10324.buffer .. A1_10325
  end,
  WriteLine = function(A0_10326, A1_10327)
    A0_10326.buffer = A0_10326.buffer .. A1_10327 .. "\n"
  end,
  WriteValue = function(A0_10328, A1_10329)
    local L2_10330
    L2_10330 = type
    L2_10330 = L2_10330(A1_10329)
    if L2_10330 == "number" then
      A0_10328.buffer = A0_10328.buffer .. A1_10329
    elseif L2_10330 == "string" then
      A0_10328.buffer = A0_10328.buffer .. "\"" .. A1_10329 .. "\""
    elseif L2_10330 == "boolean" then
      A0_10328.buffer = A0_10328.buffer .. (A1_10329 and "true" or "false")
    elseif L2_10330 == "table" or L2_10330 == "function" then
      A0_10328.buffer = A0_10328.buffer .. "[" .. tostring(A1_10329) .. "]"
    else
      A0_10328.buffer = A0_10328.buffer .. "Unrecognised type " .. L2_10330
    end
  end,
  WriteIndex = function(A0_10331, A1_10332)
    local L2_10333
    L2_10333 = type
    L2_10333 = L2_10333(A1_10332)
    if L2_10333 == "number" then
      A0_10331.buffer = A0_10331.buffer .. "[" .. A1_10332 .. "]"
    elseif L2_10333 == "string" then
      A0_10331.buffer = A0_10331.buffer .. "[\"" .. A1_10332 .. "\"]"
    else
      A0_10331.buffer = A0_10331.buffer .. "Unrecognised type " .. L2_10333
    end
  end,
  Reset = function(A0_10334)
    local L1_10335
    A0_10334.buffer = ""
  end
}
LuaDumpRecursionTable = Set.New()
function DumpTableAsLua(A0_10336, A1_10337, A2_10338, A3_10339, A4_10340)
  local L5_10341, L6_10342, L7_10343, L8_10344, L9_10345, L10_10346, L11_10347, L12_10348, L13_10349, L14_10350, L15_10351
  A4_10340 = A4_10340 or 0
  L5_10341 = string
  L5_10341 = L5_10341.rep
  L6_10342 = "  "
  L7_10343 = A4_10340
  L5_10341 = L5_10341(L6_10342, L7_10343)
  L7_10343 = A2_10338
  L6_10342 = A2_10338.WriteLine
  L8_10344 = L5_10341
  L9_10345 = "--Automatically dumped LUA table"
  L8_10344 = L8_10344 .. L9_10345
  L6_10342(L7_10343, L8_10344)
  L7_10343 = A2_10338
  L6_10342 = A2_10338.WriteLine
  L8_10344 = L5_10341
  L9_10345 = A1_10337
  L10_10346 = " = {"
  L8_10344 = L8_10344 .. L9_10345 .. L10_10346
  L6_10342(L7_10343, L8_10344)
  L6_10342 = A4_10340 + 2
  L7_10343 = string
  L7_10343 = L7_10343.rep
  L8_10344 = "  "
  L9_10345 = L6_10342
  L7_10343 = L7_10343(L8_10344, L9_10345)
  L8_10344 = {}
  L9_10345 = 1
  L10_10346 = StringStream
  L10_10346 = L10_10346.New
  L10_10346 = L10_10346(L11_10347)
  for L14_10350, L15_10351 in L11_10347(L12_10348) do
    if type(L15_10351) == "table" and A3_10339 and Set.Add(LuaDumpRecursionTable, L15_10351) then
      if type(L14_10350) == "table" then
        L14_10350 = "[Table]"
      end
      DumpTableAsLua(L15_10351, L14_10350, A2_10338, A3_10339, L6_10342)
    else
      L10_10346:Write(L7_10343)
      L10_10346:WriteIndex(L14_10350)
      L10_10346:Write(" = ")
      L10_10346:WriteValue(L15_10351)
      L10_10346:Write(",")
      L8_10344[L9_10345] = L10_10346.buffer
      L9_10345 = L9_10345 + 1
      L10_10346:Reset()
    end
  end
  L11_10347(L12_10348)
  for L14_10350, L15_10351 in L11_10347(L12_10348) do
    A2_10338:WriteLine(L15_10351)
  end
  if A4_10340 == 0 then
    L14_10350 = "}"
    L11_10347(L12_10348, L13_10349)
  else
    L14_10350 = "},"
    L11_10347(L12_10348, L13_10349)
  end
end
function DumpTableAsLuaString(A0_10352, A1_10353, A2_10354)
  StringStream:Reset()
  Set.RemoveAll(LuaDumpRecursionTable)
  DumpTableAsLua(A0_10352, A1_10353, StringStream, A2_10354)
  Set.RemoveAll(LuaDumpRecursionTable)
  return StringStream.buffer
end
function TableDifference(A0_10355, A1_10356, A2_10357)
  table.foreach(A0_10355, function(A0_10358, A1_10359)
    local L2_10360, L3_10361
    L2_10360 = _UPVALUE0_
    L2_10360 = L2_10360[A0_10358]
    L3_10361 = A1_10359
    if L2_10360 ~= L3_10361 and tostring(L2_10360) ~= tostring(L3_10361) then
      _UPVALUE1_[A0_10358] = A1_10359
    end
  end)
end
function TableDifferenceRecursive(A0_10362, A1_10363, A2_10364)
  local L3_10365, L4_10366, L5_10367, L6_10368, L7_10369, L8_10370, L9_10371
  for L6_10368, L7_10369 in L3_10365(L4_10366) do
    L8_10370 = type
    L9_10371 = L7_10369
    L8_10370 = L8_10370(L9_10371)
    if L8_10370 == "table" then
      L8_10370 = {}
      A2_10364[L6_10368] = L8_10370
      L8_10370 = A1_10363[L6_10368]
      if L8_10370 then
        L8_10370 = TableDifferenceRecursive
        L9_10371 = L7_10369
        L8_10370(L9_10371, A1_10363[L6_10368], A2_10364[L6_10368])
        L8_10370 = pairs
        L9_10371 = A2_10364[L6_10368]
        L8_10370 = L8_10370(L9_10371)
        L9_10371 = A2_10364[L6_10368]
        L8_10370 = L8_10370(L9_10371)
        if not L8_10370 then
          A2_10364[L6_10368] = nil
        end
      else
        L8_10370 = table
        L8_10370 = L8_10370.foreach
        L9_10371 = L7_10369
        L8_10370(L9_10371, function(A0_10372, A1_10373)
          local L2_10374
          L2_10374 = _UPVALUE0_
          L2_10374 = L2_10374[_UPVALUE1_]
          L2_10374[A0_10372] = A1_10373
        end)
      end
    else
      L8_10370 = A1_10363[L6_10368]
      L9_10371 = L7_10369
      if L8_10370 ~= L9_10371 and tostring(L8_10370) ~= tostring(L9_10371) then
        A2_10364[L6_10368] = L7_10369
      end
    end
  end
end
function TableAdd(A0_10375, A1_10376)
  for _FORV_5_, _FORV_6_ in pairs(A0_10375) do
    if A1_10376[_FORV_5_] == nil then
      A1_10376[_FORV_5_] = _FORV_6_
    end
  end
end
function TableAddRecursive(A0_10377, A1_10378)
  local L2_10379, L3_10380, L4_10381, L5_10382, L6_10383
  for L5_10382, L6_10383 in L2_10379(L3_10380) do
    if A1_10378[L5_10382] == nil then
      if type(L6_10383) == "table" then
        A1_10378[L5_10382] = {}
        TableAddRecursive(L6_10383, A1_10378[L5_10382])
      else
        A1_10378[L5_10382] = L6_10383
      end
    elseif type(L6_10383) == "table" and type(A1_10378[L5_10382]) == "table" then
      TableAddRecursive(L6_10383, A1_10378[L5_10382])
    end
  end
end
function TableIntersectKeys(A0_10384, A1_10385)
  for _FORV_5_, _FORV_6_ in pairs(A1_10385) do
    if A0_10384[_FORV_5_] == nil then
      A1_10385[_FORV_5_] = nil
    end
  end
end
function TableIntersectKeysRecursive(A0_10386, A1_10387)
  local L2_10388, L3_10389, L4_10390, L5_10391, L6_10392
  for L5_10391, L6_10392 in L2_10388(L3_10389) do
    if A0_10386[L5_10391] == nil then
      A1_10387[L5_10391] = nil
    elseif type(A0_10386[L5_10391]) == "table" and type(L6_10392) == "table" then
      TableIntersectKeysRecursive(A0_10386[L5_10391], L6_10392)
    end
  end
end
function TableAddRecursive(A0_10393, A1_10394)
  local L2_10395, L3_10396, L4_10397, L5_10398, L6_10399
  for L5_10398, L6_10399 in L2_10395(L3_10396) do
    if not A1_10394[L5_10398] then
      if type(L6_10399) == "table" then
        A1_10394[L5_10398] = {}
        TableAddRecursive(L6_10399, A1_10394[L5_10398])
      else
        A1_10394[L5_10398] = L6_10399
      end
    elseif type(L6_10399) == "table" and type(A1_10394[L5_10398]) == "table" then
      TableAddRecursive(L6_10399, A1_10394[L5_10398])
    end
  end
end
function FlattenTree(A0_10400, A1_10401, A2_10402)
  A2_10402 = A2_10402 or "Root"
  A1_10401[A2_10402] = {}
  FlattenSubTree(A0_10400, A1_10401, A1_10401[A2_10402])
end
function FlattenSubTree(A0_10403, A1_10404, A2_10405)
  table.foreach(A0_10403, function(A0_10406, A1_10407)
    if type(A1_10407) == "table" then
      _UPVALUE0_[A0_10406] = {}
      FlattenSubTree(A1_10407, _UPVALUE0_, _UPVALUE0_[A0_10406])
    else
      _UPVALUE1_[A0_10406] = A1_10407
    end
  end)
end
function BreakUpHugeString(A0_10408, A1_10409, A2_10410)
  local L3_10411, L4_10412, L5_10413, L6_10414, L7_10415, L8_10416
  A1_10409 = A1_10409 or 128
  A2_10410 = A2_10410 or 256
  L3_10411 = {}
  L4_10412 = 1
  L5_10413 = string
  L5_10413 = L5_10413.len
  L6_10414 = A0_10408
  L5_10413 = L5_10413(L6_10414)
  L6_10414 = 1
  L7_10415 = L4_10412
  while L4_10412 < L5_10413 do
    L8_10416 = string
    L8_10416 = L8_10416.find
    L8_10416 = L8_10416(A0_10408, "\n", L4_10412, true)
    L8_10416 = L8_10416 or L5_10413
    if A2_10410 < L8_10416 - L7_10415 then
      L8_10416 = L7_10415 + A2_10410
    end
    if A1_10409 < L8_10416 - L7_10415 or L8_10416 == L5_10413 then
      L3_10411[L6_10414] = string.sub(A0_10408, L7_10415, L8_10416)
      L6_10414 = L6_10414 + 1
      L7_10415 = L8_10416 + 1
    end
    L4_10412 = L8_10416 + 1
  end
  return L3_10411
end
function LogTable(A0_10417, A1_10418, A2_10419)
  local L3_10420, L4_10421, L5_10422, L6_10423, L7_10424, L8_10425, L9_10426
  A1_10418 = A1_10418 or "DumpedTable"
  if A2_10419 == nil then
    A2_10419 = true
  end
  L3_10420 = DumpTableAsLuaString
  L4_10421 = A0_10417
  L3_10420 = L3_10420(L4_10421, L5_10422, L6_10423)
  L4_10421 = BreakUpHugeString
  L4_10421 = L4_10421(L5_10422)
  for L8_10425, L9_10426 in L5_10422(L6_10423) do
    System.Log(L9_10426)
  end
end
function GetValueRecursive(A0_10427)
  local L1_10428
  L1_10428 = loadstring
  L1_10428 = L1_10428("return " .. A0_10427)
  if L1_10428 and pcall(L1_10428) then
    return pcall(L1_10428)
  end
  return nil
end
function SetValueRecursive(A0_10429, A1_10430)
  local L2_10431
  L2_10431 = loadstring
  L2_10431 = L2_10431(A0_10429 .. " = " .. A1_10430)
  if L2_10431 then
    return L2_10431()
  end
  return nil
end
function out(...)
  local L1_10433, L2_10434
  L1_10433 = System
  if L1_10433 then
    L1_10433 = System
    L1_10433 = L1_10433.Log
    if L1_10433 then
      L1_10433 = 0
      for _FORV_5_ = 1, 10 do
        if L0_10432[_FORV_5_] ~= nil then
          L1_10433 = _FORV_5_
        end
      end
      while L1_10433 > 0 do
      end
      System.Log(L2_10434)
    end
  else
    L1_10433 = print
    if L1_10433 then
      L1_10433 = print
      L1_10433(L2_10434)
    end
  end
end
