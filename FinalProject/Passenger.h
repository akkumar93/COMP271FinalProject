#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED

#endif   //PASEENGER_H_INCLUDED

#define coord 2



class Passenger{
private:
	string name;
	int start[coord];
	int end[coord];
	int distance;
public:
	Passenger();
	Passenger(string filename);
	int calc_distance(int a[], int b[]);

}
