'''
def product(n):
    if n%2==0 and n%3==0 and n%5==0:
        return True
    else:
        return False

def find(limit):
    result=[]
    factor=[]
    for i in range (30,limit+1):
        if product(i):
            while i%2==0:
                factor.append(2)
                i//=2
            while i%3==0:
                factor.append(3)
                i//=3
            while i%5==0:
                factor.append(5)
                i//=5    
            factor.sort()
            result.append("{}={'*'.join(map(str,factor))}".format(i))
    return result


limit=int(input())
print('\n'.join(find(limit)))
'''
def get_factors(n):
    factors = []
    if n % 2 == 0 and n % 3 == 0 and n % 5 == 0:
        if n % 2 == 0:
            while n % 2 == 0:
                factors.append(2)
                n //= 2
        if n % 3 == 0:
            while n % 3 == 0:
                factors.append(3)
                n //= 3
        if n % 5 == 0:
            while n % 5 == 0:
                factors.append(5)
                n //= 5
    return factors if n == 1 else []
def find(limit):
    result = []
    for i in range(30, limit + 1):
        factors = get_factors(i)
        if factors:  # 只有当 factors 非空时（即 i 能被 2, 3, 5 整除时）
            factors.sort()
            result.append("{}={}".format(i, '*'.join(map(str, factors))))
    return result

limit = int(input())
print('\n'.join(find(limit)))