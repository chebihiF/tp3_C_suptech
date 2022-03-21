#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule
{
	double note;
	struct Cellule* next;
} Cel;

typedef Cel* List;

void addNote(List, double);
void DisplayList(List);

void main() {
	List l = NULL;
	double note;
	int choix;

	do {
		printf("1 - Add note \n");
		printf("2 - Get all notes \n");
		printf("3 - Exit \n");
		printf("choise : ");
		scanf_s("%d", &choix);
		
		switch (choix)
		{
		case 1: {
			printf("Donner une note  : ");
			scanf_s("%lf", &note);
			addNote(&l, note);}break;

		case 2: DisplayList(l);break;
		}
		
	} while (choix != 3);

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