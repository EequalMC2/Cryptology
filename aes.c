#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void display(const unsigned char* buff, size_t size)
{
	int i ;

	for(i = 0; i < size; ++i )
		printf("%X",(const unsigned int )buff[i]);
	printf("\n--------\n");
		
}



int main(int argc, char* argv[])
{
    AES_KEY aesKey_ = {0} ;
    unsigned char userKey_[16]  = {0000000000000000};
    unsigned char in_[16] 		= {'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',};
    unsigned char out_[16] 		= {0};
    
    
	display(in_,16);
    
    AES_set_encrypt_key(userKey_, 128, &aesKey_);
    AES_encrypt(in_, out_, &aesKey_);

	display(out_, 16);	
    memset(in_,0,16);
	display(in_, 16);
	AES_set_decrypt_key(userKey_, 128, &aesKey_);
    AES_decrypt(out_, in_,&aesKey_);
 
	display(in_,16);

    return 0;
}

