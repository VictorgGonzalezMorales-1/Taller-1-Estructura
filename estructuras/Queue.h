
#pragma once
#include "Node.h"
template <class T> //Para usar los genéricos

class Queue {

private:
    Node<T>* start;
    Node<T>* end;
    int sizeQueue;

public:
    Queue(); //Constructor

    void push(T value); //Insertar al final
    void pop(); //Elimina al del frente
    T front(); //Entrega el valor del principio de la fila
    T back(); //Entrega el valor del final de la fila
    bool isEmpty(); //Dice si está o no vacia la cola
    int size(); //Entrega el tamaño

    ~Queue(); //Destructor

};

#include "Queue.cpp"