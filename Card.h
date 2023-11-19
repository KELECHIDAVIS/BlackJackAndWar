/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Card.h
 * Author: kboss
 *
 * Created on October 25, 2023, 6:48 PM
 */

#ifndef CARD_H
#define CARD_H

enum CardSuit {HEARTS, CLUBS, DIAMONDS, SPADES }; 

struct Card{
   int num ; // 1-13
   CardSuit suit; 
   
   
}; 

#endif /* CARD_H */

