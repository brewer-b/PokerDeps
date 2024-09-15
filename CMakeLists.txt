cmake_minimum_required(VERSION 3.29 FATAL_ERROR)
project(PokerDeps)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
    hand-isomorphism
    GIT_REPOSITORY https://github.com/kdub0/hand-isomorphism.git
    GIT_TAG dabcee4a84c1d62ee6ded9b6ff02ece6823fcc0f # Aug 1, 2014
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/external/hand-isomorphism
)

FetchContent_Declare(
    PokerHandEvaluator
    GIT_REPOSITORY https://github.com/HenryRLee/PokerHandEvaluator.git
    GIT_TAG ca8b5abb2b09949c550cda8a0393e6ce08710347  # May 7, 2024
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/external/PokerHandEvaluator
)

FetchContent_MakeAvailable(
    hand-isomorphism
    PokerHandEvaluator
)

add_subdirectory(${PROJECT_SOURCE_DIR}/external)

