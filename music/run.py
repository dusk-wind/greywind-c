import pygame
import sys

pygame.mixer.init()
#midi_file = 'lemon.mid'
#midi_file = 'ticking.mid'
midi_file = 'yosal.mid'
pygame.mixer.music.load(midi_file)
pygame.mixer.music.play()
while pygame.mixer.music.get_busy():
    pygame.time.Clock().tick(10)


pygame.quit()
sys.exit()

