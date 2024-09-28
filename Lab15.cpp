// Lab 15: Reads movie data from file delimeted by '\n' and populates movie objects to output to console.

#include <iostream>
#include <fstream> // For filestream access
#include <sstream>
#include <iomanip>
#include <string>
#include <vector> // To store movie objects

using namespace std;

// Declare movie class to store movie variables
class Movie
{
private:
    string title;
    int yearReleased;
    string screenWriter;

public:
    Movie();
    Movie(string, int, string);
    void setTitle(string);
    void setYearReleased(int);
    void setScreenWriter(string);
    string getTitle() const;
    int getYearReleased() const;
    string getScreenWriter() const;
    string toString() const; // print() method but returns a string
    ~Movie();
};

int main()
{
    // Initialize variables
    vector<Movie> movies = {};

    // Output movies to console
    cout << "Movies:" << endl;
    for (size_t i = 0; i < movies.size(); i++)
    {
        if (i % 4 == 0 && i != 0) cout << endl;
        movies[i] = Movie().randomizeMovie(); // Return randomized color object
        SetForegroundMovie(movies[i].getR(), movies[i].getG(), movies[i].getB()); // Change text color to RGB values
        cout << "Movie " << i << "::";
        ResetMovie();
        cout << " " << movies[i].toString() << "\t";        
    }      

    cout << endl << endl; // Spacing
    return 0;
}

// COLOR CLASS
// Default constructor
Movie::Movie()
    : title(""), yearReleased(0), screenWriter("") // Initialized default if none specified
{
}

// Overloaded constructor
Movie::Movie(string movieTitle, int year, int writer)
// Initialized default if none specified
{
    setR(red);
    setG(green);
    setB(blue);
}

void Movie::setTitle(string movieTitle)
{
    if (Red >= 0 && Red <= 255)
    {
        r = Red;
    }
    else
    {
        throw invalid_argument("Red value must be between 0 and 255.");
    }
}
void Movie::setG(int Green)
{
    if (Green >= 0 && Green <= 255)
    {
        g = Green;
    }
    else
    {
        throw invalid_argument("Green value must be between 0 and 255.");
    }
}
void Movie::setB(int Blue)
{
    if (Blue >= 0 && Blue <= 255)
    {
        b = Blue;
    }
    else
    {
        throw invalid_argument("Blue value must be between 0 and 255.");
    }
}
void Movie::setMovie(int Red, int Green, int Blue)
{
    setR(Red);
    setG(Green);
    setB(Blue);
}
int Movie::getR() const
{
    return r;
}
int Movie::getG() const
{
    return g;
}
int Movie::getB() const
{
    return b;
}

// Randomize color. Return by & for method chaining
Movie& Movie::randomizeMovie(){
    // Random number generator to create RGB
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);  // For creating movies
    setR(dist(gen));
    setG(dist(gen));
    setB(dist(gen));
    return *this;
}

// Standard toString function for class
string Movie::toString() const
{
    stringstream oss;
    oss << "r: " << r << " g: " << g << " b: " << b;
    string output = oss.str();
    return output;
}

// Overriden operator<<
ostream &operator<<(ostream &os, const Movie &c)
{
    os << c.toString();
    return os;
}

Movie::~Movie()
{
}