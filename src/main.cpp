#include <iostream>

#include "RsaCrypto.h"

const char *PUBLIC_KEY = 
"-----BEGIN PUBLIC KEY-----\n"
"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA5dI3UpLx6bE1Z+EtFwoD\n"
"SLQyUo0xpLxB5ND6t1VYv93pF6lSejpcPZzno6c9YsW7q2mg2VPafVoKZrsKmUf1\n"
"IbGVqh6FK2E1KzIagXAtxwDOiuJUl9OkaL4EAXjX7eEN1WNHZ99cE24xhxl3coR0\n"
"uRl5imOpnICR1k1mfOFONDlwJb61Cah4uS5FvzfPcVdaZdpIptQsJye/NjQ7EyW6\n"
"R1zLo5c7g+KNnPbANiCcrIUpXl3xFg+8LzSAzBGgw6AZlB1FvBrob69oFgacc5s3\n"
"RHV7oejSs2YZIEWtzWOQyEMyDWiNcSUkFHZIhUWBcCF7Hq3i0hMu8hAVo09uD7qC\n"
"UQIDAQAB\n"
"-----END PUBLIC KEY-----";

const char *PRIVATE_KEY = 
"-----BEGIN RSA PRIVATE KEY-----\n"
"MIIEpAIBAAKCAQEA5dI3UpLx6bE1Z+EtFwoDSLQyUo0xpLxB5ND6t1VYv93pF6lS\n"
"ejpcPZzno6c9YsW7q2mg2VPafVoKZrsKmUf1IbGVqh6FK2E1KzIagXAtxwDOiuJU\n"
"l9OkaL4EAXjX7eEN1WNHZ99cE24xhxl3coR0uRl5imOpnICR1k1mfOFONDlwJb61\n"
"Cah4uS5FvzfPcVdaZdpIptQsJye/NjQ7EyW6R1zLo5c7g+KNnPbANiCcrIUpXl3x\n"
"Fg+8LzSAzBGgw6AZlB1FvBrob69oFgacc5s3RHV7oejSs2YZIEWtzWOQyEMyDWiN\n"
"cSUkFHZIhUWBcCF7Hq3i0hMu8hAVo09uD7qCUQIDAQABAoIBAQCDEWB7t1I/9NCA\n"
"betJOGynCh2o9t1ZFgR+erCB3iq/Qc+truNa0e3JNbLlontf2WUuXQ9e4nO5CaDk\n"
"9ccVo/QpQx4X51ALbWTlPa3gJBn3ZH5mtq2H6SvakIO4UzLSd4dsKzKOCtR4QF/+\n"
"rIdyyBfJeL3YLv6MQsbpcTsB/XycSxDe61u/7tAGvbm1ZLWAXoTbU7zUmXtQvNfG\n"
"GK25yqMw/CwlXxGLKZmr4zDLQ3GdICGU0ELO7B7K5olanZ3bM7CydKCqhGCU9gtg\n"
"8Z11h1lszanfB9s/ajHoalVnzrhrdeuKU+R39Db4HltKCp4yA9Ii6DZ9KX1OB8IZ\n"
"GChG1wABAoGBAPoKs69qTtJaHuMonJQDbx6QHqGm4esUpdMIVnaZEUdnmEgD1RMH\n"
"eDisOE1VPEFD9lSxKjfla7GuVTd7cxbSGZ3/GRGQgyAPcEyEgmzBs8r9R3P7MwnZ\n"
"0pDXuO/B3s5hqUSyLpgKT+kJvGNrBFbPhLWYr62q5cuyiprMn7za2rbBAoGBAOtM\n"
"Ki6IC4Nf17X21h3ONVk/NVmSpI5fRgdWTTGAROhiLtXOJborWkx25wT4pNEaaLPg\n"
"Jfj59pPFOCJLF5Oi8HvCWY1hsgIQv8NNJ0QHkddRbsBU1dLh3idHesjhMF/PfUbH\n"
"gRcS8BZazJx/QVRLVpstC59q50nhrbK5IvhyP7+RAoGAY6HUC3euxL7IQ/ewvIHJ\n"
"y0HeEseuib+Ge9p8qXFAo1UyJq/wPU7ipqJpJNdr1Q3Bn+mgSvmNuhUfO6ZjK5q4\n"
"Pm6hjJAqz6GXO8YpOjDM9XuK9zoHEkvLTY/HzzFPGKlti0P8sPSa9t68RFkmN3kl\n"
"Bj868VaBjnMsK5aRp+0E7YECgYBXO8iTsbpa/WhyvM2LBU1ABjAYQkahxe6nf7Zk\n"
"uMJTSTtF5wSTrcjvelGRxUENiPXyYhKR6NIi3MY/6IkYIht4NoiO4v5kx6LgnDUH\n"
"gqruIfGmeo0/fp+m/lgmK16M1tcCK6rPTCUYlJcxGfi1cKzuINgjRTX0bSfBj+PI\n"
"Kks6EQKBgQCJslAyTtf6IMS40nDIRJ0jQzkhlF4c4YRLzj2afIoocm8uEto27u6J\n"
"olo7LO85rTtdfT1bRSvF7zMNPt79kVKUcHesKNShrQzyPTWsKwP+8oglhT/cj0cs\n"
"bfjckZba4wJfSuyBj5FMgjSglIbGw/3ccfg5VPB26357Vu+xV2PF6A==\n"
"-----END RSA PRIVATE KEY-----";


int main(int argc, char *argv[])
{
    const std::string clearMessage = "Hello World!";
    
    RsaCrypto pubEnc(PUBLIC_KEY, RsaCrypto::PUBLIC);

    std::vector<uint8_t> messageBuffer(clearMessage.length()+1, 0);
    std::copy(begin(clearMessage), end(clearMessage), begin(messageBuffer));

    std::vector<uint8_t> encryptedBuffer;
    pubEnc.encrypt(messageBuffer, encryptedBuffer);

    RsaCrypto privKey(PRIVATE_KEY, RsaCrypto::PRIVATE);

    std::vector<uint8_t> decryptedMessageBuffer;
    privKey.decrypt(encryptedBuffer, decryptedMessageBuffer);

    std::string decryptedString = reinterpret_cast<char *>(decryptedMessageBuffer.data());

    std::cout << "Original message : " << clearMessage << std::endl;
    std::cout << "Decrypted message: " << decryptedString << std::endl;

    return 0;
}
