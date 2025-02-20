cmake_minimum_required(VERSION 3.31.4)

project(tiniest-cc C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

## Targets
### maxwell3025_fileio
set(common_SOURCES
    src/common/load_file.c
)

set(common_HEADERS
    src/common/load_file.h
)

add_library(maxwell3025_fileio
    ${common_SOURCES}
    ${common_HEADERS}
)

### parser_codegen
set(parser_codegen_SOURCES
    src/parser_codegen/parser_codegen.c
)

set(parser_codegen_HEADERS
)

add_executable(parser_codegen
    ${parser_codegen_SOURCES}
    ${parser_codegen_HEADERS}
    ${common_HEADERS}
)

target_link_libraries(parser_codegen PRIVATE
    maxwell3025_fileio
)

### cc
set(cc_SOURCES
    src/cc/cc.c
    src/cc/tokenize.c
)

set(cc_HEADERS
)

add_executable(cc
    ${cc_SOURCES}
    ${cc_HEADERS}
    ${common_HEADERS}
)

target_link_libraries(cc PRIVATE
    maxwell3025_fileio
)

## Debug Config
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Enable exports for Debug build
  set_property(TARGET parser_codegen PROPERTY ENABLE_EXPORTS ON)
  set_property(TARGET cc PROPERTY ENABLE_EXPORTS ON)
else()
  # Disable exports for other build types (e.g., Release)
  set_property(TARGET parser_codegen PROPERTY ENABLE_EXPORTS OFF)
  set_property(TARGET cc PROPERTY ENABLE_EXPORTS OFF)
endif()

## Testing
enable_testing()

add_subdirectory(googletest)

add_subdirectory(test)

