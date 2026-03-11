#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraStudent {
	int id;
	int varsta;
	float medie;
	char* nume;
	char* facultate;
	unsigned char grupa;
};

typedef struct StructuraStudent Student;


void afisareStudent(Student s) {
	printf("ID: %d\n", s.id);
	printf("Varsta: %d\n", s.varsta);
	printf("Medie: %.2f\n", s.medie);
	printf("Nume: %s\n", s.nume);
	printf("Facultate: %s\n", s.facultate);
	printf("Grupa: %c\n", s.grupa);
	printf("--------------------\n");
}


void afisareVectorStudenti(Student* studenti, int nrStudenti) {
	for (int i = 0; i < nrStudenti; i++) {
		afisareStudent(studenti[i]);
	}
}


void adaugaStudentInVector(Student** studenti, int* nrStudenti, Student studentNou) {

	Student* aux = (Student*)malloc(sizeof(Student) * (*nrStudenti + 1));

	for (int i = 0; i < *nrStudenti; i++) {
		aux[i] = (*studenti)[i];
	}

	aux[*nrStudenti] = studentNou;

	free(*studenti);
	*studenti = aux;

	(*nrStudenti)++;
}


Student citireStudentFisier(FILE* f) {

	Student s;
	char buffer[100];

	if (fscanf(f, "%d", &s.id) != 1) {
		s.nume = NULL;
		return s;
	}

	fscanf(f, "%d", &s.varsta);
	fscanf(f, "%f", &s.medie);

	fscanf(f, "%s", buffer);
	s.nume = (char*)malloc(strlen(buffer) + 1);
	strcpy(s.nume, buffer);

	fscanf(f, "%s", buffer);
	s.facultate = (char*)malloc(strlen(buffer) + 1);
	strcpy(s.facultate, buffer);

	fscanf(f, " %c", &s.grupa);

	return s;
}


Student* citireVectorStudentiFisier(const char* numeFisier, int* nrStudenti) {

	FILE* f = fopen(numeFisier, "r");

	if (!f) {
		printf("Fisierul nu a putut fi deschis!\n");
		return NULL;
	}

	Student* studenti = NULL;
	*nrStudenti = 0;

	while (1) {

		Student s = citireStudentFisier(f);

		if (s.nume == NULL)
			break;

		adaugaStudentInVector(&studenti, nrStudenti, s);
	}

	fclose(f);

	return studenti;
}


void dezalocareVectorStudenti(Student** vector, int* nrStudenti) {

	for (int i = 0; i < *nrStudenti; i++) {
		free((*vector)[i].nume);
		free((*vector)[i].facultate);
	}

	free(*vector);

	*vector = NULL;
	*nrStudenti = 0;
}


int main() {

	int nrStudenti = 0;

	Student* studenti = citireVectorStudentiFisier("studenti.txt", &nrStudenti);

	afisareVectorStudenti(studenti, nrStudenti);

	dezalocareVectorStudenti(&studenti, &nrStudenti);

	return 0;
}