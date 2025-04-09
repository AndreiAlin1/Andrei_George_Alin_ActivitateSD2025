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
	Masina masina;
	struct Nod* next;
};
typedef struct Nod Nod;

struct HashTable {
	int dim;
	Nod** tabela;
};
typedef struct HashTable HashTable;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m; 

	aux = strtok(buffer, sep);
	m.id = atoi(aux);

	aux = strtok(NULL, sep);
	m.nrUsi = atoi(aux);

	aux = strtok(NULL, sep);
	m.pret = atof(aux);

	aux = strtok(NULL, sep);
	m.model = malloc(strlen(aux) + 1);
	strcpy_s(m.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m.numeSofer, strlen(aux) + 1, aux);

	m.serie = *strtok(NULL, sep);

	return m;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(Nod* headlist) {
	while (headlist) {
		afisareMasina(headlist->masina);
		headlist = headlist->next;
	}
}

void adaugaMasinaInLista(Nod* headlist, Masina masinaNoua) {
	Nod* p = headlist;
	while (p->next) {
		p = p->next;
	}
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->masina = masinaNoua;
	nou->next = NULL;
	p->next = nou;
}


HashTable initializareHashTable(int dimensiune) {
	HashTable ht;
	ht.dim = dimensiune;
	ht.tabela = (Nod**)malloc(dimensiune * sizeof(Nod*));
	for (int i = 0; i < dimensiune; i++) {
		ht.tabela[i] = NULL;
	}
	return ht;
}

int calculeazaHash(const char* nume, int dimensiune) {
	int suma = 0;
	for (int i = 0; i < strlen(nume); i++) {
		suma += nume[i];
	}
	return suma % dimensiune;
}

void inserareMasinaInTabela(HashTable hash, Masina masina) {
	int pozitie = calculeazaHash(masina.numeSofer, hash.dim);
	if (hash.tabela[pozitie] == NULL) {
		hash.tabela[pozitie] = (Nod*)malloc(sizeof(Nod));
		hash.tabela[pozitie]->masina = masina;
		hash.tabela[pozitie]->next = NULL;
	}
	else {
		adaugaMasinaInLista(hash.tabela[pozitie], masina);
	}
}

HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) {
	HashTable hash = initializareHashTable(dimensiune);
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina masina = citireMasinaDinFisier(f);
		inserareMasinaInTabela(hash, masina);
	}
	fclose(f);
	return hash;
}

void afisareTabelaDeMasini(HashTable ht) {
	for (int i = 0; i < ht.dim; i++) {
		if (ht.tabela[i] != NULL) {
			printf("\nMasinile de pe poz %d sunt: \n", i);
			afisareListaMasini(ht.tabela[i]);
		}
		else {
			printf("\nPe poz %d nu avem masini\n");
		}
	}
}

void dezalocareTabelaDeMasini(HashTable *ht) {
	//sunt dezalocate toate masinile din tabela de dispersie
}

float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
	//calculeaza pretul mediu al masinilor din fiecare cluster.
	//trebuie sa returnam un vector cu valorile medii per cluster.
	//lungimea vectorului este data de numarul de clustere care contin masini
	return NULL;
}

Masina getMasinaDupaCheie(HashTable ht /*valoarea pentru masina cautata*/) {
	Masina m;
	//cauta masina dupa valoarea atributului cheie folosit in calcularea hash-ului
	//trebuie sa modificam numele functiei 
	return m;
}

int main() {
	HashTable ht = citireMasiniDinFisier("masini.txt", 7);
	afisareTabelaDeMasini(ht);

	return 0;
}