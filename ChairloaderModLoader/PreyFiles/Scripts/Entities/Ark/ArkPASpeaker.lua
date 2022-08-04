Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkPASpeaker = {
  Properties = {
    object_Model = "",
    nChannelId = 0,
    vector_audioOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {Icon = "Sound.bmp", IsScalable = false},
  PropertiesInstance = {
    nChannelIdOverride = -1,
    bVerbose = 0,
    bAudioEffect = 1,
    attenuationScale = 1
  },
  m_bVerbose = false,
  m_channelId = 0
}
GetArkEntityUtils(ArkPASpeaker)
SetupCollisionFiltering(ArkPASpeaker)
function ArkPASpeaker.SetFromProperties(A0_4437)
  local L1_4438
  L1_4438 = Ark
  L1_4438 = L1_4438.UnregisterPASpeaker
  L1_4438(A0_4437.id, A0_4437.m_channelId)
  L1_4438 = A0_4437.SetupModelAndPhysics
  L1_4438(A0_4437)
  L1_4438 = A0_4437.PropertiesInstance
  L1_4438 = L1_4438.bVerbose
  L1_4438 = L1_4438 == 1
  A0_4437.m_bVerbose = L1_4438
  L1_4438 = A0_4437.PropertiesInstance
  L1_4438 = L1_4438.nChannelIdOverride
  if L1_4438 == -1 then
    L1_4438 = A0_4437.Properties
    L1_4438 = L1_4438.nChannelId
    A0_4437.m_channelId = L1_4438
  else
    L1_4438 = A0_4437.PropertiesInstance
    L1_4438 = L1_4438.nChannelIdOverride
    A0_4437.m_channelId = L1_4438
  end
  L1_4438 = A0_4437.Log
  L1_4438(A0_4437, "channelId is " .. tostring(A0_4437.m_channelId))
  L1_4438 = Ark
  L1_4438 = L1_4438.RegisterPASpeaker
  L1_4438(A0_4437.id, A0_4437.m_channelId, A0_4437.PropertiesInstance.attenuationScale)
  L1_4438 = A0_4437.GetDefaultAuxAudioProxyID
  L1_4438 = L1_4438(A0_4437)
  A0_4437:SetAudioProxyOffset(A0_4437.Properties.vector_audioOffset, L1_4438)
  if System.IsEditing() and A0_4437.m_bVerbose then
    CryAction.PersistantSphere(A0_4437:ToGlobal(0, A0_4437.Properties.vector_audioOffset), 0.25, g_Vectors.v010, "offset", 1)
  end
end
function ArkPASpeaker.Init(A0_4439, A1_4440)
  local L2_4441
  L2_4441 = A0_4439.GetDefaultAuxAudioProxyID
  L2_4441 = L2_4441(A0_4439)
  A0_4439:SetAudioProxyAttenuationScale(A0_4439.PropertiesInstance.attenuationScale, L2_4441)
end
function ArkPASpeaker.OnPostLoad(A0_4442)
  local L1_4443
  L1_4443 = A0_4442.GetDefaultAuxAudioProxyID
  L1_4443 = L1_4443(A0_4442)
  A0_4442:SetAudioProxyAttenuationScale(A0_4442.PropertiesInstance.attenuationScale, L1_4443)
end
function ArkPASpeaker.OnDestroy(A0_4444)
  Ark.UnregisterPASpeaker(A0_4444.id, A0_4444.m_channelId)
end
