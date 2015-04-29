
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
		curr2->name = passengers[t];
		curr2->place = t;
		headnodes[t]=curr2;
		for (int i = 0; i < num_pass; i++){
			PNode * tmp = new PNode;
			tmp->place = i;
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
}
bool Graph::contains(vector<PNode*> visited, string word){
	int flag = 0;
	for (vector<PNode*>::iterator it = visited.begin(); it != visited.end(); it++){
		if ((*it)->name == word) flag=1;
	}
	return flag;
}

void Graph::find_all_paths(int start, vector<PNode*> visited,  string end, int max_length, int min_length){
	  //keep track of visited nodes
	/*for (int i = 0; i < num_pass; i++){ //set them to false
		visited[i] = false;
	}*/
	visited.push_back(headnodes[start]);
	PNode *curr = new PNode;
	curr = headnodes[start]->next; //start at first point in head nodes
	vector<PNode*> adjNodes;   //vector for adjacent nodes
	while (curr != NULL){   //add adjacent nodes to the vector 
		adjNodes.push_back(curr);  
		curr = curr->next;
	}
	for (vector<PNode*> ::iterator it = adjNodes.begin(); it != adjNodes.end(); it++){
		PNode * node = new PNode;
		node = *it;
		if (contains(visited, node->name)) continue;
		if (node->name == end){
			visited.push_back(*it);
			int length = visited.size();
			if ((max_length < 1 || length <= max_length) && length >= min_length){
				paths.push_back(visited);
				for (int i = 0; i < length; i++){
					cout << visited[i]->name << "->";
				}
				cout << endl;
			}
			
			int n = length - 1;
			visited.erase(visited.begin() + n);
			break;
		}
	}
	for (vector<PNode*>::iterator it = adjNodes.begin(); it != adjNodes.end(); it++){
		PNode* node2 = *it;
		if (contains(visited, node2->name) || node2->name == end) continue;
		visited.push_back(node2);
		find_all_paths(node2->place, visited, end,max_length, min_length);
		int n = visited.size() - 1;
		visited.erase(visited.begin() + n);
	}
}


int Graph::charge_passengers(){
	vector<int>sums;
	int total_distance=0;
	double average_distance=0.00;
	int profit = 15;
	float gas_price = 0.0843;
	double fee = 0.00;
	int num_paths = paths.size();
	vector< vector<PNode*> >::iterator row;
	vector<PNode*>::iterator col;
	for (row = paths.begin(); row != paths.end(); row++) {
		int sum = 0;
		for (col = row->begin(); col != row->end(); col++) {
			sum += (*col)->weight;
		}
		sums.push_back(sum);
	}
	for (int i = 0; i < num_paths; i++){
		cout << sums[i] << endl;
	}
	for (int j = 0; j < num_paths; j++){
		total_distance += sums[j];
	}
	average_distance = ((double)total_distance) / num_paths;
	cout << average_distance << endl;
	fee = ((double) profit/3) + ((double)(gas_price*average_distance)/3);
	cout << "You should charge $" << fee << endl;
	return fee;
};

int Graph::shortest_path(){
	vector<int>sums;
	vector<int> pos;
	int short_path = 0;
	int num_paths = paths.size();
	vector< vector<PNode*> >::iterator row;
	vector<PNode*>::iterator col;
	for (row = paths.begin(); row != paths.end(); row++) {
		int sum = 0;
		for (col = row->begin(); col != row->end(); col++) {
			sum += (*col)->weight;
		}
		sums.push_back(sum);
	}
	short_path = sums[0];
	pos.push_back(0);
	for (int i = 1; i < num_paths; i++){
		if (sums[i] < short_path){
			short_path = sums[i];
			int n = pos.size()-1;
			pos.erase(pos.begin()+n);
			pos.push_back(i);
		}
		if (sums[i] == short_path){ 
			pos.push_back(i); 
		}
	}
	cout << "The shortest path(s): " << endl;
	int size = pos.size();
	for (int p = 0; p < size; p++){
		for (vector<PNode*> ::iterator it2 = paths[p].begin(); it2 != paths[p].end(); it2++){
			cout << "->" << (*it2)->name;
		}
		cout << endl;
	}
	

	cout << "These paths have total mileage of " << short_path << endl;
	return short_path;
}

void Graph::vector_to_screen(){
	
	cout << "------------ADJACENCY LIST REPRESENATION OF GRAPH------------" << endl;
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