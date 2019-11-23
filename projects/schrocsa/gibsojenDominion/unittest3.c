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
	int discardCount2;
	int handCount;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int hand = 5;
	int coppers[hand];
	int currentPlayer = 0;
	int nextPlayer = 1;


	printf("\n\nTesting ambassadorEffect():\n");

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
		
	r = ambassadorEffect(0, 1, 3, currentPlayer, &G); // test the function with choice2 too large

	if (r == -1)
	{
		printf("Function fails if choice2 is too large: PASS\n");
	}
	else
	{
		printf("Function fails if choice2 is too large: FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game

	r = ambassadorEffect(0, 1, -1, currentPlayer, &G); // test the function with choice2 too large

	if (r == -1)
	{
		printf("Function fails if choice2 is too small: PASS\n");
	}
	else
	{
		printf("Function fails if choice2 is too small: FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game

	r = ambassadorEffect(0, 0, 1, currentPlayer, &G); // test the function with choice1 = handPos

	if(r == -1)
	{
		printf("Function fails if choice1 is invalid: PASS\n");
	}
	else
	{
		printf("Function fails if choice1 is invalid: FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = ambassador;
	G.hand[currentPlayer][3] = estate;

	r = ambassadorEffect(0, 3, 2, currentPlayer, &G); // test the function with j too small

	if (r == -1)
	{
		printf("Function fails if too few to discard: PASS\n");
	}
	else
	{
		printf("Function fails if too few to discard: FAIL\n");
	}

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
	//set variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = ambassador;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = estate;
	G.supplyCount[copper] = 0;
	handCount = G.handCount[currentPlayer];
	discardCount2 = G.discardCount[nextPlayer];
	
	ambassadorEffect(0, 1, 2, currentPlayer, &G); // test the function discarding 2 cards

	printf("\nTesting Ambassador discarding 2 cards:\n");
		
	if(G.supplyCount[copper] == 1) // verify +1 added to supply count
	{
		printf("Supply Count +1 = PASS\n");
	}
	else
	{
		printf("Supply Count +1 = FAIL\n");
	}

	if(G.handCount[currentPlayer] == handCount - 2) 
	{
		printf("Hand count -2 = PASS\n");
	}
	else 
	{
		printf("Hand count -2 = FAIL\n");
	}

	if (G.discardCount[nextPlayer] == discardCount2 + 1)
	{
		printf("Next player gained card = PASS\n");
	}
	else
	{
		printf("Next player gained card = FAIL\n");
	}

	printf("\nTesting Ambassador discarding 1 card:\n");

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
												 //set variables
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.hand[currentPlayer][0] = ambassador;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = estate;
	G.supplyCount[copper] = 0;
	handCount = G.handCount[currentPlayer];
	discardCount2 = G.discardCount[nextPlayer];

	ambassadorEffect(0, 1, 1, currentPlayer, &G); // test the function discarding 1 card

	if (G.supplyCount[copper] == 0) // verify supply count unchanged
	{
		printf("Supply Count unchanged = PASS\n");
	}
	else
	{
		printf("Supply Count unchanged = FAIL\n");
	}

	if (G.handCount[currentPlayer] == handCount - 1)
	{
		printf("Hand count -2 = PASS\n");
	}
	else
	{
		printf("Hand count -2 = FAIL\n");
	}

	if (G.discardCount[nextPlayer] == discardCount2 + 1)
	{
		printf("Next player gained card = PASS\n");
	}
	else
	{
		printf("Next player gained card = FAIL\n");
	}


	printf("\n\n");

	return 0;
}