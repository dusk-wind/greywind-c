def is_valid_move(maze, x, y, visited):
    """检查移动是否有效（在边界内且未访问过且是通路）"""
    rows, cols = len(maze), len(maze[0])
    return 0 <= x < rows and 0 <= y < cols and maze[x][y] == 0 and not visited[x][y]

def dfs(maze, x, y, visited, path, end_x, end_y):
    """深度优先搜索算法"""
    # 标记当前位置为已访问
    visited[x][y] = True
    path.append((x, y))
    
    # 检查是否到达终点
    if x == end_x and y == end_y:
        return True
    
    # 尝试四个方向的移动：右、下、左、上
    moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    for move in moves:
        new_x, new_y = x + move[0], y + move[1]
        if is_valid_move(maze, new_x, new_y, visited):
            if dfs(maze, new_x, new_y, visited, path, end_x, end_y):
                return True
    
    # 如果所有方向都不可行，回溯
    path.pop()
    visited[x][y] = False
    return False

def solve_maze(maze, start, end):
    """解决迷宫问题"""
    rows, cols = len(maze), len(maze[0])
    visited = [[False for _ in range(cols)] for _ in range(rows)]
    path = []
    
    if dfs(maze, start[0], start[1], visited, path, end[0], end[1]):
        return path
    else:
        return None  # 无解

# 示例迷宫（0表示通路，1表示障碍）
maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

# 起点和终点
start = (0, 0)
end = (4, 4)

# 求解迷宫
solution = solve_maze(maze, start, end)

if solution:
    print("解决方案:")
    for step in solution:
        print(step,end="->")
print("到达终点")
