//#define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// 
// struct StructuraMasina {
// 	int id;
// 	int nrUsi;
// 	float pret;
// 	char* model;
// 	char* numeSofer;
// 	unsigned char serie;
// };
// typedef struct StructuraMasina Masina;
// 
// struct Nod {
//     Masina info;
//     struct Nod* next;
//     struct Nod* prev;
// };
// typedef struct Nod Nod;
//
// struct ListaDubla {
//     int nrNoduri;
//     Nod* first;
//     Nod* last;
// };
//
// typedef struct ListaDubla ListaDubla;
// 
// Masina citireMasinaDinFisier(FILE* file) {
// 	char buffer[100];
// 	char sep[3] = ",\n";
// 	fgets(buffer, 100, file);
// 	char* aux;
// 	Masina m1;
// 	aux = strtok(buffer, sep);
// 	m1.id = atoi(aux);
// 	m1.nrUsi = atoi(strtok(NULL, sep));
// 	m1.pret = atof(strtok(NULL, sep));
// 	aux = strtok(NULL, sep);
// 	m1.model = malloc(strlen(aux) + 1);
// 	strcpy_s(m1.model, strlen(aux) + 1, aux);
// 
// 	aux = strtok(NULL, sep);
// 	m1.numeSofer = malloc(strlen(aux) + 1);
// 	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
// 
// 	m1.serie = *strtok(NULL, sep);
// 	return m1;
// }
// 
// void afisareMasina(Masina masina) {
// 	printf("Id: %d\n", masina.id);
// 	printf("Nr. usi : %d\n", masina.nrUsi);
// 	printf("Pret: %.2f\n", masina.pret);
// 	printf("Model: %s\n", masina.model);
// 	printf("Nume sofer: %s\n", masina.numeSofer);
// 	printf("Serie: %c\n\n", masina.serie);
// }
// 
// void afisareListaMasiniDeLaInceput(ListaDubla lista) {
//     Nod* p = lista.first;
//     while (p) {
//         afisareMasina(p->info);
//         p = p->next;
//     }
// }
//
// void afisareListaMasiniDeLaSfarsit(ListaDubla lista) {
//     Nod* p = lista.last;
//     while (p) {
//         afisareMasina(p->info);
//         p = p->prev;
//     }
// }
// 
// void adaugaMasinaInLista(ListaDubla* lista, Masina masinaNoua) {
//     Nod* nou = (Nod*)malloc(sizeof(Nod));
//     nou->info = masinaNoua;
//     nou->next = NULL;
//     nou->prev = lista->last;
//     if (lista->last != NULL) {
//         lista->last->next = nou;
//     }
//     else {
//         lista->first = nou;
//     }
//     lista->last = nou;
//     lista->nrNoduri++;
// }
// 
// void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) {
//     Nod* nou = (Nod*)malloc(sizeof(Nod));
//     nou->info = masinaNoua;
//     nou->next = lista->first;
//     nou->prev = NULL;
//     if(lista->first != NULL){
//         lista->first->prev = nou;
//     }
//     else {
//         lista->last = nou;
//     }
//     lista->first = nou;
//     lista->nrNoduri++;
// }
// 
// ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
//     FILE* f = fopen(numeFisier, "r");
//     ListaDubla lista;
//     lista.first = NULL;
//     lista.last = NULL;
//     lista.nrNoduri = 0;
//     while (!feof(f)) {
//         adaugaMasinaInLista(&lista,citireMasinaDinFisier(f));
//     }
//     fclose(f);
//     return lista;
// }
// 
// void dezalocareLDMasini(ListaDubla* lista) {
//     Nod* p = lista->first;
//     while (p) {
//         Nod* aux = p;
//         p = p->next;
//         if (aux->info.model) {
//             free(aux->info.model);
//         }
//         if (aux->info.numeSofer) {
//             free(aux->info.numeSofer);
//         }
//         free(aux);
//     }
//     lista->first = NULL;
//     lista->last = NULL;
//     lista->nrNoduri = 0;
// }
// 
// float calculeazaPretMediu(/*lista de masini*/) {
// 	//calculeaza pretul mediu al masinilor din lista.
// 	return 0;
// }
// 
// void stergeMasinaDupaID(/*lista masini*/ int id) {
// 	//sterge masina cu id-ul primit.
// 	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
// }
// 
// char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
// 	//cauta masina cea mai scumpa si 
// 	//returneaza numele soferului acestei maasini.
// 	return NULL;
// }
// 
// int main() {
//     ListaDubla lista = citireLDMasiniDinFisier("masini.txt");
//     afisareListaMasiniDeLaInceput(lista);
//     //afisareListaMasiniDeLaSfarsit(lista);
//     dezalocareLDMasini(&lista);
//     Masina m;
//     m.id = 132131231;
//     m.nrUsi = 4;
//     m.pret = 35000.5;
//
//     m.model = malloc(strlen("Audi A4") + 1);
//     strcpy(m.model, "Audi A4");
//
//     m.numeSofer = malloc(strlen("Ion Popescu") + 1);
//     strcpy(m.numeSofer, "Ion Popescu");
//
//     m.serie = 'Z';
//
//     adaugaLaInceputInLista(&lista, m);
//     afisareListaMasiniDeLaSfarsit(lista);
// 	return 0;
// }