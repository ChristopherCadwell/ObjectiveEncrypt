#include "Encryption.h"
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "A_Encrypt.h"


int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j;
char en[50], m[50];
char msg[100];


long int cd(long int);


void A_Encrypt::EncryptionProcess()
{
    //ask for prime inputs
    A_Encrypt::PrimeSelection();

    std::cout << "\nENTER MESSAGE OR STRING TO ENCRYPT\n";
    std::cin.getline(msg, 100); 

    for (i = 0; msg[i] != NULL; i++)
        m[i] = msg[i];
    n = x * y;
    t = (x - 1) * (y - 1);

    A_Encrypt::KeyGen();
    std::cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";

    for (i = 0; i < j - 1; i++)
        std::cout << "\n" << e[i] << "\t" << d[i];

    A_Encrypt::Encrypt();
    A_Encrypt::Decrypt();
}


long int cd(long int a)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % a == 0)
            return(k / a);
    }
}




//encrypt message
void A_Encrypt::Encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);

    //encryption, does math and shifts ascii values based on results
    while (i != len)
    {
         
        pt = m[i];
        pt = pt - 96;
        k = 1;

        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    //display encrypted message
    std::cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
        std::cout << en[i];

    //inherited, overriden command to save file 
    A_Encrypt::SaveMessage(en[i], "rsaSave");
}

//decrypt message
void A_Encrypt::Decrypt()
{
    long int pt, ct, key = d[0], k;

    i = 0;
    //reverse the math from encryption
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    //shift ascii values
    std::cout << "\n\nTHE DECRYPTED MESSAGE IS\n";
    
    for (i = 0; m[i] != -1; i++)
        std::cout << m[i];

    std::cout << std::endl;
}

//get numbers to generate key
void A_Encrypt::PrimeSelection()
{
    std::cout << "\nPlease enter your FIRST Prime Number\n" << std::endl;
    //get input
    std::string inputx;
    getline(std::cin, inputx);
    //convert to int
    x = std::stoi(inputx);

    //checking whether input is prime or not
    flag = A_Encrypt::PrimeVerify(x);
    if (flag == 0)
    {
        std::cout << "\nINVALID INPUT\n";
        exit(0);
    }

    std::cout << "\nEPlease enter your SECOND Prime Number\n";
    //get input
    std::string inputy;
    getline(std::cin, inputy);
    //convert to int
    y = std::stoi(inputy);

    //again, check for prime
    flag = A_Encrypt::PrimeVerify(y);
    if (flag == 0 || x == y)
    {
        std::cout << "\nINVALID INPUT\n";
        exit(0);
    }
}
//generate encryption key
void A_Encrypt::KeyGen()
{
    int k;
    k = 0;
    //math for encryption key, based on 2 selected prime numbers
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        //final check to ensure primes
        flag = PrimeVerify(i);
        if (flag == 1 && i != x && i != y)
        {
            //generate key
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

//take a number (pr) and check if it is prime
int A_Encrypt::PrimeVerify(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
