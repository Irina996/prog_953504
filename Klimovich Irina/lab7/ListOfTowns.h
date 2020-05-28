// ---------------------------------------------------------------------------

#ifndef ListOfTownsH
#define ListOfTownsH
#include "Town.h"

// ---------------------------------------------------------------------------
/* ������ ���� ������� */
struct ListOfTowns {
	Town *head;
	Town *tail;
};

void ReadFromFile(ListOfTowns *towns); // ������ �� �����
void AddNewTown(ListOfTowns *towns, char name[20], float longti, float lati);
// ���������� ����� ����
ListOfTowns* CreateListOfTowns(); // �������� ������
void DeleteListOfTowns(ListOfTowns **list); // ������� ������
void PrintTowns(ListOfTowns towns);  /*����� �������*/
#endif
