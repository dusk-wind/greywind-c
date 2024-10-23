'''
def is_prime(num):
    for factor in range(2, int(num ** 0.5) + 1):
        if num % factor == 0:
            return False
    return True if num != 1 else False
i=4
count = 0
while(i<=2000):
    for j in range (1,i):
            if is_prime(j) and is_prime(i-j) :
                print("{}={}+{} ".format(i,j,i-j),end=' ')
                count += 1
                if count % 6 == 0:
                    print()
                i += 2 
                break     
'''               


def is_prime(n):
    for factor in range(2, int(n ** 0.5) + 1):
        if n % factor == 0:
            return False
    return True if n != 1 else False


count = 0  
for even_num in range(4, 2001, 2): 
    for prime in range(2, even_num): 
        if is_prime(prime) and is_prime(even_num - prime):  
            print("{}={}+{}".format(even_num,prime,even_num-prime), end=' ')
            count += 1
            if count % 6 == 0:
                print()
            break
if count % 6 != 0:
    print()
