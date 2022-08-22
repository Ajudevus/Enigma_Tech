#include <iostream>
#include <sstream>
#include <string>

#include <openssl/sha.h>

void sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        int val=(int)hash[i];
        std::stringstream ss;
        ss<<std::hex<<val;
        std::string res = ss.str();
        std::cout<<res;
    }
    std::cout<<std::endl;

}

int main() {
    sha256("Hello World");
    return 0;
}
