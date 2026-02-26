#include<stdio.h>
#include<stdlib.h>


struct Produs
{
	int id;
	int stoc;
	char* denumire;
	float pret;
	char categorie;


};
struct Produs initializare(int id, int stoc, char* denumire, float pret, char categorie)
{
	struct Produs s;
	s.id = id;
	s.stoc = stoc;
	s.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(s.denumire, denumire);

	s.pret = pret;
	s.categorie = categorie;
	return s;
}

void afisare(struct Produs s)
{
	printf("ID: %d\n", s.id);
	printf("stoc: %d\n ", s.stoc);
	printf("denumire : %s\n", s.denumire);
	printf("pret: %5.2f\n ", s.pret);
	printf("Categrorie : %c\n", s.categorie);
}


void modifica_Denumire(struct Produs* s, char* nouaDenumire)
{
	free(s->denumire);
	s->denumire = (char*)malloc(sizeof(char) * strlen(nouaDenumire) + 1);
	strcpy(s->denumire, nouaDenumire);

}
void dezalocare(struct Produs* s)
{
	if (s->denumire != NULL)
	{
		free(s->denumire);
		s->denumire = NULL;
	}
}

float calculeaza_valaore(struct Produs s)
{
	return s.stoc * s.pret;
}






int main()
{

	struct Produs s;

	s = initializare(1, 20, "Telefon ", 2000, 'A');
	afisare(s);
	modifica_Denumire(&s, "mouse");
	afisare(s);
	printf("valoarea totala pentru %s este %5.2f RON ", s.denumire, calculeaza_valaore(s));
	dezalocare(&s);


}

//
//void afisare(struct Telefon t) {
//	if (t.producator != NULL) {
//		printf("%d. Telefonul %s seria %c are %d GB RAM si costa %5.2f RON.\n",
//			t.id, t.producator, t.serie, t.RAM, t.pret);
//	}
//	else {
//		printf("%d. Telefonul din seria %c are %d GB RAM si costa %5.2f RON.\n",
//			t.id, t.serie, t.RAM, t.pret);
//	}
//}
//
//void modificaPret(struct Telefon* t, float noulPret) {
//	if (noulPret > 0) {
//		t->pret = noulPret;
//	}
//}
//
//void dezalocare(struct Telefon* t) {
//	if (t->producator != NULL) {
//		free(t->producator);
//		t->producator = NULL;
//	}
//}
//
//int main() {
//	struct Telefon t;
//	t = initializare(1, 256, "Samsung", 2000.5, 'A');
//	afisare(t);
//	modificaPret(&t, 1000);
//
//	afisare(t);
//	dezalocare(&t);
//	afisare(t);
//	return 0;
//}