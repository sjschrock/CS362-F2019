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
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int currentPlayer = 0;
	int hand = 5;
	int coppers[hand];

	printf("\n\nTesting mineEffect():\n");

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
	//set the variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = mine;
	G.hand[currentPlayer][1] = estate;
		
	r = mineEffect(1, gold, &G, 0, currentPlayer);

	if(r == -1)
	{
		printf("Function fails with non-treasure choice 1 = PASS\n");
	}
	else
	{
		printf("Function fails with non-treasure choice 1 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = mine;
	G.hand[currentPlayer][1] = estate;

	r = mineEffect(2, estate, &G, 0, currentPlayer);

	if (r == -1)
	{
		printf("Function fails with non-treasure choice 2 = PASS\n");
	}
	else
	{
		printf("Function fails with non-treasure choice 2 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = mine;
	G.hand[currentPlayer][1] = estate;

	r = mineEffect(2, gold, &G, 0, currentPlayer);

	if (r == -1)
	{
		printf("Function fails if choice 2 > +3 cost of choice 1 = PASS\n");
	}
	else
	{
		printf("Function fails if choice 2 > +3 cost of choice 1 = FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = mine;

	mineEffect(1, silver, &G, 0, currentPlayer);

	if (G.hand[currentPlayer][4] == 5)
	{
		printf("Trash copper gain silver = PASS\n");
	}
	else
	{
		printf("Trash copper gain silver = FAIL\n");
	}


	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set the variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = mine;
	G.hand[currentPlayer][1] = silver;

	mineEffect(1, gold, &G, 0, currentPlayer);

	if (G.hand[currentPlayer][4] == 6)
	{
		printf("Trash silver gain gold = PASS\n");
	}
	else
	{
		printf("Trash silver gain gold = FAIL\n");
	}

	
	printf("\n\n");

	return 0;
}