// ---------------------------------------------------------------------------

#ifndef ListOfTripsH
#define ListOfTripsH
#include "Trip.h"

// ---------------------------------------------------------------------------
/* ������� = ���������� ������ */
struct ListOfTrips {
	Trip *head; // ������ �������
	Trip *tail; // ��������� �������
	int amount;
};

void AddRoute(ListOfTrips *trips, Trip *tmp, ListOfTowns towns);
// ���������� ������ ����
void AddStandartTrip(ListOfTrips *trips, ListOfTowns towns);
/* ���������� �������� �� ��������� ������� */
ListOfTrips* CreateListOfTrips(); // �������� ������
void PrintListOfTrips(ListOfTrips trips);/*����� ������ ���������*/
void DeleteListOfTrips(ListOfTrips **trips);/*��������*/
Trip* SearchTrip(ListOfTrips tripps, int number); /*����� �������� �� ������*/

#endif
