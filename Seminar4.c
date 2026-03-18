//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//
//struct Nod {
//	Masina info;
//	struct Nod* next;
//};
//typedef struct Nod Nod; 
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret= atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(Nod* cap) {
//	//parcurgem lista cat timp cap e diferit de null
//	while (cap !=NULL) {
//		afisareMasina(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {// de ce e cap ** ?
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = NULL;
//	//cum facem distinctia dintre cele doua??
//	if (*cap == NULL) {
//		*cap = nodNou;
//	}
//	else {
//		Nod* aux = *cap;
//		while (aux != NULL)
//		{//ce e un auxiliar?
//			aux = aux->next;
//		}
//		aux->next = nodNou;
//	}
//}
//
//void adaugaLaInceputInLista(Nod**cap, Masina masinaNoua) {
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nouNod->info = masinaNoua;
//	nouNod->next = *cap;
//	*cap = nodNou;
//}
//
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	if (file) {
//		Nod* cap = NULL;
//		while (!feof(file)) {
//			adaugaMasinaInLista(&cap, citireMasinaDinFisier(file));
//		}return cap;
//		fclose(file);
//	}
//	return NULL;
//}
//
//void dezalocareListaMasini(Nod** cap) {
//	while (*cap) {
//		Nod* p = *cap;
//		(*cap) = p->next;
//		if (p->info.numeSofer) {
//			free(p->info.model);
//
//
//		}
//		free(p);
//	}
//
//	
//}
//
//float calculeazaPretMediu(Nod* cap) {
//	if (!cap) return 0;
//	float suma = 0;
//	int contor = 0;
//	while (cap) {
//		suma += cap->info.pret;
//		contor++;
//		cap = cap->next;
//	}
//	if (contor > 0) {
//		return suma / contor;
//	}
//	return 0;
//}
//// cel mai greu
//void stergeMasiniDinSeria(Nod** cap, char serieCautata) {
//	
//		while (*cap && (*cap)->info.serie == serieCautata) {
//			Nod* temp = *cap;
//			(*cap) = temp->next;
//
//			if (temp->info.numeSofer) {
//
//				free(temp->info.numeSofer);
//			}
//			if (temp->info.model) {
//				free(temp->info.model);
//			}
//			free(temp);
//		}
//		Nod* p = *cap;
//
//		while (p) {
//			while ((*p)->next&& p->next->info.serie!=serieCauta) 
//			{
//				p = p->next;
//							}
//			if (p->next) {
//
//
//				Nod* temp = p->next;
//
//				p->next = temp->next;
//
//				if (temp->info.numeSofer) {
//
//					free(temp->info.numeSofer);
//				}
//				if (temp->info.model) {
//					free(temp->info.model);
//				}
//				free(temp);
//
//			}
//			else {
//
//				p = p->next;
//
//			}
//		}
//	
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*lista masini*/ const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	return 0;
//}
//
//int main() {
//
//	Nod* cap = NULL;
//	cap= citireListaMasiniDinFisier("masini.txt");
//	afisareListaMasini(cap);
//	//dezalocareListaMasini(&cap);
//	afisareListaMasini(cap);
//	float valoare = 0;
//	valoare = calculeazaPretMediu(cap);
//	printf("pretul calculat este: %2F\n ", valoare);
//	printf("stergem serie\n");
//	stergeMasiniDinSeria(&cap, "A");
//	printf("dupa stergem serie a");
//	afisareListaMasini(cap);
//
//	return 0;
//}