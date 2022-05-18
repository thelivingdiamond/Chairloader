Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkTechnopath_x = {
  physicsParams = {
    Living = {
      gravity = 9.81,
      mass = 150,
      air_resistance = 0,
      k_air_control = 0,
      inertia = 2,
      inertiaAccel = 2,
      timeImpulseRecover = 1.5,
      height = 1.2,
      size = {
        x = 1,
        y = 1,
        z = 0.5
      },
      use_capsule = 1
    }
  },
  gameParams = {
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 1,
          y = 1,
          z = 0.5
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "stand",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 1,
          y = 1,
          z = 0.5
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "alerted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_CRAWL,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "crawl",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 1,
          y = 1,
          z = 0.5
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "zerog",
        useCapsule = 1
      },
      {
        stanceId = STANCE_HOVER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 1,
          y = 1,
          z = 0.5
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "hover",
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 1,
          y = 1,
          z = 0
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "relaxed",
        useCapsule = 1
      }
    }
  }
}
mergef(ArkTechnopath_x, AIBase, 1)
function ArkTechnopath_x.Server.OnStartGame(A0_1991)
  A0_1991.arknpc:AttachGameEffect(5)
  A0_1991.arknpc:AttachGameEffect(8)
end
function ArkTechnopath_x.OnNpcKilled(A0_1992)
  A0_1992.arknpc:DetachGameEffect(5)
  A0_1992.arknpc:DetachGameEffect(8)
  A0_1992:SetupInventoryOnDeath()
end
