#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int currentBalance(int balance, int totalCost, int selected, int quantity);
int confirmation(int confirm, int balance, int totalCost, int selected, int quantity);
int change(int balance, int totalCost, int selected, int quantity);
int acceptMoney(int selected, int quantity);
