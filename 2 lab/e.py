n = int(input())
students = []
for i in range(n):
    s = input()
    if s not in students:
        students.append(s)
print("All in all: ", len(students))
print("Students:")
students.sort()
for i in students:
    print(i)