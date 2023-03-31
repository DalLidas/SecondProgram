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

void InputFromFile(vector<book*>* books) {
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
                        book* b = new book;
                        b->SetName(name);
                        b->SetAuthor(author);
                        b->SetPublisher(publisher);
                        b->SetPages(pages);

                        books->push_back(b);
                    }
                    else if (delimiter == tmpTechBook) {
                        inputStream >> university;

                        if (inputStream >> types) {
                            if (!IsInBetween<int>(types, 0, maxOfTypes)) {
                                types = CorrectTypes(name, author, publisher);
                            }
                        }
                        else {
                            inputStream.clear();
                            inputStream >> trash;
                            types = CorrectTypes(name, author, publisher);
                        }

                        inputStream >> delimiter;
                        if (delimiter == tmpNextBook){
                            fieldOrder = 0;
                            techBook* b = new techBook;
                            b->SetName(name);
                            b->SetAuthor(author);
                            b->SetPublisher(publisher);
                            b->SetPages(pages);
                            b->SetUniversity(university);
                            b->SetType(types);

                            books->push_back(b);
                        }
                       
                    }
                    else {
                        cout << endl << "Corrupted data from file. Maybe incorrect delimetr" << endl;
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
}

int CorrectPages(const string& name, const string& author, const string& publisher) {
    int pages = 0;
    while (!IsInBetween<int>(pages, 0, maxOfPages)) {
        cout << endl << "incorrect number of pages from the book \"" << name << "\" by the author \"" << author << "\" under the publishing house \"" << publisher << "\"" << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Pages: ";
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
        cout << endl << "incorrect number of types from the book \"" << name << "\" by the author \"" << author <<"\" under the publishing house \"" << publisher <<"\"" << endl
            << "You can enter now correct (press 1) or do not initialize it (press 2): ";
        if (EnterSettingsTwo() == 1) {
            cout << "Type: ";
            types = EnterNum<int>();;
        }
        else {
            return 0;
        }
    }
    return types;
}
