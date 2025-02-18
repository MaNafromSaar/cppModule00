/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:07:37 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/18 15:19:33 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv) {
    if (argc == 1) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    } else if (argc == 2 && std::strcmp(argv[1], "quiet") == 0) {
        cout << "https://www.youtube.com/watch?v=gLF-_Z8TK1k" << endl;
    } else {
        for (int i = 1; i < argc; i++) {
            string arg(argv[i]);
            for (unsigned int j = 0; j < arg.length(); j++) {
                cout << static_cast<char>(toupper(arg[j]));
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
