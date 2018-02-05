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
    

    // Beginnning of the game
    printf ("TESTING isGameOver() at beginning of game:\n");
    
    int returned = isGameOver(&G);
    if(0 == returned)
    {
        printf("PASSED: isGameOver() returned %i; Expected %i\n", returned, 0);

    }
    else
    {
        printf("FAILED: isGameOver() returned %i; Expected %i\n", returned, 0);
        failed++;
    }


    // No more province cards
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);
    G.supplyCount[province] = 0;
    
    printf ("TESTING isGameOver() after setting Province cards to zero:\n");
    
    returned = isGameOver(&G);
    if(1 == returned)
    {
        printf("PASSED: isGameOver() returned %i; Expected %i\n", returned, 1);

    }
    else
    {
        printf("FAILED: isGameOver() returned %i; Expected %i\n", returned, 1);
        failed++;
    }

    // Supply piles running out
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);
    printf ("TESTING isGameOver() with various supply piles set to 0:\n");
    
    int numPilesSet = 0;
    int i;
    for(i = 10; i < 20; i++)
    {
        returned = isGameOver(&G);
        int expected = numPilesSet < 3 ? 0 : 1;

        G.supplyCount[i] = 0;
        numPilesSet++;

        if(expected == returned)
        {
            printf("PASSED: isGameOver() returned %i; Expected %i\n", returned, expected);

        }
        else
        {
            printf("FAILED: isGameOver() returned %i; Expected %i\n", returned, expected);
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
