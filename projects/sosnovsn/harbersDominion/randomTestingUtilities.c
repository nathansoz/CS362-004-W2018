#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include "randomTestingUtilities.h"
#include <stdlib.h>

void GenerateGameState(struct gameState *G, int currentPlayer, int numPlayers)
{
    int i;
    for (i = 0; i < sizeof(struct gameState); i++) 
    {
      ((char*)G)[i] = floor(Random() * 256);
    }
    G->numPlayers = numPlayers;
    G->whoseTurn = currentPlayer;

    G->deckCount[currentPlayer] = floor(Random() * MAX_DECK);

    // Have at least 8 cards
    if(G->deckCount[currentPlayer] < 8)
    {
        G->deckCount[currentPlayer] = 8;
    }

    G->discardCount[currentPlayer] = floor(Random() * MAX_DECK);
    G->handCount[currentPlayer] = floor(Random() * MAX_HAND);
    G->playedCardCount = floor(Random() * MAX_DECK - 20);
    G->numActions = floor(Random() * 4) + 1;
   int numTreasure = 0;

   while(1)
   {
     for (i = 0; i < G->deckCount[currentPlayer]; i++)
     {
       int card = floor(Random() * treasure_map);

       if(card == copper || card == silver || card == gold)
       {
         numTreasure++;
       }
       G->deck[currentPlayer][i] = floor(Random() * treasure_map);
     }

     if(numTreasure > 1)
     {
       break;
     }
     else
     {
       numTreasure = 0;
     }
   }

   for (i = 0; i < G->handCount[currentPlayer]; i++)
   {
     G->hand[currentPlayer][i] = floor(Random() * treasure_map);
   }

   for (i = 0; i < G->discardCount[currentPlayer]; i++)
   {
     G->discard[currentPlayer][i] = floor(Random() * treasure_map);
   }

   for (i = 0; i < G->playedCardCount; i++)
   {
     G->playedCards[i] = floor(Random() * treasure_map);
   }
}
