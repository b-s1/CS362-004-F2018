//random adventurer test

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_TESTS 100
#define CARD_TESTS 10

int main() {
	//init gameplay vars
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};
	int i, j, n, players, player, hc, dc, seed, adrs;
	int loopCnter;
	struct gameState state;
	printf("ran avdenturer\n");

	for (i = 0; i < MAX_TESTS; i++) {
		players = rand() % 4;
		seed = rand();
		//init game
		initializeGame(players, k, seed, &state);
		for (player = 0; player < players; player++)
		{
			state.deckCount[player]    = rand() % MAX_DECK;
			state.discardCount[player] = rand() % MAX_DECK;
			state.handCount[player]    = rand() % MAX_HAND;
			//get gameplay info 
			hc = state.handCount[player];
			dc = state.deckCount[player];
			// insert rand cards to hand via card val
			for (j = 0; j < hc; j++)
			{
				//rand card val zero to 27 to hand
				state.hand[player][j] = rand() % 28; 
			}
			//tally treasure cards.
			if (seed % 3 == 0) {
				state.deckCount[player] = 0;
			}
			//run rand num cards from user hand
			int card_tests = rand() % CARD_TESTS;
			for (loopCnter = 0; loopCnter < card_tests; loopCnter++)
			{
				//run top card or adventurer 50/50
				switch (rand() % 2)
				{
					case 0:
						{
							int count = 0;
							for (j = 0; j < dc; j++)
							{
								int card = state.deck[player][j];
								if (card == copper || card == silver || card == gold)
									++count;
							}
							int hand_count = 0;
							for (j = 0; j < hc; j++)
							{
								int card = state.hand[player][j];
								if (card == copper || card == silver || card == gold)
									++hand_count;
							}
							//run advent
							cardEffect(adventurer, 1, 1, 1, &state, 0, 0);
							//tally treasure in deck post call
							int postcallCnt = 0;
							for (j = 0; j < state.deckCount[player]; j++)
							{
								int card = state.deck[player][j];
								if (card == copper || card == silver || card == gold)
									++postcallCnt;
							}
							//tally treasure in hand post call
							int hcDeck = 0;
							for (j = 0; j < state.handCount[player]; j++)
							{
								int card = state.hand[player][j];
								if (card == copper || card == silver || card == gold)
									++hcDeck;
							}
							//tally treasure count in deck. max 2 out. see if they inserted to hand
							if (count >= 2)
							{
								if(postcallCnt != count-2){ fprintf(stdout, "fail. postcallCnt: %d-2 not %d\n", count, postcallCnt);}
								if(hcDeck != hand_count+2){ fprintf(stdout, "fail hcDeck:  %d+2 not %d\n", hand_count, hcDeck);}
							}
							else if (count == 1)
							{
								if (postcallCnt != 0){ fprintf(stdout, "fail postcallCnt: %d-1 not %d\n", count, postcallCnt);}
								if(hcDeck != hand_count+1){ fprintf(stdout, "fail hcDeck: %d+1 not %d\n", hand_count, hcDeck);}
							}

							else if (count == 0)
							{
								if (postcallCnt != 0){ fprintf(stdout, "fail postcallCnt: 0 not %d\n", count, postcallCnt);}
								if(hcDeck != hand_count){ fprintf(stdout, "fail hcDeck: %d not %d\n", hand_count, hcDeck);}
							}
						}
					case 1:
						{
							// play top hand card.
							cardEffect(state.hand[player][0], 1, 1, 1, &state, 0, 0);
						}
				}
			}
		}

	}
	printf("done\n");
	return 0;
}