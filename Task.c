//1. Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов.
//2. Переписать программу, реализующую двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;
//в) *Добавить в программу обработку командной строки, с помощью которой можно указывать, из какого файла считывать данные, каким образом обходить дерево.
//Белканов Алексей
#include <stdio.h>
#include <math.h>
#include <windows.h>
#define CompletedTask 3
FILE* file;
///Task2 Добавление структуры - узел дерева
typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;
void printMenu();
void task_1();
void task_2a();
void task_2b();
void task_2c();
int HasFunSumKodStr(char str[]);
void preOrderTravers(Node* root);
Node *create(Node *root, int data);
Node *add(Node *root, int data);
//Node* Tree(int n);
//void printTree(Node *root);
//void example();

int main(int argc, const char * argv[])
{
	printMenu();
}

void printMenu() {
	int answer = 0;
	do {
		printf("Select task number:\n");
		printf("0. ExiT The MenU\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n1 Hash function;\n2(2a).Tree traversal;\n3(2b).Search in a binary tree;\n4(2c).Bypass program with menu and selection;\n");
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
		task_2a();
		break;
	case 3:
		task_2b();
		break;
	case 4:
		task_2c();
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
	char str[1000];
	printf("Enter a string to convert with the HASH function\n");
	scanf("%s", str);
	printf("\nThe sum of the character codes: %d",HasFunSumKodStr(str));
}

void task_2a() {
	Node tree;
	create(&tree, 1);
	//for (int i=0; i<10;i++)
	add(&tree, 1);
	preOrderTravers(&tree);
}

void task_2b() {

}

void task_2c() {

}



/// Task1 Подается строка, на выходе сумма кодов символов
int HasFunSumKodStr(char str[])
{
	int i=0,sum=0;
	if (str[i] == !0)
		printf("Invalid data transmitted");
	else 
	{
		printf("Character codes have the form:");
		while (str[i] != '\0')
		{
			printf("%d", (int)str[i]);					//тут можно задать кодирвоание добавив сторонние символы
			sum += (int)str[i];
			i++;
		}
		return sum;
	}
	
}
/// Task2 Создание корня бинарного дерева
Node *create (Node *root, int data)
{
	Node *tmp = malloc(sizeof(Node));
	tmp->data = data;
	tmp->parent = NULL;
	tmp->left = tmp->right = NULL;
	root = tmp;
	return root;
}
/// Task2 Добавление элемента узла
Node *add(Node *root, int data)
{
	Node *root2 = root, *root3 = NULL;
	Node *tmp = malloc(sizeof(Node));
	tmp->data = data;
	while (root2 != NULL)
	{
		root3 = root2;
		if (data < root2->data)
			root2 = root2->left;
		else
			root2 = root2->right;
	}
	tmp->parent = root3;
	tmp->left = NULL;
	tmp->right = NULL;
	if (data < root3->data) root3->left = tmp;
	else root3->right = tmp;
	return root;
}
/// Task2 Обход в прямом порядке
void preOrderTravers(Node* root) {
		if (root) {
			printf("%d ", root->data);
			preOrderTravers(root->left);
			preOrderTravers(root->right);
		}
	}
/// Task2 Обход симметричный
void inOrderTravers(Node* root) {
	if (root) {
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}
/// Task2 Обход в обратном порядке
void postOrderTravers(Node* root) {
	if (root) {
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}

//void example() {
//	Node* tree = NULL;
//	file = fopen("data.txt", "r");
//	if (file == NULL)
//	{
//		puts("Can't open file!");
//		return 1;
//	}
//	int count;
//	fscanf(file, "%d", &count); // Считываем количество записей
//	tree = Tree(count);
//	fclose(file);
//	printTree(tree);
//	return 0;
//}
// //from lesson построение сбалансированного дерева символов не менее 6
//Node* Tree(int n)
//{
//	Node* newNode;
//	int x, nl, nr;
//	if (n == 0)
//		newNode = NULL;
//	else
//	{
//		fscanf(file, "%d", &x);
//		nl = n / 2;
//		nr = n - nl - 1;
//		newNode = (Node*)malloc(sizeof(Node));
//		newNode->data = x;
//		newNode->left = Tree(nl);
//		newNode->right = Tree(nr);
//	}
//	return newNode;
//}
//// from lesson распечатка дерева в виде скобочнйо записи
//void printTree(Node *root)
//{
//	if (root)
//	{
//		printf("%d", root->data); 
//		if (root->left || root->right)
//		{
//			printf("(");
//			if (root->left)
//				printTree(root->left);
//			else
//				printf("NULL");
//			printf(",");
//			
//			if (root->right)
//				printTree(root->right);
//			else
//				printf("NULL");
//			printf(")");
//		}
//	}
//}









////https://tim4ous.com/realizatsiya-binarnogo-dereva-poiska-v-si/
////https://prog-cpp.ru/data-tree/
////https://learnc.info/adt/binary_tree_traversal.html