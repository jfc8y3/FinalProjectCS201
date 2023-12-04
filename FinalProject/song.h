#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Song {
private:
    string name;
    string key;
    string time;
    int min;
    int sec;

public:
    Song();

    Song(string name, string key, string time, int min, int sec);

    string getName() const {
        return name;
    }
    string getKey() const {
        return key;
    }
    string getTime() const {
        return time;
    }
    int getMin() const {
        return min;
    }
    int getSec() const {
        return sec;
    }

    void setName(string name) {
        this->name = name;
    }
    void setKey(string key) {
        this->key = key;
    }
    void setTime(string time) {
        this->time = time;
    }
    void setMin(int min) {
        this->min = min;
    }
    void setSec(int sec) {
        this->sec = sec;
    }

    virtual void printAttributes(ostream& out) const {
        out << name << setw(20) << key << setw(20) << time << setw(20) << min << ":" << sec << setw(20);    //Virtual function so when the attributes of the class are printed out, it prints out the correct ones for its respective class.
        out << endl;
    }


};

// Rock Song Class

class Rock : public Song {
private:
    int dLevel; // distortion level

public:
    Rock(string name, string key, string time, int min, int sec, int dLevel);

    int getDLevel() const {
        return dLevel;
    }

    void setDLevel(int dLevel) {
        this->dLevel = dLevel;
    }

    void printAttributes(ostream& out) const override {
        Song::printAttributes(out);
        out << "Distorion Level: " << dLevel << endl;
        out << endl;
    }

};

// Mariachi Song Class

class Mariachi : public Song {
private:
    string trumpet;

public:
    Mariachi(string name, string key, string time, int min, int sec, string trumpet);

    string getTrumpet() const {
        return trumpet;
    }

    void setTrumpet(string trumpet) {
        this->trumpet = trumpet;
    }

    void printAttributes(ostream& out) const override {
        Song::printAttributes(out);
        out << "Trumpet? " << trumpet << endl;
        out << endl;
    }
};
