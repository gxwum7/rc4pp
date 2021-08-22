#include <iostream>
#include "RC4.h"

int main()
{
	RC4 enc; // initializing the rc4 class.
	unsigned char* cipher = enc.encrypt((unsigned char*)"this is plain text", (unsigned char*)"password123", 18, 11); // can't encrypt more than 256 bytes because that is how the rc4 works, to encrypt more than 256 bytes with rc4 the .encrypt method needs to be called for every 256 bytes (which is not implemented here).
	// we are using plain text as a key which isn't a good idea, when using passwords the password needs to be hashed before used with an algorithm (which again is not implemented here).
	std::cout << cipher << std::endl; // you shouldn't do that, the cipher can contain unprintable characters.
	unsigned char* plaintext = enc.decrypt(cipher, (unsigned char*)"password123", 18, 11); // decrypt the cipher with the password.
	std::cout << plaintext << std::endl; // here is the decrypted plain text.

	// cleanup: delete the return values.
	delete[] cipher;
	delete[] plaintext;
	return 0;
}
