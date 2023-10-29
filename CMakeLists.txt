cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 23)

project(HelloWorld)

SET(CADLIB_DIR "C:/source/cadlib")

set(CADWORK_VERSION 30)


INCLUDE_DIRECTORIES(
        "${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D"
        "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/cpr"
)

link_directories(
        "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/cpr/x64"
        "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/curl/x64"
)

add_library(${PROJECT_NAME} SHARED 
        library.c++
        MyModule.ixx
)


target_link_libraries(${PROJECT_NAME} PRIVATE
        libcurl
        cpr
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWPLUGIN_EXPORTS
        CWAPI3D_PLUGIN_NAME=L"Cadwork Test Plugin"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)
