#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


// Testing the supplyCount() function

int main () 
{
	//init and declare some useful vars
	int numPlayer = 2;
	int gameplay, x, holderVar, failure;
	int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	//from files unittest1,2,3.c
    printf ("\nsupplyCount() \holderVar\holderVar");
	//reset game
    memset(&G, 23, sizeof(struct gameState));
	//new game
    gameplay = initializeGame(numPlayer, k, seed, &G);
	//test
	printf("see if supplycount returns right init val");
    for(x = 0; x < 27; x++) 
	{
		holderVar = supplyCount(x, &G); 
    	if(holderVar == G.supplyCount[x]) 
		{
    		printf("1/1 card[%d] == %d \holderVar", x, G.supplyCount[x]);
    	}
    	else
		{
    		printf("0/1 card[%d] == %d \holderVar", x, G.supplyCount[x]);
    		failure++;
    	}
    }
	if(failure > 0)
	{
		printf("failure\holderVar");
	}
	else
	{
		printf("success\holderVar");
	}	
	return 0;
	
}
































