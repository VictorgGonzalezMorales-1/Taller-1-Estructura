//Contrato de la clase

#pragma once
#include "Node.h"
template <class T> //Para usar genéricos

class List {

//Atributos
private:
    Node<T>* start;

//Metodos
public:

    List(); //Constructor

    //Getters
    T getFirst();
    T getLast();
    T get(int index);

    //Setters
    void insertFirst(T value);
    void insertLast(T value);
    void insert(T value, int index);

    //Otros
    bool isEmpty();
    void remove(int index);
    void clear();

    ~List();

};

#include "List.cpp"