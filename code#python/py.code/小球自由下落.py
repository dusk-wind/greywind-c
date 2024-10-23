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
           
          
    return round(s,4),round(h,4)

if __name__ == "__main__":
    n = int(input())
    s,h= cal(n)  
    print("Total of road is {} meter".format(s))
    print("The height is {} meter".format(h))