#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
   srand(time(NULL));

   int currPlayer = 0;
   struct gameState G, testGame;	// declare game state
   int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};  // set card array
   int nextPlayer = 1;
   int numOfPlayers = 2;		// set number of players
   int playerDeck1[8] = { copper, gold, silver, copper, silver, gold, copper, silver };
   int playerDeck2[5] = { remodel, outpost, feast, adventurer, tribute };
   int playerDeck3[5] = { province, duchy, estate, province, duchy };
   int playerHand[5] = { baron, duchy, mine, minion, ambassador };
   int seed = rand() % 100 + 1;         // random seed

   // clear the game state
   memset(&G, 23, sizeof(struct gameState));

   // initialize game
   initializeGame(numOfPlayers, k, seed, &G);


   // begin testing bug 7 - tribute
   // reveal two different treasure cards
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #1 FOR BUG 7\n\n");

   memcpy(G.hand[currPlayer], playerHand, sizeof(int) * 5);
   memcpy(G.deck[nextPlayer], playerDeck1, sizeof(int) * 8);

   G.handCount[currPlayer] = 5;
   G.deckCount[nextPlayer] = 8;

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   cardEffect(tribute, 0, 0, 0, &testGame, 0, 0);

   printf("Two different treasure cards were revealed.\n\n");

   if (G.coins + 4 == testGame.coins) {
      printf("OK:  the number of coins increased by 4, 2 for each treasure card.\n");
   }
   else {
      printf("ERROR:  the number of coins did not increase by 4, 2 for each treasure card.\n");
   }

   printf("Number of coins before play = %d\n", G.coins);
   printf("Number of coins after play = %d\n", testGame.coins);
   printf("Number of coins expected = %d\n\n", G.coins + 4);


   if (G.numActions == testGame.numActions) {
      printf("OK:  the number of actions remained the same.\n");
   }
   else {
      printf("ERROR:  the number of actions changed.\n");
   }

   printf("Number of actions before play = %d\n", G.numActions);
   printf("Number of actions after play = %d\n", testGame.numActions);
   printf("Number of actions expected = %d\n\n", G.numActions);

   if (G.handCount[currPlayer] == testGame.handCount[currPlayer]) {
      printf("OK:  the hand count of the current player has not changed.\n");
   }
   else {
      printf("ERROR:  the hand count of the current player changed.\n");
   }

   printf("Number of cards in hand before play = %d\n", G.handCount[currPlayer]);
   printf("Number of cards in hand after play = %d\n", testGame.handCount[currPlayer]);
   printf("Number of cards in hand expected = %d\n\n", G.handCount[currPlayer]);


   printf("END TEST #1 FOR BUG 7\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   // reveal two different action cards
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #2 FOR BUG 7\n\n");

   memcpy(G.hand[currPlayer], playerHand, sizeof(int) * 5);
   memcpy(G.deck[nextPlayer], playerDeck2, sizeof(int) * 5);

   G.handCount[currPlayer] = 5;
   G.deckCount[nextPlayer] = 5;
   

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   cardEffect(tribute, 0, 0, 0, &testGame, 0, 0);

   printf("Two different action cards were revealed.\n\n");
   
   if (G.coins == testGame.coins) {
      printf("OK:  the number of coins remained the same.\n");
   }
   else {
      printf("ERROR:  the number of coins changed.\n");
   }

   printf("Number of coins before play = %d\n", G.coins);
   printf("Number of coins after play = %d\n", testGame.coins);
   printf("Number of coins expected = %d\n\n", G.coins);


   if (G.numActions + 4 == testGame.numActions) {
      printf("OK:  the number of actions increased by 4, 2 for each action card revealed.\n");
   }
   else {
      printf("ERROR:  the number of actions did not increase by 4, 2 for each action card revealed.\n");
   }

   printf("Number of actions before play = %d\n", G.numActions);
   printf("Number of actions after play = %d\n", testGame.numActions);
   printf("Number of actions expected = %d\n\n", G.numActions + 4);

   if (G.handCount[currPlayer] == testGame.handCount[currPlayer]) {
      printf("OK:  the hand count of the current player has not changed.\n");
   }
   else {
      printf("ERROR:  the hand count of the current player changed.\n");
   }

   printf("Number of cards in hand before play = %d\n", G.handCount[currPlayer]);
   printf("Number of cards in hand after play = %d\n", testGame.handCount[currPlayer]);
   printf("Number of cards in hand expected = %d\n\n", G.handCount[currPlayer]);



   printf("END TEST #2 FOR BUG 7\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   // reveal two different victory cards
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #3 FOR BUG 7\n\n");


   memcpy(G.hand[currPlayer], playerHand, sizeof(int) * 5);
   memcpy(G.deck[nextPlayer], playerDeck3, sizeof(int) * 5);

   G.handCount[currPlayer] = 5;
   G.deckCount[nextPlayer] = 5;

   // copy game state for test game
   memcpy(&testGame, &G, sizeof(struct gameState));

   cardEffect(tribute, 0, 0, 0, &testGame, 0, 0);

   printf("Two different victory cards were revealed.\n\n");

   if (G.coins == testGame.coins) {
      printf("OK:  the number of coins remained the same.\n");
   }
   else {
      printf("ERROR:  the number of coins changed.\n");
   }

   printf("Number of coins before play = %d\n", G.coins);
   printf("Number of coins after play = %d\n", testGame.coins);
   printf("Number of coins expected = %d\n\n", G.coins);

   if (G.numActions == testGame.numActions) {
      printf("OK:  the number of actions remained the same.\n");
   }
   else {
      printf("ERROR:  the number of actions changed.\n");
   }

   printf("Number of actions before play = %d\n", G.numActions);
   printf("Number of actions after play = %d\n", testGame.numActions);
   printf("Number of actions expected = %d\n\n", G.numActions);

   if (G.handCount[currPlayer] + 4 == testGame.handCount[currPlayer]) {
      printf("OK:  the hand count of the current player has increased by 4 cards, +2 for each victory card.\n");
   }
   else {
      printf("ERROR:  the hand count of the current player did not increase by 4, +2 for each victory card.\n");
   }

   printf("Number of cards in hand before play = %d\n", G.handCount[currPlayer]);
   printf("Number of cards in hand after play = %d\n", testGame.handCount[currPlayer]);
   printf("Number of cards in hand expected = %d\n\n", G.handCount[currPlayer] + 4);


   printf("END TEST #3 FOR BUG 7\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   return 0;

}
