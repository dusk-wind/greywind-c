#用turtle绘制图案小房子
#注：图片颜色随机
import turtle
turtle.speed(1)
turtle.up()
turtle.goto(-70.71,141.42)
turtle.down()
turtle.pensize(0)
#颜色从这些颜色中依次选择
color=["#caff67","#67becf","#f9f51a","#f6ca29","#fa8ecc","#a594c0","#ef3d61"]
#首先收集正方形、平行四边形和两个三角形各点坐标
M=[[(0,141.42),(0,70.71),(-70.71,70.71)],
   [(-135.35,0),(-70.71,0),(0,70.71)],
   [(29.29,100),(129.29,0),(-70.71,0)],
   [(-100,0),(-100,-100),(0,0)]]
#然后是收集剩余的三个三角形各点坐标
N=[[(-100,-100),(100,-100)],[(100,0),(50,-50)],[(100,0),(0,0)]]
#绘制正方形、平行四边形和两个三角形
def drawcircle(m1,n1,k,color):
    turtle.color(color)
    turtle.begin_fill()
    turtle.goto(m1)
    turtle.goto(n1)
    turtle.goto(k)
    turtle.end_fill()
for i in range(4):
    drawcircle(M[i][0],M[i][1],M[i][2],color[i])
#绘制剩余的三个三角形
def drawcircle2(m2,n2,color):
    turtle.color(color)
    turtle.begin_fill()
    turtle.goto(m2)
    turtle.goto(n2)
    turtle.end_fill()
for i in range(3):
    drawcircle2(N[i][0],N[i][1],color[i+4])
#绘制完毕
turtle.hideturtle()
turtle.done()