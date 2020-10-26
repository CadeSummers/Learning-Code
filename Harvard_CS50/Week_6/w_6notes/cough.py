#illustrates repition of cough from week 1, and implementation of main in python
def main():
    #loop using range, you do not have to define i
    #for i in range(3):
        #cough()
        
    #version of cough above (commented out) that takes as argument the number of times to cough
    cough(7)

def cough(num):
    for i in range(num):
        print("cough")

#calling of main, which contains cough    
main()
