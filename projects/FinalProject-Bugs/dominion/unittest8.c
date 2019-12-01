#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
   srand(time(NULL));

   int choice1 = 2;
   int currPlayer = 0;
   struct gameState G, testGame; 	// declare game state
   int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};  // set card array
   int numOfPlayers = 2;		// set number of players
   int playerHand[5] = { steward, gold, gold, gold, gold };
   int seed = rand() % 100 + 1;         // random seed
		
   // clear the game state
   memset(&G, 23, sizeof(struct gameState));

   // initialize game
   initializeGame(numOfPlayers, k, seed, &G);


   // begin testing bug 8 - bonus coins
   // steward function uses bonus coins
   // showing the difference when cardEffect() is directly called, and when using playCard()
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #1 FOR BUG 8\n\n");

   memcpy(G.hand[currPlayer], playerHand, sizeof(int) * 5);
   G.handCount[currPlayer] = 5;

   G.coins = 0;

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   cardEffect(steward, choice1, 0, 0, &testGame, 0, 0);

   printf("Using cardEffect() function to call steward case.\n\n");
   
   if (G.coins + 2 == testGame.coins) {
      printf("OK:  the number of coins increased by 2.\n");
   }
   else {
      printf("ERROR:  the number of coins did not increase by 2.\n");
   }

   printf("Number of coins before play = %d\n", G.coins);
   printf("Number of coins after play = %d\n", testGame.coins);
   printf("Number of coins expected = %d\n\n", G.coins + 2);



   printf("END TEST #1 FOR BUG 8\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   // begin testing bug 8 - bonus coins
   // steward function uses bonus coins
   // showing the difference when cardEffect() is directly called, and when using playCard()
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #2 FOR BUG 8\n\n");

   memcpy(G.hand[currPlayer], playerHand, sizeof(int) * 5);
   G.handCount[currPlayer] = 5;

   G.coins = 0;

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   playCard(0, choice1, 0, 0, &testGame);

   printf("Using playCard() function to call cardEffect with steward case.\n\n");

   if (G.coins + 14 == testGame.coins) {
      printf("OK:  the number of coins increased by 2.\n");
   }
   else {
      printf("ERROR:  the number of coins did not increase by 2.\n");
   }

   printf("Number of coins before play = %d\n", G.coins);
   printf("Number of coins after play = %d\n", testGame.coins);
   printf("Number of coins expected = %d\n\n", G.coins + 14);



   printf("END TEST #2 FOR BUG 8\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");


   return 0;

}
