cmake_minimum_required(VERSION 3.16)
project(vigenere_cipher)

set(CMAKE_CXX_STANDARD 20)

add_executable(vigenere_cipher VigenereEncoder.cpp VigenereEncoder.h main.cpp VigenereAttacker.cpp VigenereAttacker.h)