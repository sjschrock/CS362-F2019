#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

int main() {

   // set players and seed
   int numOfPlayers = 2;
   int seed = 232;

   // declare game state
   struct gameState G, testGame;

   // set card array
   int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};

   // initialize game
   initializeGame(numOfPlayers, k, seed, &G);

   int currPlayer = 0;
   int choice1 = 2;


   // begin testing bug 8 - bonus coins
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #1 FOR BUG 8\n\n");

   G.hand[currPlayer][0] = steward;
   G.hand[currPlayer][1] = gold;
   G.hand[currPlayer][2] = gold;
   G.hand[currPlayer][3] = gold;
   G.hand[currPlayer][4] = gold;
   G.handCount[currPlayer] = 5;

   G.coins = 0;

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   cardEffect(steward, choice1, 0, 0, &testGame, 0, 0);

   if (G.coins + 2 == testGame.coins) {
      printf("OK:  the number of coins increased by 2.\n");
      printf("Number of coins before play = %d\n", G.coins);
      printf("Number of coins after play = %d\n", testGame.coins);
      printf("Number of coins expected = %d\n\n", G.coins + 2);
   }
   else {
      printf("ERROR:  the number of coins did not increase by 2.\n");
      printf("Number of coins before play = %d\n", G.coins);
      printf("Number of coins after play = %d\n", testGame.coins);
      printf("Number of coins expected = %d\n\n", G.coins + 2);
   }


   printf("END TEST #1 FOR BUG 8\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   // begin testing bug 8 - bonus coins
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #2 FOR BUG 8\n\n");

   G.hand[currPlayer][0] = steward;
   G.hand[currPlayer][1] = gold;
   G.hand[currPlayer][2] = gold;
   G.hand[currPlayer][3] = gold;
   G.hand[currPlayer][4] = gold;
   G.handCount[currPlayer] = 5;

   G.coins = 0;

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   playCard(0, choice1, 0, 0, &testGame);

   if (G.coins + 2 == testGame.coins) {
      printf("OK:  the number of coins increased by 2.\n");
      printf("Number of coins before play = %d\n", G.coins);
      printf("Number of coins after play = %d\n", testGame.coins);
      printf("Number of coins expected = %d\n\n", G.coins + 2);
   }
   else {
      printf("ERROR:  the number of coins did not increase by 2.\n");
      printf("Number of coins before play = %d\n", G.coins);
      printf("Number of coins after play = %d\n", testGame.coins);
      printf("Number of coins expected = %d\n\n", G.coins + 2);
   }


   printf("END TEST #2 FOR BUG 8\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");


   return 0;

}
