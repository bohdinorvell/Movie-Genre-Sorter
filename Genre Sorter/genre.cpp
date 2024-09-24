//Author: Bohdi Norvell
//Assignment: PA 1- Movie Genre Sorter
#include "genre.h"

//Class Constructors
Genre::Genre(){
    nameOfGenre = "";
    Movie moviesOfGenre[500];
    numMoviesInGenre = 0;
}

Genre::Genre(string name, Movie* movies, int num){
    nameOfGenre = name;
    numMoviesInGenre = num;
    for(int i = 0; i < 500; i++){
        moviesOfGenre[i] = movies[i]; //movies[i] was initially '0' when downloading PA
    }
}

Genre::Genre(const Genre &rhs){
    nameOfGenre = rhs.nameOfGenre;
    numMoviesInGenre = rhs.numMoviesInGenre;
    for(int i = 0; i < 500; i++){
        moviesOfGenre[i] = rhs.moviesOfGenre[i]; 
    }
}

//Class Getters
string Genre::getNameOfGenre(){
    return nameOfGenre;
}

Movie* Genre::getMoviesOfGenre(){
    return moviesOfGenre;
}

int Genre::getNumMoviesInGenre(){
    return numMoviesInGenre;
}

//Class Setters
void Genre::setNameOfGenre(string name){
    nameOfGenre = name;
}

void Genre::addMovieOfGenre(Movie movie){
    if(numMoviesInGenre < 500){
        moviesOfGenre[numMoviesInGenre] = movie;
        numMoviesInGenre++;
    } else{
        cout << "Size of the MovieOfGenre array is exceeded" << endl;
    }
}

//Other Useful Functions
void Genre::swapMovies(int mov1, int mov2){
    Movie temp(moviesOfGenre[mov1]);
    moviesOfGenre[mov1] = moviesOfGenre[mov2];
    moviesOfGenre[mov2] = temp;
}

void Genre::displayMovies(){
    for(int i = 0; i < numMoviesInGenre; i++){
        cout << i+1 << ". " << moviesOfGenre[i].getTitle() << endl;
    }
}