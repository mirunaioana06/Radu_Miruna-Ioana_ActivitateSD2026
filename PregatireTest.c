#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char* nume;
    float medie;
    char sex;
};


struct Student initStudent(int id, char* nume, float medie, char sex) {
    struct Student s;
    s.id = id;
    s.nume = (char*)malloc(strlen(nume) + 1);
    strcpy(s.nume, nume);
    s.medie = medie;
    s.sex = sex;
    return s;
}


struct Student* initVector(int n) {
    struct Student* v = (struct Student*)malloc(n * sizeof(struct Student));
    if (v == NULL) {
        printf("Eroare malloc!\n");
        return NULL;
    }
    return v;
}


void afisare(struct Student* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] ID:%d | Nume:%s | Medie:%.2f | Sex:%c\n",
            i, v[i].id, v[i].nume, v[i].medie, v[i].sex);
    }
}


void modificaMedie(struct Student* v, int index, float medie_noua) {
    v[index].medie = medie_noua; 
}


void dezalocare(struct Student** v, int n) {
    for (int i = 0; i < n; i++) {
        free(v[i]->nume);  
        v[i]->nume = NULL;
    }
    free(*v);              
    *v = NULL;
}

int main() {
    int n = 3;
    struct Student* v = initVector(n);

    v[0] = initStudent(1, "Ion Popescu", 9.50f, 'M');
    v[1] = initStudent(2, "Ana Ionescu", 8.75f, 'F');
    v[2] = initStudent(3, "Radu Georgescu", 7.00f, 'M');

    afisare(v, n);
    modificaMedie(v, 1, 9.99f);
    printf("\nDupa modificare:\n");
    afisare(v, n);

    dezalocare(&v, n);
    return 0;
}