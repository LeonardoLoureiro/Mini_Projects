#!/usr/bin/env python
# This program randomly chooses a number between 1 and 20 and has user guess
# which it is by either telling them whether their input was too high or too
# low. The user only has 7 turns to guess this number.

import random

state = True
while state:
    turns = 0
    numb = random.randint(1,20)
    guesses = 7

    print("#"*10 + " WELCOME " + "#"*10)
    print("I'm guessing of a number between 1 and 20")

    while turns < guesses:
        tries = guesses - turns

        print("(You have %d tries left)\nGuess the number:" % (tries) )

        usr = int(input(">> "))
        
        turns += 1
        if turns == 7:
            break

        elif usr == numb:
            print("\nWell done, you've guessed it in %s tries!" % ( turns ) )
            break
        
        elif usr > numb:
            print("\nYour guess is too high.")
        
        elif usr < numb:
            print("\nYour guess is too low")

    if turns == guesses:
        print("\nBad Luck\nThe number I was thinking was %s" % (numb))

    choice = True
    while choice:
        play = raw_input("\nPlay again?\t(y/n)\n>> ")

        if play == "y":
            choice = False
        
        elif play == "n":
            state = False
            print("~"*10 + " GOODBYE " + "~"*10)
            choice = False
        
        else:
            print("")
