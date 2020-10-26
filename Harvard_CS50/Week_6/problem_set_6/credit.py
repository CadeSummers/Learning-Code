#Program which verifies credit card and returns type of credit card
#card = 4003600000000014
import math

card = input("Enter your credit card: ")

check = len(card) - 2

while len(card) not in [13, 15, 16]:
    print("Invalid credit card length. Try again.")
    card = input("Enter your credit card: ")

#convert datatype to int so we can work with it    
card = int(card)
    
#declare 2 copies of card, cardodd and cardeven    
cardeven = cardodd = card

#declare to variables to hold the sum of numbers in card copies
sumeven = sumodd = 0

#reduce cardeven by one decimal place (see line 27)
cardeven = math.floor(cardeven / 10)

while cardeven != 0:
    
    # this operation grabs every other digit, starting from the first digit. We previously divided by 10 and floored to only get needed digits.
    i = (cardeven % 100) % 10
    
    #double the value of number in question
    i = i*2
    
    #if i is greater than 9, adds the digit in the 1's place and 1 more for the digit in the 10's place (which can only be 1)
    if i > 9:
        sumeven += i % 10
        sumeven += 1
    else:
        sumeven += i
    
    #reduce cardeven by two decimal places and continue the process
    cardeven = math.floor(cardeven / 100)

while cardodd != 0:
    
    #this operation grab every other digit, starting from the seccond to last
    i = (cardodd % 100) % 10
    
    #add digits
    sumodd += i
    
    #move onto next values
    cardodd = math.floor(cardodd/100)

#grab the totalsum of the above math
totalsum = sumeven + sumodd

#grab the first two digits of the card and set card equal to that value
card = math.floor(card / pow(10, check))

#final if check to determine cardtype
if totalsum % 10 == 0:
    
    if card >= 40 and card < 50:
        print("VISA")
        
    elif card > 50 and card <= 55:
        print("MASTERCARD")
        
    elif card == 34 or card == 37:
        print("AMEX")
        
    else:
        print("INVALID")
    
else:
    print("INVALID")
