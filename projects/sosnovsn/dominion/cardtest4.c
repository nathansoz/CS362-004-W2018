/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int p;
    int c;
    int bonus;
    int failed = 0;
    int numPlayer = 4;
    int maxCards = 5;
    int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};

    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    int r = initializeGame(numPlayer, k, seed, &G);

    int numActions = G.numActions;
    int numCards = G.handCount[0];
    printf ("TESTING CARD gardens:\n");
    cardEffect(village, 0, 0, 0, &G, 7, &bonus);
    int newNumActions = G.numActions;
    int newNumCards = G.handCount[0];

    if(newNumActions == numActions + 2)
    {
        printf("PASSED: Number of actions is %i; Expected %i\n", newNumActions, numActions + 2);
    }
    else
    {
        printf("FAILED: Number of actions is %i; Expected %i\n", newNumActions, numActions + 2);
        failed++;
    }

    if(numCards == newNumCards)
    {
        printf("PASSED: Number of cards is %i; Expected %i\n", newNumCards, numCards);
    }
    else
    {
        printf("FAILED: Number of cards is %i; Expected %i\n", newNumCards, numCards);
        failed++;
    }

    if(failed == 0)
    {
        printf("All tests passed!\n");
    }
    else
    {
        printf("ERROR: %i TESTS FAILED!!!\n", failed);
    }

    return 0;
}
