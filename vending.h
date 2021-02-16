#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int showSelection ();
int selected(int selection);
int sellProduct (int selected, int quantity);

struct inventoryInDispenser {
	char nameOfItem[250];
	int numberOfItems;
	int cost;
};
