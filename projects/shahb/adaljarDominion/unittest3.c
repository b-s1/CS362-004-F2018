#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


// getCost() test

int main () 
{
	//init and declare some useful vars
	int seed = 1000;
	int failure, gameplay, x, n;
	int ppl = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	//from unittest1 and 2.c
    printf ("\ngetCost()\n");
	//rest game
    memset(&G, 23, sizeof(struct gameState)); 
	//new game
    gameplay = initializeGame(ppl, k, seed, &G); 
    const char *nameOfCards[28] = {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
	int costOfCards[28] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
	
	for (x=0; x<27; x++)
	{
		n = getCost(x);
		if(n == costOfCards[x])
		{
			printf("Test: ** PASSED ** Card %s == Cost %d\n", nameOfCards[x], costOfCards[x]);
		}
		else
		{
			printf("Test: ** FAILED ** Card %s != Cost %d\n", nameOfCards[x], costOfCards[x]);
			failure++;
		}
	}
	if(failure > 0)
	{
		printf("bad\n");
	}
	else
	{
		printf("perfect\n");
	}	
	return 0;
}