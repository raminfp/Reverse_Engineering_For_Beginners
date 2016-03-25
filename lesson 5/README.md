# [+] Lesson 5
***
#### Scanf()

```

(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x30,%rsp
   0x0000000000401718 <+8>:     callq  0x402a73 <__main>
   0x000000000040171d <+13>:    movl   $0xa,-0x4(%rbp)
   0x0000000000401724 <+20>:    mov    -0x4(%rbp),%eax
   0x0000000000401727 <+23>:    mov    %eax,%edx
   0x0000000000401729 <+25>:    lea    0x38d0(%rip),%rcx        # 0x405000
   0x0000000000401730 <+32>:    callq  0x4034f8 <printf>
   0x0000000000401735 <+37>:    lea    -0x4(%rbp),%rax
   0x0000000000401739 <+41>:    mov    %rax,%rdx
   0x000000000040173c <+44>:    lea    0x38bd(%rip),%rcx        # 0x405000
   0x0000000000401743 <+51>:    callq  0x403500 <scanf>
   0x0000000000401748 <+56>:    mov    $0x0,%eax
   0x000000000040174d <+61>:    add    $0x30,%rsp
   0x0000000000401751 <+65>:    pop    %rbp
   0x0000000000401752 <+66>:    retq
   0x0000000000401753 <+67>:    nop
   0x0000000000401754 <+68>:    nop
   0x0000000000401755 <+69>:    nop
   0x0000000000401756 <+70>:    nop
   0x0000000000401757 <+71>:    nop
   0x0000000000401758 <+72>:    nop
   0x0000000000401759 <+73>:    nop
   0x000000000040175a <+74>:    nop
   0x000000000040175b <+75>:    nop
   0x000000000040175c <+76>:    nop
   0x000000000040175d <+77>:    nop
   0x000000000040175e <+78>:    nop
   0x000000000040175f <+79>:    nop
End of assembler dump.
(gdb) x/2s 0x0000000000401718
0x401718 <main+8>:      "èV\023"
0x40171c <main+12>:     ""
(gdb) b *0x0000000000401718
Breakpoint 1 at 0x401718
(gdb) run
Starting program: D:\Github Project\Reverse_Engineering\lesson 5\a.exe
[New Thread 6048.0x146c]
[New Thread 6048.0xdc8]

Breakpoint 1, 0x0000000000401718 in main ()
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x30,%rsp
=> 0x0000000000401718 <+8>:     callq  0x402a73 <__main>
   0x000000000040171d <+13>:    movl   $0xa,-0x4(%rbp)			// int x = 10
   0x0000000000401724 <+20>:    mov    -0x4(%rbp),%eax			// move 10 t0 eax
   0x0000000000401727 <+23>:    mov    %eax,%edx				// move eax to edx
   0x0000000000401729 <+25>:    lea    0x38d0(%rip),%rcx        #  0x405000 // load format string of argument printf() "%d"
   0x0000000000401730 <+32>:    callq  0x4034f8 <printf>		// call prinft()
   0x0000000000401735 <+37>:    lea    -0x4(%rbp),%rax			// import address (rbp - 4) to rax
   0x0000000000401739 <+41>:    mov    %rax,%rdx				// move address
   0x000000000040173c <+44>:    lea    0x38bd(%rip),%rcx        #  0x405000 // load format string of scanf()
   0x0000000000401743 <+51>:    callq  0x403500 <scanf>			// call scanf()
   0x0000000000401748 <+56>:    mov    $0x0,%eax
   0x000000000040174d <+61>:    add    $0x30,%rsp
   0x0000000000401751 <+65>:    pop    %rbp
   0x0000000000401752 <+66>:    retq
   0x0000000000401753 <+67>:    nop
   0x0000000000401754 <+68>:    nop
   0x0000000000401755 <+69>:    nop
   0x0000000000401756 <+70>:    nop
   0x0000000000401757 <+71>:    nop
   0x0000000000401758 <+72>:    nop
   0x0000000000401759 <+73>:    nop
   0x000000000040175a <+74>:    nop
   0x000000000040175b <+75>:    nop
   0x000000000040175c <+76>:    nop
   0x000000000040175d <+77>:    nop
   0x000000000040175e <+78>:    nop
   0x000000000040175f <+79>:    nop
End of assembler dump.
(gdb) x/1s 0x405000
0x405000:       "%d"
(gdb) x/1s 0x405000
0x405000:       "%d"
(gdb) nexti
0x000000000040171d in main ()
(gdb) nexti
0x0000000000401724 in main ()
(gdb) nexti
0x0000000000401727 in main ()
(gdb) nexti
0x0000000000401729 in main ()
(gdb) info r
rax            0xa      10
rbx            0x40115b 4198747
rcx            0x1      1
rdx            0xa      10
rsi            0x7ff5ffff9000   140694538653696
rdi            0x7ff5ffff9000   140694538653696
rbp            0x24fe20 0x24fe20
rsp            0x24fdf0 0x24fdf0
r8             0x7f1e80 8330880
r9             0x24fd80 2424192
r10            0x0      0
r11            0x286    646
r12            0x0      0
r13            0x0      0
r14            0x0      0
r15            0x0      0
rip            0x401729 0x401729 <main+25>
eflags         0x202    [ IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x30,%rsp
   0x0000000000401718 <+8>:     callq  0x402a73 <__main>
   0x000000000040171d <+13>:    movl   $0xa,-0x4(%rbp)
   0x0000000000401724 <+20>:    mov    -0x4(%rbp),%eax
   0x0000000000401727 <+23>:    mov    %eax,%edx
=> 0x0000000000401729 <+25>:    lea    0x38d0(%rip),%rcx        # 0x405000
   0x0000000000401730 <+32>:    callq  0x4034f8 <printf>
   0x0000000000401735 <+37>:    lea    -0x4(%rbp),%rax
   0x0000000000401739 <+41>:    mov    %rax,%rdx
   0x000000000040173c <+44>:    lea    0x38bd(%rip),%rcx        # 0x405000
   0x0000000000401743 <+51>:    callq  0x403500 <scanf>
   0x0000000000401748 <+56>:    mov    $0x0,%eax
   0x000000000040174d <+61>:    add    $0x30,%rsp
   0x0000000000401751 <+65>:    pop    %rbp
   0x0000000000401752 <+66>:    retq
   0x0000000000401753 <+67>:    nop
   0x0000000000401754 <+68>:    nop
   0x0000000000401755 <+69>:    nop
   0x0000000000401756 <+70>:    nop
   0x0000000000401757 <+71>:    nop
   0x0000000000401758 <+72>:    nop
   0x0000000000401759 <+73>:    nop
   0x000000000040175a <+74>:    nop
   0x000000000040175b <+75>:    nop
   0x000000000040175c <+76>:    nop
   0x000000000040175d <+77>:    nop
   0x000000000040175e <+78>:    nop
   0x000000000040175f <+79>:    nop
End of assembler dump.
(gdb) nexti
0x0000000000401730 in main ()
(gdb) nexti
100x0000000000401735 in main ()
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x30,%rsp
   0x0000000000401718 <+8>:     callq  0x402a73 <__main>
   0x000000000040171d <+13>:    movl   $0xa,-0x4(%rbp)
   0x0000000000401724 <+20>:    mov    -0x4(%rbp),%eax
   0x0000000000401727 <+23>:    mov    %eax,%edx
   0x0000000000401729 <+25>:    lea    0x38d0(%rip),%rcx        # 0x405000
   0x0000000000401730 <+32>:    callq  0x4034f8 <printf>
=> 0x0000000000401735 <+37>:    lea    -0x4(%rbp),%rax
   0x0000000000401739 <+41>:    mov    %rax,%rdx
   0x000000000040173c <+44>:    lea    0x38bd(%rip),%rcx        # 0x405000
   0x0000000000401743 <+51>:    callq  0x403500 <scanf>
   0x0000000000401748 <+56>:    mov    $0x0,%eax
   0x000000000040174d <+61>:    add    $0x30,%rsp
   0x0000000000401751 <+65>:    pop    %rbp
   0x0000000000401752 <+66>:    retq
   0x0000000000401753 <+67>:    nop
   0x0000000000401754 <+68>:    nop
   0x0000000000401755 <+69>:    nop
   0x0000000000401756 <+70>:    nop
   0x0000000000401757 <+71>:    nop
   0x0000000000401758 <+72>:    nop
   0x0000000000401759 <+73>:    nop
   0x000000000040175a <+74>:    nop
   0x000000000040175b <+75>:    nop
   0x000000000040175c <+76>:    nop
   0x000000000040175d <+77>:    nop
   0x000000000040175e <+78>:    nop
   0x000000000040175f <+79>:    nop
End of assembler dump.
(gdb) nexti
0x0000000000401739 in main ()
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x30,%rsp
   0x0000000000401718 <+8>:     callq  0x402a73 <__main>
   0x000000000040171d <+13>:    movl   $0xa,-0x4(%rbp)
   0x0000000000401724 <+20>:    mov    -0x4(%rbp),%eax
   0x0000000000401727 <+23>:    mov    %eax,%edx
   0x0000000000401729 <+25>:    lea    0x38d0(%rip),%rcx        # 0x405000
   0x0000000000401730 <+32>:    callq  0x4034f8 <printf>
   0x0000000000401735 <+37>:    lea    -0x4(%rbp),%rax
=> 0x0000000000401739 <+41>:    mov    %rax,%rdx
   0x000000000040173c <+44>:    lea    0x38bd(%rip),%rcx        # 0x405000
   0x0000000000401743 <+51>:    callq  0x403500 <scanf>
   0x0000000000401748 <+56>:    mov    $0x0,%eax
   0x000000000040174d <+61>:    add    $0x30,%rsp
   0x0000000000401751 <+65>:    pop    %rbp
   0x0000000000401752 <+66>:    retq
   0x0000000000401753 <+67>:    nop
   0x0000000000401754 <+68>:    nop
   0x0000000000401755 <+69>:    nop
   0x0000000000401756 <+70>:    nop
   0x0000000000401757 <+71>:    nop
   0x0000000000401758 <+72>:    nop
   0x0000000000401759 <+73>:    nop
   0x000000000040175a <+74>:    nop
   0x000000000040175b <+75>:    nop
   0x000000000040175c <+76>:    nop
   0x000000000040175d <+77>:    nop
   0x000000000040175e <+78>:    nop
   0x000000000040175f <+79>:    nop
End of assembler dump.
```

```
lea    -0x4(%rbp),%rax
output :
C:\Users\RaminFP>irb
irb(main):001:0> 0x24fe20 - 0x4
=> 2424348
irb(main):002:0>
```

You see rbp same with rax (2424348)

```
(gdb) info r
rax            0x24fe1c 2424348
rbx            0x40115b 4198747
rcx            0xffffffff       4294967295
rdx            0x7ff86c09e240   140704941204032
rsi            0x7ff5ffff9000   140694538653696
rdi            0x7ff5ffff9000   140694538653696
rbp            0x24fe20 0x24fe20
rsp            0x24fdf0 0x24fdf0
r8             0x7ff86c0a35a0   140704941225376
r9             0x24e270 2417264
r10            0x0      0
r11            0x246    582
r12            0x0      0
r13            0x0      0
r14            0x0      0
r15            0x0      0
rip            0x401739 0x401739 <main+41>
eflags         0x202    [ IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
(gdb)
```