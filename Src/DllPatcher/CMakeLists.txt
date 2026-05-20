set(SOURCE_FILES
        CMakeLists.txt
        main.cpp
        pch.h
)


add_executable(DllPatcher ${SOURCE_FILES}
)

target_include_directories(DllPatcher PRIVATE .)


target_link_libraries(DllPatcher
        Boost::json
        ZLIB::ZLIB

        Common.Private
)

cl_output_to_data(DllPatcher)
cl_version_info(DllPatcher "DllPatcher.exe" "ChairManager DLL Patcher")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
