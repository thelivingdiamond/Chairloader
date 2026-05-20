set(SOURCE_FILES
        CMakeLists.txt
        main.cpp
        pch.h
)


add_executable(ChairMerger.Runner ${SOURCE_FILES}
)

target_include_directories(ChairMerger.Runner PRIVATE .)
target_include_directories(ChairMerger PRIVATE .)


target_link_libraries(ChairMerger.Runner
        Boost::json

        ChairMerger
)

cl_output_to_data(ChairMerger.Runner)
cl_version_info(ChairMerger.Runner "ChairMerger.Runner.exe" "Chairmanger Merger")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
