
#include "stdafx.h"
#include "Graph.h"
#include <queue>
#include<iostream>
#include <string>
#include<vector>
#include <list>
#include <fstream>



using namespace std;

//empty constructor
Graph::Graph(){};
//creates a graph in adjacency list representation based on info from a file
void Graph::create(string filename){
	PNode * curr=new PNode;   //intermediate variables used throughout the function
	PNode* temp = new PNode;
	int distance, miles;
	string name_temp;
	char person[10];
	fstream file;
	file.open(filename);
	file >> num_pass;     //gets the number of passengers from the first line of the file
	for (int k = 0; k < num_pass; k++){
		headnodes.push_back(curr);      //push nodes onto the vector of nodes. will act as a starting point
										//to branch off for adjacent nodes.
	}
	
	file >> name_temp;              //take in the first name on second line of file
	while (file.peek() != '\n'){     
		//until you hit the new line, keep adding each string as a name in another vector that stores passenger names
		passengers.push_back(name_temp);
		file >> name_temp;
	}
	passengers.push_back(name_temp);
	int t = 0;
	while (file.peek() != EOF){    //add adjacent nodesbased on weight to each head node. do this until end of file
		PNode*curr2 = new PNode;
		curr2->name = passengers[t];    //node's name corresponds to name in passengers vector at position t
		curr2->place = t;             //place of the node in vector
		headnodes[t]=curr2;          //add curr2 to the vector of head nodes as a head node
		for (int i = 0; i < num_pass; i++){    //for each each passenger, conenct the headnode to a new node if they are adjacent
			PNode * tmp = new PNode;    
			tmp->place = i;             //remeber it's place
			tmp->name = passengers[i];   //name of the passenger
			file >> distance;            //weight from headnode to this node (distance from one place to the next)
			if (distance > 0){        //if greater than 0, that means there is a connection and they are adjacent nodes
				tmp->weight = distance;      //store distance as the weight for this tmp node
				curr2->next = tmp;          //connect new node to headnode
				curr2 = curr2->next;     //iterate current
			}
		}
		t++;
	}
	file.close(); file.clear();
}

//function to check if a element is inside a vector
bool Graph::contains(vector<PNode*> visited, string word){
	int flag = 0;
	for (vector<PNode*>::iterator it = visited.begin(); it != visited.end(); it++){
		if ((*it)->name == word) flag=1;   //iterate through vector and return true if found
	}
	return flag;   //else if not found, flag will be 0 and false will be returned
}

void Graph::find_all_paths(int start, vector<PNode*> visited,  string end, int max_length, int min_length){
	if (visited.empty()) visited.push_back(headnodes[start]);  //visited is the vector that stores 
	PNode *curr = new PNode;
	curr = headnodes[start]->next; //start at first point in head nodes
	vector<PNode*> adjNodes;   //vector for adjacent nodes
	while (curr != NULL){   //add adjacent nodes to the vector 
		adjNodes.push_back(curr);  
		curr = curr->next;
	}
	for (vector<PNode*> ::iterator it = adjNodes.begin(); it != adjNodes.end(); it++){ //iterate through the vector of adjacent nodes
		PNode * node = new PNode;  
		node = *it;   
		if (contains(visited, node->name)) continue; //if the node is already in the vector of visited, then continue through loop.
		if (node->name == end){         //if the node is the goal we want to end at
			visited.push_back(*it);    //push the node onto visited
			int length = visited.size();     //find length of the visited vector
			if ((max_length < 1 || length <= max_length) && length >= min_length){  //if the vector is less than max and greater than min
				paths.push_back(visited);           //include it in our vector of paths
				for (int i = 0; i < length; i++){    //print it out to the screen
					cout << visited[i]->name << "->";
				}
				cout << endl;
			}
			
			int n = length - 1;  
			visited.erase(visited.begin() + n);   //erase the contents of visited so another path can be stored in it
			break;
		}
	}
	for (vector<PNode*>::iterator it = adjNodes.begin(); it != adjNodes.end(); it++){  //loop where we recursively call funcition
		PNode* node2 = *it;
		if (contains(visited, node2->name) || node2->name == end) continue;  //if the node is already in visited or is the end, continue through loop
		visited.push_back(node2);  //push node on visited vector
		find_all_paths(node2->place, visited, end,max_length, min_length);  //call find_all_paths using the place of this node as the start
		int n = visited.size() - 1; 
		visited.erase(visited.begin() + n);  //erase contents of visited in order to store another path
	}
}

//funcition that calculates how much to charge passengers based on desired profit and average distance of all paths
float Graph::charge_passengers(int profit){
	float total_distance=0.00;  //total distance traveled
	float average_distance=0.00; //average distance of all paths
	float gas_price = 0.1; //price per mile, based on price of gas in US per galloon and a 30 mpg vehicle
	float fee = 0.00;  //what you will charge the passengers
	int num_paths = paths.size();  //how many paths are there?
	vector< vector<PNode*> >::iterator row;   
	vector<PNode*>::iterator col;
	for (row = paths.begin(); row != paths.end(); row++) {
		int sum = 0;
		for (col = row->begin(); col != row->end(); col++) {
			sum += (*col)->weight;  //sum of each path
		}
		total_distance += sum;  //total distance of all paths combined
		sums.push_back(sum);  //keep track of the sum of each path for other functions
	} 
	average_distance = ((float)total_distance) / num_paths;   //average distance for each path based on number of paths
	fee = ((float) profit/(num_pass-2)) + ((float)(gas_price*average_distance)/3);  //calculate the fee based on profit and average distace
	printf("You should charge $%.2f.\n", fee);  //print info out to console
	
	return fee; //return it for use in main
};

//determines the shortest path in the vector of all relevant paths
int Graph::shortest_path(){
	vector<int> pos;  //vector to keep track of where the position of the shortest path is in vector of paths
	int short_path = 0;  
	int num_paths = paths.size(); //number of paths
	short_path = sums[0];  //start with short_path being the first path in the vector of path sums
	pos.push_back(0);  //push zero on the vector of positions
	for (int i = 1; i < num_paths; i++){   //itereate through sums
		if (sums[i] < short_path){  //if a certain element of sums is less than short_path
			short_path = sums[i];   //update short_path to be that length
			int n = pos.size()-1;    
			pos.erase(pos.begin()+n);//erase pos of all currently held in vector
			pos.push_back(i);  //push new position onto the vector
		}
		else if (sums[i] == short_path){  //if there are equal path lengths
			pos.push_back(i); //include that position as well
		}
	}
	cout << "The shortest path(s): " << endl;   
	int size = pos.size();
	for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++){  //iterate through pos
		//print out the paths at the positon in the paths vector that corresponds to teh value in pos
 		for (vector<PNode*> ::iterator it2 = paths[*it].begin(); it2 != paths[*it].end(); it2++){
			cout << "->" << (*it2)->name;
		}
		cout << endl;
	}
	
	 //print out the shortest path mileage
	cout << "Shortest path total mileage: " << short_path <<" miles."<< endl;
	return short_path; //return for use in main
}
//prints the adjacency list which is a vector to the screen
void Graph::vector_to_screen(){
	
	cout << "------------ADJACENCY LIST REPRESENATION OF GRAPH------------" << endl;
	for (vector<PNode*>::iterator it = headnodes.begin(); it != headnodes.end(); ++it){  //iterate through headnodes
		PNode* temp2 = new PNode;
		temp2 = *it;
		while (temp2 != NULL){
			cout << temp2->name << "->"; //at each headnode print out the nodes that are connected to it until you hit null
			temp2 = temp2->next;
		}
		cout << endl;
	}
		
}