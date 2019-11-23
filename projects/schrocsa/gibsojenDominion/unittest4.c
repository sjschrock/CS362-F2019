#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"

int main()
{
	struct gameState G;
	int r;
	int handCount;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int currentPlayer = 0;
	int nextPlayer = 1;
	int numActions;
	int numCoins;

	printf("\n\nTesting tributeEffect():\n");

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
	//set the variables
	numActions = G.numActions;
	G.discardCount[nextPlayer] = 0;
	G.deckCount[nextPlayer] = 1;
	G.deck[nextPlayer][0] = feast;
	G.deck[nextPlayer][1] = -1;
		
	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 1 in deck, 0 in discard & Action card:\n");

	if(G.numActions == numActions + 2)
	{
		printf("Actions +2 = PASS\n");
	}
	else
	{
		printf("Actions +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	handCount = G.handCount[currentPlayer];
	G.discardCount[nextPlayer] = 0;
	G.deckCount[nextPlayer] = 1;
	G.deck[nextPlayer][0] = estate;
	G.deck[nextPlayer][1] = -1;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 1 in deck, 0 in discard & Victory card:\n");

	if (G.handCount[currentPlayer] == handCount + 2)
	{
		printf("Hand Count +2 = PASS\n");
	}
	else
	{
		printf("Hand Count +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numCoins = G.coins;
	G.discardCount[nextPlayer] = 0;
	G.deckCount[nextPlayer] = 1;
	G.deck[nextPlayer][0] = copper;
	G.deck[nextPlayer][1] = -1;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 1 in deck, 0 in discard & Treasure card:\n");

	if (G.coins == numCoins + 2)
	{
		printf("Coins +2 = PASS\n");
	}
	else
	{
		printf("Coins +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numActions = G.numActions;
	G.discardCount[nextPlayer] = 1;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = feast;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 1 in discard & Action card:\n");

	if (G.numActions == numActions + 2)
	{
		printf("Actions +2 = PASS\n");
	}
	else
	{
		printf("Actions +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	handCount = G.handCount[currentPlayer];
	G.discardCount[nextPlayer] = 1;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = estate;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 1 in discard & Victory card:\n");

	if (G.handCount[currentPlayer] == handCount + 2)
	{
		printf("Hand Count +2 = PASS\n");
	}
	else
	{
		printf("Hand Count +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numCoins = G.coins;
	G.discardCount[nextPlayer] = 1;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = copper;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 1 in discard & Treasure card:\n");

	if (G.coins == numCoins + 2)
	{
		printf("Coins +2 = PASS\n");
	}
	else
	{
		printf("Coins +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numActions = G.numActions;
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = feast;
	G.discard[nextPlayer][1] = feast;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & same Action card:\n");

	if (G.numActions == numActions + 2)
	{
		printf("Actions +2 = PASS\n");
	}
	else
	{
		printf("Actions +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	handCount = G.handCount[currentPlayer];
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = estate;
	G.discard[nextPlayer][1] = estate;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & same Victory card:\n");

	if (G.handCount[currentPlayer] == handCount + 2)
	{
		printf("Hand Count +2 = PASS\n");
	}
	else
	{
		printf("Hand Count +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numCoins = G.coins;
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = copper;
	G.discard[nextPlayer][1] = copper;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & same Treasure card:\n");

	if (G.coins == numCoins + 2)
	{
		printf("Coins +2 = PASS\n");
	}
	else
	{
		printf("Coins +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numActions = G.numActions;
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = feast;
	G.discard[nextPlayer][1] = mine;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & different Action card:\n");

	if (G.numActions == numActions + 4)
	{
		printf("Actions +4 = PASS\n");
	}
	else
	{
		printf("Actions +4 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	handCount = G.handCount[currentPlayer];
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = estate;
	G.discard[nextPlayer][1] = province;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & different Victory card:\n");

	if (G.handCount[currentPlayer] == handCount + 4)
	{
		printf("Hand Count +4 = PASS\n");
	}
	else
	{
		printf("Hand Count +4 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numCoins = G.coins;
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = copper;
	G.discard[nextPlayer][1] = gold;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & different Treasure card:\n");

	if (G.coins == numCoins + 4)
	{
		printf("Coins +4 = PASS\n");
	}
	else
	{
		printf("Coins +4 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numActions = G.numActions;
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = feast;
	G.discard[nextPlayer][1] = estate;
	handCount = G.handCount[currentPlayer];

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & Action/Victory card:\n");

	if (G.numActions == numActions + 2)
	{
		printf("Actions +2 = PASS\n");
	}
	else
	{
		printf("Actions +2 = FAIL\n");
	}

	if (G.handCount[currentPlayer] == handCount + 2)
	{
		printf("Hand Count +2 = PASS\n");
	}
	else
	{
		printf("Hand Count +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	handCount = G.handCount[currentPlayer];
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = feast;
	G.discard[nextPlayer][1] = gold;
	numActions = G.numActions;
	numCoins = G.coins;

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & Action/Treasure card:\n");

	if (G.numActions == numActions + 2)
	{
		printf("Actions +2 = PASS\n");
	}
	else
	{
		printf("Actions +2 = FAIL\n");
	}

	if (G.coins == numCoins + 2)
	{
		printf("Coins +2 = PASS\n");
	}
	else
	{
		printf("Coins +2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	numCoins = G.coins;
	G.discardCount[nextPlayer] = 2;
	G.deckCount[nextPlayer] = 0;
	G.discard[nextPlayer][0] = copper;
	G.discard[nextPlayer][1] = gold;
	handCount = G.handCount[currentPlayer];

	r = tributeEffect(currentPlayer, nextPlayer, &G);

	printf("\nTesting 0 in deck, 2 in discard & Treasure/Victory card:\n");

	if (G.coins == numCoins + 2)
	{
		printf("Coins +2 = PASS\n");
	}
	else
	{
		printf("Coins +2 = FAIL\n");
	}

	if (G.handCount[currentPlayer] == handCount + 2)
	{
		printf("Hand Count +2 = PASS\n");
	}
	else
	{
		printf("Hand Count +2 = FAIL\n");
	}
	
	printf("\n\n");

	return 0;
}