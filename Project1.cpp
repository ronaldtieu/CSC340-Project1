//
//  main.cpp
//  Project1
//
//  Created by Ronald Tieu on 3/1/23.
//

#include <iostream>
#include <array>

using namespace std;

int arrayX[10];
int arrayY[10];

// if count == 0
// then arrayX and arrayY are full, both arrays add things in parallel
// at index[count] change value to input
void StoreNewLocation (int *count) {

      if(*count < 9) {
        int newX;
        int newY;

        cout << "Enter X Coordinate: " << endl;
        cin >> newX;
        cout << "Enter Y Coordinate: " << endl;
        cin >> newY;
        *count = *count + 1; // conditionally an empty array would have -1 count, so will need to add one

        
        arrayX[*count] = newX;
        arrayY[*count] = newY;
          
        cout << "Location (" << newX << ", " << newY << ")" << " has been stored" << endl;
        cout << "Count in the IF Statement = " << *count << endl;

        
    } else {
        cout << "Unable to add, at maximum capacity. Please remove location in order to add." << endl;
        cout << "Count = " << *count << endl;
    }
}

void ShowStoredLocation (int count) {
    
    if(count < 0) {
        cout << "Error! Nothing is stored." << endl;
    } else {
        cout << "The following locations are stored: " << endl;
        for(int i = 0; i <= count && i <= 9; i++) {
            int offset = i + 1;
            cout << offset << ". " << "(" << arrayX[i] << ", " << arrayY[i] << ")" << endl;
        }
    }
}

void RemoveLocation (int *count) {
//    cout << *count << endl;
    if(*count < 0) {
        cout << "Error! There is nothing to remove" << endl;
    }
    else {
        
        int location;

        ShowStoredLocation(*count);
        
        cout << endl; // spacing
        cout << "Which location do you want to remove?" << endl;
        cin >> location;
        
        cout << endl; // spacing
        

        
        
        if(location > *count+1 || location <= 0) {
//            cout << "Location = " << location << endl;
//            cout << "Count = "  << *count << endl;
          cout << "Error! Invalid location." << endl;

        } else {

            
        // location will be +1 since the first index starts at 1 instead of 0
        // so there will need to be an offset
        

        // need pointer to save those extracted values, this is printing the updated values
        int tempX = arrayX[location-1];
        int tempY = arrayY[location-1];

        for(int i=location-1; i<*count+1;i++) {
            arrayX[i] = arrayX[i+1];
            arrayY[i] = arrayY[i+1];
        }
        
        
        cout << "Removed X Location = " << tempX << endl;
        cout << "Removed Y Location = " << tempY << endl;
        *count = *count - 1;
    }
      }
    
}




    int main() {
        string input;
        bool flag = true;
//        int count = 0; // to keep track of how many things were added or removed

        int count = -1;

        
        while(flag){
            cout << "Choose an option: " << endl;
            cout << "1) Store new location" << endl;
            cout << "2) Remove a location" << endl;
            cout << "3) Show a stored location " << endl;
            cout << endl; // spacing
            cin >> input;
//            cout << endl; // spacing
            
            
            
            if(input == "1") { // StoreNewLocation
                // cout << "Option 1 selected" << endl;
                StoreNewLocation(&count);
                cout << endl; // spacing
//                count++;
            }
            else if (input == "2") { // RemoveLocation
//                cout << "Option 2 selected" << endl;
//                cout << endl; // spacing
                RemoveLocation(&count);
                cout << endl;
//                count--;
            }
            else if (input == "3") { // ShowStoredLocation
//                cout << "Option 3 selected" << endl;
//                cout << endl; // spacing
                ShowStoredLocation(count);
                cout << endl;
            } else {
                cout << "Invalid input, please choose a valid input." << endl;
            }
            
        }
        
        

    
    return 0;
}
