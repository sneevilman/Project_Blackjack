/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 12 Jan, 2017
 * Purpose: BlackJack
 * 
 */

//System Libraries Here
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//User Libraries Here


//Function Prototypes Here

//Program Execution Begins Here

int main() {
    //Declare and process variables
    short          deck,        //number of cards in deck
                   drawV,       //value of card drawn
                   hand;       //number of cards in hand
    char           rstrt,       //used to set restart value with y/n
                   vHand,       //used to view hand
                   ans;         //used to set draw value with y/n
    bool           draw,        //used to execute draw function
                   dupe,        //used to check for >4 of a card
                   restart;
    string         crdType;     //converts drawV to card type string
    

    //Process/Calculations Here
    
    do {
        
        srand(time(0));
        
        short cAce=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0, 
                cJ=0, cQ=0, cK=0;
        hand=1;
  
      for(deck=51;deck>-1;deck--,hand++) {
          
          do{
              crdType="Redraw";
              drawV=rand()%13+1;
                  switch (drawV){
                      case 1:if(cAce!=4){crdType="an Ace";cAce++;}break;
                       case 2:if(c2!=4){crdType="a Two";c2++;}break;
                      case 3:if(c3!=4){crdType="a Three";c3++;}break;
                      case 4:if(c4!=4){crdType="a Four";c4++;}break;
                      case 5:if(c5!=4){crdType="a Five";c5++;}break;
                      case 6:if(c6!=4){crdType="a Six";c6++;}break;
                      case 7:if(c7!=4){crdType="a Seven";c7++;}break;
                      case 8:if(c8!=4){crdType="an Eight";c8++;}break;
                      case 9:if(c9!=4){crdType="a Nine";c9++;}break;
                      case 10:if(c10!=4){crdType="a Ten";c10++;}break;
                      case 11:if(cJ!=4){crdType="a Jack";cJ++;}break;
                      case 12:if(cQ!=4){crdType="a Queen";cQ++;}break;
                      case 13:if(cK!=4){crdType="a King";cK++;}break;
                   }    //card Table
          }while (crdType=="Redraw");
          
          cout<<"You drew "<<crdType<<".    Hand: "<<hand<<"    Deck: "<<deck
                  <<endl;
          cout<<"Draw a card? y/n (or press 'h' to view hand.)"<<endl;
          cin>>ans;
          while (ans == 'h' || ans == 'H'){
              if (cAce>0){cout<<"Aces: "<<cAce<<endl;}
              if (c2>0){cout<<"Twos: "<<c2<<endl;}
              if (c3>0){cout<<"Threes: "<<c3<<endl;}
              if (c4>0){cout<<"Fours: "<<c4<<endl;}
              if (c5>0){cout<<"Fives: "<<c5<<endl;}
              if (c6>0){cout<<"Sixes: "<<c6<<endl;}
              if (c7>0){cout<<"Sevens: "<<c7<<endl;}
              if (c8>0){cout<<"Eights: "<<c8<<endl;}
              if (c9>0){cout<<"Nines: "<<c9<<endl;}
              if (c10>0){cout<<"Tens: "<<c10<<endl;}
              if (cJ>0){cout<<"Jacks: "<<cJ<<endl;}
              if (cQ>0){cout<<"Queens: "<<cQ<<endl;}
              if (cK>0){cout<<"Kings: "<<cK<<endl;}
              cout<<endl;
              cout<<"Draw a card? y/n (or press 'h' to view hand.)"<<endl;
              cin>>ans;
          }     //view hand
          while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N'
                  && ans != 'h' && ans != 'H') {cout << "Please enter y/n"<<endl;
                                                cin>>ans;}
          if(ans=='n'||ans=='N'){deck=0;}
          if((ans=='y'||ans=='Y')&&deck==0) {cout<<"The deck is empty"<<endl;}
      }
      
        cout << endl;
        cout << "Play again? y/n" << endl;
        cin>>rstrt;
        while (rstrt != 'y' && rstrt != 'n' && rstrt != 'Y' && rstrt != 'N') {
            cout << "Please enter y/n" << endl;
            cin>>rstrt;
        }
        if (rstrt == 'y' || rstrt == 'Y')
            restart = true;
        else
            restart = false;
        } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

