//
//  stack_element.hpp
//  triple stack
//
//  Created by Jacob Mathai on 6/18/18.
//  Copyright © 2018 Jacob Mathai. All rights reserved.
//

#ifndef stack_element_h
#define stack_element_h

#include <iostream>

using namespace std;

const unsigned short n = 9; // Array size

unsigned short occupied = 0;   // Number of occuppied array elements
unsigned short s1_top = 0;   // Indexes of top element of each stack (changes with push/pop operations)
unsigned short s2_top = 1;
unsigned short s3_top = 2;

template <class T>
class stack_element {
    public:
        stack_element<T>() : data(0), index(-1), stack_number(0), exist(0) {}
        stack_element<T>(T input, unsigned short idx, unsigned short stack) : 
            data(input), 
            index(idx), 
            stack_number(stack), 
            exist(1) {}
        ~stack_element<T>();
        bool exists() { return exist; }    // Boolean indicating if array element contains valid data
        void set_exists (bool e) { exist = e; }
        T get_data() { return data; }
        void set_data (T input) { data = input; }
        short get_index() { return index; }
        void set_index (unsigned short i) { index = i; }
        void operator = (stack_element* n);
    private:    
        T data;     // Stack data type
        unsigned short index;    // Array position
        unsigned short stack_number; // Number between 1 and 3 specifying which stack the element is a member of
        bool exist;
};

template <class T>
void push (T input, stack_element<T> a[], unsigned short stack_num);    // Traditional stack member functions

template <class T>
void pop (unsigned short stack_num, stack_element<T> a[]);

template <class T>
stack_element<T>* top (unsigned short stack_num, stack_element<T> a[]);

template <class T>
void print_array (stack_element<T> a[]);    // Helper function to show contents of array in driver program

#endif /* stack_element_h */
