// FinalProject.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <cmath>
#include<fstream>
#include<string>
#include "stdafx.h"
#define coord 2
using namespace std;


Graph::Graph(){
  for(int i=0; i<max; i++){
    headnodes[i]=NULL;
  }
}
void Graph::create(){
  GraphNode *curr, *prev;
  int n1, i, j, vertex, done=false;
  
}
