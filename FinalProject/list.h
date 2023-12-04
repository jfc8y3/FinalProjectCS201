#pragma once
#include <iostream>
#include "song.h"
using namespace std;

template <class T>
struct Node {
    T data;
    Node* nextPtr;

    Node(const T& newData) : data(newData), nextPtr(nullptr) {}

    ~Node() {
        
    }
};

template <class T>
class Linked {
private:
    Node<T>* headPtr;
    Node<T>* tailPtr;

public:
    Linked();
    Linked(T d);
    ~Linked();
    void addNode(T d);
    void delNode(string name);
    void printList(ostream& out);
    void delSong(const string& attributeValue, bool compare(const T&, const string&));     //this is a delete node function, but instead of deleting by node name, it gets the object's name from its getter function.
                                                                                           //it then compares it to delete a song given by the user input.
};

