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
    	
    	Movie* createdMovie = NULL;
    	if(genre == "C") createdMovie = movieTemplates[0] -> create();
		if(genre == "D") createdMovie = movieTemplates[1] -> create();
		if(genre == "F") createdMovie = movieTemplates[2] -> create();
		
        const string* dataTypeNames = createdMovie -> dataTypeNames();
        int dataTypeCount = createdMovie -> dataTypeCount();
		for(int i = 0; i < dataTypeCount-1; i++){	//TODO: error checking
			string currentData;
			getline(inputFile, currentData, ',');
            createdMovie -> addData(dataTypeNames[i],currentData);
		}

		string lastData;
		getline(inputFile, lastData);
		createdMovie -> addData(dataTypeNames[dataTypeCount-1],lastData);

		return createdMovie;
    }
};