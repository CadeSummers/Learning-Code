#get positive integer

def main():
    i = get_posint()
    print(i)

def get_posint():
    
    num = int(input("Enter a positive number: "))
    
    while num <= 0:
        print("Number is not positive. Try Again.")
        num = int(input("Enter a positive number: "))
        
    return num

main()