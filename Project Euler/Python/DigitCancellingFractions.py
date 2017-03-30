prodNu = 1
prodDe = 1

for nu in range(10, 100):
    for de in range(10, 100):
        flg = False
        if nu%10 != 0 and de % 10 != 0 and nu != de and nu < de:
            if nu % 10 == de % 10:
                if (nu//10)/(de//10) == nu/de:
                    flg = True
                    print("1 : {0}/{1}".format(nu, de))
            elif nu % 10 == de//10:
                if (nu//10)/(de%10) == nu/de:
                    flg = True
                    print("2 : {0}/{1}".format(nu, de))
            elif nu//10 == de//10:
                if (nu % 10)/(de % 10) == nu/de:
                    flg = True
                    print("3 : {0}/{1}".format(nu, de))
            elif nu//10 == de%10:
                if (nu % 10)/(de//10) == nu/de:
                    flg = True
                    print("4 : {0}/{1}".format(nu, de))
        if flg:
            prodNu *= nu
            prodDe *= de
print("fraction is : {0}/{1}".format(prodNu,prodDe))
