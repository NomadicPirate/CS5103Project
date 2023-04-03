# CS5103Project - RAJ PATEL - sgs391
The program will take user input of a date and time in the format "YYYY-MM-DD HH:MM:SS" and convert it from Central Standard Time (CST) to Eastern Standard Time (EST). If the input is valid, the program will output the converted date and time in the format "YYYY-MM-DD HH:MM:SS" in Eastern Standard Time (EST). If the input is invalid, the program will output an "Invalid" message with a brief explanation of the invalid input.
<br>
The program also includes validations to ensure that the input follows certain rules, such as the year being between 1900 and 2100, the month being between 1 and 12, and the day being valid for the given month and year. If any of these validations fail, the program will output an "Invalid" message with a brief explanation of the invalid input.
<br><hr>
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

### Outputs

Valid Test Cases:
"2023-04-02 11:30:00" (CST) -> "2023-04-02 12:30:00" (EST)<br>
"1904-02-29 23:00:00" (CST) -> "1904-03-01 00:00:00" (EST)<br>
"2100-12-31 23:59:59" (CST) -> "2101-01-01 00:59:59" (EST)<br>

Invalid Test Cases:
"2023-04-31 11:30:00" -> "Invalid date"<br>
"2023-13-01 11:30:00" -> "Invalid date"<br>
"2023-04-02 24:00:00" -> "Invalid time"<br>
"2023-04-02 11:60:00" -> "Invalid time"<br>
"2023-04-02 11:30:60" -> "Invalid time"<br>
"1899-12-31 23:59:59" -> "Invalid year"<br>
"2101-01-01 00:00:00" -> "Invalid year"<br>
"2023-02-29 11:30:00" -> "Invalid date"<br>

Updated the previous code using the <ctime> header file as well as updated regarding the requirement changes. Added a few more test cases then last time and made changes as per the assignment requirements.
