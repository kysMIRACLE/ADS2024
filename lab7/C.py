n, m = map(int, input().strip().split())

first_person_numbers = list(map(int, input().strip().split()))
second_person_numbers = list(map(int, input().strip().split()))

common_numbers = set(first_person_numbers).intersection(second_person_numbers)

print(" ".join(map(str, sorted(common_numbers))))