import time
import sys

mins = 0
hours = 0
secs = 0
while True:
    if secs < 10:
        if mins < 10:
            if hours < 10:
                print('0%s:0%s:0%s'%(hours, mins, secs))
            
            elif hours >= 10:
                print('%s:0%s:0%s'%(hours, mins, secs))
        
        elif mins >= 10:
            if hours < 10:
                print('0%s:%s:0%s'%(hours, mins, secs))
                
            elif hours >= 10:
                print('%s:%s:0%s'%(hours, mins, secs))

    elif secs >= 10:
        if mins < 10:
            if hours < 10:
                print('0%s:0%s:%s'%(hours, mins, secs))
            
            elif hours >= 10:
                print('%s:0%s:%s'%(hours, mins, secs))
       
        elif mins >= 10:
            if hours < 10:
                print('0%s:%s:%s'%(hours, mins, secs))
            
            elif hours >= 10:
                print('%s:%s:%s'%(hours, mins, secs))

    secs += 1
    
    if secs == 60:
        
        secs = 0
        mins += 1
        
        if mins == 60:
            hours += 1
            mins = 0
            secs = 0
    
    time.sleep(1)
