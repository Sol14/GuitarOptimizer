#!/usr/bin/python
import sys
from Models import Chord

chord_path = sys.argv[1]
song_path = sys.argv[2]

chord_list = open(chord_path)
song_chords = open(song_path)


chord_data = {}
song_data = []

#Chord data creation
print("Loading data: ")
for line in chord_list:
    line = line.rstrip()
    metadata = line.split(",")
    for i in range(1, len(metadata)):
        if not metadata[i]:
            metadata[i] = 0
        metadata[i] = int(metadata[i])
    chord = Chord(metadata[0], metadata[1:len(metadata)])
    chord_data.update({chord.label : chord})

print("Loading song: ")
for line in song_chords:
    line = line.rstrip()
    song_data.append(Chord(chord_data[line]))
