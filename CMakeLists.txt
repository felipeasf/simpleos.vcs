cmake_minimum_required(VERSION 3.5)
project(simpleos_vcs VERSION 0.1.0)

find_package(eosio.cdt)

add_contract(simpleos_vcs simpleos_vcs ${CMAKE_CURRENT_SOURCE_DIR}/src/simpleos_vcs.cpp)

target_include_directories(simpleos_vcs.wasm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
