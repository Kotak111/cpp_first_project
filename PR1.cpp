#include <iostream>
#include <iomanip>

class TimeConverter {
public:
    
    void convertSSToTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        std::cout << "HH:MM:SS => " << hours << ":" 
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }

    
    int convertTimeToSS(int hours, int minutes, int seconds) {
        return (hours * 3600) + (minutes * 60) + seconds;
    }
};

int main() {
    TimeConverter converter;
    int choice;

    do {
        std::cout << "\n--- Time Converter ---\n";
        std::cout << "1. Convert seconds to HH:MM:SS\n";
        std::cout << "2. Convert HH:MM:SS to seconds\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int totalSeconds;
                std::cout << "Enter total seconds: ";
                std::cin >> totalSeconds;
                converter.convertSSToTime(totalSeconds);
                break;
            }
            case 2: {
                int hours, minutes, seconds;
                std::cout << "Enter hours: ";
                std::cin >> hours;
                std::cout << "Enter minutes: ";
                std::cin >> minutes;
                std::cout << "Enter seconds: ";
                std::cin >> seconds;

                int totalSeconds = converter.convertTimeToSS(hours, minutes, seconds);
                std::cout << "Total seconds: " << totalSeconds << std::endl;
                break;
            }
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
