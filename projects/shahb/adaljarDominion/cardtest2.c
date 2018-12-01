#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Adventurer Card 

int main () 
{
	//init and declare some useful vars
    int ppl = 2;
	int x, failures;
	int nums = 500;
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};
	//start game
    initializeGame(ppl, k, nums, &G); 
	//set fail count to zero
	failures = 0;
	printf ("\ntesting begins for adventurer \n\n");    
	
	// add curse cards	
    for(x = 0; x < 5; x++) 
	{
        G.hand[1][x] = curse;
        G.handCount[1]++;
    }
    //printf("FIRST TEST: Expected Cards %d, got cards %d\n", 5, G.handCount[1]);
    adventurerFunction(1, &G);
	if(7 == G.handCount[1])
	{
		printf("1/1 so far. Needed %d, got %d\n\n",7, G.handCount[1]);
	}
	else
	{
		printf("0/1. Needed %d, got %d\n\n",7, G.handCount[1]);
		failures++;
	}
	
	//clear hand count
	G.handCount[1] = 0;	
	// refill curse
	for(x = 0; x < 6; x++) 
	{
        G.hand[1][x] = curse;
        G.handCount[1]++;
    }
	//second test
	adventurerFunction(1, &G);
	if(8 == G.handCount[1])
	{
		printf("Passed final test. Needed %d, got  %d\n\n",8, G.handCount[1]);
	}
	else
	{
		printf("Failed. Needed %d, got %d\n\n",8, G.handCount[1]);
		failures++;
	}
	if(failures > 0)
	{
		printf("Not successful\n");
	}
	else
	{
		printf("100%\n");
	}	
	printf("\nThanks \n\n");
    return 0;
}









































