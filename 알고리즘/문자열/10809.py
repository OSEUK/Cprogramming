S = input()
lst = [-1 for i in range (ord('a'), ord('z') + 1)]
for i in range(len(S)):
    num = lst[ord(S[i]) - ord('a')]
    if num == -1:
        lst[ord(S[i]) - ord('a')] += i
for i in lst:
    print(i, end=" ")