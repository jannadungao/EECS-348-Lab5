#include <stdio.h>

// Monthly Sales Report
void msales_report() {

}



// Sales Summary Report
void sales_summary() {

}



// Six-Month Moving Average Report
void six_month_avg() {

}



// Sales Report highest to loweset
void highlow_sales_report() {

}


int main() {
    // get filename as input
    char filename;
    printf("Enter file name: ");
    scanf("%s", filename);

    // open file
    FILE* input_ptr;
    input_ptr = fopen(filename, "r");

    // generate array w/ sales per month
    int sales[12];
    
}