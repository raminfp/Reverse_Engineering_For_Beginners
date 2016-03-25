# [+] Lesson 6
***
#### Functions

```bash

(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401732 <+0>:     push   %rbp
   0x0000000000401733 <+1>:     mov    %rsp,%rbp
   0x0000000000401736 <+4>:     sub    $0x20,%rsp
   0x000000000040173a <+8>:     callq  0x402a73 <__main>
   0x000000000040173f <+13>:    mov    $0x4,%edx			// a = 4
   0x0000000000401744 <+18>:    mov    $0x2,%ecx			// b = 2
   0x0000000000401749 <+23>:    callq  0x401710 <func>      // func(a,b)
   0x000000000040174e <+28>:    mov    $0x0,%eax			// eax = 0
   0x0000000000401753 <+33>:    add    $0x20,%rsp			// add to stack 
   0x0000000000401757 <+37>:    pop    %rbp					// pop :)
   0x0000000000401758 <+38>:    retq
   0x0000000000401759 <+39>:    nop
   0x000000000040175a <+40>:    nop
   0x000000000040175b <+41>:    nop
   0x000000000040175c <+42>:    nop
   0x000000000040175d <+43>:    nop
   0x000000000040175e <+44>:    nop
   0x000000000040175f <+45>:    nop
End of assembler dump.
```
### How to CALL other function?
```bash
 0x0000000000401749 <+23>:    callq  0x401710 <func>
```
You see call function address "0x401710" Now let's go see to disass func
```bash
(gdb) disassemble func
Dump of assembler code for function func:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x10,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)		// a = 2
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)		// b = 4
   0x000000000040171e <+14>:    mov    0x10(%rbp),%edx	
   0x0000000000401721 <+17>:    mov    0x18(%rbp),%eax
   0x0000000000401724 <+20>:    add    %edx,%eax			// a + b
   0x0000000000401726 <+22>:    mov    %eax,-0x4(%rbp)		// c local value variable
   0x0000000000401729 <+25>:    mov    -0x4(%rbp),%eax
   0x000000000040172c <+28>:    add    $0x10,%rsp
   0x0000000000401730 <+32>:    pop    %rbp
   0x0000000000401731 <+33>:    retq
End of assembler dump.
```