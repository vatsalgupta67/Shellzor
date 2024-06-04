
## XOR shellcode framework - Windows, Linux


### ***Tool for encode/decode xor & later executing it on target via .bin File***

# **Made With :heart: in 	:india:!!**


## Kindly follow instructions on [How To Use](https://github.com/vatsalgupta67/Shellzor/blob/main/README.md#warning-how-to-use)

![red](https://github.com/vatsalgupta67/Shellzor/assets/71017420/39bfd156-1d9f-469d-9f7e-e56641375087)

***:dart:	Some kind of detection can be evaded by this as we prefered .bin shellcode format. Which is more evasive in nature, You can achieve some kind of signature evasion easily than Exe or Dll files. If your primary focus is to evade then, it all depends mostly on your shellcode rather than the binary itself.***

> [!WARNING]
> ## **The user is only be responsible for the use, There's no liability of the Owner.**

# Index

* [Demonstration]()
* [How To Use](https://github.com/vatsalgupta67/Shellzor/blob/main/README.md#warning-how-to-use)

### Credit of this image goes to respective creator - 


![xor](https://github.com/vatsalgupta67/Shellzor/assets/71017420/61ff7719-80f9-42c9-808b-90349da7e835)

* [article on Xor](https://bluegoatcyber.com/blog/how-is-xor-used-in-encryption/#:~:text=The%20XOR%20Encryption%20Process&text=It%20combines%20plaintext%20with%20a,sensitive%20information%20from%20unauthorized%20access.)


## *Demonstration Images*

![obfucsator-kali](https://github.com/vatsalgupta67/Shellzor/assets/71017420/f3c132fd-e5f2-431f-a6e3-d18b84352af2)

![linux-executor](https://github.com/vatsalgupta67/Shellzor/assets/71017420/d3df5298-a27b-4f30-bd34-344b51260c22)




![windows_shellcode_executor](https://github.com/vatsalgupta67/Shellzor/assets/71017420/9afb7f58-e0df-4aa0-9174-9398f2cedf4c)



![kali-windows-meter](https://github.com/vatsalgupta67/Shellzor/assets/71017420/bba8edf8-517b-47f6-a145-217adc125317)



  

## :warning: How To Use

1. Generate your shellcode or custom one
2. save it or make it in Raw format shellcode or basically hexadecimal. If using metasploit the, you can do it my "-f raw" or  if you're not sure how to do it, then use command with example - " echo -ne <hexxadecimal shellcode> > shellcode.bin"
   
3. Use obfucsator tool, provide .bin file & give hexadecimal key to decode/encode
4. Copy and save obfuscated shellcode to .bin file by the same "echo" command, which you have genarated by "obfuscator script."
5. Transfer obfuscated shellcode file to target or as you want.
6. copy windows_executor/linux_executor binary to target machine.
7. Now, to execute shellcode - use executor script with the obfuscated shellcode file & provide same key what you gave to obfuscate it.
8. Enjoy the shell :crossed_fingers:	
   
> [!NOTE]
> Key should be in VALID hexadecimal format as yoou can give any or simply demonstration is provided above.
> Hex keys are much better & it's more easy to give unique characters in argument as Obfuscation/Deobfuscation key.
