cmake_minimum_required(VERSION 3.29)
project(untitled29 C)

set(CMAKE_C_STANDARD 17)

add_executable(untitled29 main.c
        jogo.cpp
        jogo.h
        jogo.c
        jogador.cpp
        jogador.h
        ficheiros.cpp
        ficheiros.h
        config.cpp
        config.h
)
