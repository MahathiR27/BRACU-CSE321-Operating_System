
# BRACU CSE321(Operating System)
* The [lab_assignments](https://github.com/MahathiR27/BRACU-CSE321-Operating_System/tree/main/lab_assignments) includes all of the **lab assignment questions** and the their **solution**.
* The [lab_files](https://github.com/MahathiR27/BRACU-CSE321-Operating_System/tree/main/lab_files) are kind of like **personal notes** so, it might not help much. The lab faculties will provide you all of the lab pdf and resouces so just follow that.
* The [theory_slides](https://github.com/MahathiR27/BRACU-CSE321-Operating_System/tree/main/theory_sldes) contains slides created by NTR, which I personally **followed**. How ever you can also see the [Central Slides](https://drive.google.com/drive/folders/1zN6sltZiY-D1xze6Zcpd_VvXXzi5C0J7?usp=drive_link) which are lot smaller but are **missing** many important information.
* The [problem_sheets](https://github.com/MahathiR27/BRACU-CSE321-Operating_System/tree/main/practice_sheet) has all the theory **problem sheets and solutions**.

* I am not including theory assignments, as they are just **research based** assignments. You will just have to a lot of Googling.

# Term Projects
## Project 1: [UNIX shell using C](https://github.com/MahathiR27/UNIX-Shell-Project)
**Repository:** https://github.com/MahathiR27/UNIX-Shell-Project

**Details:** The shell must be able to run basic linux commands, I/O redirections and handle errors. Following core features must be implemented:
1. Display a command prompt (e.g., `sh>` ) and read user input.
2. Parse and execute system commands.  
_For example, running `pwd` will output the absolute path of the directory that your shell is working on.  
Hint: Use `fork` and `exec` system call._
3. Support input (`<`) and output (`>` and `>>`) redirection.  
_Hint: Use `dup` and `dup2`._
4. Support command piping (`|`). Your shell should support any number of piping.  
_For example, `command1 | command2 | command3 | command4` should work._
5. Support multiple commands in-line separated by semicolon (`;`).
6.  Support multiple command in sequence using (`&&`).
7.  Support history of executed commands.
8.   Support signal handling. Pressing `CTRL+C` should terminate the currently running command inside your shell, not your shell.  
_Hint: Use `signal` and `sigaction`._

## Project 2: [VSFSck: A Consistency Checker for Very Simple File System (VSFS)](https://github.com/MahathiR27/VSFSck-Consistency_Checker_for-Very_Simple_File_System-VSFS)
**Repository:** https://github.com/MahathiR27/VSFSck-Consistency_Checker_for-Very_Simple_File_System-VSFS

**Details:** Design and implement a file system consistency checker, vsfsck, for a custom virtual file system (VSFS). Your tool will be responsible for verifying the integrity and consistency of essential file system structures, including:

-   Superblock
-   Inodes
-   Data blocks
-   Inode and data bitmaps

The checker will operate on a file system image (vsfs.img), identifying and reporting any inconsistencies found.

