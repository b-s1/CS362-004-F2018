//Random Smithy Card Test
#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>
//max tests for max coverage
#define NUM_OF_TESTS 50000

void testPlayCardFunction()
{
	//vars to init new game
	int seed = 1000;
	int i, j;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int handcount;
	int cardspot, pretally, posttally;
	int numPlayer = 2;
	int success = 0;
	int errors = 0;
	int printIt = 0;	
	srand(time(NULL));

	printf("\n %d trails smithy vs playcard\n", NUM_OF_TESTS);
	for (i = 0; i < NUM_OF_TESTS; i++)
	{
		//clr game. init new game
		memset(&G, 23, sizeof(struct gameState));  
		initializeGame(numPlayer, k, seed, &G);
		handcount = (rand() % 100) + 1;
		G.whoseTurn = rand() % 2;
		G.handCount[G.whoseTurn] = handcount;													
		for (j = 0; j < handcount; j++)
		{
			G.hand[G.whoseTurn][j] = floor(rand() % 17 + 1);
		}
		cardspot = rand() % handcount;		
		G.hand[G.whoseTurn][cardspot] = smithy;			
		pretally = handcount;				
		playCard(cardspot, -1, -1, -1, &G);
		posttally = G.handCount[G.whoseTurn];		
		if (posttally != pretally + 2)
		{
			if (printIt == 1)
			{
				printf("Test_%i Unsuccessful. card sum unequal. %d == %d\n", i, posttally, pretally);
			}
			errors++;
		}
		else
		{
			if (printIt == 1)
			{
				printf("Test_%i success. card sum equal. %d == %d\n", i, posttally, pretally);
			}
			success++;
		}
	}
	printf("pass: %d\n", success);
	printf("fail: %d\n\n\n", errors);
}


int main()
{
	printf("\n\nSmithy random\n");
	//testSmithyFunction();
	//init gameplay
	srand(time(NULL));
	int i, j;
	int seed = 1000;
	//set game play for cards
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	//init hand
	int handcount;
	int cardspot, pretally, posttally;
	int numPlayer = 2;
	int pass = 0;
	int fails = 0;
	int printIt = 0;

	printf("Testing %d runs of smithy\n", NUM_OF_TESTS);
	for (i = 0; i < NUM_OF_TESTS; i++)
	{
		//clr game
		memset(&G, 23, sizeof(struct gameState));
		//init game
		initializeGame(numPlayer, k, seed, &G);
		handcount = (rand() % 100) + 1;
		G.whoseTurn = rand() % 2;
		//set num cards in hand
		G.handCount[G.whoseTurn] = handcount;

		//place rand cards in hand				
		for (j = 0; j < handcount; j++)
		{
			G.hand[G.whoseTurn][j] = floor(rand() % 17 + 1);
		}
		//find rand card pos nun
		cardspot = rand() % handcount;
		//put smithy in rand spot in user hand
		G.hand[G.whoseTurn][cardspot] = smithy;
		//save num cards before fx called
		pretally = handcount;
		//call smithy fx
		playSmithyCard(&G, G.whoseTurn, cardspot);
		//count num cards after smithy called
		posttally = G.handCount[G.whoseTurn];

		if (posttally != pretally + 2)
		{
			if (printIt == 1)
			{
				printf("Test_%i Unsuccessful.card sum !=.  %d == %d\n", i, posttally, pretally);
			}
			fails++;
		}
		else
		{
			if (printIt == 1)
			{
				printf("Test_%i Success. card sums equal. %d == %d\n", i, posttally, pretally);
			}
			pass++;
		}
	}
	printf("Pass: %d\n", pass);
	printf("Fail: %d\n", fails);
	testPlayCardFunction();
	return 0;
}