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

template <typename type> inline bool IsInBetween(const type& num, const type& start, const type& end) {
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

vector<book> InputFromFile() {
    string name = "Undefined";
    string author = "Undefined";
    string publisher = "Undefined";
    int pages = 0;
    string university = "Undefined";
    int types = 0;

    string trash = " ";
    string delimiter = " ";
    string tmpNextBook = "#======#";
    string tmpTechBook = "--tech--";

    vector <book> b;

    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();
        ifstream inputStream(filePath.c_str());
        if (!inputStream.is_open()) {
            cout << "File with this name don't exist. Try again" << endl;
            continue;
        }
        else {
            int fieldOrder = 0;

            while (inputStream) {
                switch (fieldOrder) {
                case(nameField):
                    inputStream >> name;
                    break;
                case(authorField):
                    inputStream >> author;
                    break;
                case(publisherField):
                    inputStream >> publisher;
                    break;
                case(pagesField):
                    if (inputStream >> pages) {
                        if (!IsInBetween<int>(pages, 0, maxOfPages)) {
                            pages = CorrectPages(name, author, publisher);
                        }
                    }
                    else {
                        inputStream.clear();
                        inputStream >> trash;
                        pages = CorrectPages(name, author, publisher);
                    }
                    break;
                }

                if (fieldOrder == 3) {
                    inputStream >> delimiter;
                    if (delimiter == tmpNextBook) {
                        fieldOrder = 0;
                        book b_;
                        b_.SetName(name);
                        b_.SetAuthor(author);
                        b_.SetPublisher(publisher);
                        b_.SetPages(pages);

                        b.push_back(b_);
                    }
                    else if (delimiter == tmpTechBook) {
                        inputStream >> university;

                        if (cin >> types) {
                            if (!IsInBetween<int>(types, 0, maxOfTypes)) {
                                types = CorrectPages(name, author, publisher);
                            }
                        }
                        else {
                            cin.clear();
                            cin >> trash;
                            types = CorrectPages(name, author, publisher);
                        }

                        techBook b_;
                        b_.SetName(name);
                        b_.SetAuthor(author);
                        b_.SetPublisher(publisher);
                        b_.SetPages(pages);
                        b_.SetUniversity(university);
                        b_.SetType(types);

                        b.push_back(b_);
                    }
                    else {
                        cout << endl << "Incorrect data from file" << endl;
                        throw true;
                    }
                }
                else {
                    ++fieldOrder;
                }
            }

            inputStream.close();
            break;
        }
    }

    return b;
}

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


template <typename type = book> void WriteOutput(const vector<type>& input) {
    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();

        ifstream test(filePath.c_str());
        if (test.is_open()) {
            cout << "File already exist. You still want a write on it? (Yes \"1\" or No \"2\"): ";
            if (EnterSettingsTwo() == 2) {
                continue;
            }
        }

        ofstream outputStream(filePath.c_str());
        if (!outputStream.is_open()) {
            cout << "File with this name don't exist. Try again" << endl;
            continue;
        }
        else {
            for (size_t i = 0; i < input.GetSize(); ++i) {
                outputStream << input[i].Get() << endl;
            }
            break;
        }
    }
}