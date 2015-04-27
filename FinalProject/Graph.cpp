#include "Graph.h"


#include <string>
#include<vector>
#include <list>
#include <fstream>



using namespace std;

void Graph::create(string filename){
	int temp, distance;
	char person[50];
	fstream file;
	file.open(filename);
	file >> temp;
	for (int i = 0; i < num_pass; i++){
		while (file.peek() != '\n'){
			for (int j = 0; j < num_pass; j++){
				file.getline(person, 50, '	');
				passMatrix[i][j].name = person;
				file >> passMatrix[i][j].cost;
				file >> passMatrix[i][j].weight;
			}
		}

	}
	file.close(); file.clear();
}