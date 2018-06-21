//
//  main.cpp
//  triple stack
//
//  Created by Jacob Mathai on 5/11/18.
//  Copyright © 2018 Jacob Mathai. All rights reserved.
//

// Program initializes array with anonymous objects and represents empty elements in the array with the keyword (empty)
// Data type integers

#include <iostream>

using namespace std;

const unsigned short n = 9; // Array size

unsigned short occupied = 0;   // Number of occuppied array elements

unsigned short s1_top = 0;   // Indexes of top element of each stack (changes with push/pop operations)
unsigned short s2_top = 1;
unsigned short s3_top = 2;

template <class T>
class stack_element
{
public:
    stack_element<T> () : data (0), index (-1), stack_number (0), exist (0) {}
    stack_element<T> (T input, unsigned short idx, unsigned short stack) : data (input), index (idx), stack_number (stack), exist (1) {}
    ~stack_element<T> ();
    
    bool exists() { return exist; }    // Boolean indicating if array element contains valid data
    void set_exists (bool e) { exist = e; }
    
    T get_data() { return data; }
    void set_data (T input) { data = input; }
    
    short get_index() { return index; }
    void set_index (unsigned short i) { index = i; }
    
    void operator = (stack_element* n);
    
    
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
void print_array(stack_element<T> a[]);    // Helper function to show contents of array in driver program

int main ()     // Driver program initializes array with "empty" elements then pops elements for each corresponding stack
{
    stack_element<int> a[n];
    for (unsigned short i = 0; i < n; ++i)  // Initialize array of stack elements, marking each as empty
    {
        a [i].exist = 0;
    }
    cout << "Current array:" << endl << endl;
    print_array<int> (a);
    cout << endl << "Enter contents for stack 1." << endl;  // Enter data for each stack
    for (unsigned short i = 0; i <= n - 3; i += 3)
    {
        int n;
        cout << "Enter element " << (i/3) + 1 << "." << endl;
        cin >> n;
        push<int> (n, a, 1);
    }
    cout << endl << "Enter contents for stack 2." << endl;
    for (unsigned short i = 1; i <= n - 2; i += 3)
    {
        int n;
        cout << "Enter element " << (i/3) + 1 << "." << endl;
        cin >> n;
        push<int> (n, a, 2);
    }
    cout << endl << "Enter contents for stack 3." << endl;
    for (unsigned short i = 2; i <= n - 1; i += 3)
    {
        int n;
        cout << "Enter element " << (i/4) + 1 << "." << endl;
        cin >> n;
        push<int> (n, a, 3);
    }
    cout << endl << "Current array: " << endl << endl;  // Pre-stack 1 pop
    print_array<int> (a);
    cout << endl << "Popping from stack 1..." << endl;
    pop<int> (1, a);    // Pop
    cout << "Current array: " << endl << endl;  // Post-stack 1 pop
    print_array<int> (a);
    cout << endl << "Popping another element from stack 1..." << endl;  // Another stack 1 pop
    pop<int> (1, a);
    cout << "Current array: " << endl << endl;  // Post-second stack 1 pop
    print_array<int> (a);
    cout << endl << "Popping from stack 2..." << endl;  // Pop from stack 2
    pop<int> (2, a);
    cout << "Current array: " << endl << endl;
    print_array<int> (a);
    cout << endl << "Data at S2's top element: " << top<int> (2, a) -> get_data() << endl << endl;  // Reference new top of stack 2
}

template <class T>
stack_element<T>::~stack_element<T> () {}   // Destructor

template <class T>
void push (T input, stack_element<T> a[], unsigned short stack_num) // Arguments include data input and stack number between 1 and 3
{
    assert (occupied < n); // Ensure array has space for another element
    if (stack_num == 1)     // If pushing onto stack 1
    {
        assert (s1_top + 3 < n);   // Ensure the next top index is within the array
        ++occupied;    // Increment number of occuppied indexes
        if (a [s1_top].exists())  // If stack not empty --> go to next available index. If empty --> top index remains unchanged
        {
            s1_top += 3;
        }
        a [s1_top].set_data (input);  // Set data input
        a [s1_top].set_index (s1_top);   // Set index
        a [s1_top].set_exists (1);    // Mark index is occupied
    }
    else if (stack_num == 2)    // If pushing onto stack 2
    {
        assert (s2_top + 3 < n);
        ++occupied;
        if (a [s2_top].exists())
        {
            s2_top += 3;
        }
        a [s2_top].set_data (input);
        a [s2_top].set_index (s2_top);
        a [s2_top].set_exists (1);
    }
    else if (stack_num == 3)    // If pushing onto stack 3
    {
        assert (s3_top + 3 < n);
        ++occupied;
        if (a [s3_top].exists())
        {
            s3_top += 3;
        }
        a [s3_top].set_data (input);
        a [s3_top].set_index (s3_top);
        a [s3_top].set_exists (1);
    }
}

template <class T>
void pop (unsigned short stack_num, stack_element<T> a[]) // Argument for which stack to pop element from
{
    assert (occupied > 0);     // Ensure array has an element to pop
    if (stack_num == 1)  // If popping from stack 1
    {
        assert (a [s1_top].exists());  // Ensure the top element is present
        a [s1_top].set_data (0);  // Clear data
        a [s1_top].set_exists (0);    // Mark index as unoccupied
        if (s1_top > 0)  // If there's more than one element in the stack --> move to next index three elements behind, else remain
        {
            s1_top -= 3; // Decrement the top index by 3
        }
        --occupied; // Decrement the number of occuppied elements.
    }
    else if (stack_num == 2) // If popping from stack 2
    {
        assert (a [s2_top].exists());
        a [s2_top].set_data(0);
        a [s2_top].set_exists(0);
        if (s2_top > 1)
        {
            s2_top -= 3;
        }
        --occupied;
    }
    else if (stack_num == 3) // If popping from stack 3
    {
        assert (a [s3_top].exists());
        a [s3_top].set_data (0);
        a [s3_top].set_exists (0);
        if (s3_top > 2)
        {
            s3_top -= 3;
        }
        --occupied;
    }
}

template <class T>
stack_element<T>* top (unsigned short stack_num, stack_element<T> a[])   // Return a pointer to the top element
{
    if (stack_num == 1) // If looking for stack 1's top
    {
        return &a [s1_top];  // Point to memory location
    }
    else if (stack_num == 2)    // If looking for stack 2's top
    {
        return &a [s2_top];
    }
    else if (stack_num == 3)    // If looking for stack 3's top
    {
        return &a [s3_top];
    }
    return NULL;
}

template <class T>
void print_array (stack_element<T> a[])
{
    short taken = 0;
    for (short i = 0; i < n; ++i)
    {
        cout << "S" << std::to_string ((i % 3) + 1) << ": ";    // Compute the stack number (between 1 and 3)
        if (!a [i].exists())     // If the slot is not marked --> represent with (empty) keyword
            cout << "(empty)" << endl << endl;
        else
        {
            cout << a [i].get_data() << endl << endl;    // If the slot is marked --> print the data
            ++taken;
        }
    }
    cout << taken << " spaces occuppied, " << n - taken << " open spaces." << endl; // Stats
}

template <class T>
void stack_element<T>::operator = (stack_element<T>* n)
{
    data = n -> data;
    index = n -> index;
    stack_number = n -> stack_number;
}


