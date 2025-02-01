#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
 // https://www.calculator.net/age-calculator.html
// Function to calculate the number of days in a given month of a year
int daysInMonth(int month, int year) {
    if (month == 2) { // February
        // Check if the year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        else
            return 28;
    }
    // Months with 31 days
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    // Months with 30 days
    return 30;
}

// Function to calculate the age details
void calculateAge(int birthDay, int birthMonth, int birthYear, int currentDay, int currentMonth, int currentYear) {
    int years, months, days;

    // Start with basic calculation of years, months, and days
    years = currentYear - birthYear;
    months = currentMonth - birthMonth;
    days = currentDay - birthDay;

    // Adjust for negative days
    if (days < 0) {
        months--;
        days += daysInMonth((currentMonth == 1) ? 12 : currentMonth - 1, currentYear);
    }

    // Adjust for negative months
    if (months < 0) {
        years--;
        months += 12;
    }

    // Total days lived
    int totalDays = years * 365 + months * 30 + days; // Approximation
    for (int y = birthYear; y < currentYear; y++) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            totalDays++; // Add leap year days
    }

    // Convert total days to hours, minutes, seconds, and weeks
    int totalWeeks = totalDays / 7;
    int totalHours = totalDays * 24;
    int totalMinutes = totalHours * 60;
    long long totalSeconds = (long long)totalMinutes * 60;

    // Output the results
    cout << "\n\n--- Age in detail ---\n"
         << "Years: " << years << "\n"
         << "Months: " << (years * 12 + months) << "\n"
         << "Weeks: " << totalWeeks << "\n"
         << "Days: " << totalDays << "\n"
         << "Hours: " << totalHours << "\n"
         << "Minutes: " << totalMinutes << "\n"
         << "Seconds: " << totalSeconds << "\n";

}

int main() {
    int birthDay, birthMonth, birthYear;
    int currentDay, currentMonth, currentYear;

    // Input birth date
    cout << "Enter your date of birth (day - month - year):  ";
    cin >> birthDay >> birthMonth >> birthYear;

    // Get current date from system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    currentDay = ltm->tm_mday;
    currentMonth = 1 + ltm->tm_mon;
    currentYear = 1900 + ltm->tm_year;

    // Output current date
    cout << "Current day's date: " << currentDay << "-" << currentMonth << "-" << currentYear << "\n";

    // Calculate and display age details
    calculateAge(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear);

    return 0;
}

