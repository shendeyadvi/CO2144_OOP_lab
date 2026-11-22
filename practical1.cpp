#include <iostream>
#include <string>
using namespace std;
class Music
{
    int songID;
    string songTitle;
    string artistName;
    string albumName;
    string genre;
    float duration;
    string playlistCategory;
public:
    // Default Constructor
    Music()
    {
        songID = 0;
        songTitle = "Unknown";
        artistName = "Unknown";
        albumName = "Unknown";
        genre = "Unknown";
        duration = 0.0;
        playlistCategory = "None";
        cout << "\nDefault Constructor Called" << endl;
    }
    // Parameterized Constructor
    Music(int id, string title, string artist, string album,
          string gen, float dur, string category)
    {
        songID = id;
        songTitle = title;
        artistName = artist;
        albumName = album;
        genre = gen;
        duration = dur;
        playlistCategory = category;
        cout << "\nParameterized Constructor Called" << endl;
    }
    // Copy Constructor
    Music(const Music &s)
    {
        songID = s.songID;
        songTitle = s.songTitle;
        artistName = s.artistName;
        albumName = s.albumName;
        genre = s.genre;
        duration = s.duration;
        playlistCategory = s.playlistCategory;
        cout << "\nCopy Constructor Called" << endl;
    }
    // Accept Song Details
    void accept()
    {
        cout << "\nEnter Song Details:" << endl;
        cout << "Enter Song ID: ";
        cin >> songID;
        cin.ignore();
        cout << "Enter Song Title: ";
        getline(cin, songTitle);
        cout << "Enter Artist Name: ";
        getline(cin, artistName);
        cout << "Enter Album Name: ";
        getline(cin, albumName);
        cout << "Enter Genre: ";
        getline(cin, genre);
        cout << "Enter Playlist/Category: ";
        getline(cin, playlistCategory);
        cout << "Enter Duration: ";
        cin >> duration;
    }
    // Display Song Details
    void display()
    {
        cout << "\n----- Song Details -----" << endl;
        cout << "Song ID: " << songID << endl;
        cout << "Song Title: " << songTitle << endl;
        cout << "Artist Name: " << artistName << endl;
        cout << "Album Name: " << albumName << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << endl;
        cout << "Playlist/Category: " << playlistCategory << endl;
    }
    // Destructor
    ~Music()
    {
        cout << "\nDestructor Called for Song ID: "
             << songID << endl;
    }
};
int main()
{
    // Object using Default Constructor
    cout << "\n----- Default Constructor Output -----";
    Music song1;
    song1.accept();
    song1.display();
    // Object using Parameterized Constructor
    cout << "\n----- Parameterized Constructor Output -----";
    Music song2(102, "Shape of You", "Ed Sheeran", "Divide", "Pop", 4.24, "Popular");
    song2.display();
    // Object using Copy Constructor
    cout << "\n----- Copy Constructor Output -----";
    Music song3(song2);
    song3.display();
    return 0;
}
