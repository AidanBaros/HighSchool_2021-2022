import pygame
import random
from pygame import scrap
pygame.init()

screen = pygame.display.set_mode((1200,1000))
pygame.display.set_caption("Pong")
screen.fill((0,0,0))

doExit = False

clock = pygame.time.Clock()

p1x = 50
p2x = 1150
p1y = 350
p2y = 350

bx = 600
by = 500
bVx = 5
bVy = 5

p1Score = 0
p2Score = 0


while not doExit:
    clock.tick(60)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True


    bx += bVx
    by += bVy

    if bx < 0 or bx > 1200:
        bVx *= -1
    if by < 0 or by > 1000:
        bVy *= -1


    keys = pygame.key.get_pressed()
    if keys[pygame.K_w] and p1y != 0:
        p1y-=5
    if keys[pygame.K_s] and p1y + 300 != 1000:
        p1y+=5
    if keys[pygame.K_UP] and p2y != 0:
        p2y-=5
    if keys[pygame.K_DOWN] and p2y + 300 != 1000:
        p2y+=5

    if bx > p1x and bx < p1x + 25 and by + 20 > p1y and by < p1y + 300:
        bVx *= -1.05
    if bx > p2x and bx < p2x + 25 and by + 20 > p2y and by < p2y + 300:
        bVx *= -1.05
    #if by > p1y and by > p1y + 25:
    #    bVx *= -1.05 

    if bx < 0:
        bx = 1100
        bVx = -5
        p2Score += 1
    if bx > 1200:
        bx = 100
        bVx = 5
        p1Score += 1 


    if p1Score == 7:
        while True:
            pygame.draw.circle(screen, (random.randint(0,255),random.randint(0,255),random.randint(0,255)), (random.randint(0,1200), random.randint(0,1000)), random.randint(0,50))
            font = pygame.font.Font(None, 74)
            text = font.render(("Player 1 Wins!"), 1, (0,0,0))
            screen.blit(text, (425,450))
            pygame.display.flip()
    if p2Score == 7:
        while True:
            pygame.draw.circle(screen, (random.randint(0,255),random.randint(0,255),random.randint(0,255)), (random.randint(0,1200), random.randint(0,1000)), random.randint(0,50))
            font = pygame.font.Font(None, 74)
            text = font.render(("Player 2 Wins!"), 1, (0,0,0))
            screen.blit(text, (425,450))
            pygame.display.flip()

    pygame.draw.line(screen, (255,255,255),[600,0],[600,1000],1)
    pygame.draw.rect(screen, (255,255,255), (p1x,p1y,25,300))
    pygame.draw.rect(screen, (255,255,255), (p2x,p2y,25,300))
    pygame.draw.circle(screen, (255,255,255), (bx, by), 10)
    font = pygame.font.Font(None, 74)
    text = font.render(str(p1Score), 1, (255,255,255))
    screen.blit(text, (550,10))
    text = font.render(str(p2Score), 1, (255,255,255))
    screen.blit(text, (620,10))
    
    
    pygame.display.flip()
    screen.fill((0,0,0))




pygame.quit()
