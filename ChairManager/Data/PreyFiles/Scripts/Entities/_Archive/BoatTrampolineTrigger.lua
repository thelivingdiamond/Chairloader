local L0_575, L1_576, L2_577, L3_578
L0_575 = {}
L0_575.type = "Trigger"
L1_576 = {}
L1_576.DimX = 5
L1_576.DimY = 5
L1_576.DimZ = 5
L1_576.bEnabled = 1
L1_576.bKillOnTrigger = 0
L1_576.bTriggerOnce = 0
L1_576.ImpulseStrength = 200
L1_576.ImpulseFadeInTime = 1
L1_576.ImpulseDuration = 1
L1_576.MinSpeed = 15
L1_576.MaxAngleOfImpact = 15
L1_576.ScriptCommand = ""
L1_576.PlaySequence = ""
L0_575.Properties = L1_576
L0_575.boat = nil
L1_576 = {}
L1_576.x = 0
L1_576.y = 0
L1_576.z = 0
L0_575.imp = L1_576
L0_575.MaxImpulse = 0
L0_575.InitImpulseTime = 0
L0_575.TotalImpulseDuration = 0
L0_575.MinSpeed2 = 0
L1_576 = {}
L1_576.Model = "Objects/Editor/T.cgf"
L0_575.Editor = L1_576
BoatTrampolineTrigger = L0_575
L0_575 = BoatTrampolineTrigger
function L1_576(A0_579)
  A0_579:OnReset()
end
L0_575.OnPropertyChange = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_580)
  A0_580.Who = nil
  A0_580.Entered = 0
  A0_580:RegisterState("Inactive")
  A0_580:RegisterState("Empty")
  A0_580:RegisterState("Occupied")
  A0_580:OnReset()
  A0_580:Activate(1)
end
L0_575.OnInit = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_581)
  local L1_582
end
L0_575.OnShutDown = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_583, A1_584)
end
L0_575.OnSave = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_585, A1_586)
end
L0_575.OnLoad = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_587)
  local L1_588, L2_589
  L1_588 = new
  L2_589 = A0_587.GetDirectionVector
  L2_589 = L2_589(A0_587)
  L1_588 = L1_588(L2_589, L2_589(A0_587))
  A0_587.imp = L1_588
  L2_589 = A0_587
  L1_588 = A0_587.Activate
  L1_588(L2_589, 1)
  L1_588 = {}
  L2_589 = A0_587.Properties
  L2_589 = L2_589.DimX
  L2_589 = -L2_589
  L2_589 = L2_589 / 2
  L1_588.x = L2_589
  L2_589 = A0_587.Properties
  L2_589 = L2_589.DimY
  L2_589 = -L2_589
  L2_589 = L2_589 / 2
  L1_588.y = L2_589
  L2_589 = A0_587.Properties
  L2_589 = L2_589.DimZ
  L2_589 = -L2_589
  L2_589 = L2_589 / 2
  L1_588.z = L2_589
  L2_589 = {}
  L2_589.x = A0_587.Properties.DimX / 2
  L2_589.y = A0_587.Properties.DimY / 2
  L2_589.z = A0_587.Properties.DimZ / 2
  A0_587:SetBBox(L1_588, L2_589)
  A0_587.Who = nil
  A0_587.UpdateCounter = 0
  A0_587.Entered = 0
  A0_587.MinSpeed2 = A0_587.Properties.MinSpeed * A0_587.Properties.MinSpeed
  A0_587.TotalImpulseDuration = A0_587.Properties.ImpulseFadeInTime + A0_587.Properties.ImpulseDuration
  if A0_587.Properties.bEnabled == 1 then
    A0_587:GotoState("Empty")
  else
    A0_587:GotoState("Inactive")
  end
end
L0_575.OnReset = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_590, A1_591)
  local L2_592, L3_593, L4_594, L5_595, L6_596, L7_597, L8_598
  L2_592 = System
  L2_592 = L2_592.LogToConsole
  L3_593 = "Something entered "
  L2_592(L3_593)
  L2_592 = A0_590.Entered
  if L2_592 ~= 0 then
    return
  end
  L2_592 = AI
  L3_593 = L2_592
  L2_592 = L2_592.RegisterWithAI
  L4_594 = A0_590.id
  L5_595 = 0
  L2_592(L3_593, L4_594, L5_595)
  if A1_591 then
    L2_592 = A1_591.type
    if L2_592 == "Vehicle" then
      L2_592 = new
      L4_594 = A1_591
      L3_593 = A1_591.GetVelocity
      L8_598 = L3_593(L4_594)
      L2_592 = L2_592(L3_593, L4_594, L5_595, L6_596, L7_597, L8_598, L3_593(L4_594))
      L3_593 = new
      L4_594 = A0_590.imp
      L3_593 = L3_593(L4_594)
      L3_593.z = 0
      L4_594 = 0
      L5_595 = 0
      L6_596 = 360
      L7_597 = L2_592.x
      if L7_597 == 0 then
        L7_597 = L2_592.y
      else
        if L7_597 ~= 0 then
          L7_597 = L3_593.x
          if L7_597 == 0 then
            L7_597 = L3_593.y
          else
            if L7_597 ~= 0 then
              L2_592.z = 0
              L7_597 = L2_592.x
              L8_598 = L2_592.x
              L7_597 = L7_597 * L8_598
              L8_598 = L2_592.y
              L8_598 = L8_598 * L2_592.y
              L4_594 = L7_597 + L8_598
              L7_597 = NormalizeVector
              L8_598 = L2_592
              L7_597(L8_598)
              L7_597 = NormalizeVector
              L8_598 = L3_593
              L7_597(L8_598)
              L7_597 = dotproduct3d
              L8_598 = L2_592
              L7_597 = L7_597(L8_598, L3_593)
              L7_597 = 1 - L7_597
              L6_596 = L7_597 * 180
          end
          else
            L6_596 = 0
            L7_597 = L2_592.z
            L8_598 = L2_592.z
            L4_594 = L7_597 * L8_598
          end
      end
      else
        L7_597 = L2_592.z
        if L7_597 ~= 0 then
          L7_597 = L3_593.z
          if L7_597 ~= 0 then
            L7_597 = L2_592.z
            L8_598 = L2_592.z
            L4_594 = L7_597 * L8_598
            L2_592.z = 1
            L7_597 = NormalizeVector
            L8_598 = L3_593
            L7_597(L8_598)
            L7_597 = dotproduct3d
            L8_598 = L2_592
            L7_597 = L7_597(L8_598, L3_593)
            L7_597 = 1 - L7_597
            L6_596 = L7_597 * 180
          else
            L6_596 = 0
            L7_597 = L2_592.x
            L8_598 = L2_592.x
            L7_597 = L7_597 * L8_598
            L8_598 = L2_592.y
            L8_598 = L8_598 * L2_592.y
            L4_594 = L7_597 + L8_598
          end
        else
          return
        end
      end
      L7_597 = System
      L7_597 = L7_597.LogToConsole
      L8_598 = "Boat entered with speed2="
      L8_598 = L8_598 .. L4_594 .. "Angle=" .. L6_596
      L7_597(L8_598)
      L7_597 = A0_590.MinSpeed2
      if L4_594 >= L7_597 then
        L7_597 = A0_590.Properties
        L7_597 = L7_597.MaxAngleOfImpact
        if L6_596 <= L7_597 then
          L7_597 = A0_590.Properties
          L7_597 = L7_597.ScriptCommand
          if L7_597 then
            L7_597 = A0_590.Properties
            L7_597 = L7_597.ScriptCommand
            if L7_597 ~= "" then
              L7_597 = dostring
              L8_598 = A0_590.Properties
              L8_598 = L8_598.ScriptCommand
              L7_597(L8_598)
            end
          end
          L7_597 = A0_590.Properties
          L7_597 = L7_597.PlaySequence
          if L7_597 ~= "" then
            L7_597 = System
            L7_597 = L7_597.LogToConsole
            L8_598 = "Playing sequence: "
            L8_598 = L8_598 .. A0_590.Properties.PlaySequence
            L7_597(L8_598)
            L7_597 = Movie
            L7_597 = L7_597.PlaySequence
            L8_598 = A0_590.Properties
            L8_598 = L8_598.PlaySequence
            L7_597(L8_598)
          end
          L7_597 = BroadcastEvent
          L8_598 = A0_590
          L7_597(L8_598, "Enter")
          A0_590.boat = A1_591
          L7_597 = A0_590.Entered
          if L7_597 == 0 then
            L7_597 = L3_593.x
            if L7_597 == 0 then
              L7_597 = L3_593.y
            elseif L7_597 ~= 0 then
              L7_597 = A0_590.boat
              L7_597 = L7_597.boat_params
              L7_597 = L7_597.fMass
              L8_598 = new
              L8_598 = L8_598(L2_592)
              L8_598.x = L3_593.x - L8_598.x
              L8_598.y = L3_593.y - L8_598.y
              L8_598.z = 0
              if L8_598.x ~= 0 or L8_598.y ~= 0 then
                NormalizeVector(L8_598)
                A0_590.boat:AddImpulseObj(L8_598, L7_597 * sqrt(L8_598.x * L8_598.x + L8_598.y * L8_598.y) * 10)
              end
            end
          end
          A0_590.Entered = 1
          L7_597 = new
          L8_598 = A0_590.boat
          L8_598 = L8_598.GetAngles
          L8_598 = L8_598(L8_598)
          L7_597 = L7_597(L8_598, L8_598(L8_598))
          A0_590.InitialAngle = L7_597
          L7_597 = _time
          A0_590.InitImpulseTime = L7_597
          L8_598 = A0_590
          L7_597 = A0_590.SetTimer
          L7_597(L8_598, 1)
          L7_597 = A0_590.boat
          L7_597 = L7_597.boat_params
          L7_597 = L7_597.fMass
          L7_597 = L7_597 / 800
          L8_598 = A0_590.Properties
          L8_598 = L8_598.ImpulseStrength
          L7_597 = L7_597 * L8_598
          A0_590.MaxImpulse = L7_597
          L7_597 = A0_590.Who
          if L7_597 == nil then
            L7_597 = player
            A0_590.Who = L7_597
            L8_598 = A0_590
            L7_597 = A0_590.GotoState
            L7_597(L8_598, "Occupied")
          end
        end
      end
    end
  end
  if A1_591 then
    L2_592 = System
    L2_592 = L2_592.LogToConsole
    L3_593 = "Player "
    L5_595 = A1_591
    L4_594 = A1_591.GetName
    L4_594 = L4_594(L5_595)
    L5_595 = " Enter BoatTrampolineTrigger "
    L7_597 = A0_590
    L6_596 = A0_590.GetName
    L6_596 = L6_596(L7_597)
    L3_593 = L3_593 .. L4_594 .. L5_595 .. L6_596
    L2_592(L3_593)
  end
end
L0_575.Event_Enter = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_599, A1_600)
  if A0_599.Entered == 0 then
    return
  end
  A0_599.Entered = 0
  if A1_600 ~= nil then
    System.LogToConsole("Player " .. A1_600:GetName() .. " Leave BoatTrampolineTrigger " .. A0_599:GetName())
  end
  BroadcastEvent(A0_599, "Leave")
end
L0_575.Event_Leave = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_601, A1_602)
  A0_601:GotoState("Empty")
  BroadcastEvent(A0_601, "Enable")
end
L0_575.Event_Enable = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_603, A1_604)
  A0_603:GotoState("Inactive")
  AI:RegisterWithAI(A0_603.id, 0)
  BroadcastEvent(A0_603, "Disable")
end
L0_575.Event_Disable = L1_576
L0_575 = BoatTrampolineTrigger
function L1_576(A0_605)
  local L1_606, L2_607
  L2_607 = A0_605.InitialAngle
  if A0_605.boat then
    if A0_605.Properties.ImpulseFadeInTime > 0 then
      L1_606 = (_time - A0_605.InitImpulseTime) / A0_605.Properties.ImpulseFadeInTime
    else
      L1_606 = 1
    end
    if L1_606 > 1 then
      L1_606 = 1
    end
    System.LogToConsole("Applying impulse =" .. A0_605.MaxImpulse * L1_606)
    A0_605.boat:AddImpulseObj(A0_605.imp, A0_605.MaxImpulse * L1_606)
    if _time - A0_605.InitImpulseTime >= A0_605.TotalImpulseDuration and 0 <= A0_605.TotalImpulseDuration then
      A0_605:KillTimer()
      A0_605:Event_Leave(A0_605, A0_605.Who)
      A0_605.boat = nil
      if 0 < A0_605.Properties.bKillOnTrigger then
        Server:RemoveEntity(A0_605.id)
      elseif 0 < A0_605.Properties.bTriggerOnce then
        A0_605:GotoState("Inactive")
      else
        A0_605:GotoState("Empty")
      end
    else
      A0_605:SetTimer(1)
    end
  end
end
L0_575.OnTimeF = L1_576
L0_575 = BoatTrampolineTrigger
L1_576 = {}
function L2_577(A0_608)
  printf("BoatTrampolineTrigger deactivating")
end
L1_576.OnBeginState = L2_577
function L2_577(A0_609)
  printf("BoatTrampolineTrigger activating")
end
L1_576.OnEndState = L2_577
L0_575.Inactive = L1_576
L0_575 = BoatTrampolineTrigger
L1_576 = {}
function L2_577(A0_610)
  local L1_611
  A0_610.Who = nil
  A0_610.UpdateCounter = 0
  A0_610.Entered = 0
end
L1_576.OnBeginState = L2_577
function L2_577(A0_612, A1_613)
  if A0_612.Who == nil then
    A0_612.Who = A1_613
    A0_612:GotoState("Occupied")
  end
end
L1_576.OnContact = L2_577
function L2_577(A0_614, A1_615, A2_616)
  if A0_614.Who == nil then
    A0_614.Who = A1_615
    A0_614:GotoState("Occupied")
  end
end
L1_576.OnEnterArea = L2_577
L2_577 = BoatTrampolineTrigger
L2_577 = L2_577.OnTimeF
L1_576.OnTimer = L2_577
L0_575.Empty = L1_576
L0_575 = BoatTrampolineTrigger
L1_576 = {}
function L2_577(A0_617)
  A0_617:Event_Enter(A0_617.Who)
  System.LogToConsole("Enter occupied")
end
L1_576.OnBeginState = L2_577
function L2_577(A0_618, A1_619)
end
L1_576.OnContact = L2_577
L2_577 = BoatTrampolineTrigger
L2_577 = L2_577.OnTimeF
L1_576.OnTimer = L2_577
L0_575.Occupied = L1_576
L0_575 = BoatTrampolineTrigger
L1_576 = {}
L2_577 = {}
L3_578 = {
  BoatTrampolineTrigger.Event_Disable,
  "bool"
}
L2_577.Disable = L3_578
L3_578 = {
  BoatTrampolineTrigger.Event_Enable,
  "bool"
}
L2_577.Enable = L3_578
L3_578 = {
  BoatTrampolineTrigger.Event_Enter,
  "bool"
}
L2_577.Enter = L3_578
L3_578 = {
  BoatTrampolineTrigger.Event_Leave,
  "bool"
}
L2_577.Leave = L3_578
L1_576.Inputs = L2_577
L2_577 = {}
L2_577.Disable = "bool"
L2_577.Enable = "bool"
L2_577.Enter = "bool"
L2_577.Leave = "bool"
L1_576.Outputs = L2_577
L0_575.FlowEvents = L1_576
