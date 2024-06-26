cmake_minimum_required(VERSION 2.8.12)

# Set extension name here
set(TARGET_NAME rfuns)

set(EXTENSION_NAME ${TARGET_NAME}_extension)
set(LOADABLE_EXTENSION_NAME ${TARGET_NAME}_loadable_extension)

project(${TARGET_NAME})
include_directories(src/include)

set(EXTENSION_SOURCES src/rfuns_extension.cpp 
                      src/add.cpp
                      src/relop.cpp
                      src/is_na.cpp
                      src/as_integer.cpp
                      src/dispatch.cpp
                      src/sum.cpp
                      src/minmax.cpp)

build_static_extension(${TARGET_NAME} ${EXTENSION_SOURCES})
build_loadable_extension(${TARGET_NAME} " " ${EXTENSION_SOURCES})

install(
  TARGETS ${EXTENSION_NAME}
  EXPORT "${DUCKDB_EXPORT_SET}"
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}"
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}")
