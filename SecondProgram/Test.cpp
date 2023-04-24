#include "Test.h"

bool ErrorHandler() {
    try {
        TestInputFromFile1();
        TestInputFromFile2();
        TestInputFromFile3();
        TestInputFromFile4();
        TestInputFromFile5();
    }
    catch (const int& numOfFailedTest) {
        switch (numOfFailedTest) {
        case(0):
            cout << "Test file dont find. Recover it. Look to test function" << endl;
            break;

        case(1):
            cout << "Test 1 is Failed" << endl;
            break;

        case(2):
            cout << "Test 2 is Failed" << endl;
            break;

        case(3):
            cout << "Test 3 is Failed" << endl;
            break;

        case(4):
            cout << "Test 4 is Failed" << endl;
            break;

        case(5):
            cout << "Test 5 is Failed" << endl;
            break;

        default:
            cout << "Undefined error" << endl;
            break;
        }

        return true;
    }
    return false;
}

bool TestInputFromFile1() {
    int numOfTest = 1;
    string fielPath = "./tmp/tmp1.txt";
    ifstream input(fielPath.c_str());
    //file data
    /*
        1Book
        1Author
        1Publisher
        451
        #======#
        2Book
        2Author
        2Publisher
        51
        #======#
        3Book
        3Author
        3Publisher
        23
        #======#
        4Book
        4Author
        4Publisher
        24
        #======#
    */
    if (!input.is_open()) {
        throw 0;
    }


    vector<book*> enteredBooks{};
    vector<book*> books{};

    book book1("1Book", "1Author", "1Publisher", 451);
    book book2("2Book", "2Author", "2Publisher", 51);
    book book3("3Book", "3Author", "3Publisher", 23);
    book book4("4Book", "4Author", "4Publisher", 24);

    books.push_back(&book1);
    books.push_back(&book2);
    books.push_back(&book3);
    books.push_back(&book4);

    try {
        InputFromFileInner(&enteredBooks, input);
    }
    catch (bool error) {
        input.close();
        if (error) throw numOfTest;
    }
    input.close();

    if (enteredBooks.size() != books.size()) throw numOfTest;

    for (int i = 0; i < enteredBooks.size(); ++i) {
        if (dynamic_cast<techBook*>(enteredBooks.at(i))) {
            if (dynamic_cast<techBook*>(books.at(i))->Get() != dynamic_cast<techBook*>(enteredBooks.at(i))->Get()) {
                throw numOfTest;
            }
        }
        else if (books.at(i)->Get() != enteredBooks.at(i)->Get()) {
            throw numOfTest;
        }
    }

    return true;
}

bool TestInputFromFile2() {
    int numOfTest = 2;
    string fielPath = "./tmp/tmp2.txt";
    ifstream input(fielPath.c_str());
    //file data
    /*
        1Book
        1Author
        1Publisher
        451
        #======#
        2Book
        2Author
        2Publisher
        44551
        --tech--
        MIT
        3
        #======#
        3Book
        3Author
        3Publisher
        23
        #======#
        4Book
        4Author
        4Publisher
        24
        --tech--
        SPSIOT
        2
        #======#
    */
    if (!input.is_open()) {
        throw 0;
    }


    vector<book*> enteredBooks{};
    vector<book*> books{};

    book book1("1Book", "1Author", "1Publisher", 451);
    techBook book2("2Book", "2Author", "2Publisher", 51, "MIT", 3);
    book book3("3Book", "3Author", "3Publisher", 23);
    techBook book4("4Book", "4Author", "4Publisher", 24, "SPSIOT", 2);

    books.push_back(&book1);
    books.push_back(&book2);
    books.push_back(&book3);
    books.push_back(&book4);

    try {
        InputFromFileInner(&enteredBooks, input);
    }
    catch (bool error) {
        input.close();
        if (error) throw numOfTest;
    }
    input.close();

    if (enteredBooks.size() != books.size()) throw numOfTest;

    for (int i = 0; i < enteredBooks.size(); ++i) {
        if (dynamic_cast<techBook*>(enteredBooks.at(i))) {
            if (dynamic_cast<techBook*>(books.at(i))->Get() != dynamic_cast<techBook*>(enteredBooks.at(i))->Get()) {
                throw numOfTest;
            }
        }
        else if (books.at(i)->Get() != enteredBooks.at(i)->Get()) {
            throw numOfTest;
        }
    }

    return true;
}

bool TestInputFromFile3() {
    int numOfTest = 3;
    string fielPath = "./tmp/tmp3.txt";
    ifstream input(fielPath.c_str());
    //file data
    /*
        1Book
        1Author
        1Publisher
        451
        --tech--
        MIT
        3
        #======#
        2Book
        2Author
        2Publisher
        2
        --tech--
        MIT
        3
        #======#
        3Book
        3Author
        3Publisher
        23
        --tech--
        MIT
        3
        #======#
        4Book
        4Author
        4Publisher
        24
        --tech--
        MIT
        3
        #======#
    */
    if (!input.is_open()) {
        throw 0;
    }


    vector<book*> enteredBooks{};
    vector<book*> books{};

    techBook book1("1Book", "1Author", "1Publisher", 451, "MIT", 3);
    techBook book2("2Book", "2Author", "2Publisher", 2, "MIT", 3);
    techBook book3("3Book", "3Author", "3Publisher", 23, "MIT", 3);
    techBook book4("4Book", "4Author", "4Publisher", 24, "MIT", 3);

    books.push_back(&book1);
    books.push_back(&book2);
    books.push_back(&book3);
    books.push_back(&book4);

    try {
        InputFromFileInner(&enteredBooks, input);
    }
    catch (bool error) {
        input.close();
        if (error) throw numOfTest;
    }
    input.close();

    if (enteredBooks.size() != books.size()) throw numOfTest;

    for (int i = 0; i < enteredBooks.size(); ++i) {
        if (dynamic_cast<techBook*>(enteredBooks.at(i))) {
            if (dynamic_cast<techBook*>(books.at(i))->Get() != dynamic_cast<techBook*>(enteredBooks.at(i))->Get()) {
                throw numOfTest;
            }
        }
        else if (books.at(i)->Get() != enteredBooks.at(i)->Get()) {
            throw numOfTest;
        }
    }

    return true;
}

bool TestInputFromFile4() {
    int numOfTest = 4;
    string fielPath = "./tmp/tmp4.txt";
    ifstream input(fielPath.c_str());
    //file data
    /*
        1Book
        1Author
        1Publisher
        1
        #======#
        2Book
        2Author
        2Publisher
        2
        #======#
        3Book
        3Author
        3Publisher
        3
        #======#
        4Book
        4Author
        4Publisher
        4
        #======#
        5Book
        5Author
        5Publisher
        5
        #======#
        6Book
        6Author
        6Publisher
        6
        #======#
        7Book
        7Author
        7Publisher
        7
        #======#
        8Book
        8Author
        8Publisher
        8
        #======#
    */
    if (!input.is_open()) {
        throw 0;
    }


    vector<book*> enteredBooks{};
    vector<book*> books{};

    book book1("1Book", "1Author", "1Publisher", 1);
    book book2("2Book", "2Author", "2Publisher", 2);
    book book3("3Book", "3Author", "3Publisher", 3);
    book book4("4Book", "4Author", "4Publisher", 4);
    book book5("5Book", "5Author", "5Publisher", 5);
    book book6("6Book", "6Author", "6Publisher", 6);
    book book7("7Book", "7Author", "7Publisher", 7);
    book book8("8Book", "8Author", "8Publisher", 8);

    books.push_back(&book1);
    books.push_back(&book2);
    books.push_back(&book3);
    books.push_back(&book4);
    books.push_back(&book5);
    books.push_back(&book6);
    books.push_back(&book7);
    books.push_back(&book8);

    try {
        InputFromFileInner(&enteredBooks, input);
    }
    catch (bool error) {
        input.close();
        if (error) throw numOfTest;
    }
    input.close();

    if (enteredBooks.size() != books.size()) throw numOfTest;

    for (int i = 0; i < enteredBooks.size(); ++i) {
        if (dynamic_cast<techBook*>(enteredBooks.at(i))) {
            if (dynamic_cast<techBook*>(books.at(i))->Get() != dynamic_cast<techBook*>(enteredBooks.at(i))->Get()) {
                throw numOfTest;
            }
        }
        else if (books.at(i)->Get() != enteredBooks.at(i)->Get()) {
            throw numOfTest;
        }
    }

    return true;
}
bool TestInputFromFile5() {
    int numOfTest = 5;
    string fielPath = "./tmp/tmp5.txt";
    ifstream input(fielPath.c_str());
    //file data
    // 1Book 1Author 1Publisher 451 --tech-- Cambrige 1 #======#
    
    if (!input.is_open()) {
        throw 0;
    }


    vector<book*> enteredBooks{};
    vector<book*> books{};

    techBook book1("1Book", "1Author", "1Publisher", 451, "Cambrige", 1);

    books.push_back(&book1);

    try {
        InputFromFileInner(&enteredBooks, input);
    }
    catch (bool error) {
        input.close();
        if (error) throw numOfTest;
    }
    input.close();

    if (enteredBooks.size() != books.size()) throw numOfTest;

    for (int i = 0; i < enteredBooks.size(); ++i) {
        if (dynamic_cast<techBook*>(enteredBooks.at(i))) {
            if (dynamic_cast<techBook*>(books.at(i))->Get() != dynamic_cast<techBook*>(enteredBooks.at(i))->Get()) {
                throw numOfTest;
            }
        }
        else if (books.at(i)->Get() != enteredBooks.at(i)->Get()) {
            throw numOfTest;
        }
    }

    return true;
}

