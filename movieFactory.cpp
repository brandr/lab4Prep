#include "movie.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
class MovieFactory{
private:
	Movie* movieTemplates[3];
	//TODO: hashtable
public:
 	MovieFactory() {
    	movieTemplates[0] = new ClassicMovie();
        movieTemplates[1] = new DramaMovie();
        movieTemplates[2] = new ComedyMovie();
    }

    ~MovieFactory() {
        for (int i = 0; i < 3; i++) {
        	delete movieTemplates[i];
            movieTemplates[i] = NULL;
        }
    }

    Movie* createMovie(string genre, ifstream& inputFile) {	//NOTE: should this take in more data and create the entire movie?
    	//TODO: replace this method with one that uses hastbale.
    	const int dataTypeCount = 4;
    	Movie* createdMovie = NULL;
    	if(genre == "C") createdMovie = movieTemplates[0];
		if(genre == "D") createdMovie = movieTemplates[1];
		if(genre == "F") createdMovie = movieTemplates[2];
		
		for(int i = 0; i < dataTypeCount-1; i++){	//TODO: error checking
			string currentData;
			getline(inputFile, currentData, ','); //TODO: fix extra space
			createdMovie -> addData(STRING_ARRAY[i],currentData);
		}
		string lastData;
		getline(inputFile, lastData); //TODO: fix extra space
		createdMovie -> addData(STRING_ARRAY[dataTypeCount-1],lastData);
		return createdMovie;
    }
};