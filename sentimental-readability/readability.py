from cs50 import get_string

text = get_string("Text: " )

num_spaces = text.count(" ")
num_inter = text.count(".") + text.count("?") + text.count("!")
num_letters = 0

for char in text:
    if char.isalpha():
        num_letters += 1

L = (num_letters/len(text.split())) * 100
S = ((num_inter/num_spaces)*100)

score = 0.0588 * L - 0.296 * S - 15.8

if score < 1:
    print("Before Grade 1")
elif score > 16:
    print("Grade 16+")
else:
    print("Grade: " + str(round(score)))
