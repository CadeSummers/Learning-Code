#Program which prints 2 mario pyramids
def main():

    #initial grab of height
    height = int(input("Enter Pyramid Height: "))
    
    #Ensure valid height size
    while height > 8 or height < 1:
        print("Invalid Height. Try Again.")
        height = int(input("Enter Pyramid Height: "))
    
    #prints the pyramid building in ascending order and then pyramid in descending  
    pyramid(height)

#definition of function to print left (ascending) pyramid
def pyramid(height):
    blanks = height
    blocks = 1
        
    while blanks > 0:
        print((" " * (blanks - 1)) + ("#" * blocks) + "  " + ("#" * blocks)) #+ (" " * (blanks - 1))
        blanks-=1
        blocks+=1

main()
