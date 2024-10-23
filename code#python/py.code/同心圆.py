#导入模块
from turtle import *
from random import *
#画六个同心圆
for i in range(6):
    begin_fill()#准备填色
    penup()#提起画笔
    goto(0, 20*(i+1)) #从底部开始画圆，每个圆起始点向上移动20
    fillcolor((random(), random(), random()))#随机选取颜色并填色,rgb用0-1之间小数表示
    pendown()#落下画笔
    circle(150-20*(i+1))#画圆，半径每次减少20
    end_fill()#完成填色
mainloop()#事件循环