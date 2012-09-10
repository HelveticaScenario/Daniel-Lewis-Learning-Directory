#include "vector.cpp"
#include <iostream>

using namespace std;

int main(){
	vec2 vec(14, 27);

	cout << vec.get_x() << endl;
	cout << vec.get_y() << endl;
	cout << vec.get_unit_x() << endl;
	cout << vec.get_unit_y() << endl;
	cout << vec.get_mag() << endl;

	vec.set_x(5.0);
	vec.set_y(35.0);

	cout << endl;
	cout << vec.get_x() << endl;
	cout << vec.get_y() << endl;
	cout << vec.get_unit_x() << endl;
	cout << vec.get_unit_y() << endl;
	cout << vec.get_mag() << endl;
	
	vec.set_mag(15.0);

	cout << endl;
	cout << vec.get_x() << endl;
	cout << vec.get_y() << endl;
	cout << vec.get_unit_x() << endl;
	cout << vec.get_unit_y() << endl;
	cout << vec.get_mag() << endl;

	return 0;
}