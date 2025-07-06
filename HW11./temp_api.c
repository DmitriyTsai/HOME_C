#include "temp_api.h"
#include <stdio.h>

void print_month_stats(const TemperatureData *data, int size, uint8_t month) {
    int count = 0;
    int sum = 0;
    int8_t min_temp = 99;
    int8_t max_temp = -99;

    for (int i = 0; i < size; i++) {
        if (data[i].month == month) {
            sum += data[i].temperature;
            count++;

            if (data[i].temperature < min_temp) {
                min_temp = data[i].temperature;
            }
            if (data[i].temperature > max_temp) {
                max_temp = data[i].temperature;
            }
        }
    }

    if (count > 0) {
        float avg_temp = (float)sum / count;
        printf("Month %02d:\n", month);
        printf("  Average temperature: %.2f\n", avg_temp);
        printf("  Min temperature: %d\n", min_temp);
        printf("  Max temperature: %d\n", max_temp);
    } else {
        printf("No data for month %02d\n", month);
    }
}

void print_year_stats(const TemperatureData *data, int size) {
    if (size == 0) {
        printf("No data available\n");
        return;
    }

    int sum = 0;
    int8_t min_temp = 99;
    int8_t max_temp = -99;
    uint16_t year = data[0].year;

    for (int i = 0; i < size; i++) {
        sum += data[i].temperature;

        if (data[i].temperature < min_temp) {
            min_temp = data[i].temperature;
        }
        if (data[i].temperature > max_temp) {
            max_temp = data[i].temperature;
        }
    }

    float avg_temp = (float)sum / size;
    printf("Year %d:\n", year);
    printf("  Average temperature: %.2f\n", avg_temp);
    printf("  Min temperature: %d\n", min_temp);
    printf("  Max temperature: %d\n", max_temp);
}