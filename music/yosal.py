import mido


mid = mido.MidiFile()
track = mido.MidiTrack()
mid.tracks.append(track)

#bpm = \frac{60000000}{tempo}
def music(note,base_num,base_time):
    
    #meta_time = 60 * 60 * 10 / bpm
    major_notes = [0, 2, 2, 1, 2, 2, 2, 1]
    base_note = 60
    track.append(mido.Message('note_on', note=base_note+base_num*12 + sum(major_notes[0:note]), velocity=96, time=0,channel=1))
    track.append(mido.Message('note_off', note=base_note+base_num*12 + sum(major_notes[0:note]), velocity=96, time=int(480*base_time),channel=1))
    #track.append(mido.Message('note_on', note=base_note, velocity=96, time=0))
    #track.append(mido.Message('note_off', note=base_note, velocity=96, time=480*base_time))
    
def a_music():
    music()
    
    
a_music()

mid.save('a.mid')