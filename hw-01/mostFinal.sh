#!/bin/bash

counties=$(cut COVIDSummaryData.csv -d ',' -f1 | uniq)
maximum=0
for county in $counties; do
    count=$(grep -i "$county.*20-29" COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}')
    if [ -n "$count" ]
       then
	   if [ $count -gt $maximum ]
	   then
	       maximum=$count
	       maxCounty=$county
	   fi
    fi
done

echo $maxCounty $maximum





