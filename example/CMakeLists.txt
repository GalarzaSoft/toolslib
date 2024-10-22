add_executable(example)

target_sources(example
    PRIVATE
        src/main.cpp
)

target_link_libraries(example PRIVATE toolslib)

target_compile_features(example
    PRIVATE
        cxx_std_23
)

set_target_properties(example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)