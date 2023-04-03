// CS5103Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//RAJ PATEL : SGS391

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool is_valid_date(int year, int month, int day) {
    if (year < 1900 || year > 2100) {
        cout << "Invalid year.\n";
        return false;
    }
    if (month < 1 || month > 12) {
        cout << "Invalid month.\n";
        return false;
    }
    if (day < 1 || day > 31) {
        cout << "Invalid day.\n";
        return false;
    }

    int max_days = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_days = 30;
    }
    else if (month == 2) {
        max_days = is_leap_year(year) ? 29 : 28;
    }

    if (day > max_days) {
        cout << "Invalid day for the given month and year.\n";
        return false;
    }

    return true;
}

bool is_valid_time(int hour, int minute, int second) {
    if (hour < 0 || hour >= 24) {
        cout << "Invalid hour.\n";
        return false;
    }
    if (minute < 0 || minute >= 60) {
        cout << "Invalid minute.\n";
        return false;
    }
    if (second < 0 || second >= 60) {
        cout << "Invalid second.\n";
        return false;
    }

    return true;
}

int main() {
    // Get user input
    cout << "Enter date and time in CST format (YYYY-MM-DD HH:MM:SS): ";
    string cst_time_str;
    getline(cin, cst_time_str);

    // Parse input string
    int year, month, day, hour, minute, second;
    if (sscanf_s(cst_time_str.c_str(), "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) != 6) {
        cout << "Invalid date and time format.\n";
        return 1;
    }

    // Validate date and time
    if (!is_valid_date(year, month, day)) {
        return 1;
    }
    if (!is_valid_time(hour, minute, second)) {
        return 1;
    }

    // Convert to EST
    hour += 1; // Add one hour for time zone difference
    if (hour >= 24) { // Adjust for rollover to next day
        hour -= 24;
        day += 1;
        if (!is_valid_date(year, month, day)) { // Check if the new date is valid
            if (month == 12) { // If it's the last day of December, rollover to next year
                year += 1;
                month = 1;
                day = 1;
            }
            else { // Otherwise, rollover to next month
                month += 1;
                day = 1;
            }
            if (!is_valid_date(year, month, day)) { // Check if the new date is valid
                return 1;
            }
        }
    }
    // Calculate day

    // Calculate day of the week
    tm timeinfo = { 0 };
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = second;
    time_t rawtime = mktime(&timeinfo);
    tm localtime = { 0 };
    localtime_s(&localtime, &rawtime);
    char day_str[10];
    strftime(day_str, 10, "%A", &localtime);

    // Print result
    printf("The date and time in EST is: %s, %04d-%02d-%02d %02d:%02d:%02d\n", day_str, year, month, day, hour, minute, second);

    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
