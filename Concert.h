/*********************************************************
*	A class that holds concert info
*	
*	Created by: Dylan Kernohan on 10/2/2017
**********************************************************/

#include <tring>
#include <vector>

class Concert
{
	public:

		/***************************
		*	Default Constructor
		***************************/
		Concert();


		/***************************
		*	Constructor
		***************************/
		Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date );


		/***************************
		*	Deconstructor
		***************************/
		~Concert();


	private:

		// Who will be performing?
		std::string concertName;

		// A list of the people you want
		// to take with you.  May be empty
		// or arbitrarily full.
		std::vector<std::string> friends;

		// A value from 1-10 concerning how
		// badly you want to see this show.
		int desire;

		// The date of the show
		// See http://en.cppreference.com/w/cpp/chrono/c/tm
		std::tm date;

	
};


