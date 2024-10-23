n=int(input())
list=[1,1]
for _ in range (2,n+1):
    temp = int(list[-2])+int(list[-1])
    list.append(temp)
print(list[n])
list.clear