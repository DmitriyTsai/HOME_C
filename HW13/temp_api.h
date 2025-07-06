#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureData;

typedef struct Node {
    TemperatureData data;
    struct Node* next;
} Node;

// Инициализация и очистка
Node* init_list();
void free_list(Node* head);

// Основные операции
bool add_record(Node** head, TemperatureData new_data);
bool remove_record(Node** head, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute);
void sort_list(Node** head);
size_t get_list_size(Node* head);

// Функции статистики
void print_month_stats(Node* head, uint8_t month);
void print_year_stats(Node* head);

// Ввод/вывод
Node* load_csv(const char* filename);
bool save_csv(Node* head, const char* filename);

// Вспомогательные функции
void print_list(Node* head);
TemperatureData create_record(uint16_t y, uint8_t m, uint8_t d, uint8_t h, uint8_t min, int8_t temp);

#endif