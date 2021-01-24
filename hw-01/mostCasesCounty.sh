#!/bin/bash

counties=$(cut COVIDSummaryData.csv -d ',' -f1 | uniq)

maximum=0
for county in $counties; do
    count=$(grep -i $county COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}')
    if [ $count -gt $maximum ]
    then
	maximum=$count
	maxCounty=$county
    fi
done

echo $maxCounty $maximum





