/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Antonio Todorov Gatovski
* @idnumber 6MI0600280
* @task 4
*
*/

#include <iostream>
using namespace std;

bool isLeapYear(int y, int month) {

    if (y <= 1916) {

        if (month < 4) {

            if (y % 4 == 0) return true;
            else return false;
        }
    }

    else {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))  return true;
        else return false;
    }

}

bool isNotValidDate(int year, int month, int day) {

    if (month < 1 || month>12) return true;

    else if (year == 1916 && month == 4 && day >= 1 && day <= 13) return true;
    //check all dates with months with 31 days are valid
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

        if (day < 1 || day > 31) {
            return true;
        }

        else {
            if (year < 1600 || year>2100)  return true;
            else return false;
        }
    }

    //check if the dates in february are valid
    else if (month == 2) {

        if (year < 1600 || year>2100)  return true;

        else {

            if (day < 0) return true;

            else if (isLeapYear(year, 2)) {
                if (day > 29) return true;
                else return false;
            }

            else {
                if (day > 28) return true;
                else return false;
            }

        }

    }
    //check all dates with months with 30 days are valid
    else {

        if (day < 1 || day > 30) {
            return true;
        }

        else {
            if (year < 1600 || year>2100)  return true;
            else return false;
        }

    }

}

bool dateBefore(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay) {

    if (endYear> startYear)  return true;

    else if (startYear == endYear) {

        if (endMonth > startMonth) return true;

        else if (startMonth == endMonth) {

            if (endDay > startDay) return true;

        }
    }
     return false;
    
}

void newDate(int& year, int& month, int& day,int daysJump) {

    day += daysJump;
    //if new date after jump is valid return it
    if (isNotValidDate(year, month, day)==false) {
        return;
    }

    //if new date after jump is not valid
    else {
        if (year == 1916 && month == 3) {
            day -= 31;
            day += 13;
            month = 4;
        }
        //if it is in month with 31 days
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

            day -= 31;
            month++;

            if (month > 12) {
                month -= 12;
                year++;
            }

            else if (year == 1916 && month == 3) {
                day = 14;
                month = 4;
            }

            if (year > 2100) {
                year = 2100;
                month = 12;
                day = 31;
            }

        }
        //if it is in fabruary
        else if (month == 2) {

            if (isLeapYear(year, 2)) {
                day -= 29;
                month++;
            }
            else {
                day -= 28;
                month++;
            }
        }

        //if it is in month with 30 days
        else {
            day -= 30;
            month++;
        }

    }
}

void printIntervalBetweenDates(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay, int daysJump) {
    
    while (dateBefore(startYear, startMonth, startDay, endYear, endMonth, endDay)) {

        cout << startYear << "-" << startMonth << "-" << startDay << " - ";// 1
        newDate(startYear, startMonth, startDay, daysJump);// 5

        //date before endDate
        if (dateBefore(startYear, startMonth, startDay, endYear, endMonth, endDay)) {
            cout << startYear << "-" << startMonth << "-" << startDay << " " << endl;
            cout << endl;

        }

        //date same as endDate
        else if (startYear == endYear && startMonth == endMonth && startDay == endDay) {
            cout << startYear << "-" << startMonth << "-" << startDay << " " << endl;
            cout << endl;
            return;
        }

        //date after endDate
        else {    
            cout << startYear << "-" << startMonth << "-" << endDay << " " << endl;
            return;
        }

        newDate(startYear, startMonth, startDay, 1);

        //if interval ends at the day before endDay
        if (startYear == endYear && startMonth == endMonth && startDay == endDay) {
            cout << startYear << "-" << startMonth << "-" << startDay << " - ";
            cout << startYear << "-" << startMonth << "-" << startDay << " " << endl;
        }

    }

}

int main()
{
    int startYear, startMonth, startDay;
    cin >> startYear >> startMonth >> startDay;

    if (isNotValidDate(startYear, startMonth, startDay)) {
        cout << "Incorrect input";
        return 0;
    }

    int endYear, endMonth,endDay;
    cin >> endYear >> endMonth >> endDay;

    if (isNotValidDate(endYear, endMonth, endDay)) {
        cout << "Incorrect input";
        return 0;
    }

    int daysJump;
    cin >> daysJump;

    if (daysJump<0 || daysJump>365) {
        cout << "Incorrect input";
        return 0;
    }

    if (dateBefore(startYear, startMonth, startDay, endYear, endMonth, endDay)) {
        printIntervalBetweenDates(startYear, startMonth, startDay, endYear, endMonth, endDay, daysJump-1);
    }

    else {
        cout << "Incorrect input";
        return 0;
    }
    

}
