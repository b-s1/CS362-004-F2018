#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


//isGameOver() test

int main () 
{
	//init and declare some useful vars
	int r, i, n, failure;
	int randoms = 1000;
	int ppl = 2;
	
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	//same from unittest1.c file
    printf ("\ntest isGameOver()  \n\n");
	//reset game
    memset(&G, 23, sizeof(struct gameState)); 
	//start new game
    r = initializeGame(ppl, k, randoms, &G);  
	
	printf("game ends when provine is zero, starting with %d\n", G.supplyCount[province]);
	for(i=G.supplyCount[province]; i >= 0; i--)
	{
		G.supplyCount[province] = i;
		n = isGameOver(&G);
		if (n == 0)
		{
			printf(1/1, counter at %d\n", G.supplyCount[province]);			
		}
		else if (i == 0 && n == 1)
		{
			printf("1/1, counter at %d\n", G.supplyCount[province]);
		}
		else if (i == 0 && n == 0)
		{
			printf("0/1, counter at %d \n", G.supplyCount[province]);
			failure++;
		}
		else 
		{
			printf("0/1, counter at %d \n", G.supplyCount[province]);
			failure++;
		}
	}
	if(failure > 0)
	{
		printf("not perfect\n");
	}
	else
	{
		printf("perfect\n");
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	