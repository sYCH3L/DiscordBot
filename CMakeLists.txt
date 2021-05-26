cmake_minimum_required (VERSION 3.6)
project(moistbot)

include_directories(include/)
add_executable(moistbot src/main.cpp src/bot.cpp src/MsgHandler.cpp src/handlers.cpp)

add_subdirectory(deps/sleepy-discord)
target_link_libraries(moistbot sleepy-discord)
