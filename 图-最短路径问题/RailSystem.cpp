#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "RailSystem.h"
#define INFTY 2147483647;

void RailSystem::reset(void) {

    // TODO: reset the data objects of the 
    // City objects' contained in cities
	map<string, City*>::iterator it;
	for(it = cities.begin(); it != cities.end(); it++)
	{
		it->second->visited = false;
		it->second->total_fee = INFTY;
		it->second->total_distance = INFTY;
		it->second->from_city = "";
	}
    
}

RailSystem::RailSystem(string const &filename) {
    
    load_services(filename);
}

void RailSystem::load_services(string const &filename) {

	ifstream inf(filename.c_str());
	string from, to;
	int fee, distance;

	while ( inf.good() ) {

		// Read in the from city, to city, the fee, and distance.
		inf >> from >> to >> fee >> distance;

		if ( inf.good() ) {
		
			// TODO: Add entries in the cities container and
			// and services in the rail system for the new 
            // cities we read in.

			Service *service = new Service(to, fee, distance);

			if(cities.find(from) == cities.end())
			{
				//cout<<from;
				City *city1 = new City(from);
				cities.insert(pair<string, City*>(from, city1));
			}

			if(cities.count(to) == 0)
			{
				//cout<<to;
				City *city2 = new City(to);
				cities.insert(pair<string, City*>(to, city2));
			}

			outgoing_services[from].push_back(service);

		}
	}

	inf.close();
}

RailSystem::~RailSystem(void) {

    // TODO: release all the City* and Service*
    // from cities and outgoing_services
	map<string, City*>::iterator it1;
	for(it1 = cities.begin(); it1 != cities.end(); it1++)
		delete it1->second;
	
	map<string, list<Service*> >::iterator it2;
	for(it2 = outgoing_services.begin(); it2 != outgoing_services.end(); it2++)
	{
		list<Service*> temp = it2->second;
		list<Service*>::iterator it3;
		for(it3 = temp.begin(); it3 != temp.end(); it3++)
			delete *it3;
			
	}
}

void RailSystem::output_cheapest_route(const string& from,
                const string& to, ostream& out) {

	reset();
	pair<int, int> totals = calc_route(from, to);

	if (totals.first == INT_MAX) {
		out << "There is no route from " << from << " to " << to << "\n";
	} else {
		out << "The cheapest route from " << from << " to " << to << "\n";
		out << "costs " << totals.first << " euros and spans " << totals.second
			<< " kilometers\n";
        cout << recover_route(to) << "\n\n";
	}
}

bool RailSystem::is_valid_city(const string& name) {

	return cities.count(name) == 1;
}

pair<int, int> RailSystem::calc_route(string from, string to) {

	priority_queue<City*, vector<City*>, Cheapest> candidates;

    // TODO: Implement Dijkstra's shortest path algorithm to
    // find the cheapest route between the cities
	cities[from]->visited = true;
	cities[from]->from_city = from;
	cities[from]->total_distance = 0;
	cities[from]->total_fee = 0;

	list<Service*>::iterator it;
	map<string, City*>::iterator it1;
	string fromTemp = from;

	while(!cities[to]->visited)
	{
		list<Service*> temp = outgoing_services[fromTemp];
		//cout<<"Thee check: "<<fromTemp<<endl;

	    for(it = temp.begin(); it != temp.end(); it++)
		{
    		Service* service = *it;
	    	City* city = new City(service->destination);
			if(city->visited == false)
			{
				if(cities[fromTemp]->total_fee + service->fee < city->total_fee)
				{
					 city->total_fee = cities[fromTemp]->total_fee + service->fee;
					 city->total_distance = cities[fromTemp]->total_distance
						 + service->distance;
					 city->from_city = fromTemp;
					 candidates.push(city);
					 //cout<<"Push: "<<city->name<<endl;
				}			
			}
		}

		while(cities[candidates.top()->name]->visited == true)
			candidates.pop();

        fromTemp=candidates.top()->from_city;
	    //cout<<"TOP: "<<candidates.top()->name<<"   "<<fromTemp<<endl;

        fromTemp = candidates.top()->name;
		cities[fromTemp] = candidates.top();
		cities[fromTemp]->visited = true;
	   	candidates.pop();		
	}
		
	// Return the total fee and total distance.
	// Return (INT_MAX, INT_MAX) if not path is found.
	if (cities[to]->visited) {
		return pair<int,int>(cities[to]->total_fee, cities[to]->total_distance);
	} else {
		return pair<int,int>(INT_MAX, INT_MAX);
 	}

}

string RailSystem::recover_route(const string& city) {
	
	// TODO: walk backwards through the cities
	// container to recover the route we found

	list<City*>::iterator it;
	list<City*> backwards;
	backwards.push_back(cities[city]);
	City *fromCity = cities[city];

	while(cities[fromCity->name]->name != fromCity->from_city)
	{
		fromCity = cities[fromCity->from_city];
		backwards.push_front(fromCity);
	}

	string route;
	string temp = "";
	route = backwards.front()->name;
	backwards.pop_front();
	while(temp != city)
	{
		//cout<<"aaa";
		temp = backwards.front()->name;
		//cout<<temp;
		backwards.pop_front();
		//cout<<backwards.front()->name;
		route += " to " + temp;
	}
	return route;
}
