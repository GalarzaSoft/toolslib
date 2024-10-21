// Experiments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "StringTokenizer.h"

using namespace std;

int main()
{
    string str{ "thisabcisabcaabcstring" };
    string str2{ "this is a string" };
    string_view view{ str };

    cout << str << "\n" << view << "\n";

    str[0] = 'A';
    str[1] = 'A';
    str[2] = 'A';

    cout << "\n" << str << "\n" << view << "\n";
    StringTokenizer tokenizer(str, "abc");

    StringTokenizer tokenizer2(str2);

    while (auto token = tokenizer.nextToken()) {
        cout << *token << "\n";
    }

    while (auto token = tokenizer2.nextToken()) {
        cout << *token << "\n";
    }
#ifdef __cpp_lib_generator
    cout << "Testing token generation: \n";


    for (auto t : tokenizer2.Tokens()) {
        cout << t << "\n";
    }

    cout << "Testing static token generation: \n";


    for (auto t : StringTokenizer::GenerateTokens (str)) {
        cout << t << "\n";
    }
#endif
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
