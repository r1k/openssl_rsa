Example code showing how to public key encrypt, private key decrypt a message using OpenSSL RSA.

Example keys generated using:

openssl genrsa -out private.pem 2048

openssl rsa -in private.pem -outform PEM -pubout -out public.pem

To build:

mkdir build  
cd build  
cmake ../  
make  
