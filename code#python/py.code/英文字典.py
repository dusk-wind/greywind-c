# 初始化一个空字典来保存词典数据
dictionary_data = {}

# 定义一个函数来处理用户输入
def process_input(user_input):
    # 将输入按照空格分割成列表
    input_list = user_input.split()
    
    # 根据输入的第一个词来判断用户想要执行的操作
    if len(input_list) == 0:
        return "Error Input"
    
    operation = input_list[0]
    
    if operation == "update":
        if len(input_list) != 3:
            return "Error Input"
        word = input_list[1]
        meaning = input_list[2]
        dictionary_data[word] = meaning
        return True
    
    elif operation == "delete":
        if len(input_list) != 2:
            return "Error Input"
        word = input_list[1]
        if word in dictionary_data:
            del dictionary_data[word]
            return True
        else:
            return False
    
    elif operation == "search":
        if len(input_list) != 2:
            return "Error Input"
        word = input_list[1]
        if word in dictionary_data:
            return dictionary_data[word]
        else:
            return "Not Found"
    
    elif operation == "quit":
        return None
    
    else:
        return "Error Input"

import sys
input_lines = sys.stdin.readlines()
for line in input_lines:
    line = line.strip()
    result = process_input(line)
    if result is not None:
        print(result)