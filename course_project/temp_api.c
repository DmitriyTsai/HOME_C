#include "temp_api.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define INITIAL_CAPACITY 100
#define GROWTH_FACTOR 2

void init_storage(TemperatureStorage* storage) {
    storage->data = malloc(INITIAL_CAPACITY * sizeof(TemperatureData));
    storage->size = 0;
    storage->capacity = INITIAL_CAPACITY;
}

void free_storage(TemperatureStorage* storage) {
    free(storage->data);
    storage->data = NULL;
    storage->size = 0;
    storage->capacity = 0;
}

bool add_record(TemperatureStorage* storage, const TemperatureData* record) {
    if (storage->size >= storage->capacity) {
        size_t new_capacity = storage->capacity * GROWTH_FACTOR;
        TemperatureData* new_data = realloc(storage->data, new_capacity * sizeof(TemperatureData));
        if (!new_data) return false;
        
        storage->data = new_data;
        storage->capacity = new_capacity;
    }
    
    storage->data[storage->size++] = *record;
    return true;
}

bool delete_record(TemperatureStorage* storage, size_t index) {
    if (index >= storage->size) return false;
    
    for (size_t i = index; i < storage->size - 1; i++) {
        storage->data[i] = storage->data[i + 1];
    }
    
    storage->size--;
    return true;
}

int compare_dates(const void* a, const void* b) {
    const TemperatureData* ta = (const TemperatureData*)a;
    const TemperatureData* tb = (const TemperatureData*)b;
    
    if (ta->year != tb->year) return ta->year - tb->year;
    if (ta->month != tb->month) return ta->month - tb->month;
    if (ta->day != tb->day) return ta->day - tb->day;
    if (ta->hour != tb->hour) return ta->hour - tb->hour;
    return ta->minute - tb->minute;
}

void sort_by_date(TemperatureStorage* storage) {
    qsort(storage->data, storage->size, sizeof(TemperatureData), compare_dates);
}

void print_all_records(const TemperatureStorage* storage) {
    printf("\nAll temperature records:\n");
    printf("Date       Time  Temperature\n");
    printf("----------------------------\n");
    
    for (size_t i = 0; i < storage->size; i++) {
        const TemperatureData* d = &storage->data[i];
        printf("%04d-%02d-%02d %02d:%02d %3d°C\n", 
               d->year, d->month, d->day, d->hour, d->minute, d->temperature);
    }
}

bool parse_csv_line(const char* line, TemperatureData* record) {
    if (!line || !record) return false;
    
    const char* p = line;
    char* endptr;
    
    // Парсим год
    record->year = (uint16_t)strtoul(p, &endptr, 10);
    if (endptr == p || *endptr != ';') return false;
    p = endptr + 1;
    while (isspace(*p)) p++;
    
    // Парсим месяц
    record->month = (uint8_t)strtoul(p, &endptr, 10);
    if (endptr == p || *endptr != ';') return false;
    p = endptr + 1;
    while (isspace(*p)) p++;
    
    // Парсим день
    record->day = (uint8_t)strtoul(p, &endptr, 10);
    if (endptr == p || *endptr != ';') return false;
    p = endptr + 1;
    while (isspace(*p)) p++;
    
    // Парсим часы
    record->hour = (uint8_t)strtoul(p, &endptr, 10);
    if (endptr == p || *endptr != ';') return false;
    p = endptr + 1;
    while (isspace(*p)) p++;
    
    // Парсим минуты
    record->minute = (uint8_t)strtoul(p, &endptr, 10);
    if (endptr == p || *endptr != ';') return false;
    p = endptr + 1;
    while (isspace(*p)) p++;
    
    // Парсим температуру
    record->temperature = (int8_t)strtol(p, &endptr, 10);
    if (endptr == p) return false;
    
    // Валидация значений
    if (record->month < 1 || record->month > 12) return false;
    if (record->day < 1 || record->day > 31) return false;
    if (record->hour > 23) return false;
    if (record->minute > 59) return false;
    if (record->temperature < -99 || record->temperature > 99) return false;
    
    return true;
}

bool load_from_csv(TemperatureStorage* storage, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return false;
    }
    
    char line[256];
    size_t line_num = 0;
    size_t records_added = 0;
    
    while (fgets(line, sizeof(line), file)) {
        line_num++;
        if (line[0] == '\n' || line[0] == '#') continue;
        
        TemperatureData record;
        if (parse_csv_line(line, &record)) {
            if (add_record(storage, &record)) {
                records_added++;
            } else {
                fprintf(stderr, "Memory allocation failed at line %zu\n", line_num);
            }
        } else {
            fprintf(stderr, "Invalid data format at line %zu: %s", line_num, line);
        }
    }
    
    fclose(file);
    printf("Successfully loaded %zu records from %s\n", records_added, filename);
    return records_added > 0;
}

void print_extended_stats(const TemperatureStorage* storage) {
    printf("\nExtended Statistics:\n");
    printf("Total records: %zu\n", storage->size);
    
    int8_t abs_min = 99, abs_max = -99;
    float sum = 0;
    
    for (size_t i = 0; i < storage->size; i++) {
        int8_t temp = storage->data[i].temperature;
        sum += temp;
        if (temp < abs_min) abs_min = temp;
        if (temp > abs_max) abs_max = temp;
    }
    
    printf("Absolute minimum: %d°C\n", abs_min);
    printf("Absolute maximum: %d°C\n", abs_max);
    printf("Overall average: %.2f°C\n", sum / storage->size);
}

// Реализации статистических функций
float calculate_monthly_avg(const TemperatureStorage* storage, uint8_t month) {
    int sum = 0;
    int count = 0;
    
    for (size_t i = 0; i < storage->size; i++) {
        if (storage->data[i].month == month) {
            sum += storage->data[i].temperature;
            count++;
        }
    }
    
    return count > 0 ? (float)sum / count : 0.0f;
}

int8_t find_monthly_min(const TemperatureStorage* storage, uint8_t month) {
    int8_t min = 99;
    
    for (size_t i = 0; i < storage->size; i++) {
        if (storage->data[i].month == month && storage->data[i].temperature < min) {
            min = storage->data[i].temperature;
        }
    }
    
    return min;
}

int8_t find_monthly_max(const TemperatureStorage* storage, uint8_t month) {
    int8_t max = -99;
    
    for (size_t i = 0; i < storage->size; i++) {
        if (storage->data[i].month == month && storage->data[i].temperature > max) {
            max = storage->data[i].temperature;
        }
    }
    
    return max;
}

float calculate_yearly_avg(const TemperatureStorage* storage) {
    int sum = 0;
    
    for (size_t i = 0; i < storage->size; i++) {
        sum += storage->data[i].temperature;
    }
    
    return storage->size > 0 ? (float)sum / storage->size : 0.0f;
}

int8_t find_yearly_min(const TemperatureStorage* storage) {
    int8_t min = 99;
    
    for (size_t i = 0; i < storage->size; i++) {
        if (storage->data[i].temperature < min) {
            min = storage->data[i].temperature;
        }
    }
    
    return min;
}

int8_t find_yearly_max(const TemperatureStorage* storage) {
    int8_t max = -99;
    
    for (size_t i = 0; i < storage->size; i++) {
        if (storage->data[i].temperature > max) {
            max = storage->data[i].temperature;
        }
    }
    
    return max;
}

void print_monthly_stats(const TemperatureStorage* storage, uint8_t month) {
    printf("\nMonthly statistics for month %d:\n", month);
    printf("  Average temperature: %.2f°C\n", calculate_monthly_avg(storage, month));
    printf("  Minimum temperature: %d°C\n", find_monthly_min(storage, month));
    printf("  Maximum temperature: %d°C\n", find_monthly_max(storage, month));
    printf("  Records count: %zu\n", storage->size);
}

void print_yearly_stats(const TemperatureStorage* storage) {
    printf("\nYearly statistics:\n");
    printf("  Average temperature: %.2f°C\n", calculate_yearly_avg(storage));
    printf("  Minimum temperature: %d°C\n", find_yearly_min(storage));
    printf("  Maximum temperature: %d°C\n", find_yearly_max(storage));
    printf("  Total records: %zu\n", storage->size);
}