#shows that there is no need for strcmp in Python, you can directly compare values in Python

from sys import exit

s1 = input("Enter first phrase: ")
s2 = input("Enter second phrase: ")

if s1 == s2:
    print("The phrases are the same")
    exit(0)
    
print("The phrases are different")
exit(1)