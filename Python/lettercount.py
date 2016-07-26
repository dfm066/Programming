def letter_count():
    h = 7
    unit = [0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8]
    tens = [0,0,6,6,5,5,5,7,6,5]
    sum  = 0
    for i in range(1, 100):
        if 1 <= i < 19:
            sum += unit[i]
        elif 20 <= i <= 99:
            ten, below_ten = divmod(i, 10)
            sum += tens[ten]+ unit[below_ten]
        print(sum,i)
    sum = sum * 10
    sum += 3*99*9
    for i in unit:
        sum += i*100
    sum += h *900
    sum += 11
    return sum

print(letter_count())


# num2words1 = {0:'',1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five',
#             6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten',
#             11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen',
#             15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
# num2words2 = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

# def number(Number):
#     if 1 <= Number < 19:
#         return num2words1[Number]
#     elif 20 <= Number <= 99:
#         tens, below_ten = divmod(Number, 10)
#         return num2words2[tens - 2] + '-' + num2words1[below_ten]
#     else:
#         print("Number out of range")
# def main():
#     for i in range(1,100):
#         number(i)
# main()