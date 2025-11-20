#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;  // Puntero al primer nodo
    int n;           // Número de elementos

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    // Métodos heredados de List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida");
        }

        if (pos == 0) {
            // Insertar al principio
            first = new Node<T>(e, first);
        } else {
            // Insertar en posición intermedia o final
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            current->next = new Node<T>(e, current->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }

        T removed_value;
        if (pos == 0) {
            // Eliminar el primer elemento
            Node<T>* temp = first;
            removed_value = first->data;
            first = first->next;
            delete temp;
        } else {
            // Eliminar elemento intermedio o final
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            removed_value = temp->data;
            current->next = temp->next;
            delete temp;
        }
        n--;
        return removed_value;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }

    int search(T e) const override {
        Node<T>* current = first;
        int pos = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        return get(pos);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        out << "[";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }
};

#endif
