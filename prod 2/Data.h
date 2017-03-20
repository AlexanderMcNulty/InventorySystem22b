//#define _CRT_SECURE_NO_WARNINGS

#ifndef DATA_H
#define DATA_H

using namespace std;

class Book {
    private:
        //PRIVATE CLASS PROPERTIES
        string ISBN;
        string Title;
        string Author;
        string Publisher;
        string DateAdded;
        string QuantityOnHand;
        string WholesaleCost;
        string RetailPrice;
    public:
        //CONSTRUCTORS
        Book();
        Book(string,string,string,string,string,string,string,string);
        //DESTRUCTOR
        ~Book();
        //SETTERS
        void setISBN(string str);
        void setTitle(string str);
        void setAuthor(string str);
        void setPublisher(string str);
        void setDateAdded(string str);
        void setQuantityOnHand(string str);
        void setWholesaleCost(string str);
        void setRetailPrice(string str);
        //GETTERS
        string getISBN() { return ISBN;}
        string getAuthor() {return Author;}
        string getTitle() {return Title;}
        string getPublisher() {return Publisher;}
        string getDateAdded() {return DateAdded;}
        string getQuantityOnHand() {return QuantityOnHand;}
        string getWholesaleCost() {return WholesaleCost;}
        string getRetailPrice() {return RetailPrice;}
        //FUNCTIONAL FUNCTIONS
        int discoverBookCount();
};
    
#endif