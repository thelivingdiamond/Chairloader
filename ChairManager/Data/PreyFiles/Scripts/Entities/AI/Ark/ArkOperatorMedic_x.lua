Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkOperatorMedic_x = {
  Properties = {
    ArkWeapon = {
      attachmenteffects_operatorArmIdleEffect = "2428940965279544626",
      attachmenteffects_operatorArmEffect = "2428940965279544716",
      attachmenteffects_operatorArmAttackEffect = "2428940965279544739"
    }
  }
}
mergef(ArkOperatorMedic_x, AIBase, 1)
