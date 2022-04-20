#include "headers/task.h"
#define numberOfTasks 3

int main(int argc, char *argv[]) {
    FILE *cerinteInput = openFile(argv[1], READ);
    Masina *cars = NULL;
    int numberOfCars, task[numberOfTasks];

    if (cerinteInput == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < numberOfTasks; i++)
        fscanf(cerinteInput, "%d", &task[i]);

    fclose(cerinteInput);
    
    if (task[0] == 1) {
        cars = enchantedCreateCarsInventory(argv[2], &numberOfCars);
        printSortedCars(cars, numberOfCars, argv[3]);
    }

    if (task[1] == 1)
        generateStatisticsAndPrintInFile(cars, numberOfCars, argv[3]);

    if (task[2] == 1) {
        if (argv[4] == NULL) {
            printf("Nu a fost introdus fisierul de marci!");
            exit(EXIT_FAILURE);
        }
        
        runDemonstrationJob(&cars, &numberOfCars, argv[3], argv[4]);
    }

    free(cars);
    cars = NULL;
    
    return 0;
}