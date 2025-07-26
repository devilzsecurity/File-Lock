#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY key;
    unsigned char k[] = "1234567890123456";  // key 16
    unsigned char buf[16];                  // aes 16
    char name[100];

    printf("File: ");
    scanf("%99s", name);

    FILE *f = fopen(name, "rb+"); 
    if (!f) {
        puts("Fail, check the content and bytes");
        return 1;
    }
    AES_set_encrypt_key(k, 128, &key); 

    while (!feof(f)) {
        long pos = ftell(f);                   
        int r = fread(buf, 1, 16, f);          
        if (r == 0) break;

        if (r < 16)
            memset(buf + r, 0, 16 - r);       

        AES_encrypt(buf, buf, &key);           

        fseek(f, pos, SEEK_SET);              
        fwrite(buf, 1, 16, f);                 
    }
    printf("Done... check it's encrypted");

    fclose(f);
    return 0;
}
