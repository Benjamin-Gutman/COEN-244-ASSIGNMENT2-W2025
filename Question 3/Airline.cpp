/*
 * Airline.cpp
 *
 *  Created on: Feb 19, 2025
 *      Author: jiyongjeon
 */

#include "Airline.h"
#include <iostream>
#include <algorithm>

// Constructor to initialize the airline with a name and address
Airline::Airline(string name, string address) : companyName(name), headquartersAddress(address) {}

// Copy constructor
Airline::Airline(const Airline& other) : companyName(other.companyName), headquartersAddress(other.headquartersAddress), flights(other.flights) {}

// Destructor
Airline::~Airline() {}

// Adds a flight to the airline's flight list
void Airline::addFlight( Flight flight) {
    flights.push_back(flight);
}

// Removes a flight from the airline's list based on its ID
//void Airline::removeFlight(const string& flightId) {
//    vector<Flight>::iterator it = flights.begin();
//    while (it != flights.end()) {
//        if (it->getId() == flightId) {
//            it = flights.erase(it); // Erases the flight and updates the iterator
//        } else {
//            ++it;
//        }
//    }
//}

void Airline::removeFlight(string flightId) {
	for (int i = 0; i< flights.size(); i++){
        if (flights[i].getId() == flightId) {
            flights.erase(flights.begin() + i);// Erases the flight and updates the iterator
            break;
        }
    }
}


// Searches for a flight by ID and returns true if found in the list
bool Airline::searchFlight(string flightId){
   for (int i =0; i<flights.size(); i++){
	   if (flights[i].getId() == flightId) {
		   return true;
       }
    }
    return false;
}

// Displays all flights in the airline's list
void Airline::displayFlights(){
    for (int i = 0; i < flights.size(); i++) {
        flights[i].printFlightInfo();
    }
}

// Displays flights that depart from and arrive at specified cities
void Airline::displayFlightsFromTo(string from, string to){
    for (int i  = 0; i < flights.size(); i++) {
        if (flights[i].getDepartureCity() == from && flights[i].getArrivalCity() == to) {
            flights[i].printFlightInfo();
        }
    }
}
