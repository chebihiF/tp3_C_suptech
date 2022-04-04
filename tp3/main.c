#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cellule
{
	double note;
	struct Cellule* next;
} Cel;

typedef Cel* List;

void addNote(List*, double);
void addFirst(List*, double);
void DisplayList(List);
void addMid(List, double);
void deleteFirst(List*);
void deleteLast(List);
void deleteByNote(List*, double);

void main() {
	List l = NULL;
	double note;
	int choix;

	do {
		printf("1 - Add Last \n");
		printf("2 - Add first \n");
		printf("3 - Add Mid \n");
		printf("4 - Delete Last \n");
		printf("5 - Delete first \n");
		printf("6 - Delete Mid \n");
		printf("7 - Get all notes \n");
		printf("8 - Exit \n");
		printf("choise : ");
		scanf_s("%d", &choix);
		
		switch (choix)
		{
		case 1: {
			printf("Donner une note  : ");
			scanf_s("%lf", &note);
			addNote(&l, note);}break;
		case 2: {
			printf("Donner une note  : ");
			scanf_s("%lf", &note);
			addFirst(&l, note);}break;

		case 3: {
			printf("Donner une note  : ");
			scanf_s("%lf", &note);
			addMid(l, note);}break;

		case 4: deleteLast(l);break;
		case 5: deleteFirst(&l);break;
		case 6: {
			printf("Donner une note  : ");
			scanf_s("%lf", &note);
			deleteByNote(&l, note);}break;

		case 7: DisplayList(l);break;

		}
		
	} while (choix != 8);

}

void addNote(List* l, double note) {
	List p;
	if (*l == NULL) {
		*l = malloc(sizeof(Cel));
		(*l)->note = note;
		(*l)->next = NULL;
	}
	else
	{
		p = *l;
		while (p->next != NULL) p = p->next;
		p->next = malloc(sizeof(Cel));
		p->next->note = note;
		p->next->next = NULL;
	}
}

void DisplayList(List l) {
	while (l!=NULL)
	{
		printf("%g->", round(l->note));
		l = l->next;
	}
	printf("NULL\n");
}

void addFirst(List* l, double note) {
	List p = malloc(sizeof(Cel));
	p->note = note;
	p->next = *l;
	*l = p;
}

/* we conceder that we use a sorted list */
void addMid(List l, double note) {
	List n = malloc(sizeof(Cel));
	n->note = note;

	List p = l;
	while (p->next->note < note)
		p = p->next;

	n->next = p->next;
	p->next = n;
}

void deleteFirst(List *l) {
	List p = *l;
	(*l) = (*l)->next;
	free(p);
}

void deleteLast(List l) {
	List p = l;
	while (p->next->next != NULL)
		p = p->next;
	List d = p->next;
	free(d);
	p->next = NULL;
}

void deleteByNote(List *l, double note) {
	while ((*l)->note == note)
		deleteFirst(l);
	List p = *l;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	if (p->note == note)
		deleteLast(*l);

	p = *l;
	while (p->next != NULL) {
		while (p->next!=NULL && p->next->note != note) {
			p = p->next;
		}
		if (p->next == NULL)
			break;
		List d = p->next;
		p->next = d->next;
		free(d);
	}
}