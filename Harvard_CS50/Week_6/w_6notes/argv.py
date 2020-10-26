#illustrates how you can have command line arguments in python

from sys import argv

for i in range(len(argv)):
    print(argv[i])