# this makes sure that the python script works regardless of the python version
# being used to run it. Python 2 uses the former and Python 3 the latter.
try:
    import tkinter as tk
except:
    import Tkinter as tk

# Setting up tkinter.
root = tk.Tk()
root.title('Calculator')

#==============================================================================
## Functions for all buttons of basic calculator

# This function just appends extra text from the buttons onto the Calc's
# label...
def AddStrToTxt(number):
    string = calc.cget("text")
    string += str(number)
    calc.configure(text=string)

# This funtion wipes away all text on the label...
def Clear():
    calc.configure(text='')

# retrieves the text from the label, removes the last char and then makes that
# the new label...
def Backspace():
    l_string = calc.cget("text")
    string = str(l_string)
    del_string = string[:-1]
    calc.configure(text=del_string)

# if a certain operator is already being used, then it makes sure that it
# doesn't just append text to it causing errors. works regardless if operator is
# the same or different to the one in the label...
def ChangeLabelTxtOp(op):
    # make sure to replace current op if already on label
    l_string = calc.cget("text")
    try:
        for item in operators:
            if l_string[-1] == item:
                l_string = l_string.replace(l_string[-1], "")
        l_string += str(op)
    except:
        pass
    calc.configure(text=l_string)

# passes the label through the 'eval' function...
def Equal():
    try:
        history_txt = open('Tkinter_history.txt', 'a')
        string = calc.cget("text")
        string = string.replace('^', '**')
        string = string.replace('x', '*')
        ans = eval('%s'%(string))
        history_txt.write("%s = %s\n"%(string, ans))
        calc.configure(text=str(ans))
        history_txt.close()

    except:
        pass

#==============================================================================
# Label for calculations to appear on.
calc = tk.Label(root, 
                text='',
                anchor='e')
calc.grid(row=0, column=0, 
          columnspan=4, 
          sticky=tk.W+tk.E)
calc.configure(background='white',
               width=44,
               height=1)


# Setting normal dimensions of buttons and text size.
bttn_w, bttn_h = 6, 3
# if to change these, also change label size too


#==============================================================================
# Button to clear everything
clear = tk.Button(root,
                  text='AC', # clearing  everything button
                  command=Clear,
                  width=bttn_w,
                  height=bttn_h)
clear.grid(row=1, column=0,
           columnspan=2,
           sticky=tk.E+tk.W+tk.S+tk.N) # makes it fit into 'squares'
    

#==============================================================================
# Button to remove last char on label
backspace = tk.Button(root,
                      text='->', # deleting button
                      command=Backspace,
                      width=bttn_w,
                      height=bttn_h)
backspace.grid(row=1, column=2,
           columnspan=2,
           sticky=tk.E + tk.W + tk.S + tk.N)

#==============================================================================
# Creating math operator buttons
operators = ['(', ')', '^', '/', 'x', '-', '+', '=', '.']
r, c = 2, 0
for item in operators:    
    bttn_command = lambda item=item: ChangeLabelTxtOp(item)
    # exception for =
    if item == '=':
        newButton = tk.Button(root, 
                              text=item, 
                              command=lambda:Equal(),
                              width=bttn_w,
                              height=bttn_h,
                              font=23)
        newButton.grid(row=r, column=c) 
    
    # exception for .
    elif item == '.':
        c -= 1
        newButton = tk.Button(root, 
                              text=item, 
                              command=bttn_command,
                              width=bttn_w,
                              height=bttn_h,
                              font=23)
        newButton.grid(row=r, column=c)
    
    # to switch from adding to column to adding to row
    elif c == 3:
        newButton = tk.Button(root, 
                              text=item, # settings for the rest of the operators button
                              command=bttn_command,
                              width=bttn_w,
                              height=bttn_h,
                              font=23)
        newButton.grid(row=r, column=c)
        r += 1
    
    # to keep adding to column until reaching the end
    else:
        newButton = tk.Button(root, 
                              text=item, # settings for the rest of the operators button
                              command=bttn_command,
                              width=bttn_w,
                              height=bttn_h,
                              font=23)
        newButton.grid(row=r, column=c)
        c += 1

#==============================================================================
# Creating number buttons. 
r, c = 3, 0
for number in range(0, 10):
    if number == 0:
        newButton = tk.Button(root, 
                              text='0', # number 0 button
                              command=lambda number=number: AddStrToTxt(number),
                              width=bttn_w,
                              height=bttn_h,
                              font=1)
        newButton.grid(row=6, 
                       column=0, 
                       columnspan=2, 
                       sticky=tk.W+tk.E) 
        continue
    elif c == 3:
        r+=1         
        c=0
    newButton = tk.Button(root, 
                          text=number, # rest of the numbers button
                          command=lambda number=number: AddStrToTxt(number),
                          width=bttn_w, # using default button dimensions
                          height=bttn_h,
                          font=1)
    newButton.grid(row=r, column=c)
    c+=1

root.mainloop()
