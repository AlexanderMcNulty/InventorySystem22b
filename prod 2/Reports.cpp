#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


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
	Book(string, string, string, string, string, string, string, string);
	void setISBN(string str);
	void setTitle(string str);
	void setAuthor(string str);
	void setPublisher(string str);
	void setDateAdded(string str);
	void setQuantityOnHand(string str);
	void setWholesaleCost(string str);
	void setRetailPrice(string str);
	string getISBN() { return ISBN; }
	string getAuthor() { return Author; }
	string getTitle() { return Title; }
	string getPublisher() { return Publisher; }
	string getDateAdded() { return DateAdded; }
	string getQuantityOnHand() { return QuantityOnHand; }
	string getWholesaleCost() { return WholesaleCost; }
	string getRetailPrice() { return RetailPrice; }
};
Book::Book(){
	ISBN = "fuckisbn";
	Author = "fuckauthor";
	//Author = b;
}
Book::Book(string a, string b, string c, string d, string e, string f, string g, string h){
	ISBN = a;
	Author = c;
	Title = b;
	Publisher = d;
	DateAdded = e;
	QuantityOnHand = f;
	WholesaleCost = g;
	RetailPrice = h;
}

void Book::setISBN(string str) { ISBN = str; }
void Book::setTitle(string str) { Title = str; }
void Book::setAuthor(string str) { Author = str; }
void Book::setPublisher(string str) { Publisher = str; }
void Book::setDateAdded(string str) { DateAdded = str; }
void Book::setQuantityOnHand(string str) { QuantityOnHand = str; }
void Book::setWholesaleCost(string str) { WholesaleCost = str; }
void Book::setRetailPrice(string str) { RetailPrice = str; }

class Report{		//NOTE THAT THE REPORT CLASS IS BASED ON WHEN IT IS CALLED
private:
	Book** inventory;
	int totalBookTitles;
	int totalBooks;
	double totalWholesaleCost;
	double totalRetailPrice;
	
public:
	Report(Book* inventor[]){
		inventory = inventor;
		totalBookTitles = 0;
		totalBooks = 0;
		totalWholesaleCost = 0;
		totalRetailPrice = 0;
		//updateMembers();
	}
	

	void settotalBookTitles(){		//calculating the number of book titles we have available 
		int total = 0;
		int i = 0;
		/*
		while (inventory[i]->getTitle() != '\n'){	//**********************************RIGHT OVER HERE THERE'S A PROBLEM******************************************
			total++;
			i++;
			cout << total << endl;
		}
		*/
		int bookCount = 1;		
		string tempBookInfo;
		fstream catalogData("./book-files.txt", ios::in);
		if (catalogData){
			while (getline(catalogData, tempBookInfo, '\n')){
				if (tempBookInfo == ""){
					bookCount++;
				}
			}
		}
		catalogData.close();
		totalBookTitles = bookCount;
	}

	
	
	void settotalBooks(){		//calculating the number of physical book copies we have available
		int total = 0;
		for (int i = 0; i < totalBookTitles; i++)
		{
			total += (stoi(inventory[i]->getQuantityOnHand()));	
		}
		totalBooks = total;
		
	}
	
	void settotalWholesaleCost(){
		double cost = 0;
		for (int i = 0; i < totalBookTitles; i++){
			cost += (stod(inventory[i]->getWholesaleCost()) * stod(inventory[i]->getQuantityOnHand()));
		}
		totalWholesaleCost = cost;
	}

	void settotalRetailPrice(){
		double cost = 0;
		for (int i = 0; i < totalBookTitles; i++){
			cost += (stod(inventory[i]->getRetailPrice()) * stod(inventory[i]->getQuantityOnHand()));
		}
		totalRetailPrice = cost;
	}

	void updateMembers(){		//This function will update all the values in the report according to the current version of the inventory[]
		settotalBookTitles();	//running this to update the number of titles first
		settotalBooks();		//then update the total number of physical book copies available for sale
		settotalWholesaleCost();
		settotalRetailPrice();
	}

	
	int gettotalBookTitles() { return totalBookTitles; }
	int gettotalBooks() { return totalBooks; }
	double gettotalRetailPrice() { return totalRetailPrice; }
	double gettotalWholesaleCost() { return totalWholesaleCost; }
	
	void printList(){
		for (int i = 0; i < totalBookTitles; i++){
			cout << inventory[i]->getISBN() << endl;
			cout << inventory[i]->getTitle() << endl;
			cout << inventory[i]->getAuthor() << endl;
			cout << inventory[i]->getPublisher() << endl;
			cout << inventory[i]->getDateAdded() << endl;
			cout << inventory[i]->getQuantityOnHand() << endl;
			cout << inventory[i]->getWholesaleCost() << endl;
			cout << inventory[i]->getRetailPrice() << endl << endl;
		}
		return;
	}

	void printWholesaleList(){
		for (int i = 0; i < totalBookTitles; i++){
			cout << inventory[i]->getISBN() << endl;
			cout << inventory[i]->getTitle() << endl;
			cout << inventory[i]->getWholesaleCost() << endl << endl;
		}
		cout << fixed << setprecision(2) << "Total Wholesale Cost: $" << totalWholesaleCost << endl;
		return;
	}

	void printRetailPriceList(){
		for (int i = 0; i < totalBookTitles; i++){
			cout << inventory[i]->getISBN() << endl;
			cout << inventory[i]->getTitle() << endl;
			cout << inventory[i]->getRetailPrice() << endl << endl;
		}
		cout << fixed << setprecision(2) << "Total Retail Price: $" << totalRetailPrice << endl;
		return;
	}

	void swapBooks(int current, int smallestIndex){
		//Take the smallest one and move it to "current" position and moves the one in "current" position to where smallestIndex was
		//tempString is used to avoid overwriting the array item
		string tempString = "";
		tempString = inventory[current]->getISBN();
		inventory[current]->setISBN(inventory[smallestIndex]->getISBN());
		inventory[smallestIndex]->setISBN(tempString);
		tempString = inventory[current]->getTitle();
		inventory[current]->setTitle(inventory[smallestIndex]->getTitle());
		inventory[smallestIndex]->setTitle(tempString);
		tempString = inventory[current]->getAuthor();
		inventory[current]->setAuthor(inventory[smallestIndex]->getAuthor());
		inventory[smallestIndex]->setAuthor(tempString);
		tempString = inventory[current]->getPublisher();
		inventory[current]->setPublisher(inventory[smallestIndex]->getPublisher());
		inventory[smallestIndex]->setPublisher(tempString);
		tempString = inventory[current]->getDateAdded();
		inventory[current]->setDateAdded(inventory[smallestIndex]->getDateAdded());
		inventory[smallestIndex]->setDateAdded(tempString);
		tempString = inventory[current]->getQuantityOnHand();
		inventory[current]->setQuantityOnHand(inventory[smallestIndex]->getQuantityOnHand());
		inventory[smallestIndex]->setQuantityOnHand(tempString);
		tempString = inventory[current]->getWholesaleCost();
		inventory[current]->setWholesaleCost(inventory[smallestIndex]->getWholesaleCost());
		inventory[smallestIndex]->setWholesaleCost(tempString);
		tempString = inventory[current]->getRetailPrice();
		inventory[current]->setRetailPrice(inventory[smallestIndex]->getRetailPrice());
		inventory[smallestIndex]->setRetailPrice(tempString);
		return;
	}

	void orderByQuantity(){
		int check; int current; int smallestIndex;

		//Looping for each index of the array
		for (current = 0; current < totalBookTitles - 1; current++){
			smallestIndex = current;
			for (check = current + 1; check < totalBookTitles; check++){
				if (stoi(inventory[check]->getQuantityOnHand()) < stoi(inventory[smallestIndex]->getQuantityOnHand())){
					smallestIndex = check;
				}
			}//use check to go across each index starting from the current. this current will keep rising 1 at a time

			swapBooks(current, smallestIndex);

		}//for current
		return;
	}

	void orderByCost(){
		//Purpose: sort elements in cost order
		int check; int current; int smallestIndex;
		//Looping for each index of the array
		for (current = 0; current < totalBookTitles - 1; current++){
			smallestIndex = current;
			for (check = current + 1; check < totalBookTitles; check++){
				if (stod(inventory[check]->getWholesaleCost()) < stod(inventory[smallestIndex]->getWholesaleCost()))
					smallestIndex = check;
			}//use check to go across each index starting from the current. this current will keep rising 1 at a time
			swapBooks(current, smallestIndex);
		}//for current
		return;
	}

	void orderByAge(){
		//Purpose: sort elements in age order
		int check; int current; int smallestIndex;
		//going to need to figure out how to make date (1/01/2017 etc) into a number to be ordered
		//Looping for each index of the array
		for (current = 0; current < totalBookTitles - 1; current++){
			smallestIndex = current;
			for (check = current + 1; check < totalBookTitles; check++){
				if (stoi((inventory[check]->getDateAdded()).substr(6, 4)) < (stoi((inventory[smallestIndex]->getDateAdded()).substr(6, 4)))){
					smallestIndex = check;
				}
				else if (stoi((inventory[check]->getDateAdded()).substr(6, 4)) == (stoi((inventory[smallestIndex]->getDateAdded()).substr(6, 4)))){
					if (stoi((inventory[check]->getDateAdded()).substr(0, 2)) < (stoi((inventory[smallestIndex]->getDateAdded()).substr(0, 2)))){
						smallestIndex = check;
					}
					else if (stoi((inventory[check]->getDateAdded()).substr(0, 2)) == (stoi((inventory[smallestIndex]->getDateAdded()).substr(0, 2)))){
						if (stoi((inventory[check]->getDateAdded()).substr(3, 2)) < (stoi((inventory[smallestIndex]->getDateAdded()).substr(3, 2)))){
							smallestIndex = check;
						}
					}
				}
			}//use check to go across each index starting from the current. this current will keep rising 1 at a time
			swapBooks(current, smallestIndex);
		}//for current
		return;
	}
};


//void printList(int, Book**);
//void printWholesaleList(int, Book**);
//double calcWholeSaleTotal(int, Book**);
//void printRetailPriceList(int , Book** );
//double calcRetailPriceTotal(int, Book**);
//void orderByQuantity(int , Book** );
//void orderByCost(int , Book** );
//void orderByAge(int , Book** );
//void swapBooks(int, Book**, int, int);

int main(){

	//OPEN FILE CREATE ARRAY
	int bookCount = 1;
	string tempBookInfo;
	fstream catelogData("./book-files.txt", ios::in);
	if (catelogData){
		while (getline(catelogData, tempBookInfo, '\n')){
			if (tempBookInfo == ""){
				bookCount++;
			}
		}
	}
	else {
		cout << "error";
	}

	catelogData.close();
	catelogData.open("./book-files.txt", ios::in);

	Book **inventory = nullptr;
	inventory = new Book*[bookCount];

	int readingFlag = 0;
	int booksCreated = 0;
	string a, b, c, d, e, f, g, h, garbage;

	while (catelogData){
		getline(catelogData, a, '\n');
		getline(catelogData, b, '\n');
		getline(catelogData, c, '\n');
		getline(catelogData, d, '\n');
		getline(catelogData, e, '\n');
		getline(catelogData, f, '\n');
		getline(catelogData, g, '\n');
		getline(catelogData, h, '\n');
		getline(catelogData, garbage, '\n');
		inventory[booksCreated] = new Book(a, b, c, d, e, f, g, h);
		booksCreated++;
	}

	cout << "test";

	//Testing statements
	/*
	Report reppy = Report(inventory);
	cout << bookCount << endl;
	reppy.settotalBookTitles();
	cout << reppy.gettotalBookTitles() << endl;
	reppy.settotalBooks();
	cout << reppy.gettotalBooks() << endl;
	reppy.settotalWholesaleCost();
	cout << reppy.gettotalWholesaleCost() << endl;
	reppy.settotalRetailPrice();
	cout << reppy.gettotalRetailPrice() << endl;
	reppy.printList();
	*/

	return 0;
	
}



