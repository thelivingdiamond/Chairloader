# Group projects in VS
set(CMAKE_FOLDER "Chairloader (Game)")

set(SOURCE_FILES
	CMakeLists.txt
	.editorconfig
	.gitattributes
	.gitignore
	debuggers
	debuggers/imgui.gdb
	debuggers/imgui.natstepfilter
	debuggers/imgui.natvis
	debuggers/README.txt
	imconfig.h
	imgui.cpp
	imgui.h
	imgui_demo.cpp
	imgui_draw.cpp
	imgui_internal.h
	imgui_stdlib.cpp
	imgui_stdlib.h
	imgui_tables.cpp
	imgui_widgets.cpp
	imstb_rectpack.h
	imstb_textedit.h
	imstb_truetype.h
	LICENSE.txt
	pch.h
	README.txt
)

add_library(Chairloader.ImGui STATIC
	${SOURCE_FILES})

target_include_directories(Chairloader.ImGui PUBLIC
	.
)

target_link_libraries(Chairloader.ImGui PUBLIC
	Common
)

target_precompile_headers(Chairloader.ImGui PUBLIC pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
