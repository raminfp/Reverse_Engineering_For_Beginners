# [+] Lesson 3
***
#### Printf()

Looking main function :
```
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     sub    $0x20,%rsp
   0x0000000000401718 <+8>:     callq  0x402a53 <__main>
   0x000000000040171d <+13>:    lea    0x38dc(%rip),%rcx        # 0x405000
   0x0000000000401724 <+20>:    callq  0x4034d8 <printf>
   0x0000000000401729 <+25>:    mov    $0x0,%eax
   0x000000000040172e <+30>:    add    $0x20,%rsp
   0x0000000000401732 <+34>:    pop    %rbp
   0x0000000000401733 <+35>:    retq
   0x0000000000401734 <+36>:    nop
   0x0000000000401735 <+37>:    nop
   0x0000000000401736 <+38>:    nop
   0x0000000000401737 <+39>:    nop
   0x0000000000401738 <+40>:    nop
   0x0000000000401739 <+41>:    nop
   0x000000000040173a <+42>:    nop
   0x000000000040173b <+43>:    nop
   0x000000000040173c <+44>:    nop
   0x000000000040173d <+45>:    nop
   0x000000000040173e <+46>:    nop
   0x000000000040173f <+47>:    nop
End of assembler dump.
(gdb) break *0x0000000000401714									// set breakpoint on gdb
Breakpoint 1 at 0x401714
(gdb) run														// run program
Starting program: D:\Github Project\Reverse_Engineering\lesson 3\a.exe
[New Thread 3980.0x17cc]
[New Thread 3980.0x1afc]

Breakpoint 1, 0x0000000000401714 in main ()
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
=> 0x0000000000401714 <+4>:     sub    $0x20,%rsp     			// Set Breakpoint Here ("=>")
   0x0000000000401718 <+8>:     callq  0x402a53 <__main>
   0x000000000040171d <+13>:    lea    0x38dc(%rip),%rcx        # 0x405000 this address store string 
   0x0000000000401724 <+20>:    callq  0x4034d8 <printf>
   0x0000000000401729 <+25>:    mov    $0x0,%eax
   0x000000000040172e <+30>:    add    $0x20,%rsp
   0x0000000000401732 <+34>:    pop    %rbp
   0x0000000000401733 <+35>:    retq
   0x0000000000401734 <+36>:    nop
   0x0000000000401735 <+37>:    nop
   0x0000000000401736 <+38>:    nop
   0x0000000000401737 <+39>:    nop
   0x0000000000401738 <+40>:    nop
   0x0000000000401739 <+41>:    nop
   0x000000000040173a <+42>:    nop
   0x000000000040173b <+43>:    nop
   0x000000000040173c <+44>:    nop
   0x000000000040173d <+45>:    nop
   0x000000000040173e <+46>:    nop
   0x000000000040173f <+47>:    nop
End of assembler dump.
(gdb) x/2s 0x405000												// you see string function printf() c language store this address "0x405000" 
0x405000:       "Hello Ramin"
0x40500c:       ""
(gdb)
(gdb)
```