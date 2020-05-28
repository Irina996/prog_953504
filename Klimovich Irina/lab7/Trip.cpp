// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Trip.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctime>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

/* ��������� ����� ���� � ����� ������ */
void AddPost(Trip *trip, char name[20], float longti, float lati) {
	if (trip->head != NULL) {
		float longt2, lat2;
		longt2 = trip->tail->longtitude;
		lat2 = trip->tail->latitude;
		trip->price += fabs(longti - longt2) + fabs(lati - lat2);
	}
	Town *tmp = (Town*) malloc(sizeof(Town));
	if (tmp == NULL) {
		printf("Error. Tehnical dificulties.");
		getch();
		exit(3);
	}
	for (int i = 0; i < 20; i++) {
		tmp->TownName[i] = name[i];
	}
	tmp->longtitude = longti;
	tmp->latitude = lati;
	tmp->next = NULL;
	tmp->prev = trip->tail;
	if (trip->tail) {
		trip->tail->next = tmp;
	}
	trip->tail = tmp;

	if (trip->head == NULL) {
		trip->head = tmp;
	}
}

/* �������� ������ */
Trip* CreateTrip() {
	Trip *tmp = (Trip*) malloc(sizeof(Trip));
	tmp->head = tmp->tail = NULL;
	tmp->next = tmp->prev = NULL;
	tmp->price = 0;

	return tmp;
}

/* �������� ������ */
void DeleteTrip(Trip **list) {
	Town *tmp = (*list)->head;
	Town *next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list)->prev = NULL;
	(*list)->next = NULL;
	(*list)->price = 0;
}

/* ����� ������ � ������� */
void PrintTrip(Trip trip) {
	// printf("\nPrice: %.2f\n", trip.price);
	struct Town *p;
	p = trip.head;
	while (p != NULL) // ������� ��������� ������
	{
		printf("%s \t", p->TownName); // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	}
	printf("\n");
}

/* ���������� ����� ����� ��������� ������������� � ������ */
void AddTrip(Trip *trip, ListOfTowns towns) {
	printf("Press 1-to add town, 2-not to add, 3-to stop adding.\n");
	Town *temp = (Town*)malloc(sizeof(Town));
	temp = towns.head;
	int answer = 0;
	while (temp != NULL) {
		printf("%s\n", temp->TownName);
		scanf("%d", &answer);
		if (answer == 1) {
			AddPost(trip, temp->TownName, temp->longtitude, temp->latitude);
		}
		else if (answer == 3) {
			break;
		}
		else if (answer != 2) { /* ���� ��� ���������� ������������ ���� */
			printf("Encorrect input.\n"); /* ����� ��������� ��������� */
			printf("Press 1-to add town, 2-not to add, 3-to stop adding.\n");
			temp = temp->prev;
		}
		temp = temp->next;
	}
}

/* �������� ������������ �������� ����� ���������� ��������� ����� */
void StandartTrip(Trip *trip, ListOfTowns towns) {
	Town *temp = (Town*)malloc(sizeof(Town));
	temp = towns.head;
	int t = 0;
	int x, y; /* ��������� ����� ����������� �� �������� */
	x = rand() % 100;
	y = rand() % 100;
	if (x > y) {
		int t = y;
		y = x;
		x = t;
	}
	while (temp != NULL) {
		t = rand() % 100;
		if (t >= x && t <= y) { /* ���� � ���������, �� ���� ����� �������� */
			AddPost(trip, temp->TownName, temp->longtitude, temp->latitude);
		}
		temp = temp->next;
	}
	/* ���� �� ���� ���� �� ����� � ������ �������� ������ � ����� ������ */
	if (trip->head == NULL) {
		AddPost(trip, towns.head->TownName, towns.head->longtitude,
			towns.head->latitude);
		AddPost(trip, towns.tail->TownName, towns.tail->longtitude,
			towns.tail->latitude);
	}
	if (trip->head == trip->tail) { /* �������� ������ ���� ����� */
		if (trip->head != towns.head) {  /*���� �� �������� ������ � ������ �������*/
			AddPost(trip, towns.head->TownName, towns.head->longtitude,
				towns.head->latitude);
		}
		else /*����������� ����� �������� ������ � ������ �������*/
			AddPost(trip, towns.head->next->TownName,
			towns.head->next->longtitude, towns.head->next->latitude);
		if (trip->head != towns.head) {/*����� �� �������� ��������� � ������*/
			AddPost(trip, towns.tail->TownName, towns.tail->longtitude,
				towns.tail->latitude); /*���������� ����� ��������� � ������ �������*/
		}
		else
			AddPost(trip, towns.tail->prev->TownName,
			towns.tail->prev->longtitude, towns.tail->prev->latitude);
	}
}
void CopyTrip(Trip *route, Trip tr) {/*����������� ��������*/
	Town *temp = (Town*)malloc(sizeof(Town));
	temp = tr.head;
	while(temp) {
		AddPost(route, temp->TownName, temp->longtitude, temp->latitude);
		temp = temp->next;
	}
}
