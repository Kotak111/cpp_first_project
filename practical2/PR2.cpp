#include <iostream>
#include <string>
using namespace std;

struct Train {
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
};

const int MAX_TRAINS = 100;
Train trains[MAX_TRAINS];
int trainCount = 0;

void displayMenu() {
    cout << "--- Railway Reservation System Menu ---" << endl;
    cout << "1. Add New Train Record" << endl;
    cout << "2. Display All Train Records" << endl;
    cout << "3. Search Train by Number" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTrain() {
    if (trainCount < MAX_TRAINS) {
        cout << "Enter Train Number: ";
        cin >> trains[trainCount].trainNumber;
        cin.ignore(); // Clear input buffer
        cout << "Enter Train Name: ";
        getline(cin, trains[trainCount].trainName);
        cout << "Enter Source: ";
        getline(cin, trains[trainCount].source);
        cout << "Enter Destination: ";
        getline(cin, trains[trainCount].destination);
        cout << "Enter Train Time: ";
        getline(cin, trains[trainCount].trainTime);
        trainCount++;
        cout << "Train record added successfully!" << endl;
    } else {
        cout << "Train record limit reached!" << endl;
    }
}

void displayTrains() {
    if (trainCount == 0) {
        cout << "No train records available!" << endl;
    } else {
        for (int i = 0; i < trainCount; i++) {
            cout << "Train " << i + 1 << " details:" << endl;
            cout << "Train Number: " << trains[i].trainNumber << endl;
            cout << "Train Name: " << trains[i].trainName << endl;
            cout << "Source: " << trains[i].source << endl;
            cout << "Destination: " << trains[i].destination << endl;
            cout << "Train Time: " << trains[i].trainTime << endl;
            cout << "-------------------------" << endl;
        }
    }
}

void searchTrain() {
    int searchNumber;
    cout << "Enter Train Number to search: ";
    cin >> searchNumber;

    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == searchNumber) {
            cout << "Train found:" << endl;
            cout << "Train Number: " << trains[i].trainNumber << endl;
            cout << "Train Name: " << trains[i].trainName << endl;
            cout << "Source: " << trains[i].source << endl;
            cout << "Destination: " << trains[i].destination << endl;
            cout << "Train Time: " << trains[i].trainTime << endl;
            return;
        }
    }
    cout << "Train with number " << searchNumber << " not found!" << endl;
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTrain();
                break;
            case 2:
                displayTrains();
                break;
            case 3:
                searchTrain();
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
