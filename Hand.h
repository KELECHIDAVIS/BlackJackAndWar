/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Hand.h
 * Author: kboss
 *
 * Created on November 11, 2023, 11:11 AM
 */

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <iostream>
#include <queue>

using namespace std; 

class Hand { 
private:
    queue<Card*> cards; 
    
    string cardNumNames[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char suitNames[4] = {'H','C','D','S'} ; 
public :
    void addCard(Card* card )
    {
        cards.push(card); 
    }
    
    Card* dealCard()
    {
        Card* dealedCard = cards.front(); 
        cards.pop(); 
        return dealedCard; 
    }
    void clearHand ()
    {
        while(!cards.empty()){
            cards.pop(); 
        }
    }
    int getHandSize()
    {
        return cards.size(); 
    }
    
    void showTop()
    {
        cout<<" "<< cardNumNames[cards.front()->num-1]<<" "; 
    }
    
    void printHand()
    {
        for(int i = 0 ; i< getHandSize(); i++)
        {
            showTop(); 
            Card* tempCard = cards.front(); 
            cards.pop(); 
            cards.push(tempCard); 
        }
    }
    
    bool isEmpty()
    {
        return cards.empty(); 
    }
    
    // these functions below are just for black jack 
    int aceFind(int numAces , int sum)
    {
        if(sum >21 ) 
        {
            return -1; 
        }
        
        if(numAces == 0 )
        {
            return sum ; 
        }
        // now return the absolute highest number we can get with the amount of aces we have 
        
        // representation if the ace was valued at 1 
        int aceOne = aceFind(numAces -1 , sum+1 ); 
        
        int aceTwo = aceFind( numAces-1 , sum+11); 
        
        
        return max(aceOne  , aceTwo); 
    }
    // this func calc the most amount you hand could possibly equal without busting 
    int calcHand()
    {
        // To get the correct val we first add up all the non ace vals and subtract that from 21
        //If the result is less than 11 then the ace can only be a one otherwise we'll just return the highest number 
        
        int sum = 0 ; 
        int numOfAces = 0 ; 
        
        for(int i = 0 ; i< getHandSize(); i++)
        {
            if(cards.front()->num>1)
            {
                if(cards.front()->num>=10)
                {
                    sum+=10; 
                }else{
                    sum+=cards.front()->num; 
                }
            }else{
                numOfAces++ ; 
            }
            Card* tempCard = cards.front();
            cards.pop(); 
            cards.push(tempCard); 
        }
        
        
        if(sum>10) // all of your aces have to be one because if not sum is greater than 21 
        {
            sum+= numOfAces; 
            return sum ; 
        }else{
            
            // if sum equals exactly ten and we have one ace just return 21 
            if(sum ==10 && numOfAces==1)
            {
                return 21; 
            }else{
                // we can just return this recursive function that finds the sum with the given number of aces
                return aceFind(numOfAces, sum); 
            }
        }
        
        
    }
    
};

#endif /* HAND_H */

