-- Main mod table.
local gMod = {
	-- This table is available to other mods using Chairloader.GetModExportTable.
	PublicExport = {}
}

-- Called when the mod is first loaded.
function gMod:OnRegister()
	ChairWarn("Hello from Lua!")
end

-- Called after all mods have been loaded.
function gMod:OnInit()
	
end

-- Called after the game has been initialized.
function gMod:OnGameInit()
	
end

-- Called when the game is shutting down.
function gMod:OnShutdown()
	
end

-- Hooks entity callbacks. May be called multiple times when reloading mods and scripts.
function gMod:HookEntities()
	local function ArkTurretInit(nextHandler, ent, ...)
		ChairWarn("ArkTurretInit called!")
		nextHandler(ent, ...)
	end
	
	Chairloader.HookEntityCallback("ArkTurret", "Server.OnInit", ArkTurretInit)
end

-- DO NOT RENAME!
-- Chairloader uses this variable to get the mod table.
-- The variable will be set to nil after the mod has loaded.
ChairloaderCurrentMod = gMod
