cmake_minimum_required(VERSION 3.20)

project(vix-ai-nn
  VERSION 0.1.0
  DESCRIPTION "Vix.AI NN: layers, networks & optimizers (header-only v0)"
  LANGUAGES CXX)

option(VIX_AI_NN_BUILD_TESTS "Build vix-ai-nn tests" ON)
option(VIX_AI_NN_INSTALL     "Install vix-ai-nn targets" ON)
option(VIX_AI_NN_WARNINGS    "Enable extra warnings" ON)

# Header-only (facile à étendre vers une lib plus tard)
add_library(vix_ai_nn INTERFACE)
add_library(Vix::AI::nn ALIAS vix_ai_nn)

target_include_directories(vix_ai_nn INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(vix_ai_nn INTERFACE cxx_std_20)

# Propager la version umbrella si dispo
if (DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()
target_compile_definitions(vix_ai_nn INTERFACE VIX_AI_NN_VERSION="${PROJECT_VERSION}")

if (VIX_AI_NN_WARNINGS)
  if (MSVC)
    target_compile_options(vix_ai_nn INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_nn INTERFACE -Wall -Wextra -Wpedantic)
  endif()
endif()

# Tests
if (VIX_AI_NN_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Install / package
if (VIX_AI_NN_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)

  install(TARGETS vix_ai_nn
          EXPORT vix_ai_nnTargets)

  install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

  install(EXPORT vix_ai_nnTargets
          FILE vix_ai_nnTargets.cmake
          NAMESPACE Vix::AI::
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nn)

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfig.cmake
"include(\"\${CMAKE_CURRENT_LIST_DIR}/vix_ai_nnTargets.cmake\")\n")

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nnConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nn)
endif()
