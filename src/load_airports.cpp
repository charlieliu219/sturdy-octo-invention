#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "weighted_struct_digraph.h"

using namespace std;
// user defined: it can store arbitrary attributes, in any fixed form at compile-time, in the nodes
// each node (airport) represents a tuple in airport.csv
// Read the data from data/airports.csv as nodes in your graph and store relevant attributes in the nodes. Additionally, read the data from data/routes.csv as edges in your graph, using the Time column as the edge weight. 
struct Airport {
    int id;
    string name;
    // string city;
    // string country;
    // string IATA;
    // string ICAO;
    // double latitude;
    // double longitude;
    // int altitude;
    // int Timezone;
    // string dst;
    // string TZ;
    // string type;
    // string source;

    bool operator<(const Airport& rhs) const { return id < rhs.id; }
    bool operator>(const Airport& rhs) const { return id > rhs.id; }
    bool operator==(const Airport& rhs) const { return id == rhs.id; }
};

// // a function to turn csv file tuple into vector pointer
// vector<vector<string>>* file_to_vector(string file_name){
//     vector<vector<string>> vec_of_tuples; // vector of tuples

//     ifstream fs(file_name);
//     if (!fs.is_open()){
//         cout << "File was not open!" << endl;
//         return nullptr;
//     }

//     string line;
//     while (getline(fs, line)){
//         stringstream ss(line);
//         string value;
//         vector<string> tuple;
        
//         while (getline(ss, value, ',')){
//             tuple.push_back(value);
//         }
//         vec_of_tuples.push_back(tuple);
//     }

//     fs.close();
//     return &vec_of_tuples;
// }


// Implement the loading of the graph in load_airports.cpp::load_data. The function should receive the file paths for airports.csv and routes.csv as its first and second arguments, respectively.
WeightedStructDigraph<Airport>* load_data(string airports_file,
                                          string routes_file) {
    
    // read from airport file
    vector<Airport> airport_list;

    ifstream airports_stream(airports_file); // airports file = "data/airport.csv"
    if (!airports_stream.is_open()){
        cout << "Airport file was not open!" << endl;
        return nullptr;
    }
    string line;
    while (getline(airports_stream, line)){
        stringstream ss(line);
        string value;
        vector<string> values;

        while (getline(ss, value, ',')){
            values.push_back(value);
        }

        Airport airport;
        airport.id = stoi(values[0]);
        airport.name = values[1];

        airport_list.push_back(airport);
    }

    WeightedStructDigraph<Airport>* sdg = new WeightedStructDigraph<Airport>(airport_list);

    // update the symbol table: node - id 
    for (auto airport : airport_list){
        sdg->st->put(airport, airport.id);
    }


    //read from routes file
    ifstream routes_stream(routes_file); // airports file = "data/airport.csv"
    if (!routes_stream.is_open()){
        cout << "Routes file was not open!" << endl;
        return nullptr;
    }
    string line;
    while (getline(airports_stream, line)){
        stringstream ss(line);
        string value;
        vector<string> route_values;

        while (getline(ss, value, ',')){
            route_values.push_back(value);
        }

        int v = stoi(route_values[3]); // id of source airport
        int v = stoi(route_values[5]); // id of destination
        auto time = stoi(route_values[9]);

        sdg->add_edge()


    }

    for (auto route : route_values){


    }

    
    return sdg;
}