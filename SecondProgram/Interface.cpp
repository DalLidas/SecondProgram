#include "Interface.h"

//#define maxOfPages INT32_MAX
//#define maxOfTypes 3 
//#define maximumOfBooks 10000 

int EnterSettingsTwo() {
    int  setting = 0;
    cin >> setting;

    while (true) {
        if (setting == 1 || setting == 2) {
            break;
        }

        while (!(cin >> setting))
        {
            cin.clear();
            cin.ignore(INT32_MAX, '\n');
            cout << "Invalid input. Try again" << endl
                << "Enter \"1\" or \"2\": ";
        }
    }
    return setting;
}

int EnterSettingThree() {
    int setting = 0;
    cin >> setting;

    while (true) {
        if (setting == 1 || setting == 2 || setting == 3) {
            break;
        }

        while (!(cin >> setting))
        {
            cin.clear();
            cin.ignore(INT32_MAX, '\n');
            cout << "Invalid input. Try again" << endl
                << "Enter \"1\" or \"2\" or \"3\": ";
        }
    }
    return setting;
}

string EnterFilePath() {
    string filePath = " ";
    static const regex reg("((/./)?(con))|((/./)?(con\\.))|((/./)?(con\\.)(.*))");

    while (true) {
        cout << "Enter file path: ";
        cin >> filePath;

        if (!regex_match(filePath.c_str(), reg)) {
            break;
        }
        cout << "You enter reserved by system file name. Try again" << endl;
    }

    return filePath.c_str();
}

int CorrectPages(const string& name, const string& author, const string& publisher) {
    int pages = 0;
    while (!IsInBetween<int>(pages, 0, maxOfPages)) {
        cout << endl << "incorrect number of pages from the book \"" << name << "\" by the author \"" << author << "\" under the publishing house \"" << publisher << "\"" << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Phone number: ";
            pages = EnterNum<int>();;
        }
        else {
            return 0;
        }
    }
    return pages;
}

int CorrectTypes(const string& name, const string& author, const string& publisher) {
    int types = 0;
    while (!IsInBetween<int>(types, 0, maxOfTypes)) {
        cout << endl << "incorrect number of pages from the book \"" << name << "\" by the author \"" << author <<"\" under the publishing house \"" << publisher <<"\"" << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Phone number: ";
            types = EnterNum<int>();;
        }
        else {
            return 0;
        }
    }
    return types;
}
