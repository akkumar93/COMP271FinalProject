// FinalProject.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <math>
#include<fstream>
#include<string>
#include "stdafx.h"
#define coord=2
using namespace std;

class Passenger{
  private:
    string name;
    int start[coord];
    int end[coord];
    int distance;
  public:
    passenger();
    passenger(string filename){
      fstream in;
      in.open(filename);
      while(!in.peek()='\n'){
        in.getline(name, 10, '  ');
        in>>start[0];
        in>>start[1];
        in>>end[0];
        in>>end[1];
      }
      distance=get_distance(start, end);
    }
    int get_distance(int a[], int b[]){
      distance=sqrt((b[0]-a[0])^2 + (b[1]-[1])^2);
      return distance;
    }
}

class GraphNode
{
  public: 
    int vertex;
    GraphNode * next;
    GraphNode(){
      vertex=0;
      next=NULL;
    }
    
};
class Graph
{
  GraphNode * headnodes[max];
  int n;
  int visited[max];
  public: 
    Graph();
    void create();
    void initialize_visited();
    
};
Graph::Graph(){
  for(int i=0; i<max; i++){
    headnodes[i]=NULL;
  }
}
void Graph::create(){
  GraphNode *curr, *prev;
  int n1, i, j, vertex, done=false;
  
}
