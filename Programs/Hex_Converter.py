# This python script just converts between different formats of RGB values,
# like #FFFFFF or (255, 255, 255)

def hex_str2num(string):
    string_c = string
    string = string[1:]

    if len(string) == 6: 
        print(string_c + "\t=> ", end='')
        for i in range(0, 6, 2):
            temp = string[i]
            temp += string[i+1]

            num = int(temp, 16)

            print(num, end=' ')            

    elif len(string) == 3:            
        print(string_c + "\t=> ", end='')
        for i in range(0, 3):
            temp = string[i]

            num = int(temp, 16)**2

            print(num, end=' ')

    else:
        print("please make sure input is right format... example: #FAFAFA")

    print("")

# Values greater than 255 will just return '00'
def hex_num2str(rgb_values):
    rgb_str = "#"
    for i in range(0, 3):
        buffer = int(rgb_values[i])
        buffer = hex(buffer)
        buffer = buffer[2:]
        buffer = buffer.zfill(2).upper()

        rgb_str += buffer

    print("%s, %s, %s => %s" % (rgb_values[0], 
                                rgb_values[1],
                                rgb_values[2],
                                rgb_str))

hex_str2num("#0FFFFF")
rgb_values = ['15', '255', '255']
hex_num2str(rgb_values)
