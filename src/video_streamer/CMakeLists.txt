cmake_minimum_required (VERSION 2.6)
project (video_streamer CXX)

set(SUPPORTED_PLATFORMS "Linux" "Bebop")
find_package(JPEG)

if (JPEG_FOUND)
    include_directories(${JPEG_INCLUDE_DIR})
    set(SRCS ${SRCS} ${SRCS_JPEG})
    set(LIBS ${LIBS} ${JPEG_LIBRARIES})
endif (JPEG_FOUND)

if (";${SUPPORTED_PLATFORMS};" MATCHES ";${PLATFORM};")
    add_executable(${PROJECT_NAME} video_streamer.cxx)
    add_custom_target(${PROJECT_NAME}_headers SOURCES ${PLATFORM_CONFIG})
    target_link_libraries(${PROJECT_NAME} tuv)
endif ()
