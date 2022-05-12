//
// Created by Shiyi on 2022/4/29.
//

#include <iostream>
#include "contacts_management_system.h"

/*
 * uses std::cout to show a function menu on console.
 */
void ShowMenu()
{
    std::cout << "**************************" << std::endl;
    std::cout << "*** 1. Add contact *******" << std::endl;
    std::cout << "*** 2. Show contacts *****" << std::endl;
    std::cout << "*** 3. Delete contact ****" << std::endl;
    std::cout << "*** 4. Search contact ****" << std::endl;
    std::cout << "*** 5. Modify contact ****" << std::endl;
    std::cout << "*** 6. Empty contacts ****" << std::endl;
    std::cout << "*** 0. Quit system *******" << std::endl;
    std::cout << "**************************" << std::endl;
}


void AddPerson(ContactsBook* contacts_book)
{
    if (contacts_book->size == MAX)
    {
        std::cout << "The contacts book is full, please "
                     "delete before add new contacts." << std::endl;
        return;
    }
    else
    {
        std::string name;
        int gender = 0;
        int age = 0;
        std::string phone_num;
        std::string addr;
        // get name
        std::cout << "Please enter the name: " << std::endl;
        std::cin >> name;
        contacts_book->contacts_array[contacts_book->size].name = name;
        // get gender
        std::cout << "Please enter the gender: " << std::endl;
        std::cout << "1 -- Male" << std::endl;
        std::cout << "2 -- Female" << std::endl;
        while (true)
        {
            std::cin >> gender;
            if (gender == 1 || gender == 2)
            {
                contacts_book->contacts_array[contacts_book->size].gender = gender;
                break;
            }
            else
            {
                std::cout << "Please enter the correct gender indicator!" << std::endl;
            }
        }
        // get age
        std::cout << "Please enter the age: " << std::endl;
        std::cin >> age;
        contacts_book->contacts_array[contacts_book->size].age = age;
        // get phone number
        std::cout << "Please enter the phone number: " << std::endl;
        std::cin >> phone_num;
        contacts_book->contacts_array[contacts_book->size].phone_num = phone_num;
        // get address
        std::cout << "Please enter the home address: " << std::endl;
        std::cin >> addr;
        contacts_book->contacts_array[contacts_book->size].phone_num = addr;

        // update contacts book size
        contacts_book->size++;

        // finish notice
        std::cout << "Add successfully!" << std::endl;
        std::cout << "Press any key to continue" << std::endl;
        int flag = std::cin.get();
        std::system("clear");
    }
}