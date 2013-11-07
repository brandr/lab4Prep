#include "lab4IoPrep.h"
	//will probably end up making an object array in Movie
Lab4IoPrep::Lab4IoPrep(){
	//setUpGenreTable();
}
/*
void Lab4IoPrep::setUpGenreTable(){
	int genreCount = 3;	//TODO: get this better
	for(int i = 0; i < genreCount;i++){
		genreTable.insert(pair<string,Movie>(VALID_GENRES[i],EMPTY_MOVIES[i]));
	}
}

Movie Lab4IoPrep::emptyMovie(string genre){
	//this implementation is bad and only for testing.
	if(genre == "C") return emptyClassic;
	if(genre == "D") return emptyDrama;
	if(genre == "F") return emptyComedy;
	cout << "GENRE NOT FOUND" << endl;
	//TODO: in the long run, use the code below instead (it just doesn't work yet)
	/*
	map<string,Movie>::iterator index = genreTable.find(genre);
	if (index == genreTable.end()){	//should do error handling *before* this eventually
    	Movie empty;
    	return empty;
	}
    return index -> second;
    
}
*/
void Lab4IoPrep::readInputFile(ifstream& inputFile){	//might want to make this static and/or add a "Movie" arg (or else return a movie)
	MovieFactory movieMaker;
	const int dataTypeCount = 4;	//TODO: get this better
	
	for(;;){
		if(inputFile.eof()) break;
		string genre = "";		//TODO: break this up into its own methods
		inputFile >> genre;		
		if(!validGenre(genre)){
			inputFile.get();
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
}