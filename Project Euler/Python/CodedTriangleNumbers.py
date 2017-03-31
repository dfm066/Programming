import csv

maxlen = 14
tri_limit = 26 * maxlen
tri_nums = {}
n = 1
while True :
    val = n*(n+1)//2
    if val <= tri_limit:
        tri_nums[val] = True
        n += 1
    else:
        break

with open('p042_words.txt', 'r') as wordfile:
    reader = csv.reader(wordfile)
    count = 0
    for words in reader:
        for word in words:
            val = 0
            for char in word:
                val += ord(char) - ord('A') + 1
            if tri_nums.get(val) is not None:
                count += 1
    print(count)