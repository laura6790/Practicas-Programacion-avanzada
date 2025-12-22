#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
private:
    int nelem;           // Número de elementos almacenados en el ABB
    BSNode<T>* root;     // Nodo raíz del ABB

    // Declaraciones de métodos privados (solo prototipos)
    BSNode<T>* search(BSNode<T>* n, T e) const;
    BSNode<T>* insert(BSNode<T>* n, T e);
    void print_inorder(std::ostream &out, BSNode<T>* n) const;
    BSNode<T>* remove(BSNode<T>* n, T e);
    T max(BSNode<T>* n) const;
    BSNode<T>* remove_max(BSNode<T>* n);
    void delete_cascade(BSNode<T>* n);

public:
    // Constructor
    BSTree();
    
    // Destructor
    ~BSTree();

    // Tamaño del árbol
    int size() const;

    // Búsqueda pública
    T search(T e) const;

    // Sobrecarga del operador []
    T operator[](T e) const;

    // Inserción pública
    void insert(T e);

    // Eliminación pública
    void remove(T e);

    // Declaración del operador << como función friend template
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const BSTree<U> &bst);
};

// Implementaciones de los métodos (fuera de la clase)

template <typename T>
BSTree<T>::BSTree() : nelem(0), root(nullptr) {}

template <typename T>
BSTree<T>::~BSTree() {
    delete_cascade(root);
}

template <typename T>
int BSTree<T>::size() const {
    return nelem;
}

template <typename T>
T BSTree<T>::search(T e) const {
    BSNode<T>* node = search(root, e);
    return node->elem;
}

template <typename T>
T BSTree<T>::operator[](T e) const {
    return search(e);
}

template <typename T>
void BSTree<T>::insert(T e) {
    root = insert(root, e);
    nelem++;
}

template <typename T>
void BSTree<T>::remove(T e) {
    root = remove(root, e);
    nelem--;
}

// Implementación del operador <<
template <typename T>
std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst) {
    bst.print_inorder(out, bst.root);
    return out;
}

// Implementaciones de métodos privados

template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* n, T e) const {
    if (n == nullptr) {
        throw std::runtime_error("Element not found");
    }
    if (e < n->elem) {
        return search(n->left, e);
    } else if (e > n->elem) {
        return search(n->right, e);
    } else {
        return n;  // Elemento encontrado
    }
}

template <typename T>
BSNode<T>* BSTree<T>::insert(BSNode<T>* n, T e) {
    if (n == nullptr) {
        return new BSNode<T>(e);
    }
    if (e < n->elem) {
        n->left = insert(n->left, e);
    } else if (e > n->elem) {
        n->right = insert(n->right, e);
    } else {
        throw std::runtime_error("Element already exists");
    }
    return n;
}

template <typename T>
void BSTree<T>::print_inorder(std::ostream &out, BSNode<T>* n) const {
    if (n != nullptr) {
        print_inorder(out, n->left);
        out << n->elem << " ";
        print_inorder(out, n->right);
    }
}

template <typename T>
T BSTree<T>::max(BSNode<T>* n) const {
    if (n == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    if (n->right == nullptr) {
        return n->elem;
    }
    return max(n->right);
}

template <typename T>
BSNode<T>* BSTree<T>::remove_max(BSNode<T>* n) {
    if (n == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    if (n->right == nullptr) {
        BSNode<T>* left = n->left;
        delete n;
        return left;
    }
    n->right = remove_max(n->right);
    return n;
}

template <typename T>
BSNode<T>* BSTree<T>::remove(BSNode<T>* n, T e) {
    if (n == nullptr) {
        throw std::runtime_error("Element not found");
    }
    
    if (e < n->elem) {
        n->left = remove(n->left, e);
    } else if (e > n->elem) {
        n->right = remove(n->right, e);
    } else {
        // Elemento encontrado
        if (n->left == nullptr && n->right == nullptr) {
            // Caso 1: Nodo hoja
            delete n;
            return nullptr;
        } else if (n->left == nullptr) {
            // Caso 2: Solo hijo derecho
            BSNode<T>* right = n->right;
            delete n;
            return right;
        } else if (n->right == nullptr) {
            // Caso 3: Solo hijo izquierdo
            BSNode<T>* left = n->left;
            delete n;
            return left;
        } else {
            // Caso 4: Dos hijos
            T max_left = max(n->left);
            n->elem = max_left;
            n->left = remove_max(n->left);
            return n;
        }
    }
    return n;
}

template <typename T>
void BSTree<T>::delete_cascade(BSNode<T>* n) {
    if (n != nullptr) {
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }
}

#endif
