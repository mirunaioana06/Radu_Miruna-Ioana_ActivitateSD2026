//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////eu
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
//void afisareMasina(Masina masina) {
//	printf("id ul masinii: %d\n", masina.id);
//	printf("nr usi ul masinii: %d\n", masina.nrUsi);
//	printf("pretul masinii: %2f\n", masina.pret);
//	printf("modelul masinii: %s\n", masina.model);
//	printf("numele spferului masinii : % s\n", masina.numeSofer);
//	printf("seria masinii: %c\n \n", masina.serie);
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	for (int i = 0;i < nrMasini;i++) {
//
//		afisareMasina(masini[i]);
//
//	}
//}
//
//void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
//	Masina* temp = (Masina*)malloc(sizeof(Masina) *( (*nrMasini) + 1));
//	for (int i = 0;i < *nrMasini;i++) {
//		
//		temp[i] = (*masini)[i];// de ce se scrie asa(vector de oboecte)  ##aici e shallow copy
//		//sa fac deep copy ? nu pentru ca vrem shallow copu=y si noi o sa facem pointerii dupa
//	
//	}
//	temp[*nrMasini] = masinaNoua;
//	free(*masini);
//	(*masini) = temp;
//	(*nrMasini)++;
//
//
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	Masina m;
//	char buffer[50];//aloca(e alocare statica pe stiva si noi avem nevoie de ea doar in interiorul acestei funtii deci noi nu ne mai ocupap cu dezalocare pt ca e static de aia facem asa)re statica
//	//ce salvam in buffr? un sir de caractere....cum imi dau seama daca sa pun spatiu in buffer de ce 27 nu e bun?  practic te uiti in fisierul txt vezi care e cea mai  are linie si dupa aia iti dai seama daca in c ape aici cea mai lunga linie e 28 asa ca ne trebuie uundeva al a30 cu aprox
//	// noi punem 50 pt siguranta
//	fgets(buffer, 50, file);
//	char* var[30]=",\n";//de ce 30?
//	strtok(buffer, ",");//aici am facut un  fel de split
//	//ce e strtok?  o functie
//	m.id = atoi(strtok(buffer, var));//ce e asci print - functia atoi?
//	m.nrUsi = atoi(strtok(NULL, var));// inainte rea buffer dar noi deja am floosit strtok cu buffer la prima si el citeste fisierul pe bucati pana dupa virgula deci daca pun null tel se duce la flagul lasta anterior cand a citit deasupra si continua de acolo
//	m.pret= atof(strtok(buffer, var));// ce e atof?
//	//model e char * deci trebuie sa ii alocam spatiu
//	char* aux=strtok(NULL, var);//aux e pointer care retine adressa w1 in casul meu unde  e sirul de caractere opel sau astra adica modelul de la masina.... nu ii facem alocare dinamica dar in alocam de tip pointr care pinteaza catre adresa unde e pus numele modelului  asa ca pointerul meu pointeaza catre o adreza unde e ceva
//	m.model = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	stcpy(m.model, aux);
//	aux = strtok(NULL, var);
//	m.numeSofer = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	stcpy(m.numeSofer, aux);
//	m.serie = (strtok(NULL, var))[0];// de ce e zero la final? ceva legat de finalul liniei
//	return m;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//	// deschidem un fisier f open
//	FILE* file;
//	file = fopen(numeFisier,"r");// ii dam r pt ca vreau sa citesc din fisier
//	//euf end of file EOF e un flag e o functie feof care zice function(find) end o file
//	Masina* masini=NULL;
//	*nrMasiniCitite = 0;//pt ca inca nu am citit nimic inca
//	while(!feof(file)){// dar el vrea pe o singura linie
//		////Masina m = citireMasinaFisier(file)// e bun si asa);
//		//adaugaMasinaInVector(*masini, *nrMasiniCitite,citireMasinaFisier(file) );
//
//		adaugaMasinaInVector(&masini, *nrMasiniCitite, citireMasinaFisier(file));
//	}
//	fclose(file);
//
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	//este dezalocat intreg vectorul de masini
//	for (int i = 0;i < (nrMasini);i++) {
//
//		free(vector[i]->model);// deref + deplasare+ dereferentiere+accesare
//	//                                 aici e deplas+deref adica []
//		free((*vector)[i].numeSofer);
//		free(*vector);
//		(*vector) = NULL;
//		(*nrMasini) = 0;
//	}
//}
//
//int main() {
//	int nrMasini = 0;
//	Masina* masini = NULL;
//	masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
//	afisareVectorMasini(masini, nrMasini);
//
//	return 0;
//}