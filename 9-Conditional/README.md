# [+] Lesson 8
***
#### Goto

```bash

(gdb) disassemble main
Dump of assembler code for function main:
   0x000000000040175f <+0>:     push   %rbp
   0x0000000000401760 <+1>:     mov    %rsp,%rbp
   0x0000000000401763 <+4>:     sub    $0x20,%rsp
   0x0000000000401767 <+8>:     callq  0x402aa3 <__main>	//Call main	
   0x000000000040176c <+13>:    mov    $0x4,%edx			// f1(3,4)
   0x0000000000401771 <+18>:    mov    $0x3,%ecx
   0x0000000000401776 <+23>:    callq  0x401710 <f1>		// Call f1
   0x000000000040177b <+28>:    mov    $0x0,%eax
   0x0000000000401780 <+33>:    add    $0x20,%rsp
   0x0000000000401784 <+37>:    pop    %rbp
   0x0000000000401785 <+38>:    retq
   0x0000000000401786 <+39>:    nop
   0x0000000000401787 <+40>:    nop
   0x0000000000401788 <+41>:    nop
   0x0000000000401789 <+42>:    nop
   0x000000000040178a <+43>:    nop
   0x000000000040178b <+44>:    nop
   0x000000000040178c <+45>:    nop
   0x000000000040178d <+46>:    nop
   0x000000000040178e <+47>:    nop
   0x000000000040178f <+48>:    nop
End of assembler dump.
(gdb) disassemble 0x401710
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)		// int a = 3
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)		// int b = 4
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax		// move 3 to eax
   0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax		// compare eax = 3 with 4
   0x0000000000401724 <+20>:    jle    0x401732 <f1+34>		// if a < b
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
   0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax
   0x0000000000401738 <+40>:    jge    0x401748 <f1+56>
   0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
   0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
(gdb) b *0x0000000000401721
Breakpoint 1 at 0x401721
(gdb) run
Starting program: D:\Github Project\Reverse_Engineering\9-Conditional\a.exe
[New Thread 396.0x248]

Breakpoint 1, 0x0000000000401721 in f1 ()
(gdb) disassemble  0x401710
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax
=> 0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax			// b less a == Not true,if (a > b) this is not true,  jump to address 0x401732
   0x0000000000401724 <+20>:    jle    0x401732 <f1+34>
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
   0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax			// if (a < b) this is a treu , b great a (b > a)
   0x0000000000401738 <+40>:    jge    0x401748 <f1+56>			// 
   0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
   0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
  "a < b"
(gdb) x/3s 0x405000
0x405000:       "a > b"
0x405006:       "a < b"
0x40500c:       "a == b"
(gdb) nexti
0x0000000000401724 in f1 ()
(gdb) info r
rax            0x3      3
rbx            0x40115b 4198747
rcx            0x3      3
rdx            0x4      4
rsi            0x7ff5ffff3000   140694538629120
rdi            0x7ff5ffff3000   140694538629120
rbp            0x24fdf0 0x24fdf0
rsp            0x24fdd0 0x24fdd0
r8             0x731e80 7544448
r9             0x24fd80 2424192
r10            0x0      0
r11            0x286    646
r12            0x0      0
r13            0x0      0
r14            0x0      0
r15            0x0      0
rip            0x401724 0x401724 <f1+20>
eflags         0x297    [ CF PF AF SF IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
(gdb) nexti
0x0000000000401732 in f1 ()
(gdb) disassemble f1
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax
   0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax
=> 0x0000000000401724 <+20>:    jle    0x401732 <f1+34>
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
   0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax
   0x0000000000401738 <+40>:    jge    0x401748 <f1+56>
   0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
   0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
(gdb) nexti
0x0000000000401732 in f1 ()
(gdb) disassemble f1
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax
   0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax
   0x0000000000401724 <+20>:    jle    0x401732 <f1+34>
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
=> 0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax
   0x0000000000401738 <+40>:    jge    0x401748 <f1+56>
   0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
   0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
(gdb) nexti
0x0000000000401735 in f1 ()
(gdb) nexti
0x0000000000401738 in f1 ()
(gdb) disassemble f1
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax
   0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax
   0x0000000000401724 <+20>:    jle    0x401732 <f1+34>
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
   0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax
=> 0x0000000000401738 <+40>:    jge    0x401748 <f1+56>
   0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
   0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
(gdb) nexti
0x000000000040173a in f1 ()
(gdb) disassemble f1
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax
   0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax
   0x0000000000401724 <+20>:    jle    0x401732 <f1+34>
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
   0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax
   0x0000000000401738 <+40>:    jge    0x401748 <f1+56>
=> 0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
   0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
(gdb) nexti
0x0000000000401741 in f1 ()
(gdb) disassemble f1
Dump of assembler code for function f1:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     mov    %ecx,0x10(%rbp)
   0x000000000040171b <+11>:    mov    %edx,0x18(%rbp)
   0x000000000040171e <+14>:    mov    0x10(%rbp),%eax
   0x0000000000401721 <+17>:    cmp    0x18(%rbp),%eax
   0x0000000000401724 <+20>:    jle    0x401732 <f1+34>
   0x0000000000401726 <+22>:    lea    0x38d3(%rip),%rcx        # 0x405000
   0x000000000040172d <+29>:    callq  0x403528 <printf>
   0x0000000000401732 <+34>:    mov    0x10(%rbp),%eax
   0x0000000000401735 <+37>:    cmp    0x18(%rbp),%eax
   0x0000000000401738 <+40>:    jge    0x401748 <f1+56>
   0x000000000040173a <+42>:    lea    0x38c5(%rip),%rcx        # 0x405006
=> 0x0000000000401741 <+49>:    callq  0x403528 <printf>
   0x0000000000401746 <+54>:    jmp    0x401754 <f1+68>
   0x0000000000401748 <+56>:    lea    0x38bd(%rip),%rcx        # 0x40500c
   0x000000000040174f <+63>:    callq  0x403528 <printf>
   0x0000000000401754 <+68>:    mov    $0x0,%eax
   0x0000000000401759 <+73>:    add    $0x20,%rsp
   0x000000000040175d <+77>:    pop    %rbp
   0x000000000040175e <+78>:    retq
End of assembler dump.
(gdb) nexti
a < b


```
