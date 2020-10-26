#illustrates usage of loops in python

#declaration of a boolean variable
i_want_code_to_run_forever = False

#when boolean variable is true, the below will loop indefinitely
while i_want_code_to_run_forever == True: 
    print("hello, world")
  
#declaration of an int    
counter = 0

#while loop counting up to three
while counter < 3:
    counter += 1
    print(f"Counter value: {counter}/3")
    
    if counter == 3:
        print("Counting Complete")

#illustration of a for loop in python, using a list
for i in [0, 1, 2]:
    print(f"i: {i}")

#illustration of a for loop in python using range()
for j in range(5):
    #just as a for loop works, this hands back a value 1 less than j, as the count is index 0
    print(f"j: {j}")
    
