#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    string serial;
    string rollno;
    string name;
    float marks;
    float attendance;
};

struct BookIssue {
    string shelf;
    string rollno;
    int bookId;
    string bookName;
    int bookissue;
};

// functions
void gradingSystem();
void attendanceSystem();
void librarySystem();

int main() {
    int choice;

    do {
        cout <<endl<< "Student Management System"<<endl;
        cout << "1. Grading System"<<endl;
        cout << "2. Attendance System<<endl";
        cout << "3. Library Management System"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                gradingSystem();
                break;
            case 2:
                attendanceSystem();
                break;
            case 3:
                librarySystem();
                break;
            case 4:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    } while (choice != 4);

    return 0;
}

//  GRADING SYSTEM -
void gradingSystem() {
    int n;
    Student s;
    vector<Student> students;

    cout <<endl <<"Enter number of students: "<<endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout <<endl<< "Roll No: ";
        cin >> s.rollno;
        cout << "Name: ";
        cin >> s.name;
        cout << "Marks: ";
        cin >> s.marks;

        students.push_back(s);
    }

    ofstream file("grades.txt", ios::app);
    for (int i = 0; i < students.size(); i++) {
        file << students[i].rollno << " "
             << students[i].name << " "
             << students[i].marks << endl;
    }
    file.close();

    ifstream fin("grades.txt");
    cout << "\n----- Grades -----\n";
    while (fin >> s.rollno >> s.name >> s.marks) {
        cout << s.rollno << " : ";
        if (s.marks >= 80) cout << "A\n";
        else if (s.marks >= 70) cout << "B\n";
        else if (s.marks >= 60) cout << "C\n";
        else if (s.marks >= 50) cout << "D\n";
        else cout << "Fail"<<endl;
    }
    fin.close();
}

//ATTENDANCE SYSTEM
void attendanceSystem() {
    int n;
    Student s;
    vector<Student> attendanceList;

    cout << "\nEnter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nRoll No: ";
        cin >> s.rollno;
        cout << "Name: ";
        cin >> s.name;
        cout << "Attendance (%): ";
        cin >> s.attendance;

        attendanceList.push_back(s);
    }

    ofstream file("attendance.txt", ios::app);
    for (int i = 0; i < attendanceList.size(); i++) {
        file << attendanceList[i].rollno << " "
             << attendanceList[i].name << " "
             << attendanceList[i].attendance << endl;
    }
    file.close();

    ifstream fin("attendance.txt");
    cout <<endl<< "Attendance Status "<<endl;
    while (fin >> s.rollno >> s.name >> s.attendance) {
        cout << s.rollno << " : ";
        if (s.attendance >= 75)
            cout << "Eligible\n";
        else
            cout << "Not Eligible\n";
    }
    fin.close();
}

// LIBRARY MANAGEMENT SYSTEM
void librarySystem() {
    int n;
    BookIssue b;
    vector<BookIssue> books;

    cout << "\nEnter number of book issues: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nStudent Roll No: ";
        cin >> b.rollno;
        cout << "Book ID: ";
        cin >> b.bookId;
        cout << "Book Name: ";
        cin >> b.bookName;

        b.bookissue = 1;
        books.push_back(b);
    }

    ofstream fout("library.txt", ios::app);
    for (int i = 0; i < books.size(); i++) {
        fout << books[i].rollno << " "
             << books[i].bookId << " "
             << books[i].bookName << " "
             << books[i].bookissue << endl;
    }
    fout.close();

    ifstream fin("library.txt");
    cout <<endl<< " Library Records "<<endl;
    while (fin >> b.rollno >> b.bookId >> b.bookName >> b.bookissue) {
        cout << "Roll No: " << b.rollno
             << " | Book: " << b.bookName
             << " | Status: Issued"<<endl;
    }
    fin.close();
}
