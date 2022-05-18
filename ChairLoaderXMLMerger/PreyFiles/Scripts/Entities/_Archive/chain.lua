local L0_670, L1_671, L2_672
L0_670 = {}
L1_671 = {}
L1_671.mass = 20
L1_671.fileModel = "Objects/glm/shipwreck/stuff/chain_swing.cgf"
L1_671.bCheckCollisions = 1
L1_671.bCheckTerrainCollisions = 0
L1_671.bShootable = 1
L1_671.coll_dist = 0.025
L1_671.material = "mat_default"
L2_672 = {}
L2_672.x = 0
L2_672.y = 0
L2_672.z = -9.81
L1_671.gravity = L2_672
L1_671.damping = 0.5
L1_671.friction = 0.1
L1_671.sleep_speed = 0.01
L1_671.max_time_step = 0.01
L1_671.rope_name = "rope"
L1_671.num_ropes = 1
L1_671.AttachTo = ""
L1_671.AttachToPart = -1
L1_671.AttachToUp = ""
L1_671.AttachToPartUp = -1
L1_671.bDetachOnDamage = 1
L1_671.bAwake = 1
L2_672 = {}
L2_672.bKeepCollisions = 1
L2_672.max_time_step = 0.03
L2_672.sleep_speed = 0.04
L1_671.LowSpec = L2_672
L0_670.Properties = L1_671
L0_670.bWasReset = 0
L0_670.bWasDetached = 0
L1_671 = {}
L1_671.Model = "Objects/Editor/LightSphear.cgf"
L0_670.Editor = L1_671
L0_670.sChainSound = nil
L0_670.sChainBroken = nil
L0_670.sChainSoundFilename = "Sounds/objectimpact/chain.wav"
ChainSwing = L0_670
L0_670 = ChainSwing
function L1_671(A0_673)
  local L1_674, L2_675, L3_676, L4_677, L5_678, L6_679, L7_680, L8_681
  A0_673.lightId = nil
  L2_675 = A0_673
  L1_674 = A0_673.NetPresent
  L3_676 = nil
  L1_674(L2_675, L3_676)
  L2_675 = A0_673
  L1_674 = A0_673.Activate
  L3_676 = 1
  L1_674(L2_675, L3_676)
  L1_674 = {}
  L1_674.entity_id_1 = -1
  L1_674.entity_part_id_1 = 0
  L2_675 = Game
  L3_676 = L2_675
  L2_675 = L2_675.GetMaterialIDByName
  L2_675 = L2_675(L3_676, L4_677)
  L1_674.surface_idx = L2_675
  L2_675 = {}
  L3_676 = A0_673.Properties
  L3_676 = L3_676.bCheckCollisions
  L3_676 = L3_676 * L4_677
  L2_675.bCheckCollisions = L3_676
  L3_676 = A0_673.Properties
  L3_676 = L3_676.bCheckTerrainCollisions
  L3_676 = L3_676 * L4_677
  L2_675.bCheckTerrainCollisions = L3_676
  L3_676 = tonumber
  L8_681 = L4_677(L5_678)
  L3_676 = L3_676(L4_677, L5_678, L6_679, L7_680, L8_681, L4_677(L5_678))
  L7_680 = 0
  L4_677(L5_678, L6_679, L7_680)
  L7_680 = 0
  L8_681 = 0
  L4_677(L5_678, L6_679, L7_680, L8_681, 0)
  for L7_680 = 1, L5_678.num_ropes do
    L8_681 = A0_673.Properties
    L8_681 = L8_681.rope_name
    if L7_680 > 1 or 1 < A0_673.Properties.num_ropes then
      L8_681 = L8_681 .. L7_680
    end
    A0_673:SetCharacterPhysicParams(0, L8_681, PHYSICPARAM_ROPE, A0_673.Properties)
    A0_673:SetCharacterPhysicParams(0, L8_681, PHYSICPARAM_ROPE, L1_674)
    A0_673:SetCharacterPhysicParams(0, L8_681, PHYSICPARAM_SIMULATION, A0_673.Properties)
    if L3_676 == 0 then
      A0_673:SetCharacterPhysicParams(0, L8_681, PHYSICPARAM_ROPE, L2_675)
      A0_673:SetCharacterPhysicParams(0, L8_681, PHYSICPARAM_SIMULATION, A0_673.Properties.LowSpec)
    end
    if A0_673.Properties.bAwake == 0 then
      A0_673:AwakeCharacterPhysics(0, L8_681, 0)
    end
  end
  L7_680 = 1
  L4_677(L5_678, L6_679, L7_680)
  A0_673.bWasReset = 1
  A0_673.bWasDetached = 0
  L7_680 = 0
  L8_681 = 255
  A0_673.sChainSound = L4_677
end
L0_670.OnReset = L1_671
L0_670 = ChainSwing
function L1_671(A0_682)
  local L1_683, L2_684, L3_685, L4_686, L5_687, L6_688, L7_689
  L1_683 = A0_682.bWasReset
  if L1_683 then
    L1_683 = A0_682.bWasReset
    if L1_683 == 1 then
      L1_683 = A0_682.Properties
      L1_683 = L1_683.AttachTo
      if L1_683 then
        L1_683 = A0_682.Properties
        L1_683 = L1_683.AttachTo
      else
        if L1_683 == "" then
          L1_683 = A0_682.Properties
          L1_683 = L1_683.AttachTo
          if L1_683 then
            L1_683 = A0_682.Properties
            L1_683 = L1_683.AttachTo
          end
      end
      elseif L1_683 ~= "" then
        L1_683 = A0_682.bWasDetached
        if L1_683 == 0 then
          L1_683 = {}
          L2_684 = nil
          if L3_685 then
            if L3_685 ~= "" then
              L2_684 = L3_685
              if L2_684 then
                L1_683.entity_id_1 = L3_685
                if L3_685 then
                  L1_683.entity_part_id_1 = L3_685
                end
              end
            end
          end
          if L3_685 then
            if L3_685 ~= "" then
              L2_684 = L3_685
              if L2_684 then
                L1_683.entity_id_2 = L3_685
                if L3_685 then
                  L1_683.entity_part_id_2 = L3_685
                end
              end
            end
          end
          for L6_688 = 1, L4_686.num_ropes do
            L7_689 = A0_682.Properties
            L7_689 = L7_689.rope_name
            if L6_688 > 1 or 1 < A0_682.Properties.num_ropes then
              L7_689 = L7_689 .. L6_688
            end
            A0_682:SetCharacterPhysicParams(0, L7_689, PHYSICPARAM_ROPE, L1_683)
          end
        end
      end
      A0_682.bWasReset = 0
    end
  end
end
L0_670.OnUpdate = L1_671
L0_670 = ChainSwing
function L1_671(A0_690)
  A0_690:OnReset()
end
L0_670.OnPropertyChange = L1_671
L0_670 = ChainSwing
function L1_671(A0_691, A1_692)
  local L2_693
  L2_693 = A1_692.shooter
  if L2_693 then
    L2_693 = A1_692.shooter
    L2_693 = L2_693.ai
    if L2_693 then
      return
    end
  end
  L2_693 = A0_691.Properties
  L2_693 = L2_693.bDetachOnDamage
  if L2_693 then
    L2_693 = A0_691.Properties
    L2_693 = L2_693.bDetachOnDamage
    if L2_693 ~= 0 then
      L2_693 = {}
      L2_693.entity_id_1 = -1
      L2_693.entity_id_2 = -2
      if A0_691.Properties.AttachToUp and A0_691.Properties.AttachToUp ~= "" and System.GetEntityByName(A0_691.Properties.AttachToUp) then
        L2_693.entity_id_1 = System.GetEntityByName(A0_691.Properties.AttachToUp).id
        if A0_691.Properties.AttachToPartUp then
          L2_693.entity_part_id_1 = A0_691.Properties.AttachToPartUp
        end
      end
      A0_691:SetCharacterPhysicParams(0, A0_691.Properties.rope_name, PHYSICPARAM_ROPE, L2_693)
      A0_691.bWasDetached = 1
      A0_691:Event_ChainBroken()
    end
  end
  L2_693 = A1_692.ipart
  if L2_693 then
    L2_693 = A0_691.AddImpulse
    L2_693(A0_691, A1_692.ipart, A1_692.pos, A1_692.dir, A1_692.impact_force_mul)
  else
    L2_693 = A0_691.AddImpulse
    L2_693(A0_691, -1, A1_692.pos, A1_692.dir, A1_692.impact_force_mul)
  end
  L2_693 = A0_691.sChainSound
  if L2_693 then
    L2_693 = Sound
    L2_693 = L2_693.IsPlaying
    L2_693 = L2_693(A0_691.sChainSound)
    if not L2_693 then
      L2_693 = Sound
      L2_693 = L2_693.SetSoundPosition
      L2_693(A0_691.sChainSound, A0_691:GetPos())
      L2_693 = Sound
      L2_693 = L2_693.PlaySound
      L2_693(A0_691.sChainSound)
    end
  end
end
L0_670.OnDamage = L1_671
L0_670 = ChainSwing
function L1_671(A0_694)
  A0_694:OnReset()
end
L0_670.OnInit = L1_671
L0_670 = ChainSwing
function L1_671(A0_695, A1_696)
  BroadcastEvent(A0_695, "ChainBroken")
  if A0_695.sChainBroken then
    Sound.SetSoundPosition(A0_695.sChainBroken, A0_695:GetPos())
    Sound.PlaySound(A0_695.sChainBroken)
  end
end
L0_670.Event_ChainBroken = L1_671
L0_670 = ChainSwing
function L1_671(A0_697, A1_698)
end
L0_670.OnWrite = L1_671
L0_670 = ChainSwing
function L1_671(A0_699, A1_700)
end
L0_670.OnRead = L1_671
L0_670 = ChainSwing
function L1_671(A0_701, A1_702)
  A1_702:WriteInt(A0_701.bWasDetached)
end
L0_670.OnSave = L1_671
L0_670 = ChainSwing
function L1_671(A0_703, A1_704)
  A0_703.bWasDetached = A1_704:ReadInt()
end
L0_670.OnLoad = L1_671
L0_670 = ChainSwing
function L1_671(A0_705)
  local L1_706
end
L0_670.OnShutDown = L1_671
L0_670 = ChainSwing
L1_671 = {}
L2_672 = {}
L2_672.ChainBroken = {
  ChainSwing.Event_ChainBroken,
  "bool"
}
L1_671.Inputs = L2_672
L2_672 = {}
L2_672.ChainBroken = "bool"
L1_671.Outputs = L2_672
L0_670.FlowEvents = L1_671
