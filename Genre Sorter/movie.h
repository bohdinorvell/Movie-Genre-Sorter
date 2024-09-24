//Author: Bohdi Norvell
//Assignment: PA 1- Movie Genre Sorter
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <fstream>

using namespace std;

class Movie{
    string title, director, description;
    string actors[5];
    string genres[5];
    int year, metascore;
    float rating;
    int actorCount;
    int genreCount;

    public:
        Movie();
        Movie(string t, string di, string de, string* act, string* gen, int y, int m, float r, int aCount, int gCount);
        Movie(const Movie &rhs);
        
        string getTitle();
        string getDirector();
        string getDescription();
        string* getActors();
        string* getGenres();
        int getYear();
        int getMetascore();
        float getRating();
        int getActorCount();
        int getGenreCount();

        void setTitle(string t);
        void setDirector(string di);
        void setDescription(string de);
        void setYear(int y);
        void setMetascore(float m);
        void setRating(int r);

        void addActor(string act);
        void addGenre(string gen);

        void displayMovieData();
};

#endif