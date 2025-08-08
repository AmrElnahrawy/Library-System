#include <bits/stdc++.h>
using namespace std;

const int maxCap = 100;
struct library_books
{
    int id;
    string name;
    int quantity;
};

struct library_users
{
    int id;
    string name;
};

struct borrow_return
{
    int status{0}; // 1 borrow, 2 return
    string user_name;
    string book_name;
};

struct library_system
{
    library_books books[maxCap];
    int addB{0};
    library_users users[maxCap];
    int addU{0};
    borrow_return borrowers[maxCap];
    int addBR{0};
    int menu()
    {
        int choice{-1};
        while (choice == -1)
        {
            cout << "Library Menu:" << endl;
            cout << "1) Add book" << endl;
            cout << "2) Search books by prefix" << endl;
            cout << "3) Print who borrowed book by name" << endl;
            cout << "4) Print library by id" << endl;
            cout << "5) Print library by name" << endl;
            cout << "6) Add user" << endl;
            cout << "7) User borrow book" << endl;
            cout << "8) User return book" << endl;
            cout << "9) Print users" << endl;
            cout << "10) Exit" << endl
                 << endl;
            cout << "Enter your menu choice [1 - 10]: ";
            cin >> choice;
            if (!(1 <= choice && choice <= 10))
            {
                cout << "Invalid choice, Please try again" << endl;
                choice = -1;
            }
        }
        return choice;
    }

    void run()
    {
        while (true)
        {
            int choice = menu();
            if (choice == 1)
                add_book();
            else if (choice == 2)
                search_book();
            else if (choice == 3)
                print_book_borrowers();
            else if (choice == 4)
                print_library_by_id();
            else if (choice == 5)
                print_library_by_name();
            else if (choice == 6)
                add_user();
            else if (choice == 7)
                user_borrow_book();
            else if (choice == 8)
                user_return_book();
            else if (choice == 9)
                print_users();
            else
                return;
        }
    }

    void add_book()
    {
        if (addB == maxCap)
        {
            cout << "Sorry the library is full" << endl;
            cout << "\n****************************************\n";
            return;
        }
        int id, quantity;
        string name;
        cout << "Enter book ID (integer) , Name , Quantity (integer): ";
        cin >> id >> name >> quantity;

        for (int i{0}; i < addB; i++)
        {
            if (books[i].id == id)
            {
                books[i].quantity += quantity;
                cout << "****************************************\n";
                return;
            }
        }
        books[addB].id = id;
        books[addB].name = name;
        books[addB].quantity = quantity;
        addB++;
        cout << "\n****************************************\n";
    }

    void search_book()
    {
        string prefix;
        cout << "Please enter the prefix of the book: ";
        cin >> prefix;
        cout << "****************************************\n";
        int flag = 0;
        for (int i{0}; i < addB; i++)
        {
            for (int j{0}; j < prefix.size(); j++)
            {
                if (prefix.size() > books[i].name.size())
                    break;
                if (prefix[j] != books[i].name[j])
                    break;
                if (j == prefix.size() - 1)
                {
                    if (flag)
                    {
                        cout << ", ";
                        flag = 0;
                    }
                    cout << books[i].name;
                    flag = 1;
                }
            }
        }
        if (!(flag))
        {
            cout << "There is no book with this prefix";
        }
        cout << "\n****************************************\n";
    }

    void print_book_borrowers()
    {
        string book_name;
        int flag = 1;
        cout << "Enter book name: ";
        cin >> book_name;
        cout << "****************************************\n";
        for (int i{0}; i < addB; i++)
        {
            if (book_name == books[i].name)
                break;
            if (i == addB - 1)
            {
                cout << "Book don't exist" << endl;
                cout << "****************************************\n";
                return;
            }
        }
        for (int i{0}; i < addBR; i++)
        {
            if (book_name == borrowers[i].book_name && borrowers[i].status == 1)
            {
                cout << borrowers[i].user_name << endl;
                flag = 0;
            }
        }
        if (flag)
        {
            cout << "No one borrowed this book" << endl;
        }
        cout << "****************************************\n";
    }

    static bool id_sort(library_books &a, library_books &b)
    {
        return a.id < b.id;
    }
    void print_library_by_id()
    {
        cout << "\n****************************************\n";
        if (addB == 0)
            cout << "There are no books to be printed\n";
        sort(books, books + addB, id_sort);
        for (int i{0}; i < addB; i++)
        {
            cout << "ID: " << books[i].id << ", Name: " << books[i].name << ", quantity: " << books[i].quantity << endl;
        }
        cout << "\n****************************************\n";
    }

    static bool name_sort(library_books &a, library_books &b)
    {
        return a.name < b.name;
    }
    void print_library_by_name()
    {

        cout << "\n****************************************\n";
        if (addB == 0)
            cout << "There are no books to be printed\n";
        sort(books, books + addB, name_sort);
        for (int i{0}; i < addB; i++)
        {
            cout << "ID: " << books[i].id << ", Name: " << books[i].name << ", quantity: " << books[i].quantity << endl;
        }
        cout << "\n****************************************\n";
    }

    void add_user()
    {
        if (addU == maxCap)
        {
            cout << "Sorry the library is full" << endl;
            cout << "\n****************************************\n";
            return;
        }
        int id;
        string name;
        cout << "Enter user ID (integer) , Name: ";
        cin >> id >> name;
        users[addU].id = id;
        users[addU].name = name;
        addU++;
        cout << "\n****************************************\n";
    }

    void print_users()
    {
        cout << "\n****************************************\n";
        if (addU == 0)
            cout << "There are no users to be printed\n";
        for (int i{0}; i < addU; i++)
        {
            cout << "ID: " << users[i].id << ", Name: " << users[i].name << endl;
        }
        cout << "\n****************************************\n";
    }

    void user_borrow_book()
    {
        if (addBR == maxCap)
        {
            cout << "Sorry the library is not active" << endl;
            cout << "\n****************************************\n";
            return;
        }
        string user_name;
        string book_name;
        cout << "Enter user name, book name: ";
        cin >> user_name >> book_name;

        for (int i{0}; i < addU; i++)
        {
            if (user_name == users[i].name)
                break;
            if (i == addU - 1)
            {
                cout << "User don't exist" << endl;
                cout << "\n****************************************\n";
                return;
            }
        }
        int book_index = 0;
        for (int i{0}; i < addB; i++)
        {
            if (book_name == books[i].name)
            {
                if (books[i].quantity == 0)
                {
                    cout << "All copies of that book is borrowed" << endl;
                    cout << "\n****************************************\n";
                    return;
                }
                book_index = i;
                break;
            }
            if (i == addB - 1)
            {
                cout << "Book don't exist" << endl;
                cout << "\n****************************************\n";
                return;
            }
        }
        borrowers[addBR].user_name = user_name;
        borrowers[addBR].book_name = book_name;
        books[book_index].quantity--;
        borrowers[addBR].status = 1;
        addBR++;
        cout << "\n****************************************\n";
    }
    void user_return_book()
    {
        string user_name;
        string book_name;
        cout << "Enter user name, book name: ";
        cin >> user_name >> book_name;
        int borrow_index = 0;
        for (int i{0}; i < addBR; i++)
        {
            if (user_name == borrowers[i].user_name && book_name == borrowers[i].book_name && borrowers[i].status == 1)
            {
                borrow_index = i;
                break;
            }
            if (i == addBR - 1)
            {
                cout << "Wrong user name or book name" << endl;
                cout << "\n****************************************\n";
                return;
            }
        }
        int book_index = 0;
        for (int i{0}; i < addB; i++)
        {
            if (book_name == books[i].name)
            {
                book_index = i;
                break;
            }
        }
        books[book_index].quantity++;
        borrowers[borrow_index].status = 2;
        cout << "\n****************************************\n";
    }
};

int main()
{
    library_system library;
    library.run();
}