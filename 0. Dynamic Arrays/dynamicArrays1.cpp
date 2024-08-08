#include <iostream> 
using namespace std; 

class Card{

string cardNumber, cardName; 
double cardBalance; 

public: 

// card constructor
Card(string name, string number, double balance){
  cardNumber = number; 
  cardName = name; 
  cardBalance = balance; 
}

// Card functions (public) 
string getNumber(){ return cardNumber;}
string getName(){ return cardName; }
double getBalance(){ return cardBalance; } 
void setBalance(double balance){ cardBalance = balance; }
};

int  main(){

  // allocating memory for 3 "Card" type objects storing them in a pointer array named "wallet" 
  Card **wallet = new Card *[3]; 

  wallet[0] = new Card("Jacob", "1234", 1000.0); 
  wallet[1] = new Card("Elijah", "2345", 12000.01); 
  wallet[2] = new Card("Ellie", "3434" , 1500.58); 

  // lets print out these cards stored in "wallet" pointer array
  for(int i = 0; i<3; i++){
    cout<<"This is wallet "<<i<<" and their name is "<<wallet[i]->getName()<<"."<<"Their Balance is "<<wallet[i]->getBalance()<<"\n"; 
  
}


}
