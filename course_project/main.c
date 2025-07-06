#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "temp_api.h"

void print_help(const char* program_name) {
    printf("Temperature Data Processor\n");
    printf("Usage: %s [OPTIONS]\n", program_name);
    printf("Options:\n");
    printf("  -h          Show this help message\n");
    printf("  -f FILE     Input CSV file with temperature data (required)\n");
    printf("  -m MONTH    Process data only for specified month (1-12)\n");
    printf("  -s          Sort data by date\n");
    printf("  -p          Print all temperature records\n");
    printf("\nCSV format: year;month;day;hour;minute;temperature\n");
}

int main(int argc, char* argv[]) {
    TemperatureStorage storage;
    init_storage(&storage);
    
    char* filename = NULL;
    int month = 0;
    bool sort_flag = false;
    bool print_flag = false;
    int opt;
    
    while ((opt = getopt(argc, argv, "hf:m:sp")) != -1) {
        switch (opt) {
            case 'h':
                print_help(argv[0]);
                free_storage(&storage);
                return EXIT_SUCCESS;
            case 'f':
                filename = strdup(optarg);
                break;
            case 'm':
                month = atoi(optarg);
                if (month < 1 || month > 12) {
                    fprintf(stderr, "Error: Month must be between 1 and 12\n");
                    free_storage(&storage);
                    return EXIT_FAILURE;
                }
                break;
            case 's':
                sort_flag = true;
                break;
            case 'p':
                print_flag = true;
                break;
            default:
                print_help(argv[0]);
                free_storage(&storage);
                return EXIT_FAILURE;
        }
    }
    
    if (!filename) {
        fprintf(stderr, "Error: No input file specified. Use -f option.\n");
        print_help(argv[0]);
        free_storage(&storage);
        return EXIT_FAILURE;
    }
    
    if (!load_from_csv(&storage, filename)) {
        fprintf(stderr, "Error: Failed to process file '%s'\n", filename);
        free(filename);
        free_storage(&storage);
        return EXIT_FAILURE;
    }
    
    free(filename);
    
    if (storage.size == 0) {
        fprintf(stderr, "Error: No valid records found in the file\n");
        free_storage(&storage);
        return EXIT_FAILURE;
    }
    
    if (sort_flag) {
        sort_by_date(&storage);
        printf("Data sorted by date.\n");
    }
    
    if (print_flag) {
        print_all_records(&storage);
    }
    
    if (month > 0) {
        print_monthly_stats(&storage, month);
        print_extended_stats(&storage);
    } else {
        for (int m = 1; m <= 12; m++) {
            print_monthly_stats(&storage, m);
        }
        print_yearly_stats(&storage);
        print_extended_stats(&storage);
    }
    
    free_storage(&storage);
    return EXIT_SUCCESS;
}