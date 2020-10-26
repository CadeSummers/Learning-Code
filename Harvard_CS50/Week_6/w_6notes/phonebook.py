#shows how to use and work with files in python
#this file creates a phonebook by appending to a pre-existing csv

#importing this package makes working with csv much easier
import csv

file = open("phonebook.csv", "a")

name = input("Name: ")
number = input("Number: ")

#this statement passes the file through the csv library so that it will be easier to work with
writer = csv.writer(file)

#this statement writes a name and a number to the file "writer", which initially came from phonebook.csv
writer.writerow((name, number))

file.close()