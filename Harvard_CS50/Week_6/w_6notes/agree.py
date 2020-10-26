#illustrates writing a program to confirm agreements (yes or no) in python
answer = str(input("Do you agree?\n"))

#Illustrates conditional answering of questions
if (answer == "Y" or answer == "y" or answer == "yes" or answer == "Yes"):
    print("Agreed.")
elif (answer == "N" or answer == "n" or answer == "n" or answer == "No"):
    print("Not Agreed.")
else:
    print("Invalid Answer. Y/N Only.")
    
answer = str(input("Are you sure? You may change your answer.\n"))    
    
#Illustrates more succint way of checking answer for conditionals
if answer in ["Y", "y", "Yes", "yes"]:
    print("Agreed It Is.")
elif answer in ["N", "n", "No", "no"]:
    print("Not Agreed It Is.")
else:
    print("Invalid Answer. Y/N Only.")
    
#Illustrates an even more succint way of checking answer for conditionals

answer = str(input("Are you sure? You may change your answer. This is the last time you may change your answer.\n"))

if answer.lower() in ["y", "yes"]:
    print("Agreed It Is.")
elif answer.lower() in ["n", "no"]:
    print("Not Agreed It Is.")
else:
    print("Invalid Answer. Y/N Only.")