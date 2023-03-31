#include "classes.h"
#include "Interface.h"

enum inputSettings { inputFromFile = 1, inputFromConsole = 2 };
enum exitSettings { oldStudent = 1, newStudent = 2, closeProgram = 3 };

int main() {

	vector <book*> *b = new vector <book*>;

	InputFromFile(b);
	
	for (auto i = 0; i < b->size(); ++i ) {
		if (dynamic_cast<techBook*>(b[0][i])) {
			cout << "Tech book" << endl;
		}
		else if (dynamic_cast<book*>(b[0][i])) {
			cout << "Book" << endl;
		}
		
	}

 
	return 0;
}