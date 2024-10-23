
import math
r=float(input())
b=round(math.sqrt(r*r*((1-math.cos(math.radians(72)))/(1-math.cos(math.radians(108))))),2)
print(b)
'''
import turtle
import math
r = float(input())
window = turtle.Screen()
window.bgcolor("white")
star = turtle.Turtle()
star.speed(1)
star.penup()
angles = [math.radians(i * 144) for i in range(5)]
coordinates = [(r * math.cos(angle), r * math.sin(angle)) for angle in angles]

# 绘制五角星（为了可视化）
star.goto(coordinates[0])
star.pendown()
for coord in coordinates[1:]:
    star.goto(coord)
star.goto(coordinates[0])
'''
theta = math.radians(36)  # 将36度转换为弧度
b = r * math.sqrt(2 - 2 * math.cos(theta))  # 计算小边长
'''
b=math.sqrt(r*r*((1-math.cos(math.radians(72)))/(1-math.cos(math.radians(108)))))
# 输出计算得到的小边长
print(f"{b:.2f}")

# 关闭turtle窗口的点击事件
window.exitonclick()
'''