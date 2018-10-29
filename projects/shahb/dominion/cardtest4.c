#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Council Room test

int main()
{
	//init and declare some useful vars
	int ppl = 4;
	int randos = 1000;
	int  j, r, handCount, handPos;
	int failures = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	//same reset, start, and set up game play for 4 users
	memset(&G, 23, sizeof(struct gameState));  
	r = initializeGame(ppl, k, randos, &G); 
	//council card spot
	handPos = 4;
	//set num cards
	handCount = 3;		
	G.deckCount[1] = 100;
	G.deckCount[2] = 100;
	G.deckCount[3] = 100;
	G.handCount[1] = 5;
	G.handCount[2] = 5;
	G.handCount[3] = 5;
	int player1 = 1;
	int player2 = 2;
	int player3 = 3;
	int player4 = 4;
	int council_room_hand_location = 4;
	int player1OrgHandCount = 0;
	int player2OrgHandCount = 0;
	int player3OrgHandCount = 0;
	int player4OrgHandCount = 0;

	//card count	
	printf("\ncouncil room test\n\n");


	for (j = 0; j < ppl; j++)
	{

		printf("\nuser %d with council room  \n\n", j + 1);
		player1OrgHandCount = G.handCount[player1 - 1];
		player2OrgHandCount = G.handCount[player2 - 1];
		player3OrgHandCount = G.handCount[player3 - 1];
		player4OrgHandCount = G.handCount[player4 - 1];

		council_roomFunction(j, &G, council_room_hand_location);
		if ((j == player1 - 1 && player1OrgHandCount == G.handCount[player1 - 1] - 3) || (j == player1 - 1 && player1OrgHandCount == G.handCount[player1 - 1] - 1) || (player1OrgHandCount == G.handCount[player1 - 1] - 3) || (player1OrgHandCount == G.handCount[player1 - 1] - 1))
		{
			printf("test %d 1/1 user %d has %d , needs %d \n", j + 1, player1, G.handCount[0], G.handCount[0]);

		}
		else
		{
			if (j == 0)
			{
				printf("test %d 0/1 user %d has %d , needs %d \n", j + 1, player1, G.handCount[0], G.handCount[0] + 3);
				failures++;
			}
			else
			{
				printf("test %d 0/1 user %d has %d , needs %d \n", j + 1, player1, G.handCount[0], G.handCount[0] + 1);
				failures++;
			}
		}
		if ((j == player2 - 1 && player2OrgHandCount == G.handCount[player2 - 1] - 3) || (j == player2 - 1 && player2OrgHandCount == G.handCount[player2 - 1] - 1) || (player2OrgHandCount == G.handCount[player2 - 1] - 3) || (player2OrgHandCount == G.handCount[player2 - 1] - 1))
		{
			printf("test %d 1/1 user %d has %d , needs %d\n", j + 1, player1, G.handCount[1], G.handCount[1]);

		}
		else
		{
			if (j == 0)
			{
				printf("test %d 0/1 user %d  has %d , needs %d\n", j + 1, player2, G.handCount[1], G.handCount[1] + 3);
				failures++;
			}
			else
			{
				printf("test %d 0/1 user %d  has %d , needs %d\n", j + 1, player2, G.handCount[1], G.handCount[1] + 1);
				failures++;
			}
		}
		if ((j == player3 - 1 && player3OrgHandCount == G.handCount[player3 - 1] - 3) || (j == player3 - 1 && player3OrgHandCount == G.handCount[player3 - 1] - 1) || (player3OrgHandCount == G.handCount[player3 - 1] - 3) || (player3OrgHandCount == G.handCount[player3 - 1] - 1))
		{
			printf("test %d 1/1 user %d has %d , needs %d \n", j + 1, player1, G.handCount[2], G.handCount[2]);
		}
		else
		{
			if (j == 0)
			{
				printf("Ttest %d 0/1 user %d  has %d , needs %d\n", j + 1, player2, G.handCount[2], G.handCount[2] + 3);
				failures++;
			}
			else
			{
				printf("test %d 0/1 user %d  has %d , needs %d\n", j + 1, player2, G.handCount[2], G.handCount[2] + 1);
				failures++;
			}
		}
		if ((j == player4 - 1 && player4OrgHandCount == G.handCount[player4 - 1] - 3) || (j == player4 - 1 && player4OrgHandCount == G.handCount[player4 - 1] - 1) || (player4OrgHandCount == G.handCount[player4 - 1] - 3) || (player4OrgHandCount == G.handCount[player4 - 1] - 1))
		{
			printf("test %d 1/1 user %d has %d , needs %d \n", j + 1, player1, G.handCount[3], G.handCount[3]);
		}
		else
		{
			if (j == 0)
			{
				printf("test %d 0/1 user %d  has %d , needs %d\n", j + 1, player2, G.handCount[3], G.handCount[3] + 3);
				failures++;
			}
			else
			{
				printf("test %d 0/1 user %d  has %d , needs %d\n", j + 1, player2, G.handCount[3], G.handCount[3] + 1);
				failures++;
			}
		}
		//rest game for next user turn with council card
		memset(&G, 23, sizeof(struct gameState));  
		r = initializeGame(ppl, k, randos, &G); 
		handPos = 4; 		
		handCount = 3;	
		G.deckCount[1] = 100;
		G.deckCount[2] = 100;
		G.deckCount[3] = 100;
		G.handCount[1] = 5;
		G.handCount[2] = 5;
		G.handCount[3] = 5;
		player1 = 1;
		player2 = 2;
		player3 = 3;
		player4 = 4;
		council_room_hand_location = 4;
	}
	if (failures > 0)
	{
		printf("\nunsuccessful\n");
	}
	else
	{
		printf("perfect\n");
	}
	printf("thanks\n");
	return 0;
}