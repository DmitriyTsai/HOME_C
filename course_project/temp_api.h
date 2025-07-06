#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureData;

typedef struct {
    TemperatureData* data;
    size_t size;
    size_t capacity;
} TemperatureStorage;

// Инициализация/очистка
void init_storage(TemperatureStorage* storage);
void free_storage(TemperatureStorage* storage);

// Основные операции
bool add_record(TemperatureStorage* storage, const TemperatureData* record);
bool delete_record(TemperatureStorage* storage, size_t index);
void sort_by_date(TemperatureStorage* storage);
void print_all_records(const TemperatureStorage* storage);

// Статистика
void print_monthly_stats(const TemperatureStorage* storage, uint8_t month);
void print_yearly_stats(const TemperatureStorage* storage);
void print_extended_stats(const TemperatureStorage* storage);
float calculate_monthly_avg(const TemperatureStorage* storage, uint8_t month);
int8_t find_monthly_min(const TemperatureStorage* storage, uint8_t month);
int8_t find_monthly_max(const TemperatureStorage* storage, uint8_t month);
float calculate_yearly_avg(const TemperatureStorage* storage);
int8_t find_yearly_min(const TemperatureStorage* storage);
int8_t find_yearly_max(const TemperatureStorage* storage);

bool parse_csv_line(const char* line, TemperatureData* record);
bool load_from_csv(TemperatureStorage* storage, const char* filename);

#endif 