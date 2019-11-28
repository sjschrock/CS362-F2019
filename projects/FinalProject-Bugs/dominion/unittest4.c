#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // set players and seed
  int hasGameExited;
  int i;
  // set card array
  int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
  int numOfPlayers = 2;
  int seed = rand() % 100 + 1;
  int numDominionCardTypes = 27;

  // declare game state
  struct gameState G;

  // clear the game state
  memset(&G, 23, sizeof(struct gameState));
  // initialize game
  initializeGame(numOfPlayers, k, seed, &G);

  for (i = 0; i < numDominionCardTypes; i++)
  {
    G.supplyCount[i] = i < (numDominionCardTypes - 3) ? 1 : 0;
  }

  // begin testing bug 4 - isGameOver
  printf("--------------------------------------------------------------------------\n");
  printf("BEGIN TEST #1 FOR BUG 4\n\n");

  // call function
  hasGameExited = isGameOver(&G);

  printf("Call isGameOver().\n\n");

  if (hasGameExited == 1)
  {
    printf("OK:  game is over.\n");
  }
  else
  {
    printf("ERROR:  game is not over.\n");
  }

  printf("Value returned from isGameOver is %d.\n\n", hasGameExited);

  printf("END TEST #1 FOR BUG 4\n");
  printf("--------------------------------------------------------------------------\n");
  printf("\n");

  return 0;
}
