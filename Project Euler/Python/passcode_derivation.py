keys = []
passcode = 
keylog = open('keylog.txt')
for lines in keylog:
    keys.append(lines[:-1])
print(keys)