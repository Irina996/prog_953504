// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "ListOfTowns.h"
#include "ListOfTrips.h"
#include"TProgram.h"
#include <ctime>
#include <time.h>
#include <iostream>
#define MaxPlace 30 //������������ ���������� �������� � ����������
// ---------------------------------------------------------------------------
#pragma argsused

/*6.2 (24). Santaren. ����������� ������ ���������� ��������������
�����������. � ������ ��������� ������ ���������
����������: �������, ����, ���������� ����, ����� ���������
����. ��������� ������� �� ������ ������������ � ��������������
������������� �����. ������������ ����� ��������������
������������ ���� ��������� ���� ������� ������ ���������.
�������� �������� ����� ������������� �������� � ����������
����� � ������������. ������ �������� �� ������ ���������,
���������� ������������� ������� �� ���� �������������� �����.
������ ������� ��������.*/

void InputDate(Date *date);/* �������� ����� ����*/
void Input(int &number, int max); /* ��������� ����� ������ ����� number(�� ������ max)*/
void Menu();/*����� ����*/
void SubMenu1();/*������� */
void SubMenu2();
void SubMenu3();

// ---------------------------------------------------------------------------
int main() {
	srand(time(NULL));
	ListOfTowns *towns = CreateListOfTowns();/* ������, ������� ����� ��������*/
	ReadFromFile(towns);/* ���������� �� �����*/
	ListOfTrips *trips = CreateListOfTrips(); /* ������ ���������*/
	for (int i = 0; i < 5; i++) {
		AddStandartTrip(trips, *towns);/*��������� ��������*/
	}
	TProgram *prog = (TProgram*)malloc(20 * sizeof(TProgram));
	/* ������������� ���������*/
	int work = 1; /* ��������� ������������� ����� ����*/
	int subwork = 0; /* ��������� ������������� ����� �������*/
	int k = 0; /*���������� ������������ ������������� ��������*/
	int number = 0;/* ��� ���������� ����������������� �����*/
	while (work) {
		number = 0;
		Menu();/* ����� ������� ����*/
		Input(work, 4); /*���� ������ ����*/
		switch (work) {
		case 1:
			printf("End");
			work = 0; /*���������� ������*/
			break;
		case 2:
			SubMenu1(); /*�������*/
			Input(subwork, 4);
			switch (subwork) {
			case 1:
				break;
			case 2: /* create new program */
				if (k < 20) {
					prog[k] = *CreateProgram();
					printf("1.Choose existing route.\n");
					printf("2.Create your own route.\n");
					printf("Enter number of function.\n");
					Input(number, 2);
					if (number == 1) { /*������� ������������ �������*/
						PrintListOfTrips(*trips);
						printf("Enter number of trip\t");
						Input(number, trips->amount + 1);
						ChooseTrip(&prog[k], *trips, number);
					}
					else if (number == 2) { /*������� ���� �������*/
						AddPersonalProgram(&prog[k], *towns, trips);
					}
					printf("Number of tourists: ");
					Input(prog[k].places, MaxPlace);/* ���������� ��������*/
					InputDate(&prog[k].date);/*���� ����*/
					Services(&prog[k]);  /* ����� ��������� �����*/
					printf("Price: %.3f\n", prog[k].price); /*����� ������������ ����*/
					++k;
				}
				break;
			case 3: // existing program
				if (k != 0) {
					for (int i = 0; i < k; i++) {
						printf("%d.\n", i + 1);
						PrintProgram(prog[i]);
					}
					int index = 0;
					printf("Enter number of program");
					Input(index, k); /*����� ���������*/
					--index;
					printf("Number of tourists: "); /*���������� ���������� ��������*/
					Input(number, MaxPlace - prog[index].places);
					prog[index].places += number;
				}
				else
					printf("No existing programs");
				break;
			case 4: /* add service */
				if (k != 0) {
					for (int i = 0; i < k; i++) {
						printf("%d.\n", i + 1);
						PrintProgram(prog[i]);
					}
					printf("Enter number of program\t");
					prog[k] = *CreateProgram();
					Input(number, k);
					--number;
					CopyInf(&prog[k], &prog[number]); /*����������� ������������ ���������*/
					Services(&prog[k]);  /*���������� �����*/
					printf("Number of tourists: ");
					Input(prog[k].places, MaxPlace);/* ���������� �������*/
					++k;
				}
				else
					printf("No existing programs");
				break;
			default:
				printf("Error. Enter one more time.\n");
				break;
			}
			break;
		case 3:
			SubMenu2();
			Input(subwork, 3);
			switch (subwork) {
			case 1:
				break;
			case 2: {
				printf("\n");
				int t = 1;   /*����� ��������, � ������� ��������� ����� ������*/
				for (int i = 0; i < k; i++) {
					if (prog[i].places == 30) {
						printf("%d\n", t);
						PrintProgram(prog[i]);
						++t;
					}
				}
				} break;
			case 3:
				printf("\n");/*����� ���� ������������ ��������*/
				for (int i = 0; i < k; i++) {
					PrintProgram(prog[i]);
				}
				break;
			default:
				printf("Error. Enter one more time.\n");
				break;
			}
			break;
		case 4:
			SubMenu3();
			Input(subwork, 2);
			switch (subwork) {
			case 1:
				break;
			case 2: {  /*������ ��������*/
					float income = 0.0;
					for (int i = 0; i < k; i++) {
						income += (prog[i].places*prog[i].price);
					}
					printf("Company income is about %.3f\n", income);
				} break;
			default:
				printf("Error. Enter one more time.\n");
				break;
			}
			break;
		default:
			printf("Error. Enter one more time..\n");
			break;
		}
	}
	/*�������� ������*/
	for (int i = 0; i < k; i++) {
		DeleteTProgram(&prog[i]);
	}
	free(prog);
	DeleteListOfTrips(&trips);
	DeleteListOfTowns(&towns);
	return 0;
}

// ---------------------------------------------------------------------------
void Menu() {
	printf("\n1.Exit.\n");
	printf("2.Record on a tourist program.\n");
	printf("3.Tourist trips\n");
	printf("4.Company income\n");
	printf("Enter number of service\n");
}

void SubMenu1() {
	printf("Record on a tourist program.\n");
	printf("\t1.To menu.\n");
	printf("\t2.Create new program.\n");
	printf("\t3.Choose existing program.\n");
	printf("\t4.Add service for an existing program.\n");
	printf("Enter number of service\n");
}

void SubMenu2() {
	printf("Tourist trips.\n");
	printf("\t1.To menu.\n");
	printf("\t2.Print tourist trips.\n");
	printf("\t3.Print tourist programs.\n");
	printf("Enter number of service\n");
}

void SubMenu3() {
	printf("Company income.\n");
	printf("\t1.To menu.\n");
	printf("\t2.Print company income.\n");
	printf("Enter number of service\n");
}

void InputDate(Date *date) {
	time_t now = time(0);
	struct tm *time;
	time = localtime(&now);
	bool error = false;
	do {
		error = false;
		printf("Date: ");
		scanf("%d.%d.%d", &date->day, &date->month, &date->year);
		fflush(stdin);
		if (date->year < time->tm_year + 1900)
		{ /* ���� ������ ��� ������ ��� ������ */
			error = true;
		}
		/* ���� ������ ����� ����� ����, ������� ��� ��� */
		else if (date->year == time->tm_year + 1900 && date->month <
			time->tm_mon + 1) {
			error = true;
		}
		/* ���� ������ ���� ����� ������ ������ ����, ������� ��� ��� */
		else if (date->month == time->tm_mon + 1 && date->day < time->tm_mday) {
			if (date->year == time->tm_year + 1900) {
				error = true;
			}
		}
		/* ���� ������ ������������� ����� ��� ���� */
		else if (date->day < 1 || date->month < 1) {
			error = true;
		}
		/* �������� �� ���������� ���� ��� ������ ���� ������� ����� ������� */
		else if (date->month < 8 && date->month != 2) {
			if (date->month % 2 != 0 && date->day > 31) {
				error = true;
			}
			else if (date->day > 30) {
				error = true;
			}
		}
		/* �������� �� ���������� ���� ��� ������ ������� */
		else if (date->month > 7) {
			if (date->month > 12) { /* ���� ������ ����� ������ ������ 12 */
				error = true;
			}
			if (date->month % 2 == 0 && date->day > 31) {
				error = true;
			}
			else if (date->day > 30) {
				error = true;
			}
		}
		else if (date->month == 2) { /* �������� ������� */
			if (date->year % 4 != 0 ||
				date->year % 100 == 0 && date->year % 400 != 0) {
				if (date->day > 28) { /* ������� ��� */
					error = true;
				}
			}
			else if (date->day > 29) { /* ���������� ��� */
				error = true;
			}
		}
		if (error) {
			printf("Error.Enter one more time.\n");
			date->day = date->month = date->year = 0;
		}
	}
	while (error);
}

void Input(int &number, int max) { /*�������� �����*/
	bool error = false;
	do {
		error = false;
		int res = scanf("%d", &number);
		fflush(stdin); /*�������� ������*/
		if (res != 1)
			error = true;
		if (number < 1 || number > max) {
			error = true;
		}
		if (error)
			printf("Invalid input. Try again.\n");
	}
	while (error);
}
