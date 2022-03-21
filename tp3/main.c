#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule
{
	double note;
	struct Cellule* next;
} Cel;

typedef Cel* List;

void addNote(List*, double);
void addFirst(List*, double);
void DisplayList(List);

void main() {
	List l = NULL;
	double note;
	int choix;

	do {
		printf("1 - Add note \n");
		printf("2 - Add first \n");
		printf("3 - Get all notes \n");
		printf("4 - Exit \n");
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

		case 3: DisplayList(l);break;
		}
		
	} while (choix != 4);

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
		printf("%lf->", l->note);
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