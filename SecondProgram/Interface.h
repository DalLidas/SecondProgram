#pragma once

#include "pch.h"
#include "classes.h"

#define maxOfPages INT32_MAX
#define maxOfTypes 3          //1 - hypothesis //2 - theorem //3 - practice
#define maximumOfBooks 10000  //2147483647 максимальное значение, так как это максимум int

enum inputFields {
    nameField, authorField, publisherField, pagesField,
    universityField, typeField
};

template <typename type> bool IsInBetween(const type& num, const type& start, const type& end) {
    return start < num && num <= end;
}

int EnterSettingsTwo();
int EnterSettingThree();
string EnterFilePath();
template <typename type> type EnterNum() {
    type num = 0;

    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cout << "Invalid input. Try again" << endl << "> ";
    }

    return num;
}

int CorrectPages(const string& name, const string& author, const string& publisher);
int CorrectTypes(const string& name, const string& author, const string& publisher);

void InputFromFile(vector<book*>* books);

//template <typename type = book> vector<type> InputFromConsole() {
//    string surname;
//    string firstname;
//    string patronymic;
//    string dateOfBirth_;
//    date dateOfBirth;
//    string address;
//    int64_t phoneNum;
//    int16_t faculty;
//    int16_t course;
//
//    int numberOfbooks = 0;
//    vector<book> s;
//
//    while (true) {
//        cout << "Enter number of books: ";
//        numberOfbooks = EnterNum<int>();
//        if (IsInBetween<int>(numberOfbooks, 0, maximumOfbooks)) {
//            break;
//        }
//        cout << "Invalid value. Try again" << endl;
//    }
//
//    for (size_t i = 0; i < numberOfbooks; ++i) {
//        cout << endl << "Surname: ";
//        cin >> surname;
//
//        cout << "Firstname: ";
//        cin >> firstname;
//
//        cout << "Patronymic: ";
//        cin >> patronymic;
//
//        cout << "Date of birth: ";
//        cin >> dateOfBirth_;
//        dateOfBirth = EnterDayMonthYear(dateOfBirth_);
//        if (!dateOfBirth.DateCorrect()) {
//            dateOfBirth = CorrectDateOfBirth(surname, firstname, patronymic);
//        }
//
//        cout << "Address: ";
//        cin >> address;
//
//        cout << "Phone number: ";
//        cin >> phoneNum;
//        if (!IsInBetween<int64_t>(phoneNum, smallestPhoneNumber, biggestPhoneNumber)) {
//            phoneNum = CorrectPhoneNum(surname, firstname, patronymic);
//        }
//
//        cout << "Faculty: ";
//        cin >> faculty;
//        if (!IsInBetween<int64_t>(faculty, 0, numberOfFaculty)) {
//            faculty = CorrectFaculty(surname, firstname, patronymic);
//        }
//
//        cout << "Course: ";
//        cin >> course;
//        if (!IsInBetween<int16_t>(course, 0, numberOfCourse)) {
//            course = CorrectCourse(surname, firstname, patronymic);
//        }
//
//        book s_;
//        s_.Set(surname, firstname, patronymic, dateOfBirth, address, phoneNum, faculty, course);
//        s.Append(s_);
//    }
//
//    return s;
//}


//void WriteOutput(const vector<book>& input) {
//    while (true) {
//        string filePath = " ";
//        filePath = EnterFilePath();
//
//        ifstream test(filePath.c_str());
//        if (test.is_open()) {
//            cout << "File already exist. You still want a write on it? (Yes \"1\" or No \"2\"): ";
//            if (EnterSettingsTwo() == 2) {
//                continue;
//            }
//        }
//
//        ofstream outputStream(filePath.c_str());
//        if (!outputStream.is_open()) {
//            cout << "File with this name don't exist. Try again" << endl;
//            continue;
//        }
//        else {
//            for (size_t i = 0; i < input.size(); ++i) {
//                //outputStream << input[i]. << endl;
//            }
//            break;
//        }
//    }
//}