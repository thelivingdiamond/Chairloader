Lua Modding Introduction
==========================
CRYENGINE includes a Lua 5.1.1-rc4 interpreter (from 2006) for entity scripting.

**Relevant resources:**

- [Lua Scripting - CRYENGINE Technical Documentation](https://docs.cryengine.com/display/CEPROG/Lua+Scripting)
- [Script Entity - CRYENGINE Technical Documentation](https://docs.cryengine.com/display/CEPROG/Script+Entity)
- [Creating a New Entity Class - CRYENGINE Technical Documentation](https://docs.cryengine.com/display/CEPROG/Creating+a+New+Entity+Class)
- [Entity script examples - bare-minimum-cryengine3](https://github.com/CapsAdmin/bare-minimum-cryengine3/tree/master/game/Game/Scripts/Entities)


Executing Scripts
------------------
Lua scripts can be executed in the console by prefixing them with a `#` symbol.
```lua
#ChairError("Hello from Lua")
[Lua] [Error] Hello from Lua
```
You can execute files using
```lua
-- Syntax: LoadScript(path, bReload = false, bRaiseError = true)
-- Without bReload = true, the script will only be loaded once.
#Script.LoadScript("D:/Path/To/Script.lua", true)
```

Formatting Rules
-----------------
Just like C++, Lua doesn't have an official formatting rule set. CRYENGINE seems to extend their C++ rules to Lua
- Indent using tabs
- Functions use `PascalCase`
- Variables use `camelCase`, sometimes with Hungarian notation `bBoolVar`, `flFloatVar`
- Global variables are prefixed with `g_`: `g_Pi, g_HitTable, ...`

Entity Scripts
---------------
Primary use of Lua in CRYENGINE is to define new entity classes, their properties (the ones you see in EntityArchetypes XML) and some of the logic via callbacks.

See _Relevant resources_ section for more details.

Lua Mods
---------
Chairloader mods can include custom Lua scripts. The mod must have a script in `Data/Scripts/Mods/mod.name/main.lua` in specific format.

The script is run in the global environment. Make sure you always use `local` for variables and functions. Otherwise the may be overwriten by other mods.

[Check the example for details.](https://github.com/thelivingdiamond/Chairloader/blob/main/ChairManager/Data/Examples/Example.LuaModExample/Data/Scripts/Mods/Example.LuaModExample/main.lua)

Logging
--------
Chairloader provides a few formatted and unformatted logging functions.
```lua
-- Formatted logging (using string.format)
ChairLog("Hello no. %d", 1)   -- Normal message, like CryLog in C++
ChairWarn("Hello no. %d", 2)  -- [Warning] prefix, like CryWarning in C++
ChairError("Hello no. %d", 3) -- [Error] prefix, like CryError in C++

-- Unformatted logging (functions take a string)
Chairloader.Log("Hello no. " .. tostring(1))
Chairloader.LogWarning("Hello no. " .. tostring(2))
Chairloader.LogError("Hello no. " .. tostring(3))
```

Entity Table Hooks
-------------------
Chairloader provides a mechanism to hook functions in entity script tables.

Use `Chairloader.HookEntityCallback` in `HookEntities`. Syntax:
```lua
-- Registers a hook function for an entity callback.
-- @param entityClassName	Entity class name.
-- @param callbackName		Callback name.
-- @param handler		Hook handler.
Chairloader.HookEntityCallback = function(entityClassName, callbackName, handler)
```
Hook handler is a function that takes the following arguments:
- Next handler.
- Entity instance (`self`).
- Callback arguments.

Example usage:
```lua
local function ArkTurret_OnLoad(nextHandler, self, saved)
	-- Call the original function (similar to InvokeOrig() in C++)
	nextHandler(self, saved)
	
	self.testScale = saved.testScale
	if self.testScale == nil then
		self.testScale = 1
	end
	
	ChairWarn("ArkTurret_OnLoad %.3f", self.testScale)
	Entity.SetSlotScale(self, 0, self.testScale)
end

function gMod:HookEntities()
	Chairloader.HookEntityCallback("ArkTurret", "OnLoad", ArkTurret_OnLoad)
end
```

If you don't know the exact arguments of a callback, you can use variadic args.
```lua
local function MyCallback(nextHandler, self, ...)
	nextHandler(self, ...)
	ChairLog("Do something here...")
end
```

Lua Mod Interop
----------------
Lua mods can have `PublicExport` entry in their main table. If they have one, other mods can get a reference to it using the following functions.
```lua
-- Gets the export table for a given mod.
-- If mod is not found, returns nil.
Chairloader.GetModExportTable = function (modName)

-- Gets the export table for a given mod.
-- If mod is not found, throws an error.
Chairloader.RequireModExportTable = function (modName)
```

Those functions can only be called after all mods have been registered (e.g. in `gMod:OnInit`).

Bridging Lua and C++
---------------------
CRYENGINE provides an easy way to expose C++ functions to Lua scripts using `CScriptableBase` class.

See [Integrations Between Lua and C++](https://docs.cryengine.com/pages/viewpage.action?pageId=23306630) in CRYENGINE docs.  
See [ScriptBind_Chairloader](https://github.com/thelivingdiamond/Chairloader/blob/main/Chairloader/Core/Lua/ScriptBind_Chairloader.cpp).