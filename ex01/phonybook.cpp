/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonybook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:11:33 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/12 17:12:05 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::setw;
using std::string;

PhoneBook::PhoneBook() {
    nextIndex = 0;
}

int main() {
    PhoneBook phoneBook;
    string command;

    while (true) {
        cout << "Enter a command: ";
        getline(cin, command);
        if (cin.eof()) {
            cout << endl;
            break;
        }
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid command. Use ADD, SEARCH, or EXIT." << endl;
        }
    }
    return 0;
}

void PhoneBook::addContact() {

    Contact contact;
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkestSecret;

    cout << "Enter first name: ";
    getline(cin, firstName);
    cout << "Enter last name: ";
    getline(cin, lastName);
    cout << "Enter nickname: ";
    getline(cin, nickname);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter darkest secret: ";
    getline(cin, darkestSecret);
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        cout << "All fields are required." << endl;
        return;
    }
    for (char c : firstName) {
        if (!isalpha(c)) {
            cout << "First name must be alphabetic." << endl;
            return;
        }
    }
    for (char c : lastName) {
        if (!isalpha(c)) {
            cout << "Last name must be alphabetic." << endl;
            return;
        }
    }
    for (char c : phoneNumber) {
        if (!(isdigit(c) || c == ' ' || c == '-' || c == '(' || c == ')' || c == '+' || c == '.' || c == '/')) {
            cout << "Phone number must be numeric." << endl;
            return;
        }
    }
    contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    contacts[nextIndex] = contact;
    nextIndex++;
    nextIndex %= 8;
}

void PhoneBook::searchContact() const {
    int index;
    string indexString;

    cout << endl;
    cout << endl;
    cout << setw(10) << "Index" << "|";
    cout << setw(10) << "First Name" << "|";
    cout << setw(10) << "Last Name" << "|";
    cout << setw(10) << "Nickname" << "|" << endl;
    cout << "_____________________________________________" << endl;
    for (int i = 0; i < 8; i++) {
        cout << setw(10) << i << "|";
        displayContact(i);
    }
    cout << "_____________________________________________" << endl;
    cout << endl;
    cout << "Enter index: ";
    getline(cin, indexString);
    try {
        index = stoi(indexString);
    } catch (const std::exception& e) {
        cout << "Invalid index." << endl;
        return;
    }
    if (index >= 0 && index < 8) {
        displayFullContact(index);
    } else {
        cout << "I am a very small phonebook with limited memory.\n 8 entries fill me up." << endl;
    }
}

string formatString(const string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return string(width - str.length(), ' ') + str;
    }
}

void PhoneBook::displayContact(int index) const {
    cout << formatString(contacts[index].getFirstName(), 10) << "|";
    cout << formatString(contacts[index].getLastName(), 10) << "|";
    cout << formatString(contacts[index].getNickname(), 10) << "|" << endl;
}

void PhoneBook::displayFullContact(int index) const {
    cout << "First Name: " << contacts[index].getFirstName() << endl;
    cout << "Last Name: " << contacts[index].getLastName() << endl;
    cout << "Nickname: " << contacts[index].getNickname() << endl;
    cout << "Phone Number: " << contacts[index].getPhoneNumber() << endl;
    cout << "Darkest Secret: " << "\033[8m" <<contacts[index].getDarkestSecret() << "\033[0m" << endl;
}
