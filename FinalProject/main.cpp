#include <iostream>
#include <fstream>
#include <string>
#include "song.h"
#include "list.h"
#include "functions.h"
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    char choice;
    cout << "Welcome to Setlist Generator" << endl;
    cout << endl;
    cout << "What genre will you be working with today?" << endl;
    cout << "R: Rock" << endl;
    cout << "M: Mariachi" << endl;
    cout << "S: Any Genre (Blank)" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 'r' or choice == 'R') {
        Linked<Rock> rockListt;
        cout << endl;
        cout << "You chose rock." << endl;
        ifstream fin("rock.txt");
        ofstream fout("setlist.txt");
        fout << "It's show time! Here is your rock setlist:" << endl;
        fout << endl;
        fout << "Name" << setw(20) << "Key" << setw(20) << "Time Signature" << setw(20) << "Length" << setw(20) << endl;
        readRock(fin, rockListt);
        cout << endl;
        cout << "List was successfully output to 'setlist.txt'" << endl;
        cout << endl;

        char choice3;
        while (true) {
            cout << "Would you like to add or delete songs?" << endl;
            cout << "A: Add song" << endl;
            cout << "D: Delete song" << endl;
            cout << "Q: Quit" << endl;
            cout << "Enter choice: ";
            cin >> choice3;

            if (choice3 == 'a' or choice3 == 'A') {
                addRock(rockListt);
            }
            else if (choice3 == 'd' or choice3 == 'D') {
                string songName;
                cout << "Enter the name of the song you want to delete: ";
                cin.ignore(); 
                getline(cin, songName);
                rockListt.delSong(songName, compareSong);
                cout << "Song deleted successfully!" << endl;
            }
            else if (choice3 == 'q' or choice3 == 'Q') {
                break; 
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        
     
        fout << endl;
        rockListt.printList(fout);
    }
    else if (choice == 'm' or choice == 'M') {
        Linked<Mariachi> mariachiList;
        cout << endl;
        cout << "You chose Mariachi." << endl;
        ifstream fin("mariachi.txt");
        ofstream fout("setlist.txt");
        fout << "It's show time! Here is your Mariachi setlist:" << endl;
        fout << endl;
        fout << "Name" << setw(20) << "Key" << setw(20) << "Time Signature" << setw(20) << "Length" << setw(20) << endl;
        readMariachi(fin, mariachiList);
        cout << endl;
        cout << "List was successfully output to 'setlist.txt'" << endl;
        cout << endl;

        char choice3;
        while (true) {
            cout << "Would you like to add or delete songs?" << endl;
            cout << "A: Add song" << endl;
            cout << "D: Delete song" << endl;
            cout << "Q: Quit" << endl;
            cout << "Enter choice: ";
            cin >> choice3;

            if (choice3 == 'a' or choice3 == 'A') {
                addMariachi(mariachiList);
            }
            else if (choice3 == 'd' or choice3 == 'D') {
                string songName;
                cout << "Enter the name of the song you want to delete: ";
                cin.ignore();
                getline(cin, songName);
                mariachiList.delSong(songName, compareSong); 
                cout << "Song deleted successfully!" << endl;
            }
            else if (choice3 == 'q' or choice3 == 'Q') {
                break; 
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }

        fout << endl;
        mariachiList.printList(fout);
    }

    else if (choice == 's' or choice == 'S') {
        Linked<Song> songList;
        char choice2;
        cout << endl;
        cout << "You chose Song." << endl;
        ifstream fin("songs.txt");
        ofstream fout("setlist.txt");
        fout << "It's show time! Here is your Song setlist:" << endl;
        fout << endl;
        fout << "Name" << setw(20) << "Key" << setw(20) << "Time Signature" << setw(20) << "Length" << endl;
        readSong(fin, songList);
        cout << endl;
        cout << "List was successfully output to 'setlist.txt'" << endl;
        cout << endl;

        char choice3;
        while (true) {
            cout << "Would you like to add or delete songs?" << endl;
            cout << "A: Add song" << endl;
            cout << "D: Delete song" << endl;
            cout << "Q: Quit" << endl;
            cout << "Enter choice: ";
            cin >> choice3;

            if (choice3 == 'a' or choice3 == 'A') {
                addSong(songList);
            }
            else if (choice3 == 'd' or choice3 == 'D') {
                string songName;
                cout << "Enter the name of the song you want to delete: ";
                cin.ignore();
                getline(cin, songName);
                songList.delSong(songName, compareSong);
                cout << "Song deleted successfully!" << endl;
            }
            else if (choice3 == 'q' or choice3 == 'Q') {
                break;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }

        fout << endl;
        songList.printList(fout);

        return 0;
    }
}