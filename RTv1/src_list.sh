find src -name "*.c" | cat -e | sed 's/\$/\\/g' | sed "s/src\///g"
