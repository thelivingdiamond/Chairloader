if not Tweaks then
  Tweaks = {}
end
if not Tweaks.Scratchpad then
  Tweaks.Scratchpad = {
    SAVEVALUES = false,
    FORCESAVE = false,
    SAVEONEXIT = false,
    RELOADVALUES = true,
    APPLYPROFILE = false,
    WARNCHANGES = true,
    DEBUG = false,
    BLACKBACKGROUND = true,
    BLACKBACKGROUNDALPHA = 0.7,
    MENUACTIVE = false,
    VALUESLASTSAVED = {asString = "Not saved", timestampTable = nil},
    REPEATRATE = 0.2,
    REPEATDELAY = 0.4,
    FONTSIZE = 1.5,
    VERTSPACE = 24,
    MOTD = false,
    SHOWHIDDEN = false,
    AINOUPDATE = false
  }
end
function Tweaks.Scratchpad.VALUESLASTSAVED.UpdateTimestamp()
  local L0_10459, L1_10460, L2_10461
  L0_10459 = Tweaks
  L0_10459 = L0_10459.Scratchpad
  L0_10459 = L0_10459.VALUESLASTSAVED
  L1_10460 = L0_10459.timestampTable
  if not L1_10460 then
    L1_10460 = {}
    L0_10459.timestampTable = L1_10460
  end
  L1_10460 = L0_10459.timestampTable
  for _FORV_5_, _FORV_6_ in L2_10461(System.GetLocalOSTime()) do
    L1_10460[_FORV_5_] = _FORV_6_
  end
  L0_10459.asString = string.format("Profile %s on %d/%d/%d at %02d:%02d", L2_10461, L1_10460.mday, L1_10460.mon, L1_10460.year + 1900, L1_10460.hour, L1_10460.min)
end
if not Tweaks.State then
  Tweaks.State = {
    g_TweakProfile = {},
    RELOADVALUES = {}
  }
end
function Tweaks.State.InitFeedbackTimer(A0_10462, A1_10463)
  A0_10462.time = System.GetLocalOSTime().sec
  A0_10462.duration = A1_10463
end
function Tweaks.State.CheckFeedbackTimer(A0_10464)
  if A0_10464.time then
    if (System.GetLocalOSTime().sec - A0_10464.time) % 60 <= A0_10464.duration then
      return true
    else
      A0_10464.time = nil
      A0_10464.duration = nil
      return false
    end
  end
end
if not Tweaks.Menus then
  Tweaks.Menus = {MENU = "Tweak Menu"}
end
if not Tweaks.Saving then
  Tweaks.Saving = {
    Saved = {},
    Temp = {},
    Defaults = {},
    Diff = {},
    Profiles = {},
    SaveDump = {}
  }
end
function Tweaks.Saving.GetSaveValues()
  local L0_10465, L1_10466, L2_10467, L3_10468, L4_10469, L5_10470, L6_10471, L7_10472, L8_10473, L9_10474, L10_10475, L11_10476, L12_10477, L13_10478
  L0_10465 = Tweaks
  L0_10465 = L0_10465.Saving
  L1_10466 = {}
  L0_10465.Saved = L1_10466
  L0_10465 = Tweaks
  L0_10465 = L0_10465.Saving
  L1_10466 = {}
  L0_10465.Temp = L1_10466
  L0_10465 = Tweaks
  L0_10465 = L0_10465.Saving
  L1_10466 = {}
  L0_10465.Diff = L1_10466
  L0_10465 = Tweaks
  L0_10465 = L0_10465.Saving
  L0_10465 = L0_10465.CollectValues
  L1_10466 = Tweaks
  L1_10466 = L1_10466.Menus
  L2_10467 = Tweaks
  L2_10467 = L2_10467.Saving
  L2_10467 = L2_10467.Temp
  L0_10465(L1_10466, L2_10467)
  L0_10465 = FlattenTree
  L1_10466 = Tweaks
  L1_10466 = L1_10466.Saving
  L1_10466 = L1_10466.Temp
  L2_10467 = Tweaks
  L2_10467 = L2_10467.Saving
  L2_10467 = L2_10467.Saved
  L0_10465(L1_10466, L2_10467, L3_10468)
  L0_10465 = Tweaks
  L0_10465 = L0_10465.Scratchpad
  L0_10465 = L0_10465.FORCESAVE
  if L0_10465 == true then
    L0_10465 = TableDifferenceRecursive
    L1_10466 = Tweaks
    L1_10466 = L1_10466.Saving
    L1_10466 = L1_10466.Saved
    L2_10467 = {}
    L0_10465(L1_10466, L2_10467, L3_10468)
    L0_10465 = Tweaks
    L0_10465 = L0_10465.Scratchpad
    L0_10465.FORCESAVE = false
  else
    L0_10465 = System
    L0_10465 = L0_10465.GetCVar
    L1_10466 = "g_TweakProfile"
    L0_10465 = L0_10465(L1_10466)
    L1_10466 = Tweaks
    L1_10466 = L1_10466.Saving
    L1_10466 = L1_10466.Profiles
    L1_10466 = L1_10466[L0_10465]
    if not L1_10466 then
      L2_10467 = Tweaks
      L2_10467 = L2_10467.Saving
      L2_10467 = L2_10467.Profiles
      L2_10467[L0_10465] = L3_10468
      L2_10467 = Tweaks
      L2_10467 = L2_10467.Saving
      L2_10467 = L2_10467.Profiles
      L1_10466 = L2_10467[L0_10465]
    end
    L2_10467 = TableDifferenceRecursive
    L2_10467(L3_10468, L4_10469, L5_10470)
  end
  L0_10465 = Tweaks
  L0_10465 = L0_10465.Saving
  L1_10466 = {}
  L0_10465.SaveDump = L1_10466
  L0_10465 = System
  L0_10465 = L0_10465.GetLocalOSTime
  L0_10465 = L0_10465()
  L1_10466 = string
  L1_10466 = L1_10466.format
  L2_10467 = "--By %s on %d/%d/%d at %02d:%02d\n"
  L6_10471 = L0_10465.year
  L6_10471 = L6_10471 + 1900
  L7_10472 = L0_10465.hour
  L8_10473 = L0_10465.min
  L1_10466 = L1_10466(L2_10467, L3_10468, L4_10469, L5_10470, L6_10471, L7_10472, L8_10473)
  L2_10467 = {}
  for L6_10471, L7_10472 in L3_10468(L4_10469) do
    L8_10473 = DumpTableAsLuaString
    L12_10477 = L6_10471
    L8_10473 = L8_10473(L9_10474, L10_10475, L11_10476)
    L2_10467[L6_10471] = L8_10473
  end
  for L6_10471, L7_10472 in L3_10468(L4_10469) do
    L8_10473 = Tweaks
    L8_10473 = L8_10473.Saving
    L8_10473 = L8_10473.Diff
    L8_10473 = L8_10473[L6_10471]
    if L8_10473 then
      L8_10473 = "--[[ State of other Tweaks at time of save was as follows:\n\n"
      for L12_10477, L13_10478 in L9_10474(L10_10475) do
        if L6_10471 ~= L12_10477 then
          L8_10473 = L8_10473 .. L13_10478 .. "\n"
        end
      end
      L12_10477 = L8_10473
      L13_10478 = "]]"
      L9_10474[L6_10471] = L10_10475
    end
  end
end
function Tweaks.Saving.GetDefaultValues()
  local L0_10479
  L0_10479 = Tweaks
  L0_10479 = L0_10479.Saving
  L0_10479.Defaults = {}
  L0_10479 = {}
  Tweaks.Saving.CollectValues(Tweaks.Menus, L0_10479)
  FlattenTree(L0_10479, Tweaks.Saving.Defaults, "tweakssave")
end
function Tweaks.Saving.PrepareProfiles()
  local L0_10480, L1_10481, L2_10482, L3_10483, L4_10484
  for L3_10483, L4_10484 in L0_10480(L1_10481) do
    TableAddRecursive(Tweaks.Saving.Defaults, L4_10484)
    TableIntersectKeysRecursive(Tweaks.Saving.Defaults, L4_10484)
  end
end
function Tweaks.Saving.CollectValues(A0_10485, A1_10486)
  local L2_10487, L3_10488, L4_10489, L5_10490, L6_10491
  for L5_10490, L6_10491 in L2_10487(L3_10488) do
    if type(L6_10491) == "table" then
      if L6_10491.MENU then
        if L6_10491.FILE then
          if not A1_10486[L6_10491.FILE] then
            A1_10486[L6_10491.FILE] = {}
          end
          Tweaks.Saving.CollectValues(L6_10491, A1_10486[L6_10491.FILE])
        else
          Tweaks.Saving.CollectValues(L6_10491, A1_10486)
        end
      elseif L6_10491.NAME and not L6_10491.NOSAVE then
        if L6_10491.LUA then
          A1_10486[L6_10491.LUA] = GetValueRecursive(L6_10491.LUA)
        elseif L6_10491.CVAR and L6_10491.CVAR ~= "" then
          A1_10486[L6_10491.CVAR] = System.GetCVar(L6_10491.CVAR)
        end
      end
    end
  end
end
function Tweaks.Saving.SaveComplete()
  Tweaks.Scratchpad.VALUESLASTSAVED.UpdateTimestamp()
  Tweaks.Saving.Profiles[System.GetCVar("g_TweakProfile")] = Tweaks.Saving.Saved
end
function Tweaks.Saving.SaveFailed(A0_10492)
  local L1_10493
  L1_10493 = Tweaks
  L1_10493 = L1_10493.Scratchpad
  L1_10493 = L1_10493.VALUESLASTSAVED
  L1_10493.asString = A0_10492
end
function Tweaks.ReloadStructure()
  Script.LoadScript("Scripts/Tweaks.lua", true, true)
end
Tweaks.Scratchpad.RELOAD = true
Script.ReloadScript("Scripts/SaveUtils.lua")
