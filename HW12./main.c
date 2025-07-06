#include "temp_api.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>  

void print_help() {
    printf("Temperature Statistics Application\n");
    printf("Usage: ./temp_app [options]\n");
    printf("Options:\n");
    printf("  -h          Show this help message\n");
    printf("  -f <file>   Input CSV file to process\n");
    printf("  -m <month>  Show statistics for specific month (1-12)\n");
    printf("  -y          Show year statistics only\n");
    printf("  -p          Print all records\n");
    printf("  -s          Sort records by date/time\n");
    printf("\nCSV format: Year;Month;Day;Hour;Minute;Temperature\n");
}

int main(int argc, char *argv[]) {
    TemperatureData records[MAX_RECORDS];
    int record_count = 0;
    char *filename = NULL;
    int month = 0;
    int year_only = 0;
    int print_all = 0;
    int sort_rec = 0;

    // Parse command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "hf:m:yps")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month = atoi(optarg);
                if (month < 1 || month > 12) {
                    fprintf(stderr, "Invalid month. Must be between 1 and 12.\n");
                    return 1;
                }
                break;
            case 'y':
                year_only = 1;
                break;
            case 'p':
                print_all = 1;
                break;
            case 's':
                sort_rec = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                return 1;
        }
    }

    // Load data from file
    if (filename) {
        if (!load_csv(records, &record_count, filename)) {
            fprintf(stderr, "Failed to load data from %s\n", filename);
            return 1;
        }
        printf("Loaded %d records from %s\n", record_count, filename);
    } else {
        fprintf(stderr, "No input file specified. Use -f option.\n");
        print_help();
        return 1;
    }

    // Sort if requested
    if (sort_rec) {
        sort_records(records, record_count);
        printf("Records sorted by date/time\n");
    }

    // Print all records if requested
    if (print_all) {
        printf("\nAll temperature records:\n");
        print_records(records, record_count);
    }

    // Show statistics
    if (month > 0) {
        print_month_stats(records, record_count, month);
    } else if (year_only) {
        print_year_stats(records, record_count);
    } else {
        // Show all months and year statistics
        print_year_stats(records, record_count);
        printf("\nMonthly statistics:\n");
        for (int m = 1; m <= 12; m++) {
            print_month_stats(records, record_count, m);
        }
    }

    return 0;
}