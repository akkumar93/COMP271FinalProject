#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#endif   //GRAPH_H_INCLUDED

#include <string>
#include<vector>
#include <list>
using namespace std;



class Passenger
{
public:
	string name;
	int cost;
	int weight;

};
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

	}
	~Graph(){
		for (int i = 0; i < num_pass; i++){
			delete[] passMatrix[i];
		}
		delete passMatrix;
	}
	void create(string filename);


};