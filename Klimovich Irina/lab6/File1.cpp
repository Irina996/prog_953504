// ---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <conio.h>
#include <tchar.h>
#include <string.h>
// ---------------------------------------------------------------------------
/*5.2(9)� ��������� ����� ���������� n ����� ����� � �������� �������
��������� (m ��� ������). ��������� �������� ������, � �������
������ ������������� ������ ������, � ���� �� ������ ������������
�������� �������������� ����� (�1� � ������� � ������� �������,
�0� � ������� � ������ �������).*/
#pragma argsused

/* ���������, ����������� ���� ������ */
typedef struct item {
	int data; // ���� ������
	struct item *left; //����� �������
	struct item *right; //������ �������
}Item;

void AddNode(char* data, int count, Item **node, int number);
void PrintTree(Item *node);
void DeleteTree(Item *node);

int _tmain(int argc, _TCHAR* argv[]) {
	char buffer[128];
	int m = 0, n = 0;
	Item *root = NULL; /* ������ ������ */
	FILE *fp = fopen("G:\\Ira\\Progr\\LR6\\Binnum.txt", "r");
	if (!fp) {
		puts("ERROR");
		getch();
		return 1;
		}
	/* ��������� �������� �� ����� ��������� */
	while (fgets(buffer, 128, fp) != NULL) {
		++n;
		printf("%s", buffer); // ����� ����������� �����
	}
	rewind (fp); // ����������� � ������ �����
	fgets(buffer, 128, fp);
	while (buffer[m]!=NULL) {
		++m;
	}
	--m;
	printf("\n%d numbers %d bits each\n", n, m);// ������� ���������� ����� � ��� � �����
	rewind (fp); // ����������� � ������ �����
    while (fgets(buffer, 128, fp) != NULL) {
		AddNode(buffer, m-1, &root, atoi(buffer));
	}
	PrintTree(root);
	DeleteTree(root);
	fclose(fp);
	getch();
	return 0;
}
void DeleteTree(Item *node) {
	if(node!=NULL) {
		DeleteTree(node->left);
		DeleteTree(node->right);
		free(node);
	}
}

/* �������� ����� � ������ */
void AddNode(char* data, int count, Item **node, int number) {
	if (*node == NULL) {      // ���� ���� ���
		*node = (Item*)malloc(sizeof(Item));  // �������� ������ ��� ����� ����
		(*node)->data = NULL;
		(*node)->left = (*node)->right = NULL;
	}
	if (count == 0) {  // ���� ��������� ���� ����� ����� ����� ����������
		Item *newnode = (Item*)malloc(sizeof(Item));
		newnode->right = newnode->left = NULL;
		newnode->data = number;
		if (data[count]=='1') {        //  ��������� ���� ������
			(*node)->right = newnode;
		}
		else (*node)->left = newnode;
		return;
	}
	if (data[count] == '1') {
		--count;                      // ��������� ������ �������
		AddNode(data, count, &(*node)->right, number);
	}
	else if (data[count] == '0') {
		--count;                      // ��������� ����� �������
		AddNode(data, count, &(*node)->left, number);
	}
}

// ����� ������
void PrintTree(Item *node) {
	if (node != NULL) { // ���� ���� �� ������
		PrintTree(node->left); //����������� ������� ��� ������ ���������
		if (node->data != NULL) { // ���� ���� ������ � ���� ����
			printf("%d ", node->data); //���������� ��
		}
		PrintTree(node->right); //����������� ������� ��� ������� ���������
	 }
}
// ---------------------------------------------------------------------------
