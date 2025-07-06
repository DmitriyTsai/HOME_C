#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_help() {
    printf("Temperature Statistics Application (Dynamic List Version)\n");
    printf("Usage: ./temp_app [options]\n");
    printf("Options:\n");
    printf("  -h          Show this help message\n");
    printf("  -f <file>   Input CSV file to process\n");
    printf("  -m <month>  Show statistics for specific month (1-12)\n");
    printf("  -y          Show year statistics only\n");
    printf("  -p          Print all records\n");
    printf("  -s          Sort records by date/time\n");
    printf("  -a          Add new record (format: YYYY MM DD HH MM TEMP)\n");
    printf("  -d          Delete record (format: YYYY MM DD HH MM)\n");
    printf("\nCSV format: Year;Month;Day;Hour;Minute;Temperature\n");
}

int main(int argc, char *argv[]) {
    Node* head = init_list();
    char* filename = NULL;
    int month = 0;
    bool year_only = false;
    bool print_all = false;
    bool sort_rec = false;
    bool add_rec = false;
    bool del_rec = false;
    int add_args[6];
    int del_args[5];

    // Parse command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "hf:m:ypsa:d:")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                free_list(head);
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month = atoi(optarg);
                if (month < 1 || month > 12) {
                    fprintf(stderr, "Invalid month. Must be between 1 and 12.\n");
                    free_list(head);
                    return 1;
                }
                break;
            case 'y':
                year_only = true;
                break;
            case 'p':
                print_all = true;
                break;
            case 's':
                sort_rec = true;
                break;
            case 'a':
                add_rec = true;
                if (sscanf(optarg, "%d %d %d %d %d %d", 
                           &add_args[0], &add_args[1], &add_args[2],
                           &add_args[3], &add_args[4], &add_args[5]) != 6) {
                    fprintf(stderr, "Invalid add format. Use: YYYY MM DD HH MM TEMP\n");
                    free_list(head);
                    return 1;
                }
                break;
            case 'd':
                del_rec = true;
                if (sscanf(optarg, "%d %d %d %d %d", 
                           &del_args[0], &del_args[1], &del_args[2],
                           &del_args[3], &del_args[4]) != 5) {
                    fprintf(stderr, "Invalid delete format. Use: YYYY MM DD HH MM\n");
                    free_list(head);
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Unknown option: %c\n", opt);
                print_help();
                free_list(head);
                return 1;
        }
    }

    // Load data from file
    if (filename) {
        head = load_csv(filename);
        if (!head) {
            fprintf(stderr, "Failed to load data from %s\n", filename);
            return 1;
        }
        printf("Loaded %zu records from %s\n", get_list_size(head), filename);
    } else {
        fprintf(stderr, "No input file specified. Use -f option.\n");
        print_help();
        free_list(head);
        return 1;
    }

    // Add record if requested
    if (add_rec) {
        TemperatureData new_rec = create_record(
            add_args[0], add_args[1], add_args[2],
            add_args[3], add_args[4], add_args[5]);
        
        if (add_record(&head, new_rec)) {
            printf("Record added successfully\n");
        } else {
            fprintf(stderr, "Failed to add record\n");
        }
    }

    // Delete record if requested
    if (del_rec) {
        if (remove_record(&head, del_args[0], del_args[1], del_args[2],
                         del_args[3], del_args[4])) {
            printf("Record deleted successfully\n");
        } else {
            fprintf(stderr, "Record not found\n");
        }
    }

    // Sort if requested
    if (sort_rec) {
        sort_list(&head);
        printf("Records sorted by date/time\n");
    }

    // Print all records if requested
    if (print_all) {
        printf("\nAll temperature records:\n");
        print_list(head);
    }

    // Show statistics
    if (month > 0) {
        print_month_stats(head, month);
    } else if (year_only) {
        print_year_stats(head);
    } else {
        print_year_stats(head);
        printf("\nMonthly statistics:\n");
        for (int m = 1; m <= 12; m++) {
            print_month_stats(head, m);
        }
    }

    // Save changes back to file if modified
    if (add_rec || del_rec || sort_rec) {
        if (save_csv(head, filename)) {
            printf("\nChanges saved to %s\n", filename);
        } else {
            fprintf(stderr, "Failed to save changes to file\n");
        }
    }

    free_list(head);
    return 0;
}