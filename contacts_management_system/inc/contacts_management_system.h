//
// Created by Shiyi on 2022/5/5.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#define MAX 1000

#ifndef CONTACTS_MANAGEMENT_SYSTEM_H
#define CONTACTS_MANAGEMENT_SYSTEM_H

// Declare person info struct
struct Contact
{
    std::string name;
    int gender;
    std::string age;
    std::string phone_num;
    std::string addr;
};

// Declare contacts-book info struct member variables
// are contacts array and the current number of contacts
struct ContactsBook
{
    struct Contact contacts_array[MAX];
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

/*
 * Checks the contact if exists in contacts book.
 * Passes "name" in to find the same member "name" of
 * "Contacts" listed in "contacts_book" recursively.
 * Returns the index in case of finding match.
 * Returns -1 if no one matches.
 */
int IsExist(ContactsBook* contacts_book, const std::string& name);

/*
 * Deletes the specific contact search by name from the contacts book.
 * Passes "contacts_book" pointer in to check or delete contact.
 */
void DeleteContact(ContactsBook* contacts_book);

/*
 * Searches the specific contact by name from the contacts book.
 * Passes "contacts_book" pointer in to show the searched contact info.
 */
void SearchContact(ContactsBook* contacts_book);

#endif //CONTACTS_MANAGEMENT_SYSTEM_H
