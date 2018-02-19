#include "dominion.h"
#include "dominion_helpers.h"
#include "randomTestingUtilities.h"
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "cards/cards.h"

int handCountErrors = 0;
int treasureCardErrors = 0;
int totalCountErrors = 0;

int iteration = 0;

void dumpState(struct gameState *state, int player)
{
  printf("HandCount: %i\n", state->handCount[player]);
  printf("DiscardCount: %i\n", state->discardCount[player]);
  printf("DeckCount: %i\n", state->deckCount[player]);
 
}

void testTreasureCard(int card)
{
  switch(card)
  {
    case copper:
      //printf("PASS: Copper treasure card found!\n");
      break;
    case silver:
      //printf("PASS: Silver treasure card found!\n");
      break;
    case gold:
      //printf("PASS: Gold Treasure card found!\n");
      break;
    default:
      printf("FAIL!!!: Card is not a treasure card\n");
      treasureCardErrors++;
      break;
  }
}

void checkAdventurer(struct gameState *ref, struct gameState *current, int player)
{
  apply_adventurer(player, current);

  // Ensure the hand count looks how we expect
  if(ref->handCount[player] + 2 == current->handCount[player])
  {
    //printf("PASS: Expected handcount to be %i, was %i\n", ref->handCount[player] + 2, current->handCount[player]);  
  }
  else
  {
    printf("FAIL!!!: Expected handcount to be %i, was %i (iteration %i)\n", ref->handCount[player] + 2, current->handCount[player], iteration);
    dumpState(ref, player);
    dumpState(current, player); 
    handCountErrors++; 
  }

  // Ensure that the total number of cards stayed the same
  int priorCount = ref->handCount[player] + ref->discardCount[player] + ref->deckCount[player];
  int currentCount = current->handCount[player] + current->discardCount[player] + current->deckCount[player];
  
  if(priorCount == currentCount)
  {
    //printf("PASS: Expected total count of player cards to be %i, was %i\n", priorCount, currentCount);  
  }
  else
  {
    printf("FAIL!!!: Expected total count of player cards to be %i, was %i\n", priorCount, currentCount); 
    totalCountErrors++; 
  }

  testTreasureCard(current->hand[player][current->handCount[player]-1]);
  testTreasureCard(current->hand[player][current->handCount[player]-2]);
}

int main()
{
  srand(time(NULL));
  SelectStream(2);
  PutSeed(3);

  iteration = 0;

  printf("-- RANDOM TEST: ADVENTURER CARD --\n");

  for(iteration = 0; iteration < 1000; iteration++)
  {
    //printf("Iteration: %i\n", i);
    struct gameState game;

    int numPlayers = 2;
    //printf("Number of players: %i\n", numPlayers);
    int curPlayer = 1;
    //printf("Current player: %i\n", curPlayer);

    GenerateGameState(&game, curPlayer, numPlayers);

    struct gameState refState;    
    memcpy(&refState, &game, sizeof(struct gameState));

    checkAdventurer(&refState, &game, curPlayer);
  }

  if(handCountErrors + totalCountErrors + treasureCardErrors == 0)
  {
    printf("All tests passed!\n");
  }
  else
  {
    printf("Total card failures: %i, Treasure card failures: %i, Hand count failures: %i\n", totalCountErrors, treasureCardErrors, handCountErrors);
  }
}
