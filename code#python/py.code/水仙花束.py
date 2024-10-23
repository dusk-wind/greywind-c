'''
for i in range(100,1000):
    s=str(i)
    if int(s[0])**3+int(s[1])**3+int(s[2])**3==i:
         print(i)
'''
 
'''
n = 0
for i in range(2,101):
    count = 0
    for j in range(2,i):
        if i%j == 0:
            break
        else:
            count += 1
    if count > i-3:
        n += 1
        if n % 5 == 0:
            print(i)
        else:
            print(i,end=" ")
'''
'''
num=input("请输入一个数:")
if num==num[::-1]:
    print(num,end=" "),print("is a palindrome number.")
else:
   print(num,end=" "),print("is not a palindrome number.")
'''
'''
num=input("请输入一个需要判断的整数：")
if num[::-1]==num:
    print("%s is a palindrome number."%num)
else:
    print("%s is not a palindrome number."%num)
'''
#print("{:3}".format(num),end="")
'''
n = 0  
for num in range(2, 101): 
    is_prime = True  
    for j in range(2, int(num ** 0.5) + 1): 
        if num % j == 0:
            is_prime = False  
            break  
    
    if is_prime:  
        n += 1  
        print("{:3}".format(num),end="")
        if n % 5 == 0:  
            print() 
'''
'''
print("* * * * * * *")
print("  * * * * *  ")
print("    * * *    ")
print("      *      ")
'''
'''
def main():
    n = input()
    numbers = [int(num.strip()) for num in n.split(',')]
    minimum_value = min(numbers)
    print(minimum_value)

if __name__ == "__main__":
    main()
'''
'''
day=int(input())
if (day==1):
    print("Monday")
elif (day==2):
    print("Tuesday")
elif (day==3):
    print("Wednesday")
elif (day==4):
    print("Thursday")
elif (day==5):
    print("Friday")
elif (day==6):
    print("Saturday")
elif (day==7):
    print("Sunday")
'''
'''
count=0
for i in range (10,51):
    if (i%3==0):
        count+=1
        if (count%5!=0):
            print(i,end=" ")
        elif (count%5==0):
            print(i)
'''
height=4
for i in range (height, 0 , -1):
    for j in range(height-i):
        print('  ',end='')
    for k in range(2*i-1):
        if k<2*i-2:
            print('*',end=' ')
        if k==2*i-2:
            print('*',end='')
    print()