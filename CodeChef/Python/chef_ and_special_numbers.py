rules = {2:'02468',5:'05',}
def main():
    T = int(input())
    while T > 0:
        T -= 1
        numbers = list(map(int, input().split()))
        K = numbers[2]
        A = numbers[0]
        B = numbers[1]
        spcl = 0
        numbers.clear()
        if K==2:
            for i in range(A, B + 1):
                num = str(i)
                if num.find('0')==-1 and num.find('2')==-1 and num.find('4')==-1 and num.find('6')==-1 and num.find('8')==-1:
                    spcl += 1
        elif K==5:
            for i in range(A, B + 1):
                num = str(i)
                if num.find('0') == -1 and num.find('5')==-1:
                    spcl += 1
        else:
            for i in range(A,B+1):
                num = str(i)
                flg = True
                limit = len(num)
                for j in range(limit):
                    for k in range(j,limit):
                        new = int(num[j:k+1])
                        if new % K == 0:
                            flg = False
                            break
                    if flg == False:
                        break
                if flg == True:
                    spcl += 1
        print(spcl)
main()
