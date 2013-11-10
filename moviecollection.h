#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include "bintree.h"
/*
#include <string>
#include <iostream>
*/

class GenreNode{
	friend class MovieCollection;
	friend ostream & operator<<(ostream &, const GenreNode &);
public:
GenreNode();
string genre();
bool isEmpty() const;
//constructor that takes bintree arg, maybe?
private:
BinTree* movieData;
GenreNode* next;
};

class MovieCollection{
	friend ostream & operator<<(ostream &, const MovieCollection &);
public:
	MovieCollection();
	void insert(Movie *);	//primary insert method
	bool isEmpty() const;
	void collectionToArray(BinTree* []) const;
private:
	GenreNode* root;
};
#endif