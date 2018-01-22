#pragma once

#include "../dominion.h"

int apply_smithy(int currentPlayer, struct gameState *state, int handPos);

int apply_adventurer(int currentPlayer, struct gameState *state);

int apply_council_room(int currentPlayer, struct gameState *state, int handPos);

int apply_gardens();

int apply_village(int currentPlayer, struct gameState *state, int handPos);
