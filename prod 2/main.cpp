//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Data.h"
#include "Data.cpp"


/*THE BOOK OBJECT 
        CONSTRUCTOR(7 STRINGS);
        void setSTAT(string str);
        string getSTAT() { return ISBN;}
        int discoverBookCount();
*/

/*THE REGISTER OBJECT
        generateInventory(int bookCount, Book **inventory);
        insertBook();
        printList(int bookCount, Book **inventory);
*/

using namespace std;
    
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
    
    void insertBook(){
        fstream logging("./book-files.txt", ios::app); 
        string info;
        cout << "ISBN: ";
        getline(cin,info);
            logging << endl << info;
        cout << "Author: ";
        getline(cin,info);
            logging << endl << info;
        cout << "Title: ";
        getline(cin,info);
            logging << endl << info;
        cout << "Publisher: ";
        getline(cin,info);
            logging << endl << info;
        cout << "Date: ";
        getline(cin,info);
            logging << endl << info;
        //CREATE A BLANK SPACE FOR DATE
            logging << endl << "0";
        cout << "wholesale cost: ";
        getline(cin,info);
            logging << endl << info;
        cout << "purchase date: ";
        getline(cin,info);
            logging << endl << info << endl;
        logging.close();
    }
    
	void printList(int bookCount, Book **inventory){
		for (int i = 0; i < bookCount; i++){
		    cout << "Book Number:" << i << "\n";
			cout << inventory[i]->getISBN() << endl;
			cout << inventory[i]->getTitle() << endl;
			cout << inventory[i]->getAuthor() << endl;
			cout << inventory[i]->getPublisher() << endl;
			cout << inventory[i]->getDateAdded() << endl;
			cout << inventory[i]->getQuantityOnHand() << endl;
			cout << inventory[i]->getWholesaleCost() << endl;
			cout << inventory[i]->getRetailPrice() << endl << endl;
		}
	}
	
	void wipeInventory(int bookCount, Book **inventory){
	    int t1;
        try{
            for(t1 = 0; t1 < bookCount; t1++){
                delete inventory[t1]; 
                //cout << t1;
            }
            if(t1<bookCount){
                string exceptionString = "\n\nERROR: not all of the books were printed\n\n";
                throw exceptionString;
            }
            if(t1==bookCount){
                cout << "\n\ninventory cleared\n\n";
            }
        }
        catch(string exceptionString){
            cout << exceptionString;
        }
        delete [] inventory;
	}

int main(){
    //INITILIZE CORE VARIBABLES
    Book a;
    Book **inventory = nullptr; 
    int bookCount;
    
    //BOOT UP INVENTORY
    bookCount = a.discoverBookCount();
    inventory = new Book*[bookCount];
    generateInventory(bookCount,inventory);
    
    //PRINT ENTIRE INVENTORY
    printList(bookCount,inventory);
    
    //ADD A BOOK TO DATABASE
    insertBook();
    
    //REFRESH INVENTORY AFTER DATABASE CHANGE
    wipeInventory(bookCount,inventory);
    bookCount = a.discoverBookCount();
    inventory = new Book*[bookCount];
    generateInventory(bookCount,inventory);
    printList(bookCount,inventory);

    
    //catch(...){
      //  cout << "UNDEFINED CATCH TRIGGERED";
    //}

    return 0;
    
}