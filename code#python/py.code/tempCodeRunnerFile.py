def cal(n):
    h = 100
    s=0
    for i in range (n):
        s += h
        h /= 2
    return (s+100),h

if __name__ ==  "__main__":
    n=(int(input()))   
    s,h=cal(n)
    print("Total of road is {:.4f} meter".format(s))
    print("Total of road is {:.4f} meter".format(h))