#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// SMITHY test

int main () 
{
	//declare and init some useful vars
	int nosuccess = 0;
	int q;
	int seeder = 1000;
	int q2, r, handCount;
	int ppl = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine
				, remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int genericHand[MAX_HAND];
	printf ("\nSmithy test \n\n");
	for (q = 0; q < MAX_HAND; q++)
	{
		genericHand[0] = gold; 
		genericHand[1] = curse;
		genericHand[2] = adventurer;
		genericHand[3] = village;
		genericHand[4] = smithy;
	}
	//save smithy hand
	int currentSpot = 4;  
	handCount = 5;

	for (q2 = 0; q2 < ppl; q2++)
	{
		printf("TEST %d Players %d.\n", q2+1, q2+1);  
		//reset game
		memset(&G, 23, sizeof(struct gameState));   
		//start game again
		r = initializeGame(ppl, k, seeder, &G);
		//set card count
		G.handCount[q2] = handCount;                 
		//the default hand setting
		memcpy(G.hand[q2], genericHand, sizeof(int) * handCount); 
		simthyFunction(q2, &G,  currentSpot);
		//pass test with right num cards
		if(G.handCount[q2] == handCount + 2) 
		{
			printf("Successful test. Have %d number of cards.\n\n", handCount + 2 );
		}
		else
		{
			printf("Unsuccessful test. Have hand  %d cards, not  %d cards.\n\n",G.handCount[q2], handCount + 2  );
			nosuccess++;	
		}
	}
	if(nosuccess > 0)
	{
		printf("Not 100% success\n");
	}
	else
	{
		printf("100% success\n");
	}	
	printf("\nThanks \n\n");
	return 0;

}

























