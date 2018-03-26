#include "carte.h"
#include "jeu.h"
#include "time.h"
/*#include "mise.h"*/
#include <stdio.h>


int egalite(int nbPlayer, player_t * joueur[])
{
	for (int i = 0; i < nbPlayer; ++i)
	{
		if (joueur[0]->jetons_mise != joueur[i]->jetons_mise)
			return 0;
	}
	return 1;
}


int changeCard(int player)
{
	//Pas a faire par toi pour l'instant
}

void guessWinner()
{
	//Pas a faire par toi pour l'instant
}

int follow(int player, int nbPlayer, player_t * joueur[])
{
	if(player == 0)
		return joueur[nbPlayer-1]->jetons_mise;
	return joueur[player-1]->jetons_mise;
}

int reflate(int player, int nbPlayer, player_t * joueur[])
{
	int jeton=0;
	int jeton_relance; 

	printf(" de combien souhaitez vous relancer\n");
	printf("Relance : ");
	scanf("%d", &jeton_relance);
	jeton = jeton_relance + follow(player, nbPlayer, joueur);
	printf("jeton:%d\n", jeton);
	return jeton;
}

int all_in(int player)
{
	

	printf("Pas encore implémenté\n");
	return 1;
}

int sleep(int player)
{
	printf("Pas encore implémenté\n");
	return 1;
}


int relance(int jeton_r, int jeton){

	return jeton +=jeton_r;	

}

int bet(int player, int nbPlayer, player_t * joueur[])
{
	int choice;
	int jeton = 0;
	printf("joueur: %d\n", player);
	
	for (int i = 0; i < nbPlayer; ++i)
	{
		printf("%i\n",joueur[i]->jetons_mise);
	}

	printf("Que souhaitez vous faire ?\n");
	printf("1 - Suivre\n");
	printf("2 - Relancer\n");
	printf("3 - Tapis\n");
	printf("4 - Coucher\n");
	printf("Votre choix : ");
	scanf("%i", &choice);

	switch(choice)
	{
		case 1: printf("Vous suivez de %i jetons\n", jeton); 
				
			return follow(player, nbPlayer, joueur); break;
		case 2: printf("Vous relancer de %i jeton\n", jeton); return reflate(player, nbPlayer, joueur); break;
		case 3: printf("Vous faites un tapis à %i jetons\n", jeton); return all_in(player); break;
		case 4: printf("Vous vous couchez\n"); return sleep(player); break;
		default : printf("Ce choix n'existe pas\n"); break;
	}
}

void turnOfBet(jeu_t * jeu, player_t * joueur[], int nbPlayer)
{

	int resultBet = 0;
	int pot = 0;
	
	int i;
	for(int cpt_turn = 0; cpt_turn < 3; cpt_turn++)
	{
	
		for (i = 0; i < nbPlayer; ++i)
		{
			
			joueur[i]->jetons_mise = 0;
		}

		do
		{
			for (i = 0; i < nbPlayer; ++i)
			{
				printf("Tour : %i\n", cpt_turn);
			
				/*Verif egalite des joueurs*/
				resultBet = bet(i, nbPlayer, joueur);
				pot += resultBet;
				joueur[i]->jetons_mise -= resultBet;
				joueur[i]->jetons_mise = resultBet;
			}
		}
		while(!egalite(nbPlayer, joueur));
		
		if (cpt_turn < 2)
		{
			for (i = 0; i < nbPlayer; ++i)
			{
				
				changeCard(i);
			}
		}
		
		

	}
	guessWinner();
}

