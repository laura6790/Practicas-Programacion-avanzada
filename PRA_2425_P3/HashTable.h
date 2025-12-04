#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2425_P1/ListLinked.h" 

template <typename V>
class HashTable: public Dict<V> {

	private:
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;
		int h(std::string key) {
			int sum = 0;
			for (size_t i = 0; i < key.length(); i++) {
                		sum += int(key.at(i));
           		}
           		return sum % max;
		}
      
	public:
        	HashTable(int size){
			max = size;
            		n = 0;
            		table = new ListLinked<TableEntry<V>>[max];
		}

		~HashTable(){
			delete[] table;
		}
		void insert(std::string key, V value) override {
            		int index = h(key);
            		for (int i = 0; i < table[index].size(); i++) {
                		if (table[index].get(i).key == key) {
                    			throw std::runtime_error("Clave ya existe en el diccionario");
               			}
            		}
            
            		// Insertar nueva entrada
            		table[index].append(TableEntry<V>(key, value));
          		n++;
       		 }

		V search(std::string key){
			int index = h(key);
			for (int i = 0; i < table[index].size(); i++) {
                		TableEntry<V> entry = table[index].get(i);
                			if (entry.key == key) {
                    				return entry.value;
               			 }
           		}

           		 throw std::runtime_error("Clave no encontrada");
		}
		
		V remove(std::string key) override {
            		int index = h(key);
			for (int i = 0; i < table[index].size(); i++) {
                		TableEntry<V> entry = table[index].get(i);
                			if (entry.key == key) {
                    				table[index].remove(i);
                   				n--;
                    				return entry.value;
               				 }
            		}
			throw std::runtime_error("Clave no encontrada");
        	}
		
		int entries() override{
			return n;
		}

		
		int capacity(){
			return max;
		}

		V operator[](std::string key) {
            		return search(key);
        	}
        
        // Operador de salida para imprimir la tabla hash
        	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            		out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            		for (int i = 0; i < th.max; i++) {
                		out << "Cubeta " << i << ": " << th.table[i] << std::endl;
            		}
            		return out;
        	}
};

#endif
