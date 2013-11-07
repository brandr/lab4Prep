#include "movie.h"

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

    Movie* createMovie(string genre) {
    	//TODO: replace this method with one that uses hastbale.
    	if(genre == "C") return movieTemplates[0];
		if(genre == "D") return movieTemplates[1];
		if(genre == "F") return movieTemplates[2];
		cout << "GENRE NOT FOUND." << endl;
		return NULL;
    }
};