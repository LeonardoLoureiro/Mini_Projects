import random
try:
    import tkinter as tk
    from tkinter import HORIZONTAL
except:
    import Tkinter as tk
    from Tkinter import HORIZONTAL

root = tk.Tk()
root.title("Password Generator")

## Functions for buttons
# To copy generated pass into clipboard
def Copy():
    #root.withdraw()
    #root.clipboard_clear()
    text = pass_label.cget('text')
    root.clipboard_append(text)
    root.update()    # stays in clipboard after program closes

# To generate password and display it on label
def Generate():
    characters = "qwertiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZCVBNM"
    numbers = "0123456789"
    special_chars = "{}~<>?/]['#,./*+=)(&^442\\\"!'"
    
    length = pass_length.get()
    special_char_val = special_check_bttn_value.get()
    nums_val = nums_check_bttn_value.get()
    
    # Are the tk.Checkbuttons ticked or not?
    if special_char_val == True:
        characters += special_chars
    if nums_val == True:
        characters += numbers

    passphrase = []
    secure_random = random.SystemRandom()

    for char in range(0, length, 1):
        passphrase.append(secure_random.choice(characters))   
    #print(''.join(passphrase))
    passphrase = ''.join(passphrase)
    pass_label.configure(text=passphrase)


## Where all generated passwords are shown
pass_label = tk.Label(  root,
                        text='52 characters can fit here.')
pass_label.grid(row=0, 
                column=0, 
                columnspan=2) 

pass_label.configure(width=52, 
                     height=2,
                     bg='white')

## Legnth of password?
length_label = tk.Label(root, text='Length of password:', anchor='e')
length_label.grid(row=1, column=0,
                  sticky='wesn') 
length_label.configure(width=5,
                       height=1)

## Scale to choose length of pass, 1-50
pass_length = tk.Scale( root, 
                        from_=1, to=50,
                        orient=HORIZONTAL)
pass_length.grid(row=1,
                 column=1,
                 sticky='n')

## Special characters or not?
# Label:
special_label = tk.Label(root, text='Special characters:', anchor='e')
special_label.grid(row=2, 
                   column=0,
                   sticky='wesn') 
special_label.configure(width=5,
                        height=1) 
# Check button:
special_check_bttn_value = tk.BooleanVar()
special_check_bttn = tk.Checkbutton(root,
                                 variable=special_check_bttn_value)
special_check_bttn.grid(row=2,
                        column=1)

## Numbers or not?
# Label:
nums_label = tk.Label(root, 
                      text='Numbers:', 
                      anchor='e')
nums_label.grid(row=3, 
                column=0,
                sticky='wesn')

nums_label.configure(width=5,
                     height=1)

# Check button
nums_check_bttn_value = tk.BooleanVar()
nums_check_bttn = tk.Checkbutton(   root,
                                    variable=nums_check_bttn_value)
nums_check_bttn.grid(row=3, 
                     column=1)

#Generate password button:
generate_bttn = tk.Button(  root, 
                            text='Generate password',
                            command=Generate)
generate_bttn.grid(row=5, 
                   column=1, 
                   sticky='wesn')

# Copy to clipboard button:
copy_bttn = tk.Button(  root, 
                        text='Copy!',
                        command=Copy)
copy_bttn.grid(row=5, 
               column=0, 
               sticky='wesn')


root.mainloop()
