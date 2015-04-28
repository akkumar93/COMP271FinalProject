
#include "stdafx.h"
#include "Graph.h"
#include <queue>
#include<iostream>
#include <string>
#include<vector>
#include <list>
#include <fstream>



using namespace std;

void Graph::create(string filename){
	int temp, distance, miles;
	char person[10];
	fstream file;
	file.open(filename);
	file >> temp;
	while (file.peek() != EOF){
		for (int i = 0; i < num_pass; i++){
			file.getline(person, 10, '	');
			file >> miles;
			for (int j = 0; j < num_pass; j++){
				passMatrix[i][j].name = person;
				passMatrix[i][j].cost=miles;
				file >> passMatrix[i][j].weight;
				passMatrix[i][j].col = j;
			}
		}
	}
	file.close(); file.clear();
	//start->p = passMatrix[0][0];
}

void Graph::write_out(){
	int i;
	for (i = 0; i < num_pass; i++){
		for (int j = 0; j < num_pass; j++){
			cout << passMatrix[i][j].weight<< "\t";
		}
		cout << endl;
	}

	
}

vector<list<Passenger>> Graph::find_all_paths(int row){
	queue<Passenger> nodes;
	vector<list<Passenger>> paths;
	list<Passenger> sing_path;
	Passenger p;
	for (int i = 0; i < num_pass; i++){
		if (passMatrix[row][i].weight > 0 &&passMatrix[row][i].visited!=1){
			nodes.push(passMatrix[row][i]);
		}
	}
	while (!nodes.empty()){
		p=nodes.front();
		sing_path.push_back(p);
		for (int i = 0; i < num_pass; i++){
			passMatrix[i][p.col].visited = 1;  //set all the values in the column as visited
		}
		
		paths=find_all_paths(++row);
		nodes.pop();
	}
	paths.push_back(sing_path);
	return paths;
}

void Graph::vector_to_screen(vector<list<Passenger>> node){

	for (int i = 0; i < node.size(); i++){
		for (list<Passenger>::iterator it2 = node[i].begin(); it2 != node[i].end(); ++it2){
			cout << it2->name << "->";
		}
		cout << endl;
	}
}