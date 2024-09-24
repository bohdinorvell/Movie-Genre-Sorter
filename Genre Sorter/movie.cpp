//Author: Bohdi Norvell
//Assignment: PA 1- Movie Genre Sorter
#include "movie.h"

//Class Constructors
Movie::Movie(){
    string title = "title";
    string director = "director";
    string description = "description";
    string actors[5];
    string genres[5];
    int year = 2000;
    int metascore = 75;
    float rating = 6.9;
    int actorCount = 5;
    int genreCount = 3;
}

Movie::Movie(string t, string di, string de, string* act, string* gen, int y, int m, float r, int aCount, int gCount){
    title = t;
    director = di;
    description = de;
    actorCount = aCount;
    genreCount = gCount;
    for(int i = 0; i < actorCount; i++){
        actors[i] = act[i];
    }
    for(int j = 0; j < genreCount; j++){
        genres[j] = gen[j];
    }
    year = y;
    metascore = m;
    rating = r;
}

Movie::Movie(const Movie& rhs){
    title = rhs.title;
    director = rhs.director;
    description = rhs.description;
    actorCount = rhs.actorCount;
    genreCount = rhs.genreCount;
    for(int i = 0; i < actorCount; i++){
        actors[i] = rhs.actors[i];
    }
    for(int j = 0; j < genreCount; j++){
        genres[j] = rhs.genres[j];
    }
    year = rhs.year;
    metascore = rhs.metascore;
    rating = rhs.rating;
}

//Class Getters
string Movie::getTitle(){
    return title;
}
string Movie::getDirector(){
    return director;
}
string Movie::getDescription(){
    return description;
}
string* Movie::getActors(){
    return actors;
}
string* Movie::getGenres(){
    return genres;
}
int Movie::getYear(){
    return year;
}
int Movie::getMetascore(){
    return metascore;
}
float Movie::getRating(){
    return rating;
}
int Movie::getActorCount(){
    return actorCount;
}
int Movie::getGenreCount(){
    return genreCount;
}

//Class Setters
void Movie::setTitle(string t){
    title = t;
}
void Movie::setDirector(string di){
    director = di;
}
void Movie::setDescription(string de){
    description = de;
}
void Movie::setYear(int y){
    year = y;
}
void Movie::setMetascore(float m){
    metascore = m;
}
void Movie::setRating(int r){
    rating = r;
}

void Movie::addActor(string act){
    if(actorCount < 5){
        actors[actorCount] = act;
        actorCount++;
    }
    else{
        cout << "Actor Array exceded count" << endl;
    }
}

void Movie::addGenre(string gen){
    if(genreCount < 5){
        genres[genreCount] = gen;
        genreCount++;
    }
    else{
        cout << "Genre Array exceded count" << endl;
    }
}

//Display Movie Object
void Movie::displayMovieData(){
    cout << title << endl;
    cout << "Director: " << director << endl;
    cout << "Actors: ";
    for(int i = 0; i < actorCount - 1; i++){
        cout << actors[i] << " * ";
    }
    cout << actors[actorCount - 1] << endl;
    cout << "Year: " << year << " Rating: " << rating << " Meta Score: " << metascore << endl;
    cout << "Description: " << description << endl;
}