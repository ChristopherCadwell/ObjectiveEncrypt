#include "C_Decrypt.h"
#include <iostream>
#include <string>



int di;
int dx;
char dstr[100];
int dshift;

void C_Decrypt::Caesar()
{

    std::cout << "Enter a number from 1-25\t";

    //store choice in string
    std::string sshift;
    getline(std::cin, sshift);
    //convert to int
    dshift = std::stoi(sshift);



    std::cout << "\nPlease choose following options:\n";
    std::cout << "1 = Input something to decrypt.\n";
    std::cout << "2 = Load txt file for decryption.\n";

    //get input
    std::string strx;
    getline(std::cin, strx);

    //convert string to int
    dx = std::stoi(strx);

    //using switch case statements
    switch (dx)
    {
        //first case for encrypting a string
    case 1:
        std::cout << "\nEnter message for Decryption" << std::endl;
        //get message for encryption
        std::cin.getline(dstr, 100);
        //encrypt message
        C_Decrypt::Decrypt();
        //display encrypted, then save to file
        std::cout << "\nDecrypted string: " << dstr << std::endl;
        C_Decrypt::SaveMessage(dstr);
        std::cout << "\nsaved to file." << std::endl;

        break;

        //second case Load file for encryption
    case 2:
        
        C_Decrypt::Decrypt();

    default:
        std::cout << "\nInvalid Input !!!\n";
    }
    return;
}

void C_Decrypt::Decrypt()
{
    for (di = 0; (di < 100 && dstr[di] != '\0'); di++)
        //subtract shift from ascii values
        dstr[di] = dstr[di] - dshift;

    std::cout << "\nDecrypted string: " << dstr << std::endl;

}
