#include <iostream>
#include <fstream>
#include "song.h"
using namespace std;

Song::Song(){}

Song::Song(string name, string key, string time, int min, int sec) : name(name), key(key), time(time), min(min), sec(sec) {}

Rock::Rock(string name, string key, string time, int min, int sec, int dLevel) : Song(name, key, time, min, sec) {
	this->dLevel = dLevel;
}

Mariachi::Mariachi(string name, string key, string time, int min, int sec, string trumpet) : Song(name, key, time, min, sec) {
	this->trumpet = trumpet;
}