// Lab 15: Reads movie data from file delimeted by '\n' and populates movie objects to output to console.
// CONFIRM WRITING A GUARD STATEMENT LIKE THE ONE IN setTitle IS SAFE.

#include <iostream>
#include <fstream> // For filestream access
#include <sstream>
#include <string>
#include <vector> // To store movie objects
#include <stdexcept>

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
    // File to read from
    const string INPUT_FILE_NAME = "input.txt";
    ifstream inputFile;
    string fileLine = "";
    size_t lineCount = 0;

    // Try opening file and output error to console if file is no good
    inputFile.open(INPUT_FILE_NAME);
    if (!inputFile)
    {
        throw runtime_error("Error opening file: " + INPUT_FILE_NAME);
    }
    else
    {
        string movieName, year, writer = "";

        // Collect movie info from file
        while (inputFile.peek())
        {
            getline(inputFile, movieName);
            getline(inputFile, year);
            getline(inputFile, writer);

            movies.push_back(Movie(movieName, stoi(year), writer));
        }

        // CLOSE THE F-ING FILE
        inputFile.close();
    }

    // Movies are now held as movie objects in vector
    // Output movies to console
    cout << "Movies:" << endl;
    for (size_t i = 0; i < movies.size(); i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << endl;
        cout << movies[i].toString() << "\t";
    }

    cout << endl
         << endl; // Spacing
    return 0;
}

// COLOR CLASS
// Default constructor
Movie::Movie()
    : title(""), yearReleased(0), screenWriter("") // Initialized default if none specified
{
}

// Overloaded constructor
Movie::Movie(string movieTitle, int year, string writer)
{
    setTitle(movieTitle);
    setYearReleased(year);
    setScreenWriter(writer);
}

void Movie::setTitle(string movieTitle)
{
    // CONFIRM WRITING A GUARD STATEMENT LIKE THIS IS SAFE
    if (movieTitle == "")
        throw invalid_argument("Movie must have a title.");
    title = movieTitle;
}
void Movie::setYearReleased(int year)
{
    if (year < 1800 || year > 2024)
        throw invalid_argument("Movie must have a valid year.");
    yearReleased = year;
}
void Movie::setScreenWriter(string writer)
{
    if (writer == "")
        throw invalid_argument("Screen writer must be a valid name.");
    screenWriter = writer;
}
string Movie::getTitle() const
{
    return title;
}
int Movie::getYearReleased() const
{
    return yearReleased;
}
string Movie::getScreenWriter() const
{
    return screenWriter;
}

// Standard toString function for class
string Movie::toString() const
{
    stringstream oss;
    oss << "Movie Title: " << title << " Year Released: " << yearReleased << " Writer: " << screenWriter;
    string output = oss.str();
    return output;
}

// Overriden operator<<
ostream &operator<<(ostream &os, const Movie &m)
{
    os << m.toString();
    return os;
}

Movie::~Movie()
{
}