
#pragma once
#include "Node.h"
template <class T> //Para usar los genéricos

class Stack {

private:
    Node<T>* start;
    int sizeStack;


//Métodos
public:

    Stack(); //Constructor

    void push(T value); //Insertar al inicio
    void pop(); //Retira el elemento superior
    T peak(); //Mira el elemento de arriba sin alterarlo
    bool isEmpty(); //Revisa si está vacia
    int size(); //Entrega el tamaño

    ~Stack(); //Destructor

};

#include "Stack.cpp"