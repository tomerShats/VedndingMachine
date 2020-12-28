#include "Header.h"

void vendingMachine()
{
	int current_coins = 0;
	int coin;
	Stack lastCoins;
	memset(&lastCoins, 0, sizeof(Stack));
	while (TRUE)
	{
		printf("Please Enter Number of coin 1,2,5 or -1 to pop the last coin\n");
		fflush(NULL);
		scanf("%d", &coin);
		if (coin != 1 && coin != 2 && coin != 5 && coin != -1) { //chek if your input is correct
			printf("Your number is wrong ");
			continue;
		}
		if (coin == -1) {
			popLastCoin(&lastCoins, &current_coins); //pop the last coin function
		}
		else {
			addCoin(coin, &current_coins, &lastCoins);//add your coin function
		}
		print_stack(&lastCoins);//print the stack to see your last coins
	}
}

void addCoin(int   coin,
	int* current_coins,
	Stack* last_coins)
{
	Node* new_node;
	int flag = 0;
	new_node = (Node*)malloc(sizeof(Stack));
	if (*current_coins + coin >= CockePrice) //chek if you got a new coke can
	{
		printf("You Got a new coke can\n");
		memset(last_coins, 0, sizeof(*last_coins));
		free(last_coins->head);                          //free the stack
		coin = ((*current_coins + coin) - CockePrice);
		*current_coins = 0;
		flag = 1; 
	}
	if (coin == 0)
		return;
	*current_coins = (*current_coins + coin) % CockePrice;
	if (last_coins->head == NULL && flag==0) //chek if need to build a new stack 
	{
		new_node->value = coin;
		last_coins->head = new_node;
		new_node->next = NULL;
	}
	else
	{
		if (flag == 1) { //if your coin get over 5 you dont need to insert the coin to the stack
			flag = 0;
			return;
	    }
		new_node->value = coin;
		new_node->next = last_coins->head;
		last_coins->head = new_node;
	}
}

int popLastCoin(Stack* last_coins,
	int* current_coins)
{
	int value;
	Node* head;
	if (last_coins->head== NULL) //if the stack is empty
	{
		printf("There arent any coins in the machine \n");
		return;
	}
	value = last_coins->head->value;
	*current_coins -= value;
	head = last_coins->head;
	last_coins->head = head->next;
	head->next = NULL;
	return value;
}

void print_stack(Stack* last_coins)
{
	Node* node;
	printf("[");
	node = last_coins->head;
	while (node != NULL)
	{
		printf("%d,", node->value);
		node = node->next;
	}
	printf("]\n");
}