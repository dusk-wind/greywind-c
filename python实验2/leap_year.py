def isleap(year):
    isleap = False
    if ((year%4==0 and year%100!=0) or year%400==0):
        isleap = True
    return isleap

count = 0
for i in range (1949,2025):
   
    if isleap(i):
        print(i,end=" ")
        count += 1
        
    if count == 5:
        print()
        count = 0

    