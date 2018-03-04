#include "dominion.h"
#include "dominion_helpers.h"
#include "randomTestingUtilities.h"
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

int handCountErrors = 0;
int treasureCardErrors = 0;
int totalCountErrors = 0;
int actionErrorCount = 0;

int iteration = 0;

void dumpState(struct gameState *state, int player)
{
  printf("HandCount: %i\n", state->handCount[player]);
  printf("DiscardCount: %i\n", state->discardCount[player]);
  printf("DeckCount: %i\n", state->deckCount[player]);
 
}


void checkVillage(struct gameState *ref, struct gameState *current, int player, int villagePos)
{
  Village(player, current, villagePos);
  //apply_village(player, current, villagePos);

  // Ensure the hand count looks how we expect
  if(ref->handCount[player] == current->handCount[player])
  {
    //printf("PASS: Expected handcount to be %i, was %i\n", ref->handCount[player], current->handCount[player]);  
  }
  else
  {
    printf("FAIL!!!: Expected handcount to be %i, was %i (iteration %i)\n", ref->handCount[player], current->handCount[player], iteration);
    handCountErrors++; 
  }

  // Ensure that the total number of cards was reduced by 1
  int priorCount = ref->handCount[player] + ref->discardCount[player] + ref->deckCount[player];
  int currentCount = current->handCount[player] + current->discardCount[player] + current->deckCount[player];
  
  if(priorCount - 1 == currentCount)
  {
    //printf("PASS: Expected total count of player cards to be %i, was %i\n", priorCount - 1, currentCount);  
  }
  else
  {
    printf("FAIL!!!: Expected total count of player cards to be %i, was %i\n", priorCount - 1, currentCount); 
    totalCountErrors++; 
  }

  if(ref->numActions + 2 == current->numActions)
  {
    //printf("PASS: Expected numActions to be %i, was %i\n", ref->numActions + 2, current->numActions);  
  }
  else
  {
    printf("FAIL!!!: Expected total number of actions to be %i, was %i\n", ref->numActions + 2, current->numActions); 
    actionErrorCount++; 
  }

}

int main()
{
  srand(time(NULL));
  SelectStream(2);
  PutSeed(3);

  iteration = 0;

  printf("-- RANDOM TEST: VILLAGE CARD --\n");

  for(iteration = 0; iteration < 1000; iteration++)
  {
    //printf("Iteration: %i\n", i);
    struct gameState game;

    int numPlayers = 2;
    int curPlayer = 1;

    int villagePos = -1;
    while(villagePos == -1)
    {
        GenerateGameState(&game, curPlayer, numPlayers);
        
        // make sure our deck has a village
        int i;
        for(i = 0; i < game.handCount[curPlayer]; i++)
        {
            if(game.hand[curPlayer][i] == village)
            {
                villagePos = i;
                break;
            }
        }
    }

    struct gameState refState;    
    memcpy(&refState, &game, sizeof(struct gameState));

    checkVillage(&refState, &game, curPlayer, villagePos);
  }

  if(handCountErrors + totalCountErrors + treasureCardErrors + actionErrorCount == 0)
  {
    printf("All tests passed!\n");
  }
  else
  {
    printf("Total card failures: %i, Treasure card failures: %i, Hand count failures: %i, Action errors: %i\n", totalCountErrors, treasureCardErrors, handCountErrors, actionErrorCount);
  }

  return 0;
}
