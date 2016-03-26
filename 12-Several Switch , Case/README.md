# [+] Lesson 12
***
#### Several Switch , Case 

```bash
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401791 <+0>:     push   %rbp
   0x0000000000401792 <+1>:     mov    %rsp,%rbp
   0x0000000000401795 <+4>:     sub    $0x20,%rsp
   0x0000000000401799 <+8>:     callq  0x402ad3 <__main>
   0x000000000040179e <+13>:    mov    $0x4,%ecx            // f(4)
   0x00000000004017a3 <+18>:    callq  0x401710 <f>         // call f(4)
   0x00000000004017a8 <+23>:    mov    $0x0,%eax
   0x00000000004017ad <+28>:    add    $0x20,%rsp
   0x00000000004017b1 <+32>:    pop    %rbp
   0x00000000004017b2 <+33>:    retq
   0x00000000004017b3 <+34>:    nop
   0x00000000004017b4 <+35>:    nop
   0x00000000004017b5 <+36>:    nop
   0x00000000004017b6 <+37>:    nop
   0x00000000004017b7 <+38>:    nop
   0x00000000004017b8 <+39>:    nop
   0x00000000004017b9 <+40>:    nop
   0x00000000004017ba <+41>:    nop
   0x00000000004017bb <+42>:    nop
   0x00000000004017bc <+43>:    nop
   0x00000000004017bd <+44>:    nop
   0x00000000004017be <+45>:    nop
   0x00000000004017bf <+46>:    nop
End of assembler dump.
(gdb) disassemble 0x401710
Dump of assembler code for function f:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)          // move 4 to 0x10(%rbp)
   0x000000000040171b <+11>:    cmpl   $0x16,0x10(%rbp)         // if 4 == 22
   0x000000000040171f <+15>:    ja     0x40177d <f+109>         // jump and message : 0x405020 "default"
   0x0000000000401721 <+17>:    mov    0x10(%rbp),%eax          // move 4 to eax 
   0x0000000000401724 <+20>:    lea    0x0(,%rax,4),%rdx        // loading
   0x000000000040172c <+28>:    lea    0x38f5(%rip),%rax        # 0x405028 
   0x0000000000401733 <+35>:    mov    (%rdx,%rax,1),%eax
   0x0000000000401736 <+38>:    movslq %eax,%rdx
   0x0000000000401739 <+41>:    lea    0x38e8(%rip),%rax        # 0x405028
   0x0000000000401740 <+48>:    add    %rdx,%rax
   0x0000000000401743 <+51>:    jmpq   *%rax
   0x0000000000401745 <+53>:    lea    0x38b4(%rip),%rcx        # 0x405000  // printf() message : "1, 2, 7, 10"
   0x000000000040174c <+60>:    callq  0x403558 <puts>
   0x0000000000401751 <+65>:    jmp    0x40178a <f+122>
   0x0000000000401753 <+67>:    lea    0x38b2(%rip),%rcx        # 0x40500c  // printf() message : "3, 4, 5"
   0x000000000040175a <+74>:    callq  0x403558 <puts>
   0x000000000040175f <+79>:    jmp    0x40178a <f+122>
   0x0000000000401761 <+81>:    lea    0x38ac(%rip),%rcx        # 0x405014  // printf() message : "8, 9, 21"
   0x0000000000401768 <+88>:    callq  0x403558 <puts>
   0x000000000040176d <+93>:    jmp    0x40178a <f+122>
   0x000000000040176f <+95>:    lea    0x38a7(%rip),%rcx        # 0x40501d  // printf() message : "22"
   0x0000000000401776 <+102>:   callq  0x403558 <puts>
   0x000000000040177b <+107>:   jmp    0x40178a <f+122>
   0x000000000040177d <+109>:   lea    0x389c(%rip),%rcx        # 0x405020  // printf() message : "default"
   0x0000000000401784 <+116>:   callq  0x403558 <puts>
   0x0000000000401789 <+121>:   nop
   0x000000000040178a <+122>:   nop
   0x000000000040178b <+123>:   add    $0x20,%rsp
   0x000000000040178f <+127>:   pop    %rbp
   0x0000000000401790 <+128>:   retq
End of assembler dump.
(gdb)

```