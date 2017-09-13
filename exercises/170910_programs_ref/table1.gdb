run
echo Find the width of the table\n
p sizeof(table[0])/sizeof(int)
echo Find the height of the table\n
p sizeof(table)/$1/sizeof(int)
echo My table starts at address\n
p /x &table
echo that means that the maximum address is\n
p /x &table[$2][$1]
echo I am trying to write in address\n
p /x &table[w*h][h]
