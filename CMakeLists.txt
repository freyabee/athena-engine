cmake_minimum_required(VERSION 2.6)
project(PROMETHEUS_ENGINE)
include_directories(
src
lib
contrib
)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)

if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()


  

add_library(prometheus
src/prometheus/stb_vorbis.h
src/prometheus/tinyobj.h
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
src/prometheus/MeshRenderer.h
src/prometheus/MeshRenderer.cpp
src/prometheus/transform.h
src/prometheus/transform.cpp
src/prometheus/camera.h
src/prometheus/camera.cpp
src/prometheus/noncopyable.h
src/prometheus/noncopyable.cpp
src/prometheus/meshrenderer.h
src/prometheus/meshrenderer.cpp
src/prometheus/screen.h
src/prometheus/screen.cpp
src/prometheus/model.h
src/prometheus/model.cpp
src/prometheus/resources.h
src/prometheus/resource.h
src/prometheus/material.h
src/prometheus/material.cpp
src/prometheus/sound.h
src/prometheus/sound.cpp
src/prometheus/soundsource.h
src/prometheus/soundsource.cpp
src/prometheus/audiocontext.h
src/prometheus/audiocontext.cpp
src/prometheus/mouse.h
src/prometheus/mouse.cpp
src/prometheus/timer.h
src/prometheus/timer.cpp
src/prometheus/staticmodelcollider.h
src/prometheus/staticmodelcollider.cpp
src/prometheus/boxcollider.h
src/prometheus/boxcollider.cpp
src/prometheus/tribox.cpp
)

target_link_libraries(prometheus SDL2 rend OpenAL32)


add_executable(game 
src/game/main.cpp
src/game/coin.h
src/game/coin.cpp
src/game/player.h
src/game/player.cpp
)

target_link_libraries(game prometheus)