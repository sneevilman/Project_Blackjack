/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 28 Jan, 2017
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
        
        char cAce=48, c2=48, c3=48, c4=48, c5=48, c6=48, c7=48, c8=48, c9=48, c10=48, 
                cJ=48, cQ=48, cK=48;
        hand=1;
  
      for(deck=51;deck>-1;deck--,hand++) {
          
          do{
              crdType="Redraw";
              drawV=rand()%13+1;
                  switch (drawV){
                      case 1:if(cAce!=52){crdType="an Ace";cAce++;}break;
                       case 2:if(c2!=52){crdType="a Two";c2++;}break;
                      case 3:if(c3!=52){crdType="a Three";c3++;}break;
                      case 4:if(c4!=52){crdType="a Four";c4++;}break;
                      case 5:if(c5!=52){crdType="a Five";c5++;}break;
                      case 6:if(c6!=52){crdType="a Six";c6++;}break;
                      case 7:if(c7!=52){crdType="a Seven";c7++;}break;
                      case 8:if(c8!=52){crdType="an Eight";c8++;}break;
                      case 9:if(c9!=52){crdType="a Nine";c9++;}break;
                      case 10:if(c10!=52){crdType="a Ten";c10++;}break;
                      case 11:if(cJ!=52){crdType="a Jack";cJ++;}break;
                      case 12:if(cQ!=52){crdType="a Queen";cQ++;}break;
                      case 13:if(cK!=52){crdType="a King";cK++;}break;
                   }    //card Table
          }while (crdType=="Redraw");
          
          cout<<"You drew "<<crdType<<".    Hand: "<<hand<<"    Deck: "<<deck
                  <<endl;
          cout<<"Draw a card? y/n (or press 'h' to view hand.)"<<endl;
          cin>>ans;
          while (ans == 'h' || ans == 'H'){
              if (cAce>48){cout<<"Aces: "<<cAce<<endl;}
              if (c2>48){cout<<"Twos: "<<c2<<endl;}
              if (c3>48){cout<<"Threes: "<<c3<<endl;}
              if (c4>48){cout<<"Fours: "<<c4<<endl;}
              if (c5>48){cout<<"Fives: "<<c5<<endl;}
              if (c6>48){cout<<"Sixes: "<<c6<<endl;}
              if (c7>48){cout<<"Sevens: "<<c7<<endl;}
              if (c8>48){cout<<"Eights: "<<c8<<endl;}
              if (c9>48){cout<<"Nines: "<<c9<<endl;}
              if (c10>48){cout<<"Tens: "<<c10<<endl;}
              if (cJ>48){cout<<"Jacks: "<<cJ<<endl;}
              if (cQ>48){cout<<"Queens: "<<cQ<<endl;}
              if (cK>48){cout<<"Kings: "<<cK<<endl;}
              cout<<endl;
              cout<<"Draw a card? y/n (or press 'h' to view hand.)"<<endl;
              cin>>ans;
          }     //view hand
          while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N'
                  && ans != 'h' && ans != 'H') {cout << "Please enter y/n"<<endl;
                                                cin>>ans;}
          if(ans=='n'||ans=='N'){deck=0;}
          if((ans=='y'||ans=='Y')&&deck==0) {cout<<"The deck is empty."<<endl;}
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

