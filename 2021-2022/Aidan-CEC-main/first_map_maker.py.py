import pygame
import random
pygame.init()

screen = pygame.display.set_mode((600, 600))
pygame.display.set_caption("MAP")

Clock = pygame.time.Clock()


#y = 0
#for a in range(120):
#    x = 0
#    Clock.tick(60)
#    for a in range(120):
#        ran = random.randint(1,7)
#        if ran == 1:
#            pygame.draw.rect(screen, (255, 0, 0), (x, y, 5, 5))
#        if ran == 2:
#            pygame.draw.rect(screen, (255, 105, 0), (x, y, 5, 5))
#        if ran == 3:
#            pygame.draw.rect(screen, (255, 220, 0), (x, y, 5, 5))
#        if ran == 4:
#            pygame.draw.rect(screen, (100, 255, 0), (x, y, 5, 5))
#        if ran == 5:
#            pygame.draw.rect(screen, (0, 100, 255), (x, y, 5, 5))
#        if ran == 6:
#            pygame.draw.rect(screen, (55, 0, 255), (x, y, 5, 5))
#        if ran == 7:
#            pygame.draw.rect(screen, (200, 0, 255), (x, y, 5, 5))
#        x += 5
#    y += 5
#    pygame.display.flip() 
#while True:
#    print("")


x = 300
y = 300
#while True:
ran = 1
for x in range(7):
    ranx = random.randint(0,30)
    rany = random.randint(0,30)
    x += ranx * 10
    y += rany * 10
    if ran == 1:
        pygame.draw.rect(screen, (255, 0, 0), (x, y, 10, 10))
    if ran == 2:
        pygame.draw.rect(screen, (255, 105, 0), (x, y, 10, 10))
    if ran == 3:
        pygame.draw.rect(screen, (255, 220, 0), (x, y, 10, 10))
    if ran == 4:
        pygame.draw.rect(screen, (100, 255, 0), (x, y, 10, 10))
    if ran == 5:
        pygame.draw.rect(screen, (0, 100, 255), (x, y, 10, 10))
    if ran == 6:
        pygame.draw.rect(screen, (55, 0, 255), (x, y, 10, 10))
    if ran == 7:
        pygame.draw.rect(screen, (200, 0, 255), (x, y, 10, 10))
    ran += 1
pygame.display.flip()

while True:
    print("")


