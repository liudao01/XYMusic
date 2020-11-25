
cmake_minimum_required(VERSION 3.4.1)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
# cmakelists 设置c++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if (COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif (COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")

endif ()

set(jnilibs ${CMAKE_SOURCE_DIR}/../jniLibs)

set(libname native-lib)

include_directories(
        include
)


link_directories(
        ${jnilibs}/${ANDROID_ABI})


#找到包含所有的cpp文件
file(GLOB my_source *.cpp *.c)

#作用 将native-lib.cpp  生成一个native-lib 的动态库
add_library( # Sets the name of the library.
        ${libname}

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${my_source})

#设置ffmpeg动态库
set(third-party-libs

        avcodec
        avdevice
        avfilter
        avformat
        avutil
        postproc
        swresample
        swscale
        )

#找到系统的已经存在的动态库
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries( # Specifies the target library.
        ${libname}

        ${third-party-libs}
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})