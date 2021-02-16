#include "cashregister.h"

int currentBalance(int balance, int totalCost, int selected, int quantity) {
	int nb, confirm;
	//
	printf("Deposit %i\n", totalCost - balance);
	scanf("%i", &nb);
	balance = balance + nb;
	//
	printf("-------------------\n");
	printf("Confirm deposit?\n\n");
	printf("[1] yes\n");
	printf("[2] no\n");
	printf("-------------------\n");
	//
	scanf("%i", &confirm);
	confirmation(confirm, balance, totalCost, selected, quantity);
}

int confirmation(int confirm, int balance, int totalCost, int selected, int quantity) {
	if(confirm == 1) {
		return change(balance, totalCost, selected, quantity);
	} else {
		return currentBalance(0, totalCost, selected, quantity);
	}
}

int change(int balance, int totalCost, int selected, int quantity) {
	int change, added;
	//
	if(balance == totalCost) {
		acceptMoney(selected, quantity);
	} else if(balance < totalCost) {
		printf("You have inputted less than your total cost. Please deposit more: \n");
		currentBalance(balance, totalCost, selected, quantity);
	} else if(balance > totalCost) {
		change = balance - totalCost;
		printf("Your change is: %i", change);
		acceptMoney(selected, quantity);
	}
	//
	return 0;
}

int acceptMoney(int selected, int quantity) {
	calculateQuantity(selected, quantity);
	printf("\nCollect your items at the bottom");
}
