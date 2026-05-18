#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct structTelefon Telefon;
struct structTelefon {
	int id;
	int memorieGB;
	float pret;
	char* model;
	char* producator;
	unsigned char cartela;


};
typedef struct Nod Nod;
struct Nod {
	Telefon info;
	Nod* stanga;
	Nod* dreapta;
};


void adaugareTelefonInArbore(Nod** radacina, Telefon telefonNou) {

	if (*radacina) {
		if ((*radacina)->info.id > telefonNou.id) {

			adaugareTelefonInArbore(&(*radacina)->stanga,telefonNou);

		}
		else if ((*radacina)->info.id < telefonNou.id) {

			adaugareTelefonInArbore(&(*radacina)->dreapta, telefonNou);

		}




	}
	else {
		Nod* nou = (Nod*)malloc(sizeof(Nod));

		nou->info = telefonNou;
		nou->dreapta = NULL;
		nou->stanga = NULL;

		*radacina = nou;




	}








}


Telefon citireTelefonDinFisier(FILE* numefisier) {

	char buffer [100];
	char sep[3] = ",\n";
	fgets(buffer,100,numefisier);
	Telefon t;
	char* aux;

	aux = strtok(buffer,sep);
	t.id =atoi( aux);

	aux = strtok(NULL, sep);
	t.memorieGB = atoi(aux);

	aux = strtok(NULL, sep);
	t.pret = atof(aux);

	aux = strtok(NULL, sep);
	t.model = malloc(sizeof(aux)+1);
	strcpy(t.model,aux);

	aux = strtok(NULL, sep);
	t.producator = malloc(sizeof(aux) + 1);
	strcpy(t.producator, aux);

	aux = strtok(NULL, sep);
	t.cartela = aux[0];

	return t;

}








































