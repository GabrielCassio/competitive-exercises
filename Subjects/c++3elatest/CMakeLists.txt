cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(project_name DT_CPP)
project(${project_name} VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Executável de Teste do Capítulo 4 ============================================

set (FILES_CHAP4
    chap4/main.cpp
)

set (EXERC_CHAP4
    exerc/
)

set(chap4_executable_name chap4)
add_executable(${chap4_executable_name})
target_sources(${chap4_executable_name} PRIVATE
    ${FILES_CHAP4}
)

set(exerc_chap4_executable_name exerc_chap4)
add_executable(${exerc_chap4_executable_name})
target_sources(${exerc_chap4_executable_name} PRIVATE
    ${EXERC_CHAP4}
)