#ifndef MASINA
#define MASINA
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define READ "r"
#define WRITE "w"
#define APPEND "a"

typedef struct Masina {
    char *marca;
    char *model;
    char tokenMasina[11];
    int pretAchizitie;
    int pretVanzare;
}Masina;

FILE *openFile(char *inputFilePath, char mode[]);
int countLinesInFile(char *inputFilePath);
void deepCopy (Masina source, Masina *destination);
void swap(Masina *firstCar, Masina *secondCar);
void swapIfConditionFulfilled(Masina *firstCar, Masina *secondCar);
void alphabeticalSortCars(Masina *listaMasini, int numberOfCars);
void printCars(Masina *listaMasini, int numberOfCars);
Masina *createCarsInventory(char *inputFilePath, int *numberOfCars);
Masina *enchantedCreateCarsInventory(char *inputFilePath, int *numberOfCars);

#endif