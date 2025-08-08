#include <bits/stdc++.h>
using namespace std;

const int maxCap = 100;
struct library_books
{
    int id;
    string name;
    int quantity;
};

struct library_system
{
    library_books books[maxCap];
    int add {0};
    int menu() {
        int choice {-1};
        while (choice == -1) {
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
            cout << "10) Exit" << endl << endl;
            cout << "Enter your menu choice [1 - 10]: ";
            cin >> choice;
            if (!(1 <= choice && choice <= 10)) {
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
            // else if (choice == 3)
            //     print_borrowers();
            // else if (choice == 4)
            //     print_library_by_id();
            // else if (choice == 5)
            //     print_library_by_name();
            // else if (choice == 6)
            //     add_user();
            // else if (choice == 7)
            //     user_borrow_book();
            // else if (choice == 8)
            //     user_return_book();
            // else if (choice == 9)
            //     print_users();
            // else
            //     return;
        }
    }

    void add_book() {
        if (add == maxCap) {
            cout << "Sorry the library if full";
            return;
        }
        int id , quantity;
        string name;
        cout << "Enter book ID (integer) , Name , Quantity: ";
        cin >> id >> name >> quantity;
        
        for (int i {0}; i <= add; i++) {
            if (books[i].id == id) {
                books[i].quantity += quantity;
                return;
            }
        }
        books[add].id = id;
        books[add].name = name;
        books[add].quantity = quantity;
        add++;
    }

    void search_book() {
        string prefix;
        cout << "Please enter the prefix of the book: ";
        cin >> prefix;
        cout << "****************************************\n";
        int flag = 0;
        for (int i {0}; i < add; i++) {
            for (int j {0}; j < prefix.size(); j++) {
                if (prefix[j] != books[i].name[j])
                    break;
                if (j == prefix.size() - 1) {
                    if (flag) {
                        cout << ", ";
                        flag = 0;
                    }
                    cout << books[i].name;
                    flag = 1;
                }
            }
        }
        if (!(flag)) {
            cout << "There is no book with this prefix";
        }
        cout << "\n****************************************\n";
    }
};

int main()
{
    library_system library;
    library.run();
}