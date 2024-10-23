student={}
while True:
    line=input()
    if line == "":
        break
    name,age=line.strip().split(',')
    age=int(age)
    student[name]=age

a=max(student,key=student.get)
print(a)