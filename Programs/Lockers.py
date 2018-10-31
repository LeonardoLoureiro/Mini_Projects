#!/usr/bin/env python
# Got this problem from TedEd riddles where you get 100 lockers, each with a key.
# The person who gets key 1 will open every locker, person with key 2
# will open or close every other locker and so on. Which lockers will be open
# by the 100th iteration?

num_locks = 100

# First make a dict with 100 (or how many you want) lockers each of them closed.
lockers = {}
for i in range(1, num_locks+1): # since range doesn't count the actual number.
    lockers[i] = "closed"

# Now iterate each one with the rules.
rounds = 0
while(1):
    rounds += 1 

    if rounds == num_locks+1:
        break
    
    for num in range(rounds, num_locks+1, rounds):
        if lockers[num] == "open":
            lockers[num] = "closed"

        elif lockers[num] == "closed":
            lockers[num] = "open"

# Finally iterate through all lockers and check which ones are open.
for key, value in lockers.iteritems():
    if value == "open":
        print("%s is %s" % (key, value) )
