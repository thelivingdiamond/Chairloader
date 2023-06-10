Chairloader_Internal = {}

Script.ReloadScript("scripts/Chairloader/logging.lua")
Script.ReloadScript("scripts/Chairloader/ent_hooks.lua")

-- Gets the export table for a given mod.
-- If mod is not found, throws an error.
Chairloader.RequireModExportTable = function (modName)
	local tbl = Chairloader.GetModExportTable(modName)
	
	if tbl == nil then
		error("Mod " .. modName .. " is not installed or doesn't have an export table")
	end
	
	return tbl
end
