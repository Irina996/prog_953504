// ---------------------------------------------------------------------------

#ifndef TripH
#define TripH
#include "Town.h"
#include "ListOfTowns.h"

// ---------------------------------------------------------------------------
/* ������� = ���������� ������ */
struct Trip {
	float price; // ���� ����
	Town *head; // ������ �����
	Town *tail; // ��������� �����
	struct Trip *next; // ��������� �������
	struct Trip *prev; // ���������� �������
};

void AddPost(Trip *trip, char name[20], float longti, float lati);
// ���������� ���o�� ����
Trip* CreateTrip(); // �������� ������
void DeleteTrip(Trip **list); // ������� ������
void PrintTrip(Trip trip); /* ����� �������� */
void AddTrip(Trip *trip, ListOfTowns towns); /* ���������� �������� */
void StandartTrip(Trip *trip, ListOfTowns towns);
/* ���������� �������� �� ��������� ������� */
void CopyTrip(Trip *route, Trip tr);/*����������� ��������*/
#endif
