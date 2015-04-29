#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#endif   //GRAPH_H_INCLUDED

#include <string>
#include<fstream>
#include<vector>
#include <list>
using namespace std;


//node type used for the adjacency list and graph respresentation of data
class PNode
{
public:
	string name;  //name of passenger
	int weight;  //weight of edge from to this passenger
	int place;   //place in the a vector
	PNode * next;
	PNode(){ //initialize the pnode as all empty
		name = "";
		weight = 0;
		place = 0;
		next = NULL;
	}
};
//actual graph and all its components/functions
class Graph
{
	vector<PNode*> headnodes;  //vector of headnodes for adjacency list representation
	int num_pass;    //number of passengers
	vector<string> passengers;   //vector to store the name of passengers. used in create function to set name of nodes
	vector<vector<PNode*>> paths; //vector of vectors to store all possible paths between the two nodes
	vector<int> sums;   //vector of sums that keeps track of the length of all paths
public:
	
	Graph();    //constructor
	void create(string filename);  //creates the graph
	bool contains(vector<PNode*> visited, string word);   //check to see if a string is in the vector of visited
	/*find all paths between start and end, with a vector of visited nodes, and a max path length and min path length*/
	void find_all_paths(int start, vector<PNode*> visited, string end,int max_length, int min_length);
	void vector_to_screen(); //prints a vector to screen, in this case prints the graph as an adjacency list representation to screen
	float charge_passengers(int profit);  //calculates the fee for the passengers
	int shortest_path();  //finds the shortest path in the vector of paths

};