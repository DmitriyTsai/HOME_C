#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

#define MAX_RECORDS 10000

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureData;

// Основные функции статистики
void print_month_stats(const TemperatureData *data, int size, uint8_t month);
void print_year_stats(const TemperatureData *data, int size);

// Функции работы с данными
int add_record(TemperatureData *data, int *size, TemperatureData new_record);
int remove_record(TemperatureData *data, int *size, int index);
void sort_records(TemperatureData *data, int size);
void print_records(const TemperatureData *data, int size);

// Функции работы с файлами
int load_csv(TemperatureData *data, int *size, const char *filename);
int save_csv(const TemperatureData *data, int size, const char *filename);

#endif