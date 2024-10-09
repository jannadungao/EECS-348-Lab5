#include <stdio.h>
#include <stdlib.h>

// Monthly Sales Report
void monthlysales(char months[12][12], float sales[256]) {
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");

    for (int i = 0; i < 12; i++) {
        printf("%s\t%f\n", months[i], sales);
    }
    printf("\n");
}

// Sales Summary Report
void sales_summary(char months, char sales) {
    float min;
    float max;
    float avg;

    printf("\nSales Summary Report\n\n");
    printf("Minimum Sales: %f\n", min);
    printf("Maximum Sales: %f\n", max);
    printf("Average Sales: %f\n", avg);
    printf("\n");

}







int main() {
    // get filename as input
    char* filename;
    printf("Enter file name: ");
    scanf("%s", filename);

    // open files
    FILE* input_ptr;
    input_ptr = fopen(filename, "r");


    // generate array w/ sales per month
    char salesinitial[256];
    float sales[256];
    char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int i = 0;
    while (fgets(salesinitial, 256, input_ptr) != NULL) {
        salesinitial[i] = sales[i];
        sales[i] = salesinitial[i];
        i++;

    }
    
    // function calls
    monthlysales(months, sales);

    // close files
    fclose(input_ptr);
    return 0;
}