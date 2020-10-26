#program illustrating how comparisons work

x = 0

y = 2

print(f"The value of x is {x} and the value of y is {y}")

if x < y:
    print("x is less than y")
    print("Adding 3 to x")
    x += 3
    
if x > y:
    print("x is greater than y.")
    print("Adding 1 to y.")
    y += 1
    
if x == y:
     print(f"x: ({x}) is now equal to y: ({y}).")
     print("Thanos is now happy.")
     