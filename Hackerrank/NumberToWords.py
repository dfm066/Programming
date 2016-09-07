num2words1 = {0:'',1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five',
            6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten',
            11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen',
            15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
num2words2 = ['','','Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
num2words3 = ['Hundred','','Thousand','Million','Billion','Trillion']

def number_to_words(num):
    if(int(num) == 0):
        return 'Zero'
    parts = '0000000000000'
    fill = 12
    limit = len(num) - 1
    ans = ''
    for i in range(limit,-1,-1):
        parts = parts[:fill] + num[i] + parts[fill+1:]
        fill -= 1
    k = 5
    i = 0
    if int(parts[i]) > 0:
        ans += num2words1[int(parts[0])] + ' ' + num2words3[k] + ' '
    i += 1
    k -= 1
    while i < 11:
        if int(parts[i]) > 0:
            ans += num2words1[int(parts[i])] + ' ' + num2words3[0] + ' '
        i += 1
        mid = int(parts[i])* 10 + int(parts[i+1])
        i += 2
        if 1 <= mid <= 19:
            ans += num2words1[mid] + ' ' + num2words3[k] + ' '
        elif mid > 19:
            ans += num2words2[mid//10] + ' '
            if(mid %10 > 0):
                ans += num2words1[mid%10] + ' '
            ans += num2words3[k] + ' '
        k -= 1
    return ans[:-2]


def main():
    t = int(input())
    while t > 0:
        t -= 1
        n = input()
        print(number_to_words(n))
main()
