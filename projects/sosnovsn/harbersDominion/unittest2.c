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

#define GETCOST_FAILED -1

const char* strings[] = { "curse", "estate", "duchy", "province", "copper", "silver",
                          "gold", "adventurer", "council_room", "feast", "gardens",
                          "mine", "remodel", "smithy", "village", "baron", "great_hall",
                          "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost",
                          "salvager", "sea_hag", "treasure_map" 
                        };

const int values[] = { 0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

int main() {

    int failed = 0;
    int i;
    int numberCards = 27;

    printf ("TESTING getCost() regular values:\n");

    for(i = 0; i < numberCards; i++)
    {
        int returned = getCost(i);
        int expected = values[i];

        if(returned == expected)
        {
            printf("PASSED: Card %s getCost() returned %i; expected %i\n", strings[i], returned, expected);
        }
        else
        {
            printf("FAILED: Card %s getCost() returned %i; expected %i\n", strings[i], returned, expected);
            failed++;
        }
    }

    printf("\nTESTING getCost() with a negative value:\n");
    int returned = getCost(-5);
    if(returned == GETCOST_FAILED)
    {
        printf("PASSED: Card invalid (-5) getCost() returned %i; expected %i\n", returned, GETCOST_FAILED);
    }
    else
    {
        printf("FAILED: Card invalid (-5) getCost() returned %i; expected %i\n", returned, GETCOST_FAILED);
        failed++;
    }

    printf("\nTESTING getCost() with an invalid positive value:\n");
    returned = getCost(27);
    if(returned == GETCOST_FAILED)
    {
        printf("PASSED: Card invalid (27) getCost() returned %i; expected %i\n", returned, GETCOST_FAILED);
    }
    else
    {
        printf("FAILED: Card invalid (27) getCost() returned %i; expected %i\n", returned, GETCOST_FAILED);
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
