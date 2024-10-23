'''
weight=float(input("请输入体重(kg):"))
height=float(input("请输入身高(m):"))
BMI=round(weight/height**2,1)
print("BMI值为:{}".format(BMI))
if BMI<0:print("数据错误!\n")
if BMI<18.5:print("体重过轻\n")
if 18.5<=BMI<=23.9:print("正常\n")
if 24.0<=BMI<=27.9:print("超重\n")
if 28.0<=BMI<=31.9:print("肥胖\n")
if BMI>=32:print("重度肥胖\n")
'''
'''
num=input("请输入一个数:")
if num==num[::-1]:
    print(f"{num}是一个回文数")
else:
    print(f"{num}不是一个回文数")
'''
'''
import random
sum=0
for i in range (0,10):
    for i in range (0,10):
        number=random.randint(0,100)
        print(number,end=',' )
        sum=sum+number
    print('\n')
average=round(sum/100,1)
print("平均值为:{}".format(average))
'''
'''
for i in range (2,1001):
    t=i
    for j in range (1,i):
        if i%j==0:
            t=t-j
    if t==0:
        print(i)
'''

money=100
sum=0
for x in range(21):
    for y in range(34):
        for z in range(301):
            sum=5*x+3*y+z/3
            if sum==money and x+y+z==100:
                print("大鸡:{}只，中鸡:{}只，小鸡:{}只".format(x,y,z))

    