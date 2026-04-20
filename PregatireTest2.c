#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Angajat {
    int id;
    char* nume;
    float salariu;
    char departament;
};

struct Angajat initializare(int id, char* nume, float salariu, char departament) {
    struct Angajat a;
    a.id = id;
    a.nume = (char*)malloc(strlen(nume) + 1);
    strcpy(a.nume, nume);
    a.salariu = salariu;
    a.departament = departament;
    return a;
}

void afisare(struct Angajat a) {
    printf("ID:%-3d | %-20s | Salariu:%7.2f | Dept:%c\n",
        a.id, a.nume, a.salariu, a.departament);
}

void afisareVector(struct Angajat* vector, int nrElemente) {
    for (int i = 0; i < nrElemente; i++) {
        afisare(vector[i]);
    }
}

struct Angajat* copiazaPrimeleNElemente(struct Angajat* vector, int nrElemente, int nrElementeCopiate) {
    struct Angajat* vectorNou = (struct Angajat*)malloc(nrElementeCopiate * sizeof(struct Angajat));
    if (vectorNou == NULL) return NULL;

    for (int i = 0; i < nrElementeCopiate; i++) {
        vectorNou[i] = initializare(
            vector[i].id,
            vector[i].nume,
            vector[i].salariu,
            vector[i].departament
        );
    }
    return vectorNou;
}

void dezalocare(struct Angajat** vector, int* nrElemente) {
    for (int i = 0; i < *nrElemente; i++) {
        free((*vector)[i].nume);
        (*vector)[i].nume = NULL;
    }
    free(*vector);
    *vector = NULL;
    *nrElemente = 0;
}

void copiazaAnumiteElemente(struct Angajat* vector, int nrElemente, float prag,
    struct Angajat** vectorNou, int* dimensiune) {
    *dimensiune = 0;
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].salariu > prag) {
            (*dimensiune)++;
        }
    }

    *vectorNou = (struct Angajat*)malloc(*dimensiune * sizeof(struct Angajat));
    if (*vectorNou == NULL) return;

    int j = 0;
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].salariu > prag) {
            (*vectorNou)[j] = initializare(
                vector[i].id,
                vector[i].nume,
                vector[i].salariu,
                vector[i].departament
            );
            j++;
        }
    }
}

struct Angajat getPrimulElementConditionat(struct Angajat* vector, int nrElemente, const char* conditie) {
    for (int i = 0; i < nrElemente; i++) {
        if (strcmp(vector[i].nume, conditie) == 0) {
            return vector[i];
        }
    }
    struct Angajat gol;
    gol.id = -1;
    gol.nume = NULL;
    gol.salariu = 0;
    gol.departament = ' ';
    return gol;
}

int main() {
    int n = 4;
    struct Angajat* v = (struct Angajat*)malloc(n * sizeof(struct Angajat));

    v[0] = initializare(1, "Ion Popescu", 3500.0f, 'I');
    v[1] = initializare(2, "Ana Ionescu", 5200.0f, 'V');
    v[2] = initializare(3, "Radu Georgescu", 4100.0f, 'I');
    v[3] = initializare(4, "Maria Constantin", 2900.0f, 'A');

    printf("=== Toti angajatii ===\n");
    afisareVector(v, n);

    printf("\n=== Primii 2 angajati ===\n");
    struct Angajat* primii2 = copiazaPrimeleNElemente(v, n, 2);
    afisareVector(primii2, 2);

    printf("\n=== Angajati cu salariu > 4000 ===\n");
    struct Angajat* bineplatiti = NULL;
    int dim = 0;
    copiazaAnumiteElemente(v, n, 4000.0f, &bineplatiti, &dim);
    afisareVector(bineplatiti, dim);

    printf("\n=== Cauta Ana Ionescu ===\n");
    struct Angajat gasit = getPrimulElementConditionat(v, n, "Ana Ionescu");
    if (gasit.id != -1) afisare(gasit);
    else printf("Nu a fost gasit!\n");

    dezalocare(&v, &n);
    dezalocare(&primii2, &(int){2});
    dezalocare(&bineplatiti, &dim);

    return 0;
}