-- Prints a formatted message to the console.
-- @param	fmt		Format string for string.format.
-- @param	...		Format arguments for string.format.
function ChairLog(fmt, ...)
	Chairloader.Log(string.format(fmt, ...))
end

-- Prints a formatted warning message to the console.
-- @param	fmt		Format string for string.format.
-- @param	...		Format arguments for string.format.
function ChairWarn(fmt, ...)
	Chairloader.LogWarning(string.format(fmt, ...))
end

-- Prints a formatted error message to the console.
-- @param	fmt		Format string for string.format.
-- @param	...		Format arguments for string.format.
function ChairError(fmt, ...)
	Chairloader.LogError(string.format(fmt, ...))
end
