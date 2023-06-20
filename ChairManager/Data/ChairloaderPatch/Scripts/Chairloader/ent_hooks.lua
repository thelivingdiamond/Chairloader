-- Entity table hook list
local gHooks = {}

-- Maps entity table name to true if it's hooked.
local gIsHooked = {}

local function EmptyHandler()
	-- Does nothing.
end

-- Splits a string into an array.
-- https://stackoverflow.com/a/7615129
local function SplitString(inputstr, sep)
	if sep == nil then
		sep = "%s"
	end
	
	local t = {}
	
	for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
		table.insert(t, str)
	end
	
	return t
end

-- Checks if the table is empty.
local function IsEmptyTable(tbl)
	return next(tbl) == nil
end

-- Checks if the table is a non-empty array.
local function IsArray(tbl)
	return tbl[1] ~= nil
end

-- Registers a hook function for an entity callback.
-- @param	entityClassName	Entity class name.
-- @param	callbackName	Callback name.
-- @param	handler			Hook handler. Params: next function, entity table, callback args... Call next function like nextHandler(entity table, callback args)
Chairloader.HookEntityCallback = function(entityClassName, callbackName, handler)
	assert(type(entityClassName) == "string")
	assert(type(callbackName) == "string")
	assert(type(handler) == "function")
	
	local hookTable = gHooks[entityClassName]
	
	if hookTable == nil then
		hookTable = {}
		gHooks[entityClassName] = hookTable
	end
	
	if gIsHooked[entityClassName] == true then
		error("Hooks have already been applied to the table.")
	end
	
	local callbackPath = SplitString(callbackName, '.')
	local curItem = hookTable
	
	for idx, pathItem in ipairs(callbackPath) do
		local isLastItem = idx == #callbackPath
		local nextItem = curItem[pathItem]
		
		if nextItem == nil then
			if isLastItem then
				curItem[pathItem] = { handler }
			else
				curItem[pathItem] = {}
				curItem = curItem[pathItem]
			end
		else
			if isLastItem then
				if not IsEmptyTable(nextItem) and not IsArray(nextItem) then
					error("Invalid path (1)")
				end
				
				table.insert(nextItem, handler)
			else
				if not IsEmptyTable(nextItem) and IsArray(nextItem) then
					error("Invalid path (2)")
				end
				
				curItem = nextItem
			end
		end
	end
end

-- Creates a function that calls the handlers in the list.
local function CreateHandlerChain(handlerList, origHandler)
	local nextHandler = origHandler
	
	-- Build handler chain
	for _, handler in ipairs(handlerList) do
		local curHandler = handler
		local prevHandler = nextHandler
		
		nextHandler = function(...)
			curHandler(prevHandler, ...)
		end
	end
	
	return nextHandler
end

-- Merges hook table with an entity table.
local function RecurseMergeTable(entTbl, mergeTbl)
	for itemName, itemTbl in pairs(mergeTbl) do
		local entItem = entTbl[itemName]
		
		if entItem == nil then
			-- Create the item in the ent table
			if IsArray(itemTbl) then
				entItem = EmptyHandler
			else
				entItem = {}
			end
			
			entTbl[itemName] = entItem
		end
		
		if type(entItem) == "function" then
			-- Hooking a function
			if not IsArray(itemTbl) then
				error("Entity has a function, while hook has table")
			end
			
			entTbl[itemName] = CreateHandlerChain(itemTbl, entItem)
		elseif type(entItem) == "table" then
			-- Merging a table
			if IsArray(itemTbl) then
				error("Entity has a table, while hook has functions")
			end
			
			RecurseMergeTable(entItem, itemTbl)
		else
			error("Trying to hook type " .. type(entItem))
		end
	end
end

-- Installs entity table hooks for a given table.
-- @param	tableName	Name of the entity table.
-- @param	entityTable	The table itself.
Chairloader_Internal.HookEntityTable = function(tableName, entityTable)
	local hookTable = gHooks[tableName]
	if hookTable == nil then
		return
	end
	
	System.Log("Hooking " .. tableName)
	gIsHooked[tableName] = true
	RecurseMergeTable(entityTable, hookTable)
end
