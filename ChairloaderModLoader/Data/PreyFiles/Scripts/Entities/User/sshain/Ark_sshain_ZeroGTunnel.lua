local L0_8997, L1_8998, L2_8999, L3_9000
L0_8997 = {}
L1_8998 = {}
L1_8998.Icon = "Magnet.bmp"
L0_8997.Editor = L1_8998
L1_8998 = {}
L1_8998.fileModel = "Objects/User/sshain/Ark_sshain_ZeroGGate.cgf"
L0_8997.Properties = L1_8998
L1_8998 = {}
L2_8999 = {}
L2_8999.x = 1
L2_8999.y = 0
L2_8999.z = 0
L1_8998.red = L2_8999
L2_8999 = {}
L2_8999.x = 0
L2_8999.y = 1
L2_8999.z = 0
L1_8998.green = L2_8999
L2_8999 = {}
L2_8999.x = 0
L2_8999.y = 0
L2_8999.z = 1
L1_8998.blue = L2_8999
L0_8997.Color = L1_8998
L0_8997.fGateSpacing = 5
L0_8997.fMaxSpeed = 8
L0_8997.fOffset = 1
L0_8997.fFractionOfSec = 1
L0_8997.fGateScale = 1
L0_8997.iNumberOfGates = 20
L0_8997.iUpdateRate = 10
L1_8998 = {}
L0_8997.vecLastVelocity = L1_8998
L1_8998 = {}
L0_8997.Gates = L1_8998
Ark_sshain_ZeroGTunnel = L0_8997
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9001)
  local L1_9002, L2_9003, L3_9004, L4_9005, L5_9006
  L1_9002(L2_9003)
  L1_9002(L2_9003, L3_9004)
  A0_9001.fOffset = L1_9002
  A0_9001.fFractionOfSec = L1_9002
  L1_9002(L2_9003, L3_9004)
  if L1_9002 ~= nil then
    for L4_9005 = 1, A0_9001.iNumberOfGates do
      L5_9006 = {}
      CopyVector(L5_9006, g_Vectors.v000)
      L5_9006.y = A0_9001.fGateSpacing * L4_9005 - A0_9001.fOffset
      A0_9001:LoadObject(L4_9005, A0_9001.Properties.fileModel)
      A0_9001:SetSlotPos(L4_9005, L5_9006)
      A0_9001:SetSlotScale(L4_9005, A0_9001.fGateScale)
      A0_9001.Gates[L4_9005] = L4_9005
    end
  end
  L1_9002(L2_9003, L3_9004)
end
L0_8997.Reset = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9007)
  local L1_9008, L2_9009, L3_9010, L4_9011, L5_9012, L6_9013, L7_9014, L8_9015, L9_9016, L10_9017, L11_9018
  L1_9008 = {}
  L2_9009 = {}
  L11_9018 = L5_9012(L6_9013)
  L3_9010(L4_9011, L5_9012, L6_9013, L7_9014, L8_9015, L9_9016, L10_9017, L11_9018, L5_9012(L6_9013))
  L3_9010(L4_9011)
  for L6_9013, L7_9014 in L3_9010(L4_9011) do
    L9_9016 = L1_9008
    L10_9017 = L7_9014
    L8_9015(L9_9016, L10_9017)
  end
  for L9_9016, L10_9017 in L6_9013(L7_9014) do
    L11_9018 = A0_9007.GetSlotPos
    L11_9018 = L11_9018(A0_9007, L10_9017)
    if L11_9018.y < -A0_9007.fOffset then
      L11_9018.y = L5_9012
      table.remove(A0_9007.Gates, L9_9016)
      table.insert(A0_9007.Gates, #A0_9007.Gates + 1, L10_9017)
    end
    L11_9018.y = L11_9018.y - L4_9011 * A0_9007.fFractionOfSec
    A0_9007:SetSlotPos(L10_9017, L11_9018)
  end
  if L3_9010 == 0 then
    L2_9009 = L6_9013
  end
  L9_9016 = L8_9015
  L11_9018 = L8_9015(L9_9016)
  L6_9013(L7_9014, L8_9015, L9_9016, L10_9017, L11_9018, L8_9015(L9_9016))
  L6_9013(L7_9014, L8_9015)
end
L0_8997.UpdateGates = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9019, A1_9020)
  A0_9019:UpdateGates()
end
L0_8997.OnUpdate = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9021)
  A0_9021:Reset()
end
L0_8997.OnReset = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9022)
  A0_9022:Reset()
end
L0_8997.OnInit = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9023)
  A0_9023:Reset()
end
L0_8997.OnPropertyChange = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9024)
  A0_9024:Activate(1)
  BroadcastEvent(A0_9024, "Started")
end
L0_8997.Event_Start = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
function L1_8998(A0_9025)
  A0_9025:Activate(0)
  BroadcastEvent(A0_9025, "Stopped")
end
L0_8997.Event_Stop = L1_8998
L0_8997 = Ark_sshain_ZeroGTunnel
L1_8998 = {}
L2_8999 = {}
L3_9000 = {
  Ark_sshain_ZeroGTunnel.Event_Start,
  "bool"
}
L2_8999.Start = L3_9000
L3_9000 = {
  Ark_sshain_ZeroGTunnel.Event_Stop,
  "bool"
}
L2_8999.Stop = L3_9000
L1_8998.Inputs = L2_8999
L2_8999 = {}
L2_8999.Started = "bool"
L2_8999.Stopped = "bool"
L1_8998.Outputs = L2_8999
L0_8997.FlowEvents = L1_8998
