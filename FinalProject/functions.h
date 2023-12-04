#pragma once
#include <iostream>
#include <fstream>
#include "song.h"
#include "list.h"
#include "functions.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

template <class T>
bool compareSong(const T& song, const string& title) {          //This is used in delSong to compare user string and song name. Uses a template to work with any class
    return song.getName() == title;
}

void readRock(istream& input, Linked<Rock>& rockList);

void addRock(Linked<Rock>& rockList);

void readMariachi(istream& input, Linked<Mariachi>& mariachiList);

void addMariachi(Linked<Mariachi>& mariachiList);

void readSong(istream& input, Linked<Song>& songList);

void addSong(Linked<Song>& songList);