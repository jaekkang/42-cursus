#!/bin/bash

cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | cut -d ':' -f -1 | rev | sort -r | awk -v FT1="$FT_LINE1" -v FT2="$FT_LINE2" "NR >= FT1 && NR <= FT2" | tr '\n' ','| sed 's/,/, /g' | sed 's/.\{2\}$/./' | tr -d '\n'
