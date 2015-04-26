#include "Passenger.h"
#include <iostream>
#include <string>
#include <fstream>




using namespace std;


Passenger::Passenger(string filename){
	ifstream in;
	in.open(filename);
	while (!in.peek() = '\n'){
		in.getline(name, 10, '  ');
		in >> start[0];
		in >> start[1];
		in >> end[0];
		in >> end[1];
	}
	distance = calc_distance(start, end);
}


int Passenger::calc_distance(int a[], int b[]){
	distance = sqrt((b[0] - a[0]) ^ 2 + (b[1] - [1]) ^ 2);
	return distance;
}
}