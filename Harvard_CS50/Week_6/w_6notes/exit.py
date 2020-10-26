#illustrates how you can exit a program

from sys import argv, exit

if len(argv) != 2:
    print("Missing Command Line Argument. Try Again.")
    exit(1)
    
print("Argument successfuly found.")
exit(0)