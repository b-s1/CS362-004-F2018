//village

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_TESTS 10
#define CARD_TESTS 10

int main(int argc, char *argv[]) {
	//init gameplay vars
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};
	int i, j, n, totalPs, pCurr, HC, DC, seed, CarAdd;
	int loopCntr;
	struct gameState state;
	if (argc != 2)
	{
		printf("input seed\n");
		scanf("%d", &seed);
	}
	else{
		seed = atoi(argv[1]);
	}
	srand(seed);
	for (i = 0; i < MAX_TESTS; i++) {
		totalPs = rand() % 4;
		seed = rand();
		//init game
		initializeGame(totalPs, k, seed, &state);	
		for (pCurr = 0; pCurr < totalPs; pCurr++)
		{
			state.deckCount[pCurr]    = rand() % MAX_DECK; 
			state.discardCount[pCurr] = rand() % MAX_DECK;
			state.handCount[pCurr]    = rand() % MAX_HAND;
			//get init vars to local vars
			HC = state.handCount[pCurr];
			DC = state.deckCount[pCurr];
			// insert rand cards to hand by HC value
			for (j = 0; j < HC; j++)
			{
				//insert rand card value zero to 27 to hand
				state.hand[pCurr][j] = rand() % 28; 
			}
			if (seed % 3 == 0) {
				state.deckCount[pCurr] = 0;
			}
			int card_tests = rand() % CARD_TESTS;
			for (loopCntr = 0; loopCntr < card_tests; loopCntr++)
			{
				switch (rand() % 2)
				{
					case 0:
						{

							printf("random village\n");
							int prev_actions = state.numActions;
							//use village card
							cardEffect(village, 1, 1, 1, &state, 0, 0);		
							//expect same hand bc discard village and draw card
							if (state.handCount[pCurr] != HC)
							{
								fprintf(stdout, "HC different. now %s vs init val %d now %d\n",
										state.handCount[pCurr] > HC ? "greater" : "less",
										HC, state.handCount[pCurr]);
							}
							if (state.hand[pCurr][0] != -1)
							{
								fprintf(stdout, "card wasn't removed from hand\n");
								printf("1st card: %d\n", state.hand[pCurr][0]);
							}
							//check game play card action
							if (state.numActions != prev_actions + 2)
							{
								printf(stdout, "expect: %d+2, but got %d\n", prev_actions, state.numActions);
							}
						}

					case 1:
						{
							//resume top card hand.
							cardEffect(state.hand[pCurr][0], 1, 1, 1, &state, 0, 0);
						}
				}
			}
		}

	}
	printf("done\n");
	return 0;
}