Script.ReloadScript("SCRIPTS/Entities/actor/BasicActor.lua")
Player = {
  AnimationGraph = "player.xml",
  UpperBodyGraph = "",
  ActionController = "Animations/Mannequin/ADB/playerControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/playerAnims3P.adb",
  AnimDatabase1P = "Animations/Mannequin/ADB/playerAnims1P.adb",
  SoundDatabase = "Animations/Mannequin/ADB/playerSounds.adb",
  type = "Player",
  Properties = {
    soclasses_SmartObjectClass = "Player",
    groupid = 0,
    commrange = 40,
    Damage = {bLogDamages = 0, FallSleepTime = 6},
    CharacterSounds = {
      footstepEffect = "footstep_player",
      remoteFootstepEffect = "footstep",
      bFootstepGearEffect = 0,
      footstepIndGearAudioSignal_Walk = "Player_Footstep_Gear_Walk",
      footstepIndGearAudioSignal_Run = "Player_Footstep_Gear_Run",
      foleyEffect = "foley_player"
    },
    Perception = {sightrange = 50},
    Effects = {
      zeroGEffectFile = "LevelShared.ArkEnvironment.Ambience.FloatingDebris_01"
    },
    fileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf",
    shadowFileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf",
    clientFileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/HitDeathReactions_PlayerSP.xml"
  },
  ArkInventory = {
    Ingredients = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    FabPlans = {},
    Items = {}
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
    Damage = {health = 1000},
    stance = {
      {
        stanceId = STANCE_STAND,
        maxSpeed = 4,
        heightCollider = 1.25,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.3
        },
        viewOffset = {
          x = 0,
          y = 0.065,
          z = 1.65
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.35
        },
        viewDownYMod = 0.05,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "stand",
        useCapsule = 1
      },
      {stanceId = -2},
      {
        stanceId = STANCE_SNEAK,
        maxSpeed = 1.5,
        heightCollider = 0.7,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.1
        },
        viewOffset = {
          x = 0,
          y = 0.065,
          z = 1
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.85
        },
        viewDownYMod = 0.05,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "sneak",
        useCapsule = 1
      },
      {
        stanceId = STANCE_SWIM,
        maxSpeed = 2.1,
        heightCollider = 1,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.35
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1.5
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0.3,
          y = 0,
          z = 0
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
          x = 0.02,
          y = 0,
          z = 1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "zerog",
        useCapsule = 1
      },
      {stanceId = -2}
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
      "HumanPlayer",
      "HumanShared"
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
  AI = {}
}
function Player.GetItems(A0_1646)
  local L1_1647, L2_1648, L3_1649, L4_1650, L5_1651, L6_1652
  L1_1647 = {}
  for L5_1651, L6_1652 in L2_1648(L3_1649) do
    table.insert(L1_1647, L6_1652)
  end
  return L1_1647
end
function Player.SetItems(A0_1653, A1_1654)
  local L2_1655, L3_1656, L4_1657, L5_1658, L6_1659, L7_1660
  L2_1655 = {}
  for L6_1659, L7_1660 in L3_1656(L4_1657) do
    table.insert(L2_1655, L7_1660)
  end
  L3_1656.Items = L2_1655
end
function Player.AddItem(A0_1661, A1_1662)
  table.insert(A0_1661.ArkInventory.Items, A1_1662)
end
function Player.ClearItems(A0_1663)
  A0_1663.ArkInventory.Items = {}
end
function Player.ClearIngredients(A0_1664)
  local L2_1665
  L2_1665 = A0_1664.ArkInventory
  L2_1665.Ingredients = {
    organic = 0,
    mineral = 0,
    synthetic = 0,
    exotic = 0
  }
end
function Player.ClearAllArkInventory(A0_1666)
  A0_1666:ClearItems()
  A0_1666:ClearIngredients()
end
function Player.GetIngredients(A0_1667)
  local L1_1668, L2_1669
  L1_1668 = {}
  L2_1669 = A0_1667.ArkInventory
  L2_1669 = L2_1669.Ingredients
  L2_1669 = L2_1669.organic
  L1_1668.organic = L2_1669
  L2_1669 = A0_1667.ArkInventory
  L2_1669 = L2_1669.Ingredients
  L2_1669 = L2_1669.mineral
  L1_1668.mineral = L2_1669
  L2_1669 = A0_1667.ArkInventory
  L2_1669 = L2_1669.Ingredients
  L2_1669 = L2_1669.synthetic
  L1_1668.synthetic = L2_1669
  L2_1669 = A0_1667.ArkInventory
  L2_1669 = L2_1669.Ingredients
  L2_1669 = L2_1669.exotic
  L1_1668.exotic = L2_1669
  return L1_1668
end
function Player.SetIngredients(A0_1670, A1_1671)
  local L3_1672, L4_1673
  L3_1672 = A0_1670.ArkInventory
  L4_1673 = {}
  L4_1673.organic = A1_1671.organic
  L4_1673.mineral = A1_1671.mineral
  L4_1673.synthetic = A1_1671.synthetic
  L4_1673.exotic = A1_1671.exotic
  L3_1672.Ingredients = L4_1673
end
function Player.AddIngredients(A0_1674, A1_1675)
  local L2_1676, L3_1677, L4_1678
  L2_1676 = A0_1674.ArkInventory
  L2_1676 = L2_1676.Ingredients
  L3_1677 = A0_1674.ArkInventory
  L3_1677 = L3_1677.Ingredients
  L3_1677 = L3_1677.organic
  L4_1678 = A1_1675.organic
  L3_1677 = L3_1677 + L4_1678
  L2_1676.organic = L3_1677
  L2_1676 = A0_1674.ArkInventory
  L2_1676 = L2_1676.Ingredients
  L3_1677 = A0_1674.ArkInventory
  L3_1677 = L3_1677.Ingredients
  L3_1677 = L3_1677.mineral
  L4_1678 = A1_1675.mineral
  L3_1677 = L3_1677 + L4_1678
  L2_1676.mineral = L3_1677
  L2_1676 = A0_1674.ArkInventory
  L2_1676 = L2_1676.Ingredients
  L3_1677 = A0_1674.ArkInventory
  L3_1677 = L3_1677.Ingredients
  L3_1677 = L3_1677.synthetic
  L4_1678 = A1_1675.synthetic
  L3_1677 = L3_1677 + L4_1678
  L2_1676.synthetic = L3_1677
  L2_1676 = A0_1674.ArkInventory
  L2_1676 = L2_1676.Ingredients
  L3_1677 = A0_1674.ArkInventory
  L3_1677 = L3_1677.Ingredients
  L3_1677 = L3_1677.exotic
  L4_1678 = A1_1675.exotic
  L3_1677 = L3_1677 + L4_1678
  L2_1676.exotic = L3_1677
end
function Player.AddIngredient(A0_1679, A1_1680, A2_1681)
  local L3_1682
  L3_1682 = 0
  for _FORV_7_, _FORV_8_ in pairs(A0_1679.ArkInventory.Ingredients) do
    if _FORV_7_ == A1_1680 then
      L3_1682 = _FORV_8_ + A2_1681
      A0_1679.ArkInventory.Ingredients[_FORV_7_] = L3_1682
    end
  end
  return L3_1682
end
function Player.RemoveIngredients(A0_1683, A1_1684)
  local L2_1685, L3_1686, L4_1687
  L2_1685 = A0_1683.ArkInventory
  L2_1685 = L2_1685.Ingredients
  L3_1686 = A0_1683.ArkInventory
  L3_1686 = L3_1686.Ingredients
  L3_1686 = L3_1686.organic
  L4_1687 = A1_1684.organic
  L3_1686 = L3_1686 - L4_1687
  L2_1685.organic = L3_1686
  L2_1685 = A0_1683.ArkInventory
  L2_1685 = L2_1685.Ingredients
  L3_1686 = A0_1683.ArkInventory
  L3_1686 = L3_1686.Ingredients
  L3_1686 = L3_1686.mineral
  L4_1687 = A1_1684.mineral
  L3_1686 = L3_1686 - L4_1687
  L2_1685.mineral = L3_1686
  L2_1685 = A0_1683.ArkInventory
  L2_1685 = L2_1685.Ingredients
  L3_1686 = A0_1683.ArkInventory
  L3_1686 = L3_1686.Ingredients
  L3_1686 = L3_1686.synthetic
  L4_1687 = A1_1684.synthetic
  L3_1686 = L3_1686 - L4_1687
  L2_1685.synthetic = L3_1686
  L2_1685 = A0_1683.ArkInventory
  L2_1685 = L2_1685.Ingredients
  L3_1686 = A0_1683.ArkInventory
  L3_1686 = L3_1686.Ingredients
  L3_1686 = L3_1686.exotic
  L4_1687 = A1_1684.exotic
  L3_1686 = L3_1686 - L4_1687
  L2_1685.exotic = L3_1686
end
function Player.SetIsMultiplayer(A0_1688)
  local L1_1689
  L1_1689 = A0_1688.Properties
  L1_1689 = L1_1689.Damage
  L1_1689.health = 100
  L1_1689 = A0_1688.Properties
  L1_1689.fileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf"
  L1_1689 = A0_1688.Properties
  L1_1689.shadowFileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf"
  L1_1689 = A0_1688.Properties
  L1_1689.clientFileModel = "Objects/Characters/Human/sdk_player/sdk_player.cdf"
  L1_1689 = A0_1688.Properties
  L1_1689.fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/HitDeathReactions_MP.xml"
  L1_1689 = A0_1688.Properties
  L1_1689 = L1_1689.Damage
  L1_1689.fileBodyDamage = "Libs/BodyDamage/BodyDamage_MP.xml"
  L1_1689 = A0_1688.Properties
  L1_1689 = L1_1689.Damage
  L1_1689.fileBodyDamageParts = "Libs/BodyDamage/BodyParts_HumanMaleShared.xml"
  L1_1689 = A0_1688.Properties
  L1_1689 = L1_1689.Damage
  L1_1689.fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_Default.xml"
  L1_1689 = A0_1688.gameParams
  L1_1689 = L1_1689.stance
  L1_1689 = L1_1689[3]
  L1_1689.maxSpeed = 2.5
  L1_1689 = A0_1688.gameParams
  L1_1689.strafeMultiplier = 0.9
  L1_1689 = A0_1688.gameParams
  L1_1689.sneakMultiplier = 1
end
function Player.Expose(A0_1690)
  Net.Expose({
    Class = A0_1690,
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
function Player.Server.OnInit(A0_1691, A1_1692)
  if AI then
    CryAction.RegisterWithAI(A0_1691.id, AIOBJECT_PLAYER, A0_1691.Properties, A0_1691.PropertiesInstance)
  end
  A0_1691:OnInit(A1_1692)
end
function Player.PhysicalizeActor(A0_1693)
  local L1_1694
end
function Player.SetModel(A0_1695, A1_1696, A2_1697, A3_1698, A4_1699)
  local L5_1700
  if A1_1696 then
    if A4_1699 then
      L5_1700 = A0_1695.Properties
      L5_1700.clientFileModel = A4_1699
    end
    L5_1700 = A0_1695.Properties
    L5_1700.fileModel = A1_1696
  end
end
function Player.Server.OnInitClient(A0_1701, A1_1702)
end
function Player.Server.OnPostInitClient(A0_1703, A1_1704)
end
function Player.Client.Revive(A0_1705)
  A0_1705.actor:Revive()
end
function Player.Client.MoveTo(A0_1706, A1_1707)
  A0_1706:SetWorldPos(A1_1707)
end
function Player.Client.AlignTo(A0_1708, A1_1709)
  A0_1708.actor:SetAngles(A1_1709)
end
function Player.Client.ClearInventory(A0_1710)
  A0_1710.inventory:Clear()
end
function Player.Client.OnSetPlayerId(A0_1711)
  local L1_1712
end
function Player.Client.OnInit(A0_1713, A1_1714)
  A0_1713:OnInit(A1_1714)
end
function Player.OnInit(A0_1715, A1_1716)
  A0_1715:SetAIName(A0_1715:GetName())
  A0_1715:OnReset(true, A1_1716)
end
function Player.OnReset(A0_1717, A1_1718, A2_1719)
  A0_1717.SoundSignals.FeedbackHit_Armor = GameAudio.GetSignal("PlayerFeedback_HitArmor")
  A0_1717.SoundSignals.FeedbackHit_Flesh = GameAudio.GetSignal("PlayerFeedback_HitFlesh")
  g_aimode = nil
  BasicActor.Reset(A0_1717, A1_1718, A2_1719)
  A0_1717:SetTimer(0, 500)
  mergef(Player.SignalData, g_SignalData, 1)
  A0_1717.squadFollowMode = 0
  if AI then
    AI.ResetParameters(A0_1717.id, A2_1719, A0_1717.Properties, A0_1717.PropertiesInstance, nil, A0_1717.melee)
  end
  A0_1717.lastOverloadTime = nil
end
function Player.OnUpdateView(A0_1720, A1_1721)
end
function Player.GrabObject(A0_1722, A1_1723, A2_1724)
  BasicActor.GrabObject(A0_1722, A1_1723, A2_1724)
end
function Player.Client.OnHit(A0_1725, A1_1726, A2_1727)
  BasicActor.Client.OnHit(A0_1725, A1_1726, A2_1727)
end
function Player.Client.OnShutDown(A0_1728)
  BasicActor.ShutDown(A0_1728)
end
function Player.OnEvent(A0_1729, A1_1730, A2_1731)
end
function Player.OnSave(A0_1732, A1_1733)
  BasicActor.OnSave(A0_1732, A1_1733)
end
function Player.OnLoad(A0_1734, A1_1735)
  BasicActor.OnLoad(A0_1734, A1_1735)
end
function Player.OnLoadAI(A0_1736, A1_1737)
  local L2_1738
  L2_1738 = {}
  A0_1736.AI = L2_1738
  L2_1738 = A1_1737.AI
  if L2_1738 then
    L2_1738 = A1_1737.AI
    A0_1736.AI = L2_1738
  end
end
function Player.OnSaveAI(A0_1739, A1_1740)
  local L2_1741
  L2_1741 = A0_1739.AI
  if L2_1741 then
    L2_1741 = A0_1739.AI
    A1_1740.AI = L2_1741
  end
end
function Player.CanPickItem(A0_1742, A1_1743)
  return A0_1742:CanChangeItem()
end
function Player.CanChangeItem(A0_1744)
  if A0_1744.holsteredItemId then
    return false
  end
  return true
end
function Player.DropItem(A0_1745)
  local L1_1746
  L1_1746 = A0_1745.inventory:GetCurrentItem()
  if L1_1746 then
    L1_1746:Drop()
  end
end
function Player.SetFollowMode(A0_1747)
  AIBehaviour.PlayerIdle:Follow(A0_1747)
end
function Player.Goto(A0_1748)
  local L1_1749
end
function Player.OnEndCommandSound(A0_1750, A1_1751)
  if AI then
    AI.Signal(SIGNALFILTER_SENDER, 1, "ON_COMMAND_TOLD", A0_1750.id, Player.SignalData)
  end
end
function Player.OnEndCommandSoundGroup(A0_1752, A1_1753)
  if AI then
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "ON_COMMAND_TOLD", A0_1752.id, Player.SignalData)
  end
end
function Player.IsSquadAlive(A0_1754)
  local L1_1755, L2_1756, L3_1757, L4_1758, L5_1759
  L1_1755 = AI
  if not L1_1755 then
    L1_1755 = false
    return L1_1755
  end
  L1_1755 = AI
  L1_1755 = L1_1755.GetGroupCount
  L1_1755 = L1_1755(L2_1756)
  for L5_1759 = 1, L1_1755 do
    if AI.GetGroupMember(A0_1754.id, L5_1759) and AI.GetGroupMember(A0_1754.id, L5_1759) ~= A0_1754 and not AI.GetGroupMember(A0_1754.id, L5_1759):IsDead() then
      return true
    end
  end
  return L2_1756
end
function Player.IsUsable(A0_1760, A1_1761)
  local L2_1762
  L2_1762 = 1
  return L2_1762
end
function Player.ShouldIgnoreHit(A0_1763, A1_1764)
  if A1_1764.type ~= "collision" then
    return false
  end
  if A1_1764.shooter and A1_1764.shooter.IsOnVehicle and A1_1764.shooter:IsOnVehicle() then
    return false
  end
  if A1_1764.shooter and A1_1764.shooter.Properties and A1_1764.shooter.Properties.bDamagesPlayerOnCollisionSP == 1 then
    return false
  end
  return true
end
CreateActor(Player)
Player:Expose()
