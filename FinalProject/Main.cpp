// FinalProject.cpp : Defines the entry point for the console application.
//
/*The problem here is that you have an n number of friends who want a ride. They are willing to pay however, which is nice.
You want to determine how much to charge your friends so that you can have money left over for a movie. The program reads in 
a file with the passenger information and creates a graph in adjacency list form. Then, all the possible paths in which you visit
friend are determine and the total miles each takes. From there, the average distance of a trip is calculated in order to determine
a fair price that would still give you the desired profit. Since you are intelligent, you also determine the shortest path so 
that you can maximize your profits using the fee for the average mileage. All the relevant information is printed to the console
as well as the adjacency list representation of the graph and all the relevant paths.*/

#include "stdafx.h"
#include <vector>
#include<iostream>
#include<fstream>
#include<string>

#include "Graph.h"


using namespace std;

void main(){
	float fee;  //fee that will be charged to the passengers
	int shortest; //shortest path length
	float earnings;  //how much you will make
	int profit;
	Graph passGraph;  //the graph of passengers
	string filename;  //name of file that has information
	cout << "Enter the file name with all passengers: ";
	cin >> filename;
	cout << "How much would you like to make?";  //ask the user how much money they would like to make
	cin >> profit;
	cout << string(2, '\n');
	passGraph.create(filename);//create the graph 
	passGraph.vector_to_screen(); //print the adjacency list representation to the screen
	cout << endl;
	cout << "------------ALL-PASSENGER INCLUSIVE PATHS FROM HOME TO THEATER------------" << endl;
	vector<PNode*> visited;  //vector of visited nodes to store paths which will then be stored in a vector of vectors called paths
	passGraph.find_all_paths(0, visited, "theater", -1, 6); //find all the paths of the specified length
	cout << endl;
	cout << "------------IMPORTANT/RELEVANT INFORMATION FOLLOWS------------" << endl;
	fee = passGraph.charge_passengers(profit);  //determine the fee that will be charged for each passenger
	shortest = passGraph.shortest_path();  //determine the miles in the shortest path 
	earnings = ((float)4 * (fee))-((float)(0.1)*(shortest));  //calculated the total earnings if you charged for average case and used shortest path
	printf("If you take the shortest path, you will make $%.2f.\n", earnings);
}
