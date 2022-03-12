#include "masina.h"
void printSortedCars(Masina *listaMasini, int numberOfCars, char *outputFilePath);
void generateStatisticsAndPrintInFile(Masina *listaMasini, int numberOfCars, char *outputFilePath);
int numberOfCarsToSell(Masina *listaMasini, int numberOfCars, char marca[]);
int vindemMasiniClan(Masina **listaMasini, int *numberOfCars, char marca[]);
void runDemonstrationJob(Masina **listaMasini, int *numberOfCars, char *outputFilePath, char *marciFilePath);