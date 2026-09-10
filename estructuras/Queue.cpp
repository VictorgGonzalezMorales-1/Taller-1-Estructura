
#pragma once
#include "Queue.h"

template <class T>
Queue<T>:: Queue() {
    this->start = nullptr;
    this->end = nullptr;
    this->sizeQueue = 0;
}

template <class T>
void Queue<T>:: push(T value) {

    Node<T>* add = new Node<T>(value);

    if (this->start == nullptr) {
        this->start = add;
        this->end = add;
        sizeQueue++;
        return;
    }

    this->end->setNext(add);
    this->end = add;
    sizeQueue++;
}

template <class T>
void Queue<T>:: pop() {

    if (this->start == nullptr) throw 0;

    Node<T>* toDelete = this->start;
    this->start = toDelete->getNext();

    if (this->start == nullptr)
        this->end = nullptr;

    delete toDelete;
    sizeQueue--;

}

template <class T>
T Queue<T>:: front() {
    if (this->start == nullptr) throw 0;
    return this->start->getValue();
}

template <class T>
T Queue<T>:: back() {
    if (this->start == nullptr) throw 0;
    return this->end->getValue();
}

template <class T>
bool Queue<T>:: isEmpty() {
    if (this->start == nullptr) return true;
    return false;
}

template <class T>
int Queue<T>:: size(){return sizeQueue;}

template <class T>
Queue<T>:: ~Queue() {

    while (start != nullptr) {
        Node<T>* toDelete = this->start;
        start = toDelete->getNext();
        delete toDelete;
    }

    this->sizeQueue = 0;

}