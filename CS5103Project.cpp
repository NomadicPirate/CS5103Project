// CS5103Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//RAJ PATEL : SGS391

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
using namespace std;
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int year)
{
    // Return true if year 
    // is a multiple of 4 and
    // not multiple of 100.
    // OR year is multiple of 400.
    return (((year % 4 == 0) &&
        (year % 100 != 0)) ||
        (year % 400 == 0));
}
bool isValidDate(int d, int m, int y)
{
    // If year, month and day 
    // are not in given range
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    // Handle February month 
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    // Months of April, June, 
    // Sept and Nov must have 
    // number of days less than
    // or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}
bool isValidTime(int hr, int min)
{
    if (hr >= 0 && hr < 24 && min >= 0 && min < 60)
    {
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{


    
    int options = 0;
    cout << "RAJ PATEL - sgs391 - CS5103Project - Milestone1";
    cout << "***** Enter the details asked below ***** \n Date Format: mm/dd/yyy \t Time Format 24 hour clock: hh:mm\n\n";
    while (options != 5)
    {
        string date;
        bool dateVal = false;
        int year=0, month=0, day=0;

        cout << "Please enter your choice \n1. CST -> EST \n2. PST -> EST \n3. EXIT \nINPUT: ";
        cin >> options;
        if (options == 3)
        {
            exit(0);
        }
        else if (options != 3 && options !=2 && options!=1)
        {
            cout<<"Enter Valid Input Options.!!\n";
            break;
        }

        do {
            cout << "Enter DATE you want to convert:(mm/dd/yyyy): ";
            cin >> date; // date can be 2005:03:09 or 2005/04/02 or whatever
            stringstream ss(date);
            char ch;
            ss >> month >> ch >> day >> ch >> year;
            if (!isValidDate(day, month, year))
            {
                cout << "Please enter VALID DATE" << endl;
            }

        } while (!isValidDate(day, month, year));

        string time;
        int hr=0, min=0;
        
        do {
            cout << "Enter TIME you want to convert: ";
            cin >> time;
            stringstream sa(time);
            char ch1;
            sa >> hr >> ch1 >> min;
            if (!isValidTime(hr, min))
            {
                cout << "Please enter VALID TIME" << endl;
            }
        } while (!isValidTime(hr, min));
        cout << endl;
        cout << "Your DATE: " << month << "/" << day << "/" << year << endl;
        cout << "Your TIME: " << hr << ":" << min << endl;
        
        int conyear = year, conmonth = month, conday = day;
        int conhr = hr, conmin = min;
        if (options == 1)
        {
            conhr = hr + 1;
            conmin = min;

            if (conhr > 23) {
                conhr = conhr - 24;
                conday = conday + 1; // if (m == 4 || m == 6 || m == 9 || m == 11)
                if (conday > 30 && (conmonth == 4 || conmonth == 6 || conmonth == 9 || conmonth == 11))
                {
                    conday = conday - 30;
                        conmonth = conmonth + 1;
                }
                else if (conday > 31 && (conmonth == 1 || conmonth == 3 || conmonth == 5 || conmonth == 7 || conmonth == 8 || conmonth == 10))
                {
                    conday = conday - 31;
                    conmonth = conmonth + 1;
                }
                else if (conday > 31 && conmonth == 12)
                {
                    conday = conday - 31;
                    conmonth = 1;
                    conyear = conyear + 1;
                }
                else if (isLeap(conyear) && conday > 29 && conmonth == 2)
                {
                    conday = conday - 29;
                    conmonth = conmonth + 1 ;
                }
                else if (!isLeap(conyear) && conday > 28 && conmonth == 2)
                {
                    conday = conday - 28;
                    conmonth = conmonth + 1;
                }
           }
        }
        if (options == 2)
        {
            conhr = hr + 3;
            conmin = min;

            if (conhr > 23) {
                conhr = conhr - 24;
                conday = conday + 1; // if (m == 4 || m == 6 || m == 9 || m == 11)
                if (conday > 30 && (conmonth == 4 || conmonth == 6 || conmonth == 9 || conmonth == 11))
                {
                    conday = conday - 30;
                    conmonth = conmonth + 1;
                }
                else if (conday > 31 && (conmonth == 1 || conmonth == 3 || conmonth == 5 || conmonth == 7 || conmonth == 8 || conmonth == 10))
                {
                    conday = conday - 31;
                    conmonth = conmonth + 1;
                }
                else if (conday > 31 && conmonth == 12)
                {
                    conday = conday - 31;
                    conmonth = 1;
                    conyear = conyear + 1;
                }
                else if (isLeap(conyear) && conday > 29 && conmonth == 2)
                {
                    conday = conday - 29;
                    conmonth = conmonth + 1;
                }
                else if (!isLeap(conyear) && conday > 28 && conmonth == 2)
                {
                    conday = conday - 28;
                    conmonth = conmonth + 1;
                }
            }
        }
        cout << "CONVERTED DATE: " << conmonth << "/" << conday << "/" << conyear << endl;
        cout << "CONVERTED TIME: " << conhr << ":" << conmin << endl<<endl;
        
    }
    

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
