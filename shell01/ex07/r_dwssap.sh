cat /etc/passwd | sed '1,10d' | awk 'NR%2-1' | cut -f1 -d":" | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' ' ' | sed "s/ $/./" | sed "s/ /, /g" | tr -d '\n'
