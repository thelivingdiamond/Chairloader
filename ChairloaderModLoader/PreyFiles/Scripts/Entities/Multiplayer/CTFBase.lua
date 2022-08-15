local L0_6302, L1_6303, L2_6304
L0_6302 = {}
L1_6303 = {}
L0_6302.Client = L1_6303
L1_6303 = {}
L0_6302.Server = L1_6303
L1_6303 = {}
L1_6303.fileModelOverride = ""
L1_6303.ModelSubObject = "main"
L1_6303.Radius = 10
L1_6303.teamName = ""
L0_6302.Properties = L1_6303
L1_6303 = {}
L1_6303.Icon = "Item.bmp"
L1_6303.IconOnTop = 1
L0_6302.Editor = L1_6303
L0_6302.HasFlag = false
L0_6302.InProximity = false
L0_6302.IsOpen = false
CTFBase = L0_6302
L0_6302 = 1
TIMER_ANIM_TRANSITION = L0_6302
L0_6302 = CTFBase
L0_6302.DEFAULT_FILE_MODEL = "engine/engineassets/objects/default.cgf"
L0_6302 = CTFBase
L0_6302 = L0_6302.Server
function L1_6303(A0_6305)
  Log("CTFBase.Server.OnInit")
  if not A0_6305.bInitialized then
    A0_6305:OnReset()
    A0_6305.bInitialized = 1
    A0_6305:SetViewDistRatio(255)
  end
  g_gameRules.game:SetTeam(g_gameRules.game:GetTeamId(A0_6305.Properties.teamName) or 0, A0_6305.id)
  A0_6305.inside = {}
end
L0_6302.OnInit = L1_6303
L0_6302 = CTFBase
L0_6302 = L0_6302.Client
function L1_6303(A0_6306)
  Log("CTFBase.Client.OnInit")
  if not A0_6306.bInitialized then
    A0_6306:OnReset()
    A0_6306.bInitialized = 1
    A0_6306:SetViewDistRatio(255)
  end
  A0_6306.inside = {}
end
L0_6302.OnInit = L1_6303
L0_6302 = CTFBase
function L1_6303(A0_6307)
  local L1_6308, L2_6309, L3_6310, L4_6311
  L1_6308 = Log
  L2_6309 = "CTFBase.OnReset"
  L1_6308(L2_6309)
  L1_6308 = A0_6307.DEFAULT_FILE_MODEL
  L2_6309 = A0_6307.Properties
  L2_6309 = L2_6309.fileModelOverride
  if L2_6309 then
    L2_6309 = A0_6307.Properties
    L2_6309 = L2_6309.fileModelOverride
    if L2_6309 ~= "" then
      L2_6309 = Log
      L3_6310 = "Override file model provided, using model '%s'"
      L4_6311 = A0_6307.Properties
      L4_6311 = L4_6311.fileModelOverride
      L2_6309(L3_6310, L4_6311)
      L2_6309 = A0_6307.Properties
      L1_6308 = L2_6309.fileModelOverride
    end
  end
  L3_6310 = A0_6307
  L2_6309 = A0_6307.LoadObject
  L4_6311 = 0
  L2_6309(L3_6310, L4_6311, L1_6308)
  L2_6309 = A0_6307.Properties
  L2_6309 = L2_6309.Radius
  L2_6309 = L2_6309 / 2
  L3_6310 = {}
  L4_6311 = -L2_6309
  L3_6310.x = L4_6311
  L4_6311 = -L2_6309
  L3_6310.y = L4_6311
  L4_6311 = -L2_6309
  L3_6310.z = L4_6311
  L4_6311 = {}
  L4_6311.x = L2_6309
  L4_6311.y = L2_6309
  L4_6311.z = L2_6309
  A0_6307:SetTriggerBBox(L3_6310, L4_6311)
  A0_6307:SetViewDistRatio(255)
  A0_6307:Physicalize(0, PE_STATIC, {mass = 0})
  A0_6307:SetFlags(ENTITY_FLAG_ON_RADAR, 0)
  A0_6307:StartAnimation(0, "base_idle", 0, 0.4, 1, 1)
end
L0_6302.OnReset = L1_6303
L0_6302 = CTFBase
function L1_6303(A0_6312, A1_6313, A2_6314)
  local L3_6315
  L3_6315 = Log
  L3_6315("CTFBase:ObjectiveAttached")
  L3_6315 = A0_6312.HasFlag
  if L3_6315 ~= A2_6314 then
    A0_6312.HasFlag = A2_6314
    L3_6315 = nil
    if A2_6314 then
      A0_6312:SetAttachmentObject(0, "flag_attachment", A1_6313, -1, 0)
      L3_6315 = "base_idle"
      BroadcastEvent(A0_6312, "Scored")
    else
      A0_6312:ResetAttachment(0, "flag_attachment")
      L3_6315 = "base_idle"
      BroadcastEvent(A0_6312, "Taken")
    end
    Log("CTFBase:ObjectiveAttached anim %s %d", L3_6315, A0_6312:StartAnimation(0, L3_6315, 0, 0.4, 1, 0) * 1000)
    A0_6312:SetTimer(TIMER_ANIM_TRANSITION, A0_6312:StartAnimation(0, L3_6315, 0, 0.4, 1, 0) * 1000)
  end
end
L0_6302.ObjectiveAttached = L1_6303
L0_6302 = CTFBase
function L1_6303(A0_6316, A1_6317)
  local L2_6318
  L2_6318 = Log
  L2_6318("CTFBase:SetInProximity")
  L2_6318 = A0_6316.InProximity
  if L2_6318 ~= A1_6317 then
    A0_6316.InProximity = A1_6317
    L2_6318 = A0_6316.HasFlag
    if L2_6318 then
      L2_6318 = nil
      if A1_6317 then
        L2_6318 = "base_idle"
      else
        L2_6318 = "base_idle"
      end
      Log("CTFBase:InProximity anim %s %d", L2_6318, A0_6316:StartAnimation(0, L2_6318, 0, 0.4, 1, 0) * 1000)
      A0_6316:SetTimer(TIMER_ANIM_TRANSITION, A0_6316:StartAnimation(0, L2_6318, 0, 0.4, 1, 0) * 1000)
    end
  end
end
L0_6302.SetInProximity = L1_6303
L0_6302 = CTFBase
L0_6302 = L0_6302.Client
function L1_6303(A0_6319, A1_6320, A2_6321)
  local L3_6322
  L3_6322 = Log
  L3_6322("CTFBase:OnTimer %d", A1_6320)
  L3_6322 = TIMER_ANIM_TRANSITION
  if A1_6320 == L3_6322 then
    L3_6322 = nil
    if A0_6319.HasFlag then
      if A0_6319.InProximity then
        L3_6322 = "base_idle"
      else
        L3_6322 = "base_idle"
      end
    else
      L3_6322 = "base_idle"
    end
    Log("CTFBase:OnTimer anim %s", L3_6322)
    A0_6319:StartAnimation(0, L3_6322, 0, 0.4, 1, 1)
  end
end
L0_6302.OnTimer = L1_6303
L0_6302 = CTFBase
L1_6303 = {}
L2_6304 = {}
L1_6303.Inputs = L2_6304
L2_6304 = {}
L2_6304.Taken = "bool"
L2_6304.Scored = "bool"
L1_6303.Outputs = L2_6304
L0_6302.FlowEvents = L1_6303
