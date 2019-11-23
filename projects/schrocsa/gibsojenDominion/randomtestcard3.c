#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include "kingdom_cards.h"

int main()
{
	struct gameState G;
	int i;
	int j;
	int preActions;
	int preCoins;
	int discardCount;
	int discardCount2;
	int deckCount;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, minion, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int hand;
	int currentPlayer;
	int nextPlayer;
	int choice1;
	int choice2;

	srand(time(0));

	printf("\n\nTesting tributeEffect():\n");
	//loop for random testing
	for (i = 0; i < 2000; i++)
	{
		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set the variables
		preActions = (rand() % (10 - 0 + 1));;
		preCoins = (rand() % (10 - 0 + 1));
		currentPlayer = (rand() % (2 - 1 + 1)) + 1;
		currentPlayer -= 1;
		hand = (rand() % (5 - 1 + 1)) + 1;
		for (j = 0; j < hand; j++) //fill the hand
		{
			G.hand[currentPlayer][j] = (rand() % (26 - 0 + 1));
		}
		
		G.whoseTurn = currentPlayer;

		if (currentPlayer)
		{
			nextPlayer = 0;
		}
		else
		{
			nextPlayer = 1;
		}
		G.deckCount[nextPlayer] = deckCount = (rand() % (20 - 0 + 1));
		for (j = 0; j < deckCount; j++) //fill the hand
		{
			G.deck[nextPlayer][j] = (rand() % (26 - 0 + 1));
		}

		G.discardCount[nextPlayer] = discardCount2 = (rand() % (20 - 0 + 1));
		for (j = 0; j < discardCount2; j++) //fill the hand
		{
			G.discard[nextPlayer][j] = (rand() % (26 - 0 + 1));
		}
		
		printf("Set up: Next Player deck count = %d, discard count = %d\n", deckCount, discardCount2);
		printf("Cards Revealed: ");
		if(deckCount == 0)
		{
			if(discardCount2 == 0)
			{
				printf("none\n");
			}
			else if(discardCount2 == 1)
			{
				printf("%d\n", G.discard[nextPlayer][0]);
			}
		}
		else if(deckCount == 1)
		{
			if(discardCount2 == 0)
			{
				printf("%d\n", G.deck[nextPlayer][0]);
			}
			else if(discardCount2 == 1)
			{
				printf("%d, %d\n", G.deck[nextPlayer][0], G.discard[nextPlayer][0]);
			}
		}
		else if(deckCount > 1)
		{
			printf("%d, %d\n", G.deck[nextPlayer][deckCount - 1], G.deck[nextPlayer][deckCount - 2]);
		}
		
		tributeCard(&G, currentPlayer); // test the function

		if(deckCount == 0)
		{
			if(discardCount2 > 1)
			{
				printf("%d, %d\n", G.discard[nextPlayer][0], G.discard[nextPlayer][1]);
			}
		}

		printf("\n1 Action card:\n");

		if (G.numActions == preActions + 2)
		{
			printf("Actions +2 = PASS\n");
		}
		else
		{
			printf("Actions +2 = FAIL\n");
		}

		printf("1 Victory card:\n");

		if (G.handCount[currentPlayer] == hand + 2)
		{
			printf("Hand Count +2 = PASS\n");
		}
		else
		{
			printf("Hand Count +2 = FAIL\n");
		}

		printf("1 Treasure card:\n");

		if (G.coins == preCoins + 2)
		{
			printf("Coins +2 = PASS\n");
		}
		else
		{
			printf("Coins +2 = FAIL\n");
		}

		printf("Same Action card:\n");

		if (G.numActions == preActions + 2)
		{
			printf("Actions +2 = PASS\n");
		}
		else
		{
			printf("Actions +2 = FAIL\n");
		}

		printf("Same Victory card:\n");

		if (G.handCount[currentPlayer] == hand + 2)
		{
			printf("Hand Count +2 = PASS\n");
		}
		else
		{
			printf("Hand Count +2 = FAIL\n");
		}

		printf("Same Treasure card:\n");

		if (G.coins == preCoins + 2)
		{
			printf("Coins +2 = PASS\n");
		}
		else
		{
			printf("Coins +2 = FAIL\n");
		}

		printf("Different Action cards:\n");

		if (G.numActions == preActions + 4)
		{
			printf("Actions +4 = PASS\n");
		}
		else
		{
			printf("Actions +4 = FAIL\n");
		}

		printf("Different Victory cards:\n");

		if (G.handCount[currentPlayer] == hand + 4)
		{
			printf("Hand Count +4 = PASS\n");
		}
		else
		{
			printf("Hand Count +4 = FAIL\n");
		}

		printf("Different Treasure cards:\n");

		if (G.coins == preCoins + 4)
		{
			printf("Coins +4 = PASS\n");
		}
		else
		{
			printf("Coins +4 = FAIL\n");
		}

		printf("\n\n");
	}


	return 0;
}