# COEN 177 Lab 1 
*Oras Phongpanangam*

Each file with name in a format of "lab1_#.c" corresponds to each programming task with the same number, with compiled executables having the same name without an extension. "makefile" is a valid makefile that can be used with `make` to compile every file .

## File list
- `helloworld.c`: A simple program printing out some string.
- `lab1_1.c`: (Task 1) Simple shell that can be used to run another program (e.g. `helloworld`) in a new thread. 
- `lab1_2.c`: (Task 2) Create a linear chain of 8 processes and print out PID and PPID of each process.
- `lab1_3.c`: (Task 3) Create a symmetric process tree with 12 children (not counting the root). The tree has 3 levels and each node has exactly 3 children.
- `lab1_4.c`: (Task 4) Create a process tree with 17 children. The procedure is 1) create left and right children manually, 2) create tree with 2 levels and 3 children per node (4 nodes) on the first child, 3) create tree with 3 levels and 3 children per node (13 nodes) on the second child.
- `makefile`: for compiling
- Other executables