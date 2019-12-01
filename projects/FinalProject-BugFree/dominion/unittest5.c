#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
   srand(time(NULL));

   int cards[4] = {estate, duchy, province, great_hall };
   int currPlayer = 0;		
   int finalScore = 0;			// track the score from function call
   struct gameState G;			// declare game state
   int i;
   int k[10] = { adventurer, baron, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute };  // card array
   int localScore = 0;			// track score locally
   int numOfCurses = 10;		// number of curses to add to hands
   int numOfPlayers = 2;		// set players
   int cardScores[4] = { 1, 3, 6, 1 };	// scores of cards
   int seed = rand() % 100 + 1;         // random seed

   // clear the game state
   memset(&G, 23, sizeof(struct gameState));
  
   // initialize game
   initializeGame(numOfPlayers, k, seed, &G);
   

   // begin testing bug 5 - scoreFor
   // test when there are less discards than cards in deck
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #1 FOR BUG 5\n\n");


   G.handCount[currPlayer] = 0;
   G.deckCount[currPlayer] = 0;
   G.discardCount[currPlayer] = 0;

   // add 10 cursses to deck, hand, and discards
   for (i = 0; i < numOfCurses; i++) {
      G.hand[currPlayer][i] = curse;
      G.deck[currPlayer][i] = curse;
      G.discard[currPlayer][i] = curse;

      G.handCount[currPlayer]++;
      G.deckCount[currPlayer]++;
      G.discardCount[currPlayer]++;
      localScore += -1 * 3;
   }

   // add cards from card array
   for (int i = 0; i < 4; i++) {
      G.hand[currPlayer][i + numOfCurses] = cards[i];
      G.deck[currPlayer][i + numOfCurses] = cards[i];
      G.discard[currPlayer][i + numOfCurses] = cards[i];

      G.handCount[currPlayer]++;
      G.deckCount[currPlayer]++;
      G.discardCount[currPlayer]++;
      localScore += cardScores[i] * 3;
   }

   // add gardens to deck and hand
   G.hand[currPlayer][G.handCount[currPlayer]] = gardens;
   G.deck[currPlayer][G.deckCount[currPlayer]] = gardens;

   G.handCount[currPlayer]++;
   G.deckCount[currPlayer]++;

   localScore += (fullDeckCount(currPlayer, 0, &G) / 10) * 2;
 
   printf("For this test, there are %d discards and %d cards in the deck.\n\n", G.discardCount[currPlayer], G.deckCount[currPlayer]); 

   finalScore = scoreFor(currPlayer, &G);
  
   if (finalScore == localScore) {
      printf("OK:  Final score is %d.\n", localScore);
   }
   else {
      printf("ERROR:  Final score is %d, but it should be %d.\n", finalScore, localScore);
   }

   printf("\n");

   printf("END TEST #1 FOR BUG 5\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n");



   // begin testing bug 5 - scoreFor
   // test when there are less in deck that discards
   printf("--------------------------------------------------------------------------\n");
   printf("BEGIN TEST #2 FOR BUG 5\n\n");


   G.handCount[currPlayer] = 0;
   G.deckCount[currPlayer] = 0;
   G.discardCount[currPlayer] = 0;
   localScore = 0;

   // add 10 cursses to deck, hand, and discards
   for (i = 0; i < numOfCurses; i++) {
      G.hand[currPlayer][i] = curse;
      G.deck[currPlayer][i] = curse;
      G.discard[currPlayer][i] = curse;

      G.handCount[currPlayer]++;
      G.deckCount[currPlayer]++;
      G.discardCount[currPlayer]++;
      localScore += -1 * 3;
   }

   // add cards from card array
   for (int i = 0; i < 4; i++) {
      G.hand[currPlayer][i + numOfCurses] = cards[i];
      G.deck[currPlayer][i + numOfCurses] = cards[i];
      G.discard[currPlayer][i + numOfCurses] = cards[i];

      G.handCount[currPlayer]++;
      G.deckCount[currPlayer]++;
      G.discardCount[currPlayer]++;
      localScore += cardScores[i] * 3;
   }

   // add gardens to discards and hand
   G.hand[currPlayer][G.handCount[currPlayer]] = gardens;
   G.discard[currPlayer][G.deckCount[currPlayer]] = gardens;

   G.handCount[currPlayer]++;
   G.discardCount[currPlayer]++;

   localScore += (fullDeckCount(currPlayer, 0, &G) / 10) * 2;
 
   printf("For this test, there are %d discards and %d cards in the deck.\n\n", G.discardCount[currPlayer], G.deckCount[currPlayer]); 

   finalScore = scoreFor(currPlayer, &G);

   if (finalScore == localScore) {
      printf("OK:  Final score is %d.\n", localScore);
   }
   else {
      printf("ERROR:  Final score is %d, but it should be %d.\n", finalScore, localScore);
   }

   printf("\n");

   printf("END TEST #2 FOR BUG 5\n");
   printf("--------------------------------------------------------------------------\n");
   printf("\n\n");

   return 0;
}
