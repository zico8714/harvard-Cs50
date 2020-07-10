from cs50 import SQL
from sys import argv, exit
import csv, re

if len(argv) != 2:
    print("nonononono milady")
    exit(1)
else:
    rstr = argv[1]

db = SQL("sqlite:///students.db")

selected = db.execute("SELECT first, middle, last, house, birth FROM students WHERE house = ? ORDER BY last, first", rstr)

for row in selected:
    if row["middle"] == "NULL":
        print(row["first"]," ", row["last"],", born ", row["birth"], sep='')
    else:
        print(row["first"]," ", row["middle"], " ",  row["last"],", born ", row["birth"], sep='')
