Script.ReloadScript("Scripts/TweakSystem.lua")
Script.ReloadScript("Scripts/TweaksConfig.lua")
Tweaks.State.SilhouetteModeChanged = nil
Tweaks.State.SilhouetteModeChangeNow = nil
Tweaks.State.SilhouetteModeTimerUp = 0
Tweaks.State.SilhouetteModeTimerDown = 0
Tweaks.Menus.Main = {MENU = "Main Menu", tMenuTweaks}
if Tweaks.Scratchpad.MOTD then
  Tweaks.Menus.Main.MOTD = {
    NAME = "Message of the day: ",
    LUA = "Dummy",
    NOSAVE = true,
    EVALUATOR = function()
      local L0_10435, L1_10436, L2_10437, L3_10438
      L0_10435 = System
      L0_10435 = L0_10435.GetLocalOSTime
      L0_10435 = L0_10435()
      L1_10436 = L0_10435.sec
      L2_10437 = L0_10435.wday
      L3_10438 = "   Difficult takes a day...loading takes a week..."
      L1_10436 = L1_10436 % (string.len(L3_10438) - 1)
      return string.sub(L3_10438, L1_10436) .. string.sub(L3_10438, 1, L1_10436 + 1)
    end
  }
end
Tweaks.Scratchpad.RELOAD = true
