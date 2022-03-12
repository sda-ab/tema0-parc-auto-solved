#include "masina.h"

int countLinesInFile(char *inputFilePath) {
    FILE *input = NULL;
    int numberOfLines = 0;
    char line[200];

    if ((input = fopen(inputFilePath, "r")) == NULL) 
        printf("eroare la deschidere\n");

    while(fgets(line, 200, input)) {
            ++numberOfLines;
    }

    fclose(input);

    return numberOfLines;
}

void carShow(Masina *car) {
    printf("%s %s %s %d %d\n", car->marca, car->model, car->tokenMasina, car->pretAchizitie, car->pretVanzare);
}

void deepCopy (Masina source, Masina *destination) {
    destination->marca = strdup(source.marca);
    destination->model = strdup(source.model);
    strcpy(destination->tokenMasina, source.tokenMasina);
    destination->pretAchizitie = source.pretAchizitie;
    destination->pretVanzare = source.pretVanzare;
}

void swap(Masina *firstCar, Masina *secondCar) {
    Masina buffer;

    deepCopy(*firstCar, &buffer);
    deepCopy(*secondCar, firstCar);
    deepCopy(buffer, secondCar);
}

void swapIfConditionFulfilled(Masina *firstCar, Masina *secondCar) {
    
    if (strcmp(firstCar->marca, secondCar->marca) > 0) {
        swap(firstCar, secondCar);
    }
    else if (strcmp(firstCar->marca, secondCar->marca) == 0) {
        if (strcmp(firstCar->model, secondCar->model) > 0) {
            swap(firstCar, secondCar);
        }
        else if (strcmp(firstCar->model, secondCar->model) == 0)
            if (strcmp(firstCar->tokenMasina, secondCar->tokenMasina) > 0) {
                swap(firstCar, secondCar);
            }
    }
}

void alphabetialcSortCars(Masina *listaMasini, int numberOfCars) {
    for (int i = 0; i < numberOfCars - 1; i++) {
        for (int j = 0; j < numberOfCars - i - 1; j++) {
            swapIfConditionFulfilled(&listaMasini[j], &listaMasini[j + 1]);
        }
    }
}

void printCars(Masina *listaMasini, int numberOfCars) {

    for (int i = 0; i < numberOfCars; i++)
        printf("%s %s %s %d %d\n", listaMasini[i].marca, listaMasini[i].model, listaMasini[i].tokenMasina, listaMasini[i].pretAchizitie, listaMasini[i].pretVanzare);
}

Masina *createCarsInventory(char *inputFilePath) {
    int numberOfCars = countLinesInFile(inputFilePath);

    FILE *input = NULL;
    Masina *listaMasini = (Masina *)malloc(numberOfCars * sizeof(Masina));

    if ((input = fopen(inputFilePath, "r")) == NULL)
        printf("Eroare, fisierul nu a putut fi deschis!\n");

    char marcaAux[25], modelAux[25];
    for (int i = 0; i < numberOfCars; i++) {
        fscanf(input, "%s%s%s%d%d", marcaAux, modelAux, listaMasini[i].tokenMasina, &listaMasini[i].pretAchizitie, &listaMasini[i].pretVanzare);
        listaMasini[i].marca = strdup(marcaAux);
        listaMasini[i].model = strdup(modelAux);
    }

    fclose(input);

    return listaMasini;
}


Masina *enchantedCreateCarsInventory(char *inputFilePath) {
    int numberOfCars = countLinesInFile(inputFilePath);
    Masina *listaMasini = createCarsInventory(inputFilePath);
    alphabetialcSortCars(listaMasini, numberOfCars);

    return listaMasini;
}