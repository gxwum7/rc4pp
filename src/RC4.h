#pragma once

class RC4
{
public:
	RC4();
	~RC4();
	unsigned char* encrypt(unsigned char* bytes, unsigned char* key, const int bytesSize, const int keySize);
	unsigned char* decrypt(unsigned char* eBytes, unsigned char* key, const int eBytesSize, const int keySize);
private:
	void __swap(unsigned char* S, unsigned char* T, const int i, const int j);
	void __ksa(unsigned char* key, const int keySize, unsigned char* S, unsigned char* T);
	unsigned char* __prga(unsigned char* bytes, const int bytesSize, unsigned char* S);
};
