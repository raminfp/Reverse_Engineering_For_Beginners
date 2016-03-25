# [+] Lesson 1
***
#### Work with GCC and GDB 

you should install MinGW on windows OS and define path on system variable like : GCC and GDB

### How to compile C language the Command Line?
```bash
 Usage : gcc <file.c> or ...
```
when use this command you see file ```a.exe``` on your current directory

Now you should run ```gdb``` command for debug source code C language

### How to debug PE file on the Command Line?
```bash
gdb <file.exe> or ...
```

### Example :
Compile :
```
D:\Github Project\Reverse_Engineering\lesson 1>
D:\Github Project\Reverse_Engineering\lesson 1>gcc 1-exam.c
```
List current directory :

```
D:\Github Project\Reverse_Engineering\lesson 1>dir
 Volume in drive D has no label.
 Volume Serial Number is 06C2-6AC3

 Directory of D:\Github Project\Reverse_Engineering\lesson 1

03/25/2016  01:03 PM    <DIR>          .
03/25/2016  01:03 PM    <DIR>          ..
03/25/2016  12:45 PM                70 1-exam.c
03/25/2016  01:03 PM            55,696 a.exe
03/25/2016  12:47 PM                39 README.md
               3 File(s)         55,805 bytes
               2 Dir(s)  30,984,159,232 bytes free
```
Run gdb for debug :
```
D:\Github Project\Reverse_Engineering\lesson 1>gdb a.exe
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