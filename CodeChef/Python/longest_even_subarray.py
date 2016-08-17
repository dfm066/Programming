def main():
    T = int(input())
    while T > 0:
        T -= 1
        n = int(input())
        num = list(map(int, input().split()))
        max_sum = sum(num)
        if max_sum%2==0:
            max_len = n
        else:
            flg = True
            for max_len in range(n-1,0,-1):
                for i in range(0, n-max_len+1):
                    curr_sum =  max_sum - (sum(num[0:i])+sum(num[max_len+i:n]))
                    if curr_sum % 2 == 0:
                        flg = False
                        break
                if flg == False:
                    break
        print(max_len)
main()
