
#include "movie.h"
#include <iostream>
using namespace std;
Movie::Movie(){
	//cout << "";
}

Movie::~Movie(){}

string Movie::genre(){
	return "none";
}

string Movie::movieDataString(){
	string dataString = "";
	for(int i = 0; i < 4; i++){

		string dataType = STRING_ARRAY[i];
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

//drama movie

string DramaMovie::genre(){
	return "drama";	//TODO: store this better
}
//comedy movie

string ComedyMovie::genre(){
	return "comedy";	//TODO: store this better
}
