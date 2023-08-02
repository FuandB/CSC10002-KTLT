#include "source.h"
/*struct book{
    char title[201];
    char id[11];
    char name[41];
    char language[40];
    unsigned int year;
    unsigned long int price;
    unsigned int stock;
    book *bnext;
};*/
void insertBook(book *&bookstore){
    book *temp = new book;
    
    cout<<"Enter title :";
    cin.ignore();
    cin.getline(temp->title,201);
    temp->title[200] = '\0';

    cout<<"Enter id :";
    cin.ignore();
    cin.getline(temp->id,11);
    temp->id[10] = '\0';

    cout<<"Enter author :";
    cin.ignore();
    cin.getline(temp->auth,41);
    temp->auth[40] = '\0';

    cout<<"Enter language :";
    cin.ignore();
    cin.getline(temp->language,41);
    temp->language[40] = '\0';

    cout<<"Enter publish year: ";
    cin>>temp->year;
    cout<<"Enter price: ";
    cin>>temp->price;
    temp->stock = 1;
    temp->bnext = nullptr;

    if(bookstore == nullptr)
    {
        bookstore = temp;
        return;
    }

    book *cur = bookstore;
    while(cur->bnext!=nullptr)
    {
        if(strcmp(cur->id,temp->id)==0)
        {
            cur->stock++;
            return;
        }
        cur=cur->bnext;
    }
    cur->bnext = temp;


}

//Sell a book: input an ISBN, print out the name and the price of the book. Then, reduce the number
//of stock level of that book. If the book is out of stock (i.e. level is zero), print out “OUT OF STOCK.”

void sellaBook(book*& bookstore)
{
    char id[11];
    cout << "Enter ISBN of the book you want to sell: ";
    cin.ignore(); // Ignore any remaining newline character
    cin.getline(id, 11);

    if (bookstore == nullptr)
    {
        cout << "The bookstore is empty, the book is out of stock\n";
        return;
    }

    book* cur = bookstore;
    book* prev = nullptr;

    while (cur != nullptr)
    {
        if (!strcmp(id, cur->id))
        {
            if (cur->stock > 1)
            {
                cur->stock--;
                cout << "Book sold successfully. Updated stock: " << cur->stock << endl;
                return;
            }
            else
            {
                if (prev == nullptr)
                {
                    bookstore = cur->bnext;
                }
                else
                {
                    prev->bnext = cur->bnext;
                }
                cout << "Book sold successfully. The book is now out of stock\n";
                delete cur;
                return;
            }
        }
        prev = cur;
        cur = cur->bnext;
    }

    cout << "We do not have the book with the given ISBN\n";
}

//Find a book: input the name, print all the books (ISBN and title) whose titles contain the name as
//a subset.
void searchBook(book*&bookstore)
{
    if(bookstore==nullptr)
    {
        cout<<"There is no book in this bookstore!!";
        return;
    }
    char name[201];
    cout<<"Enter search book's name : ";
    cin.ignore();
    cin.getline(name,201);
    name[200] = '\0';

    book *cur = bookstore;
    int count = 0;
    while(cur!= nullptr)
    {
        if(strstr(cur->title,name)!= nullptr)
        {
            cout<<"ISBN: "<<cur->id;
            cout<<"\nTitle: "<<cur->title<<endl;
            count++;

        }
        cur=cur->bnext;
    }
    if(count==0)
    {
        cout<<"Your book's name does not match any book in our store!!\n";
    }

}

void removeAllBook(book *&bookstore)
{
    if(bookstore==nullptr)
    {
        cout<<"Book store is empty"<<endl;
        return;
    }
    book *cur = bookstore;

    while(cur!=nullptr)
    {
        book *temp = cur;
        cur = cur->bnext;
        delete temp;
    }
    bookstore = nullptr;
}