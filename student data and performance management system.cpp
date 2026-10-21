#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    float marks;

    // Function to calculate GPA/Grade based on marks
    float calculateGPA() {
        return (marks / 100.0) * 10.0; // Converts marks out of 100 to a 10-point scale
    }

    // Function to display student details on screen
    void display() {
        cout << "Roll No: " << rollNumber 
             << " | Name: " << name 
             << " | Marks: " << marks 
             << " | GPA: " << calculateGPA() << endl;
    }
};
void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cin.ignore(); // Clear newline character from buffer
    
    cout << "Enter Student Name: ";
    getline(cin, s.name);
    
    cout << "Enter Marks (0-100): ";
    cin >> s.marks;

    // Open file in append mode
    ofstream outFile("students.txt", ios::app);
    outFile << s.rollNumber << "\n" << s.name << "\n" << s.marks << "\n";
    outFile.close();
    cout << "Student record saved successfully!\n\n";
}
void viewStudents() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No records found!\n";
        return;
    }

    Student s;
    string rollStr, marksStr;
    cout << "\n--- ALL STUDENT RECORDS ---\n";
    
    // Read every field as a line and convert numbers safely
    while (getline(inFile, rollStr) && getline(inFile, s.name) && getline(inFile, marksStr)) {
        s.rollNumber = stoi(rollStr);
        s.marks = stof(marksStr);
        s.display();
    }
    
    inFile.close();
    cout << "---------------------------\n\n";
}
int main() {
    int choice;
    do {
        cout << "1. Add Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
