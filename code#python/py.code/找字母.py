sentence = input()
letter_count = {}
for char in sentence:
    if char.isalpha():
        lower_char = char.lower()
        if lower_char in letter_count:
            letter_count[lower_char] += 1
        else:
            letter_count[lower_char] = 1

most_common_letter = max(letter_count, key=letter_count.get)
print(most_common_letter)