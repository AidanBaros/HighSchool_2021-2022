import pygame
import random
import math

pygame.init()
(width, height) = (800, 800)
screen = pygame.display.set_mode((width, height)) # creates pygame screen
pygame.display.set_caption("Valentine's Hearts")
screen.fill((255, 145, 171))

font = pygame.font.SysFont('comicsansms', 32)
text = font.render("Are you my Valentine?", True, (0, 0, 0))
textRect = text.get_rect()
textRect.center = (400, 400-20)
text2 = font.render("Cuz you're the only", True, (0, 0, 0))
text2Rect = text2.get_rect()
text2Rect.center = (400, 450-20)
text3 = font.render("Val I Tine", True, (0, 0, 0))
text3Rect = text3.get_rect()
text3Rect.center = (400, 500-20)

GameLoop = True
                
t=0
ticker = 2
adder = 1

# GAME LOOP-----------------------------------------------------------
while GameLoop:
    if ticker<1 or ticker>250:
       adder*=-1
    ticker+=adder
    t+=1
    xpos1 = -100*2.5 *math.sin(t)+100*.8*math.sin(3*t)-100*.5*math.cos(36*t/7)+400
    ypos1 = -100*2.7*math.cos(t)+100*math.cos(2*t)+100*.5*math.cos(3*t)-100*.5*math.sin(36*t/7)+400
    xpos2 = -90*2.5 *math.sin(t)+90*.8*math.sin(3*t)-90*.5*math.cos(36*t/7)+400
    ypos2 = -90*2.7*math.cos(t)+90*math.cos(2*t)+90*.5*math.cos(3*t)-90*.5*math.sin(36*t/7)+400
    xpos3 = -80*2.5 *math.sin(t)+80*.8*math.sin(3*t)-80*.5*math.cos(36*t/7)+400
    ypos3 = -80*2.7*math.cos(t)+80*math.cos(2*t)+80*.5*math.cos(3*t)-100*.5*math.sin(36*t/7)+400
    xpos4 = -70*2.5 *math.sin(t)+70*.8*math.sin(3*t)-70*.5*math.cos(36*t/7)+400
    ypos4 = -70*2.7*math.cos(t)+70*math.cos(2*t)+70*.5*math.cos(3*t)-70*.5*math.sin(36*t/7)+400
    
    # render section
    pygame.draw.circle(screen, (250-ticker/3, ticker/3, ticker), (xpos1, ypos1), 3)
    pygame.draw.circle(screen, (100-ticker/3, ticker, ticker/10), (xpos2, ypos2), 3)
    pygame.draw.circle(screen, (ticker, ticker, ticker), (xpos3, ypos3), 3)
    pygame.draw.circle(screen, (ticker/3, ticker/2, 250-ticker/3), (xpos4, ypos4), 3)

    screen.blit(text, textRect)
    screen.blit(text2, text2Rect)
    screen.blit(text3, text3Rect)
    pygame.display.flip()

pygame.quit()
