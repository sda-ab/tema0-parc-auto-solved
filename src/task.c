#include "task.h"

void printSortedCars(Masina *listaMasini, int numberOfCars, char *outputFilePath) {
    FILE *output = openFile(outputFilePath, WRITE);
    
    for (int i = 0; i < numberOfCars; i++)
        fprintf(output, "%s %s %s %d %d\n", listaMasini[i].marca, listaMasini[i].model, listaMasini[i].tokenMasina, listaMasini[i].pretAchizitie, listaMasini[i].pretVanzare);

    fclose(output);
}

void generateStatisticsAndPrintInFile(Masina *listaMasini, int numberOfCars, char *outputFilePath) {
    FILE *output = openFile(outputFilePath, WRITE);
    int counter = 1;

    for (int i = 0; i < numberOfCars - 1; i++) {
        if (strcmp(listaMasini[i].marca, listaMasini[i + 1].marca) == 0)
            ++counter;
        else {
            fprintf(output, "%s %d\n", listaMasini[i].marca, counter);
            counter = 1;
        }
    }

    fprintf(output, "%s %d\n", listaMasini[numberOfCars - 1].marca, counter);

    fclose(output);
}

int numberOfCarsToSell(Masina *listaMasini, int numberOfCars, char marca[]) {
    int numberOfCarsToSell = 0;
    for (int i = 0; i < numberOfCars; i++)
        if (strcmp(listaMasini[i].marca, marca) == 0)
            ++numberOfCarsToSell;
    
    return numberOfCarsToSell;
}

int sellCarsAndReturnProfit(Masina **listaMasini, int *numberOfCars, char marca[]) {
    int carsToSell = numberOfCarsToSell(*listaMasini, *numberOfCars, marca);
    Masina *updatedCarList = (Masina *)malloc((*numberOfCars - carsToSell) * sizeof(Masina));

    int flag = 0, profit = 0;
    for (int i = 0; i < *numberOfCars; i++) 
        if (strcmp((*listaMasini + i)->marca, marca) != 0) {
            deepCopy(*(*listaMasini + i), &updatedCarList[flag]);
            ++flag;
        } else {
            profit += (*listaMasini + i)->pretVanzare - (*listaMasini + i)->pretAchizitie;
        }

    *numberOfCars = *numberOfCars - carsToSell;

    free(*listaMasini);
    *listaMasini = updatedCarList;

    return profit;
}

void runDemonstrationJob(Masina **listaMasini, int *numberOfCars, char *outputFilePath, char *marciFilePath) {
    FILE *output = openFile(outputFilePath, WRITE);
    FILE *input = openFile(marciFilePath, READ);
    
    int numberOfMarci = countLinesInFile(marciFilePath);
    int profit = 0;
    char marca[25];
    
    for (int i = 0; i < numberOfMarci; i++) {
        fscanf(input, "%s", marca);
        profit += sellCarsAndReturnProfit(listaMasini, numberOfCars, marca);
    }

    for (int i = 0; i < *numberOfCars; i++) 
        fprintf(output, "%s %s %s %d %d\n", (*listaMasini + i)->marca, (*listaMasini + i)->model, (*listaMasini + i)->tokenMasina, (*listaMasini + i)->pretAchizitie, (*listaMasini + i)->pretVanzare);

    fprintf(output, "%d\n", profit);
}