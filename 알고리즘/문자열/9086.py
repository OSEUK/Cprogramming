num = int(input())
list = []
for i in range(num):
    str = input()
    list.append(str[0] + str[-1])

for j in list:
    print(j)