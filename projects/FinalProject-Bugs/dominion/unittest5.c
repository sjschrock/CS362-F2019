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
   struct gameState G;

   // set card array
   int k[10] = {adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};

   // initialize game
   initializeGame(numOfPlayers, k, seed, &G);

   int currPlayer = 0;

   // begin testing bug 5 - scoreFor
   // test when there are less discards than cards in deck
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #1 FOR BUG 5\n\n");

   G.hand[currPlayer][0] = estate; // 1 point
   G.hand[currPlayer][1] = estate; // 1 point
   G.hand[currPlayer][2] = estate; // 1 point
   G.hand[currPlayer][3] = estate; // 1 point
   G.hand[currPlayer][4] = estate; // 1 point
   G.handCount[currPlayer] = 5;

   G.deck[currPlayer][0] = duchy; // 3 points
   G.deck[currPlayer][1] = duchy; // 3 points
   G.deck[currPlayer][2] = duchy; // 3 points
   G.deck[currPlayer][3] = duchy; // 3 points
   G.deck[currPlayer][4] = duchy; // 3 points
   G.deckCount[currPlayer] = 5;

   G.discard[currPlayer][0] = province; // 6 points
   G.discard[currPlayer][1] = province; // 6 points
   G.discard[currPlayer][2] = province; // 6 points
   G.discardCount[currPlayer] = 3;

   // total of 38 points
  
   printf("For this test, there are %d discards and %d cards in the deck.\n\n", G.discardCount[currPlayer], G.deckCount[currPlayer]); 

   int finalScore;
   finalScore = scoreFor(currPlayer, &G);
  
   if (finalScore == 38) {
      printf("OK:  Final score is 38.\n");
   }
   else {
      printf("ERROR:  Final score is %d, but it should be 38.\n", finalScore);
   }

   printf("\n");

   printf("END TEST #1 FOR BUG 5\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   // begin testing bug 5 - scoreFor
   // test when there are less in deck that discards
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #2 FOR BUG 5\n\n");

   G.hand[currPlayer][0] = estate; // 1 point
   G.hand[currPlayer][1] = estate; // 1 point
   G.hand[currPlayer][2] = estate; // 1 point
   G.hand[currPlayer][3] = estate; // 1 point
   G.hand[currPlayer][4] = estate; // 1 point
   G.handCount[currPlayer] = 5;

   G.deck[currPlayer][0] = duchy; // 3 points
   G.deck[currPlayer][1] = duchy; // 3 points
   G.deckCount[currPlayer] = 2;

   G.discard[currPlayer][0] = province; // 6 points
   G.discard[currPlayer][1] = province; // 6 points
   G.discard[currPlayer][2] = province; // 6 points
   G.discard[currPlayer][3] = province; // 6 points
   G.discard[currPlayer][4] = province; // 6 points
   G.discardCount[currPlayer] = 5;

   // total of 41 points
  
   printf("For this test, there are %d discards and %d cards in the deck.\n\n", G.discardCount[currPlayer], G.deckCount[currPlayer]); 

   finalScore = scoreFor(currPlayer, &G);
  
   if (finalScore == 41) {
      printf("OK:  Final score is 41.\n");
   }
   else {
      printf("ERROR:  Final score is %d, but it should be 41.\n", finalScore);
   }

   printf("\n");

   printf("END TEST #2 FOR BUG 5\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n\n");

   return 0;
}
