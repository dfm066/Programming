num2words1 = {0:'',1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five',
            6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten',
            11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen',
            15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
num2words2 = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
num2words3 = 'Hundred'
num2words4 = 'Thousand'
num2words5 = 'And'

def number(Number):
    if 1 <= Number <= 19:
        return num2words1[Number]
    elif 20 <= Number <= 99:
        tens, below_ten = divmod(Number, 10)
        return num2words2[tens - 2] + num2words1[below_ten]
    else:
        return ''

def main():
    sum = 0
    for i in range(1, 1001):
        no_words = ''
        if i // 1000 > 0:
            no_words += number(i // 1000)
            no_words += num2words4
            i %= 1000
        if i // 100 > 0:
            no_words += number(i // 100)
            no_words += num2words3
            if i % 100 > 0:
                no_words += num2words5
            i %= 100
        if i % 100 > 0:

            no_words += number(i % 100)

        print(no_words, len(no_words))
        sum += len(no_words)
    print (sum)
main()
