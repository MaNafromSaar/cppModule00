/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:45:19 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/12 00:29:24 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	
	public:
		void setContact(std::string f, std::string l, std::string n, std::string p, std::string d) {
			firstName = f;
			lastName = l;
			nickname = n;
			phoneNumber = p;
			darkestSecret = d;
		}
	
		std::string getFirstName() { return firstName; }
		std::string getLastName() { return lastName; }
		std::string getNickname() { return nickname; }
		std::string getPhoneNumber() { return phoneNumber; }
		std::string getDarkestSecret() { return darkestSecret; }
};

class PhoneBook {
	private:
		Contact contacts[8];
		int nextIndex;
	
	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
		void displayContact(int index) const;
};
	
#endif