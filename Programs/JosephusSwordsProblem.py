# The Josephus Problem states that if X set of people sit in a circle, every
# other 'soldier' kills the next 'soldier' to their left, at the start you get
# to choose which chair to sit in so you can win, which position do you choose?
# This program tells you which position will win depending on how many players
# you start with.

chairs=int(input("Please enter the number of chairs:\n>> "))
n=2

while n<=chairs:
    n = n*2

if n>chairs:
    n = n//2

winning_pos = chairs-n

print("The chair which you win is %s"%( ( winning_pos*2 ) + 1 ) )
