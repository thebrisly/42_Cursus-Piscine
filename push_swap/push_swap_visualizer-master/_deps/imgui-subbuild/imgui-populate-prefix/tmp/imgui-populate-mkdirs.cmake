# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-src"
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-build"
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix"
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/lfabbian/Desktop/GithubLaura/push_swap/push_swap_visualizer-master/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
