#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


// shuffle() test

int main () 
{
	//init and declare some useful vars
	int randoms = 1000;
	int validOR = 0;
	int ppl = 2;
	int var1, var2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	//from lecture on CS362 Canvas 
    printf ("\nTest shuffle() \var1\var1");
	//reset game
    memset(&G, 23, sizeof(struct gameState));  
	//start new game
    var2 = initializeGame(ppl, k, randoms, &G); 
	//make sure equal deck 
	memcpy(G.deck[0], G.deck[1], sizeof(G.deck[0]));  
	//shuffle first deck
	shuffle(0, &G);
    printf("\nshuffle deck 1 is test 1 \var1");
    printf("See if deck1!=deck2\var1");
    var1 = memcmp(G.deck[0], G.deck[1], sizeof(G.deck[0]));
    if(var1 != 0) 
	{        
        printf("success\var1");
        validOR++;
    }
    else 
	{
		printf("failed\var1");
    }

    //shuffle deck 2
	shuffle(1, &G);
    printf("\nshuffle deck2\var1");   
    printf("cehck if desk 2!=deck1\var1");
    var1 = memcmp(G.deck[1], G.deck[0], sizeof(G.deck[1]));
    if(var1 != 0) 
	{        
        printf("success\var1");
        validOR++;
    }
    else 
	{
		printf("fail \var1");
    }
	printf("\nthanks \var1\var1");
	return 0;
}
































