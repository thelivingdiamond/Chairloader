Elevator = {
  Server = {},
  Client = {},
  Properties = {
    soclasses_SmartObjectClass = "Elevator",
    objModel = "engine/engineassets/objects/default.cgf",
    Sounds = {
      soundSoundOnStart = "",
      soundSoundOnMove = "",
      soundSoundOnStop = ""
    },
    bAutomatic = 0,
    nFloorCount = 2,
    fFloorHeight = 5,
    nInitialFloor = 0,
    nDestinationFloor = 1,
    bExactPosition = 1,
    Slide = {
      fSpeed = 1,
      fAcceleration = 1,
      sAxis = "z",
      fStopTime = 0.75
    }
  },
  Editor = {
    Icon = "elevator.bmp",
    IconOnTop = 0
  }
}
Net.Expose({
  Class = Elevator,
  ClientMethods = {
    ClSlide = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      INT8,
      BOOL
    },
    ClInitMoving = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      VEC3,
      INT8,
      INT8,
      FLOAT,
      FLOAT
    }
  },
  ServerMethods = {},
  ServerProperties = {}
})
function Elevator.OnPropertyChange(A0_5037)
  A0_5037:Reset()
end
function Elevator.OnReset(A0_5038)
  A0_5038:Reset()
end
function Elevator.OnSpawn(A0_5039)
  CryAction.CreateGameObjectForEntity(A0_5039.id)
  CryAction.BindGameObjectToNetwork(A0_5039.id)
  CryAction.ForceGameObjectUpdate(A0_5039.id, true)
  A0_5039.isServer = CryAction.IsServer()
  A0_5039.isClient = CryAction.IsClient()
  A0_5039.originalpos = A0_5039:GetWorldPos()
  A0_5039:Reset()
end
function Elevator.Server.OnStartGame(A0_5040)
  A0_5040.originalpos = A0_5040:GetWorldPos()
  A0_5040:OnReset()
end
function Elevator.OnDestroy(A0_5041)
  local L1_5042
end
function Elevator.DoPhysicalize(A0_5043)
  if A0_5043.currModel ~= A0_5043.Properties.objModel then
    CryAction.ActivateExtensionForGameObject(A0_5043.id, "ScriptControlledPhysics", false)
    A0_5043:LoadObject(0, A0_5043.Properties.objModel)
    A0_5043:Physicalize(0, PE_RIGID, {mass = 0})
    CryAction.ActivateExtensionForGameObject(A0_5043.id, "ScriptControlledPhysics", true)
  end
  A0_5043.currModel = A0_5043.Properties.objModel
end
function Elevator.OnSave(A0_5044, A1_5045)
  A1_5045.currFloor = A0_5044.currFloor
  A1_5045.goalFloor = A0_5044.goalFloor
  A1_5045.prevFloor = A0_5044.prevFloor
  A1_5045.nextFloor = A0_5044.nextFloor
  A1_5045.resting = A0_5044.resting
  A1_5045.active = A0_5044:IsActive()
end
function Elevator.OnLoad(A0_5046, A1_5047)
  A0_5046.currFloor = A1_5047.currFloor
  A0_5046.goalFloor = A1_5047.goalFloor
  A0_5046.prevFloor = A1_5047.prevFloor
  A0_5046.nextFloor = A1_5047.nextFloor
  A0_5046.resting = A1_5047.resting
  A0_5046:Activate(A1_5047.active and 1 or 0)
  if A1_5047.active then
  end
end
function Elevator.Reset(A0_5048)
  local L1_5049, L2_5050, L3_5051, L4_5052, L5_5053, L6_5054, L7_5055, L8_5056, L9_5057, L10_5058
  L1_5049 = A0_5048.Activate
  L1_5049(L2_5050, L3_5051)
  L1_5049 = A0_5048.DoPhysicalize
  L1_5049(L2_5050)
  L1_5049 = A0_5048.scp
  L1_5049 = L1_5049.Reset
  L1_5049(L2_5050)
  L1_5049 = A0_5048.Properties
  L1_5049 = L1_5049.nInitialFloor
  A0_5048.floorpos = L2_5050
  L2_5050[L1_5049] = L3_5051
  if L2_5050 > 0 then
    for L5_5053 = 0, L3_5051 - 1 do
      L6_5054 = vecNew
      L7_5055 = A0_5048.originalpos
      L6_5054 = L6_5054(L7_5055)
      L7_5055 = A0_5048.Properties
      L7_5055 = L7_5055.Slide
      L7_5055 = L7_5055.sAxis
      L8_5056 = A0_5048.Properties
      L8_5056 = L8_5056.fFloorHeight
      L9_5057 = L5_5053 * L8_5056
      L10_5058 = L1_5049 * L8_5056
      L9_5057 = L9_5057 - L10_5058
      L10_5058 = g_Vectors
      L10_5058 = L10_5058.temp_v1
      if L7_5055 == "X" or L7_5055 == "x" then
        L10_5058 = A0_5048:GetDirectionVector(0, L10_5058)
      elseif L7_5055 == "Y" or L7_5055 == "y" then
        L10_5058 = A0_5048:GetDirectionVector(1, L10_5058)
      else
        L10_5058 = A0_5048:GetDirectionVector(2, L10_5058)
      end
      L6_5054.x = L6_5054.x + L10_5058.x * L9_5057
      L6_5054.y = L6_5054.y + L10_5058.y * L9_5057
      L6_5054.z = L6_5054.z + L10_5058.z * L9_5057
      A0_5048.floorpos[L5_5053] = L6_5054
    end
  end
  A0_5048.currFloor = L1_5049
  A0_5048.goalFloor = L1_5049
  A0_5048.prevFloor = L1_5049
  A0_5048.nextFloor = nil
  A0_5048.resting = true
  L5_5053 = L1_5049
  L2_5050(L3_5051, L4_5052, L5_5053)
  L2_5050 = L2_5050 ~= 0
  A0_5048.automatic = L2_5050
  if L2_5050 then
    L5_5053 = A0_5048
    L6_5054 = L2_5050
    L7_5055 = L3_5051
    L4_5052(L5_5053, L6_5054, L7_5055)
  end
  L2_5050(L3_5051, L4_5052)
  L2_5050(L3_5051, L4_5052)
end
function Elevator.Server.OnTimer(A0_5059, A1_5060, A2_5061)
  if A1_5060 == 1 then
    if A0_5059.automatic and not A0_5059.resting then
      A0_5059:Slide(A0_5059.Properties.nInitialFloor)
    elseif A0_5059.nextFloor and A0_5059.nextFloor ~= A0_5059.currFloor then
      A0_5059:Slide(A0_5059.nextFloor)
      A0_5059.nextFloor = nil
    end
  elseif A0_5059.automatic then
    A0_5059:Slide(A0_5059.Properties.nDestinationFloor)
  end
end
function Elevator.Server.OnEnterArea(A0_5062, A1_5063, A2_5064)
  if A1_5063 and A1_5063.actor then
    A0_5062:SetTimer(0, 1500)
  end
end
function Elevator.UpdateSlide(A0_5065, A1_5066)
  if A0_5065.currFloor == A0_5065.goalFloor then
    A0_5065:ActivateOutput("CurrentFloor", A0_5065.currFloor)
    return
  end
  if A0_5065:HasArrived() then
    A0_5065.currFloor = A0_5065.goalFloor
    A0_5065:ActivateOutput("CurrentFloor", A0_5065.currFloor)
    if A0_5065.prevFloor > A0_5065.currFloor then
      A0_5065:ActivateOutput("StoppedSlidingDown", 1)
    else
      A0_5065:ActivateOutput("StoppedSlidingUp", 1)
    end
    if A0_5065.isServer then
      if A0_5065.automatic and A0_5065.currFloor == A0_5065.Properties.nInitialFloor then
        A0_5065.resting = true
      end
      A0_5065:SetTimer(1, 3000)
    end
    A0_5065:Activate(0)
  else
    A0_5065.resting = false
  end
end
function Elevator.HasArrived(A0_5067)
  return A0_5067.scp:HasArrived()
end
function Elevator.Server.OnUpdate(A0_5068, A1_5069)
  A0_5068:UpdateSlide(A1_5069)
end
function Elevator.Client.OnUpdate(A0_5070, A1_5071)
  if not A0_5070.isServer then
    A0_5070:UpdateSlide(A1_5071)
  end
end
function Elevator.Server.OnInitClient(A0_5072, A1_5073)
  if A0_5072.currFloor == A0_5072.goalFloor then
    A0_5072.onClient:ClSlide(A1_5073, A0_5072.goalFloor, true)
  else
    A0_5072.onClient:ClInitMoving(A1_5073, A0_5072.currFloor, A0_5072.goalFloor, A0_5072.scp:GetSpeed(), A0_5072.scp:GetAcceleration())
  end
end
function Elevator.Server.SvRequestSlide(A0_5074, A1_5075, A2_5076)
  A0_5074:Slide(user, A2_5076)
end
function Elevator.Client.ClSlide(A0_5077, A1_5078)
  if not A0_5077.isServer then
    A0_5077:Slide(A1_5078)
  end
end
function Elevator.OnPostStep(A0_5079)
  local L1_5080
end
function Elevator.SlideInternal(A0_5081, A1_5082, A2_5083, A3_5084, A4_5085, A5_5086)
  if A1_5082 >= A0_5081.Properties.nFloorCount then
    A1_5082 = A0_5081.Properties.nFloorCount - 1
  elseif A1_5082 < 0 then
    A1_5082 = 0
  end
  if A0_5081.currFloor == A1_5082 and A0_5081.scp:GetSpeed() == 0 then
    return
  elseif A0_5081.goalFloor == A1_5082 then
    return
  end
  if 0 >= A0_5081.scp:GetSpeed() then
    if A1_5082 < A0_5081.currFloor then
      A0_5081:ActivateOutput("StartedSlidingDown", 1)
    else
      A0_5081:ActivateOutput("StartedSlidingUp", 1)
    end
    A0_5081.goalFloor = A1_5082
    A0_5081.prevFloor = A0_5081.currFloor
    A0_5081.currFloor = -1
    A0_5081:Activate(1)
    if A0_5081.isServer then
      A0_5081.allClients:ClSlide(A1_5082, false)
    end
    A0_5081.scp:MoveTo(A0_5081.floorpos[A0_5081.goalFloor], A0_5081:GetSpeed(), A2_5083, A3_5084, A4_5085, A5_5086)
  else
    A0_5081.nextFloor = A1_5082
  end
end
function Elevator.Slide(A0_5087, A1_5088)
  A0_5087:SlideInternal(A1_5088, A0_5087.Properties.Slide.fSpeed, A0_5087.Properties.Slide.fAcceleration, A0_5087.Properties.Slide.fStopTime, A0_5087.Properties.bExactPosition)
end
function Elevator.Sound(A0_5089, A1_5090, A2_5091)
  local L3_5092
  if not A1_5090 or A1_5090 == "" then
    return
  end
  if A2_5091 then
    L3_5092 = A0_5089.soundIds
    if not L3_5092 then
      L3_5092 = {}
      A0_5089.soundIds = L3_5092
    end
  end
  if A2_5091 then
    L3_5092 = A0_5089.soundIds
    L3_5092[A1_5090] = id
  end
end
function Elevator.SoundOff(A0_5093, A1_5094)
  if A0_5093.soundIds and A0_5093.soundIds[A1_5094] then
    A0_5093:StopSound(A0_5093.soundIds[A1_5094])
    A0_5093.soundIds[A1_5094] = nil
  end
end
function Elevator.SetCurrentFloor(A0_5095, A1_5096, A2_5097)
  A0_5095:SlideInternal(A2_5097, 500, 500, 0, 1)
end
function Elevator.SetDestinationFloor(A0_5098, A1_5099, A2_5100)
  A0_5098:Activate(1)
  A0_5098:Slide(A2_5100)
end
function Elevator.Up(A0_5101, A1_5102)
  A1_5102 = A1_5102 or A0_5101.currFloor + 1
  if A0_5101.currFloor == A1_5102 then
    A0_5101:Slide(A0_5101.goalFloor + 1)
  else
    A0_5101:Slide(A1_5102)
  end
end
function Elevator.Down(A0_5103, A1_5104)
  A1_5104 = A1_5104 or A0_5103.currFloor - 1
  if A0_5103.currFloor == A1_5104 then
    A0_5103:Slide(A0_5103.goalFloor - 1)
  else
    A0_5103:Slide(A1_5104)
  end
end
function Elevator.Client.ClSlide(A0_5105, A1_5106, A2_5107)
  if not A0_5105.isServer then
    if not A2_5107 then
      A0_5105:Slide(A1_5106)
    else
      A0_5105.goalFloor = A1_5106
      A0_5105.currFloor = A1_5106
      A0_5105:SetWorldPos(A0_5105.floorpos[A0_5105.goalFloor])
    end
  end
end
function Elevator.Client.ClInitMoving(A0_5108, A1_5109, A2_5110, A3_5111, A4_5112)
  A0_5108.currFloor = A1_5109
  A0_5108.goalFloor = A2_5110
  A0_5108.scp:MoveTo(A0_5108.floorpos[A0_5108.goalFloor], A3_5111, A0_5108.Properties.Slide.fSpeed, A4_5112, A0_5108.Properties.Slide.fStopTime, A0_5108.Properties.bExactPosition)
  A0_5108:Activate(1)
end
Elevator.FlowEvents = {
  Inputs = {
    Up = {
      Elevator.Up,
      "any"
    },
    Down = {
      Elevator.Down,
      "any"
    },
    SetCurrentFloor = {
      Elevator.SetCurrentFloor,
      "int"
    },
    SetDestinationFloor = {
      Elevator.SetDestinationFloor,
      "int"
    }
  },
  Outputs = {
    StartedSlidingUp = "bool",
    StoppedSlidingUp = "bool",
    StartedSlidingDown = "bool",
    StoppedSlidingDown = "bool",
    CurrentFloor = "int",
    DestinationFloor = "int"
  }
}
