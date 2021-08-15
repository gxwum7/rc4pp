#include <iostream>
#include "../RC4Enc.h"

int main()
{
	const char* cipher = RC4Enc::encrypt("this is plain text, 124375 test", "encryptedPass12446", 32, 19);
	std::cout << cipher << std::endl; // you shouldn't do it, the cipher can contain unprintable characters.
	const char* plaintext = RC4Enc::decrypt(cipher, "encryptedPass12446", 32, 19);
	std::cout << plaintext << std::endl;
	// cleanup: make sure to delete the return values
	delete[] cipher;
	delete[] plaintext;
	return 0;
}
