
#include "movie.h"
#include <iostream>
using namespace std;

Movie::Movie(){}

Movie::~Movie(){}

string Movie::genre() const{
	return "none";
}

string Movie::movieDataString() const{
	string dataString = "";
	const string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
		string dataType = tempTypeNames[i];
		dataString += dataType +": ";
		map<string,string>::const_iterator index = movieData.find(dataType);
   	 	string value = index -> second;	
   	 	dataString += value;
   	 	dataString += "\n";
	}
	return dataString;
}

void Movie::addData(string key, string value){	//TODO: value should not have its class defined yet. (maybe?)
	movieData.insert(pair<string,string>(key,value));
}

string Movie::getData(string dataType) const{	
	map<string,string>::const_iterator index = movieData.find(dataType);
	return index -> second;	
}

ostream& operator<<(ostream& output, const Movie& m) {
	//MovieFactory tempFactory;
	//Movie* temp = tempFactory.createMovie(m);
    output << m.movieDataString();   //TODO: change how this is done.
    return output;
}

//classic movie
string ClassicMovie::genre() const{
	return "classic";	//TODO: store this better
}

const string* ClassicMovie::dataTypeNames() const{return CLASSIC_MOVIE_DATA_TYPES;}
int ClassicMovie::dataTypeCount() const {return sizeof(CLASSIC_MOVIE_DATA_TYPES)/sizeof(*CLASSIC_MOVIE_DATA_TYPES);};

//drama movie
string DramaMovie::genre() const {
	return "drama";	//TODO: store this better
}

const string* DramaMovie::dataTypeNames () const{return DRAMA_MOVIE_DATA_TYPES;}
int DramaMovie::dataTypeCount() const {return sizeof(DRAMA_MOVIE_DATA_TYPES)/sizeof(*DRAMA_MOVIE_DATA_TYPES);};

//comedy movie
string ComedyMovie::genre() const{
	return "comedy";	//TODO: store this better
}

const string* ComedyMovie::dataTypeNames() const {return COMEDY_MOVIE_DATA_TYPES;}
int ComedyMovie::dataTypeCount() const {return sizeof(COMEDY_MOVIE_DATA_TYPES)/sizeof(*COMEDY_MOVIE_DATA_TYPES);};