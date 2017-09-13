echo // That the segmentation fault is at the end of the program makes it much harder to understand what happens.\n
echo // We do not have a specific update to start from.\n
echo // But I do expect that is has something to do with my updates, which is in line 30.
start
echo // Number of elements in x\n
p sizeof(x)/sizeof(int)
echo // Start of x\n
p &x
echo // Largest address of x\n
p &x[$1-1]
echo // With can not try to check if our call to update always are within the array bound.\n
break 28 if &arr[size-1] > $3
continue
info args
echo // Yes, that would read longer than my array. Let's see where we came from\n
backtrace
echo // So at #3 we see that the address counts more up that the size is decreasing.
echo // Thus, it must be in our call to update.
echo // We can see that in update(arr+i, size-1), the size is only decremented while the pointer can move further up.