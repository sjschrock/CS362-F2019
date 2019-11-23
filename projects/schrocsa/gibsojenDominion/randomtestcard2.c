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
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, minion, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int hand;
	int currentPlayer;
	int nextPlayer;
	int choice1;
	int choice2;

	srand(time(0));

	printf("\n\nTesting minionEffect():\n");
	//loop for random testing
	for (i = 0; i < 50; i++)
	{
		memset(&G, 23, sizeof(struct gameState)); //clear the game state
		initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//set variables
		hand = (rand() % (5 - 1 + 1)) + 1;
		currentPlayer = (rand() % (2 - 1 + 1)) + 1;
		currentPlayer -= 1;
		G.whoseTurn = currentPlayer;
		G.handCount[currentPlayer] = hand;
		for (j = 0; j < hand; j++) //fill the hand
		{
			G.hand[currentPlayer][j] = (rand() % (26 - 0 + 1));
		}
		if(hand == 1)
		{
			j = 0;
		}
		else
		{
			j = (rand() % ((hand - 1) - 0 + 1));
		}
				choice1 = (rand() % (1 - 0 + 1));
		choice2 = (rand() % (1 - 0 + 1));
		G.numActions = (rand() % (10 - 0 + 1));
		G.coins = (rand() % (10 - 0 + 1));
		if(currentPlayer)
		{
			nextPlayer = 0;
		}
		else
		{
			nextPlayer = 1;
		}
		G.handCount[nextPlayer] = (rand() % (10 - 0 + 1));
		
		preActions = G.numActions;
		preCoins = G.coins;
		discardCount = G.discardCount[currentPlayer];
		discardCount2 = G.discardCount[nextPlayer];

		printf("Minion in hand at %d: choice1 = %d, choice2 = %d, next player's hand count = %d\n\n", j, choice1, choice2, G.handCount[nextPlayer]);

		minionCard(choice1, choice2, &G, j, currentPlayer); // test the function

		if (G.numActions == preActions + 1) // verify +1 added to number of actions
		{
			printf("+1 Action = PASS\n");
		}
		else
		{
			printf("+1 Action = FAIL\n");
		}

		printf("Should pass if choice1\n");

		if (G.coins == preCoins + 2) // verify +2 coins added to buying power
		{
			printf("+2 coins = PASS\n");
		}
		else
		{
			printf("+2 coins = FAIL\n");
		}

		printf("\nTesting choice2\n");

		if (G.discardCount[currentPlayer] == discardCount + hand) // verify hand is discarded
		{
			printf("Hand discarded = PASS\n");
		}
		else
		{
			printf("Hand discarded = FAIL\n");
		}
		
		if (G.handCount[currentPlayer] == 4) // verify 4 cards in hand
		{
			printf("Current Player Hand count is 4 = PASS\n");
		}
		else
		{
			printf("Current Player Hand count is 4 = FAIL\n");
		}

		if (G.handCount[nextPlayer] == 4) // verify player 2 has 4 cards in hand
		{
			printf("Next Player Hand count 4 = PASS\n");
		}
		else
		{
			printf("Next Player Hand count 4 = FAIL\n");
		}

		if (G.discardCount[nextPlayer] == discardCount2 + hand) // verify player 2 discarded 5 cards
		{
			printf("Next Player Hand discarded = PASS\n");
		}
		else
		{
			printf("Next Player Hand discarded = FAIL\n");
		}

		if (G.discardCount[nextPlayer] == discardCount2) // verify player 2 didn't discard
		{
			printf("Next Player No discard = PASS\n");
		}
		else
		{
			printf("Next Player No discard = FAIL\n");
		}

		printf("\n");
	}


	return 0;
}