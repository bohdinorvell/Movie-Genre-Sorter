//Author: Bohdi Norvell
//Assignment: PA 1- Movie Genre Sorter
#include "helpers.h"

int readFile(ifstream& file, Movie* movies){
    int count = 0;

    string junk;
    getline(file, junk);

    while(!file.eof()){
        getline(file, junk, ',');
        string title, genre, description, director, actor, yearStr, metascoreStr, ratingStr;
        string genreAr[5], actorAr[5];
        int genreCount = 0, actorCount = 0;

        getline(file, title, ',');
        getline(file, junk, '"');
        do{
            getline(file, genreAr[genreCount], ',');
            genreCount++;
        }while(genreAr[genreCount-1][genreAr[genreCount-1].length() - 1] != '"');
        genreAr[genreCount-1].pop_back();
        getline(file, description, ',');
        getline(file, director, ',');
        getline(file, junk, '"');
        do{
            getline(file, actorAr[actorCount], ',');
            actorCount++;
        }while(actorAr[actorCount-1][actorAr[actorCount-1].length() - 1] != '"');
        actorAr[actorCount-1].pop_back();
        getline(file, yearStr, ',');
        int year = stoi(yearStr);
        getline(file, junk, ',');
        getline(file, ratingStr, ',');
        float rating = stof(ratingStr);
        getline(file, junk, ',');
        getline(file, junk, ',');
        getline(file, metascoreStr, '\n');
        int metascore = stoi(metascoreStr);
        Movie temp(title, director, description, actorAr, genreAr, year, metascore, rating, actorCount, genreCount);
        movies[count] = temp;
        count++;
    }

    return count;
}

void bubbleSortSelection(int userChoice, Genre &genreObject){
    int n = genreObject.getNumMoviesInGenre();
    bool swapped;
    switch(userChoice){
        case 1: //alphabetical sort
            for(int i = 0; i < n-1; i++){
                swapped = false;
                for(int j =0; j < n-1-i; j++){
                    if(genreObject.getMoviesOfGenre()[j].getTitle() > genreObject.getMoviesOfGenre()[j+1].getTitle()){
                        genreObject.swapMovies(j, j+1);
                        swapped = true;
                    }
                }
            }
            break;
        case 2: //year sort
            for(int i = 0; i < n-1; i++){
                swapped = false;
                for(int j =0; j < n-1-i; j++){
                    if(genreObject.getMoviesOfGenre()[j].getYear() > genreObject.getMoviesOfGenre()[j+1].getYear()){
                        genreObject.swapMovies(j, j+1);
                        swapped = true;
                    }
                    else if(genreObject.getMoviesOfGenre()[j].getYear() == genreObject.getMoviesOfGenre()[j+1].getYear()){
                        if(genreObject.getMoviesOfGenre()[j].getTitle() > genreObject.getMoviesOfGenre()[j+1].getTitle()){
                            genreObject.swapMovies(j, j+1);
                            swapped = true;
                        }
                    }
                }
            }
            break;
        case 3: //rating sort
            for(int i = 0; i < n-1; i++){
                swapped = false;
                for(int j =0; j < n-1-i; j++){
                    if(genreObject.getMoviesOfGenre()[j].getRating() < genreObject.getMoviesOfGenre()[j+1].getRating()){
                        genreObject.swapMovies(j, j+1);
                        swapped = true;
                    }
                    else if(genreObject.getMoviesOfGenre()[j].getRating() == genreObject.getMoviesOfGenre()[j+1].getRating()){
                        if(genreObject.getMoviesOfGenre()[j].getTitle() > genreObject.getMoviesOfGenre()[j+1].getTitle()){
                            genreObject.swapMovies(j, j+1);
                            swapped = true;
                        }
                    }
                }
            }
            break;
        default:
            cout << "Invalid choice. Select an option between 1-4";
            break;
    }
}

Genre constructGenre(Movie* movies, int numMovies, string genreName){
    Movie selectedGenre[500];
    int selectedGenreCounter = 0;

    for(int i = 0; i < numMovies; i++){
        for(int j = 0; j < movies[i].getGenreCount(); j++){
            if(movies[i].getGenres()[j] == genreName){
                selectedGenre[selectedGenreCounter] = movies[i];
                selectedGenreCounter++;
            }
        }
    }
    Genre genreObject(genreName, selectedGenre, selectedGenreCounter);
    return genreObject;
}
