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

void DrawBorder();
void DrawSubBorder();

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

void InputFromConsole(vector<book*>* books);

void WriteOutput(vector<book*>* books, bool flagIgnoreHaritage, bool flagWriteTo);

void ClearVector(vector<book*>* books);