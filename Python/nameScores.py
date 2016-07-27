def countScore(names)->int:
    score = 0
    index = 1
    for name in names:
        val = 0
        for ch in name:
            if ch != '"':
                val += ord(ch)-ord('A')+1
        val *= index
        score += val
        index += 1
    return score

def main():
    names = []
    f = open("names.txt",'r',-1,None,None,)
    for line in f:
        names.extend(line.split(','))
    names.sort()
    print(countScore(names))

main()
