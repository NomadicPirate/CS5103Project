# CS5103Project - RAJ PATEL - sgs391
This program takes a date and time in the format "YYYY-MM-DD HH:MM:SS" and converts it from Central Standard Time (CST) to Eastern Standard Time (EST).

### Usage
Run the program in a C++ compiler.
Enter the date and time in the format "YYYY-MM-DD HH:MM:SS".
The program will output the converted date and time in the format "YYYY-MM-DD HH:MM:SS" in Eastern Standard Time (EST).


### Validations
The program performs the following validations:
<li> The year must be between 1900 and 2100. </li>
<li> The month must be between 1 and 12.</li>
<li>The day must be a valid day for the given month and year.</li>
<li>The hour must be between 0 and 23.</li>
<li>The minute must be between 0 and 59.</li>
<li>The second must be between 0 and 59.</li>
<li>If any of these validations fail, the program will output an "Invalid" message.</li>


### Test Cases
The program has been tested with the following valid and invalid test cases:

### Valid Test Cases:

"2023-04-02 11:30:00" (normal case)<br>
"1904-02-29 23:00:00" (leap year)<br>
"2100-12-31 23:59:59" (end of century)<br>

### Invalid Test Cases:

"2023-04-31 11:30:00" (invalid day for the given month and year)<br>
"2023-13-01 11:30:00" (invalid month)<br>
"2023-04-02 24:00:00" (invalid hour)<br>
"2023-04-02 11:60:00" (invalid minute)<br>
"2023-04-02 11:30:60" (invalid second)<br>
"1899-12-31 23:59:59" (year before 1900)<br>
"2101-01-01 00:00:00" (year after 2100)<br>
"2023-02-29 11:30:00" (not a leap year)<br>
