#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

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
    
    void generateInventory(int bookCount, Book **inventory){
        fstream catelogData("./book-files.txt", ios::in);
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
        
        catelogData.close();
    }

int main(){
    
    Book a;
    int bookCount = a.discoverBookCount();
    Book **inventory = new Book*[bookCount];
    generateInventory(bookCount,inventory);

   

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