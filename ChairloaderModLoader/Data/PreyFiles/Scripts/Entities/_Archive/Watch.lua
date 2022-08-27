Script.ReloadScript("Scripts/Default/Entities/Others/BasicEntity.lua")
Watch_x = {
  Name = "Watch",
  CustomProperties = {}
}
function Watch_x.OnInit(A0_1446)
  A0_1446.__super.OnInit(A0_1446)
  A0_1446:StartAnimation(0, "default", 0, 0, 1, 1)
  A0_1446:GotoState("")
end
function Watch_x.OnPropertyChange(A0_1447)
  A0_1447.__super.OnPropertyChange(A0_1447)
  A0_1447:StartAnimation(0, "default", 0, 0, 1, 1)
end
function Watch_x.OnReset(A0_1448)
  A0_1448.__super.OnReset(A0_1448)
  A0_1448:SetFromProperties()
  A0_1448:StartAnimation(0, "default", 0, 0, 1, 1)
end
function Watch_x.OnUpdate(A0_1449)
  A0_1449:SetAnimationSpeed(0)
  A0_1449:SetAnimationTime(0, 0, (System.GetLocalOSTime().hour * 60 + System.GetLocalOSTime().min + System.GetLocalOSTime().sec / 60) / 30)
end
function CreateWatchEntity(A0_1450)
  local L1_1451
  L1_1451 = {}
  mergef(L1_1451, BasicEntity, 1)
  mergef(L1_1451, A0_1450, 1)
  mergef(L1_1451.Properties, A0_1450.CustomProperties, 1)
  L1_1451.__super = BasicEntity
  L1_1451.Properties.object_Model = "Objects/Indoor/props/office_items/clock_animated.cga"
  return L1_1451
end
Watch = CreateWatchEntity(Watch_x)
