#include "RC4.h"


RC4::RC4()
{}

RC4::~RC4()
{}

unsigned char* RC4::encrypt(unsigned char* bytes, unsigned char* key, const int bytesSize, const int keySize)
{
	unsigned char S[256];
	unsigned char T[256];
	for (int i = 0; i < 256; i++)
	{
		S[i] = i;
	}
	int i = 0;
	unsigned char* eBytes = new unsigned char[bytesSize + 1]; // make sure to delete the return value

	__ksa(key, keySize, S, T);
	unsigned char* generatedKey = __prga(bytes, bytesSize, S);
	for (int i = 0; i < bytesSize; i++)
	{
		eBytes[i] = (generatedKey[i] ^ bytes[i]);
	}
	eBytes[bytesSize] = '\0';
	return eBytes;
}

unsigned char* RC4::decrypt(unsigned char* eBytes, unsigned char* key, const int eBytesSize, const int keySize)
{
	unsigned char S[256];
	unsigned char T[256];
	for (int i = 0; i < 256; i++)
	{
		S[i] = i;
	}
	unsigned char* bytes = new unsigned char[eBytesSize + 1];  // make sure to delete the return value
	__ksa(key, keySize, S, T);
	unsigned char* generatedKey = __prga(bytes, eBytesSize, S);
	for (int i = 0; i < eBytesSize; i++)
	{
		bytes[i] = (generatedKey[i] ^ eBytes[i]);
	}
	bytes[eBytesSize] = '\0';
	return bytes;
}

void RC4::__swap(unsigned char* S, unsigned char* T, const int i, const int j)
{
	unsigned char temp = S[i];
	S[i] = T[j];
	T[j] = temp;
}

void RC4::__ksa(unsigned char* key, const int keySize, unsigned char* S, unsigned char* T)
{
	for (int i = 0; i < 256; i++)
	{
		T[i] = key[i % keySize];
	}

	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		j = (j + S[i] + T[i]) % 256;
		__swap(S, T, i, j);
	}
}

unsigned char* RC4::__prga(unsigned char* bytes, const int bytesSize, unsigned char* S)
{
	unsigned char* generatedKey = new unsigned char[bytesSize];
	int i = 0, j = 0;
	unsigned char t, k;
	for (int ii = 0; ii < bytesSize; ii++)
	{
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		__swap(S, S, i, j);
		t = (S[i] + S[j]) % 256;
		k = S[t];
		generatedKey[ii] = k;
	}
	return generatedKey;
}
