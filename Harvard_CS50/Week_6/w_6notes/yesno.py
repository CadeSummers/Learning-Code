#illustrates functionality of regular expressions in python

import re

s = input("Do you agree? ")

if re.search("^y(es)?$", s, re.IGNORECASE):
    print("Agreed.")
elif re.search("^n(o)?$", s, re.IGNORECASE):
    print("Disagreed.")