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

int returnErrorCount = 0;

int iteration = 0;


void checkGardens()
{
    int ret = apply_gardens();
    
    if(ret == -1)
    {
    
    }
    else
    {
        printf("Fail!!! Gardens returned %i. Expected %i\n", ret, -1);
        returnErrorCount++;
    }
}

int main()
{
  srand(time(NULL));
  SelectStream(2);
  PutSeed(3);

  iteration = 0;

  printf("-- RANDOM TEST: GARDENS CARD --\n");

  for(iteration = 0; iteration < 1; iteration++)
  {
    checkGardens();
  }

  if(returnErrorCount == 0)
  {
    printf("All tests passed!\n");
  }
  else
  {
    printf("Return Error Count: %i\n", returnErrorCount);
  }
}
