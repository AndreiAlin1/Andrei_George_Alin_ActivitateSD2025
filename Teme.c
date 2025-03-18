#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Andrei Alin - aa
struct Magazin {
	char* denumire;
	int nrMagazineInRomania;
	int nrAngajati;
};
typedef struct Magazin Magazin;

void afisareMagazin(Magazin magazin) {
	printf("Denumire: %s \n", magazin.denumire);
	printf("Nr magazine in Romania: %d \n", magazin.nrMagazineInRomania);
	printf("Nr angajati: %d \n\n", magazin.nrAngajati);
}

Magazin citireMagazinFisier(FILE* file) {
	Magazin m;
	char buffer[100];
	char delimiter[4] = ",;\n";
	fgets(buffer, 100, file);

	char* tok = strtok(buffer, delimiter);

	m.denumire = malloc(strlen(tok) + 1);
	strcpy(m.denumire, tok);

	m.nrMagazineInRomania = atoi(strtok(NULL, delimiter));
	m.nrAngajati = atoi(strtok(NULL, delimiter));

	return m;
}

void adaugaMagazinInVector(Magazin** magazin, int* nrMagazine, Magazin magazinNou) {
	Magazin* aux = (Magazin*)malloc(sizeof(Magazin) * ((*nrMagazine) + 1));
	for (int i = 0; i < (*nrMagazine); i++) {
		aux[i] = (*magazin)[i];
	}
	aux[(*nrMagazine)] = magazinNou;
	free(*magazin);
	(*magazin) = aux;
	(*nrMagazine)++;
}

Magazin* citireVectorMagazinFisier(const char* numeFisier, int* nrMagazineCitite) {
	Magazin* magazin = NULL;
	FILE* file = fopen(numeFisier, "r");
	while (!feof(file)) {
		Magazin m = citireMagazinFisier(file);
		adaugaMagazinInVector(&magazin, nrMagazineCitite, m);
	}
	fclose(file);
	return magazin;
}

void afisareVectorMasini(Magazin* magazin, int nrMagazine) {
	int i;
	for (i = 0; i < nrMagazine; i++) {
		afisareMagazin(magazin[i]);
	}
}

void salvareMagazinInFisier(const char* numeFisier, Magazin magazin) {
	FILE* file = fopen(numeFisier, "a");
	if (file == NULL) {
		printf("Eroare la deschiderea fișierului!\n");
		return;
	}

	fprintf(file, "\n%s,%d,%d", magazin.denumire, magazin.nrMagazineInRomania, magazin.nrAngajati);
	fclose(file);
}

void salvareVectorMagazineInFisier(const char* numeFisier, Magazin* magazine, int nrMagazine) {
	FILE* file = fopen(numeFisier, "w");
	if (file == NULL) {
		printf("Eroare la deschiderea fișierului!\n");
		return;
	}

	for (int i = 0; i < nrMagazine; i++) {
		fprintf(file, "%s,%d,%d\n", magazine[i].denumire, magazine[i].nrMagazineInRomania, magazine[i].nrAngajati);
	}

	fclose(file);
	printf("Vectorul de magazine a fost salvat cu succes in %s!\n", numeFisier);
}

int main() {
	Magazin* magazine = NULL;
	int nrMagazine = 0;
	magazine = citireVectorMagazinFisier("magazine.txt", &nrMagazine);
	afisareVectorMasini(magazine, nrMagazine);

	Magazin m;
	m.denumire = "Vodafone";
	m.nrMagazineInRomania = 300;
	m.nrAngajati = 10000;
	salvareMagazinInFisier("magazine.txt", m);

	int nrMagazine2 = 3;
	salvareVectorMagazineInFisier("magazineVector.txt", magazine, nrMagazine2);

	return 0;
}