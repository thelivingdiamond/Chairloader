Mod developers:
	This directory contains common headers and sources used by Chairloader.
	Source files here will be built as part of CommonMod static library.
	
	You have two options on how to use it:
	 1) Copy the contents of "Common" from Chairloader's root to here.
	    This prevents ABI breaks with option 2 but if you maintain a lot of mods,
		you'll need to manually update Common in each of them.
	 2) Set CHAIRLOADER_COMMON_PATH to point to Chairloader's "Common" directory. You can share
		this directory between many mods (and Chairloader itself). But if there is a change that
		breaks API, you'll have to fix every mod.
	
	I recommend option 2 for better maintainability. The project is in active development
	so neither API nor ABI are stable.
	
	CHAIRLOADER_COMMON_PATH takes priority over copied files.


Chairloader developers:
	If you're testing ExampleMod inside the source tree of Chairloader,
	set CHAIRLOADER_COMMON_PATH to "../Common" instead of manually copying the files.
