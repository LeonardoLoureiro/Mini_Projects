#!/usr/bin/env python
# A small program that is used to calculate orders given to waiter. Each item/food/drink will be assigned
# a number and the waiter will enter orders.
# The program will also calculate a proposed tip...
# The program also displays the number of each item/food/drink that is ordered.
# Make sure to seperate order numbers with ',' when program asks for them.
import csv
'''
TO BE MADE:
    import csv
reader = csv.reader(open('filename.csv', 'r'))
d = {}
for row in reader:
   k, v = row
   d[k] = v
'''

menu = {}

# Converting from csv and adding it to the menu dict,i but First
# converting all prices from strings to floats. I could use straight
# from the DictReader but that would require code edit for the rest
# of the file which is too long.. :/
with open('MenuCalc.txt', 'r') as file:
    reader = csv.DictReader( file, delimiter=';' )

    for item in reader: 
        k, v = item['FOOD'], float( item['PRICE'] )
        menu[k] = v

def get_price( order_n ):
    return menu.values()[ order_n - 1 ]

# Display food on the menu for user...
print("\n" + "-"*8 + " MENU " + "-"*9 )
index = 1
for item in menu:
    print("%d) %.2f - %s" % ( index, menu[item], item ) )
    index += 1

# Taking orders from user and separating them into seperate numbers for
# the program to be able to 'understand' what the orders are...
# First the program iterates over the enterire order given then appends
# each number to a buffer until it encounters a comma, which then the 
# number so far is converted into an int.
print("\nPlease enter order:\t(please separate numbers with \',\')")
order = str(raw_input("> "))

sum = 0.00
order_repeats = {}

obj = ''
for char in order:
    if char != ',':
        obj += char
        continue

    order_n = int( obj )
    
    try:
        sum += get_price( order_n )

        obj = ''

        if order_n not in order_repeats:
            order_repeats[ order_n ] = 1

        elif order_n in order_repeats:
            order_repeats[ order_n ] += 1

    except:
        continue

# To compensate for the last order since for loop won't iterate once more
# and allow for order to be converted into int and added to sum and list...
order_n = int( obj )
sum += get_price( order_n )
if order_n not in order_repeats:
    order_repeats[ order_n ] = 1

elif order_n in order_repeats:
    order_repeats[ order_n ] += 1

# Here you display how many number of a certain item on menu is ordered
# along with the frequency of each food order as well as showing the
# total sum of the bill...
print("\n" + "-"*8 + " ORDER " + "-"*8 )

for order_item in order_repeats:
    print("%d x %s" % (order_repeats[order_item],
                       menu.keys()[ int( order_item - 1 ) ] ) )

print("\n" + "-"*9 + " SUM " + "-"*9 )
print("Sum: %.2f" % sum)
print("Sum with recommended tip (20%%): %.2f" % (sum*1.2) )
