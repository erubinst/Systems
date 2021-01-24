# hw-01-erubinst

Esme Rubinstein and Nuriel Leve

1.Description of programs
    
    testurl.sh - This program read through each url in a file and checked if the url existed or not and printed out if the url did not.
    
    backup.sh - This program takes in an argument of one or more files and/or directories and backs it up into the backup directory. If the file or directory does not exist, it will back it up. If it does exist and it is the newer version, it will update that file in the backup directory.
    
    diskhog.sh - This lists the top 5 biggest things in the working directory in human readable format.  Option to add a flag with a number to specify if you want a different number than 5
    
    linecount.sh - This program determined the total number of lines in all files in a directory.

2.Answers

  How many cases are in Lorain county? 

    2253, using the command:
    grep -i "Lorain" COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}'

  How many cases are there for Males vs. Females?

    There are 67,620 cases for Males, and 74814 for Females.
    I used these two commands to find the total number of cases for Males and for Females.
    
    grep -w "Male" COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}'

    grep -w "Female" COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}'
   
  Which county has the most cases?
  
  	Franklin 26242 cases.
	
	The commands for this can be found in our mostCasesCounty.sh file, but the general commands used were:
	counties=$(cut COVIDSummaryData.csv -d ',' -f1 | uniq)
	for county in $counties; do
	count=$(grep -i $county COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}')

  Which county has the most cases for 20-29 year olds?
  
  	Franklin with 7096 cases.
	
  	The commands for this can be found in our mostFinal.sh file, but the general commands used were:
	counties=$(cut COVIDSummaryData.csv -d ',' -f1 | uniq)
	for county in $counties; do
	count=$(grep -i "$county.*20-29" COVIDSummaryData.csv | cut -d',' -f7 | awk '{total = total + $1}END{print total}')


3.Estimate time it took to complete each part

    Part 1, 3, and 4 took about 15 - 20 minutes each. Part 2 took about 30 minues to complete and part 5 took about an hour to complete. 


4.Any known bugs or incomplete functions

     No bugs or Incomplete Functions
     
 
5.Any interesting design decisions you'd like to share

    N/A
