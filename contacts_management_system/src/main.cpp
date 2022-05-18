//
// Created by Shiyi on 2022/5/5.
//

#include <iostream>
#include "contacts_management_system.h"

int main()
{
    // init user input variable
    int user_input = 0;
    // define contacts book struct
    ContactsBook contacts_book;
    // init contacts size
    contacts_book.size = 0;

    while(1)
    {
        // invoke ShowMenu function
        ShowMenu();

        std::cin >> user_input;

        switch(user_input)
        {
            // add contact
            case 1:
                AddContact(&contacts_book);
                break;
            // show contacts
            case 2:
                break;
            // delete contact
            case 3:
                break;
            // search contact
            case 4:
                break;
            // modify contact
            case 5:
                break;
            // empty contacts
            case 6:
                break;
            // quit system
            case 0:
                std::cout << "Welcome to use next time!" << std::endl;
                std::cout << "Press any number or letter key to continue ..." << std::endl;
                char flag;
                std::cin >> flag;
                return 0;
            default:
                break;
        }
    }
}
