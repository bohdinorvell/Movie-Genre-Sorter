//Author: Bohdi Norvell
//main.cpp driver for the main menu and calling all the variant helper files

#include "helpers.h"

int main(int argc, char** argv){
    //Check for correct command line arguments
    if(argc != 2){
        cout << "Incorrect format.  Expected a filename." << endl;
        return 1;
    }
    Movie movies[500];

    //Check for file open
    ifstream fin(argv[1]);
    if(!fin.is_open()){
        cout << "File not found..." << endl;
        return 1;
    }
    
    //Get movie data from file
    int movieCount = readFile(fin, movies);
    fin.close();

    string genreOptions[9] = {"Sci-Fi", "Fantasy", "Biography", "Romance", "Comedy", "Horror", "Drama", "Family", "Exit"};

    //Get Genre Option to Display
    int userChoice = 0;
    do{
        for(int i = 0; i < 9; i++){
            cout << i+1 << ". " << genreOptions[i] << endl;
        }
        cout << "=============================================" << endl;
        cout << "Which genre of movies would you like to view? ";
        cin >> userChoice;

        if(userChoice == 9){
            return 0;
        }
        else if(userChoice < 1 || userChoice > 9){
            cout << "Invalid choice. Select an option between 1-9" << endl;
        }
        //Construct object with movies of genre
        else{
            int sortChoice = 0;
            Genre genChoice = constructGenre(movies, movieCount, genreOptions[userChoice-1]);
            do{
                cout << endl;
                cout << "1. Alphabetically by title" << endl;
                cout << "2. Numerically by year" << endl;
                cout << "3. Numerically by rating" << endl;
                cout << "4. Exit" << endl;
                cout << "=====================================" << endl;
                cout << "How would you like to sort the " << genreOptions[userChoice - 1] << " movies? ";
                cin >>sortChoice;

                if(sortChoice == 4){
                    return 0;
                }
                else if(sortChoice < 1 || sortChoice > 4){
                    cout << "Invalid choice. Select an option between 1-4" << endl;
                }
                //Sort movies of genre the way user selected
                else{
                    int movieChoice;
                    bubbleSortSelection(sortChoice, genChoice);
                    cout << endl;
                    genChoice.displayMovies();
                    cout << genChoice.getNumMoviesInGenre() + 1 << ". Exit" << endl;
                    cout << "===================================" << endl;
                    cout << "Which movie would you like to view? ";
                    cin >> movieChoice;
                    if(movieChoice == genChoice.getNumMoviesInGenre()+1){
                        return 0;
                    }
                    cout << endl;
                    genChoice.getMoviesOfGenre()[movieChoice-1].displayMovieData();

                    //View selected movie option
                    char select;
                    do{
                        cout << "Would you like to select another movie(y/n)? ";
                        cin >> select;
                        select = tolower(select);
                    }while(select != 'y' && select != 'n');

                    if(select == 'n'){
                        return 0;
                    }
                    else{
                        userChoice = 0;
                    }
                }
            }while(sortChoice < 1 || sortChoice > 6);
        }
    }while(userChoice < 1 || userChoice > 9);

    return 0;
}