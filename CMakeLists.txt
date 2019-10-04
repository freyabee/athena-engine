cmake_minimum_required(VERSION 2.6)
project(PROMETHEUS_ENGINE)

add_library(prometheus
  src/prometheus/Core.cpp
)

add_executable(sandbox
  src/sandbox/main.cpp
)

target_link_libraries(sandbox prometheus)