
#include "List.h"
#include "Node.h"

template <class T>
List<T>:: List() {
    this-> start = nullptr;
}

template <class T>
T List<T>:: getFirst() {
    if (start == nullptr) throw 0;
    return this->start->getValue();
}

template <class T>
T List<T>:: getLast() {
    if (start == nullptr) throw 0;

    Node<T>* cursor = this->start;

    while(cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }

    return cursor->getValue();
}

template <class T>
T List<T>:: get(int index) {
    if (start == nullptr || index < 0) throw 0;

    int count = 0;
    Node<T>* cursor = this->start;

    while (cursor!= nullptr && count < index) {
        cursor = cursor->getNext();
        count++;
    }

    if (cursor == nullptr) throw 0;

    return cursor->getValue();

}

template <class T>
void List<T>:: insertFirst(T value) {
    Node<T>* n = new Node<T>(value);
    n->setNext(this->start);
    this->start = n;
}

template <class T>
void List<T>:: insertLast(T value) {

    if (start == nullptr) {
        this->start = new Node<T>(value);
        return;
    }

    Node<T>* cursor = this->start;

    while (cursor->getNext() != nullptr) {
        cursor = cursor-> getNext();
    }

    cursor->setNext(new Node<T>(value));
}

template <class T>
void List<T>:: insert(T value, int index) {

    if (index < 0) throw 0;
    if (index == 0) {
        this->insertFirst(value);
        return;
    }
    if (start == nullptr) throw 0;

    Node<T>* cursor = this->start;

    for (int a = 0; a < index-1; a++) {
        cursor = cursor->getNext();
        if (cursor == nullptr) throw 0;
    }

    Node<T>* n = new Node<T>(value);
    n->setNext(cursor->getNext());
    cursor->setNext(n);

}

template <class T>
bool List<T>:: isEmpty() {
    if (start == nullptr) return true;
    return false;
}

template <class T>
void List<T>:: remove(int index) {

    if (index < 0) throw 0;
    if (index == 0) {
        Node<T>* toDelete = this->start;
        this->start = start->getNext();
        delete toDelete;
        return;
    }

    Node<T>* cursor = this->start;

    for (int a = 0; a < index - 1; a++) {
        cursor = cursor-> getNext();
        if (cursor == nullptr) throw 0;
    }

    Node<T>* toDelete = cursor->getNext();

    if (toDelete == nullptr) throw 0;
    cursor->setNext(toDelete->getNext());
    delete toDelete;

}

template <class T>
void List<T>:: clear() {

    while (this->start != nullptr) {
        Node<T>* save = this->start->getNext();
        delete this->start;
        this->start = save;
    }

}

template <class T>
List<T>:: ~List() {this->clear();}