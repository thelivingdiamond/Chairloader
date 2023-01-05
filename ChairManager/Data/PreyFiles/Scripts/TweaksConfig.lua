local L0_10439
L0_10439 = {
  {
    NAME = "Active Tweak profile:",
    CVAR = "g_TweakProfile",
    NOSAVE = true,
    EVALUATOR = function()
      local L0_10440
      L0_10440 = Tweaks
      L0_10440 = L0_10440.State
      L0_10440 = L0_10440.g_TweakProfile
      if Tweaks.State.CheckFeedbackTimer(L0_10440) then
        return "There are changes - save or revert"
      end
    end,
    INCREMENTER = function(A0_10441)
      local L1_10442, L2_10443, L3_10444, L4_10445, L5_10446, L6_10447, L7_10448, L8_10449
      L1_10442 = System
      L1_10442 = L1_10442.GetCVar
      L2_10443 = "g_TweakProfile"
      L1_10442 = L1_10442(L2_10443)
      L2_10443 = Tweaks
      L2_10443 = L2_10443.Saving
      L3_10444 = {}
      L2_10443.Temp = L3_10444
      L2_10443 = Tweaks
      L2_10443 = L2_10443.Saving
      L3_10444 = {}
      L2_10443.Diff = L3_10444
      L2_10443 = Tweaks
      L2_10443 = L2_10443.Saving
      L2_10443 = L2_10443.CollectValues
      L3_10444 = Tweaks
      L3_10444 = L3_10444.Menus
      L4_10445 = Tweaks
      L4_10445 = L4_10445.Saving
      L4_10445 = L4_10445.Temp
      L2_10443(L3_10444, L4_10445)
      L2_10443 = {}
      L3_10444 = FlattenTree
      L4_10445 = Tweaks
      L4_10445 = L4_10445.Saving
      L4_10445 = L4_10445.Temp
      L5_10446 = L2_10443
      L6_10447 = "tweakssave"
      L3_10444(L4_10445, L5_10446, L6_10447)
      L3_10444 = Tweaks
      L3_10444 = L3_10444.Saving
      L3_10444.Temp = L2_10443
      L3_10444 = Tweaks
      L3_10444 = L3_10444.Saving
      L3_10444 = L3_10444.Profiles
      L3_10444 = L3_10444[L1_10442]
      if not L3_10444 then
        L4_10445 = {}
        L3_10444 = L4_10445
      end
      L4_10445 = TableDifferenceRecursive
      L5_10446 = Tweaks
      L5_10446 = L5_10446.Saving
      L5_10446 = L5_10446.Temp
      L6_10447 = L3_10444
      L7_10448 = Tweaks
      L7_10448 = L7_10448.Saving
      L7_10448 = L7_10448.Diff
      L4_10445(L5_10446, L6_10447, L7_10448)
      L4_10445 = pairs
      L5_10446 = Tweaks
      L5_10446 = L5_10446.Saving
      L5_10446 = L5_10446.Diff
      L4_10445 = L4_10445(L5_10446)
      L5_10446 = Tweaks
      L5_10446 = L5_10446.Saving
      L5_10446 = L5_10446.Diff
      L4_10445 = L4_10445(L5_10446)
      if L4_10445 then
        L5_10446 = Tweaks
        L5_10446 = L5_10446.Scratchpad
        L5_10446 = L5_10446.WARNCHANGES
        if L5_10446 then
          L5_10446 = Tweaks
          L5_10446 = L5_10446.State
          L5_10446 = L5_10446.InitFeedbackTimer
          L6_10447 = Tweaks
          L6_10447 = L6_10447.State
          L6_10447 = L6_10447.g_TweakProfile
          L7_10448 = 3
          L5_10446(L6_10447, L7_10448)
          L5_10446 = Tweaks
          L5_10446 = L5_10446.Scratchpad
          L5_10446 = L5_10446.DEBUG
          if L5_10446 then
            L5_10446 = System
            L5_10446 = L5_10446.Log
            L6_10447 = "There were changes - description follows of Tweaks.Saving.Temp, profileTable, Tweaks.Saving.Diff (last is crucial)"
            L5_10446(L6_10447)
            L5_10446 = LogTable
            L6_10447 = Tweaks
            L6_10447 = L6_10447.Saving
            L6_10447 = L6_10447.Temp
            L7_10448 = "Tweaks.Saving.Temp"
            L5_10446(L6_10447, L7_10448)
            L5_10446 = LogTable
            L6_10447 = L3_10444
            L7_10448 = "profileTable"
            L5_10446(L6_10447, L7_10448)
            L5_10446 = LogTable
            L6_10447 = Tweaks
            L6_10447 = L6_10447.Saving
            L6_10447 = L6_10447.Diff
            L7_10448 = "Tweaks.Saving.Diff"
            L5_10446(L6_10447, L7_10448)
          end
        else
          L5_10446 = Tweaks
          L5_10446 = L5_10446.Saving
          L5_10446 = L5_10446.Profiles
          L6_10447 = Tweaks
          L6_10447 = L6_10447.Saving
          L6_10447 = L6_10447.Temp
          L5_10446[L1_10442] = L6_10447
          L5_10446 = Tweaks
          L5_10446 = L5_10446.Saving
          L6_10447 = {}
          L5_10446.Temp = L6_10447
        end
        return
      end
      L5_10446 = false
      L6_10447 = false
      L7_10448, L8_10449 = nil, nil
      for _FORV_12_, _FORV_13_ in pairs(Tweaks.Saving.Profiles) do
        if L5_10446 then
          if A0_10441 > 0 then
            L7_10448 = _FORV_12_
          end
          L5_10446 = false
        end
        if _FORV_12_ == L1_10442 then
          L5_10446 = true
          if A0_10441 <= 0 then
            L7_10448 = L8_10449
          end
        end
        L8_10449 = _FORV_12_
      end
      if not L7_10448 then
        if A0_10441 > 0 then
          L7_10448 = pairs(Tweaks.Saving.Profiles)(Tweaks.Saving.Profiles)
        else
          L7_10448 = L8_10449
        end
      end
      System.SetCVar("g_TweakProfile", L7_10448)
      Tweaks.Scratchpad.APPLYPROFILE = true
      Tweaks.State.g_TweakProfile.time = nil
    end
  },
  {
    NAME = "Profile comment: ",
    CVAR = "g_TweakComment"
  },
  {
    NAME = "Black menu background",
    LUA = "Tweaks.Scratchpad.BLACKBACKGROUND"
  },
  {
    NAME = "Black menu background alpha",
    LUA = "Tweaks.Scratchpad.BLACKBACKGROUNDALPHA",
    DELTA = "0.1"
  },
  {
    NAME = "Tweaks menu input repeat rate",
    LUA = "Tweaks.Scratchpad.REPEATRATE",
    DELTA = "0.025"
  },
  {
    NAME = "Tweaks menu input repeat delay (until first repeat)",
    LUA = "Tweaks.Scratchpad.REPEATDELAY",
    DELTA = "0.05",
    MINIMUM = 0.05,
    MAXIMUM = 2
  },
  {
    NAME = "Tweak menu font size",
    LUA = "Tweaks.Scratchpad.FONTSIZE",
    DELTA = "1",
    MINIMUM = 10,
    MAXIMUM = 100
  },
  {
    NAME = "Tweak menu vertical spacing",
    LUA = "Tweaks.Scratchpad.VERTSPACE",
    DELTA = "1",
    MINIMUM = 10,
    MAXIMUM = 50
  },
  {
    NAME = "Display MotD:",
    HIDDEN = true,
    LUA = "Tweaks.Scratchpad.MOTD",
    INCREMENTER = function()
      Tweaks.Scratchpad.MOTD = not Tweaks.Scratchpad.MOTD
      Script.ReloadScript("Scripts/Tweaks.lua")
    end
  },
  {
    NAME = "Save active profile on exit",
    NOSAVE = true,
    LUA = "Tweaks.Scratchpad.SAVEONEXIT"
  },
  {
    NAME = "Save active profile now, last saved this session:",
    LUA = "Tweaks.Scratchpad.VALUESLASTSAVED.asString",
    NOSAVE = true,
    INCREMENTER = function()
      local L0_10450, L1_10451
      L0_10450 = Tweaks
      L0_10450 = L0_10450.Scratchpad
      L0_10450.SAVEVALUES = true
    end
  },
  {
    NAME = "Force complete save of active profile now",
    LUA = "",
    EVALUATOR = function()
      local L0_10452, L1_10453
      L0_10452 = ""
      return L0_10452
    end,
    NOSAVE = true,
    INCREMENTER = function()
      local L0_10454, L1_10455
      L0_10454 = Tweaks
      L0_10454 = L0_10454.Scratchpad
      L0_10454.SAVEVALUES = true
      L0_10454 = Tweaks
      L0_10454 = L0_10454.Scratchpad
      L0_10454.FORCESAVE = true
    end
  },
  {
    NAME = "Revert all values in all profiles",
    LUA = "Tweaks.Scratchpad.RELOADVALUES",
    NOSAVE = true,
    EVALUATOR = function()
      local L0_10456
      L0_10456 = ""
      if Tweaks.State.CheckFeedbackTimer(Tweaks.State.RELOADVALUES) then
        L0_10456 = "Loaded..."
      end
      return L0_10456
    end,
    INCREMENTER = function()
      Tweaks.Scratchpad.RELOADVALUES = true
      Tweaks.State.InitFeedbackTimer(Tweaks.State.RELOADVALUES, 2)
    end
  },
  {
    NAME = "Reload Tweak menu structure",
    LUA = "Dummy",
    NOSAVE = true,
    EVALUATOR = function()
      local L0_10457, L1_10458
      L0_10457 = ""
      return L0_10457
    end,
    INCREMENTER = function()
      Tweaks.ReloadStructure()
    end
  }
}
L0_10439.MENU = "Menu Configuration"
tMenuTweaks = L0_10439
