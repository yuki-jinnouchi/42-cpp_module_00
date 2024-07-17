/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:32:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/17 20:45:25 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// My coding style is based in C++ Coding Standard by Todd Hoff:
// http://maultech.com/chrislott/resources/cstyle/CppCodingStandard.html

#include <iostream>
#include <string>

using namespace std;

string to_upper(string str)
{
    int     i;
    int     strlen;

    i = 0;
    strlen = str.length();
    while (i < strlen)
    {
        str[i] = toupper(str[i]);
        i++;
    }
    return (str);
}

void megaphone(int argc, char **argv)
{
    int     i;
    string  str;

    i = 1;
    while (i < argc)
    {
        str = argv[i];
        str = to_upper(str);
        cout << str;
        i++;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        megaphone(argc, argv);
    } else {
	    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    }
    return (0);
}
