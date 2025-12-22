#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {
private:
    BSTree<TableEntry<V>>* tree;  // ABB con elementos de tipo TableEntry<V>

public:
    // Constructor
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }
    
    // Destructor
    ~BSTreeDict() {
        delete tree;
    }
    
    // Implementación de métodos abstractos heredados de Dict<V>
    
    // Inserta el par key->value en el diccionario
    void insert(std::string key, V value) override {
        TableEntry<V> entry(key, value);
        try {
            tree->insert(entry);
        } catch (const std::runtime_error& e) {
            // Si el elemento ya existe, lanzamos la excepción requerida
            throw std::runtime_error("Key already exists");
        }
    }
    
    // Busca el valor correspondiente a key
    V search(std::string key) override {
        TableEntry<V> searchEntry(key);  // Crea una entrada con key para buscar
        try {
            TableEntry<V> found = tree->search(searchEntry);
            return found.value;
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("Key not found");
        }
    }
    
    // Elimina el par key->value si se encuentra
    V remove(std::string key) override {
        TableEntry<V> removeEntry(key);  // Crea una entrada con key para eliminar
        try {
            // Primero buscamos para obtener el valor
            TableEntry<V> found = tree->search(removeEntry);
            V value = found.value;
            
            // Luego eliminamos
            tree->remove(removeEntry);
            return value;
        } catch (const std::runtime_error& e) {
            throw std::runtime_error("Key not found");
        }
    }
    
    // Devuelve el número de elementos
    int entries() override {
        return tree->size();
    }
    
    // Sobrecarga del operador [] para búsqueda
    V operator[](std::string key) {
        return search(key);
    }
    
    // Sobrecarga del operador << para imprimir
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<U> &bs);
};

// Implementación del operador << fuera de la clase
template <typename V>
std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
    out << *bs.tree;  // Delega en el operador << de BSTree
    return out;
}

#endif
