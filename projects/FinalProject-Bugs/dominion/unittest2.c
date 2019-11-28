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
  int choice1 = 3;
  int choice2 = gold;
  int currPlayer = 0;
  int i;
  int initGameGold = 0;
  int initGameSilver = 2;
  int initGameTreasureMap = 1;
  // set card array
  int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
  int numOfPlayers = 2;
  int playerHand[5] = {treasure_map, copper, copper, silver, silver};
  int seed = rand() % 100 + 1;
  int testGameGold = 0;
  int testGameSilver = 0;
  int testGameTreasureMap = 0;

  // declare game state
  struct gameState G, testGame;

  // clear the game state
  memset(&G, 23, sizeof(struct gameState));
  // initialize game
  initializeGame(numOfPlayers, k, seed, &G);

  // begin testing bug 2 - mine gainCard
  // discard silver for gold
  printf("--------------------------------------------------------------------------\n");
  printf("BEGIN TEST #1 FOR BUG 2\n\n");

  //copy game state for test game
  memcpy(&testGame, &G, sizeof(struct gameState));
  memcpy(testGame.hand[currPlayer], playerHand, sizeof(int) * 5);

  // call function
  cardEffect(mine, choice1, choice2, 0, &testGame, 0, 0);

  for (i = 0; i < testGame.handCount[currPlayer]; i++)
  {
    if (testGame.hand[currPlayer][i] == gold)
    {
      testGameGold++;
    }

    if (testGame.hand[currPlayer][i] == silver)
    {
      testGameSilver++;
    }
  }

  printf("Call cardEffect() function with mine case and choice1 is %d and choice 2 is %d.\n\n", choice1, choice2);

  if (initGameGold != testGameGold)
  {
    printf("OK:  the number of gold changes.\n");
  }
  else
  {
    printf("ERROR:  the number of gold remains the same.\n");
  }

  printf("Number of gold before play = %d\n", initGameGold);
  printf("Number of gold after play = %d\n", testGameGold);
  printf("Number of gold expected = %d\n\n", testGameGold);

  if (initGameSilver != testGameSilver)
  {
    printf("OK:  the number of silver changes.\n");
  }
  else
  {
    printf("ERROR:  the number of silver remains the same.\n");
  }

  printf("Number of silver before play = %d\n", initGameSilver);
  printf("Number of silver after play = %d\n", testGameSilver);
  printf("Number of silver expected = %d\n", testGameSilver);

  printf("\n");
  printf("END TEST #1 FOR BUG 2\n");
  printf("\n");

  // begin testing bug 2 - mine gainCard
  // discard silver for copper
  printf("--------------------------------------------------------------------------\n");
  printf("BEGIN TEST #2 FOR BUG 2\n\n");

  //copy game state for test game
  memcpy(&testGame, &G, sizeof(struct gameState));
  memcpy(testGame.hand[currPlayer], playerHand, sizeof(int) * 5);

  testGameSilver = 0;
  choice2 = silver;

  // call function
  cardEffect(mine, choice1, choice2, 0, &testGame, 0, 0);

  for (i = 0; i < testGame.handCount[currPlayer]; i++)
  {
    if (testGame.hand[currPlayer][i] == silver)
    {
      testGameSilver++;
    }
  }

  printf("Call cardEffect() function with mine case and choice1 is %d and choice 2 is %d.\n\n", choice1, choice2);

  if (initGameSilver == testGameSilver)
  {
    printf("OK:  the number of silver remains the same.\n");
  }
  else
  {
    printf("ERROR:  the number of silver changes.\n");
  }

  printf("Number of silver before play = %d\n", initGameSilver);
  printf("Number of silver after play = %d\n", testGameSilver);
  printf("Number of silver expected = %d\n\n", testGameSilver);

  printf("END TEST #2 FOR BUG 2\n\n");

  // begin testing bug 2 - mine gainCard
  // discard treasure_map for gold
  printf("--------------------------------------------------------------------------\n");
  printf("BEGIN TEST #3 FOR BUG 2\n\n");

  //copy game state for test game
  memcpy(&testGame, &G, sizeof(struct gameState));
  memcpy(testGame.hand[currPlayer], playerHand, sizeof(int) * 5);

  choice1 = 0;
  choice2 = gold;
  testGameGold = 0;

  // call function
  cardEffect(mine, choice1, choice2, 0, &testGame, 0, 0);

  for (i = 0; i < testGame.handCount[currPlayer]; i++)
  {
    if (testGame.hand[currPlayer][i] == gold)
    {
      testGameGold++;
    }

    if (testGame.hand[currPlayer][i] == treasure_map)
    {
      testGameTreasureMap++;
    }
  }

  printf("Call cardEffect() function with mine case and choice1 is %d and choice 2 is %d.\n\n", choice1, choice2);

  if (initGameGold != testGameGold)
  {
    printf("OK:  the number of gold changes.\n");
  }
  else
  {
    printf("ERROR:  the number of gold remains the same.\n");
  }

  printf("Number of gold before play = %d\n", initGameGold);
  printf("Number of gold after play = %d\n", testGameGold);
  printf("Number of gold expected = %d\n\n", testGameGold);

  if (initGameTreasureMap != testGameTreasureMap)
  {
    printf("OK:  the number of treasure_map changes.\n");
  }
  else
  {
    printf("ERROR:  the number of treasure_map remains the same.\n");
  }

  printf("Number of treasure_map before play = %d\n", initGameTreasureMap);
  printf("Number of treasure_map after play = %d\n", testGameTreasureMap);
  printf("Number of treasure_map expected = %d\n\n", testGameTreasureMap);

  printf("END TEST #3 FOR BUG 2\n\n");
  printf("--------------------------------------------------------------------------\n");
  printf("\n");

  return 0;
}
