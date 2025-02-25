/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string sentence;
    
    // Nhập câu từ bàn phím
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);
    
    // Đảo ngược câu
    std::reverse(sentence.begin(), sentence.end());
    
    // In ra câu đã đảo ngược
    std::cout << "Reversed sentence: " << sentence << std::endl;
    
    return 0;
}