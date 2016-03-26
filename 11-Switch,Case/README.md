# [+] Lesson 11
***
#### Switch , Case

```bash
(gdb) disassemble main
Dump of assembler code for function main:
   0x000000000040176a <+0>:     push   %rbp
   0x000000000040176b <+1>:     mov    %rsp,%rbp
   0x000000000040176e <+4>:     sub    $0x20,%rsp
   0x0000000000401772 <+8>:     callq  0x402aa3 <__main>
   0x0000000000401777 <+13>:    mov    $0x1,%ecx
   0x000000000040177c <+18>:    callq  0x401710 <f>
   0x0000000000401781 <+23>:    mov    $0x0,%eax
   0x0000000000401786 <+28>:    add    $0x20,%rsp
   0x000000000040178a <+32>:    pop    %rbp
   0x000000000040178b <+33>:    retq
   0x000000000040178c <+34>:    nop
   0x000000000040178d <+35>:    nop
   0x000000000040178e <+36>:    nop
   0x000000000040178f <+37>:    nop
End of assembler dump.
(gdb) disassemble 0x401710
Dump of assembler code for function f:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    0x10(%rbp),%eax				// Now eax = 1
   0x000000000040171e <+14>:    cmp    $0x1,%eax					// if eax == 1 (case 1: printf ("One\n"); break;)
   0x0000000000401721 <+17>:    je     0x40173a <f+42>				// Jump to 0x000000000040173a
   0x0000000000401723 <+19>:    cmp    $0x2,%eax					// if eax == 2 	(case 2: printf ("Two\n"); break;)
   0x0000000000401726 <+22>:    je     0x401748 <f+56>				// Jump to 0x0000000000401748
   0x0000000000401728 <+24>:    test   %eax,%eax					// Jump if the %eax is zero. (case 0: printf ("Zero\n"); break;)
   0x000000000040172a <+26>:    jne    0x401756 <f+70>				// if not found argument jump to  0x0000000000401756
																	// default: printf ("unknown\n"); break;
   0x000000000040172c <+28>:    lea    0x38cd(%rip),%rcx        # 0x405000
   0x0000000000401733 <+35>:    callq  0x403528 <puts>
   0x0000000000401738 <+40>:    jmp    0x401763 <f+83>
   0x000000000040173a <+42>:    lea    0x38c4(%rip),%rcx        # 0x405005
   0x0000000000401741 <+49>:    callq  0x403528 <puts>
   0x0000000000401746 <+54>:    jmp    0x401763 <f+83>
   0x0000000000401748 <+56>:    lea    0x38ba(%rip),%rcx        # 0x405009
   0x000000000040174f <+63>:    callq  0x403528 <puts>
   0x0000000000401754 <+68>:    jmp    0x401763 <f+83>
   0x0000000000401756 <+70>:    lea    0x38b0(%rip),%rcx        # 0x40500d
   0x000000000040175d <+77>:    callq  0x403528 <puts>
   0x0000000000401762 <+82>:    nop
   0x0000000000401763 <+83>:    nop
   0x0000000000401764 <+84>:    add    $0x20,%rsp
   0x0000000000401768 <+88>:    pop    %rbp
   0x0000000000401769 <+89>:    retq
End of assembler dump.
```
