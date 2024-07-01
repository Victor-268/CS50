from cs50 import get_int

while True:
    number = get_int("Height: ")
    if 0 < number < 9:
        break
    else:
        print("number above 0 please")

for i in range(1, number+1):
    print(" " * (number-i), end='')
    print("#" * i, end='')
    print("  ", end='')
    print("#" * i)
