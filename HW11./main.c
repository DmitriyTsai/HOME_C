#include "temp_api.h"
#include <stdio.h>

int main() {
    TemperatureData records[MAX_RECORDS];
    int record_count = 0;

    records[0] = (TemperatureData){2025, 1, 15, 12, 30, -5};
    records[1] = (TemperatureData){2025, 1, 15, 18, 45, -8};
    records[2] = (TemperatureData){2025, 2, 20, 9, 15, 10};
    records[3] = (TemperatureData){2025, 2, 21, 15, 20, 12};
    record_count = 4;

    for (int month = 1; month <= 12; month++) {
        print_month_stats(records, record_count, month);
    }

    print_year_stats(records, record_count);

    return 0;
}