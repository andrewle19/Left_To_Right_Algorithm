// Author: Andrew Le
// andrewle19@csu.fullerton.edu
// 2/13/17
// Programming Assignment 1: Left to Right



#include <iostream>
using namespace std;

int main() {
    int n,m = 0; // n- size of the input m-number of swaps
    char *disks; // char pointer to point to dynamica array that stores black and white disk
    
    cout << "Enter the number of single color disks(light or dark)" << endl;
    cin >> n;
    
    
    // dynamically allocate char array
    disks = new char[2*n];
    
    // set the initial configurations for the disks to alternate
    for(int i= 0; i < n; i++)
    {
        disks[2*i] = 'd';
        disks[2*i+1] = '1';
    }
   
    cout << "Intial configuration: ";
    // print out intial configurations of disks
    for(int i = 0; i < 2*n; i++)
    {
        cout << disks[i];
    }
    cout << endl;

    
    // Left to Right traversal making swaps when nessecary
    // the c loop is to make the traversal shorter everytime
    // starts at the next index from last start ends at index before last end
    for (int c = 0; c < n; c++)
    {
        for(int i = c; i < 2*n-c-1; i++) // next loop starts at next index ends at last index -1
        {
            if(disks[i] != disks[i+1]) // if the disk index i is not equal to the next index we swap
            {
                // swaps the disks array value
                char temp;
                temp = disks[i];
                disks[i] = disks[i+1];
                disks[i+1] = temp;
                m++; // increments the number of swaps
            }
        }
    }
    
    
    
    // prints out sorted array
    cout << "Sorted configuration: ";
    for(int i = 0; i < 2*n; i++)
    {
        cout << disks[i];
    }
    cout << endl;
    
    // prints out number of swaps
    cout << "Number of swaps: " << m << endl;
    
    // delete pointer
    delete[] disks;
    return 0;
}
