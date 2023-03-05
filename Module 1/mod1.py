import sys

obj = []

chordRoots = {
    "F": 0,
    "G": 1,
    "A": 2,
    "Bb": 3,
    "B": 4,
    "C": 5,
    "Db": 6,
    "D": 7
}

chordTypes = {
    "": 0,
    "/A": 1,
    "dim": 2,
    "m6": 3,
    "add4": 4,
    "m7": 5,
    "7": 6,
    "m7b5": 7,
    "7sus": 8,
    "7#5": 9,
    "7#9": 10,
    "m9": 11,
    "9": 12,
    "Maj9": 13,
    "Maj9/A": 14,
    "m11": 15
}

file = open(sys.argv[1], 'r')
for line in file.readlines():
    lineArr = line.strip('\n').split('\t')
    if len(lineArr) == 2:
        struct = {
            "time": lineArr[0],
            "word": lineArr[1],
            "chordRoot": -1,
            "chordType": -1
		}
        obj.append(struct)
    else:
        struct = {
            "time": lineArr[0],
            "word": lineArr[1],
            "chordRoot": chordRoots[lineArr[2]],
            "chordType": chordTypes[lineArr[3]]
		}
        obj.append(struct)

for i in range(len(obj) - 1):
    print("{")
    print(f'\tletters: "{obj[i]["word"]}",')
    print(f'\tchordRoot: {obj[i]["chordRoot"]},')
    print(f'\tchordModifier: {obj[i]["chordType"]},')
    timeEnd = obj[i+1]["time"].split(":")
    timeStart = obj[i]["time"].split(":")
    length = (int(timeEnd[0]) - int(timeStart[0])) * 60000 # minutes
    length += (int(timeEnd[1]) - int(timeStart[1]) % 60) * 1000 # seconds
    length += (int(timeEnd[2]) - int(timeStart[2]) % 25) * 40 # subdivision
    length += (int(timeEnd[3]) - int(timeStart[3]) % 8) * 5 # smallest subdivision
    print(f'\tlen: {length}')
    print("},")