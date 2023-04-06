#include "Interface.h"

enum inputSettings { inputFromFile = 1, inputFromConsole = 2 };
enum writeMenuSettings { wrirteAndIgnore = 1, writeDontIgnore = 2, dontWrite = 3 };
enum writeModSettings { dontIgnoring = 0, ignoring = 1 };
enum writeSettings { toConsole = 0, toFile = 1 };
enum exitSettings { oldBooks = 1, newBooks = 2, closeProgram = 3 };

int main() {
	//settings
	int inputSetting = 0;
	int outputSetting = 0;
	int exitSetting = 0;

    //flag
    bool flagInputNewBook = true;

    cout << "2 Task by Mukhametov D.I. 423 group option 2" << endl << endl
        << "In the control work, the base and derived classes are set." << endl
        << "It is necessary to develop fields and methods inherited from the base class, " << endl
        << "as well as native components of derived classes.The base class can be abstract." << endl
        << "Implement the ability to get a list of objects in a container" << endl << endl
        << "To realize the base class is a book. The derived class is technical literature" << endl;

    while (true) {
        //containers with students
        vector <book*> books;

        if (flagInputNewBook) {
            //input
            cout << "How do you want to input books (File \"1\" or Console \"2\"): ";
            inputSetting = EnterSettingsTwo();

            switch (inputSetting) {
            case(inputFromFile): InputFromFile(&books); break;        //for file input
            case(inputFromConsole): InputFromConsole(&books); break;  //for console input
            default: cout << "Unexpected behavior" << endl; continue;
            }

            if (books.size() == 0) {
                cout << endl;
                DrawBorder();
                cout << endl << "Invalid data (Empty). Try again" << endl;
                continue;
            }
        }

        DrawBorder();
        cout << endl << "How do you want to write books to console:" << endl
            << "1.Write to a console ignoring types of books" << endl
            << "2.Write to a console with types of books" << endl
            << "3.Don't write to console" << endl;
        outputSetting = EnterSettingThree();

        //output(to console)
        switch (outputSetting) {
        case(writeDontIgnore): WriteOutput(&books, dontIgnoring, toConsole); break; //write and don't ignore type of book
        case(wrirteAndIgnore): WriteOutput(&books, ignoring, toConsole); break;     //write and ignore type of book
        case(dontWrite): break;                                                     //nothing :)
        default: cout << "Unexpected behavior" << endl; continue;
        }
        
        DrawBorder();
        cout << endl << "How do you want to write books to file:" << endl
            << "1.Write to a file ignoring types of books" << endl
            << "2.Write to a file with types of books" << endl
            << "3.Don't write to file" << endl;
        outputSetting = EnterSettingThree();

        //output(to file)
        switch (outputSetting) {
        case(writeDontIgnore): WriteOutput(&books, dontIgnoring, toFile); break;   //write and don't ignore type of book
        case(wrirteAndIgnore): WriteOutput(&books, ignoring, toFile); break;       //write and ignore type of book
        case(dontWrite): break;                                                    //nothing :)
        default: cout << "Unexpected behavior" << endl; continue;
        }

        DrawBorder();
        cout << endl << "What do you prefer to do next:" << endl
            << "1.Work with current books" << endl
            << "2.Work with new books" << endl
            << "3.Close program " << endl;
        exitSetting = EnterSettingThree();

        //ending
        switch (exitSetting) {
        case(oldBooks): flagInputNewBook = false; break;                     //use old students on next cycle
        case(newBooks): flagInputNewBook = true; ClearVector(&books); break; //enter new students on next cycle
        case(closeProgram): ClearVector(&books); return 0;                                            //closeProgram
        default: cout << "Unexpected behavior" << endl; continue;
        }
    }
}