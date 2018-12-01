//non faulty adventurer tester
#include "dominion.h"
#include <assert.h>
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//number of simulation iterations
#define gameplayCycles 50
#define quantity treasure_map

int main(){

	//gameplay vars 
	struct gameState G;
	//init randomizer for number generator for simulation cycles
	srand(time(NULL));   
	int k[10] = {steward, baron, duchy,
        minion, copper, estate,
		treasure_map, province, curse, smithy};
	//gameplay and simulation vars
	int before, after, prizes, currentUser,
	mainsimulationcounter, gameplaycounter, 
	totalgameusers, currentuser, numgenerator, currentuserholdings;

		
	//iterations for multiple rounds of gameplay
	for(mainsimulationcounter = 0; mainsimulationcounter < gameplayCycles; mainsimulationcounter++)
	{ 
		//init card tracker
		before = 0; after = 0;
		//get anywhere from 2 to 6 users for each simulation cycle
		totalgameusers = rand() % 5+2;
		numgenerator = rand() % 100;	
		// generate a random current user in this simulation cycle to test
		currentuser = rand() % totalgameusers;
		//init the user's hand
		G.discardCount[currentUser] = 0;
		//available actions
		G.numActions = 1;
		//number of cards
		G.handCount[currentUser] = 5;
		//set turn to selected user
		G.whoseTurn = currentUser;
		//randomize deck count
		G.deckCount[currentUser] = rand() % MAX_HAND;

		//create simulation cycle user hand
		for(gameplaycounter = 0; gameplaycounter < G.handCount[currentuser]; gameplaycounter++)
		{
			//from possible cards available in dominion	
			G.hand[currentuser][gameplaycounter] = rand() % quantity;

			if(G.hand[currentuser][gameplaycounter] <= gold && G.hand[currentuser][gameplaycounter] >= copper )
			{ 
				before++;	
			}
		}
		//create simulation cycle dominion deck
		for(gameplaycounter = 0; gameplaycounter < G.deckCount[currentuser]; gameplaycounter++)
		{
			//from possible cards available in dominion
			G.deck[currentuser][gameplaycounter] = rand() % quantity;

			if(G.deck[currentuser][gameplaycounter] <= gold && G.deck[currentuser][gameplaycounter] >= copper)
			{ 
				prizes++;
			}
		}
		//give target card to user
		G.hand[currentuser][0] = adventurer; 
		//play the card
		playCard(0, 0, 0, 0, &G); 
		currentuserholdings = G.handCount[currentuser];
		for (gameplaycounter = 0; gameplaycounter < G.handCount[currentuser]; gameplaycounter++) {
		  if (G.hand[currentuser][gameplaycounter] <= gold && G.hand[currentuser][gameplaycounter] >= copper) 
			  printf("error with card count!\n");

			after++;}
	}	
	return 0;
}