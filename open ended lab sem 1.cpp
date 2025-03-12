
#include <iostream>
#include <string>
using namespace std;

// Structure to hold student info
struct StudInfo {
    int studID;
    string studName;
    int studAge;
    string studClass;
    float studMarks;
};

// Function prototypes
void addMultipleStud(StudInfo arr[], int &num);
void showAllStud(StudInfo arr[], int num);
void searchStud(StudInfo arr[], int num);
void updateStud(StudInfo arr[], int num);
void avgMarks(StudInfo arr[], int num);

int main() {
    const int maxStud = 100;
    StudInfo studList[maxStud];
    int totalStud = 0;
    int option;

    cout << "Welcome to the Simple Student Info System!" << endl;

    do {
        cout << "\\nMenu:" << endl;
        cout << "1. Add Students" << endl;
        cout << "2. Show All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Average Marks" << endl;
        cout << "6. Exit" << endl;
        cout << "Pick an option: ";
        cin >> option;

        switch (option) {
            case 1:
                addMultipleStud(studList, totalStud);
                break;
            case 2:
                showAllStud(studList, totalStud);
                break;
            case 3:
                searchStud(studList, totalStud);
                break;
            case 4:
                updateStud(studList, totalStud);
                break;
            case 5:
                avgMarks(studList, totalStud);
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Wrong choice. Try again!" << endl;
        }
    } while (option != 6);

    return 0;
}

// Add multiple students
void addMultipleStud(StudInfo arr[], int &num) {
    int addCount;
    cout << "\\nHow many students do you want to add? ";
    cin >> addCount;
    cin.ignore();

    for (int i = 0; i < addCount; i++) {
        if (num >= 100) {
            cout << "Cannot add more students. Limit reached!" << endl;
            return;
        }
        cout << "\\nEnter details for student " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> arr[num].studID;
        cin.ignore();
        cout << "Name: ";
        getline(cin, arr[num].studName);
        cout << "Age: ";
        cin >> arr[num].studAge;
        cin.ignore();
        cout << "Class: ";
        getline(cin, arr[num].studClass);
        cout << "Marks: ";
        cin >> arr[num].studMarks;
        num++;
        cout << "Student Added!" << endl;
    }
}

// Show all students
void showAllStud(StudInfo arr[], int num) {
    if (num == 0) {
        cout << "\\nNo data to show." << endl;
        return;
    }
    for (int i = 0; i < num; i++) {
        cout << "ID: " << arr[i].studID << ", Name: " << arr[i].studName
             << ", Age: " << arr[i].studAge << ", Class: " << arr[i].studClass
             << ", Marks: " << arr[i].studMarks << endl;
    }
}

// Search student by ID
void searchStud(StudInfo arr[], int num) {
    if (num == 0) {
        cout << "\\nNo students to search." << endl;
        return;
    }
    int searchID;
    cout << "Enter ID to find: ";
    cin >> searchID;
    for (int i = 0; i < num; i++) {
        if (arr[i].studID == searchID) {
            cout << "\\nFound Student: ID: " << arr[i].studID
                 << ", Name: " << arr[i].studName << ", Age: " << arr[i].studAge
                 << ", Class: " << arr[i].studClass << ", Marks: " << arr[i].studMarks << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Update student details
void updateStud(StudInfo arr[], int num) {
    if (num == 0) {
        cout << "\\nNo students to update." << endl;
        return;
    }
    int updateID;
    cout << "Enter ID to update: ";
    cin >> updateID;
    for (int i = 0; i < num; i++) {
        if (arr[i].studID == updateID) {
            cin.ignore();
            cout << "New Name: ";
            getline(cin, arr[i].studName);
            cout << "New Age: ";
            cin >> arr[i].studAge;
            cin.ignore();
            cout << "New Class: ";
            getline(cin, arr[i].studClass);
            cout << "New Marks: ";
            cin >> arr[i].studMarks;
            cout << "Updated!" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Average marks
void avgMarks(StudInfo arr[], int num) {
    if (num == 0) {
        cout << "\\nNo students available." << endl;
        return;
    }
    float total = 0;
    for (int i = 0; i < num; i++) {
        total += arr[i].studMarks;
    }
    cout << "\\nAverage Marks: " << (total / num) << endl;
}
