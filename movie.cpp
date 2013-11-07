
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
