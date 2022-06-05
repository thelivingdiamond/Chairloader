local L0_820, L1_821, L2_822, L3_823
L0_820 = {}
L1_821 = {}
L1_821.object_Model_Supporter_Animated = "objects/multiplayer/flagbase/mp_flag_animated.cgf"
L1_821.object_Model_Supporter_AnimatedAMD64 = "objects/multiplayer/flagbase/mp_flag_animated_amd.cgf"
L0_820.Properties = L1_821
L0_820.ASSAULTCheckPointID = nil
L0_820.fRaiseHeight = 0
L0_820.animation_state = 0
L0_820.is_moving = 0
FlagEntity = L0_820
L0_820 = FlagEntity
function L1_821(A0_824)
  A0_824.fRaiseHeight = 0
  A0_824:GotoState("down")
end
L0_820.OnReset = L1_821
L0_820 = FlagEntity
function L1_821(A0_825)
  if Client and Client:GetServerCPUTargetName() == "AMD64" then
    A0_825:LoadCharacter(A0_825.Properties.object_Model_Supporter_AnimatedAMD64, 0)
  else
    A0_825:LoadCharacter(A0_825.Properties.object_Model_Supporter_Animated, 0)
  end
  A0_825:DrawCharacter(0, 1)
  A0_825:ResetAnimation(0, -1)
  A0_825:StartAnimation(0, "flag_bottom", 0, 0, 1, 1)
  A0_825.fRaiseHeight = 0
end
L0_820.LoadGeometry = L1_821
L0_820 = FlagEntity
function L1_821(A0_826, A1_827)
end
L0_820.OnContact = L1_821
L0_820 = FlagEntity
function L1_821(A0_828, A1_829)
end
L0_820.OnUpdate = L1_821
L0_820 = FlagEntity
function L1_821(A0_830)
  local L1_831
end
L0_820.OnShutDown = L1_821
L0_820 = FlagEntity
function L1_821(A0_832)
  local L1_833
end
L0_820.OnActivate = L1_821
L0_820 = FlagEntity
function L1_821(A0_834)
  A0_834:RegisterState("up")
  A0_834:RegisterState("down")
end
L0_820.RegisterStates = L1_821
L0_820 = FlagEntity
function L1_821(A0_835, A1_836)
  if A0_835.is_moving == 0 then
    if A1_836 ~= A0_835.animation_state then
      if A1_836 == 1 then
        A0_835:StartAnimation(0, "flag_up", 0, 0)
      else
        A0_835:StartAnimation(0, "flag_down", 0, 0)
      end
      A0_835.is_moving = 1
    elseif A0_835:IsAnimationRunning(0) == nil then
      if A1_836 == 1 then
        A0_835:StartAnimation(0, "flag_waving", 0, 0, 1, 1)
      else
        A0_835:StartAnimation(0, "flag_bottom", 0, 0, 1, 1)
      end
    end
  elseif A0_835:IsAnimationRunning(0) == nil then
    A0_835.animation_state = A1_836
    A0_835.is_moving = 0
  end
end
L0_820.UpdateAnimation = L1_821
L0_820 = FlagEntity
L1_821 = {}
function L2_822(A0_837)
  A0_837:LoadGeometry()
  A0_837:RegisterStates()
  A0_837:OnReset()
  A0_837:NetPresent(nil)
  A0_837:Activate(1)
end
L1_821.OnInit = L2_822
L2_822 = {}
L1_821.up = L2_822
L2_822 = {}
L1_821.down = L2_822
L0_820.Server = L1_821
L0_820 = FlagEntity
L1_821 = {}
function L2_822(A0_838)
  A0_838:LoadGeometry()
  A0_838:RegisterStates()
end
L1_821.OnInit = L2_822
L2_822 = {}
function L3_823(A0_839)
  local L1_840
end
L2_822.OnBeginState = L3_823
function L3_823(A0_841)
  A0_841:UpdateAnimation(1)
end
L2_822.OnUpdate = L3_823
L1_821.up = L2_822
L2_822 = {}
function L3_823(A0_842)
  local L1_843
end
L2_822.OnBeginState = L3_823
function L3_823(A0_844)
  A0_844:UpdateAnimation(0)
end
L2_822.OnUpdate = L3_823
L1_821.down = L2_822
L0_820.Client = L1_821
