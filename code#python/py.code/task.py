#a,b=12,5
#print('{}+{}={}'.format(a,b,a+b))
#print('{}-{}={}'.format(a,b,a-b))
#print('{}*{}={}'.format(a,b,a*b))
#print('{}/{}={}'.format(a,b,a/b))
#print('{}%{}={}'.format(a,b,a%b))
'''
C=37.2
F=C*9/5+32
print("{:.2f}".format(F))
'''
'''
a=input()
b=a[::-1]
print(b)
'''
'''
minutes=int(input())
years=minutes//(365*24*60)
remaining_minutes=minutes%(365*24*60)
days=remaining_minutes//(24*60)
remaining_minutes=remaining_minutes%(24*60)
hours=remaining_minutes//60
remaining_minutes=remaining_minutes%60
print("{}minutes={}years,{}days,{}hours,{}minutes".format(minutes,years,days,hours,remaining_minutes))
'''
'''
year=int(input())
if ((year%4==0) and (year%100!=0)) or (year%400==0):
    print("{} is leap year.".format(year))
else:
    print("{} is not leap year.".format(year))
'''
import turtle
import math

# 接受用户输入的半径
r = float(input("请输入圆的半径: "))

# 计算五角星的边长
# 五角星的一个内角是36度，因此我们可以使用cos(36度)来找到边长和半径的关系
theta = math.radians(36)  # 将角度转换为弧度
b = 2 * r * math.cos(theta)  # 计算边长

# 使用turtle绘制五角星
window = turtle.Screen()  # 创建绘图窗口
window.bgcolor("white")  # 设置背景颜色

pentagon = turtle.Turtle()  # 创建一个turtle对象来绘制五角星
pentagon.speed(1)  # 设置绘制速度
pentagon.penup()  # 抬起笔，移动到第一个顶点

# 计算五角星的顶点坐标
# 五角星顶点均匀分布在圆上，因此我们可以通过角度和半径来计算它们的坐标
angles = [math.radians(i * 144) for i in range(5)]  # 计算每个顶点的角度（以弧度为单位）
coordinates = [(r * math.cos(angle), r * math.sin(angle)) for angle in angles]  # 计算每个顶点的坐标

# 绘制五角星
pentagon.goto(coordinates[0])  # 移动到第一个顶点
pentagon.pendown()  # 放下笔，开始绘制
for coord in coordinates[1:]:
    pentagon.goto(coord)  # 依次移动到其他顶点，绘制五角星
pentagon.goto(coordinates[0])  # 回到第一个顶点，完成五角星

# 输出计算得到的边长
print(f"计算得到的五角星边长为: {b:.2f}")

# 关闭turtle窗口的点击事件
window.exitonclick()