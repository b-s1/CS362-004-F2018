#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Village test

int main () 
{
	//init and declare some useful vars for testing
	int ppl = 2;
	int randoms = 1000;
	int failures = 0;
	int ii, r, HC, AC, HP, x;
	int k[10] = {adventurer, council_room, feast, gardens, mine
				, remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int genericHand[MAX_HAND];

	printf ("\nVillage\n");
	for (x = 0; x < MAX_HAND; x++)
	{
		genericHand[0] = gold; 
		genericHand[1] = curse;
		genericHand[2] = adventurer;
		genericHand[3] = smithy;
		genericHand[4] = village;
	}
	//set action level
	AC = 6;
	//village spot
	HP = 4; 		
	//set num cards
	HC = 3;	
	for (ii = 0; ii < ppl; ii++)
	{
		printf("check %d for p %d.\n", ii+1, ii+1); 
		//reset game
		memset(&G, 23, sizeof(struct gameState));  
		//new game
		r = initializeGame(ppl, k, randoms, &G); 
		//set num cards
		G.handCount[ii] = HC;
		//set action level
		G.numActions = AC * (ii+1);	
		//set default generic hand
		memcpy(G.hand[ii], genericHand, sizeof(int) * HC); 		
		villageFunction(ii, &G,  HP);
		
		if(G.numActions == AC * (ii+1) + 2) 
		{
			printf("1/1: Correct action count %d.\n\n", G.numActions );
		}
		else
		{
			printf("0/1, you have action count %d, but needed %d\n",G.numActions, AC * (ii+1) + 2);
			failures++;	
		}
	}
	if(failures > 0)
	{
		printf("You messed up\n");
	}
	else
	{
		printf("Good job\n");
	}	
	printf("\nThanks\n");
	return 0;
}