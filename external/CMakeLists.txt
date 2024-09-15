set(CMAKE_BUILD_TYPE  "Release")
add_library(hand-isomorphism STATIC hand-isomorphism/src/deck.c hand-isomorphism/src/hand_index.c)
target_compile_options(hand-isomorphism PUBLIC -O3 -w)
target_include_directories(hand-isomorphism PUBLIC hand-isomorphism/src/)
install(TARGETS hand-isomorphism ARCHIVE DESTINATION lib)
install(FILES hand_index.h DESTINATION include/hand-isomorphism)

add_subdirectory(PokerHandEvaluator/cpp)