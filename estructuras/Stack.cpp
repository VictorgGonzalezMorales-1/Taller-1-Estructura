
#pragma once
#include "Stack.h"

template <class T>
Stack<T>:: Stack() {
    this->start = nullptr;
    this->sizeStack = 0;
}

template <class T>
void Stack<T>:: push(T value) {

    Node<T>* n = new Node<T>(value);
    n->setNext(this->start);
    this->start = n;

    this->sizeStack++;

}

template <class T>
void Stack<T>:: pop() {

    if (this->start == nullptr) throw 0;

    Node<T>* toDelete = this->start;
    this->start = toDelete->getNext();
    delete toDelete;
    this->sizeStack--;

}

template <class T>
T Stack<T>:: peak() {
    if (start == nullptr) throw 0;
    return this->start->getValue();
}

template <class T>
bool Stack<T>:: isEmpty() {
    if (this->start == nullptr) return true;
    return false;
}

template <class T>
int Stack<T>:: size() {return this->sizeStack;}

template <class T>
Stack<T>:: ~Stack() {

    while (this->start != nullptr) {
        Node<T>* toDelete = this->start;
        this->start = toDelete->getNext();
        delete toDelete;
    }

    this->sizeStack = 0;

}