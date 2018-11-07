#!/usr/bin/env python
# A small program that is used to calculate orders given to waiter. Each item/food/drink will be assigned
# a number and the waiter will enter orders such as 553 translate to 2 small drinks and 1 salad. 
# The program will also calculate a proposed tip... 
# The program also displays the number of each item/food/drink that is ordered


menu = {"Chicken w/ rice": 3.99, 
        "Burger w/ fries": 4.99,
        "Hot dog": 1.49, 
        "Potato salad": 3.50,
        "Small drink": 0.99, 
        "Medium drink": 1.50,
        "Large drink": 2, 
        "Milkshake": 2.49,
        "Small pasta": 2.50, 
        "Big pasta": 3.00}

def get_price( order_n ):
    return menu.values()[ order_n - 1 ]

# Display food on the menu for user...
print("\n" + "-"*8 + " MENU " + "-"*9 )
index = 1
for item in menu:
    print("%d) %.2f - %s" % ( index, menu[item], item ) )
    index += 1

# Taking orders from user...
print("\nPlease enter order:\t(separate numbers with \',\')")
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

# To compensate for the last order since for loop won't iterate once more..
order_n = int( obj )
sum += get_price( order_n )
if order_n not in order_repeats:
    order_repeats[ order_n ] = 1

elif order_n in order_repeats:
    order_repeats[ order_n ] += 1

# Here you display how many number of a certain item on menu is ordered...
print("\n" + "-"*8 + " ORDER " + "-"*8 )

for order_item in order_repeats:
    print("%d x %s" % (order_repeats[order_item],
                       menu.keys()[ int( order_item - 1 ) ] ) )

print("\n" + "-"*9 + " SUM " + "-"*9 )
print("Sum: %.2f" % sum)
print("Sum with recommended tip (20%%): %.2f" % (sum*1.2) )
