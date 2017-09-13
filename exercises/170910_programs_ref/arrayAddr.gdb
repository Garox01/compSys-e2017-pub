echo // The question is now, why did we get the segmentation fault at the end of the program and not while updating x. That was where we updated outside the array.\n
echo // First back to the stack!\n
start
echo // Remember from Monday that just before on the stack (higher address) we have information about how to continue execution when we return from the current function.\n
echo // We can get this information by: info frame\n
info frame
echo // Some interesting information\n
echo //  rip: the address current instruction we are execution.\n
echo //  saved rip: the address to which we return to after return of this function\n
echo //  later under "Saved registers:"  the part for rip tells us where the above address is stored.\n
echo // We can compare this to the address from "Locals at" (where the local variables start) or the largest address of x from before\n
echo // Number of elements in x\n
p sizeof(x)/sizeof(int)
echo // Largest address of x\n
p &x[$1-1]
echo // Note how the return address are just before.\n
echo // Now let's execute the program again\n
continue
echo // First we can take a new look at the stack frame\n
info frame
echo // See how the data including the rip and rbp have been updated.\n
echo // Simply said, when we return we are telling the program to continue execution at a complete random place in memory.\n
echo // That we are not allowed to and therefore gets a segmentation fault\n
echo \n
echo // But why did we not get it earlier?\n
echo // Let's look at the maxaddr that I added.\n
p maxaddr
echo // We can see that the maximal address is actually not very large, but still above our local values.\n
echo // So, update did write outside the local data, but not too much so it made segmentation fault.\n
echo // But it was just enough to mess-up our function return.\n

