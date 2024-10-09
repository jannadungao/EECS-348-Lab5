#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Monthly Sales Report
void monthlysales(char months[12][12], float sales[256]) {
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");

    // print each month and sales
    for (int i = 0; i < 12; i++) {
        printf("%s\t%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

// Sales Summary Report
void sales_summary(float sales[256]) {
    float min = 99999999999;
    float max = 0;
    float avg = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) { // find min
            min = sales[i];
        }

        if (sales[i] > max) { // find max
            max = sales[i];
        }

        avg += sales[i]; // calculate average
    }
    avg /= 12;

    // print results
    printf("\nSales Summary Report:\n\n");
    printf("Minimum Sales: %.2f\n", min);
    printf("Maximum Sales: %.2f\n", max);
    printf("Average Sales: %.2f\n", avg);
    printf("\n");

}

// Six month moving average sales report
void six_month_avg(float sales[256]) {
    printf("Six-Month moving average report:\n\n");
    float avg1, avg2, avg3, avg4, avg5, avg6, avg7 = 0; // initalize averages

    // January - June
    for (int i = 0; i <= 5; i++) {
        avg1 += sales[i]; // add sales
    }
    avg1 /=6; // divide to calculate average
    printf("January - June: %.2f\n", avg1); // print result

    // Feb - July
    for (int i = 1; i <= 6; i++) {
        avg2 += sales[i];
    }
    avg2 /= 6;
    printf("February - July: %.2f\n", avg2);

    // March - Aug
    for (int i = 2; i <= 7; i++) {
        avg3 += sales[i];
    }
    avg3 /= 6;
    printf("March - August: %.2f\n", avg3);

    // April - Sep
    for (int i = 3; i <= 8; i++) {
        avg4 += sales[i];
    }
    avg4 /= 6;
    printf("April - September: %.2f\n", avg4);

    // May - Oct
    for (int i = 4; i <= 9; i++) {
        avg5 += sales[i];
    }
    avg5 /=6;
    printf("May - October: %.2f\n", avg5);

    // June - November
    for (int i = 5; i <= 10; i++) {
        avg6 += sales[i];
    }
    avg6 /= 6;
    printf("June - November: %.2f\n", avg6);

    // July - Dec
    for (int i = 6; i <= 11; i++) {
        avg7 += sales[i];
    }
    avg7 /= 6;
    printf("July - June: %.2f\n", avg7);
}

// Sales report highest to lowest
void hightolow(char months[12][12], float sales[256]) {
    printf("Sales Report (Highest to Lowest): \n\n");
    printf("Month\tSales\n");

    int place[12];
    for (int i = 0; i < 12; i++) {
        place[i] = i;
    }

    // Sort places high to low
    for (int i = 0; i < 12 - 1; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales[place[i]] < sales[place[j]]) {
                int temp = place[i];
                place[i] = place[j];
                place[j] = temp;
            }
        }
    }
    // print
    for (int i = 0; i < 12; i++) {
        printf("%-12s %.2f\n", months[place[i]], sales[place[i]]);
    }
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

    while (line < 12 && fgets(sales[line], 256, input_ptr) != NULL) {
        fsales[line] = roundf(atof(sales[line]) * 100) / 100;
        line++;
    }
    
    // function calls
    monthlysales(months, fsales);
    sales_summary(fsales);
    six_month_avg(fsales);
    hightolow(months, fsales);


    // close files
    fclose(input_ptr);
    return 0;
}