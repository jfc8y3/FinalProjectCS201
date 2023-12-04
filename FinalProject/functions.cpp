#include <iostream>
#include <fstream>
#include "song.h"
#include "list.h"
#include "functions.h"
#include <string>
#include <sstream>
using namespace std;

void addRock(Linked<Rock>& rockList) {            //this function adds rock songs when  the user chooses "Rock" class in the menu. There are other functions for the rest of the classes.
    string name, key, time;
    int min, sec, dLevel;
    cin.ignore();
    cout << "Enter Rock Song Details:" << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Key: ";
    getline(cin, key);

    cout << "Time: ";
    getline(cin, time);

    cout << "Duration (minutes): ";
    cin >> min;

    cout << "Duration (seconds): ";
    cin >> sec;

    cout << "Distortion Level: ";
    cin >> dLevel;

    
    Rock newRockSong(name, key, time, min, sec, dLevel);

    
    rockList.addNode(newRockSong);

    cout << "Rock song added successfully!" << endl;
}

void addMariachi(Linked<Mariachi>& mariachiList){
    string name, key, time, trumpet;
    int min, sec;
    cin.ignore();
    cout << "Enter Mariachi Song Details:" << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Key: ";
    getline(cin, key);

    cout << "Time: ";
    getline(cin, time);

    cout << "Duration (minutes): ";
    cin >> min;

    cout << "Duration (seconds): ";
    cin >> sec;

    cout << "Trumpet?: ";
    cin >> trumpet;


    Mariachi newMariachiSong(name, key, time, min, sec, trumpet);


    mariachiList.addNode(newMariachiSong);

    cout << "Mariachi song added successfully!" << endl;
}

void addSong(Linked<Song>& songList) {
    string name, key, time;
    int min, sec;
    cin.ignore();
    cout << "Enter Song Details:" << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Key: ";
    getline(cin, key);

    cout << "Time: ";
    getline(cin, time);

    cout << "Duration (minutes): ";
    cin >> min;

    cout << "Duration (seconds): ";
    cin >> sec;

    Song newSong(name, key, time, min, sec);


    songList.addNode(newSong);

    cout << "Song added successfully!" << endl;
}

void readRock(istream& input, Linked<Rock>& rockList) {            //This function reads in the genre songs from the respective .txt file. There are also functions for the other genres.
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        vector<string> index;
        while (getline(iss, line, ',')) {
            index.push_back(line);
        }
        if (index.size() == 6) {
            string name = index[0];
            string key = index[1];
            string time = index[2];
            int min = stoi(index[3]);
            int sec = stoi(index[4]);
            int dLevel = stoi(index[5]);
            Rock rockSong(name, key, time, min, sec, dLevel);
            rockList.addNode(rockSong);
        }
        else {
            cout << "Invalid data format in line: " << line << endl;
        }
    }
}

void readMariachi(istream& input, Linked<Mariachi>& mariachiList) {
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        vector<string> index;
        while (getline(iss, line, ',')) {
            index.push_back(line);
        }
        if (index.size() == 6) {
            string name = index[0];
            string key = index[1];
            string time = index[2];
            int min = stoi(index[3]);
            int sec = stoi(index[4]);
            string trumpet = (index[5]);
            Mariachi mariachiSong(name, key, time, min, sec, trumpet);
            mariachiList.addNode(mariachiSong);
        }
        else {
            cout << "Invalid data format in line: " << line << endl;
        }
    }
}

void readSong(istream& input, Linked<Song>& songList) {
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        vector<string> index;
        while (getline(iss, line, ',')) {
            index.push_back(line);
        }
        if (index.size() == 5) {
            string name = index[0];
            string key = index[1];
            string time = index[2];
            int min = stoi(index[3]);
            int sec = stoi(index[4]);
            Song song(name, key, time, min, sec);
            songList.addNode(song);
        }
        else {
            cout << "Invalid data format in line: " << line << endl;
        }
    }
}
