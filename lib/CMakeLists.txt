add_library(toolslib STATIC module/library.cppm)

target_sources(toolslib
    PRIVATE
        module/library.cppm
        src/StringTokenizer.cpp
)

target_include_directories(toolslib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_features(toolslib
    PUBLIC
        cxx_std_23
)

set_target_properties(toolslib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)