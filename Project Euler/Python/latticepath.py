def lattice_path(n):
    list = []
    list.append(1)
    for i in range(1,n+1):
        for j in range(1,i):
           list[j] += list[j-1]
        list.append(list[-1]*2)
    return list[-1]

def main():
    size = int(input("Enter Grid Size : "))
    path_count = lattice_path(size)
    print("Total Possible Paths : {0}".format(path_count))

main()
