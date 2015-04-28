#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#endif   //GRAPH_H_INCLUDED

#include <string>
#include<fstream>
#include<vector>
#include <list>
using namespace std;



class Passenger
{
public:
	string name;
	int cost;
	int weight;
	int col;
	bool visited;

};
class PNode
{
public:
	string name;
	int weight;
	int cost;
	PNode * next;
	PNode(){
		name = "";
		weight = 0;
		cost = 0;
		next = NULL;
	}
};

//PNode * start;
//PNode *curr;
class PAdjList{
	PNode * head;
};

class Graph
{
	vector<PNode*> headnodes;
	int num_pass;
	vector<string> passengers;
public:
	
	Graph();

	/*Graph(string filename){
		fstream in;
		in.open(filename);
		in >> num_pass;
		for (int i = 0; i < num_pass; i++){
			
		}
		in.close(); in.clear();
		
		
	}
	~Graph(){
		for (int i = 0; i < num_pass; i++){
			delete[] passMatrix[i];
		}
		delete passMatrix;
	}*/


	void create(string filename);
	void write_out();
	vector<list<Passenger>> BFS(string start, string goal);
	vector<PNode*> find_all_paths(int row);
	void vector_to_screen();
	int total_cost();

};