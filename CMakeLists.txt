cmake_minimum_required(VERSION 3.17)

if(NOT DEFINED ACBT_PROJECT_LOADED)
    include(cmake/project.cmake)
endif()

project(auik-wbe-awin
    VERSION 0.0.1
    LANGUAGES CXX C
    DESCRIPTION "Auik awin Window Backend")

if(NOT DEFINED ACBT_LOADED)
    include(cmake/utils.cmake)
endif()

create_symbol_export_file()
add_files(${PROJECT_NAME} RECURSE "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_library(${PROJECT_NAME} SHARED ${AUIK_WBE_AWIN_SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
    DEFINE_SYMBOL AUIK_WBE_AWIN_BUILD
    CXX_VISIBILITY_PRESET hidden
)

target_link_libraries(${PROJECT_NAME} PUBLIC acul awin auik)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${AUIK_WBE_AWIN_CONFIGURE_PATH}"
)

if(WIN32)
    gen_manifest_lib(lib${PROJECT_NAME} ${PROJECT_VERSION})
endif()

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_EXTENSIONS YES
)
