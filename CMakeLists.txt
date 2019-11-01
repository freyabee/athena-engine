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
src/prometheus/trianglerenderer.h
src/prometheus/trianglerenderer.cpp
src/prometheus/transform.h
src/prometheus/transform.cpp
src/prometheus/camera.h
src/prometheus/camera.cpp
src/prometheus/noncopyable.h
src/prometheus/noncopyable.cpp
src/prometheus/meshrenderer.h
src/prometheus/meshrenderer.cpp
)

add_library(rend
src/rend/Exception.h
src/rend/Context.h
src/rend/Texture.h
src/rend/RenderTexture.h
src/rend/shader.h
src/rend/buffer.h
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
)

if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()
add_executable(game src/game/main.cpp
)

target_link_libraries(game prometheus SDL2 glew32 rend opengl32)