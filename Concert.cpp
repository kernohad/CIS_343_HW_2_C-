/*********************************************************
*	A file that implements the Concert.h
*	
*	Created by: Dylan Kernohan on 10/2/2017
**********************************************************/

#include "Concert.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>



/*************************************************************************************
*	Default Constructor
*************************************************************************************/
Concert::Concert(){
	concertName = "";
	friends.clear();
	desire = -1;
	date.tm_year = 2099;
	date.tm_mon = 1;
	date.tm_mday = 1;
}


/*************************************************************************************
*	Constructor
*************************************************************************************/
Concert::Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date ){
	this -> concertName = concertName;
	this -> friends = friends;
	this -> desire = desire;
	this -> date = date;

}

// Getters

/*************************************************************************************
*	Get the Concert Name
*************************************************************************************/
std::string Concert::getConcertName() const{
	return concertName;
}

/*************************************************************************************
*	Get the Concert Friend Vector
*************************************************************************************/
std::vector<std::string> Concert::getFriends() const{
	return friends;
}

/*************************************************************************************
*	Get the Concert Desire
*************************************************************************************/
int Concert::getDesire() const{
	return desire;
}

/*************************************************************************************
*	Get the Concert Date
*************************************************************************************/
std::tm Concert::getDate() const{
	return date;
}



/************************************************************************************
*	< Operator Overload
*
*	Compare a concert by date first
*	then its desire
*
*	If the concert date is closer, the concert is higher priority (greater than) 
*************************************************************************************/
bool Concert::operator<(const Concert& other) const{


    if (date.tm_year > other.date.tm_year){
        return true;
    }
    else if (date.tm_year == other.date.tm_year){
        if(date.tm_mon > other.date.tm_mon){
            return true;
        }
        else if(date.tm_mon == other.date.tm_mon){
            if(date.tm_mday > other.date.tm_mday)
                return true;
            else if(date.tm_mday == other.date.tm_mday){
                if(desire < other.desire){
                    return true;
                }
            }
        }
    }


    return false;

}


/*************************************************************************************
*	<< Operator Overload
*
*	Allows the user to cout<< a Concert object easily
*************************************************************************************/
std::ostream& operator<<(std::ostream& out, const Concert& c) {

	// Gets the date of the concert
	std::tm date = c.getDate();

	// Gets the friends vector of the concert
	std::vector<std::string> friendsVector = c.getFriends();

	// Creates a string that will store all the friends
	std::string friends = "{";

	// Iterates throught he friends vector and stores each friend into the friend string
	for (int i = 0; i < friendsVector.size(); i++){
		// Checks to see if it is the last friend in the vector to add a comma or not
		if(i != friendsVector.size() - 1)
			friends += friendsVector[i] + ", ";
		else
			friends += friendsVector[i];
	}

	friends += "}";
	
	// Formats the out stream of the  Concert object
    out << '(' << c.getConcertName() << ": " << date.tm_mon << "/" << date.tm_mday << "/" << date.tm_year << " | " << c.getDesire() << " | " << friends << ')' << "\n";

    return out;
    }





/*************************************************************************************
*	Main
*************************************************************************************/
int main(int argc, char* argv[]){

	// Concert 1
	std::tm tempdate1;
	tempdate1.tm_year = 2017;
	tempdate1.tm_mon = 1;
	tempdate1.tm_mday = 1;
	std::vector<std::string> sample1 {"dylan", "ryan", "keith"};

	auto concert_1 = new Concert("Concert 1", sample1, 5, tempdate1);

	// Concert 2
	std::tm tempdate2;
	tempdate2.tm_year = 2017;
	tempdate2.tm_mon = 2;
	tempdate2.tm_mday = 1;
	std::vector<std::string> sample2 {"dylan", "ryan", "keith"};

	auto concert_2 = new Concert("Concert 2", sample2, 5, tempdate2);

	// Concert 3
	std::tm tempdate3;
	tempdate3.tm_year = 2017;
	tempdate3.tm_mon = 1;
	tempdate3.tm_mday = 1;
	std::vector<std::string> sample3 {"dylan", "ryan", "keith"};

	auto concert_3 = new Concert("Concert 3", sample3, 7, tempdate3);

	

	std::vector<Concert> concerts;

	concerts.push_back(*concert_1);
	concerts.push_back(*concert_2);
	concerts.push_back(*concert_3);

	sort(concerts.begin(), concerts.begin()+3);

	std::cout << concerts[0] << concerts[1] << concerts[2] << std::endl;




	if ( *concert_2 < *concert_1){

		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}




	
}
