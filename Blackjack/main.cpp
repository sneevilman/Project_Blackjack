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
    short          deck=52,     //number of cards in deck
                   drawV,       //value of card drawn
                   hand,        //number of cards in hand
                   score,       //user's blackjack score
                   wins,        //total wins
                   losses;      //total losses
    char           rstrt,       //used to set restart value with y/n
                   vHand,       //used to view hand
                   ans;         //used to set draw value with y/n
    bool           draw,        //used to execute draw function
                   dupe,        //used to check for >4 of a card
                   restart;
    string         crdType;     //converts drawV to card type string
    

    //Process/Calculations Here
    
        short dAce=0,d2=0,d3=0,d4=0,d5=0,d6=0,d7=0,d8=0,d9=0,d10=0, 
                dJ=0,dQ=0,dK=0;    //tracks cards taken from the deck
        
    do {
        
        srand(time(0));       
        short hAce=0,h2=0,h3=0,h4=0,h5=0,h6=0,h7=0,h8=0,h9=0,h10=0,
              hJ=0,hQ=0,hK=0;     //tracks cards in hand
        hand=0;
        draw=true;
        
      do {
          hand++;
          deck--;
          do{
              crdType="Redraw";
              drawV=rand()%13+1;
                  switch (drawV){
                      case 1:if(dAce!=4){crdType="an Ace";hAce++;dAce++;}break;    //Checks number of card taken from deck - if it's 4, defaults and 
                       case 2:if(d2!=4){crdType="a Two";h2++;d2++;}break;          //rerolls drawV. If it's less than 4, add the card to your hand, and
                      case 3:if(d3!=4){crdType="a Three";h3++;d3++;}break;         //output the card type
                      case 4:if(d4!=4){crdType="a Four";h4++;d4++;}break;
                      case 5:if(d5!=4){crdType="a Five";h5++;d5++;}break;
                      case 6:if(d6!=4){crdType="a Six";h6++;d6++;}break;
                      case 7:if(d7!=4){crdType="a Seven";h7++;d7++;}break;
                      case 8:if(d8!=4){crdType="an Eight";h8++;d8++;}break;
                      case 9:if(d9!=4){crdType="a Nine";h9++;d9++;}break;
                      case 10:if(d10!=4){crdType="a Ten";h10++;d10++;}break;
                      case 11:if(dJ!=4){crdType="a Jack";hJ++;dJ++;}break;
                      case 12:if(dQ!=4){crdType="a Queen";hQ++;dQ++;}break;
                      case 13:if(dK!=4){crdType="a King";hK++;dK++;}break;
                   }    //card Table
          }while (crdType=="Redraw");   //card type table
          
          score=2*h2+3*h3+4*h4+5*h5+6*h6+7*h7+8*h8+9*h9+10*h10+10*hJ+10*hQ+10*hK;   //calculate score by multiplying hand quantities by card values
          for(short aces=hAce;aces>0;aces--){   //determines values of aces in hand
              if(score<=10){score+=11;}
              else{score+=1;}
          }
          
          cout<<"You drew "<<crdType<<".        Deck: "<<deck<<endl;   //tell the user what they drew
          cout<<"Score: "<<score<<endl;
          
          if(score==21){cout<<"Blackjack!"<<endl;wins++;draw=false;}
          if(score>21){cout<<"Busted!"<<endl;losses++;draw=false;}
          if(score<21){
          cout<<"Draw a card? y/n (or press 'h' to view hand.)"<<endl;
          cin>>ans;
          while (ans == 'h' || ans == 'H'){
              cout<<"You have "<<hand<<" cards in your hand"<<endl;
              if (hAce>0){cout<<"Aces: "<<hAce<<endl;} //displays how many of each type of card is in the user's hand
              if (h2>0){cout<<"Twos: "<<h2<<endl;}
              if (h3>0){cout<<"Threes: "<<h3<<endl;}
              if (h4>0){cout<<"Fours: "<<h4<<endl;}
              if (h5>0){cout<<"Fives: "<<h5<<endl;}
              if (h6>0){cout<<"Sixes: "<<h6<<endl;}
              if (h7>0){cout<<"Sevens: "<<h7<<endl;}
              if (h8>0){cout<<"Eights: "<<h8<<endl;}
              if (h9>0){cout<<"Nines: "<<h9<<endl;}
              if (h10>0){cout<<"Tens: "<<h10<<endl;}
              if (hJ>0){cout<<"Jacks: "<<hJ<<endl;}
              if (hQ>0){cout<<"Queens: "<<hQ<<endl;}
              if (hK>0){cout<<"Kings: "<<hK<<endl;}
              cout<<endl;
              cout<<"Draw again? y/n (or press 'h' to view hand.)"<<endl;
              cin>>ans;
          }     //view hand
          while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N'
                  && ans != 'h' && ans != 'H') {cout << "Please enter y/n"<<endl;   //checks if the input is valid
                                                cin>>ans;}
          if(ans=='n'||ans=='N'){draw=false;}
      }
      }while(draw);
      
      cout<<"Wins: "<<wins<<"   Losses: "<<losses<<endl;
      
        cout << endl;
        cout << "Play again? y/n" << endl;
        cin>>rstrt;
        while (rstrt != 'y' && rstrt != 'n' && rstrt != 'Y' && rstrt != 'N') {
            cout << "Please enter y/n" << endl;
            cin>>rstrt;
        }
        if (rstrt == 'y' || rstrt == 'Y'){
            restart = true;
            if(deck<13){
                cout<<"The dealer shuffles the deck"<<endl;
                deck=52;
                dAce=0,d2=0,d3=0,d4=0,d5=0,d6=0,d7=0,d8=0,d9=0,d10=0, 
                dJ=0,dQ=0,dK=0;
            }
        }else{restart=false;}
        
        } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

