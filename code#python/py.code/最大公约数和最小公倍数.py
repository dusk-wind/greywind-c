data = input()
numbers = data.split(',')
a = int(numbers[0])
b = int(numbers[1])
t = a*b
if a<b:a,b = b,a 
while (b):
    c = a%b
    a = b
    b = c
m = int(a)
n = int(t/m)
print("{},{}".format(m,n))