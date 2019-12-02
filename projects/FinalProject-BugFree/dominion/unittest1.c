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
  // set card array
  int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
  int numOfPlayers = 2;
  int playerHand[5] = {copper, copper, copper, silver, silver};
  int seed = rand() % 100 + 1;

  // declare game state
  struct gameState G, testGame;

  // clear the game state
  memset(&G, 23, sizeof(struct gameState));
  // initialize game
  initializeGame(numOfPlayers, k, seed, &G);

  // begin testing bug 1 - mine discardCard
  // discard copper for gold
  printf("--------------------------------------------------------------------------\n");
  printf("BEGIN TEST #1 FOR BUG 1\n\n");

  G.playedCardCount = 0;

  //copy game state for test game
  memcpy(&testGame, &G, sizeof(struct gameState));
  memcpy(testGame.hand[currPlayer], playerHand, sizeof(int) * 5);

  // call function
  cardEffect(mine, choice1, choice2, 0, &testGame, 0, 0);

  printf("Call cardEffect() function with mine case and choice1 is %d and choice 2 is %d.\n\n", choice1, choice2);

  if (G.playedCardCount == testGame.playedCardCount)
  {
    printf("OK:  the number of played cards remains the same.\n");
  }
  else
  {
    printf("ERROR:  the number of played cards changes.\n");
  }

  printf("Number of played cards before play = %d\n", G.playedCardCount);
  printf("Number of played cards after play = %d\n", testGame.playedCardCount);
  printf("Number of played cards expected = %d\n\n", G.playedCardCount);

  printf("END TEST #1 FOR BUG 1\n");
  printf("--------------------------------------------------------------------------\n");
  printf("\n");

  return 0;
}
