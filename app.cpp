#include <bits/stdc++.h>
using namespace std;

struct library_books
{
    
};

struct library_system
{
    int menu() {
        int choice = -1;
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
            if (1 <= choice && choice <= 10) {
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
            {
                add_book();
            }
            else if (choice == 2)
            {
                search_book();
            }
            else if (choice == 3)
            {
                print_borrowers();
            }
            else if (choice == 4)
            {
                print_library_by_id();
            }
            else if (choice == 5)
            {
                print_library_by_name();
            }
            else if (choice == 6)
            {
                add_user();
            }
            else if (choice == 7)
            {
                user_borrow_book();
            }
            else if (choice == 8)
            {
                user_return_book();
            }
            else if (choice == 9)
            {
                print_users();
            }
            else if (choice == 10)
            {
                return;
            }
        }
    }
}

int main()
{

}