#include "classes.h"
//#include "Interface.h"
#include <vector>

using namespace std;

enum inputSettings { inputFromFile = 1, inputFromConsole = 2 };
enum exitSettings { oldStudent = 1, newStudent = 2, closeProgram = 3 };

int main() {

	vector <book> b;


	for (auto i = 0; i < b.size(); ++i ) {
		b[i].Show();
	}

 
	return 0;
}