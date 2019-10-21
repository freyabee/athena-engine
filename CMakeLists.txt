cmake_minimum_required(VERSION 2.6)
project(PROMETHEUS_ENGINE)
include_directories(
src
lib
)

add_library(prometheus
src/prometheus/Core.cpp
src/prometheus/Core.h
src/prometheus/Component.cpp
src/prometheus/Component.h
src/prometheus/Entity.cpp
src/prometheus/Entity.h
src/prometheus/Environment.cpp
src/prometheus/Environment.h
src/prometheus/Keyboard.cpp
src/prometheus/Keyboard.h
src/prometheus/prometheus.h
src/prometheus/testscreen.cpp
src/prometheus/testscreen.h
)

add_executable(game src/game/main.cpp
)

target_link_libraries(game prometheus)