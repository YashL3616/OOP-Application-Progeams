#include <iostream>
using namespace std;
class WeatherReport {
public:
    int day_of_month;
    int high_temp;
    int low_temp;
    double amount_rain;
    double amount_snow;


    // Constructor with default values
    WeatherReport() : day_of_month(99), high_temp(999), low_temp(-999), amount_rain(0), amount_snow(0) {}

    // Function to set values for each field
    void enterData() {
        cout << "Enter day of the month: ";
        cin >> day_of_month;

        cout << "Enter high temperature: ";
        cin >> high_temp;

        cout << "Enter low temperature: ";
        cin >> low_temp;

        cout << "Enter amount of rain: ";
        cin >> amount_rain;

        cout << "Enter amount of snow: ";
        cin >> amount_snow;
    }

    // Function to display the weather report
    void displayReport()  {
        cout << "Day of Month: " << day_of_month << endl;
        cout << "High Temperature: " << high_temp << endl;
        cout << "Low Temperature: " << low_temp << endl;
        cout << "Amount of Rain: " << amount_rain << endl;
        cout << "Amount of Snow: " << amount_snow << endl;
    }
};

int main() {
    WeatherReport monthlyReport;

    int choice;
    do {
        cout << "\nMenu:\n1. Enter Data\n2. Display Report\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                monthlyReport.enterData();
                break;

            case 2:
                monthlyReport.displayReport();
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}
