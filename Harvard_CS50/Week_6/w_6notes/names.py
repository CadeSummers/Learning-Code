#illustrates linear search style-algorithm in python

from sys import exit

names = ["EMMA HUMPHREY", "CADE", "ELORAGH", "DAVID"]

if "EMMA" in names:
    print("Found")
    exit(0)

print("Not found")
exit(1)
