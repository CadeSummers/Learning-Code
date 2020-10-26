#recreation of overflow.c in python, showing that python has no upperbound on ints

#import sleep from the time library
from time import sleep

#set initial value equivalent to 1
i = 1

#indefinite loop
while True:
    print(i)
    sleep(.01)
    i *= 2