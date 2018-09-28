# This program will give you a set number of numbers within the Fibonacci
# sequence.

ans=int(input("How many fibonacci number would you like?\n>> "))

n1 = 1
n2 = 1

if ans <= 2:
    if ans == 2:
        print(n1)
        print(n2)

    elif ans == 1:
        print(n1)

    elif ans <= 0:
        print("Sorry too low...")

elif ans > 2:
    print(n1)
    print(n2)

    while 2 < ans:    
        n3=(n1+n2)
        
        print(n3)
        
        n1=n2
        n2=n3
        
        ans -= 1
