//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "ListOfTrips.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
/* ���������� ������ ����*/
void AddRoute(ListOfTrips *trips,Trip *tmp, ListOfTowns towns) {
	tmp->next = NULL;
	tmp->prev = trips->tail;
	if (trips->tail) {
		trips->tail->next = tmp;
	}
	trips->tail = tmp;
	if (trips->head == NULL) {
		trips->head = tmp;
	}
	AddTrip(tmp, towns);
	++trips->amount;
}
/*���������� �������� �� ��������� �������*/
void AddStandartTrip (ListOfTrips *trips, ListOfTowns towns) {
	Trip *tmp = (Trip*)malloc(sizeof(Trip));
	tmp->next = NULL;
	tmp->prev = trips->tail;
	if (trips->tail) {
		trips->tail->next = tmp;
	}
	trips->tail = tmp;
	if (trips->head == NULL) {
		trips->head = tmp;
	}
	StandartTrip(tmp, towns);
	++trips->amount;
}

/* �������� ������ */
ListOfTrips* CreateListOfTrips() {
	ListOfTrips *tmp = (ListOfTrips*) malloc(sizeof(ListOfTrips));
	tmp->head = tmp->tail = NULL;
	tmp->amount = 0;
	return tmp;
}
/*����� ������*/
void PrintListOfTrips(ListOfTrips trips) {
	Trip *tmp = (Trip*)malloc(sizeof(Trip));
	tmp = trips.head;
	int i = 1;
	while(tmp) {
		printf("%d\n", i);
		PrintTrip(*tmp);
		tmp = tmp->next;
		++i;
	}
}
/*��������*/
void DeleteListOfTrips(ListOfTrips **trips) {
	Trip *tmp = (*trips)->head;
	Trip *next = NULL;
	(*trips)->amount = 0;
	while (tmp) {
		next = tmp->next;
		DeleteTrip(&tmp);
		free(tmp);
		tmp = next;
	}
	free(*trips);
	(*trips) = NULL;
}
/*����� �������� �� ������*/
Trip* SearchTrip(ListOfTrips trips, int number){
	Trip *tmp = (Trip*)malloc(sizeof(Trip));
	tmp = trips.head;
	for (int i = 0; i < number-1; i++) {
		tmp = tmp->next;
	}
	Trip *route = (Trip*)malloc(sizeof(Trip));
	CopyTrip(route, *tmp);
	return route;
}
