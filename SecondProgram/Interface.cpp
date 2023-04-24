#include "Interface.h"

//#define maxOfPages INT32_MAX
//#define maxOfTypes 3 
//#define maximumOfBooks 10000 


void DrawBorder() {
    cout << "===================================================================================";
}
void DrawSubBorder() {
    cout << "-----------------------------------------------------------------------------------";
}

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
        cout << endl << "incorrect number of types from the book \"" << name << "\" by the author \"" << author << "\" under the publishing house \"" << publisher << "\"" << endl
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

void InputFromFile(vector<book*>* books) {
    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();
        ifstream inputStream(filePath.c_str());
        if (!inputStream.is_open()) {
            cout << "File with this name don't exist. Try again" << endl;
            continue;
        }
        else {
            try {
                InputFromFileInner(books, inputStream);
            }
            catch (bool& error) {
                if (error) {
                    cout << endl << "Corrupted data from file. Maybe incorrect delimiter" << endl;
                    inputStream.close();
                    continue;
                }
            }

            inputStream.close();
            break;
        }
    }
}

void InputFromFileInner(vector<book*>* books, istream& inputStream){
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

    int fieldOrder = 0;

    while (!inputStream.eof()) {
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
                if (delimiter == tmpNextBook) {
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
                throw true;
            }
        }
        else {
            ++fieldOrder;
        }
    }
}

void InputFromConsole(vector<book*>* books) {
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

    int numberOfBooks = 0;

    while (true) {
        DrawBorder();
        cout << endl << "Enter number of books: ";
        numberOfBooks = EnterNum<int>();
        if (IsInBetween<int>(numberOfBooks, 0, maximumOfBooks)) {
            break;
        }
        cout << "Invalid value. Try again" << endl;
    }

    for (size_t i = 0; i < numberOfBooks; ++i) {
        if (i != 0) {
            DrawSubBorder();
            cout << endl;
        }

        cout << "Name: ";
        cin >> name;

        cout << "Author: ";
        cin >> author;

        cout << "Publisher: ";
        cin >> publisher;
        
        cout << "Pages: ";
        if (cin >> pages) {
            if (!IsInBetween<int>(pages, 0, maxOfPages)) {
                pages = CorrectPages(name, author, publisher);
            }
        }
        else {
            cin.clear();
            cin >> trash;
            pages = CorrectPages(name, author, publisher);
        }

        cout << "Is it tech book? (Yes \"1\", No \"2\"): ";
        if (EnterSettingsTwo() == 1) {
            cout << "University: ";
            cin >> publisher;

            cout << "Type: ";
            if (cin >> types) {
                if (!IsInBetween<int>(types, 0, maxOfTypes)) {
                    types = CorrectTypes(name, author, publisher);
                }
            }
            else {
                cin.clear();
                cin >> trash;
                types = CorrectTypes(name, author, publisher);
            }

            techBook* b = new techBook;
            b->SetName(name);
            b->SetAuthor(author);
            b->SetPublisher(publisher);
            b->SetPages(pages);
            b->SetUniversity(university);
            b->SetType(types);

            books->push_back(b);
        }
        else {
            book* b = new book;
            b->SetName(name);
            b->SetAuthor(author);
            b->SetPublisher(publisher);
            b->SetPages(pages);

            books->push_back(b);
        }
    }
}

void WriteOutput(vector<book*>* books, bool flagIgnoreHaritage, bool flagWriteTo) {
    if (flagWriteTo) {
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
                for (size_t i = 0; i < books->size(); ++i) {
                    if (flagIgnoreHaritage) {
                        outputStream << books->at(i)->Get();
                    }
                    else {
                        if (dynamic_cast<techBook*>(books->at(i))){
                            outputStream << dynamic_cast<techBook*>(books->at(i))->Get();
                        }
                        else {
                            outputStream << books->at(i)->Get();
                        }
                    }
                }
                break;
            }
        }
    }
    else{
        for (size_t i = 0; i < books->size(); ++i) {
            if (flagIgnoreHaritage) {
                cout << books->at(i)->Get();
            }
            else {
                if (dynamic_cast<techBook*>(books->at(i))){
                    cout << dynamic_cast<techBook*>(books->at(i))->Get();
                }
                else {
                    cout << books->at(i)->Get();
                }
            }
        }
    }
    
}

void ClearVector(vector<book*>* books) {
    for (auto i = 0; i < books->size(); ++i) {
        delete books->at(i);
    }
}