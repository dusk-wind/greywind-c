scores = {
    'Tom': {'Chinese': 95, 'Math': 98},
    'Jack': {'Chinese': 85, 'Math': 85},
    'Jerry': {'Chinese': 56, 'Math': 36},
    'Rose': {'Chinese': 87, 'Math': 85},
    'Mary': {'Chinese': 97, 'Math': 95}
}

chinese_scores = [scores[student]['Chinese'] for student in scores]
math_scores = [scores[student]['Math'] for student in scores]

chinese_avg = round(sum(chinese_scores) / len(chinese_scores), 1)
math_avg = round(sum(math_scores) / len(math_scores), 1)

print("The Chinese average score is {}".format(chinese_avg))
print("The Math average score is {}".format(math_avg))

failed_students = [student for student in scores if scores[student]['Chinese'] < 60 and scores[student]['Math'] < 60]
failed_students_sorted = sorted(failed_students)
failed_students_str = ','.join(failed_students_sorted) if failed_students_sorted else 'None'
print("Students failed in both courses are:{}".format(failed_students_str))

high_avg_students = [student for student in scores if (scores[student]['Chinese'] + scores[student]['Math']) / 2 > 90]
high_avg_students_sorted = sorted(high_avg_students)
high_avg_students_str = ','.join(high_avg_students_sorted) if high_avg_students_sorted else 'None'
print("Students with average scores of more than 90 in the two courses are:{}".format(high_avg_students_str))
