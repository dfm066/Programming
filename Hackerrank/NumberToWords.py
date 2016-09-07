num2words1 = {0:'',1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five',
            6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten',
            11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen',
            15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
num2words2 = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
num2words3 = 'Hundred'
num2words4 = 'Thousand'
num2words5 = 'Million'
num2words6 = 'Billion'
num2words7 = 'Trillion'

def number_to_words(num):
    parts = '0000000000000'
    fill = 12
    limit = len(num) - 1
    ans = ''
    for i in range(limit,-1,-1):
        parts = parts[:fill] + num[i] + parts[fill+1:]
        fill -= 1
    if parts[0] > '0':
        ans += num
    print(parts)
def main():
    t = int(input())
    while t > 0:
        t -= 1
        n = input()
        number_to_words(n)
        # print(number_to_words(n))
main()
