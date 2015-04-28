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
	Passenger p;
	PNode * next;
	PNode(){
		p.name = "";
		p.cost = 0;
		p.weight = 0;
		p.col = 0;
		p.visited = 0;
		next = NULL;
	}
};
//PNode * start;
//PNode *curr;

class Graph
{
	Passenger ** passMatrix;
	int num_pass;
	
public:
	
	Graph();
	Graph(string filename){
		fstream in;
		in.open(filename);
		in >> num_pass;
		passMatrix = new Passenger*[num_pass];
		for (int i = 0; i < num_pass; i++){
			passMatrix[i] = new Passenger[num_pass];
		}
		in.close(); in.clear();
		for (int k = 0; k < num_pass; k++){
			for (int m = 0; m < num_pass; m++){
				passMatrix[k][m].name = "";
				passMatrix[k][m].cost = 0;
				passMatrix[k][m].weight = 0;
				passMatrix[k][m].visited = 0;
			}
		}
		
	}
	~Graph(){
		for (int i = 0; i < num_pass; i++){
			delete[] passMatrix[i];
		}
		delete passMatrix;
	}
	void create(string filename);
	void write_out();
	vector<list<Passenger>> find_all_paths(int row);
	void vector_to_screen(vector<list<Passenger>> node);
	int total_cost();

};