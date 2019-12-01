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
  int choice1 = 0;
  int choice2 = gold;
  int currPlayer = 0;
  int i;
  int initGameCopper = 2;
  int initGameGold = 0;
  // set card array
  int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
  int numOfPlayers = 2;
  int playerHand[5] = { copper, copper, copper, silver, silver };
  int seed = rand() % 100 + 1;
  int testGameGold = 0;
  int testGameCopper = 0;

  // declare game state
  struct gameState G, testGame;

  // clear the game state
  memset(&G, 23, sizeof(struct gameState));
  // initialize game
  initializeGame(numOfPlayers, k, seed, &G);

  // begin testing bug 3 - remodel gainCard
  // discard copper for gold
  printf("--------------------------------------------------------------------------\n");
  printf("BEGIN TEST #1 FOR BUG 3\n\n");

  //copy game state for test game
  memcpy(&testGame, &G, sizeof(struct gameState));
  memcpy(testGame.hand[currPlayer], playerHand, sizeof(int) * 5);

  // call function
  cardEffect(remodel, choice1, choice2, 0, &testGame, 0, 0);

  for (i = 0; i < testGame.handCount[currPlayer]; i++)
  {
    if (testGame.hand[currPlayer][i] == gold)
    {
      testGameGold++;
    }

    if (testGame.hand[currPlayer][i] == copper)
    {
      testGameCopper++;
    }
  }

  printf("Call cardEffect() function with remodel case and choice1 is %d and choice 2 is %d.\n\n", choice1, choice2);

  if (initGameGold == testGameGold)
  {
    printf("OK:  the number of gold remains the same.\n");
  }
  else
  {
    printf("ERROR:  the number of gold changes.\n");
  }

  printf("Number of gold before play = %d\n", initGameGold);
  printf("Number of gold after play = %d\n", testGameGold);
  printf("Number of gold expected = %d\n\n", initGameGold);

  if (initGameCopper == testGameCopper)
  {
    printf("OK:  the number of copper remains the same.\n");
  }
  else
  {
    printf("ERROR:  the number of copper changes.\n");
  }

  printf("Number of copper before play = %d\n", initGameCopper);
  printf("Number of copper after play = %d\n", testGameCopper);
  printf("Number of copper expected = %d\n\n", initGameCopper);

  printf("END TEST #1 FOR BUG 3\n");
  printf("--------------------------------------------------------------------------\n");
  printf("\n");

  return 0;
}
