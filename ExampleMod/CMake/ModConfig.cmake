include_guard()

# Mod SDK defines
add_compile_definitions(
	CHAIRLOADER_MOD_SDK
)

# Creates a configuration variable with mod's DLL path. If set, mod's DLL will be put there.
# @param    mod_target  Mod target name.
# @param    mod_prefix  Mod prefix for variable name.
function(mod_output_dir mod_target mod_prefix)
	set("${mod_prefix}_DLL_PATH" "${CMAKE_SOURCE_DIR}" CACHE PATH "Where to put the DLL")
	set(mod_dll_path ${${mod_prefix}_DLL_PATH})
	if (mod_dll_path)
		set_target_properties(${mod_target} PROPERTIES
			RUNTIME_OUTPUT_DIRECTORY ${mod_dll_path}
			RUNTIME_OUTPUT_DIRECTORY_DEBUG ${mod_dll_path}
			RUNTIME_OUTPUT_DIRECTORY_DEBUGCHAIR ${mod_dll_path}
			RUNTIME_OUTPUT_DIRECTORY_RELEASE ${mod_dll_path}
			RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${mod_dll_path}
			RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${mod_dll_path}
		)
	endif()
endfunction()
