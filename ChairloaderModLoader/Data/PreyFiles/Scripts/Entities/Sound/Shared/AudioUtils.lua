local L0_8294, L1_8295
L0_8294 = {}
L0_8294.sObstructionCalcSwitchName = "ObstrOcclCalcType"
L1_8295 = {
  "Ignore",
  "SingleRay",
  "MultiRay"
}
L0_8294.sObstructionStateNames = L1_8295
AudioUtils = L0_8294
L0_8294 = AudioUtils
function L1_8295(A0_8296)
  local L1_8297
  if A0_8296 ~= nil and A0_8296 ~= "" then
    L1_8297 = Sound.GetAudioTriggerID(A0_8296)
  end
  return L1_8297
end
L0_8294.LookupTriggerID = L1_8295
L0_8294 = AudioUtils
function L1_8295(A0_8298)
  local L1_8299
  if A0_8298 ~= nil and A0_8298 ~= "" then
    L1_8299 = Sound.GetAudioRtpcID(A0_8298)
  end
  return L1_8299
end
L0_8294.LookupRtpcID = L1_8295
L0_8294 = AudioUtils
function L1_8295(A0_8300)
  local L1_8301
  if A0_8300 ~= nil and A0_8300 ~= "" then
    L1_8301 = Sound.GetAudioSwitchID(A0_8300)
  end
  return L1_8301
end
L0_8294.LookupSwitchID = L1_8295
L0_8294 = AudioUtils
function L1_8295(A0_8302, A1_8303)
  local L2_8304, L3_8305, L4_8306, L5_8307, L6_8308, L7_8309
  L2_8304 = {}
  if A0_8302 ~= nil and A1_8303 ~= nil then
    for L6_8308, L7_8309 in L3_8305(L4_8306) do
      L2_8304[L6_8308] = Sound.GetAudioSwitchStateID(A0_8302, L7_8309)
    end
  end
  return L2_8304
end
L0_8294.LookupSwitchStateIDs = L1_8295
L0_8294 = AudioUtils
function L1_8295(A0_8310)
  local L1_8311
  if A0_8310 ~= nil and A0_8310 ~= "" then
    L1_8311 = Sound.GetAudioEnvironmentID(A0_8310)
  end
  return L1_8311
end
L0_8294.LookupAudioEnvironmentID = L1_8295
L0_8294 = AudioUtils
function L1_8295()
  local L0_8312
  L0_8312 = AudioUtils
  L0_8312 = L0_8312.LookupSwitchID
  L0_8312 = L0_8312(AudioUtils.sObstructionCalcSwitchName)
  return {
    hSwitchID = L0_8312,
    tStateIDs = AudioUtils.LookupSwitchStateIDs(L0_8312, AudioUtils.sObstructionStateNames)
  }
end
L0_8294.LookupObstructionSwitchAndStates = L1_8295
