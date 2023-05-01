# CS5103Project - RAJ PATEL - sgs391

## Program Description

This C++ program takes a date and time in the Central Standard Time (CST) zone and converts it to Eastern Standard Time (EST). The program prompts the user for the date and time in the format "YYYY-MM-DD HH:MM:SS", and also asks if Daylight Saving Time (DST) is active. If DST is active, the program asks for the DST start and end dates and times.

The program then performs the necessary timezone and DST adjustments and calculates the day of the week for the EST date and time. Finally, the program outputs the converted date and time in EST along with the day of the week.

## Validations

The program includes the following validations to ensure that the input is valid:

1. The year must be between 1900 and 2100 (inclusive).
2. The month must be between 1 and 12 (inclusive).
3. The day must be between 1 and 31 (inclusive).
4. The day must be valid for the given month and year (e.g. February 30 is not a valid date).
5. The hour must be between 0 and 23 (inclusive).
6. The minute must be between 0 and 59 (inclusive).
7. The second must be between 0 and 59 (inclusive).
8. The DST start and end dates and times must be valid.

Note: The program assumes that the input date and time is in the CST timezone. If the input is in a different timezone, the output will not be correct.

## How to Use

1. Clone the repository or download the source code.
2. Compile the program using a C++ compiler (e.g. g++).
3. Run the program from the command line.
4. Enter the date and time in the format "YYYY-MM-DD HH:MM:SS".
5. Enter "Y" or "N" to indicate if DST is active.
6. If DST is active, enter the DST start and end dates and times in the format "MM DD HH".
7. The program will output the converted date and time in EST along with the day of the week.


## Functionality

The program uses the following functions to validate the input and calculate the output:

### `bool is_leap_year(int year)`

This function takes a year as input and returns a boolean value indicating whether it is a leap year.

### `bool is_valid_date(int year, int month, int day)`

This function takes a year, month, and day as input and returns a boolean value indicating whether they form a valid date in the range 1900-2100. It also checks whether the day is valid for the given month and year.

### `bool is_valid_time(int hour, int minute, int second)`

This function takes an hour, minute, and second as input and returns a boolean value indicating whether they form a valid time in the range 00:00:00-23:59:59.

### `int main()`

This function is the entry point of the program. It gets the user input, parses it, validates it, adjusts for DST if necessary, converts it to EST, calculates the day of the week in EST, and outputs the result.

## Example output

```
Enter date and time in CST format (YYYY-MM-DD HH:MM:SS): 2023-05-01 12:00:00
Is Daylight Saving Time active? (Y/N): Y
Enter the Daylight Saving starting date and time in CST format (MM DD HH): 03 13 02
Enter the Daylight Saving ending date and time in CST format (MM DD HH): 11 06 02
The date and time in EST is: Monday, 2023-05-01 14:00:00
```

In this example, the input is `2023-05-01 12:00:00` in CST format, and DST is active with starting date `03-13` and ending date `11-06`. The output is `Monday, 2023-05-01 14:00:00` in EST format, and the corresponding day of the week in EST is `Monday`.
