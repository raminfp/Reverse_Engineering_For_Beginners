# [+] Lesson 7
***
#### Pointers

```bash

(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401742 <+0>:     push   %rbp
   0x0000000000401743 <+1>:     mov    %rsp,%rbp
   0x0000000000401746 <+4>:     sub    $0x20,%rsp
   0x000000000040174a <+8>:     callq  0x402ab3 <__main>
   0x000000000040174f <+13>:    lea    0x722e(%rip),%rax        # 0x408984 <product> 	// Pointers
   0x0000000000401756 <+20>:    mov    %rax,%r9	
   0x0000000000401759 <+23>:    lea    0x7220(%rip),%rax        # 0x408980 <sum>		// Pointers
   0x0000000000401760 <+30>:    mov    %rax,%r8
   0x0000000000401763 <+33>:    mov    $0x1c8,%edx
   0x0000000000401768 <+38>:    mov    $0x7b,%ecx
   0x000000000040176d <+43>:    callq  0x401710 <f1>									// CAll Function f1
   0x0000000000401772 <+48>:    lea    0x720b(%rip),%rax        # 0x408984 <product>	// argument f1
   0x0000000000401779 <+55>:    mov    (%rax),%edx
   0x000000000040177b <+57>:    lea    0x71fe(%rip),%rax        # 0x408980 <sum>		// argument f1
   0x0000000000401782 <+64>:    mov    (%rax),%eax										//move address rax(%rax) to eax 
   0x0000000000401784 <+66>:    mov    %edx,%r8d
   0x0000000000401787 <+69>:    mov    %eax,%edx
   0x0000000000401789 <+71>:    lea    0x3870(%rip),%rcx        # 0x405000
   0x0000000000401790 <+78>:    callq  0x403538 <printf>
   0x0000000000401795 <+83>:    nop
   0x0000000000401796 <+84>:    add    $0x20,%rsp
   0x000000000040179a <+88>:    pop    %rbp
   0x000000000040179b <+89>:    retq
   0x000000000040179c <+90>:    nop
   0x000000000040179d <+91>:    nop
   0x000000000040179e <+92>:    nop
   0x000000000040179f <+93>:    nop
End of assembler dump.
(gdb) b *0x000000000040174f
Breakpoint 1 at 0x40174f
(gdb) run
Starting program: D:\Github Project\Reverse_Engineering\7-Pointer\a.exe
[New Thread 248.0x164c]

Breakpoint 1, 0x000000000040174f in main ()
(gdb) info r
rax            0x1      1
rbx            0x40115b 4198747
rcx            0x1      1
rdx            0x891490 8983696
rsi            0x7ff5ffffc000   140694538665984
rdi            0x7ff5ffffc000   140694538665984
rbp            0x24fe20 0x24fe20
rsp            0x24fe00 0x24fe00
r8             0x891e80 8986240
r9             0x24fd80 2424192
r10            0x0      0
r11            0x286    646
r12            0x0      0
r13            0x0      0
r14            0x0      0
r15            0x0      0
rip            0x40174f 0x40174f <main+13>				//  0x720b(%rip),%rax = address rip  = rip + 0x720b = 4229466('0x40895a')
eflags         0x206    [ PF IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
(gdb)
```
You see ```lea``` syntax for pointer loading
```bash

   0x000000000040174f <+13>:    lea    0x722e(%rip),%rax        # 0x408984 <product> 	// Pointers 
   0x0000000000401756 <+20>:    mov    %rax,%r9	
   0x0000000000401759 <+23>:    lea    0x7220(%rip),%rax        # 0x408980 <sum>		// Pointers ('0x40895a')
   0x0000000000401760 <+30>:    mov    %rax,%r8
#############
Information registers:
   
(gdb) info r
rax            0x1      1
rbx            0x40115b 4198747
rcx            0x1      1
rdx            0x891490 8983696
rsi            0x7ff5ffffc000   140694538665984
rdi            0x7ff5ffffc000   140694538665984
rbp            0x24fe20 0x24fe20
rsp            0x24fe00 0x24fe00
r8             0x891e80 8986240
r9             0x24fd80 2424192
r10            0x0      0
r11            0x286    646
r12            0x0      0
r13            0x0      0
r14            0x0      0
r15            0x0      0
rip            0x40174f 0x40174f <main+13>
eflags         0x206    [ PF IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0
(gdb)
```
You see  two pointer address here :
```bash
   
(gdb) x/5s 0x408984
0x408984 <product>:     ""		// 1 byte
0x408985 <product+1>:   ""		// 2 byte
0x408986 <product+2>:   ""		// 3 byte
0x408987 <product+3>:   ""		// 4 byte for type Integer

```
You see end format string for call prinft()
```bash

(gdb) x/5s 0x405000
0x405000:       "sum=%d, product=%d\n"
```
