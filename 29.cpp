/*
Create a class for Book. A book has unique isbn (string), title, a list of authors, and a price. Write relevant
functions. Now write a class BookStore which has a list of books. There may be multiple copies of a book in the
book store. Write relevant member functions. Write a function books() that returns list of unique isbn numbers of
the books, a function noOfCopies() that returns the number of copies available for a given isbn number and a
function totalPrice() that returns the total price of all the books. Create a book store having a number of books
(multiple copies). Now, for each book, print number of copies of that book along with its title.
*/

// If code doesn't run properly on vscode, use
// this link to online ide: https://ide.geeksforgeeks.org/EGbtgrmjdE

#include <iostream>
using namespace std;

class Book
{
    string isbn, title;
    string *auth;
    double price;

public:
    Book()
    {
        isbn = title = "";
        price = 0.0;
    }
    Book(string is, string t, string a[], int na, double p)
    {
        isbn = is;
        title = t;
        price = p;
        auth = new string[na];
        for (int i = 0; i < na; i++)
            auth[i] = a[i];
    }
    // getters
    string getIsbn()
    {
        return isbn;
    }
    string getTitle()
    {
        return title;
    }
    double getPrice()
    {
        return price;
    }
};

class BookStore
{
    Book *books;
    int size;

public:
    BookStore()
    {
        size = 0;
    }
    BookStore(Book b[], int sz)
    {
        size = sz;
        books = (Book *)malloc(size * sizeof(Book));
        for (int i = 0; i < size; i++)
            books[i] = b[i];
    }

    string *uniqueBooks()
    {
        string *isbn_list = new string[size];
        int k = 0;
        for (int i = 0; i < size; i++)
        {
            int j;
            for (j = 0; j < i; j++)
            {
                if (books[i].getIsbn() == books[j].getIsbn())
                    break;
            }
            if (j == i)
                isbn_list[k++] = books[i].getIsbn();
        }
        return isbn_list;
    }

    int noOfCopies(string isbn)
    {
        int ctr = 0;
        for (int i = 0; i < size; i++)
        {
            if (books[i].getIsbn() == isbn)
                ctr++;
        }
        return ctr;
    }

    double totalPrice()
    {
        double tot = 0.0;
        for (int i = 0; i < size; i++)
        {
            tot += books[i].getPrice();
        }
        return tot;
    }

    void printDetailsOfBook(Book book)
    {
        cout << "Title: " << book.getTitle() << "\n";
        cout << "ISBN: " << book.getIsbn() << "\n";
        cout << "Nos of copies available: " << noOfCopies(book.getIsbn()) << "\n";
    }
};

int main()
{
    string a1[] = {"Silberschatz", "Korth", "Sudarshan"};
    string a2[] = {"Andrew Ng", "Lawrence Mooroney"};
    string a3[] = {"V.J. Dalal"};
    string a4[] = {"J.D.Lee", "Sudarshan Guha"};
    string a5[] = {"R.Resnick", "D.Halliday"};

    Book b1 = Book("1243592005823", "DBMS", a1, 3, 780);
    Book b2 = Book("1402050504504", "Deep Learning", a2, 2, 1825.75);
    Book b3 = Book("9087892619493", "ICSE Chemistry", a3, 1, 500);
    Book b4 = Book("3460912487608", "Inorganic Chemistry for JEE", a4, 2, 750.00);
    Book b5 = Book("8956748877178", "Physics Vol.1", a5, 2, 570.00);
    Book b6 = Book("1402050504504", "Deep Learning", a2, 2, 1825.75);
    Book b7 = Book("9087892619493", "ICSE Chemistry", a3, 1, 500);

    Book b[] = {b1, b2, b3, b4, b5, b6, b7};
    BookStore bs = BookStore(b, 7);

    cout << "Unique Books:\n";
    string *isbn_list = bs.uniqueBooks();
    for (int i = 0; i < 7; i++)
    {
        cout << isbn_list[i] << "\n";
    }
    cout << "Details of each book:\n";
    for (int i = 0; i < 7; i++)
    {
        bs.printDetailsOfBook(b[i]);
        cout << "\n\n";
    }
    cout << "Total price of bookstore: Rs " << bs.totalPrice() << "\n";
}