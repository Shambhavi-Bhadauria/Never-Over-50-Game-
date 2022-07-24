#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

/*Menu */
void menu(void) {
	int option = 0;
	puts("\n");
	puts("  --------------------------------");
	puts(" |       NEVER OVER 50 GAME       |");
	puts("  --------------------------------");

	puts("\n 1.   Game Rules");                          /* Choice 1: Game Rules */
	puts(" 2.   Edit Player Details");                  /* Choice 2: Game Details */
	puts(" 3.   Play");                                /* Game Play */
	puts(" 4.   Exit");                               /* Exit the Game*/

	printf("\n Please pick an option: "); /*Asks user to pick a choice*/
}
void game_rules() {                  /*Explains the game rules*/
	int game_option  = 0;
	
		printf("  ----------------------- ");
		printf("\n |       GAME RULES      |");
		printf("\n  ----------------------- ");
		/*The rules*/
		puts("\n This game aims to add up a random number in the range of 1 to 20 each turn to get a final number in the range of 40 to 50.");
		puts("\n If the players score is less than 50 after each turn,they can choose to continue.");
		puts("\n If they choose to continue, the number of turns will increase by 1.");
		puts("\n The players turn will automatically stop if the final score exceeds 50 or the player has lost the game with 0 points.");
		puts("\n If the players final score is in the range of 40 to 50, then the final point is equal to the final score substracting the");
		puts(" number of turns the user took to get the final score.");

		printf("\n\n Press 0 to go back to the main menu: ");  /*Gives the user the option to go back to the main menu*/
		scanf("%d", &game_option);
	while (game_option != 2) 
	{

		if (game_option == 0) {   /*if they press 0 then they can go back to the main menu*/
			break;
		}
		else {
			printf("\n Wrong option, press 0 to go back to the main menu: ");
			scanf("%d", &game_option);
		}
	}
}

void player_details() { /*Play details*/
	char player_name[50];
	int player_option = 0;
	
		printf("  ---------------------------- ");
		printf(" \n |       PLAYER DETAILS       |");
		printf("\n  ---------------------------- ");

		printf("\n Player name: Player");

		printf("\n\n Press 1 to edit or press 0 to go back to main menu: "); /* press 1 to edit details*/
		scanf("%d", &player_option);

	while (player_option != 2) 
	{
		if (player_option == 1) {
            printf("\n Please enter new details: "); /* User enters the their details*/
			scanf(" %s",&player_name);

			printf("\n Player details changed "); /*Detail changed*/
			printf("\n Player name: ");
			printf("%s", player_name);  /*Changed Detail printed */
			
			printf("\n\n Press 1 to edit or press 0 to go back to main menu: ");
			scanf("%d", &player_option);  /*press 1 to redit the the detail or 0 to go back to the main menu*/
		
		}
	    else if (player_option == 0) {
			break;
		}
		else {
			printf("\n Wrong option, press 1 to edit or press 0 to go back to the main menu: "); /* warning which lets user reenter again the correct option*/
			scanf("%d", &player_option);


    	}
	}
}

void play()
{

	printf("\n  ------------------");
	printf("\n |        PLAY      | ");
	printf("\n  ------------------");

	int number = 0, score = number;
	int turn = 1,play_option;
	char decision;
	int range1 = 1, ranger2 = 20;

	srand(time(NULL));
	number = (rand() % (ranger2 - range1 + 1)) + range1;
	
	printf("\n  Turn % d, ", turn++);
	printf("random number is %d ", number);
	printf("and your score is % d", score += number);
	printf("\n  press 'y' to continue or 's' to stop: ");
	scanf(" %s", &decision);
	
	while (decision != 2)
	{
		if (decision == 'y') {

				srand(time(NULL));
				number = (rand() % (ranger2 - range1 + 1)) + range1;
				printf("  Turn % d, ", turn++);
				printf("random number is %d ", number);
				printf("and your score is % d", (score += number));
				printf("\n  press 'y' to continue or 's' to stop: ");
				scanf(" %c", &decision);
			if (score > 49) 
			{
				printf("\n  You have lost the game, 0 is your final point");

				printf("\n\n Press 1 to play the game again or press 0 to go back to main menu: ");

				scanf("%d", &play_option);
				while (play_option != 3)
				{
					if (play_option == 0) {
						
						menu();
					}
					else if (play_option == 1)
					{
						play();
					}
					else {
						printf("\n Wrong option, press 1 to play the game again or press 0 to go back to the main menu: ");
						scanf("%d", &play_option);

					}
				}
					
			}

		}
		else if (decision == 's')
		{
			if (score <40)
			{
				printf("\n  You have lost the game, 0 is your final point");
			}
			else if(41 <score) {
				printf("\n  You have won the game, %d is your final point", score - turn);
			}
			else if (score > 50)
			{
				printf("\n  You have won the game, %d is your final point", score - turn);

			}
			printf("\n\n Press 1 to play the game again or press 0 to go back to main menu: ");
			scanf("%d", &play_option);
			while (play_option != 2)
			{
				if (play_option == 0) {

					menu();

				}
				else if (play_option == 1)
				{
					play();
				}
				else {
					printf("\n Wrong option, press 1 to play the game again or press 0 to go back to the main menu: ");
					scanf("%d", &play_option);

				}

			}
		}
	}	
	
}

		
	

	
int main() {
	int option = 0;
	while (option != 4) {
		menu();
		scanf("%d", &option);

		switch (option) {
		case 1:
			game_rules(); /* press 1 to read the game rules */
			break;
		case 2:
			player_details(); /* Press 2 to edit the player details*/
			break;
		case 3: /* Press 3 to play the game*/
			play();
			break;
		case 4: /* press 4 to exit */
			break;
		default:
			puts("\n Your choosen option isn't listed, please try again:"); /*Tells the user about incorrect input*/
			break;
		} // END_SWITCH
	} // END_WHILE
	return 0;
}
