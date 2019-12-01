#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>

int main()
{
	srand(time(NULL));

	int currentPlayer = 0;
	int handCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int numActions;
	int numCoins;
	int nextPlayer = 1;
	int numPlayers = 2;
	int seed = rand() % 100 + 1;
	struct gameState G;

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game

	//begin testing bug 9

	printf("--------------------------------------------------------------------------\n");
   	printf("BEGIN TEST #1 FOR BUG 9\n\n");

	
	//set the variables for the gameState
	G.discardCount[nextPlayer] = 0;
	G.deckCount[nextPlayer] = 1;
	G.deck[nextPlayer][0] = copper;
	G.whoseTurn = 0;

	//set up the variables for the assertions
	numActions = G.numActions;
	numCoins = G.coins;
	handCount = G.handCount[currentPlayer];
	
	printf("For this test there are %d cards in deck and %d cards in discard\n", G.deckCount[nextPlayer], G.discardCount[nextPlayer]);
	printf("Revealed card is %d\n", G.deck[nextPlayer][0]);

	//call the function with the bug	
	cardEffect(tribute, 0, 0, 0, &G, 0, 0);

	//run tests
	if(G.numActions == numActions)
	{
		printf("OK:	numsActions is unchanged\n");
	}
	else
	{
		printf("ERROR:	numActions is %d, but it should be %d\n", G.numActions, numActions);
	}

	if(G.coins == numCoins + 2)
	{
		printf("OK:	coins increased by 2\n");
	}
	else
	{
		printf("ERROR:	coins is %d, but it should be %d\n", G.coins, numCoins + 2);
	}

	if(G.handCount[currentPlayer] == handCount)
	{
		printf("OK:	handCount is unchanged\n");
	}
	else
	{
		printf("ERROR:	handCount is %d, but it should be %d\n", G.handCount[currentPlayer], handCount);
	}

	printf("\n");
	printf("END TEST #1 FOR BUG 9\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	
	//test 2
	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game

	printf("--------------------------------------------------------------------------\n");
   	printf("BEGIN TEST #2 FOR BUG 9\n\n");

	
	//set the variables for the gameState
	G.discardCount[nextPlayer] = 1;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = copper;
	G.whoseTurn = 0;

	//set up the variables for the assertions
	numActions = G.numActions;
	numCoins = G.coins;
	handCount = G.handCount[currentPlayer];
	
	printf("For this test there are %d cards in deck and %d cards in discard\n", G.deckCount[nextPlayer], G.discardCount[nextPlayer]);
	printf("Revealed card is %d\n", G.discard[nextPlayer][0]);
	
	//call the function with the bug	
	cardEffect(tribute, 0, 0, 0, &G, 0, 0);

	//run tests
	if(G.numActions == numActions)
	{
		printf("OK:	numsActions is unchanged\n");
	}
	else
	{
		printf("ERROR:	numActions is %d, but it should be %d\n", G.numActions, numActions);
	}

	if(G.coins == numCoins + 2)
	{
		printf("OK:	coins increased by 2\n");
	}
	else
	{
		printf("ERROR:	coins is %d, but it should be %d\n", G.coins, numCoins + 2);
	}

	if(G.handCount[currentPlayer] == handCount)
	{
		printf("OK:	handCount is unchanged\n");
	}
	else
	{
		printf("ERROR:	handCount is %d, but it should be %d\n", G.handCount[currentPlayer], handCount);
	}

	printf("\n");
	printf("END TEST #2 FOR BUG 9\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	
	//test 3
	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game

	printf("--------------------------------------------------------------------------\n");
   	printf("BEGIN TEST #3 FOR BUG 9\n\n");

	
	//set the variables for the gameState
	G.discardCount[nextPlayer] = 0;
	G.deckCount[nextPlayer] = 2;
	G.deck[nextPlayer][0] = copper;
	G.deck[nextPlayer][1] = copper;
	G.whoseTurn = 0;

	//set up the variables for the assertions
	numActions = G.numActions;
	numCoins = G.coins;
	handCount = G.handCount[currentPlayer];
	
	printf("For this test there are %d cards in deck and %d cards in discard\n", G.deckCount[nextPlayer], G.discardCount[nextPlayer]);
	printf("Revealed cards are %d and %d\n", G.deck[nextPlayer][0], G.deck[nextPlayer][1]);
	//call the function with the bug	
	cardEffect(tribute, 0, 0, 0, &G, 0, 0);

	//run tests
	if(G.numActions == numActions)
	{
		printf("OK:	numsActions is unchanged\n");
	}
	else
	{
		printf("ERROR:	numActions is %d, but it should be %d\n", G.numActions, numActions);
	}

	if(G.coins == numCoins + 2)
	{
		printf("OK:	coins increased by 2\n");
	}
	else
	{
		printf("ERROR:	coins is %d, but it should be %d\n", G.coins, numCoins + 2);
	}

	if(G.handCount[currentPlayer] == handCount)
	{
		printf("OK:	handCount is unchanged\n");
	}
	else
	{
		printf("ERROR:	handCount is %d, but it should be %d\n", G.handCount[currentPlayer], handCount);
	}

	printf("\n");
	printf("END TEST #3 FOR BUG 9\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	return 0;
}