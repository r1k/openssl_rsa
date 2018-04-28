#include "RsaCrypto.h"

#include <openssl/pem.h>
#include <openssl/err.h>
#include <stdexcept>
#include <vector>

std::string GetErrorMessage()
{
    std::vector<char> err_vec(256, 0);
    
    ERR_load_crypto_strings();
    ERR_error_string(ERR_get_error(), err_vec.data());
    
    std::string err;
    err = err_vec.data();
    return std::move(err);
}

RsaCrypto::RsaCrypto(const char *_key, KeyType _type, int _padding) throw()
    :
    rsa{nullptr},
    bio{nullptr},
    type{_type},
    padding{_padding}
{
    bio = BIO_new_mem_buf(_key, -1);
    if (bio)
    {
        if(type == PUBLIC)
        {
            rsa = PEM_read_bio_RSA_PUBKEY(bio, &rsa, nullptr, nullptr);
        }
        else if (type == PRIVATE)
        {
            rsa = PEM_read_bio_RSAPrivateKey(bio, &rsa, nullptr, nullptr);
        }
        else
        {
            throw std::invalid_argument("Invalid key type");
        }

        if (!rsa)
        {
            throw std::invalid_argument(GetErrorMessage().c_str());
        }
    }
}

RsaCrypto::~RsaCrypto()
{
    if (rsa)
    {
        RSA_free(rsa);
        rsa = nullptr;
    }

    if (bio)
    {
        BIO_free(bio);
        rsa = nullptr;
    }
}

int RsaCrypto::encrypt(const std::vector<uint8_t>& data, std::vector<uint8_t>& encrypted)
{
    encrypted.resize(RSA_size(rsa));
    return RSA_public_encrypt(data.size(), data.data(), encrypted.data(), rsa, padding);
}

int RsaCrypto::decrypt(const std::vector<uint8_t>& enc_data, std::vector<uint8_t>& decrypted)
{
    decrypted.resize(RSA_size(rsa));
    return RSA_private_decrypt(enc_data.size(), enc_data.data(), decrypted.data(), rsa, padding);
}
