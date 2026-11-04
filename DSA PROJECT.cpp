#include <iostream>
#include <string>
using namespace std;

// 1. Structure to hold student details
struct Student {
    int rollNo;
    string name;
    string course;
    int semester;
    float marks;
    Student* next; // Pointer to the next student in the list
};

Student* head = nullptr;

// 2. Check if a roll number already exists
bool rollExists(int roll) {
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == roll) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// 3. Add a new student record
void addStudent() {
    int roll, sem;
    string name, course;
    float marks;

    cout << "\n--- Add New Student ---\n";
    cout << "Enter Roll Number: ";
    cin >> roll;

    if (rollExists(roll)) {
        cout << "Error: Roll number already exists! Please try again.\n";
        return;
    }

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Course: ";
    getline(cin, course);
    cout << "Enter Semester: ";
    cin >> sem;
    cout << "Enter Marks: ";
    cin >> marks;

    // Create a new student node in memory
    Student* newStudent = new Student;
    newStudent->rollNo = roll;
    newStudent->name = name;
    newStudent->course = course;
    newStudent->semester = sem;
    newStudent->marks = marks;
    newStudent->next = nullptr;

    // If the list is empty, make this the first student
    if (head == nullptr) {
        head = newStudent;
    } else {
        // Otherwise, move to the end and attach it
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    cout << "Student added successfully!\n";
}

// 4. Display all student records
void displayAll() {
    if (head == nullptr) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n----------------- All Student Records ------------------------------------------\n";
    Student* temp = head;
    while (temp != nullptr) {
        cout << "Roll No: " << temp->rollNo 
             << " | Name: " << temp->name 
             << " | Course: " << temp->course 
             << " | Semester: " << temp->semester 
             << " | Marks: " << temp->marks << "\n";
        temp = temp->next;
    }
    cout << "----------------------------------------------------------------------------------\n";
}

// 5. Search for a student by roll number
void searchStudent() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == roll) {
            cout << "\nRecord Found:\n";
            cout << "Roll No : " << temp->rollNo << "\n";
            cout << "Name    : " << temp->name << "\n";
            cout << "Course  : " << temp->course << "\n";
            cout << "Semester: " << temp->semester << "\n";
            cout << "Marks   : " << temp->marks << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student with Roll Number " << roll << " not found.\n";
}

// 6. Update student details
void updateStudent() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == roll) {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter New Course: ";
            getline(cin, temp->course);
            cout << "Enter New Semester: ";
            cin >> temp->semester;
            cout << "Enter New Marks: ";
            cin >> temp->marks;

            cout << "Record updated successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student with Roll Number " << roll << " not found.\n";
}

// 7. Delete a student record by roll number
void deleteStudent() {
    if (head == nullptr) {
        cout << "\nList is empty. Nothing to delete.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    // Case 1: First student is to be deleted
    if (head->rollNo == roll) {
        Student* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Record deleted successfully!\n";
        return;
    }

    // Case 2: Student is somewhere else in the list
    Student* temp = head;
    while (temp->next != nullptr && temp->next->rollNo != roll) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Student with Roll Number " << roll << " not found.\n";
    } else {
        Student* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Record deleted successfully!\n";
    }
}

// 8. Sort records by roll number using Bubble Sort
void sortStudents() {
    if (head == nullptr || head->next == nullptr) {
        cout << "\nNot enough records to sort.\n";
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Student* temp = head;
        while (temp->next != nullptr) {
            if (temp->rollNo > temp->next->rollNo) {
                // Swap all fields between current and next node
                swap(temp->rollNo, temp->next->rollNo);
                swap(temp->name, temp->next->name);
                swap(temp->course, temp->next->course);
                swap(temp->semester, temp->next->semester);
                swap(temp->marks, temp->next->marks);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);

    cout << "\nRecords sorted by Roll Number successfully!\n";
}

// 9. Main function (Menu-driven)
int main() {
    int choice;

    while (true) {
        cout << "\n====== STUDENT RECORD SYSTEM ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Update Student Details\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Sort by Roll No\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortStudents(); displayAll(); break;
            case 7: cout << "\nExiting... Bye!\n"; return 0;
            default: cout << "Invalid choice! Enter 1 to 7.\n";
        }
    }

    return 0;
}