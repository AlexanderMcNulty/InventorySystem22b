//#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

Book::Book(){
        ISBN = "testISNB";
        Author = "testAuthor";
}

Book::Book(string a, string b, string c, string d, string e, string f, string g, string h){
       ISBN = a;
       Author = b;
       Title = c;
       Publisher = d;
       DateAdded = e;
       QuantityOnHand = f;
       WholesaleCost = g;
       RetailPrice = h;
}
void Book::setISBN(string str) {ISBN = str;}
void Book::setTitle(string str) {Title = str;}
void Book::setAuthor(string str) {Author = str;}
void Book::setPublisher(string str) {Publisher = str;}
void Book::setDateAdded(string str) {DateAdded = str;}
void Book::setQuantityOnHand(string str) {QuantityOnHand = str;}
void Book::setWholesaleCost(string str) {WholesaleCost = str;}
void Book::setRetailPrice(string str) {RetailPrice = str;}

int Book::discoverBookCount(){
    //OPEN THE FILE TO FIND THE NUMBER ON ENTRIES
    fstream catelogData("./book-files.txt", ios::in);
    //READ THROUGH THE DOCUMENT AND COUNT THE NUMBER OF ENTRIES BASED ON NEWLINE CHARACTERS
    int BookCount=1;
    string tempBookInfo;
    if(catelogData){
        while(getline(catelogData, tempBookInfo, '\n')){
            if (tempBookInfo==""){
                BookCount++;
            }
        }
    } else {
        cout << "error";
    }
    //RETURN THE FSTREAM OBJECTS READING LOCATION TO THE BEGINNING OF FILE
    catelogData.close();
    return BookCount;
}

Book::~Book(){
    cout << "i ";
}