#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include "kingdom_cards.h"

int main()
{
	struct gameState G;
	int i;
	int preNumBuys;
	int preCoins;
	int discardCount;
	int handCount;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int hand = 6;
	int coppers[hand];
	int currentPlayer = 0;
	int estateCount = 1;


	printf("Testing baronCard():\n");
	//loop to test estate card in each hand position
	for(i = 0; i < hand; i++)
	{
		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set variables
		G.handCount[currentPlayer] = hand;
		memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
		G.hand[currentPlayer][i] = estate;
		G.hand[currentPlayer][5] = -1;
		preNumBuys = G.numBuys;
		preCoins = G.coins;
		discardCount = G.discardCount[currentPlayer];
		handCount = G.handCount[currentPlayer];
		
		baronCard(1, &G, currentPlayer); // test the function with choice 1 and an estate card in the hand

		printf("\nTesting Estate in hand position %d:\n", i);
		
		if(G.numBuys == preNumBuys + 1) // verify +1 added to number of buys
		{
			printf("+1 Buys = PASS\n");
		}
		else
		{
			printf("+1 Buys = FAIL\n");
		}

		if(G.coins == preCoins + 4) // verify +4 coins added to buying power
		{
			printf("+4 coins = PASS\n");
		}
		else
		{
			printf("+4 coins = FAIL\n");
		}

		if(G.discard[currentPlayer][discardCount] == estate) // verify estate card is discarded to discard pile
		{
			printf("Estate discarded = PASS\n");
		}
		else
		{
			printf("Estate discarded = FAIL\n");
		}

		if(G.discardCount[currentPlayer] == discardCount + 1) // verify discard count increased by 1
		{
			printf("Discard count +1 = PASS\n");
		}
		else
		{
			printf("Discard count +1 = FAIL\n");
		}

		if(G.handCount[currentPlayer] == handCount - 1) // verify hand count decreased by 1
		{
			printf("Hand count -1 = PASS\n");
		}
		else
		{
			printf("Hand count -1 = FAIL\n");
		}

		if(G.hand[currentPlayer][G.handCount[currentPlayer]] == -1) // verify last position in hand is not -1
		{
			printf("Last hand position not -1 = PASS\n");
		}
		else
		{
			printf("Last hand position not -1 = FAIL\n");
		}

		printf("\n");
	}

	//test the function with choice 1 and no estate card in hand
	printf("Testing choice 1 and no estate card in hand:\n");
	memset(&G, 0, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.supplyCount[estate] = estateCount;
	discardCount = G.discardCount[currentPlayer];
	
	baronCard(1, &G, currentPlayer); // test the function with choice 1 and no estate card in the hand
	
	printf("\nTesting gainEstate() with estate in supply:\n");

	if(G.discardCount[currentPlayer] == discardCount + 1) // verify gainEstate increases discard count
	{
		printf("Discard count +1 = PASS\n");
	}
	else
	{
		printf("Discard count +1 = FAIL\n");
	}

	if (G.discard[currentPlayer][discardCount] == estate) // verify estate card is added to discard pile
	{
		printf("Estate discarded = PASS\n");
	}
	else
	{
		printf("Estate discarded = FAIL\n");
	}

	if(G.supplyCount[estate] == estateCount - 1) // verify estate supply count -1
	{
		printf("Estate supply -1 = PASS\n");
	}
	else
	{
		printf("Estate supply -1 = FAIL\n");
	}

	printf("\nTesting gainEstate() with no estate in supply:\n");

	memset(&G, 0, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.supplyCount[estate] = 0; // set estate supply to 0
	discardCount = G.discardCount[currentPlayer];

	baronCard(1, &G, currentPlayer);

	if (G.discardCount[currentPlayer] == discardCount) // verify discard count unchanged
	{
		printf("Discard count same = PASS\n");
	}
	else
	{
		printf("Discard count same = FAIL\n");
	}

	printf("\nTesting choice 0 (gain estate card):\n");
	memset(&G, 0, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	discardCount = G.discardCount[currentPlayer];
	G.supplyCount[estate] = estateCount;

	baronCard(0, &G, currentPlayer); // test the function with choice 0

	printf("Testing gainEstate() with estate in supply:\n");

	if (G.discardCount[currentPlayer] == discardCount + 1) // verify gainEstate increases discard count
	{
		printf("Discard count +1 = PASS\n");
	}
	else
	{
		printf("Discard count +1 = FAIL\n");
	}

	if (G.discard[currentPlayer][discardCount] == estate) // verify estate card is added to discard pile
	{
		printf("Estate discarded = PASS\n");
	}
	else
	{
		printf("Estate discarded = FAIL\n");
	}

	if (G.supplyCount[estate] == estateCount - 1) // verify estate supply count -1
	{
		printf("Estate supply -1 = PASS\n");
	}
	else
	{
		printf("Estate supply -1 = FAIL\n");
	}

	printf("\nTesting gainEstate() with no estate in supply:\n");

	memset(&G, 0, sizeof(struct gameState)); //clear the game state
	initializeGame(numPlayers, k, seed, &G); // initialize a new game
	G.handCount[currentPlayer] = hand;
	memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
	G.supplyCount[estate] = 0; // set estate supply to 0
	discardCount = G.discardCount[currentPlayer];

	baronCard(0, &G, currentPlayer);

	if (G.discardCount[currentPlayer] == discardCount) // verify discard count unchanged
	{
		printf("Discard count same = PASS\n");
	}
	else
	{
		printf("Discard count same = FAIL\n");
	}

	return 0;
}