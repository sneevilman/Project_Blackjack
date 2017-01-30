/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 12 Jan, 2017
 * Purpose: Deck of Cards
 * step 1: shuffle the deck
 * step 2: draw a card
 * step 3: display cards drawn
 * step 4: continue to draw
 * step 5: run out of cards
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries Here


//Function Prototypes Here

//Program Execution Begins Here

int main() {
    //Declare and process variables
    short          deck,        //number of cards in deck
                   hand;       //number of cards in hand
    char           ans;         //used to set draw value with y/n
    bool           draw;        //used to execute draw function

    //Process/Calculations Here

        hand = 0;
        deck = 52;
  
      do {
          
          cout<<"There are "<<hand<<" cards in your hand."<<endl;
          cout<<"There are "<<deck<<" cards left in the deck."<<endl;
   
          deck -=1;
          hand +=1;
          draw = false;
         
          cout<<"Draw a card? y/n"<<endl;
          cin>>ans;
          while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N') {
          cout << "Please enter y/n" << endl;
          cin>>ans;
          }
           if ((ans == 'y' || ans == 'Y')&&deck>=0){
            cout<<"You drew a card"<<endl;
            draw = true;
           }else{
            if (deck<0){
                cout<<"The deck is empty."<<endl;
                }
            draw = false;
            }
      }while (draw);
      

    return 0;
}

