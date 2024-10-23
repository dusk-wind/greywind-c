import matplotlib.pyplot as plt

# 用户预定义的数据（这里以示例数据为准，实际数据应根据实验测量得到）
# 电压（V）
voltage = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
# 电流（A），注意这里的电流值是根据电压变化而模拟的，实际数据会有所不同
current = [0.1, 0.1, 0.1, 0.1, 0.4, 0.1, 0.1, 0.15, 0.1, 0.6, 0.1, 0.1, 0.2, 0.1, 0.8, 0.1, 0.1, 0.25, 0.1, 0.1, 1.0]

# 绘制弗兰克-赫兹曲线图
plt.figure(figsize=(10, 6))
plt.plot(voltage, current, label='弗兰克-赫兹曲线图', marker='o')

# 添加标题和标签
plt.title('弗兰克-赫兹曲线图')
plt.xlabel('电压(V)')
plt.ylabel('电流(10^(-7)*A)')

# 添加网格线
plt.grid(True)

# 添加图例
plt.legend()

# 显示图形
plt.show()