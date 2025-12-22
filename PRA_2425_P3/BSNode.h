#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
public:
    T elem;                // El elemento almacenado en el nodo
    BSNode<T>* left;       // Puntero al nodo sucesor izquierdo
    BSNode<T>* right;      // Puntero al nodo sucesor derecho

    // Constructor
    // Parámetros por defecto: left = nullptr, right = nullptr
    BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr)
        : elem(elem), left(left), right(right) {}

    // Sobrecarga global del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn) {
        out << bsn.elem;
        return out;
    }
};

#endif
