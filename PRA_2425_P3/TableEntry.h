#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <ostream>
#include <string>

template <typename V> 
class TableEntry {
public:
    std::string key;
    V value;
    
    // Constructor con key y value
    TableEntry(std::string key, V value) : key(key), value(value) {}
    
    // Constructor solo con key (para búsquedas)
    TableEntry(std::string key) : key(key), value() {}
    
    // Constructor por defecto
    TableEntry() : key(""), value() {}
    
    // Operadores de comparación para BSTree
    bool operator<(const TableEntry<V> &other) const {
        return key < other.key;
    }
    
    bool operator>(const TableEntry<V> &other) const {
        return key > other.key;
    }
    
    bool operator==(const TableEntry<V> &other) const {
        return key == other.key;
    }
    
    bool operator!=(const TableEntry<V> &other) const {
        return key != other.key;
    }
    
    // Operador de salida (SOLO UNO)
    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
        out << "{" << te.key << ":" << te.value << "}";
        return out;
    }
};

#endif
