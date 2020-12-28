#pragma once
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define CockePrice 5

typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* head;
} Stack;

void vendingMachine();

void addCoin(int   coin,
	int* current_coins,
	Stack* last_coins);

int popLastCoin(Stack* last_coins,
	int* current_coins);

void print_stack(Stack* last_coins);