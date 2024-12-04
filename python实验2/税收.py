def tax(n):
    if n<=0:
        print("数据错误！")
        return None
    if n<=36000:
        return n*0.03
    if n<=144000:
        return n*0.1-2520
    if n<=300000:
        return n*0.2-16920
    if n<=420000:
        return n*0.25-31920
    if n<=660000:
        return n*0.3-52920
    if n<=960000:
        return n*0.35-85920
    else:
        return n*0.45-181920
    
if __name__ == "__main__":
    n=float(input("应纳税所得额:"))
    print("个人所得税:{}".format(tax(n)))