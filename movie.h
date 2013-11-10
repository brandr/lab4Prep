#ifndef MOVIE_H
#define MOVIE_H
#include <map>
#include <string>
#include <iostream>
//#include "moviefactory.cpp"

using namespace std;

class Movie {
friend ostream & operator<<(ostream &, const Movie &);
public:
	Movie();
	Movie(const Movie &);
	virtual ~Movie();
	virtual string genre() const = 0;
	virtual const string* dataTypeNames() const = 0;
	virtual int dataTypeCount() const = 0;
	string movieDataString() const;
	virtual Movie* create() = 0;
	void addData(string,string);
	string getData(string) const;
	bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;
private:
	map<string,string> movieData;
};

const string CLASSIC_MOVIE_DATA_TYPES [] = {"director","title","lead actor","date"};
class ClassicMovie: public Movie {
public:
	virtual ClassicMovie* create(){return new ClassicMovie();}
	virtual string genre() const;
	virtual const string* dataTypeNames() const;
	virtual int dataTypeCount() const;
};

const string DRAMA_MOVIE_DATA_TYPES [] = {"director","title","date"};
class DramaMovie: public Movie {
public:
	virtual DramaMovie* create(){return new DramaMovie();}
	virtual string genre() const;
	virtual const string* dataTypeNames() const;
	virtual int dataTypeCount() const;
};

const string COMEDY_MOVIE_DATA_TYPES [] = {"director","title","date"};
class ComedyMovie: public Movie {
public:
	virtual ComedyMovie* create(){return new ComedyMovie();}
	virtual string genre() const;
	virtual const string* dataTypeNames() const;
	virtual int dataTypeCount() const;
};
#endif