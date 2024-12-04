def avgScore(*paras):
    averages = []
    for para in paras:
        total_score = sum(para)
        num_courses = len(para)
        average = round(total_score / num_courses, 1)
        averages.append(average)
    return averages

student1 = [81, 95, 76, 90]
student2 = [61, 57, 42, 75, 80, 68]
student3 = [97, 95, 93, 95, 88]
scores_averages = avgScore(student1, student2, student3)
for i, average in enumerate(scores_averages, 1):
    print(f"学生{i}的平均分是: {average}")
    