# [+] Lesson 4
***
#### Local Variable 

```
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp					// save the value of rbp (64bit)
   0x0000000000401711 <+1>:     mov    %rsp,%rbp			// rbp now points to the top of the stack  
   0x0000000000401714 <+4>:     sub    $0x30,%rsp			// space allocated on the stack for the local variables (0x30 = 48 bit)
   0x0000000000401718 <+8>:     callq  0x402a63 <__main>    // CALL Main Function
   0x000000000040171d <+13>:    movl   $0x5,-0x4(%rbp)		// a = 5 ;; -0x4(%rbp) = %rbp - 0x4(byte)
   0x0000000000401724 <+20>:    movl   $0x7,-0x8(%rbp)		// b = 7 ;; (%rbp) = address rbp
   0x000000000040172b <+27>:    mov    -0x4(%rbp),%edx      // edx = 5
   0x000000000040172e <+30>:    mov    -0x8(%rbp),%eax		// eax = 7
   0x0000000000401731 <+33>:    add    %edx,%eax			// c = a + b => eax = edx + eax 
   0x0000000000401733 <+35>:    mov    %eax,-0xc(%rbp)	     
   0x0000000000401736 <+38>:    mov    $0x0,%eax
   0x000000000040173b <+43>:    add    $0x30,%rsp
   0x000000000040173f <+47>:    pop    %rbp
   0x0000000000401740 <+48>:    retq
```
More information :

```
:    : 
|  2 | [ebp + 16] (3rd function argument)
|  5 | [ebp + 12] (2nd argument)
| 10 | [ebp + 8]  (1st argument)
| RA | [ebp + 4]  (return address)
| FP | [ebp]      (old ebp value)
|    | [ebp - 4]  (1st local variable)
:    : [ebp - 8] 
:    :
|    | [ebp - X]  (esp - the current stack pointer. The use of push / pop is valid now)

```
Registers : 
```
|__64__|__56__|__48__|__40__|__32__|__24__|__16__|__8___|
|__________________________RAX__________________________|
|xxxxxxxxxxxxxxxxxxxxxxxxxxx|____________EAX____________|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|_____AX______|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|__AH__|__AL__|

```