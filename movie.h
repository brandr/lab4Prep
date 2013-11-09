#ifndef MOVIE_H
#define MOVIE_H
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Movie {
public:
	Movie();
	virtual ~Movie();
	virtual string genre() = 0;
	virtual const string* dataTypeNames() = 0;
	virtual const int dataTypeCount() = 0;
	string movieDataString();
	virtual Movie* create() = 0;
	void addData(string,string);
private:
	map<string,string> movieData;
};

const string CLASSIC_MOVIE_DATA_TYPES [4] = {"director","title","lead actor","date"};
class ClassicMovie: public Movie {
public:
	virtual ClassicMovie* create(){return new ClassicMovie();}
	virtual string genre();
	virtual const string* dataTypeNames();
	virtual const int dataTypeCount();
};

const string DRAMA_MOVIE_DATA_TYPES [3] = {"director","title","date"};
class DramaMovie: public Movie {
public:
	virtual DramaMovie* create(){return new DramaMovie();}
	virtual string genre();
	virtual const string* dataTypeNames();
	virtual const int dataTypeCount();
};

const string COMEDY_MOVIE_DATA_TYPES [3] = {"director","title","date"};
class ComedyMovie: public Movie {
public:
	virtual ComedyMovie* create(){return new ComedyMovie();}
	virtual string genre();
	virtual const string* dataTypeNames();
	virtual const int dataTypeCount();
};
#endif