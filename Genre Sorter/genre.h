//Author: Bohdi Norvell
//Assignment: PA 1- Movie Genre Sorter
#ifndef GENRE_H
#define GENRE_H

#include "movie.h"

class Genre{
    string nameOfGenre;
    Movie moviesOfGenre[500];
    int numMoviesInGenre;

    public:
        Genre();
        Genre(string name, Movie* movies, int num);
        Genre(const Genre &rhs);

        string getNameOfGenre();
        Movie* getMoviesOfGenre();
        int getNumMoviesInGenre();

        void setNameOfGenre(string name);

        void addMovieOfGenre(Movie movie);

        void swapMovies(int mov1, int mov2);

        void displayMovies();
};

#endif