#!/usr/bin/env python
# A small program that is used to calculate orders given to waiter. Each item/food/drink will be assigned
# a number and the waiter will enter orders such as 553 translate to 2 small drinks and 1 salad. 
# The program will also calculate a proposed tip... 
# The program also displays the number of each item/food/drink that is ordered


menu = {"Chicken w/ rice": 3.99, "Burger w/ fries": 4.99,
        "Hot dog": 1.49, "Potato salad": 3.50,
        "Small drink": 0.99, "Medium drink": 1.50,
        "Large drink": 2, "Milkshake": 2.49 }

print("\n" + "-"*8 + " MENU " + "-"*9 )
index = 1
for item in menu:
    print("%d) %.2f - %s" % ( index, menu[item], item ) )
    index += 1

print("\nPlease enter order:")
order = str(raw_input("> "))

sum = 0.00
order_multiples = {}
for number in order:
    try:
        number = int( number )
        sum += menu.values()[ number - 1 ]

        if number in order_multiples:
            order_multiples[number] += 1
        elif number not in order_multiples:
            order_multiples[number] = 1

    except:
        continue

print("\n" + "-"*8 + " ORDER " + "-"*8 )
for item in order_multiples:
    print("%d x %s" % ( order_multiples[item], 
                        menu.keys()[ int( item ) ] )  )


print("\n" + "-"*9 + " SUM " + "-"*9 )
print("Sum of order totals to: %.2f" % (sum) )
print("Sum with recommended tip (20%%): %.2f" % (sum*1.2) )
