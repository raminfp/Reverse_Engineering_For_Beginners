# [+] Lesson 2
***
#### Work with GDB Debugger

```
D:\Github Project\Reverse_Engineering\lesson 2>gdb a.exe
GNU gdb (GDB) 7.9
Copyright (C) 2015 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word".
This binary was built by Equation Solution <http://www.Equation.com>...
Reading symbols from a.exe...done.
(gdb)

```
Looking main function :
```
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401710 <+0>:     push   %rbp         			// Push to stack
   0x0000000000401711 <+1>:     mov    %rsp,%rbp    			// move SP(stack pointer) to BP (Base Pointer)
   0x0000000000401714 <+4>:     sub    $0x20,%rsp   			// sub 32 bit of Stack
   0x0000000000401718 <+8>:     callq  0x402a53 <__main> 		// CALL main Function and start debug
   0x000000000040171d <+13>:    lea    0x38dc(%rip),%rcx        # 0x405000 // Load args of printf function 
   0x0000000000401724 <+20>:    callq  0x4034d8 <printf>        // CALL printf function  
   0x0000000000401729 <+25>:    mov    $0x0,%eax 				// eax = 0
   0x000000000040172e <+30>:    add    $0x20,%rsp  				// SP = SP + 32bit
   0x0000000000401732 <+34>:    pop    %rbp						// POP of Stack
   0x0000000000401733 <+35>:    retq  							// EXIT
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
(gdb)
```