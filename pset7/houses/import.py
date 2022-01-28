from cs50 import SQL
from sys import argv, exit
import csv, re

if len(argv) != 2:
    print("nonononono milady")
    exit(1)
else:
    csvfile = argv[1]

db = SQL("sqlite:///students.db")

with open(csvfile, "r") as file:
    readCSV = csv.DictReader(file)

    for line in readCSV:
        nombre = line["name"].split()
        if len(nombre) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
            nombre[0], nombre[1], nombre[2], line["house"], line["birth"])
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
            nombre[0], "NULL", nombre[1], line["house"], line["birth"])
