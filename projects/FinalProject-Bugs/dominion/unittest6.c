#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

int main() {
   
   int choice1 = mine;  // if province, it would be too expensive and create an infinite loop
   int currPlayer = 0;
   struct gameState G, testGame;	// declare game state
   int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};   // set card array
   int numOfPlayers = 2;		// set number of players
   int seed = 232;			// random seed


   // initialize game
   initializeGame(numOfPlayers, k, seed, &G);

   

   // begin testing bug 6 - feast
   // trade for mine card with 0 coins
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #1 FOR BUG 6\n\n");


   // reset coins
   G.coins = 0;


   //copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   // call function
   cardEffect(feast, choice1, 0, 0, &testGame, 0, 0);

   printf("Call cardEffect() function with feast case and choice1 is mine.\n\n");


   if (G.coins == testGame.coins) {
      printf("OK:  the number of coins remains the same.\n");
   }  
   else {
      printf("ERROR:  the number of coins changed.\n");
   }

   printf("Number of coins before play = %d\n", G.coins);
   printf("Number of coins after play = %d\n", testGame.coins);
   printf("Number of coins expected = %d\n\n", G.coins);


   if (G.discardCount[currPlayer] + 1 == testGame.discardCount[currPlayer]) {
      printf("OK:  the number of discards increased by 1.\n");
   }
   else {
      printf("ERROR:  the number of discards did not increase by 1.\n");
   }

   printf("Number of discards before play = %d\n", G.discardCount[currPlayer]);
   printf("Number of discards after play = %d\n", testGame.discardCount[currPlayer]);
   printf("Number of discards expected = %d\n\n", G.discardCount[currPlayer]);


   printf("\n");

   printf("END TEST #1 FOR BUG 6\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n\n");


   return 0;

}


