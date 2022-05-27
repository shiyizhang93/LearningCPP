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


void AddContact(ContactsBook* contacts_book)
{
    if (contacts_book->size == MAX)
    {
        std::cout << "The contacts book is full, please "
                     "delete before add new contacts." << std::endl;
        // use cin to pause console
        std::cout << "Press any number or letter key to continue ..." << std::endl;
        int flag;
        std::cin >> flag;
        // use ANSI escape codes to clear console
        std::cout << "\x1B[2J\x1B[H";
        return;
    }
    else
    {
        std::string name;
        int gender = 0;
        std::string age;
        std::string phone_num;
        std::string addr;

        // get name
        std::cout << "Please enter the name: " << std::endl;
        std::cin.ignore();
        getline(std::cin,name);
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
        std::cin.ignore();
        getline(std::cin, phone_num);
        contacts_book->contacts_array[contacts_book->size].phone_num = phone_num;
        // get address
        std::cout << "Please enter the home address: " << std::endl;
        getline(std::cin, addr);
        contacts_book->contacts_array[contacts_book->size].addr = addr;

        // update contacts book size
        contacts_book->size++;

        // finish notice
        std::cout << "Add successfully!" << std::endl;
        // use cin to pause console
        std::cout << "Press any number or letter key to continue ..." << std::endl;
        int flag;
        std::cin >> flag;
        // use ANSI escape codes to clear console
        std::cout << "\x1B[2J\x1B[H";
    }
}


void ShowContacts(ContactsBook* contacts_book)
{
    if (contacts_book->size == 0)
    {
        std::cout << "The contacts book is empty, please "
                     "add contacts before show contacts." << std::endl;
        // use cin to pause console
        std::cout << "Press any num or letter key to continue ..." << std::endl;
        int flag;
        std::cin >> flag;
        // use ANSI escape codes to clear console
        std::cout << "\x1B[2J\x1B[H";
        return;
    }
    else
    {
        for (int i = 0; i < contacts_book->size; i++)
        {
            std::cout << "Name: " << contacts_book->contacts_array[i].name << "\t";
            std::cout << "Gender: " << (contacts_book->contacts_array[i].gender == 1 ? "Male" : "Female") << "\t";
            std::cout << "Age: " << contacts_book->contacts_array[i].age << "\t\t";
            std::cout << "Phone Number: " << contacts_book->contacts_array[i].phone_num << "\t";
            std::cout << "Home Address: " << contacts_book->contacts_array[i].addr << std::endl;
        }
    }
    // use cin to pause console
    std::cout << "Press any num or letter key to continue ..." << std::endl;
    int flag;
    std::cin >> flag;
    // use ANSI escape codes to clear console
    std::cout << "\x1B[2J\x1B[H";
}


int IsExist(ContactsBook* contacts_book, const std::string& name)
{
    for (int i = 0; i < contacts_book->size; i++)
    {
        if (contacts_book->contacts_array[i].name == name)
        {
            return i;
        }
    }
    return -1;
}


void DeleteContact(ContactsBook* contacts_book)
{
    std::string name;
    int ret;

    std::cout << "Please enter the name of contact you want to delete: " << std::endl;
    std::cin.ignore();
    getline(std::cin,name);
    ret = IsExist(contacts_book, name);
    if (ret != -1)
    {
        for (int i = ret; i < contacts_book->size - 1; i++)
        {
            contacts_book->contacts_array[i] = contacts_book->contacts_array[i+1];
        }
        contacts_book->size--;
        std::cout << "The contact has been deleted." << std::endl;
    }
    else
    {
        std::cout << "No contact matches!" << std::endl;
    }

    // use cin to pause console
    std::cout << "Press any num or letter key to continue ..." << std::endl;
    int flag;
    std::cin >> flag;
    // use ANSI escape codes to clear console
    std::cout << "\x1B[2J\x1B[H";
}