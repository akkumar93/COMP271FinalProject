
#include "stdafx.h"
#include "Graph.h"
#include <queue>
#include<iostream>
#include <string>
#include<vector>
#include <list>
#include <fstream>



using namespace std;

Graph::Graph(){};

void Graph::create(string filename){
	PNode * curr=new PNode;
	PNode* temp = new PNode;
	int distance, miles;
	string name_temp;
	char person[10];
	fstream file;
	file.open(filename);
	file >> num_pass;
	for (int k = 0; k < num_pass; k++){
		headnodes.push_back(curr);
	}
	file >> name_temp;
	while (file.peek() != '\n'){
		//name_temp = person;
		passengers.push_back(name_temp);
		file >> name_temp;
	}
	passengers.push_back(name_temp);
	int t = 0;
	while (file.peek() != EOF){
		PNode*curr2 = new PNode;
		headnodes[t]=curr2;
		for (int i = 0; i < num_pass; i++){
			PNode * tmp = new PNode;
			tmp->name = passengers[i];
			file >> distance;
			if (distance > 0){
				tmp->weight = distance;
				curr2->next = tmp;
				curr2 = curr2->next;
			}
		}
		t++;
	}
	file.close(); file.clear();
	//start->p = passMatrix[0][0];
}

/*void Graph::write_out(){
	int i;
	for (i = 0; i < num_pass; i++){
		for (int j = 0; j < num_pass; j++){
			cout << passMatrix[i][j].col<< "\t";
		}
		cout << endl;
	}

	
}

vector<PNode*> Graph::find_all_paths(int row){
	queue<Passenger> nodes;
	vector<list<Passenger>> paths;
	list<Passenger> sing_path;
	Passenger p;
	for (int i = 0; i < num_pass; i++){
		if (passMatrix[row][i].weight > 0 && passMatrix[row][i].visited!=1){
			nodes.push(passMatrix[row][i]);
		}
	}
	while (!nodes.empty()){
		p=nodes.front();
		sing_path.push_back(p);
		for (int i = 0; i < num_pass; i++){
			passMatrix[i][p.col].visited = 1;  //set all the values in the column as visited
		}
		
		paths=find_all_paths(row+1);
		paths.push_back(sing_path);
		nodes.pop();
	}
	
	return paths;
}

vector<list<Passenger>> Graph::BFS(string start, string goal){
	/*queue to store the adjacent nodes*/
	/*start search at the row with name "start"*/
	/*mark all vertices as unvisited*/
	/*mark start as visited*/
	/*add start to teh queue*/
	/*mark nodes in the queue as visited*/
	/*while queue is not empty*/
	/*delete top from queue*/
	/*

	queue<Passenger> q;
	vector<list<Passenger>> paths;
	list<Passenger> sing_path;
	for (int i = 0; i < num_pass; i++){
		if (passMatrix[i][i].name == start){
			q.push(passMatrix[i][i]);

		}
		for (int j = 0; j < num_pass; j++){
			passMatrix[i][j].visited = 1;
		}
	}
	while (!q.empty()){
		sing_path.push_back(q.front());
		
		for (int k = 0; k < num_pass; k++){
			if (passMatrix[q.front().col][k].weight > 0 && passMatrix[q.front().col][k].visited != 1){
				q.push(passMatrix[q.front().col][k]);
				for (int m = 0; m < num_pass; m++){
					passMatrix[q.front().col][k].visited = 1;
				}
			}
		}
		BFS(q.front().name, goal);
		paths.push_back(sing_path);
		q.pop();
		
	}
	return paths;
}*/


void Graph::vector_to_screen(){
	 
	for (vector<PNode*>::iterator it = headnodes.begin(); it != headnodes.end(); ++it){
		PNode* temp2 = new PNode;
		temp2 = *it;
		while (temp2 != NULL){
			cout << temp2->name << "->";
			temp2 = temp2->next;
		}
		cout << endl;
	}
		
}