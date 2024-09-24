//Author: Bohdi Norvell
//Assignment: PA 1- Movie Genre Sorter
#ifndef HELPERS_H
#define HELPERS_H

#include "genre.h"

int readFile(ifstream& file, Movie* movies);

void bubbleSortSelection(int userChoice, Genre &genreObject);

Genre constructGenre(Movie* movies, int numMovies, string genreName);
#endif