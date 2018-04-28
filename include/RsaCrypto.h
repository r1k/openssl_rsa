#ifndef RSA_CRYPTO
#define RSA_CRYPTO

#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <stdint.h>
#include <vector>

class RsaCrypto
{
public:

    enum KeyType {
        PUBLIC,
        PRIVATE
    };

    // Constructor will throw std::invalid_argument if key is invalid
    RsaCrypto(const char *_key, KeyType _type, int _padding=RSA_PKCS1_OAEP_PADDING) throw();
    virtual ~RsaCrypto();

    int encrypt(const std::vector<uint8_t>& data, std::vector<uint8_t>& encrypted);
    int decrypt(const std::vector<uint8_t>& enc_data, std::vector<uint8_t>& decrypted);

private:

    RsaCrypto(const RsaCrypto&) = delete;
    RsaCrypto(const RsaCrypto&&) = delete;

    RsaCrypto& operator=(const RsaCrypto&) = delete;
    RsaCrypto& operator=(const RsaCrypto&&) = delete;

    RSA *rsa;
    BIO *bio;

    KeyType type;
    int padding;
};

#endif

