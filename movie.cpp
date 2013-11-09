
#include "movie.h"
#include <iostream>
using namespace std;

Movie::Movie(){}

Movie::~Movie(){}

string Movie::genre(){
	return "none";
}

string Movie::movieDataString(){
	string dataString = "";
	const string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
		string dataType = tempTypeNames[i];
		dataString += dataType +": ";
		map<string,string>::iterator index = movieData.find(dataType);
   	 	string value = index -> second;	//this is causing a problem. Fix it.
   	 	dataString += value;
   	 	dataString += "\n";
	}
	return dataString;
}

void Movie::addData(string key, string value){	//TODO: value should not have its class defined yet.
	movieData.insert(pair<string,string>(key,value));
}

//classic movie
string ClassicMovie::genre(){
	return "classic";	//TODO: store this better
}

const string* ClassicMovie::dataTypeNames(){return CLASSIC_MOVIE_DATA_TYPES;}
const int ClassicMovie::dataTypeCount(){return sizeof(CLASSIC_MOVIE_DATA_TYPES)/sizeof(*CLASSIC_MOVIE_DATA_TYPES);};

//drama movie
string DramaMovie::genre(){
	return "drama";	//TODO: store this better
}

const string* DramaMovie::dataTypeNames(){return DRAMA_MOVIE_DATA_TYPES;}
const int DramaMovie::dataTypeCount(){return sizeof(DRAMA_MOVIE_DATA_TYPES)/sizeof(*DRAMA_MOVIE_DATA_TYPES);};

//comedy movie
string ComedyMovie::genre(){
	return "comedy";	//TODO: store this better
}

const string* ComedyMovie::dataTypeNames(){return COMEDY_MOVIE_DATA_TYPES;}
const int ComedyMovie::dataTypeCount(){return sizeof(COMEDY_MOVIE_DATA_TYPES)/sizeof(*COMEDY_MOVIE_DATA_TYPES);};