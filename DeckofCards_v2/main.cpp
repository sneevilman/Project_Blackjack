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
                   ans;         //used to set draw value with y/n
    bool           draw,        //used to execute draw function
                   dupe,        //used to check for >4 of a card
                   restart;
    string         crdType;     //converts drawV to card type string
    

    //Process/Calculations Here
    
    do {
        
        srand(time(0));
        hand = 0;
        deck = 52;
        
        short cAce=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0, cJack=0, cQueen=0, cKing=0;
        
        cout<<"You drew a card"<<endl;
  
      do {
 
          drawV = rand() %13+1;
          deck -=1;
          hand +=1;
          dupe = false;
          cout<<"DrawV = "<<drawV<<endl;      //test line
          
          {
              if(drawV==1&&cAce!=4){
                  crdType="an Ace";
                  cAce+=1;
                  cout<<"cAce = "<<cAce<<endl;
                  dupe = true;
              }
              
              else if(drawV==2&&c2!=4){
                  crdType="a two";
                  c2+=1;
                  cout<<"c2 = "<<c2<<endl;
                  dupe = true;
              }
              
              else if(drawV==3&&c3!=4){
                  crdType="a three";
                  c3+=1;
                  cout<<"c3 ="<<c3<<endl;
                  dupe = true;
              }
              
              else if(drawV==4&&c4!=4){
                  crdType="a four";
                  c4+=1;
                  cout<<"c4 ="<<c4<<endl;
                  dupe = true;
              }
              
              else if(drawV==5&&c5!=4){
                  crdType="a five";
                  c5+=1;
                  cout<<"c5 ="<<c5<<endl;
                  dupe = true;
              }
              
              else if(drawV==6&&c6!=4){
                  crdType="a six";
                  c6+=1;
                  cout<<"c6 ="<<c6<<endl;
                  dupe = true;
              }
              
              else if(drawV==7&&c7!=4){
                  crdType="a seven";
                  c7+=1;
                  cout<<"c7 ="<<c7<<endl;
                  dupe = true;
              }
              
              else if(drawV==8&&c8!=4){
                  crdType="an eight";
                  c8+=1;
                  cout<<"c8 ="<<c8<<endl;
                  dupe = true;
              }
              
              else if(drawV==9&&c9!=4){
                  crdType="a nine";
                  c9+=1;
                  cout<<"c9 ="<<c9<<endl;
                  dupe = true;
              }
              
              else if(drawV==10&&c10!=4){
                  crdType="a ten";
                  c10+=1;
                  cout<<"c10 ="<<c10<<endl;
                  dupe = true;
              }
              
              else if(drawV==11&&cJack!=4){
                  crdType="a Jack";
                  cJack+=1;
                  cout<<"cJack ="<<cJack<<endl;
                  dupe = true;
              }
              
              else if(drawV==12&&cQueen!=4){
                  crdType="a Queen";
                  cQueen+=1;
                  cout<<"cQueen ="<<cQueen<<endl;
                  dupe = true;
              }
              
              else if(drawV==13&&cKing!=4){
                  crdType="a King";
                  cKing+=1;
                  cout<<"cKing ="<<cKing<<endl;
                  dupe = true;
              }
              
          }             //crdType Table
          
          draw = false;
          
          if (dupe == true){
              cout<<"You drew "<<crdType<<"."<<endl;
          
          cout<<"There are "<<hand<<" cards in your hand."<<endl;
          cout<<"There are "<<deck<<" cards left in the deck."<<endl;

          cout<<"Draw a card? y/n"<<endl;
          cin>>ans;
          while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N') {
          cout << "Please enter y/n" << endl;
          cin>>ans;
          }
          }else{
              draw = true;
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

        {cout << endl;
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
        }} while (restart);

    //Output Located Here

    //Exit
    return 0;
}

