#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void obfuscate_shellcode(unsigned char * code, size_t length, unsigned char obf_key){

    for(size_t i = 0; i < length; i++){

        code[i] = code[i] ^ obf_key;
        
    }

}





int main(int argc, char *argv[]){

    if(argc < 3){

        fprintf(stderr,"Usage: %s <.bin shellcode file> <Valid hexadecimal key format like 0x2f>\n",argv[0]);
        
        return 1;

        }



    unsigned char obf_key = (unsigned char)strtoul(argv[2], NULL, 0);



    FILE * file = fopen(argv[1],"rb");


    if (file == NULL){

        perror("[+] Error opening file");
        return 1;


    }


    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file,0,SEEK_SET);


    unsigned char * original_shellcode = (unsigned char *)malloc(length);


    if (original_shellcode == NULL){

        perror("[+] Error Allocating Memory");

        fclose(file);

        return 1;

    }
    

    fread(original_shellcode,1, length, file);
    fclose(file);



    printf("\n");
    
    

obfuscate_shellcode(original_shellcode, length, obf_key);

    printf("Obfuscated Shellcode:\n\n");

        for(size_t i = 0; i < length; i++){

            printf("\\x%02x", original_shellcode[i]);



        }



    printf("\n");

    
   
    free(original_shellcode);
    

    printf("\n\n");


    return 0;

    
}