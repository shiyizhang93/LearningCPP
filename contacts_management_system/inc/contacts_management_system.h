//
// Created by Shiyi on 2022/5/5.
//

#include <iostream>
#include <string>

#define MAX 1000

#ifndef CONTACTS_MANAGEMENT_SYSTEM_H
#define CONTACTS_MANAGEMENT_SYSTEM_H

// declare person info struct
struct Person
{
    std::string name;
    int gender;
    std::string age;
    std::string phone_num;
    std::string addr;
};

// declare contacts-book info struct member variables
// are contacts array and the current number of contacts
struct ContactsBook
{
    struct Person contacts_array[MAX];
    int size;
};

/*
 * Gives user some operation hints. It offers 5 different operations.
 */
void ShowMenu();

/*
 * Achieves adding contact info to contacts books struct.
 * Passes "contacts_book" pointer in to modify contacts info.
 */
void AddContact(ContactsBook* contacts_book);

/*
 * Achieves showing contacts info in contacts books struct.
 * Passes "contacts_book" pointer in to check contacts info.
 */
void ShowContacts(ContactsBook* contacts_book);

#endif //CONTACTS_MANAGEMENT_SYSTEM_H
