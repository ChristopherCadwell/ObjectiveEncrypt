#pragma once
#include "Encryption.h"
#include <string>

class A_Encrypt : public Encryption
{
public:
	static void EncryptionProcess();

private:
	static void PrimeSelection();
	static void KeyGen();
	static int PrimeVerify(long int);
	static void Encrypt();
	static void Decrypt();


};

