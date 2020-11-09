#Program which analyzes a sequence of DNA to determine who it most likely belongs to

#Imports from sys
from sys import argv, exit

#Import the CSV module
import csv

def identify_dna(csvfile):
    #Creates a dictionary allowing the indexing of the list dnacount, byt simply calling the name of the dna sequence. dnacount below keeps the index of repeating sequences.
    ##dnadict = {0 : "AGATC" , 1 : "TTTTTTCT", 2 : "AATG", 3 : "TCTAG", 4 : "GATA", 5 : "TATC", 6 : "GAAA", 7 : "TCTG"}

    #Save the csv file to a variable named toprow
    toprow = csv.reader(csvfile)

    #Make the variable toprow only equivalent to the top row of the file
    #(This was the only way I could figure out how to get the first row of the csvfile)
    for row in toprow:
        toprow = row
        break

    #Get rid of the first column value of toprow (the "name" section in this case, this leaves us with the dna sequences we will check for later on)
    toprow.pop(0)

    #declare dnadict as an dictionary
    dnadict = {}

    #store the item values of toprow to the dictionary dnadict, and associate the key values of each element to be the current index of i
    for i in range(len(toprow)):
        dnadict[i] = toprow[i]
    
    #return our dictionary of dna to the main    
    return dnadict

#Define recursive function to check dna elements
def dnacheck(dnacount, check, row):
    
    #We are checking the dnacounts from last element to first element. If the last element isn't filled, it means it was from small.csv, and we need to reduce the check index to 3
    while dnacount[check] == 0:
        check-=1
    
    #Compare the dnacount at index check to the integer value of row at index check to the integer value of dnacount at check. There are 8 checks to make max 
    if dnacount[check] == int(row[check]):
        
        #reduce check by 1
        check-=1
        
        #special case for final analysis if check == 0 to return true function
        if check == 0 and (int(row[check]) == dnacount[check]):
            return True
        
        #recursive statement if check is greater than 0 recall this function
        elif check > 0: #and int(row[check]) == dnacount[check]:
            
            dnacheck(dnacount, check, row)
        
        #if the last element is reached and the match fails, report failure    
        else: 
            
            return True
    else:
        
        return False
        

#######################################   MAIN CODE   #######################################

#Ensure proper usage
if len(argv) != 3:
    print("Invalid Number Of Files Attached. Program Must Include Database & Sequence Attached. Try Again.")
    exit(1)

#Ensure one txt file and one csv file
if argv[1].endswith(".csv") and argv[2].endswith(".csv"):
    print("Duplicate files detected. Arguments should consist of one .csv file and of one .txt file.")
    exit(2)
elif argv[1].endswith(".txt") and argv[2].endswith(".txt"):
    print("Duplicate file types detected. Arguments should consist of one .csv file and of one .txt file.")
    exit(3)

#Ensure proper file type of first argument.
if argv[1].endswith(".csv"):
    csvfile = open(argv[1], "r")
elif argv[1].endswith(".txt"):
    txtfile = open(argv[1], "r")
    
    #convert txtfile to string
    txtfile = txtfile.read().replace("\n", "")
else:
    print("Wrong File Type.") 
    exit(4)

#Ensure proper file type of second argument.   
if argv[2].endswith(".csv"):
    csvfile = open(argv[2], "r")
elif argv[2].endswith(".txt"):
    txtfile = open(argv[2], "r")
    
    #convert txtfile to string
    txtfile = txtfile.read().replace("\n", "")
     
else:
    print("Wrong File Type.") 
    exit(5)

#establish a dictionary for reference based on the STRs imported from the csvfile
dnadict = identify_dna(csvfile)
    
#list to store the values of the above repeating STRs (the index of the STR in dictionary is the index of the STR from toprow & dnadict)
dnacount = [0, 0, 0, 0, 0, 0, 0, 0]

#For each index of the dictionary (aka each sequence of dna we are checking)
for x in dnadict:
    
    #print(f"checking {dnadict[x]}")
    
    #initialize a counter for the maximum consecutive STRs
    dnamax = 0
    
    #Define a buffer to be the index of y plus the length of the dictionary item we are currently looking at
    buff = len(dnadict[x])
    
    #traverse the indeces of the txtfile
    for y in range(len(txtfile)):
        
        #If the sequence of characters in the txtfile from index y through index of y + buff is the same as sequence of characters in the dnadict at index x (aka one of the STRs)
        if txtfile[y:(y + buff)] == dnadict[x]:
            
            #increment the dnamax value by 1
            dnamax+=1
            
            while txtfile[y - buff:y] == txtfile[y: y + buff]:
                #increment the number of maximum sequences we have found by 1
                dnamax+=1
                #print(f"Match between txtfile's {txtfile[y:(y+buff)]} ({y} through {(y+buff)}) and the number {x} element of dnadict: {dnadict[x]}")
                #print(f"dnamax: {dnamax}")
                
                #increment y by the length of the element in dnadict at index x
                y+=buff
        
        #When the consecutive sequences of characters ends    
        else:
            
            #If the value of dnamax is greater than the value of the corresponding element in dnacount, set the value of the corresponding index to the value of dnamax
            if dnamax > dnacount[x]:
                #print(f"setting dnacount at position {x} to {dnamax}")
                dnacount[x] = dnamax
            
            #reset the value of dnamax
            dnamax = 0
        

#convert csvfile to list format
csvfile = csv.reader(csvfile)

#create a variable to store names
names = []

#create a variable to serve as the index between names and dna strains
count = 0

#Analyze the dna sequence of each person in the CSV and look for a match
for row in csvfile:
    
    #add the name of the person we are checking to the names list
    names.append(row[0])
    
    #remove the name section from the row we are checking
    row.pop(0)
    
    #index of string comparison, starting from the final index of the dnacount, which is 1 less than the length of dnacount
    check = len(dnacount) - 1
    
    if dnacheck(dnacount, check, row) is True:
        print(f"{names[count]}")
        exit(0)
        
    count+=1
    
#print(names)

print("No Match")        