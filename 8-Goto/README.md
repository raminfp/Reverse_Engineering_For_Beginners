# [+] Lesson 8
***
#### Goto

```bash
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     callq  0x402a63 <__main>
   0x000000000040171d <+13>:    lea    0x38dc(%rip),%rcx        # 0x405000
   0x0000000000401724 <+20>:    callq  0x4034e8 <puts>
   0x0000000000401729 <+25>:    nop
   0x000000000040172a <+26>:    lea    0x38db(%rip),%rcx        # 0x40500c
   0x0000000000401731 <+33>:    callq  0x4034e8 <puts>
   0x0000000000401736 <+38>:    mov    $0x0,%eax
   0x000000000040173b <+43>:    add    $0x20,%rsp
   0x000000000040173f <+47>:    pop    %rbp
   0x0000000000401740 <+48>:    retq
```
Start of main function :
```bash
0x0000000000401718 <+8>:     callq  0x402a63 <__main>
```
Load format string of memory address 0x405000 and print or puts
```bash
     0x000000000040171d <+13>:    lea    0x38dc(%rip),%rcx        # 0x405000
     0x0000000000401724 <+20>:    callq  0x4034e8 <puts>
   
(gdb) x/1s 0x405000
0x405000:       "Hello Ramin"
```
now jump to Goto with ```nop``` and call puts
```bash
	0x000000000040172a <+26>:    lea    0x38db(%rip),%rcx        # 0x40500c
	0x0000000000401731 <+33>:    callq  0x4034e8 <puts>

(gdb) x/1s 0x40500c
0x40500c:       "Good Bye Ramin"

```
