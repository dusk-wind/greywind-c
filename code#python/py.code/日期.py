def leap_year(year):
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
        return True
    return False

def cal(year,month,day):
    total = 0
    list1=[31,28,31,30,31,30,31,31,30,31,30,31]
    list2=[31,29,31,30,31,30,31,31,30,31,30,31]
    for i in range (month-1):
        if leap_year(year):
            total += list2[i]
        else:
            total += list1[i]  
       
    return total+day
        
if __name__ == "__main__":
    data=input()
    value = data.split(',')
    year = int(value[0])
    month = int(value[1])
    day = int(value[2])
    date=cal(year,month,day)
    print(date)