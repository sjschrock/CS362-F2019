#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"

int main()
{
	int i, r;
	int currentPlayer = 0;
	int discardCount;
	int handCount;
	int k[10] = { ambassador, council_room, feast, gardens, mine, remodel, smithy, village, treasure_map, great_hall };
	int maps;
	int nextPlayer = 1;
	int numPlayers = 2;
	int seed = 1000;
	struct gameState G;

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game

	//begin testing bug 10

	printf("--------------------------------------------------------------------------\n");
   	printf("BEGIN TEST #1 FOR BUG 10\n\n");

	
	//set the variables for the gameState
	G.handCount[currentPlayer] = 5;
	for(i = 1; i < G.handCount[currentPlayer]; i++)
	{
		G.hand[currentPlayer][i] = treasure_map;
	}
	G.hand[currentPlayer][0] = ambassador;
	G.whoseTurn = 0;

	//set up the variables for the assertions
	handCount = G.handCount[currentPlayer];
	maps = G.supplyCount[treasure_map];
	discardCount = G.discardCount[nextPlayer];
	
	printf("For this test there are 4 treasure map cards and 1 ambassador card in hand\n");

	//call the function with the bug	
	r = cardEffect(ambassador, 1, 2, 0, &G, 0, 0);

	//run tests
	if(G.handCount[currentPlayer] == handCount - 2)
	{
		printf("OK:	handCount is -2\n");
	}
	else
	{
		printf("ERROR:	handCount is %d, but it should be %d\n", G.handCount[currentPlayer], handCount - 2);
	}

	if(G.supplyCount[treasure_map] == maps - 1)
	{
		printf("OK:	treasure map supply count -1\n");
	}
	else
	{
		printf("ERROR:	treasure_map supply count is %d, but it should be %d\n", G.supplyCount[treasure_map], maps - 1);
	}

	if(G.discardCount[nextPlayer] == discardCount + 1)
	{
		printf("OK:	nextPlayer discardCount +1\n");
	}
	else
	{
		printf("ERROR:	nextPlayer discardCount is %d, but it should be %d\n", G.discardCount[nextPlayer], discardCount + 1);
	}

	if(G.discard[nextPlayer][G.discardCount[nextPlayer] - 1] == treasure_map)
	{
		printf("OK:	treasure map is last card in discard\n");
	}
	else
	{
		printf("ERROR:	last card in discard is %d, but it should be %d\n", G.discard[nextPlayer][G.discardCount[nextPlayer] - 1], treasure_map);
	}

	if(r == 0)
	{
		printf("OK:	return value is 0\n");
	}
	else
	{
		printf("ERROR:	return value is %d, but it should be %d\n", r, 0);
	}

	printf("\n");
	printf("END TEST #1 FOR BUG 10\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n");

	printf("\n\n");

	return 0;
}