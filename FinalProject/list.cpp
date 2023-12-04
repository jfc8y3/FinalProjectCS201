#include "list.h"
#include "song.h"
using namespace std;

template <class T>
Linked<T>::Linked() : headPtr(nullptr), tailPtr(nullptr) {}

template <class T>
Linked<T>::Linked(T d) {
    headPtr = new Node<T>(d);
    tailPtr = headPtr;
}

template <class T>
Linked<T>::~Linked() {
    Node<T>* current = headPtr;
    while (current != nullptr) {
        Node<T>* next = current->nextPtr;
        delete current;
        current = next;
    }
}

template <class T>
void Linked<T>::addNode(T d) {
    Node<T>* tempNode = new Node<T>(d);
    if (headPtr == nullptr) {
        headPtr = tempNode;
        tailPtr = tempNode;
    }
    else {
        tailPtr->nextPtr = tempNode;
        tailPtr = tempNode;
    }
}

template <class T>
void Linked<T>::delNode(string name) {
    Node<T>* tempNode = headPtr;
    Node<T>* prevNode = nullptr;

    while (tempNode != nullptr && tempNode->data.getName() != name) {
        prevNode = tempNode;
        tempNode = tempNode->nextPtr;
    }

    if (tempNode == nullptr) {
        return;
    }

    if (prevNode == nullptr) {
        headPtr = headPtr->nextPtr;
    }
    else {
        prevNode->nextPtr = tempNode->nextPtr;
        if (tempNode == tailPtr) {
            tailPtr = prevNode;
        }
    }

    delete tempNode;
}

template <class T>
void Linked<T>::printList(ostream& out) {
    Node<T>* tempNode = headPtr;
    while (tempNode != nullptr) {
        tempNode->data.printAttributes(out);
        tempNode = tempNode->nextPtr;
    }
}

template <class T>
void Linked<T>::delSong(const string& attributeValue, bool compare(const T&, const string&)) {
    Node<T>* tempNode = headPtr;
    Node<T>* prevNode = nullptr;

    while (tempNode != nullptr && !compare(tempNode->data, attributeValue)) {
        prevNode = tempNode;
        tempNode = tempNode->nextPtr;
    }

    if (tempNode == nullptr) {
        return;
    }

    if (prevNode == nullptr) {
        headPtr = headPtr->nextPtr;
    }
    else {
        prevNode->nextPtr = tempNode->nextPtr;
        if (tempNode == tailPtr) {
            tailPtr = prevNode;
        }
    }

    delete tempNode;
}



template class Linked<Song>;   //instantion for classes, since they are in a .cpp file
template class Linked<Rock>;
template class Linked<Mariachi>;