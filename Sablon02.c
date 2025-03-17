//#include<stdio.h>
//#include<malloc.h>
//
//struct Masina {
//	int id;
//	int nrKm;
//	char* model;
//	float pret;
//	char tipMotor;
//};
//struct Masina initializare(int id, int nrKm, const char* model, float pret, char tipMotor) {
//	struct Masina m;
//	m.id = id;
//	m.nrKm = nrKm;
//	m.model = (char*)malloc(strlen(model) + 1);
//	strcpy(m.model, model);
//	m.pret = pret;
//	m.tipMotor = tipMotor;
//	return m;
//}
//
//void afisare(struct Masina m) {
//	printf("Id: %d, nr km: %d, model: %s, pret: %f, tip motor: %c", m.id, m.nrKm, m.model, m.pret, m.tipMotor);
//
//}
//
//void afisareVector(struct Masina* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afisare(vector[i]);
//		printf("\n");
//	}
//}
//
//struct Masina* copiazaPrimeleNElemente(struct Masina* vector, int nrElemente, int* nrElementeCopiate) {
//	struct Masina* vectorNou;
//	vectorNou = NULL;
//
//	if (vector != NULL && (*nrElementeCopiate) > 0) {
//		if (nrElemente < (*nrElementeCopiate)) {
//			(*nrElementeCopiate) = nrElemente;
//		}
//		vectorNou = malloc(sizeof(struct Masina) * (*nrElementeCopiate));
//
//		for (int i = 0; i < (*nrElementeCopiate); i++) {
//			vectorNou[i] = initializare(vector[i].id, vector[i].nrKm, vector[i].model, vector[i].pret, vector[i].tipMotor);
//		}
//	}
//	return vectorNou;
//}
//
//void dezalocare(struct Masina** vector, int* nrElemente) {
//	for (int i = 0; i < (*nrElemente); i++) {
//		if ((*vector)[i].model != NULL) {
//			free((*vector)[i].model);
//		}
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//
//void copiazaMasiniIeftine(struct Masina* vector, char nrElemente, float prag, struct Masina** vectorNou, int* dimensiune) {
//	*dimensiune = 0;
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].pret < prag) {
//			(*dimensiune)++;
//		}
//	}
//	if (*dimensiune == 0) {
//		*vectorNou = NULL;
//		return;
//	}
//	*vectorNou = (struct Masina*)malloc(sizeof(struct Masina) * (*dimensiune));
//	if (*vectorNou == NULL) {
//		printf("Eroare la alocarea memoriei!\n");
//		exit(1);
//	}
//	int k = 0;
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].pret < prag) {
//			(*vectorNou)[k] = vector[i];
//			(*vectorNou)[k].model = (char*)malloc(strlen(vector[i].model) + 1);
//			if ((*vectorNou)[k].model != NULL) {
//				strcpy((*vectorNou)[k].model, vector[i].model);
//			}
//			k++;
//		}
//	}
//}
//
//
//struct Masina getPrimulElementConditionat(struct Masina* vector, int nrElemente, const char* conditie) {
//	struct Masina s;
//	s.id = -1;
//
//	for(int i =0;i<nrElemente;i++){
//		if (strcmp(vector[i].model, conditie) == 0) {
//			return vector[i];
//		}
//	}
//
//	return s;
//}
//
//
//
//int main() {
//	struct Masina* vec;
//	int n = 3;
//	vec = malloc(sizeof(struct Masina) * n);
//	vec[0] = initializare(10, 100000, "Logan", 1000.4, 'd');
//	vec[1] = initializare(11, 1000, "Passat", 2500.4, 'b');
//	vec[2] = initializare(12, 25675, "CyberTruck", 1000.0, 'e');
//	afisareVector(vec, n);
//	printf("\n");
//
//	int nrElementeCopiate = 5;
//	struct Masina* vecnou = copiazaPrimeleNElemente(vec, n, &nrElementeCopiate);
//	printf("Afisare elementele copiate: \n");
//	afisareVector(vecnou, nrElementeCopiate);
//
//	//dezalocare(&vecnou, &nrElementeCopiate);
//
//	printf("Afisare elementele ieftine: \n");
//	copiazaMasiniIeftine(vec, n, 1500, (&vecnou), &nrElementeCopiate);
//	afisareVector(vecnou, nrElementeCopiate);
//
//	//dezalocare(&vecnou, &nrElementeCopiate);
//	//dezalocare(&vec, &n);
//
//	struct Masina cautare = getPrimulElementConditionat(vec, n, "Logan");
//	if (cautare.id != -1) {
//		printf("Masina gasita: ID=%d, Model=%s\n", cautare.id, cautare.model);
//	}
//	else {
//		printf("Nu exista nicio masina care indeplineste conditia data.\n");
//	}
//
//
//	return 0;
//}