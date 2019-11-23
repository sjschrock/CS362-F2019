#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>

int main()
{
	struct gameState G;
	int i;
	int j;
	int preNumBuys;
	int preCoins;
	int discardCount;
	int handCount;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int hand;
	int currentPlayer;
	int estateFlag;
	int choice;
	int estateSupply;


	srand(time(0));

	printf("Testing baronEffect():\n");
	//loop for random testing
	for (i = 0; i < 50; i++)
	{
		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set variables
		hand = (rand() % (5 - 0 + 1));
		currentPlayer = (rand() % (1 - 0 + 1));
		estateSupply = (rand() % (10 - 0 + 1));
		G.supplyCount[estate] = estateSupply;
		G.handCount[currentPlayer] = hand;
		for (j = 0; j < hand; j++) //fill the hand
		{
			G.hand[currentPlayer][j] = (rand() % (26 - 0 + 1));
		}
		preNumBuys = G.numBuys;
		preCoins = G.coins;
		discardCount = G.discardCount[currentPlayer];
		handCount = G.handCount[currentPlayer];
		estateFlag = 0;
		choice = (rand() % (2 - 0 + 1));

		printf("Testing: choice = %d, current player = %d, estate supply = %d\n", choice, currentPlayer, estateSupply);

		for (j = 0; j < hand; j++) //check if estate in hand
		{
			if (G.hand[currentPlayer][j] == estate)
			{
				printf("Estate in hand\n\n");
				estateFlag = 1;
				break;
			}
		}

		if (!estateFlag)
		{
			printf("No Estate in hand\n\n");
		}

		baronEffect(choice, &G, currentPlayer); // test the function 

		if (G.numBuys == preNumBuys + 1) // verify +1 added to number of buys
		{
			printf("+1 Buys = PASS\n");
		}
		else
		{
			printf("+1 Buys = FAIL\n");
		}

		if (G.coins == preCoins + 4) // verify +4 coins added to buying power
		{
			printf("+4 coins = PASS\n");
		}
		else
		{
			printf("+4 coins = FAIL\n");
		}

		if (G.discard[currentPlayer][discardCount] == estate) // verify estate card is discarded to discard pile
		{
			printf("Estate discarded = PASS\n");
		}
		else
		{
			printf("Estate discarded = FAIL\n");
		}

		if (G.discardCount[currentPlayer] == discardCount + 1) // verify discard count increased by 1
		{
			printf("Discard count +1 = PASS\n");
		}
		else
		{
			printf("Discard count +1 = FAIL\n");
		}

		if (G.handCount[currentPlayer] == handCount - 1) // verify hand count decreased by 1
		{
			printf("Hand count -1 = PASS\n");
		}
		else
		{
			printf("Hand count -1 = FAIL\n");
		}

		if (G.hand[currentPlayer][G.handCount[currentPlayer]] == -1) // verify last position in hand is not -1
		{
			printf("Last hand position not -1 = PASS\n");
		}
		else
		{
			printf("Last hand position not -1 = FAIL\n");
		}

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

		if (G.supplyCount[estate] == estateSupply - 1) // verify estate supply count -1
		{
			printf("Estate supply -1 = PASS\n");
		}
		else
		{
			printf("Estate supply -1 = FAIL\n");
		}

		if (G.discardCount[currentPlayer] == discardCount) // verify discard count unchanged
		{
			printf("Discard count same = PASS\n");
		}
		else
		{
			printf("Discard count same = FAIL\n");
		}

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

		if (G.supplyCount[estate] == estateSupply - 1) // verify estate supply count -1
		{
			printf("Estate supply -1 = PASS\n");
		}
		else
		{
			printf("Estate supply -1 = FAIL\n");
		}

		if (G.discardCount[currentPlayer] == discardCount) // verify discard count unchanged
		{
			printf("Discard count same = PASS\n");
		}
		else
		{
			printf("Discard count same = FAIL\n");
		}

		printf("\n");

	}

	return 0;

}	