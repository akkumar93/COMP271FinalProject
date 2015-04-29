#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#endif   //GRAPH_H_INCLUDED

#include <string>
#include<fstream>
#include<vector>
#include <list>
using namespace std;



class PNode
{
public:
	string name;
	int weight;
	int place;
	PNode * next;
	PNode(){
		name = "";
		weight = 0;
		place = 0;
		next = NULL;
	}
};

class Graph
{
	vector<PNode*> headnodes;
	int num_pass;
	vector<string> passengers;
	vector<vector<PNode*>> paths;
public:
	
	Graph();
	void create(string filename);
	void write_out();
	bool contains(vector<PNode*> visited, string word);
	void find_all_paths(int start, vector<PNode*> visited, string end,int max_length, int min_length);
	void vector_to_screen();
	int charge_passengers();
	int shortest_path();

};