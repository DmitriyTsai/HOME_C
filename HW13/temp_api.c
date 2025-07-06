#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* init_list() {
    return NULL;
}

void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

bool add_record(Node** head, TemperatureData new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return false;
    
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
    return true;
}

bool remove_record(Node** head, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute) {
    Node *current = *head, *prev = NULL;
    
    while (current != NULL) {
        if (current->data.year == year &&
            current->data.month == month &&
            current->data.day == day &&
            current->data.hour == hour &&
            current->data.minute == minute) {
            
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

int compare_records(const TemperatureData* a, const TemperatureData* b) {
    if (a->year != b->year) return a->year - b->year;
    if (a->month != b->month) return a->month - b->month;
    if (a->day != b->day) return a->day - b->day;
    if (a->hour != b->hour) return a->hour - b->hour;
    return a->minute - b->minute;
}

void sort_list(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    bool swapped;
    Node *ptr1, *lptr = NULL;
    
    do {
        swapped = false;
        ptr1 = *head;
        
        while (ptr1->next != lptr) {
            if (compare_records(&ptr1->data, &ptr1->next->data) > 0) {
                TemperatureData temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

size_t get_list_size(Node* head) {
    size_t count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void print_month_stats(Node* head, uint8_t month) {
    int count = 0;
    int sum = 0;
    int8_t min_temp = 99;
    int8_t max_temp = -99;
    
    Node* current = head;
    while (current != NULL) {
        if (current->data.month == month) {
            sum += current->data.temperature;
            count++;
            
            if (current->data.temperature < min_temp)
                min_temp = current->data.temperature;
            if (current->data.temperature > max_temp)
                max_temp = current->data.temperature;
        }
        current = current->next;
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

void print_year_stats(Node* head) {
    if (head == NULL) {
        printf("No data available\n");
        return;
    }
    
    int sum = 0;
    size_t count = 0;
    int8_t min_temp = 99;
    int8_t max_temp = -99;
    uint16_t year = head->data.year;
    
    Node* current = head;
    while (current != NULL) {
        sum += current->data.temperature;
        count++;
        
        if (current->data.temperature < min_temp)
            min_temp = current->data.temperature;
        if (current->data.temperature > max_temp)
            max_temp = current->data.temperature;
        
        current = current->next;
    }
    
    printf("Year %d statistics:\n", year);
    printf("  Records count: %zu\n", count);
    printf("  Average temperature: %.2f°C\n", (float)sum / count);
    printf("  Min temperature: %d°C\n", min_temp);
    printf("  Max temperature: %d°C\n", max_temp);
}

Node* load_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;
    
    Node* head = NULL;
    char line[100];
    
    while (fgets(line, sizeof(line), file)) {
        TemperatureData record;
        if (sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                  &record.year, &record.month, &record.day,
                  &record.hour, &record.minute, &record.temperature) == 6) {
            add_record(&head, record);
        }
    }
    
    fclose(file);
    return head;
}

bool save_csv(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) return false;
    
    Node* current = head;
    while (current != NULL) {
        fprintf(file, "%d;%d;%d;%d;%d;%d\n",
                current->data.year, current->data.month, current->data.day,
                current->data.hour, current->data.minute, current->data.temperature);
        current = current->next;
    }
    
    fclose(file);
    return true;
}

void print_list(Node* head) {
    printf("%-6s %-6s %-6s %-6s %-8s %-12s\n", 
           "Year", "Month", "Day", "Hour", "Minute", "Temperature");
    
    Node* current = head;
    while (current != NULL) {
        printf("%-6d %-6d %-6d %-6d %-8d %-12d\n",
               current->data.year, current->data.month, current->data.day,
               current->data.hour, current->data.minute, current->data.temperature);
        current = current->next;
    }
}

TemperatureData create_record(uint16_t y, uint8_t m, uint8_t d, uint8_t h, uint8_t min, int8_t temp) {
    TemperatureData record = {y, m, d, h, min, temp};
    return record;
}