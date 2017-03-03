#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*
class Catelog {
    private:
        
    
};
*/

class Book {
    private:
        string ISBN;
        string Title;
        string Author;
        string Publisher;
        string DateAdded;
        string QuantityOnHand;
        string WholesaleCost;
        string RetailPrice;
    public:
        Book();
        Book(string,string,string,string,string,string,string,string);
        void setISBN(string str);
        void setTitle(string str);
        void setAuthor(string str);
        void setPublisher(string str);
        void setDateAdded(string str);
        void setQuantityOnHand(string str);
        void setWholesaleCost(string str);
        void setRetailPrice(string str);
        string getISBN() { return ISBN;}
        string getAuthor() {return Author;}
        string getTitle() {return Title;}
        string getPublisher() {return Publisher;}
        string getDateAdded() {return DateAdded;}
        string getQuantityOnHand() {return QuantityOnHand;}
        string getWholesaleCost() {return WholesaleCost;}
        string getRetailPrice() {return RetailPrice;}
};
        Book::Book(){
                ISBN = "fuckisbn";
                Author = "fuckauthor";
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



int main(){
    
    //OPEN FILE CREATE ARRAY
    int bookCount=1;
    string tempBookInfo;
    fstream catelogData("./book-files.txt", ios::in);
    if(catelogData){
        while(getline(catelogData, tempBookInfo, '\n')){
            if (tempBookInfo==""){
                bookCount++;
            }
        }
    } else {
        cout << "error";
    }

    catelogData.close();
    catelogData.open("./book-files.txt", ios::in);
    
    Book **inventory = nullptr;
    inventory = new Book*[bookCount];
    
    int readingFlag = 0;
    int booksCreated = 0;
    string a,b,c,d,e,f,g,h,garbage;

    while(catelogData){
        getline(catelogData, a, '\n');
        getline(catelogData, b, '\n');
        getline(catelogData, c, '\n');
        getline(catelogData, d, '\n');
        getline(catelogData, e, '\n');
        getline(catelogData, f, '\n');
        getline(catelogData, g, '\n');
        getline(catelogData, h, '\n');
        getline(catelogData, garbage, '\n');
        inventory[booksCreated] = new Book(a,b,c,d,e,f,g,h);
        booksCreated++;
    }
   

    for(int i = 0; i < bookCount; i++){
        cout << inventory[i]->getISBN() << endl;
        cout << inventory[i]->getTitle() << endl;
        cout << inventory[i]->getAuthor() << endl;
        cout << inventory[i]->getPublisher() << endl;
        cout << inventory[i]->getDateAdded() << endl;
        cout << inventory[i]->getQuantityOnHand() << endl;
        cout << inventory[i]->getWholesaleCost() << endl;
        cout << inventory[i]->getRetailPrice() << endl << endl; 
    }
    
    return 0;
    
}