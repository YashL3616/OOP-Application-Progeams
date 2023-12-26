#include<iostream>
#include<cstring>

using namespace std;

class Book {
private:
    char title[100];
    char author[100];
    float price;
    char publisher[100];
    int stock;

public:
    // Constructor to set book details
    Book(const char* t, const char* a, float p, const char* pub, int s) {
        strcpy(title, t);
        strcpy(author, a);
        price = p;
        strcpy(publisher, pub);
        stock = s;
    }

    // Display book details
    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }

    // Check availability and calculate cost
    void checkAvailability(int numCopies) {
        // if (stock >= requestedCopies) {
        //     cout << "Book available. Enter the number of copies required: ";
        //     int numCopies;
        //     cin >> numCopies;

            if (numCopies <= stock) {
                float totalCost = numCopies * price;
                cout << "Total cost: $" << totalCost << endl;
            } else {
                cout << "Required copies not in stock.\n";
           }
        // } else {
        //     cout << "Book not available.\n";
        // }
    }
};

int main() {
    // Example usage of the Book class
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 10.99, "Scribner", 5);

    // Display book details
    cout << "Book details:\n";
    book1.displayDetails();

    // Check availability and calculate cost
    book1.checkAvailability(3);

    return 0;
}
