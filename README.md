# File-Lock
Showcase the encryption method of AES ECB MODE.
# File-Lock
Showcase the encryption method of AES ECB MODE.


ECB mode means:
The data is divided into 16-byte blocks.
Each block is encrypted independently.
There is no IV in this mode :)).
It’s fast but insecure.

Compile:
```gcc aes_encrypt.c -o aes_encrypt -lcrypto```
