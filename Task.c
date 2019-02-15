#include <stdio.h>
#include <math.h>
#define CompletedTask 6 
#define LenStack 1000
//for Тask2
#define T char
typedef struct TNode Node;struct TNode
{
	T value;
	struct TNode *next;
};
struct Stack
{
	Node *head;
	int size;
	int maxSize;
};
typedef struct TNode Node;
struct Stack Stack;
//for Тask1
int steck[LenStack];	//массив как стэк Тask1
int i = -1;				//крайний элемент стэка Тask1
//for Lesson
void printMenu();
void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
//for Тask2
void push(T value);		
T pop();			
void PrintStack();	

int main(int argc, const char * argv[])
{
	printMenu();
}

void printMenu() {
	int answer = 0;
	do {
		printf("Select task number:\n");
		printf("0. ExiT The MenU\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n1.10-2(Stack);\n2.Checking for memory allocation(Stack);\n3.A sequence of brackets;\n4.Copying a single linked list;\n5.Infix to Postfix;\n6.Queue;\n");
		scanf("%d", &answer);
		system("cls");
	} while (answer < 0 || answer > CompletedTask);

	switch (answer) {
	case 0:
		return;
	case 1:
		task_1();
		break;
	case 2:
		task_2();
		break;
	case 3:
		task_3();
		break;
	case 4:
		task_4();
		break;
	case 5:
		task_5();
		break;
	case 6:
		task_6();
		break;
	
	default:
		break;
	}
	printf("\n-=-=-=-=-= Press any key =-=-=-=-=-\n");
	getch();
	system("cls");
	printMenu();
}

void task_1() {
	int num10;
	printf("Enter a number in the 10NS ");
	scanf("%d", &num10);
	printf("%d in the 2NS = ", num10);
	if (num10 == 0) steck[i++] = 0; else
	while (num10>0)
	{
		i++;
		steck[i]=num10 % 2;
		num10 /= 2;
	}
	while (i >= 0)
	{
		printf("%d",steck[i]);
		i--;
	}
}

void task_2() {

		Stack.maxSize = 5; //макс размер стека
		Stack.head = NULL; //головной элемент

		push('a');
		push('b');
		push('c');
		push('d');
		push('e');
		//в этом месте память перестается выделяться
		push('f');
		PrintStack();
		return 0;
	
	printf("Body task_2");
 }

void task_3() {
	int j=-1,ControlChek=0;
	char str[1000];
	printf("Enter the bracket sequence\n");
	scanf("%s", str);
	//printf("%s", str);
	i = 0;
	while (str[i] != '\0')
	{
		
		if (str[i] == '(')
		{
			j++;
			steck[j] = 1;
		}
		if (str[i] == ')')
		{
			steck[j] = steck[j] - 1;
			ControlChek = steck[j];
			if (ControlChek == 0)j--;
		}
			
		if (str[i] == '{')
		{
			j++;
			steck[j] = 2;
		}
		if (str[i] == '}')
		{
			steck[j] = steck[j] - 2;
			ControlChek = steck[j];
			if (ControlChek==0)j--;
		}
		
		if (str[i] == '[')
		{
			j++;
			steck[j] = 3;
		}
		if (str[i] == ']')
		{
			steck[j] = steck[j]-3;
			ControlChek = steck[j];
			if (ControlChek == 0)j--;
		}
	//printf("CC=%d S[j]=%d j=%d", ControlChek, steck[j], j);
	//	getch();
		i++;
	}
	if (ControlChek == 0 & j == -1)//steck[j] == -1
		printf("The sequence is correct");
	else printf("The sequence is not correct");
	
}

void task_4() {
	printf("Body task_4");
}

void task_5() {
	printf("Body task_4");
}

void task_6() {
	printf("Body task_4");
}

//добавление элемента в стек char
void push(T value){
	if (Stack.size >= Stack.maxSize) {
		printf("Error stack size.\nThere was enough space for values:");
		return;
	}
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}
T pop() {
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	Node* next = NULL;
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	free(next);
	Stack.size--;
	return value;
}
void PrintStack()
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}