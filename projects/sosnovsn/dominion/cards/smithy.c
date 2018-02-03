#include "cards.h"

int apply_smithy(int currentPlayer, struct gameState *state, int handPos)
{
    int i;

    //+3 Cards
    for (i = 0; i < 4; i++)
    {
        drawCard(currentPlayer, state);
    }
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}
