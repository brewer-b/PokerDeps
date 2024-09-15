#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint64_t hand_index_t;
typedef struct hand_indexer_t {
  uint8_t cards_per_round[8], round_start[8];
  uint_fast32_t rounds, configurations[8], permutations[8];
  hand_index_t round_size[8];
  uint_fast32_t * permutation_to_configuration[8], * permutation_to_pi[8], * configuration_to_equal[8];  
  uint_fast32_t (* configuration[8])[4];
  uint_fast32_t (* configuration_to_suit_size[8])[4];
  hand_index_t * configuration_to_offset[8];
} hand_indexer_t;

/**
 * Initialize a hand indexer.  This generates a number of lookup tables and is relatively
 * expensive compared to indexing a hand.
 *
 * @param rounds number of rounds
 * @param cards_per_round number of cards in each round
 * @param indexer 
 */
bool hand_indexer_init(uint_fast32_t rounds, const uint8_t cards_per_round[], hand_indexer_t * indexer);

/**
 * Free a hand indexer.
 *
 * @param indexer
 */
void hand_indexer_free(hand_indexer_t * indexer);

/**
 * @param indexer
 * @param round 
 * @returns size of index for hands on round
 */
hand_index_t hand_indexer_size(const hand_indexer_t * indexer, uint_fast32_t round);

/**
 * Index a hand on every round.  This is not more expensive than just indexing the last round.
 *
 * @param indexer
 * @param cards
 * @param indices
 * @returns hand's index on the last round
 */
hand_index_t hand_index_all(const hand_indexer_t * indexer, const uint8_t cards[], hand_index_t indices[]);

/**
 * Index a hand on the last round.
 *
 * @param indexer
 * @param cards
 * @returns hand's index on the last round
 */
hand_index_t hand_index_last(const hand_indexer_t * indexer, const uint8_t cards[]);

/**
 * Recover the canonical hand from a particular index.
 *
 * @param indexer
 * @param round
 * @param index
 * @param cards
 * @returns true if successful
 */
bool hand_unindex(const hand_indexer_t * indexer, uint_fast32_t round, hand_index_t index, uint8_t cards[]);


#ifdef __cplusplus
}
#endif