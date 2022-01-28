from sys import argv, exit
import csv, re

# Quit if more or less than 3 arguments
# else, assing each to data and seq
nums = []

if not len(argv) == 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
else:
    data = argv[1]
    seq = argv[2]

# Read the 2 of them into memmory
dataSEQ = open(seq, "r")
readSEQ = dataSEQ.read()

with open(data, "r") as dataCSV:
    readCSV = csv.reader(dataCSV)
    # While the csv file is open, copy those values into a list to use
    countsV = [i for i in readCSV]

# Count SRTs
def countingSEQ(string):
    count = 0
    maxim = 0
    verdad = False
    n = 0

    for i in range(0, len(readSEQ)):
        while verdad:
            n += 1
            if n == len(string):
                verdad = False
                n = 0
            else:
                continue

        if re.search(string, readSEQ[i : i + len(string)]):
            count += 1
            while re.search(string, readSEQ[i - len(string) : i]):
                count += 1
                i -= len(string)
        else:
            count = 0
            continue
        if count > maxim:
            maxim = count
        else:
            count = 0
    nums.append(str(maxim))

# Avoid "name" excepting index 0
for i in range(1, len(countsV[0])):
    countingSEQ(countsV[0][i])

for j in range(len(countsV)):
    if nums == countsV[j][1:]:
        print(countsV[j][0])
        exit(0)
print("No match")
exit(1)