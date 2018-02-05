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
    int failed = 0;
    int numPlayer = 4;
    int maxCards = 5;
    int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};

    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    int r = initializeGame(numPlayer, k, seed, &G);

    printf ("TESTING whoseTurn():\n");
    for (p = 0; p < numPlayer; p++)
    {
        G.whoseTurn = p;

        int returned = whoseTurn(&G);

        if(returned == p)
        {
            printf("PASSED: whoseTurn() returned %i; Expected %i\n", returned, p);
        }
        else
        {
            printf("FAILED: whoseTurn() returned %i; Expected %i\n", returned, p);
            failed++;
        }
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
