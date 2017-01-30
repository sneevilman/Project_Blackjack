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
        
        char dAce=48,d2=48,d3=48,d4=48,d5=48,d6=48,d7=48,d8=48,d9=48,d10=48, 
                dJ=48,dQ=48,dK=48,    //tracks cards taken from the deck
                hAce=48,h2=48,h3=48,h4=48,h5=48,h6=48,h7=48,h8=48,h9=48,h10=48,
                hJ=48,hQ=48,hK=48;     //tracks cards in hand
        hand=1;
  
      for(deck=51;deck>-1;deck--,hand++) {
          
          do{
              crdType="Redraw";
              drawV=rand()%13+1;
                  switch (drawV){
                      case 1:if(dAce!=52){crdType="an Ace";hAce++;dAce++;}break;    //Checks number of card taken from deck - if it's 4, defaults and 
                       case 2:if(d2!=52){crdType="a Two";h2++;d2++;}break;          //rerolls drawV. If it's less than 4, add the card to your hand, and
                      case 3:if(d3!=52){crdType="a Three";h3++;d3++;}break;         //output the card type
                      case 4:if(d4!=52){crdType="a Four";h4++;d4++;}break;
                      case 5:if(d5!=52){crdType="a Five";h5++;d5++;}break;
                      case 6:if(d6!=52){crdType="a Six";h6++;d6++;}break;
                      case 7:if(d7!=52){crdType="a Seven";h7++;d7++;}break;
                      case 8:if(d8!=52){crdType="an Eight";h8++;d8++;}break;
                      case 9:if(d9!=52){crdType="a Nine";h9++;d9++;}break;
                      case 10:if(d10!=52){crdType="a Ten";h10++;d10++;}break;
                      case 11:if(dJ!=52){crdType="a Jack";hJ++;dJ++;}break;
                      case 12:if(dQ!=52){crdType="a Queen";hQ++;dQ++;}break;
                      case 13:if(dK!=52){crdType="a King";hK++;dK++;}break;
                   }    //card Table
          }while (crdType=="Redraw");   //card type table
          
          
          
          cout<<"You drew "<<crdType<<".    Hand: "<<hand<<"    Deck: "<<deck
                  <<endl;   //tell the user what they drew
          cout<<"Draw a card? y/n (or press 'h' to view hand.)"<<endl;
          cin>>ans;
          while (ans == 'h' || ans == 'H'){
              if (hAce>48){cout<<"Aces: "<<hAce<<endl;} //displays how many of each type of card is in the user's hand
              if (h2>48){cout<<"Twos: "<<h2<<endl;}
              if (h3>48){cout<<"Threes: "<<h3<<endl;}
              if (h4>48){cout<<"Fours: "<<h4<<endl;}
              if (h5>48){cout<<"Fives: "<<h5<<endl;}
              if (h6>48){cout<<"Sixes: "<<h6<<endl;}
              if (h7>48){cout<<"Sevens: "<<h7<<endl;}
              if (h8>48){cout<<"Eights: "<<h8<<endl;}
              if (h9>48){cout<<"Nines: "<<h9<<endl;}
              if (h10>48){cout<<"Tens: "<<h10<<endl;}
              if (hJ>48){cout<<"Jacks: "<<hJ<<endl;}
              if (hQ>48){cout<<"Queens: "<<hQ<<endl;}
              if (hK>48){cout<<"Kings: "<<hK<<endl;}
              cout<<endl;
              cout<<"Draw again? y/n (or press 'h' to view hand.)"<<endl;
              cin>>ans;
          }     //view hand
          while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N'
                  && ans != 'h' && ans != 'H') {cout << "Please enter y/n"<<endl;   //checks if the input is valid
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

