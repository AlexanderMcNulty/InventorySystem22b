

#include <iostream>
#include <string>

using namespace std;


class library {

private:
	string isbn;
	string title;
	string author;
	double price;
	
public:

	library() {
		isbn = "rushisABitch";
		title = "rushiLovesSuckingCock";
		author = "my Dick";
		price = 69.69;
		

	}
	library(string, string,string,double);
	void setisbn(string i) { isbn = i; };
	void settitle(string t) { title = t; };
	string getisbn() { return isbn; };
	string gettitle() { return title; };
	string getauthor() { return author; };
	double getprice() { return price; };

};

library::library(string a, string b,string c, double p) {

	isbn = a;
	title = b;
	author = c;
	price = p;
}

library books[] = { library("fuck", "pussy","pornhub", 69.69), library("booty", "bitch","my Hoe", 0.69) };


void cashModule();
void inventoryDatabase();
void reportModule();

void menu() {

	int num = 0;

	while (num != 4) {

		cout << "  ____________________________________________________________________ " << endl;
		cout << " |                                                                    | " << endl;
		cout << " |                    Serendipity Booksellers                         | " << endl;
		cout << " |                          Main Menu                                 | " << endl;
		cout << " |                                                                    | " << endl;
		cout << " |                 1) CASHIER MODULE                                  | " << endl;
		cout << " |                 2) INVENTORY DATABASE MODULE                       | " << endl;
		cout << " |                 3) REPORT MODULE                                   | " << endl;
		cout << " |                 4) EXIT THE PROGRAM                                | " << endl;
		cout << " |                                                                    | " << endl;
		cout << " |____________________________________________________________________| " << endl;

		cout << " Enter your choice: ";
		cin >> num;

		int choice3 = 0;


		switch (num) {

		case 1:
			cashModule();
			break;
		case 2:
			inventoryDatabase();
			break;
		case 3:
			reportModule();
			break;
		case 4:
			
			break;
		default:
			cout << "Please eneter a valid number." << endl;
			menu();
			break;


		}

		if (num = 4) {
			break;
		}



	}





}




void cashModule() {

	//cash module

	int choice1 = 0;

	while (choice1 != 4) {

		cout << "Please use one of the following methods to search the book you would like to purchase." << endl;
		cout << " ________________________" << endl;
		cout << "|                        |" << endl;
		cout << "|      1) ISBN           |" << endl;
		cout << "|      2) Title          |" << endl;
		cout << "|      3) Author         |" << endl;
		cout << "|      4) Main menu      |" << endl;
		cout << "|Enter your choice below |" << endl;
		cout << "|________________________|" << endl;


		cin >> choice1;
		string isbn;
		string title;
		string author;
		int qty = 0;
		double tax = 0;
        double subtotal = 0;
	    double total = 0;

		switch (choice1)
		{
		case 1:
			cout << "Enter ISBN: ";
			cin >> isbn;
				
			tax = subtotal * 0.0925;
	
			// 9.25% california tax 
			total = qty * (subtotal + tax);

			cout << " How many quantity would you like ?";
			cin >> qty;

			cout << " Title : " << "            " << books[1].gettitle() << endl;
			cout << "isbn: " << "               " << books[1].getisbn() << endl;
			cout << "author: " << "             " << books[1].getauthor() << endl;
			cout << "# of qty purchased: " << "   " << qty << endl;
			cout << "Price: " << "              " << books[1].getprice() << endl;
			//	total = books[1].getprice();
			subtotal = qty * books[1].getprice();

			cout << "subtotal: " << "           " << subtotal << endl;
			cout << "salestax: " << "           " << tax << endl;
			cout << "total: " << "              " << total << endl;

			cout << "       " << "THANK YOU FOR SHOPPING" << "        " << endl;


			break;
		case 2:
			cout << "Enter Title: ";
			cin >> title;
	
			// gave it a random value, but actual value should be something like books[index].getretailvalue();
			// 9.25% california tax 
			total = qty * (subtotal + tax);

			cout << " How many quantity would you like ?";
			cin >> qty;

			cout << " Title : " << "            " << books[1].gettitle() << endl;
			cout << "isbn: " << "               " << books[1].getisbn() << endl;
			cout << "author: " << "             " << books[1].getauthor() << endl;
			cout << "# of qty purchased: " << "   " << qty << endl;
			cout << "Price: " << "              " << books[1].getprice() << endl;
			//	total = books[1].getprice();
			subtotal = qty * books[1].getprice();

			cout << "subtotal: " << "           " << subtotal << endl;
			cout << "salestax: " << "           " << tax << endl;
			cout << "total: " << "              " << total << endl;

			cout << "       " << "THANK YOU FOR SHOPPING" << "        " << endl;


			break;
		case 3:
			cout << "Enter Author: ";
			cin >> author;
		
			// gave it a random value, but actual value should be something like books[index].getretailvalue();
			// 9.25% california tax 
			total = qty * (subtotal + tax);

			cout << " How many quantity would you like ?";
			cin >> qty;

			cout << " Title : " << "            " << books[1].gettitle() << endl;
			cout << "isbn: " << "               " << books[1].getisbn() << endl;
			cout << "author: " << "             " << books[1].getauthor() << endl;
			cout << "# of qty purchased: " << "   " << qty << endl;
			cout << "Price: " << "              " << books[1].getprice() << endl;
			//	total = books[1].getprice();
			subtotal = qty * books[1].getprice();

			cout << "subtotal: " << "           " << subtotal << endl;
			cout << "salestax: " << "           " << tax << endl;
			cout << "total: " << "              " << total << endl;

			cout << "       " << "THANK YOU FOR SHOPPING" << "        " << endl;


			break;
		case 4:
		//	menu();
			break;
		default:
			cout << "please enter a valid number. " << endl;
			cashModule();
			break;
		}

		// search the isbn or title or author in the array 
		// if exists then asks the user for how many quantity he wants to buy
		// else print "we are out bitch";
	
	

		/*
		// then print out the reciept
		cout << " ___________________________________________________________________________ " << endl;
		cout << "|  Serendipity Book Sellers                                                 |" << endl;
		cout << "|___________________________________________________________________________|" << endl;
		cout << "| Qty    |ISBN            |Title                    |Price   | Total        | " << endl;
		cout << "|________|________________|_________________________|________|______________|" << endl;
		cout << "|        |                |                         |        |              |" << endl;
		cout << "|        |                |                         |        |              |" << endl;
		cout << "|        |                |                         |        |              |" << endl;
		cout << "|________|________________|_________________________|________|______________|" << endl;
		cout << "|                                                            |              |" << endl;
		cout << "|                         Subtotal:                          |              |" << endl;
		cout << "|                         Tax:                               |              |" << endl;
		cout << "|                         Total:                             |              |" << endl;
		cout << "|                                                            |              |" << endl;
		cout << "|  Thank you for shoping at Serendipity!                     |              |" << endl;
		cout << "|____________________________________________________________|______________|" << endl;

		// subtract the purchased book. some function
		*/

		if (choice1 = 4) {
			menu();
			break;
		}

	}


}




void inventoryDatabase() {

	// inventory module

	int choice2 = 0;

	while (choice2 != 5) {

		//inventory database module
		cout << " ___________________________________________" << endl;
		cout << "|        Serendipity Booksellers            |" << endl;
		cout << "|          Inventory Database               |" << endl;
		cout << "|                                           |" << endl;
		cout << "|       1) Look Up a Book                   |" << endl;
		cout << "|       2) Add a Book                       |" << endl;
		cout << "|       3) Edit a Book's Record             |" << endl;
		cout << "|       4) Delete a Book                    |" << endl;
		cout << "|       5) Return to the Main Menu          |" << endl;
		cout << "|                                           |" << endl;
		cout << "|        Enter your choice:                 |" << endl;
		cout << "|___________________________________________|" << endl;

		cin >> choice2;

		string isbn;
		string title;
		string author;
		int choice1 = 0;

		switch (choice2)
		{

		case 1:



			while (choice1 != 4) {

				cout << "Look up a book" << endl;

				cout << "Please use one of the following methods to search the book you would like to purchase." << endl;
				cout << " ________________________" << endl;
				cout << "|                        |" << endl;
				cout << "|      1) ISBN           |" << endl;
				cout << "|      2) Title          |" << endl;
				cout << "|      3) Author         |" << endl;
				cout << "|      4) main menu      |" << endl;
				cout << "|Enter your choice below |" << endl;
				cout << "|________________________|" << endl;


				cin >> choice1;

				switch (choice1)
				{
				case 1:
					cout << "Enter ISBN: ";
					cin >> isbn;
					break;
				case 2:
					cout << "Enter Title: ";
					cin >> title;
					break;
				case 3:
					cout << "Enter Author: ";
					cin >> author;
					break;
				case 4:
				//	menu();
					break;
				default:
					cout << "please enter a valid number. " << endl;
					inventoryDatabase();
					break;
				}


				if (choice1 = 4) {
					break;
				}


			}


			break;
		case 2:
			cout << "Add a book" << endl;
			break;
		case 3:
			cout << "Edit a book's record " << endl;
			break;
		case 4:
			cout << "delete a book " << endl;
			break;
		case 5:
			// return to main menu 
		//	menu();
			break;
		default:
			cout << "please enter a valid number. " << endl;
			inventoryDatabase();
			break;
		}


		if (choice2 = 5) {
			menu();
			break;
		}

	}


}









void reportModule() {

	int choice3 = 0;

	while (choice3 != 7) {

		cout << " ___________________________________________" << endl;
		cout << "|        Serendipity Booksellers            |" << endl;
		cout << "|                Reports                    |" << endl;
		cout << "|                                           |" << endl;
		cout << "|         1) Inventory Listing              |" << endl;
		cout << "|         2) Inventory Wholesale Value      |" << endl;
		cout << "|         3) Inventory Retail Value         |" << endl;
		cout << "|         4) Listing by Quantity            |" << endl;
		cout << "|         5) Listing by Cost                |" << endl;
		cout << "|         6) Listing by Age                 |" << endl;
		cout << "|         7) Return to Main Menu            |" << endl;
		cout << "|                                           |" << endl;
		cout << "|           ENTER YOUR CHOICE:              |" << endl;
		cout << "|___________________________________________|" << endl;

		cin >> choice3;

		double total = 0;

		switch (choice3)
		{

		case 1:
			cout << "Inventory List" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "isbn: " << books[i].getisbn() << endl;
				cout << "title: " << books[i].gettitle() << endl;
				cout << "author: " << books[i].getauthor() << endl;
				cout << " price: " << books[i].getprice() << endl;
				cout << endl;
			}
			break;
		case 2:
			cout << "Total WholeSale Value" << endl;
			for (int i = 0; i < 2; i++) {
				total += books[i].getprice();
				cout << endl;
			}
			cout << "Wholesale value : " << total << endl;
			//string total;
			/*for(int i  = 0; i < 2; i++){
			total += books[i].getWholesaleValue();
			cout << total << " " << "dollars" << endl;
			}*/
			break;
		case 3:
			cout << "Total retail Value" << endl;
			for (int i = 0; i < 2; i++) {
				total += books[i].getprice();
				cout << endl;
			}
			cout << "Retail value : " << total << endl;

			//string total;
			/*for(int i  = 0; i < 2; i++){
			total += books[i].getretailValue();
			cout << total << " " << "dollars" << endl;
			}*/
			break;
		case 4:
			cout << "Listing by quantity" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "isbn: " << books[i].getisbn() << endl;
				cout << "title: " << books[i].gettitle() << endl;
				cout << "author: " << books[i].getauthor() << endl;
				cout << " price: " << books[i].getprice() << endl;
				cout << endl;
			}
			// run a for loop and display inventory sorted by quantity 
		case 5:
			cout << "Listing by cost" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "isbn: " << books[i].getisbn() << endl;
				cout << "title: " << books[i].gettitle() << endl;
				cout << "author: " << books[i].getauthor() << endl;
				cout << " price: " << books[i].getprice() << endl;
				cout << endl;
			}
			// run a for loop and display inventory sorted by retail value
		case 6:
			cout << "Listing by age" << endl;
			for (int i = 0; i < 2; i++) {
				cout << "isbn: " << books[i].getisbn() << endl;
				cout << "title: " << books[i].gettitle() << endl;
				cout << "author: " << books[i].getauthor() << endl;
				cout << " price: " << books[i].getprice() << endl;
				cout << endl;
			}
			// run a for loop and display inventory sorted by date added 
		case 7:
			// return to menu
		//	menu();
			break;
		default:
			cout << "please enter a valid number." << endl;
			reportModule();
			break;
		}



		if (choice3 = 7) {
			menu();
			break;
		}

	}


}











int main() {


	menu();

	//	library books[] = { library("fuck", "pussy"), library("booty", "bitch") };


	//printout(); just testing




	// main menu

	/*
	int num = 0;

	while (num != 4){

	cout << "  ____________________________________________________________________ " << endl;
	cout << " |                                                                    | " << endl;
	cout << " |                    Serendipity Booksellers                         | " << endl;
	cout << " |                          Main Menu                                 | " << endl;
	cout << " |                                                                    | " << endl;
	cout << " |                 1) CASHIER MODULE                                  | " << endl;
	cout << " |                 2) INVENTORY DATABASE MODULE                       | " << endl;
	cout << " |                 3) REPORT MODULE                                   | " << endl;
	cout << " |                 4) EXIT THE PROGRAM                                | " << endl;
	cout << " |                                                                    | " << endl;
	cout << " |____________________________________________________________________| " << endl;

	cout << " Enter your choice: ";
	cin >> num;

	int choice3 = 0;


	switch (num){

	case 1:
	cashModule();
	break;
	case 2:
	inventoryDatabase();
	break;
	case 3:
	reportModule();
	break;
	case 4:
	break;
	default:
	cout << "Please eneter a valid number." << endl;
	break;


	}

	if (num = 4){
	break;
	}



	}
	*/

	cout << endl;
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}
