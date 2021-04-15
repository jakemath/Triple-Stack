#include "stack_element.h"

template <class T>
stack_element<T>::~stack_element<T> () {}   // Destructor

template <class T>
void push (T input, stack_element<T> a[], unsigned short stack_num) { // Arguments include data input and stack number between 1 and 3
    assert (occupied < n); // Ensure array has space for another element
    if (stack_num == 1) {   // If pushing onto stack 1
        assert(s1_top + 3 < n);   // Ensure the next top index is within the array
        ++occupied;    // Increment number of occuppied indexes
        if (a[s1_top].exists())  // If stack not empty --> go to next available index. If empty --> top index remains unchanged
            s1_top += 3;
        a[s1_top].set_data(input);  // Set data input
        a[s1_top].set_index(s1_top);   // Set index
        a[s1_top].set_exists(1);    // Mark index is occupied
    }
    else if (stack_num == 2) {   // If pushing onto stack 2
        assert(s2_top + 3 < n);
        ++occupied;
        if (a[s2_top].exists())
            s2_top += 3;
        a[s2_top].set_data(input);
        a[s2_top].set_index(s2_top);
        a[s2_top].set_exists(1);
    }
    else if(stack_num == 3) {   // If pushing onto stack 3
        assert(s3_top + 3 < n);
        ++occupied;
        if (a[s3_top].exists())
            s3_top += 3;
        a[s3_top].set_data(input);
        a[s3_top].set_index(s3_top);
        a[s3_top].set_exists(1);
    }
}

template <class T>
void pop (unsigned short stack_num, stack_element<T> a[]) { // Argument for which stack to pop element from
    assert(occupied > 0);     // Ensure array has an element to pop
    if (stack_num == 1) { // If popping from stack 1

        assert (a[s1_top].exists());  // Ensure the top element is present
        a[s1_top].set_data(0);  // Clear data
        a[s1_top].set_exists(0);    // Mark index as unoccupied
        if (s1_top > 0)  // If there's more than one element in the stack --> move to next index three elements behind, else remain
            s1_top -= 3; // Decrement the top index by 3
        --occupied; // Decrement the number of occuppied elements.
    }
    else if (stack_num == 2) { // If popping from stack 2
        assert(a[s2_top].exists());
        a[s2_top].set_data(0);
        a[s2_top].set_exists(0);
        if (s2_top > 1)
            s2_top -= 3;
        --occupied;
    }
    else if (stack_num == 3) {  // If popping from stack 3
        assert(a[s3_top].exists());
        a[s3_top].set_data(0);
        a[s3_top].set_exists(0);
        if (s3_top > 2)
            s3_top -= 3;
        --occupied;
    }
}

template <class T>
stack_element<T>* top (unsigned short stack_num, stack_element<T> a[]) {  // Return a pointer to the top element
    if (stack_num == 1) // If looking for stack 1's top
        return &a[s1_top];  // Point to memory location
    else if (stack_num == 2)    // If looking for stack 2's top
        return &a[s2_top];
    else if (stack_num == 3)    // If looking for stack 3's top
        return &a[s3_top];
    return NULL;
}

template <class T>
void print_array (stack_element<T> a[]) { 
    short taken = 0;
    for (short i = 0; i < n; ++i) {
        cout << "S" << std::to_string ((i % 3) + 1) << ": ";    // Compute the stack number (between 1 and 3)
        if (!a[i].exists())     // If the slot is not marked --> represent with (empty) keyword
            cout << "(empty)" << endl << endl;
        else {
            cout << a[i].get_data() << endl << endl;    // If the slot is marked --> print the data
            ++taken;
        }
    }
    cout << taken << " spaces occuppied, " << n - taken << " open spaces." << endl; // Stats
}

template <class T>
void stack_element<T>::operator = (stack_element<T>* n) {
    data = n -> data;
    index = n -> index;
    stack_number = n -> stack_number;
}

