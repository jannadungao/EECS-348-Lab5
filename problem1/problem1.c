#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Monthly Sales Report
void monthlysales(char months[12][12], float sales[256]) {
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");

    for (int i = 0; i < 12; i++) {
        printf("%s\t%f\n", months[i], sales[i]);
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
    char filename[256];
    printf("Enter file name: ");
    scanf("%s", filename);

    // open files
    FILE* input_ptr;
    input_ptr = fopen(filename, "r");


    // generate array w/ sales per month
    char sales[12][256];
    float fsales[256];
    char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int line = 0;

    while (line < 12 && fgets(*sales, 256, input_ptr) != NULL) {
        fsales[line] = atof(sales[line]);
        line++;
    }
    
    // function calls
    monthlysales(months, fsales);

    // close files
    fclose(input_ptr);
    return 0;
}