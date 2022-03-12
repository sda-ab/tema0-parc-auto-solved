#include "task.h"
#define numberOfTasks 3

int main(int argc, char *argv[]) {
    /*
    argv[1] = cerinte.in
    argv[2] = date.in
    argv[3] = rezultate.out
    argv[4] = marci.in
    */
    Masina *cars = NULL;
    int numberOfCars = countLinesInFile(argv[2]);
    int task[numberOfTasks];
    FILE *cerinteInput = NULL;

    if ((cerinteInput = fopen(argv[1], "r")) == NULL) {
        printf("Eroare la deschiderea fisierului");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numberOfTasks; i++) {
        fscanf(cerinteInput, "%d", &task[i]);
    }

    fclose(cerinteInput);
    
    if (task[0] == 1) {
        cars = enchantedCreateCarsInventory(argv[2]);
        printSortedCars(cars, numberOfCars, argv[3]);
    }

    if (task[1] == 1) {
        generateStatisticsAndPrintInFile(cars, numberOfCars, argv[3]); //groupBy de sarakie
    }

    if (task[2] == 1) {
        if (argv[4] == NULL) {
            printf("Nu a fost introdus fisierul de marci!");
            exit(EXIT_FAILURE);
        }
        
        runDemonstrationJob(&cars, &numberOfCars, argv[3], argv[4]);
    }

    free(cars);
    return 0;
}