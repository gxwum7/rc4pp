# RC4 Encryption implementation in C++
this is a RC4 implementation in C++, this repository is meant for learning.    
i'm not an expert of the subject so don't expect this to be perfect code.
# Important notes
1. Don't try to print the cipher after encrypting because it can contain unprintable characters.
2. Make sure to delete the return value of the function when you finish using it.
(feel free to change the char* to vector or unique_ptr but don't return the pointer because the memory will be deleted automatically).