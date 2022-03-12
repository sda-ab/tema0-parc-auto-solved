#ifndef MASINA
#define MASINA
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Masina {
    char *marca;
    char *model;
    char tokenMasina[11];
    int pretAchizitie;
    int pretVanzare;
}Masina;

int countLinesInFile(char *inputFilePath);
void deepCopy (Masina source, Masina *destination);
void swap(Masina *firstCar, Masina *secondCar);
void swapIfConditionFulfilled(Masina *firstCar, Masina *secondCar);
void alphabetialcSortCars(Masina *listaMasini, int numberOfCars);
void printCars(Masina *listaMasini, int numberOfCars);
Masina *createCarsInventory(char *inputFilePath);
Masina *enchantedCreateCarsInventory(char *inputFilePath);

#endif