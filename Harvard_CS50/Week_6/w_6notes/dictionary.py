#illustrates the implementation of speller in python

words = set()

def check(word):
    #you can ask if statements much more powerfully than in C, and thus you can simply as if a word exists in a set, rather than having to iterate through
    #.lower is a function built into strings that allows you compare to lowercase rather than having to make a word lowercase yourself
    if word.lower() in words:
        return True
    else:
        return False
    
def load(dictionary):
    file = open(dicitonar, "r")
    #for loops can work like this, allowing you to check each line in a file, rather than having to know the final value
    for line in file:
        #this function ads the line from the dictionary, but uses rstrip to strip a character starting from the last character, in this case "\n"
        words.add(line.rstrip("\n"))
    #closes file
    file.close
    return True
    
def size():
    #instantly finds the length of words in a file
    return len(words)
    
def unload():
    #python has garbage collection, and there's no need to free memory
    return True

    