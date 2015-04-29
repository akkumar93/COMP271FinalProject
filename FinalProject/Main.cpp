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
	int fee;
	int shortest;
	Graph passGraph;
	passGraph.create("PassengerList.txt");
	//passGraph.find_all_paths(0);
	//passGraph.write_out();
	vector<PNode*> visited;
	passGraph.find_all_paths(0, visited, "theater", -1, 8);
	passGraph.vector_to_screen();
	fee = passGraph.charge_passengers();
	shortest = passGraph.shortest_path();

}
