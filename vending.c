#include "vending.h"
#include "dispenser.h"

//------------

int main() {
	int selection;
		
	selection = showSelection();
	
	//Check if selection is within bounds of valid integer inputs (from 1 to 5)
	if(selection <= 5) {
		selected(selection);
	} else {
		printf("Invalid selection. Try again:\n");
		return showSelection();
	}
	
	return 0;
}

int showSelection() {
	int selection;
	//Line break
	printf("-------------------\n");
	//Prompt and selection list
	printf("What would you like to buy?");
	printf("\n\n");
	printf("[1] Candies\t\tPhp 10\n");
	printf("[2] Chips\t\tPhp 15\n");
	printf("[3] Cookies\t\tPhp 15\n");
	printf("[4] Soda\t\tPhp 25\n");
	printf("[5] Quit");
	printf("\n\n");
	//Prompt to enter selection
	printf("Please enter your selection:\n");
	scanf("%i", &selection);
	//returns selection
	return selection;
}

int selected(int selection) {
	int quantity;
	//Cases of what was chosen and the proper prompts
	switch(selection) {
		//Chosen candies
		case 1 : printf("How many candies do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen chips
		case 2 : printf("How many chips do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen cookies
		case 3 : printf("How many cookies do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen soda
		case 4 : printf("How many sodas do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen quit
		case 5 : printf("\nSee you again next time!");
					return 0;
					break;
	}
}

int sellProduct(int selected, int quantity) {
	getCount(selected, quantity);
	//returns 0 to exit
	return 0;
}
