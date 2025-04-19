#pragma once

#define MAX 100

typedef struct {
    char name[30];
    char phone[15];
} Contact;

typedef struct {
    Contact contacts[MAX];
    int size;
} PhoneBook;

void addContact(PhoneBook* pb, char name[], char phone[]);
void deleteContact(PhoneBook* pb, char name[]);
void searchContact(PhoneBook* pb, char name[]);
void displayContacts(PhoneBook* pb);

void menuAddContact(PhoneBook* pb);
void menuDeleteContact(PhoneBook* pb);
void menuSearchContact(PhoneBook* pb);
void menuDisplayContacts(PhoneBook* pb);
