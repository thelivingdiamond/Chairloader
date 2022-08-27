local L0_4901, L1_4902, L2_4903, L3_4904
L0_4901 = {}
L1_4902 = {}
L1_4902.soclasses_SmartObjectClass = "Door,AutomaticDoor"
L1_4902.MapVisMask = 0
L2_4903 = {}
L2_4903.X = 0
L2_4903.Y = 0
L2_4903.Z = 1
L1_4902.Direction = L2_4903
L1_4902.CloseDelay = 1.5
L2_4903 = {}
L2_4903.X = 3
L2_4903.Y = 3
L2_4903.Z = 2
L1_4902.BBOX_Size = L2_4903
L1_4902.MovingDistance = 2.4
L1_4902.MovingSpeed = 4
L1_4902.bPlayerBounce = 1
L1_4902.bPlayerOnly = 0
L1_4902.fileModel = "Objects/Indoor/doors/default_200w250h.cgf"
L1_4902.soundOpenSound = "Sounds/doors/open.wav"
L1_4902.soundCloseSound = "Sounds/doors/close.wav"
L1_4902.bAutomatic = 1
L1_4902.bCloseTimer = 1
L1_4902.bEnabled = 1
L1_4902.nNeededKey = -1
L0_4901.Properties = L1_4902
L0_4901.CurrModel = "Objects/lift/lift.cgf"
L1_4902 = {}
L1_4902.x = 0
L1_4902.y = 0
L1_4902.z = 0
L0_4901.temp_vec = L1_4902
L0_4901.Distance = 0
L0_4901.EndReached = nil
L0_4901.OpeningTime = 0
L0_4901.bLocked = false
L0_4901.bInitialized = nil
AutomaticDoor1Piece = L0_4901
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4905)
  A0_4905:OnReset()
  if A0_4905.Properties.fileOpenSound ~= A0_4905.CurrOpenSound then
    A0_4905.CurrOpenSound = A0_4905.Properties.fileOpenSound
  end
  if A0_4905.Properties.fileCloseSound ~= A0_4905.CurrCloseSound then
    A0_4905.CurrCloseSound = A0_4905.Properties.fileCloseSound
  end
end
L0_4901.OnPropertyChange = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4906)
  A0_4906:LoadObject(A0_4906.Properties.fileModel, 0, 0)
  A0_4906:DrawObject(0, 1)
  A0_4906:CreateStaticEntity(100, 0)
  A0_4906.CurrOpenSound = A0_4906.Properties.fileOpenSound
  A0_4906.CurrCloseSound = A0_4906.Properties.fileCloseSound
  A0_4906:SetBBox({
    x = -(A0_4906.Properties.BBOX_Size.X * 0.5),
    y = -(A0_4906.Properties.BBOX_Size.Y * 0.5),
    z = -(A0_4906.Properties.BBOX_Size.Z * 0.5)
  }, {
    x = A0_4906.Properties.BBOX_Size.X * 0.5,
    y = A0_4906.Properties.BBOX_Size.Y * 0.5,
    z = A0_4906.Properties.BBOX_Size.Z * 0.5
  })
  A0_4906:RegisterState("Opened")
  A0_4906:RegisterState("Closed")
  if A0_4906.Properties.nNeededKey ~= -1 then
    A0_4906.bLocked = 1
  else
    A0_4906.bLocked = 0
  end
  A0_4906:GotoState("Closed")
  if A0_4906.MovingSpeed == 0 then
    A0_4906.MovingSpeed = 0.01
  end
  A0_4906.OpeningTime = A0_4906.Properties.MovingDistance / A0_4906.Properties.MovingSpeed
  A0_4906.Timer = 0
  System.ActivatePortal(A0_4906:GetPos(), 0, A0_4906.id)
end
L0_4901.OnReset = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4907)
  A0_4907:Activate(0)
  A0_4907:TrackColliders(1)
  if A0_4907.bInitialized == nil then
    A0_4907:OnReset()
    A0_4907:NetPresent(nil)
    A0_4907.bInitialized = 1
  end
end
L0_4901.OnInit = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4908, A1_4909)
  if A0_4908.Properties.bEnabled == 0 then
    return
  end
  A0_4908:GotoState("Opened")
  BroadcastEvent(A0_4908, "Open")
  System.ActivatePortal(A0_4908:GetPos(), 1, A0_4908.id)
end
L0_4901.Event_Open = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4910, A1_4911)
  if A0_4910.Properties.bEnabled == 0 then
    return
  end
  A0_4910:GotoState("Closed")
  BroadcastEvent(A0_4910, "Close")
end
L0_4901.Event_Close = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4912, A1_4913)
  if A0_4912.Properties.bEnabled == 0 then
    return
  end
  A0_4912:Activate(0)
  BroadcastEvent(A0_4912, "Opened")
end
L0_4901.Event_Opened = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4914, A1_4915)
  if A0_4914.Properties.bEnabled == 0 then
    return
  end
  A0_4914:Activate(0)
  BroadcastEvent(A0_4914, "Closed")
  System.ActivatePortal(A0_4914:GetPos(), 0, A0_4914.id)
end
L0_4901.Event_Closed = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4916, A1_4917)
  A0_4916.Properties.bEnabled = 1
end
L0_4901.Event_Enable = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4918, A1_4919)
  A0_4918.Properties.bEnabled = 0
end
L0_4901.Event_Disable = L1_4902
L0_4901 = AutomaticDoor1Piece
L1_4902 = {}
L2_4903 = AutomaticDoor1Piece
L2_4903 = L2_4903.OnInit
L1_4902.OnInit = L2_4903
L2_4903 = {}
function L3_4904(A0_4920)
  if A0_4920.Properties.bCloseTimer == 1 then
    A0_4920:SetTimer(A0_4920.Properties.CloseDelay * 1000)
  end
  if A0_4920.Timer ~= 0 then
    Game:KillTimer(A0_4920.Timer)
  end
  A0_4920.Timer = Game:SetTimer(A0_4920, A0_4920.OpeningTime)
  A0_4920.EventSent = nil
end
L2_4903.OnBeginState = L3_4904
function L3_4904(A0_4921)
  Game:KillTimer(A0_4921.Timer)
  A0_4921.Timer = 0
end
L2_4903.OnEndState = L3_4904
function L3_4904(A0_4922, A1_4923)
  if A0_4922.Properties.bCloseTimer == 1 then
    if A0_4922.Properties.bPlayerOnly == 1 and A1_4923.type ~= "Player" then
      return
    end
    A0_4922:SetTimer(A0_4922.Properties.CloseDelay * 1000)
  end
end
L2_4903.OnContact = L3_4904
function L3_4904(A0_4924)
  A0_4924:GotoState("Closed")
  A0_4924:Event_Close(A0_4924)
end
L2_4903.OnTimer = L3_4904
function L3_4904(A0_4925, A1_4926)
  if A1_4926 == ScriptEvent_OnTimer then
    A0_4925.temp_vec.x = A0_4925.Properties.Direction.X * A0_4925.Properties.MovingDistance
    A0_4925.temp_vec.y = A0_4925.Properties.Direction.Y * A0_4925.Properties.MovingDistance
    A0_4925.temp_vec.z = A0_4925.Properties.Direction.Z * A0_4925.Properties.MovingDistance
    A0_4925:SetObjectPos(0, A0_4925.temp_vec)
  end
end
L2_4903.OnEvent = L3_4904
L1_4902.Opened = L2_4903
L2_4903 = {}
function L3_4904(A0_4927)
  if A0_4927.Timer ~= 0 then
    Game:KillTimer(A0_4927.Timer)
  end
  A0_4927.Timer = Game:SetTimer(A0_4927, A0_4927.OpeningTime)
  A0_4927.EventSent = nil
  A0_4927.EndReached = nil
end
L2_4903.OnBeginState = L3_4904
function L3_4904(A0_4928)
  Game:KillTimer(A0_4928.Timer)
  A0_4928.Timer = 0
end
L2_4903.OnEndState = L3_4904
function L3_4904(A0_4929, A1_4930)
  if A0_4929.Properties.bAutomatic == 1 then
    if A0_4929.bLocked ~= 0 then
      if A1_4930 and A1_4930.cnt and A1_4930.cnt.KeyCardAvailable then
        if A1_4930.cnt:KeyCardAvailable(A0_4929.Properties.nNeededKey) then
          A1_4930.cnt:SetKeyCard(A0_4929.Properties.nNeededKey, 0)
          A0_4929.bLocked = 0
          Hud:AddMessage("Door Unlocked.")
        else
          if not A0_4929.MsgShown and KeyCardInfo and KeyCardInfo[A0_4929.Properties.nNeededKey] then
            Game:ShowIngameDialog(-1, "", "", 12, "You need the " .. KeyCardInfo[A0_4929.Properties.nNeededKey].Desc .. " to open this door...", 3)
            Hud:AddMessage("You need the " .. KeyCardInfo[A0_4929.Properties.nNeededKey].Desc .. " to open this door...")
            A0_4929.MsgShown = 1
          end
          A0_4929:SetTimer(100)
          return
        end
      else
        Hud:AddMessage("This door is locked.")
        return
      end
    end
    if A0_4929.Properties.bPlayerOnly == 1 and A1_4930.type ~= "Player" then
      return
    end
    if A0_4929.EndReached == nil then
      A0_4929:Event_Open(A0_4929)
    end
  end
end
L2_4903.OnContact = L3_4904
function L3_4904(A0_4931)
  local L1_4932
  A0_4931.MsgShown = nil
end
L2_4903.OnTimer = L3_4904
function L3_4904(A0_4933, A1_4934)
  if A1_4934 == ScriptEvent_OnTimer then
    A0_4933:SetObjectPos(0, g_Vectors.v000)
  end
end
L2_4903.OnEvent = L3_4904
L1_4902.Closed = L2_4903
L0_4901.Server = L1_4902
L0_4901 = AutomaticDoor1Piece
L1_4902 = {}
L2_4903 = AutomaticDoor1Piece
L2_4903 = L2_4903.OnInit
L1_4902.OnInit = L2_4903
L2_4903 = {}
function L3_4904(A0_4935)
  A0_4935:StartAnimation(0, "open")
  if A0_4935.OpenSound then
  end
  A0_4935:Activate(1)
end
L2_4903.OnBeginState = L3_4904
function L3_4904(A0_4936, A1_4937)
  A0_4936.Distance = A0_4936.Distance + A1_4937 * A0_4936.Properties.MovingSpeed
  if A0_4936.Distance > A0_4936.Properties.MovingDistance then
    A0_4936.Distance = A0_4936.Properties.MovingDistance
    if not A0_4936.EventSent then
      A0_4936.Event_Opened(A0_4936)
    end
    A0_4936.EventSent = 1
  end
  A0_4936.temp_vec.x = A0_4936.Properties.Direction.X * A0_4936.Distance
  A0_4936.temp_vec.y = A0_4936.Properties.Direction.Y * A0_4936.Distance
  A0_4936.temp_vec.z = A0_4936.Properties.Direction.Z * A0_4936.Distance
  A0_4936:SetObjectPos(0, A0_4936.temp_vec)
end
L2_4903.OnUpdate = L3_4904
L1_4902.Opened = L2_4903
L2_4903 = {}
function L3_4904(A0_4938)
  A0_4938:StartAnimation(0, "close")
  if A0_4938.CloseSound then
  end
  A0_4938:Activate(1)
end
L2_4903.OnBeginState = L3_4904
function L3_4904(A0_4939, A1_4940)
  A0_4939.Distance = A0_4939.Distance - A1_4940 * A0_4939.Properties.MovingSpeed
  if A0_4939.Distance < 0 then
    A0_4939.Distance = 0
    if not A0_4939.EventSent then
      A0_4939.Event_Closed(A0_4939)
    end
    A0_4939.EventSent = 1
  end
  A0_4939.temp_vec.x = A0_4939.Properties.Direction.X * A0_4939.Distance
  A0_4939.temp_vec.y = A0_4939.Properties.Direction.Y * A0_4939.Distance
  A0_4939.temp_vec.z = A0_4939.Properties.Direction.Z * A0_4939.Distance
  A0_4939:SetObjectPos(0, A0_4939.temp_vec)
end
L2_4903.OnUpdate = L3_4904
L1_4902.Closed = L2_4903
L0_4901.Client = L1_4902
L0_4901 = AutomaticDoor1Piece
function L1_4902(A0_4941)
  local L1_4942
end
L0_4901.OnShutDown = L1_4902
L0_4901 = AutomaticDoor1Piece
L1_4902 = {}
L2_4903 = {}
L3_4904 = {
  AutomaticDoor1Piece.Event_Close,
  "bool"
}
L2_4903.Close = L3_4904
L3_4904 = {
  AutomaticDoor1Piece.Event_Closed,
  "bool"
}
L2_4903.Closed = L3_4904
L3_4904 = {
  AutomaticDoor1Piece.Event_Disable,
  "bool"
}
L2_4903.Disable = L3_4904
L3_4904 = {
  AutomaticDoor1Piece.Event_Enable,
  "bool"
}
L2_4903.Enable = L3_4904
L3_4904 = {
  AutomaticDoor1Piece.Event_Open,
  "bool"
}
L2_4903.Open = L3_4904
L3_4904 = {
  AutomaticDoor1Piece.Event_Opened,
  "bool"
}
L2_4903.Opened = L3_4904
L1_4902.Inputs = L2_4903
L2_4903 = {}
L2_4903.Close = "bool"
L2_4903.Closed = "bool"
L2_4903.Disable = "bool"
L2_4903.Enable = "bool"
L2_4903.Open = "bool"
L2_4903.Opened = "bool"
L1_4902.Outputs = L2_4903
L0_4901.FlowEvents = L1_4902
