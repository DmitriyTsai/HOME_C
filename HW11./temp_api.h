#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

#define MAX_RECORDS 1000

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureData;

void print_month_stats(const TemperatureData *data, int size, uint8_t month);
void print_year_stats(const TemperatureData *data, int size);

#endif