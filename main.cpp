#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Student {
    string rollno;
    string name;
    float marks[5];
    float cgpa;
};
struct Attendance {
    string rollno;
    string name;
    int totalClasses;
    int presentClasses;
    float percentage;
};

struct Book {
    string rollno;
    int bookId;
    string bookName;
    bool isIssued;
};
vector<Student> students;
vector<Attendance> attendance;
vector<Book> books;


void showMenu();
void cgpaSystem();
void attendanceSystem();
void librarySystem();
void addStudent();
void viewStudents();
void saveStudents();
void addAttendance();
void viewAttendance();
void saveAttendance();
void addBook();
void viewBooks();
void saveBooks();
int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if(choice == 1) {
            cgpaSystem();
        }
        else if(choice == 2) {
            attendanceSystem();
        }
        else if(choice == 3) {
            librarySystem();
        }
        else if(choice == 4) {
            saveStudents();
            saveAttendance();
            saveBooks();
            cout <<endl<< "All data saved successfully!"<<endl;
        }
        else {
            cout <<endl<< "Invalid choice! Please try again."<<endl;
        }

    } while(choice != 4);

    return 0;
}
void showMenu() {
    cout << "   STUDENT MANAGEMENT SYSTEM"<<endl;
    cout << "1. CGPA System"<<endl;
    cout << "2. Attendance System"<<endl;
    cout << "3. Library System"<<endl;
    cout << "4. Exit"<<endl;
}
void cgpaSystem() {
    int choice;

    do {
        cout <<endl<<"CGPA SYSTEM"<<endl;
        cout << "1. Add Student"<<endl;
        cout << "2. View All Students"<<endl;
        cout << "3. Save to File"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            addStudent();
        }
        else if(choice == 2) {
            viewStudents();
        }
        else if(choice == 3) {
            saveStudents();
        }
        else {
            cout <<endl<< "Invalid choice!"<<endl;
        }

    } while(choice != 4);
}
void addStudent() {
    Student s;

    cout <<endl<< "ADD NEW STUDENT "<<endl;
    cout << "Enter Roll Number: ";
    cin >> s.rollno;
    cout << "Enter Name: ";
    cin >> s.name;

    cout <<endl<< "Enter marks for 5 subjects:"<<endl;
    cout << " pf marks: ";
    cin >> s.marks[0];
    cout << "math marks: ";
    cin >> s.marks[1];
    cout << "ict marks: ";
    cin >> s.marks[2];
    cout << "phys marks: ";
    cin >> s.marks[3];
    cout << "english marks: ";
    cin >> s.marks[4];

    float total = 0;
    for(int i = 0; i < 5; i++) {
        total += s.marks[i];
    }
    float average = total / 5;
    s.cgpa = average / 25;

    students.push_back(s);

    cout <<endl<< "Student added successfully!"<<endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll No: " << s.rollno << endl;
    cout << "CGPA: " << s.cgpa << endl;

    if(s.cgpa >= 2.0) {
        cout << "Status: PASS"<<endl;
    }
    else {
        cout << "Status: FAIL"<<endl;
    }
}
void viewStudents() {
    if(students.empty()) {
        cout << endl<<"No student records found!"<<endl;
    }
else {
    cout <<endl<< "   ALL STUDENT RECORDS "<<endl;
    cout << "Total students: " << students.size() << endl;
}
    for(int i = 0; i < students.size(); i++) {
        cout <<endl<< "Student " << i+1 << ":"<<endl;
        cout << "Roll No: " << students[i].rollno << endl;
        cout << "Name: " << students[i].name << endl;

        cout << "Marks: ";
        for(int j = 0; j < 5; j++) {
            cout << students[i].marks[j] << " ";
        }

        cout << endl<<"CGPA: " << students[i].cgpa << endl;


        if(students[i].cgpa >= 2.0) {
            cout << "Status: PASS"<<endl;
        }
        else {
            cout << "Status: FAIL"<<endl;
        }
    }
}
void saveStudents() {
    ofstream file("students.txt");

    if(!file) {
        cout << "Error creating file!"<<endl;

    }
    else {
        for(int i = 0; i < students.size(); i++) {
            file << students[i].rollno << " "
                 << students[i].name << " ";

            for(int j = 0; j < 5; j++) {
                file << students[i].marks[j] << " ";
            }

            file << students[i].cgpa << endl;
        }
    }
    file.close();
    cout <<endl <<"Student data saved to 'students.txt"<<endl;
}

void attendanceSystem() {
    int choice;

    do {
        cout <<endl<< "ATTENDANCE SYSTEM "<<endl;
        cout << "1. Add Attendance Record"<<endl;
        cout << "2. View All Attendance"<<endl;
        cout << "3. Save to File"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            addAttendance();
        }
        else if(choice == 2) {
            viewAttendance();
        }
        else if(choice == 3) {
            saveAttendance();
        }
        else {
            cout <<endl<< "Invalid choice!"<<endl;
        }

    } while(choice != 4);
}
void addAttendance() {
    Attendance a;

    cout <<endl<< " ADD ATTENDANCE RECORD"<<endl;
    cout << "Enter Roll Number: ";
    cin >> a.rollno;
    cout << "Enter Name: ";
    cin >> a.name;
    cout << "Enter Total Classes: ";
    cin >> a.totalClasses;
    cout << "Enter Present Classes: ";
    cin >> a.presentClasses;

    // Calculate percentage
    if(a.totalClasses > 0) {
        a.percentage = (float)a.presentClasses / a.totalClasses * 100;
    }
    else {
        a.percentage = 0;
    }

    attendance.push_back(a);

    cout <<endl<< "Attendance record added!"<<endl;
    cout << "Roll No: " << a.rollno << endl;
    cout << "Name: " << a.name << endl;
    cout << "Percentage: " << a.percentage << "%" << endl;

    if(a.percentage >= 75) {
        cout << "Status: ELIGIBLE for exams"<<endl;
    }
    else {
        cout << "Status: NOT ELIGIBLE for exams"<<endl;
    }
}
void viewAttendance() {
    if(attendance.empty()) {
        cout <<endl<< "No attendance records found!"<<endl;
        return;
    }

    cout <<endl<< " ALL ATTENDANCE RECORDS "<<endl;
    cout << "Total records: " << attendance.size() << endl;

    for(int i = 0; i < attendance.size(); i++) {
        cout <<endl<< "Record " << i+1 << ":"<<endl;
        cout << "Roll No: " << attendance[i].rollno << endl;
        cout << "Name: " << attendance[i].name << endl;
        cout << "Total Classes: " << attendance[i].totalClasses << endl;
        cout << "Present Classes: " << attendance[i].presentClasses << endl;
        cout << "Percentage: " << attendance[i].percentage << "%" << endl;

        if(attendance[i].percentage >= 75) {
            cout << "Status: ELIGIBLE"<<endl;
        }
        else {
            cout << "Status: NOT ELIGIBLE"<<endl;
        }
    }
}
void saveAttendance() {
    ofstream file("attendance.txt");

    if(!file) {
        cout <<endl<< "Error creating file!"<<endl;
        return;
    }

    for(int i = 0; i < attendance.size(); i++) {
        file << attendance[i].rollno << " "
             << attendance[i].name << " "
             << attendance[i].totalClasses << " "
             << attendance[i].presentClasses << " "
             << attendance[i].percentage << endl;
    }

    file.close();
    cout <<endl<< "Attendance data saved to 'attendance.txt'"<<endl;
}
void loadAttendance() {
    ifstream file("attendance.txt");

    if(!file) {

        cout<<"error attendance.txt!"<<endl;
    }

    Attendance a;

    while(file >> a.rollno >> a.name >> a.totalClasses >> a.presentClasses >> a.percentage) {
        attendance.push_back(a);
    }

    file.close();
}

void librarySystem() {
    int choice;

    do {
        cout <<endl<< " LIBRARY SYSTEM "<<endl;
        cout << "1. Issue Book"<<endl;
        cout << "2. View All Issued Books"<<endl;
        cout << "3. Save to File"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            addBook();
        }
        else if(choice == 2) {
            viewBooks();
        }
        else if(choice == 3) {
            saveBooks();
        }
        else {
            cout << endl<<"Invalid choice!"<<endl;
        }

    } while(choice != 4);
}
void addBook() {
    Book b;

    cout <<endl<< " ISSUE NEW BOOK "<<endl;
    cout << "Enter Student Roll Number: ";
    cin >> b.rollno;
    cout << "Enter Book ID: ";
    cin >> b.bookId;
    cout << "Enter Book Name: ";
    cin >> b.bookName;
    b.isIssued = true;
    books.push_back(b);

    cout <<endl<< "Book issued successfully!"<<endl;
    cout << "Roll No: " << b.rollno << endl;
    cout << "Book ID: " << b.bookId << endl;
    cout << "Book Name: " << b.bookName << endl;
    cout << "Status: ISSUED"<<endl;
}
void viewBooks() {
    if(books.empty()) {
        cout <<endl<< "No book records found!"<<endl;
    }
    else {
        cout <<endl<<"ALL ISSUED BOOKS "<<endl;
        cout << "Total books issued: " << books.size() << endl;
    }
    for(int i = 0; i < books.size(); i++) {
        cout <<endl<< "Book " << i+1 << ":"<<endl;
        cout << "Roll No: " << books[i].rollno << endl;
        cout << "Book ID: " << books[i].bookId << endl;
        cout << "Book Name: " << books[i].bookName << endl;

        if(books[i].isIssued) {
            cout << "Status: ISSUED"<<endl;
        }
        else {
            cout << "Status: RETURNED"<<endl;
        }
    }
}
void saveBooks() {
    ofstream file("Library.txt",ios::app);

    if(!file) {
        cout << endl<<"Error creating file!"<<endl;
        return;
    }

    for(int i = 0; i < books.size(); i++) {
        file << books[i].rollno << " "
             << books[i].bookId << " "
             << books[i].bookName << " "
             << books[i].isIssued << endl;
    }

    file.close();
    cout <<endl<< "Library data saved to 'library.txt'"<<endl;
}
