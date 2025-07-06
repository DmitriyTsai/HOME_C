#include "temp_api.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_month_stats(const TemperatureData *data, int size, uint8_t month) {
    int count = 0;
    int sum = 0;
    int8_t min_temp = 99;
    int8_t max_temp = -99;

    for (int i = 0; i < size; i++) {
        if (data[i].month == month) {
            sum += data[i].temperature;
            count++;

            if (data[i].temperature < min_temp)
                min_temp = data[i].temperature;
            if (data[i].temperature > max_temp)
                max_temp = data[i].temperature;
        }
    }

    if (count > 0) {
        printf("Month %02d statistics:\n", month);
        printf("  Records count: %d\n", count);
        printf("  Average temperature: %.2f°C\n", (float)sum / count);
        printf("  Min temperature: %d°C\n", min_temp);
        printf("  Max temperature: %d°C\n", max_temp);
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

        if (data[i].temperature < min_temp)
            min_temp = data[i].temperature;
        if (data[i].temperature > max_temp)
            max_temp = data[i].temperature;
    }

    printf("Year %d statistics:\n", year);
    printf("  Records count: %d\n", size);
    printf("  Average temperature: %.2f°C\n", (float)sum / size);
    printf("  Min temperature: %d°C\n", min_temp);
    printf("  Max temperature: %d°C\n", max_temp);
}

int add_record(TemperatureData *data, int *size, TemperatureData new_record) {
    if (*size >= MAX_RECORDS)
        return 0;
    
    data[*size] = new_record;
    (*size)++;
    return 1;
}

int remove_record(TemperatureData *data, int *size, int index) {
    if (index < 0 || index >= *size)
        return 0;
    
    for (int i = index; i < *size - 1; i++)
        data[i] = data[i + 1];
    
    (*size)--;
    return 1;
}

int compare_records(const void *a, const void *b) {
    const TemperatureData *ta = a;
    const TemperatureData *tb = b;
    
    if (ta->year != tb->year) return ta->year - tb->year;
    if (ta->month != tb->month) return ta->month - tb->month;
    if (ta->day != tb->day) return ta->day - tb->day;
    if (ta->hour != tb->hour) return ta->hour - tb->hour;
    return ta->minute - tb->minute;
}

void sort_records(TemperatureData *data, int size) {
    qsort(data, size, sizeof(TemperatureData), compare_records);
}

void print_records(const TemperatureData *data, int size) {
    printf("%-6s %-6s %-6s %-6s %-8s %-12s\n", 
           "Year", "Month", "Day", "Hour", "Minute", "Temperature");
    for (int i = 0; i < size; i++) {
        printf("%-6d %-6d %-6d %-6d %-8d %-12d\n",
               data[i].year, data[i].month, data[i].day,
               data[i].hour, data[i].minute, data[i].temperature);
    }
}

int load_csv(TemperatureData *data, int *size, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;
    
    char line[100];
    *size = 0;
    
    while (fgets(line, sizeof(line), file) && *size < MAX_RECORDS) {
        TemperatureData record;
        if (sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                  &record.year, &record.month, &record.day,
                  &record.hour, &record.minute, &record.temperature) == 6) {
            data[(*size)++] = record;
        }
    }
    
    fclose(file);
    return 1;
}

int save_csv(const TemperatureData *data, int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return 0;
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d;%d;%d;%d;%d;%d\n",
                data[i].year, data[i].month, data[i].day,
                data[i].hour, data[i].minute, data[i].temperature);
    }
    
    fclose(file);
    return 1;
}