#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"

int main()
{
	struct gameState G;
	int i;
	int r;
	int preActions;
	int preCoins;
	int discardCount;
	int discardCount2;
	int handCount;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int hand = 5;
	int coppers[hand];
	int currentPlayer = 0;
	int nextPlayer;


	printf("\n\nTesting minionEffect():\n");
	//loop to test minion card in each hand position
	for(i = 0; i < hand; i++)
	{
		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set variables
		G.handCount[currentPlayer] = hand;
		memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
		G.hand[currentPlayer][i] = minion;
		preActions = G.numActions;
		preCoins = G.coins;
		handCount = G.handCount[currentPlayer];
		
		minionEffect(i, currentPlayer, &G, 1, 0); // test the function with choice 1

		printf("\nTesting Minion in hand position %d:\n", i);
		
		if(G.numActions == preActions + 1) // verify +1 added to number of actions
		{
			printf("+1 Action = PASS\n");
		}
		else
		{
			printf("+1 Action = FAIL\n");
		}

		printf("\nTesting choice1:\n");

		if(G.coins == preCoins + 2) // verify +2 coins added to buying power
		{
			printf("+2 coins = PASS\n");
		}
		else
		{
			printf("+2 coins = FAIL\n");
		}

		printf("\nTesting choice2:\n");

		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set variables
		G.handCount[currentPlayer] = hand;
		memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
		G.hand[currentPlayer][i] = minion;
		handCount = G.handCount[currentPlayer];
		nextPlayer = currentPlayer + 1;
		discardCount = G.discardCount[currentPlayer];
		G.handCount[nextPlayer] = hand;
		discardCount2 = G.discardCount[nextPlayer];

		minionEffect(i, currentPlayer, &G, 0, 1); // test the function with choice 2

		if(G.discardCount[currentPlayer] == discardCount + handCount) // verify hand is discarded
		{
			printf("Hand discarded = PASS\n");
		}
		else
		{
			printf("Hand discarded = FAIL\n");
		}

		if(G.handCount[currentPlayer] == 4) // verify 4 cards in hand
		{
			printf("Hand count is 4 = PASS\n");
		}
		else
		{
			printf("Hand count is 4 = FAIL\n");
		}

		printf("\nTesting player 2 has 5 cards in hand:\n");

		if(G.handCount[nextPlayer] == 4) // verify player 2 has 4 cards in hand
		{
			printf("Hand count 4 = PASS\n");
		}
		else
		{
			printf("Hand count 4 = FAIL\n");
		}

		if(G.discardCount[nextPlayer] == discardCount2 + hand) // verify player 2 discarded 5 cards
		{
			printf("Hand discarded = PASS\n");
		}
		else
		{
			printf("Hand discarded = FAIL\n");
		}

		printf("\nTesting player 2 has less than 5 cards in hand:\n");

		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set variables
		G.handCount[currentPlayer] = hand;
		memcpy(G.hand[currentPlayer], coppers, sizeof(int) * hand);
		G.hand[currentPlayer][i] = minion;
		nextPlayer = currentPlayer + 1;
		G.handCount[nextPlayer] = 4;
		discardCount2 = G.discardCount[nextPlayer];

		minionEffect(i, currentPlayer, &G, 0, 1); // test the function with choice 2

		if(G.discardCount[nextPlayer] == discardCount2)
		{
			printf("No discard = PASS\n");
		}
		else
		{
			printf("No discard = FAIL\n");
		}

		printf("\n");
	}


	return 0;
}