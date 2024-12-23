import turtle
turtle.speed(1)
turtle.up()
turtle.goto(-200,200)
turtle.down()
turtle.pensize(0)
#绘制上方三角形
turtle.color("#caff67")
turtle.begin_fill()
turtle.goto(200,200)
turtle.home()
turtle.goto(-200,200)
turtle.end_fill()
#绘制左方大三角形
turtle.color("#67becf")
turtle.begin_fill()
turtle.goto(-200,-200)
turtle.home()
turtle.end_fill()
#绘制中间小三角形
turtle.color("#f9f51a")
turtle.begin_fill()
turtle.goto(100,100)
turtle.goto(100,-100)
turtle.end_fill()
#绘制右边平行四边形
turtle.color("#ef3d61")
turtle.begin_fill()
turtle.goto(100,100)
turtle.goto(200,200)
turtle.goto(200,0)
turtle.end_fill()
#绘制右下三角形
turtle.color("#f6ca29")
turtle.begin_fill()
turtle.goto(200,-200)
turtle.goto(0,-200)
turtle.end_fill()
#绘制下方正方形
turtle.color("#a594c0")
turtle.begin_fill()
turtle.goto(100,-100)
turtle.goto(0,0)
turtle.goto(-100,-100)
turtle.end_fill()
#绘制左下三角形
turtle.color("#fa8ecc")
turtle.begin_fill()
turtle.goto(0,-200)
turtle.goto(-200,-200)
turtle.end_fill()
#绘制完毕
turtle.hideturtle()
turtle.done()