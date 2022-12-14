Script.ReloadScript("SCRIPTS/Entities/actor/BasicActor.lua")
PlayerHeavy = {
  AnimationGraph = "player.xml",
  UpperBodyGraph = "",
  type = "Player",
  Properties = {
    soclasses_SmartObjectClass = "Player",
    groupid = 0,
    commrange = 40,
    Damage = {
      bLogDamages = 0,
      health = 90,
      FallSleepTime = 6
    },
    CharacterSounds = {
      footstepEffect = "footstep_player",
      remoteFootstepEffect = "footstep",
      bFootstepGearEffect = 0,
      footstepIndGearAudioSignal_Walk = "Player_Footstep_Gear_Walk",
      footstepIndGearAudioSignal_Run = "Player_Footstep_Gear_Run",
      foleyEffect = "foley_player"
    },
    Perception = {sightrange = 50},
    fileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf",
    shadowFileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf",
    clientFileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/HitDeathReactions_PlayerSP.xml"
  },
  PropertiesInstance = {aibehavior_behaviour = "PlayerIdle"},
  gameParams = {
    inventory = {
      items = {
        {name = "Zeus", equip = true}
      },
      ammo = {
        {
          name = "lightbullet",
          amount = 28
        }
      }
    },
    Damage = {health = 90},
    stance = {
      {
        stanceId = STANCE_STAND,
        maxSpeed = 4,
        heightCollider = 1.7,
        heightPivot = 0,
        size = {
          x = 0.9,
          y = 0.9,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = -2,
          z = 3.2
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.55
        },
        name = "stand",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.8,
        heightPivot = 0,
        size = {
          x = 0.9,
          y = 0.9,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = -2,
          z = 3
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.55
        },
        name = "alerted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_STEALTH,
        normalSpeed = 0.6,
        maxSpeed = 50,
        heightCollider = 1,
        heightPivot = 0,
        size = {
          x = 0.4,
          y = 0.4,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = -2,
          z = 3.35
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.1
        },
        name = "stealth",
        useCapsule = 1
      },
      {
        stanceId = STANCE_SNEAK,
        normalSpeed = 0.5,
        maxSpeed = 1.5,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.4,
          y = 0.4,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = -2,
          z = 3.1
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.85
        },
        name = "sneak",
        useCapsule = 1
      },
      {
        stanceId = STANCE_LOW_COVER,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.4,
          y = 0.4,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0.9
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.85
        },
        name = "coverLow",
        useCapsule = 1
      },
      {
        stanceId = STANCE_HIGH_COVER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 0.4,
          y = 0.4,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1.7
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.1
        },
        name = "coverHigh",
        useCapsule = 1
      },
      {
        stanceId = STANCE_SWIM,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.9,
        heightPivot = 0.5,
        size = {
          x = 0.4,
          y = 0.4,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.3
        },
        name = "swim",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ZEROG,
        maxSpeed = 2.1,
        heightCollider = 0.7,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.1
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 1
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0.85
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "zerog",
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.8,
        heightPivot = 0,
        size = {
          x = 0.9,
          y = 0.9,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 2
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.55
        },
        name = "relaxed",
        useCapsule = 1
      }
    },
    autoAimTargetParams = {
      primaryTargetBone = BONE_SPINE,
      physicsTargetBone = BONE_SPINE,
      secondaryTargetBone = BONE_HEAD,
      fallbackOffset = 1.2,
      innerRadius = 1,
      outerRadius = 3.5,
      snapRadius = 1,
      snapRadiusTagged = 1
    },
    boneIDs = {
      BONE_BIP01 = "Bip01",
      BONE_SPINE = "Bip01 Spine1",
      BONE_SPINE2 = "Bip01 Spine2",
      BONE_SPINE3 = "Bip01 Spine3",
      BONE_HEAD = "Bip01 Head",
      BONE_EYE_R = "eye_right_bone",
      BONE_EYE_L = "eye_left_bone",
      BONE_WEAPON = "weapon_bone",
      BONE_WEAPON2 = "Lweapon_bone",
      BONE_FOOT_R = "Bip01 R Foot",
      BONE_FOOT_L = "Bip01 L Foot",
      BONE_ARM_R = "Bip01 R Forearm",
      BONE_ARM_L = "Bip01 L Forearm",
      BONE_CALF_R = "Bip01 R Calf",
      BONE_CALF_L = "Bip01 L Calf",
      BONE_CAMERA = "Bip01 Camera",
      BONE_HUD = "Bip01 HUD"
    },
    characterDBAs = {
      "HumanPlayer"
    },
    lookFOV = 90,
    aimFOV = 180,
    proceduralLeaningFactor = 0
  },
  SoundSignals = {FeedbackHit_Armor = -1, FeedbackHit_Flesh = -1},
  Server = {},
  Client = {},
  squadFollowMode = 0,
  squadTarget = {
    x = 0,
    y = 0,
    z = 0
  },
  SignalData = {},
  AI = {},
  OnUseEntityId = NULL_ENTITY,
  OnUseSlot = 0,
  useHoldFiredAlready = false,
  usePressFiredForPickup = true,
  usePressFiredForUse = true
}
function PlayerHeavy.SetIsMultiplayer(A0_1765)
  local L1_1766
end
function PlayerHeavy.Expose(A0_1767)
  Net.Expose({
    Class = A0_1767,
    ClientMethods = {
      Revive = {RELIABLE_ORDERED, POST_ATTACH},
      MoveTo = {
        RELIABLE_ORDERED,
        POST_ATTACH,
        VEC3
      },
      AlignTo = {
        RELIABLE_ORDERED,
        POST_ATTACH,
        VEC3
      },
      ClearInventory = {RELIABLE_ORDERED, POST_ATTACH}
    },
    ServerMethods = {},
    ServerProperties = {}
  })
end
function PlayerHeavy.Server.OnInit(A0_1768, A1_1769)
  if AI then
    CryAction.RegisterWithAI(A0_1768.id, AIOBJECT_PLAYER, A0_1768.Properties, A0_1768.PropertiesInstance)
  end
  A0_1768:OnInit(A1_1769)
end
function PlayerHeavy.PhysicalizeActor(A0_1770)
  local L1_1771
end
function PlayerHeavy.SetModel(A0_1772, A1_1773, A2_1774, A3_1775, A4_1776)
  local L5_1777
  if A1_1773 then
    if A4_1776 then
      L5_1777 = A0_1772.Properties
      L5_1777.clientFileModel = A4_1776
    end
    L5_1777 = A0_1772.Properties
    L5_1777.fileModel = A1_1773
  end
end
function PlayerHeavy.Server.OnInitClient(A0_1778, A1_1779)
end
function PlayerHeavy.Server.OnPostInitClient(A0_1780, A1_1781)
end
function PlayerHeavy.Client.Revive(A0_1782)
  A0_1782.actor:Revive()
end
function PlayerHeavy.Client.MoveTo(A0_1783, A1_1784)
  A0_1783:SetWorldPos(A1_1784)
end
function PlayerHeavy.Client.AlignTo(A0_1785, A1_1786)
  A0_1785.actor:SetAngles(A1_1786)
end
function PlayerHeavy.Client.ClearInventory(A0_1787)
  A0_1787.inventory:Clear()
end
function PlayerHeavy.Client.OnSetPlayerId(A0_1788)
  local L1_1789
end
function PlayerHeavy.Client.OnInit(A0_1790, A1_1791)
  A0_1790:OnInit(A1_1791)
end
function PlayerHeavy.OnInit(A0_1792, A1_1793)
  A0_1792:SetAIName(A0_1792:GetName())
  A0_1792:OnReset(true, A1_1793)
end
function PlayerHeavy.OnReset(A0_1794, A1_1795, A2_1796)
  A0_1794.SoundSignals.FeedbackHit_Armor = GameAudio.GetSignal("PlayerFeedback_HitArmor")
  A0_1794.SoundSignals.FeedbackHit_Flesh = GameAudio.GetSignal("PlayerFeedback_HitFlesh")
  g_aimode = nil
  BasicActor.Reset(A0_1794, A1_1795, A2_1796)
  A0_1794:SetTimer(0, 500)
  mergef(PlayerHeavy.SignalData, g_SignalData, 1)
  A0_1794.squadFollowMode = 0
  if AI then
    AI.ResetParameters(A0_1794.id, A2_1796, A0_1794.Properties, A0_1794.PropertiesInstance, nil, A0_1794.melee)
  end
  A0_1794.lastOverloadTime = nil
end
function PlayerHeavy.SetOnUseData(A0_1797, A1_1798, A2_1799)
  A0_1797.OnUseEntityId = A1_1798
  A0_1797.OnUseSlot = A2_1799
end
function PlayerHeavy.ItemPickUpMechanic(A0_1800, A1_1801, A2_1802)
  local L3_1803, L4_1804, L5_1805
  L3_1803 = A1_1801 == "itemPickup"
  L4_1804 = A1_1801 == "use"
  L5_1805 = L4_1804 or L3_1803
  if A1_1801 == "heavyweaponremove" and A2_1802 == "press" and A0_1800.actor:IsCurrentItemHeavy() then
    A0_1800:UseEntity(A0_1800.OnUseEntityId, A0_1800.OnUseSlot, true)
    A0_1800.useHoldFiredAlready = true
  elseif L5_1805 and A2_1802 == "press" then
    if L3_1803 then
      if A0_1800.usePressFiredForUse then
        A0_1800.usePressFiredForUse = false
        A0_1800.usePressFiredForPickup = false
      else
        A0_1800.usePressFiredForPickup = true
      end
    elseif L4_1804 then
      if A0_1800.usePressFiredForPickup then
        A0_1800.usePressFiredForPickup = false
        A0_1800.usePressFiredForUse = false
      else
        A0_1800.usePressFiredForUse = true
      end
    end
    if true then
      Log("[tlh] @ Player:OnAction: action: " .. A1_1801 .. " press path")
      A0_1800:UseEntity(A0_1800.OnUseEntityId, A0_1800.OnUseSlot, true)
    end
  elseif L5_1805 and A2_1802 == "hold" and A0_1800.useHoldFiredAlready == false then
    if A0_1800.OnUseEntityId ~= NULL_ENTITY then
      A0_1800.useHoldFiredAlready = true
      A0_1800:UseEntity(A0_1800.OnUseEntityId, A0_1800.OnUseSlot, true)
    end
  elseif L5_1805 and A2_1802 == "release" then
    A0_1800.useHoldFiredAlready = false
  end
end
function PlayerHeavy.OnActionUse(A0_1806, A1_1807)
  A0_1806:UseEntity(A0_1806.OnUseEntityId, A0_1806.OnUseSlot, A1_1807)
end
function PlayerHeavy.OnUpdateView(A0_1808, A1_1809)
end
function PlayerHeavy.GrabObject(A0_1810, A1_1811, A2_1812)
  BasicActor.GrabObject(A0_1810, A1_1811, A2_1812)
end
function PlayerHeavy.Client.OnHit(A0_1813, A1_1814, A2_1815)
  BasicActor.Client.OnHit(A0_1813, A1_1814, A2_1815)
end
function PlayerHeavy.UseEntity(A0_1816, A1_1817, A2_1818, A3_1819)
  local L4_1820, L5_1821, L6_1822, L7_1823
  L4_1820 = assert
  L5_1821 = A1_1817
  L4_1820(L5_1821)
  L4_1820 = assert
  L5_1821 = A2_1818
  L4_1820(L5_1821)
  L4_1820 = A0_1816.actor
  L5_1821 = L4_1820
  L4_1820 = L4_1820.GetHealth
  L4_1820 = L4_1820(L5_1821)
  if not (L4_1820 <= 0) then
    L4_1820 = A0_1816.actor
    L5_1821 = L4_1820
    L4_1820 = L4_1820.GetSpectatorMode
    L4_1820 = L4_1820(L5_1821)
  elseif L4_1820 ~= 0 then
    return
  end
  L4_1820 = false
  L5_1821 = System
  L5_1821 = L5_1821.GetEntity
  L6_1822 = A1_1817
  L5_1821 = L5_1821(L6_1822)
  if L5_1821 then
    L6_1822 = L5_1821.OnUsed
    L7_1823 = L5_1821.OnUsedRelease
    if not L6_1822 and L5_1821:GetState() ~= "" and L5_1821[L5_1821:GetState()] then
      L6_1822 = L5_1821[L5_1821:GetState()].OnUsed
    end
    if not L7_1823 and L5_1821:GetState() ~= "" and L5_1821[L5_1821:GetState()] then
      L7_1823 = L5_1821[L5_1821:GetState()].OnUsedRelease
    end
    if L6_1822 and A3_1819 then
      L4_1820 = L6_1822(L5_1821, A0_1816, A2_1818)
      if AI then
        AI.SmartObjectEvent("OnUsed", L5_1821.id, A0_1816.id)
      end
    end
    if L7_1823 and not A3_1819 then
      L7_1823(L5_1821, A0_1816, A2_1818)
      if AI then
        AI.SmartObjectEvent("OnUsedRelease", L5_1821.id, A0_1816.id)
      end
    end
  end
  return L4_1820
end
function PlayerHeavy.Client.OnShutDown(A0_1824)
  BasicActor.ShutDown(A0_1824)
end
function PlayerHeavy.OnEvent(A0_1825, A1_1826, A2_1827)
end
function PlayerHeavy.OnSave(A0_1828, A1_1829)
  BasicActor.OnSave(A0_1828, A1_1829)
end
function PlayerHeavy.OnLoad(A0_1830, A1_1831)
  BasicActor.OnLoad(A0_1830, A1_1831)
end
function PlayerHeavy.OnLoadAI(A0_1832, A1_1833)
  local L2_1834
  L2_1834 = {}
  A0_1832.AI = L2_1834
  L2_1834 = A1_1833.AI
  if L2_1834 then
    L2_1834 = A1_1833.AI
    A0_1832.AI = L2_1834
  end
end
function PlayerHeavy.OnSaveAI(A0_1835, A1_1836)
  local L2_1837
  L2_1837 = A0_1835.AI
  if L2_1837 then
    L2_1837 = A0_1835.AI
    A1_1836.AI = L2_1837
  end
end
function PlayerHeavy.CanPickItem(A0_1838, A1_1839)
  return A0_1838:CanChangeItem()
end
function PlayerHeavy.CanChangeItem(A0_1840)
  if A0_1840.holsteredItemId then
    return false
  end
  return true
end
function PlayerHeavy.DropItem(A0_1841)
  local L1_1842
  L1_1842 = A0_1841.inventory:GetCurrentItem()
  if L1_1842 then
    L1_1842:Drop()
  end
end
function PlayerHeavy.SetFollowMode(A0_1843)
  AIBehaviour.PlayerIdle:Follow(A0_1843)
end
function PlayerHeavy.Goto(A0_1844)
  local L1_1845
end
function PlayerHeavy.OnEndCommandSound(A0_1846, A1_1847)
  if AI then
    AI.Signal(SIGNALFILTER_SENDER, 1, "ON_COMMAND_TOLD", A0_1846.id, PlayerHeavy.SignalData)
  end
end
function PlayerHeavy.OnEndCommandSoundGroup(A0_1848, A1_1849)
  if AI then
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "ON_COMMAND_TOLD", A0_1848.id, PlayerHeavy.SignalData)
  end
end
function PlayerHeavy.IsSquadAlive(A0_1850)
  local L1_1851, L2_1852, L3_1853, L4_1854, L5_1855
  L1_1851 = AI
  if not L1_1851 then
    L1_1851 = false
    return L1_1851
  end
  L1_1851 = AI
  L1_1851 = L1_1851.GetGroupCount
  L1_1851 = L1_1851(L2_1852)
  for L5_1855 = 1, L1_1851 do
    if AI.GetGroupMember(A0_1850.id, L5_1855) and AI.GetGroupMember(A0_1850.id, L5_1855) ~= A0_1850 and not AI.GetGroupMember(A0_1850.id, L5_1855):IsDead() then
      return true
    end
  end
  return L2_1852
end
function PlayerHeavy.IsUsable(A0_1856, A1_1857)
  local L2_1858
  L2_1858 = 1
  return L2_1858
end
function PlayerHeavy.ShouldIgnoreHit(A0_1859, A1_1860)
  if A1_1860.type ~= "collision" then
    return false
  end
  if A1_1860.shooter and A1_1860.shooter.IsOnVehicle and A1_1860.shooter:IsOnVehicle() then
    return false
  end
  if A1_1860.shooter and A1_1860.shooter.Properties and A1_1860.shooter.Properties.bDamagesPlayerOnCollisionSP == 1 then
    return false
  end
  return true
end
CreateActor(PlayerHeavy)
PlayerHeavy:Expose()
