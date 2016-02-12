//
//  main.cpp
//  InsertionSort
//
//  Created by Michael Avnyin on 9/15/15.
//  Copyright (c) 2015 Michael Avnyin. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

class LinkedList{ // create class LinkedList
    
    struct node{ // (nested) makes everything public by default
        
        int data;    // integer data part of the node
        node* next; // pointer of node
        
    }; // end struct node
    
public:
    
    node* listHead = new node(); // listHead which will be our dummy node
    node* curr = new node();    // curr will be our current node (in the linked list)
    // that we will compare to a newly inserted node
    
    //decaling methods
    
    LinkedList();        // constructor
    void insert(int n); // insertion sort method into linked list
    void printList(string s);  // printing of linked list
    
}; // end linked list

//defining methods

LinkedList::LinkedList(){     // constructor for Linked List class
    
    listHead->data = -9999;  // set dummy nodes data to -9999
    listHead->next = NULL;  // set the pointer to null
    curr = NULL;
}// end constructor

void LinkedList::insert(int numData){   // Insertion Sort for inserting new nodes into Linked List
    
    
    node* newNode = new node();  // create a new node to insert into linked list
    newNode->data = numData;    // set new nodes data to an integer passed through the method from the textfile
    newNode->next = NULL;      // set its pointer to point to nothing for now
    
    curr = listHead; // let the curr node point to the listHead
    
    while (curr->next != NULL && newNode->data > curr->next->data){ // while the list isnt empty & the new node is greater the current node in list
        curr = curr->next;                                         //  traverse through the list by setting current to what its pointing to
    } // end while
    
    if(curr->next != NULL && curr->next->data == newNode->data){
        // this if statement is just to keep duplicates from being inserted into linked list (if they are dup's theyll skip right to else)
    } // end if
    else{
        newNode->next = curr->next; // when new node is less then our current node we insert
        curr->next = newNode;
    } // end else
    
} // end of Insertion Sort


void LinkedList::printList(string s){ // method for printing our Linked List
    
    int count = 0;
    ofstream outputFile;
    outputFile.open( s );
    
    curr = listHead; // set curr node to the listHead
    
    outputFile << "LISTHEAD --> ";
    cout << "LISTHEAD --> ";
    
    while (curr != NULL) { // while our list isnt empty
        
        if (count < 11){  // used to keep track and print first ten nodes
            
            if(curr->next == NULL){ // this statement will check for our last node in the list we know whatever points to null is at the end
                
                outputFile << "( " << curr->data << " , -1 )" << endl;
                cout << "( " << curr->data << " , -1 )" << endl; // prints our last night point to null (-1)
            } // end if
            
            else{ // else we print nodes data and the the next nodes data
                outputFile << "( " << curr->data << " , " << curr->next->data << " ) --> ";
                cout << "( " << curr->data << " , " << curr->next->data << " ) --> ";
                count++;
            } //end else
            
            curr = curr->next; // traverse through the list
            
        } // end if counter
        
        else
            break; // counter brake while loop
        
    } // end while
    outputFile << endl;
    outputFile << endl;
    outputFile.close();
} // end printList



int main(int argc, const char * argv[]) {
    
    LinkedList myList; // object of type LinkedList
    ifstream myfile ( argv[1] );   // for command line
    
    if (argc < 2) { // this will check how many arguments are in the commannd line and if none are entered we will print a messafe
        cout << "You must compile like this : " << argv[0] << " <input file>  <output file>\n";
        
        return -1;
    } // end if
    
    int num;
    while (myfile >> num){ // reads and parses in a text file
        

        myList.insert(num); // reads in number from textfile and sends it to the insert method to be put in the linked list
        myList.printList(argv[2]); // prints our contents of linked list
        cout << endl;
    } // end while
    
    
    myfile.close(); // closes text file
    
    return 0;
} // end main


