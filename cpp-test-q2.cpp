#include <iostream>
using namespace std;

class CountableObject{


private:
	static int number_of_objects;


public:

	// construct
	CountableObject() {
		number_of_objects++;
	}
	// destructor
	~CountableObject() {
		number_of_objects--;
	}



	int nobjs(){
		return number_of_objects;
	}

	static void print_nobjs(){
		cout << "Number of objects: " << number_of_objects << endl;
	}


};

int CountableObject::number_of_objects = 0;

int main() {

	CountableObject a, b, c;
	CountableObject* test = new CountableObject();
	CountableObject::print_nobjs();

	delete test;

	CountableObject::print_nobjs();

	return 0;
}

// assumptions:
// counting only initialised objects
// assumes that all objects not in use are deleted
// assumes number_of_objects is initialised to 0
