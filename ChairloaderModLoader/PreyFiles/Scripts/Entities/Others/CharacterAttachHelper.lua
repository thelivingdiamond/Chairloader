local L0_6610, L1_6611, L2_6612
L0_6610 = {}
L1_6611 = {}
L1_6611.Icon = "Magnet.bmp"
L0_6610.Editor = L1_6611
L1_6611 = {}
L1_6611.BoneName = "Bip01 Head"
L0_6610.Properties = L1_6611
CharacterAttachHelper = L0_6610
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6613)
  A0_6613:MakeAttachment()
end
L0_6610.OnInit = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6614)
  A0_6614:MakeAttachment()
end
L0_6610.OnStartGame = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6615)
  A0_6615:MakeAttachment()
end
L0_6610.OnPropertyChange = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6616)
  A0_6616:MakeAttachment()
end
L0_6610.OnBindThis = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6617)
  A0_6617:DestroyAttachment()
end
L0_6610.OnUnBindThis = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6618)
  A0_6618:DestroyAttachment()
end
L0_6610.OnShutDown = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6619)
  if A0_6619:GetParent() then
    A0_6619:GetParent():DestroyAttachment(0, A0_6619:GetName())
    A0_6619:EnableInheritXForm(0)
    A0_6619:GetParent():CreateBoneAttachment(0, A0_6619.Properties.BoneName, A0_6619:GetName())
    A0_6619:GetParent():SetAttachmentObject(0, A0_6619:GetName(), A0_6619.id, -1, 0)
  end
end
L0_6610.MakeAttachment = L1_6611
L0_6610 = CharacterAttachHelper
function L1_6611(A0_6620)
  if A0_6620:GetParent() then
    A0_6620:GetParent():DestroyAttachment(0, A0_6620:GetName())
  end
end
L0_6610.DestroyAttachment = L1_6611
L0_6610 = CharacterAttachHelper
L1_6611 = {}
L2_6612 = CharacterAttachHelper
L2_6612 = L2_6612.OnBindThis
L1_6611.OnBindThis = L2_6612
L2_6612 = CharacterAttachHelper
L2_6612 = L2_6612.OnUnBindThis
L1_6611.OnUnBindThis = L2_6612
L0_6610.Server = L1_6611
L0_6610 = CharacterAttachHelper
L1_6611 = {}
L2_6612 = CharacterAttachHelper
L2_6612 = L2_6612.OnBindThis
L1_6611.OnBindThis = L2_6612
L2_6612 = CharacterAttachHelper
L2_6612 = L2_6612.OnUnBindThis
L1_6611.OnUnBindThis = L2_6612
L0_6610.Client = L1_6611
