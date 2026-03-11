#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Nod {
	Masina info;
	struct Nod* next;
};
typedef struct Nod Nod;

// --- FUNCTII AJUTATOARE ---

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	if (fgets(buffer, 100, file) == NULL) {
		Masina m = { 0 };
		return m;
	}
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = (float)atof(strtok(NULL, sep));

	aux = strtok(NULL, sep);
	m1.model = (char*)malloc(strlen(aux) + 1);
	strcpy(m1.model, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m1.numeSofer, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d, Usi: %d, Pret: %.2f, Model: %s, Sofer: %s, Serie: %c\n",
		masina.id, masina.nrUsi, masina.pret, masina.model, masina.numeSofer, masina.serie);
}

// --- GESTIONARE LISTA ---

void afisareListaMasini(Nod* cap) {
	while (cap) {
		afisareMasina(cap->info);
		cap = cap->next;
	}
}

void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
	Nod* temp = (Nod*)malloc(sizeof(Nod));
	temp->info = masinaNoua;
	temp->next = NULL;

	if (*cap == NULL) {
		*cap = temp;
	}
	else {
		Nod* p = *cap;
		while (p->next) {
			p = p->next;
		}
		p->next = temp;
	}
}

Nod* citireListaMasiniDinFisier(const char* numeFisier) {
	FILE* file = fopen(numeFisier, "r");
	if (!file) return NULL;

	Nod* cap = NULL;
	while (!feof(file)) {
		Masina m = citireMasinaDinFisier(file);
		if (m.model != NULL) { // Verificam sa nu fi citit o linie goala
			adaugaMasinaInLista(&cap, m);
		}
	}
	fclose(file);
	return cap;
}

void dezalocareListaMasini(Nod** cap) {
	while (*cap) {
		free((*cap)->info.model);
		free((*cap)->info.numeSofer);
		Nod* temp = *cap;
		*cap = (*cap)->next;
		free(temp);
	}
	*cap = NULL;
}

// --- FUNCTII PRELUCRARE ---

float calculeazaPretMediu(Nod* cap) {
	if (!cap) return 0;
	float suma = 0;
	int contor = 0;
	while (cap) {
		suma += cap->info.pret;
		contor++;
		cap = cap->next;
	}
	return (contor > 0) ? (suma / contor) : 0;
}

void stergeMasiniDinSeria(Nod** cap, char serieCautata) {
	while (*cap && (*cap)->info.serie == serieCautata) {
		Nod* temp = *cap;
		*cap = (*cap)->next;
		free(temp->info.model);
		free(temp->info.numeSofer);
		free(temp);
	}

	if (*cap == NULL) return;

	Nod* p = *cap;
	while (p->next) {
		if (p->next->info.serie == serieCautata) {
			Nod* temp = p->next;
			p->next = temp->next;
			free(temp->info.model);
			free(temp->info.numeSofer);
			free(temp);
		}
		else {
			p = p->next;
		}
	}
}

float calculeazaPretulMasinilorUnuiSofer(Nod* cap, const char* numeSofer) {
	if (!cap || !numeSofer) return 0;
	float suma = 0;
	while (cap) {
		if (strcmp(cap->info.numeSofer, numeSofer) == 0) {
			suma += cap->info.pret;
		}
		cap = cap->next;
	}
	return suma;
}

int main() {
	Nod* cap = citireListaMasiniDinFisier("masini.txt");
	if (cap) {
		printf("=== Lista initiala ===\n");
		afisareListaMasini(cap);

		printf("\nPret mediu: %.2f\n", calculeazaPretMediu(cap));

		printf("\nStergem seria 'A'...\n");
		stergeMasiniDinSeria(&cap, 'A');

		printf("\n=== Lista dupa stergere ===\n");
		afisareListaMasini(cap);

		dezalocareListaMasini(&cap);
		printf("\nMemorie eliberata. Program terminat.\n");
	}
	else {
		printf("Fisierul nu a putut fi deschis sau este gol!\n");
	}
	return 0;
}