#include <vector>
#include <iostream>
#include <string>
#include <string>

using namespace std;

class Encrypt
{
private:
    const std::string private_key{"XZNLWEBGJHQDYVTKFUOMPCIASRxynlwebgjhqdyvtkfuompciasr "};

    std::string _encrypted_str{};

public:
    const std::string public_key{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};

    std::string post_encryption_str{};
    std::string unencrypted_str{};
    std::string decrypted_str{};

    void encrypt();
    void decrypt();
    void fetch_usr_str();
};

void Encrypt::fetch_usr_str()
{
    std::cout << "Unencrypted String: ";
    getline(std::cin, unencrypted_str);
}

void Encrypt::encrypt()
{
    _encrypted_str = unencrypted_str;
    for (size_t i{0}; i < _encrypted_str.length(); ++i)
        if (public_key.find(_encrypted_str[i]) != std::string::npos)
            _encrypted_str[i] = private_key[public_key.find(_encrypted_str[i])];

    post_encryption_str = _encrypted_str;
    std::cout << "String encrypted successfully" << std::endl;
    std::cout << unencrypted_str << " -> " << _encrypted_str << endl;
}

void Encrypt::decrypt()
{
    decrypted_str = _encrypted_str;
    for (size_t i{0}; i < decrypted_str.length(); ++i)
        if (private_key.find(decrypted_str[i]) != std::string::npos)
            decrypted_str[i] = public_key[private_key.find(decrypted_str[i])];

    std::cout << "\nString unencrypted successfully" << std::endl;
    std::cout << post_encryption_str << " -> " << decrypted_str << endl;
}

int main()
{
    Encrypt *str1{new Encrypt};

    str1->fetch_usr_str();
    str1->encrypt();
    str1->decrypt();

    delete str1;

    return 0;
}