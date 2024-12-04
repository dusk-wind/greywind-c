def cal(n):
    s = 0  
    h = 100  
    if n == 1:
        s = 100 
        h = 50
    else:
        s = 100 
        h = 50
        for i in range (1,n):
            s = s + 2*h
            h /= 2   
    return round(s,2)

n=int(input("n="))
print("第{}次落地时经过的距离:{}".format(n,cal(n)))
    
    