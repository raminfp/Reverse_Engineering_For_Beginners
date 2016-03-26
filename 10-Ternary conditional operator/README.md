# [+] Lesson 10
***
#### Ternary conditional operator (True , False)

```bash
(gdb) disassemble 0x401710
Dump of assembler code for function f:							// Call f function
   0x0000000000401710 <+0>:     push   %rbp
   0x0000000000401711 <+1>:     mov    %rsp,%rbp
   0x0000000000401714 <+4>:     mov    %ecx,0x10(%rbp)
   0x0000000000401717 <+7>:     cmpl   $0xa,0x10(%rbp)			// value of address argument 0x10(%rbp) == 10 
   0x000000000040171b <+11>:    jne    0x401726 <f+22>			// if not true jump to address 0x401726  
   0x000000000040171d <+13>:    lea    0x38dc(%rip),%rax        # 0x405000	//if is true  load string
   0x0000000000401724 <+20>:    jmp    0x40172d <f+29>			// jump pop 
   0x0000000000401726 <+22>:    lea    0x38dd(%rip),%rax        # 0x40500a	// if not true
   0x000000000040172d <+29>:    pop    %rbp
   0x000000000040172e <+30>:    retq
End of assembler dump.
(gdb) x/1s  0x405000
0x405000:       "it is ten"
(gdb)
```
