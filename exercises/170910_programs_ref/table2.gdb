start
echo Find the width of the table\n
p sizeof(table[0])/sizeof(int)
echo Find the height of the table\n
p sizeof(table)/$1/sizeof(int)
echo Let's make a bit more advanced way of checking of out of bound\n
echo If we index into with either first or second dimension outside of bound\n
break 16 if (&table[w][0] > &table[$2][0])
break 16 if (&table[0][h] > &table[0][$1])
continue
echo Highest first index\n
p &table[$2][0]
echo I am writing to address\n
p &table[w][0]
echo Highest second index\n
p &table[0][$1]
echo I am writing to address\n
p &table[0][h]
echo Ahh! I swapped the indexes\n