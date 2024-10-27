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
    
def ticking_music():
    music(3,1,1)#music(6,0,0.5)
    music(1,1,0.5)
    music(3,1,1)#music(6,0,0.5)
    music(1,1,0.5)
    music(3,1,1)#music(6,0,0.5)
    music(1,1,0.5)
    music(3,1,1)#music(6,0,0.5)
    music(1,1,0.5)
    music(3,1,1)#music(6,0,0.5)
    music(1,1,0.5)
    music(3,1,1)#music(6,0,0.5)
    music(4,1,0.5)
    music(6,0,0.5)#music(6,0,0.5)
    
    music(6,0,1)#music(3,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(1,1,1)#music(6,0,0.5),music(3,0,0.5)
    music(3,1,1)
    music(1,1,1)
    music(6,0,1)
    music(1,1,1)
    
    music(3,1,1)#music(6,0,0.5),music(3,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(1,1,1)
    music(6,0,0.5)#music(3,0,0.5)
    music(6,0,0.5)#music(3,0,0.5)
    music(1,1,1)
    music(3,1,1)#music(6,0,0.5),music(3,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(1,1,1)
    music(6,0,1)
    music(1,1,1)

    music(3,1,1)#music(6,0,0.5),music(3,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(4,1,1)
    music(6,0,0.5)#music(3,0,0.5)
    music(6,0,0.5)#music(3,0,0.5)
    
    music(6,0,1)#music(4,0,0.5),music(1,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(1,1,1)#music(4,0,0.5),music(1,0,0.5)
    music(3,1,1)
    music(1,1,1)
    music(6,0,1)
    music(1,1,1)
    music(4,0,0.5)#music(1,0,0.5)
    music(3,1,1)
    music(1,1,1)
    music(3,1,1)
    music(1,1,1)
    music(4,0,0.5)#music(1,0,0.5)
    music(6,0,1)#music(4,0,0.5),music(1,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(1,1,1)
    music(3,1,1)#music(4,0,0.5),music(1,0,0.5)
    music(1,1,1)
    music(6,0,1)
    music(1,1,1)

    music(3,1,1)#music(4,0,0.5),music(1,0,0.5)
    music(1,1,1)
    music(3,1,1)
    music(4,1,1)
    music(5,0,0.5)#music(1,0,0.5)
    music(5,0,0.5)#music(1,0,0.5)
 
ticking_music()
mid.save('ticking.mid')