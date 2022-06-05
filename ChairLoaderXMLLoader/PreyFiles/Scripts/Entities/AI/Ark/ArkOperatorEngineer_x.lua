Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkOperatorEngineer_x = {
  Properties = {
    ArkWeapon = {
      attachmenteffects_operatorArmEffect = "17591291352653887158",
      attachmenteffects_operatorArmAttackEffect = "2428940965270635283"
    }
  },
  gameParams = {aimFOV = 200}
}
mergef(ArkOperatorEngineer_x, AIBase, 1)
