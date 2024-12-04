def count_str(str1):
    words = str1.split()
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
            
    for word, count in word_count.items():
        print(f"{word} {count}")
        
input_string = "Python C++ Java PHP Python Java Go Java"
count_str(input_string)