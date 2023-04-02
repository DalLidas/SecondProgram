#include "Interface.h"

enum inputSettings { inputFromFile = 1, inputFromConsole = 2 };
enum exitSettings { wrirteAndIgnore = 1, writeDontIgnore = 2, dontWrite = 3 };
enum writeModSettings { dontIgnoring = 0, ignoring = 1 };
enum writeSettings { toConsole = 0, toFile = 1 };

int main() {
	//settings
	int inputSetting = 0;
	int outputSetting = 0;

	//containers with students
    vector <book*> books;

    cout << "3.1 Task by Mukhametov D.I. 423 group option 1" << endl << endl
        << "Create class student included fields ( surname, first name, patronymic," << endl
        << "date of birth, address, phone, faculty, course.Create an array of objects." << endl << endl
        << "To realize the possibility of obtaining :" << endl
        << "- a list of students of a given faculty," << endl
        << "- lists of students for each faculty and course," << endl
        << "- a list of students born after a given year." << endl << endl;

    while (true) {
        //input
        cout << "How do you want to input information about student (File \"1\" or Console \"2\"): ";
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

        DrawBorder();
        cout << endl << "How do you want to write books to console:" << endl
            << "1.Write to a console ignoring types of books" << endl
            << "2.Write to a console with types of books" << endl
            << "3.Don't write to console" << endl;
        outputSetting = EnterSettingThree();

        //output(to file)
        switch (outputSetting) {
        case(writeDontIgnore): WriteOutput(&books, dontIgnoring, toConsole); break;  //write and don't ignore type of book
        case(wrirteAndIgnore): WriteOutput(&books, ignoring, toConsole); break;        //write and ignore type of book
        case(dontWrite): break;                                                   //nothing :)
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
        case(writeDontIgnore): WriteOutput(&books, dontIgnoring, toFile); break;  //write and don't ignore type of book
        case(wrirteAndIgnore): WriteOutput(&books, ignoring, toFile); break;        //write and ignore type of book
        case(dontWrite): break;                                                //nothing :)
        default: cout << "Unexpected behavior" << endl; continue;
        }

        //ending
        
        
        return 0;
    }
}