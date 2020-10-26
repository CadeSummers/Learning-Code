#implements readability in python rather than c
from math import floor
#implement an index for characters (c) and two variables for sentences and words all set to 0
c = sentences = letters = words = 0

text = (input("Enter a piece of text: "))

n = len(text)

while c < n: 
    
    if text[c] == " ":
        words+=1
    elif text[c] in ['!', '?', '.']:
        sentences+=1
        #words+=1
        #checks for elipses and reduces sentence count if found. Works because in english no other character exists between two periods but another period
        if text[c] and text[c - 2] == '.': 
            sentences-=1
    else:
        #check for grammar marks (that are always followed by spaces), and does not increment letter count for them
        if text[c] not in [',', ':', ';']:
            letters+=1

    c+=1

#print(f"letters: {letters}")
#print(f"words: {words}")
#print(f"sentences: {sentences}")

avglet = round(letters/words, 2)

avgsents = round(sentences/words, 2)

letperh = avglet * 100

sentperh = avgsents * 100

index = floor(0.0588 * letperh - 0.296 * sentperh - 15.8)

#print(f"Index = {letperh} * 0.0588 - 0.296 * {sentperh} - 15.8")
#print(f"Index = {index}")

if index < 1:
    print("Before Grade 1")
    
elif index >= 16:
    print("Grade 16+")
    
else:    
    print(f"Grade {index}")
