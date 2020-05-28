// ---------------------------------------------------------------------------

#ifndef TProgramH
#define TProgramH
#include "ListOfTrips.h"

// ---------------------------------------------------------------------------
struct Date { // ���� �������

	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
};

struct Service { // ������

	bool chose; // ������� ��� ���
	float price; // ���������
	char name[40]; // ��������
};

typedef struct TouristProgram {
	struct Trip *route; // �������
	Date date; // ����
	int places; // ���������� ���������� �� ��� ��������
	float price; // ���������
	Service service[9]; // ������
} TProgram;

TProgram* CreateProgram(); /* �������� ��������� */
void AddPersonalProgram(TProgram*, ListOfTowns, ListOfTrips*);
/* ���������� ����� �������� ������� ������� ��������� �������� ������������ */
void ChooseTrip(TProgram *prog, ListOfTrips trips, int number);
/* ����� �������� ��� ���������*/
void PrintProgram(TProgram prog);/*����� ���������*/
void DeleteTProgram(TProgram *prog);/*��������*/
void Services(TProgram *prog); /*����� �����*/
void CopyInf(TProgram* pr1, TProgram* pr2);/*����������� ���������� �� pr1 � pr2*/

#endif
