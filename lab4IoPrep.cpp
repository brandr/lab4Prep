#include "lab4IoPrep.h"
	//will probably end up making an object array in Movie
Lab4IoPrep::Lab4IoPrep(){}

void Lab4IoPrep::readInputFile(ifstream& inputFile){	//might want to make this static and/or add a "Movie" arg (or else return a movie)
	MovieFactory movieMaker;
	
	for(;;){
		if(inputFile.eof()) break;
		string genre = "";		//TODO: break this up into its own methods
		inputFile >> genre;		
		if(!validGenre(genre)){
			string temp;
			getline(inputFile,temp);
			continue;
		}
		Movie *nextMovie = (movieMaker.createMovie(genre,inputFile));
		cout << nextMovie -> movieDataString() << endl;
	}
}

bool Lab4IoPrep::validGenre(string genre){
	int genreCount = 3; //TODO: get this better
	for(int i = 0; i < genreCount; i++){
		if(genre == VALID_GENRES[i]) return true;
	}
	return false;
}