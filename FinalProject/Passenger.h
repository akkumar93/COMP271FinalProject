#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED

#endif   //PASEENGER_H_INCLUDED

#define coord 2



class Passenger{
private:
	int name;
	/*int start[coord];
	int end[coord];*/
	int distance;
	int costPass;
public:
	Passenger();
	int calc_distance(int a[], int b[]);
	int calc_cost(int dist);
};