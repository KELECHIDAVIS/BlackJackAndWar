/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Deck.h
 * Author: kboss
 *
 * Created on October 25, 2023, 6:59 PM
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std; 
class Deck {
    
    stack<Card*> cardStack;
    
    // these make it so i don't have to have if statements when printing 
    string cardNumNames[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char suitNames[4] = {'H','C','D','S'} ; 
public :
    
    Deck(){
        // a deck has 52 cards, 4 suit x 13 cards per suit
        
        for(int i = 0 ; i<4; i++)
        {
            for(int j =1; j<=13; j++)
            {
                Card* temp = new Card(); 
                temp->num = j;
                temp->suit = CardSuit(i); 
                cardStack.push(temp); 
            }
        }
        
        shuffle(); 
        
    }
    
    ~Deck()
    {
        deleteDeck(); 
    }
    
    void deleteDeck()
    {
        while(!cardStack.empty())
        {
            Card* temp = cardStack.top(); 
            delete temp; 
            cardStack.pop(); 
        }
    }
    
    stack<Card*> getCardStack(){
        return cardStack; 
    }
    
    Card* dealCard()
    {
        if ( !cardStack.empty())
        {
            Card* card = cardStack.top(); 
            cardStack.pop(); 
            return card; 
        }else{
            
            return nullptr; 
        }
    }
    
    void shuffle()
    {
        // have to copy contents into an arr then shuffle said array then copy back into a stack 
        Card* tempArr[52]; 
        
        for(int i = 0; i<52 ; i++ )
        {
            tempArr[i] = cardStack.top(); 
            cardStack.pop(); 
        }
        
        // shuffle original contents
        std::random_shuffle(begin(tempArr) , end(tempArr)); 
        
        //copy back into stack 
        for(int i = 0; i<52 ; i++ )
        {
            cardStack.push(tempArr[i]); 
        }
        
    }
    
    //The print function has to be done recursively so that we are able to keep the values of the array 
    void printDeck()
    {
        if(cardStack.empty())
        {        
            cout<<endl;
            return ; 
        }
        
        Card* temp = cardStack.top(); 
        cardStack.pop() ;
        printDeck(); 
        cardStack.push(temp); 
        
        printCard(temp); 
    
    }
    
    void printCard(Card* card)
    {
        cout<<cardNumNames[card->num-1]<<suitNames[card->suit]<<"  "; 
    }
    
        
};


#endif /* DECK_H */

