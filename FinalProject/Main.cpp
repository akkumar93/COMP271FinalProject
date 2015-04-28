// FinalProject.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <cmath>
#include<fstream>
#include<string>
#include "stdafx.h"
#include "Graph.h"


#define coord 2
using namespace std;

void main(){
	vector<list<Passenger>> paths;
	Graph passGraph("PassengerList.txt");
	passGraph.create("PassengerList.txt");
	passGraph.write_out();
	paths= passGraph.find_all_paths(0);
	passGraph.vector_to_screen(paths);
}
