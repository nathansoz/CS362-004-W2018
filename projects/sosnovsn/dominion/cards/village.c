#include "cards.h"

int apply_village(int currentPlayer, struct gameState *state, int handPos)
{
    //+1 Card
    drawCard(currentPlayer, state);
			
    //+2 Actions
    state->numActions = state->numActions + 2;
			
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}
