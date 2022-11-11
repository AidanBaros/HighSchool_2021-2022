import pygame
import math
import random

pygame.init


screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("simple base code")
screen.fill((0,0,255))
clock = pygame.time.Clock()
doExit = False

class Butterfly:
    def __init__(self,posX,posY):
        self.posX = posX
        self.posY = posY
    def draw(self):
        pygame.draw.circle(screen,(150,0,220),((self.posX+35,self.posY+20)),50)
        pygame.draw.circle(screen,(150,0,220),((self.posX-35,self.posY+20)),50)

        pygame.draw.circle(screen,(150,0,180),((self.posX+35,self.posY-20)),60)
        pygame.draw.circle(screen,(150,0,180),((self.posX-35,self.posY-20)),60)

        pygame.draw.ellipse(screen,(255,255,0),(self.posX-20,self.posY-80,40,150),0)

        pygame.draw.line(screen,(0,0,0),(self.posX-5,self.posY-75),(self.posX-30,self.posY-100),5)
        pygame.draw.line(screen,(0,0,0),(self.posX+5,self.posY-75),(self.posX+30,self.posY-100),5)

        pygame.draw.arc(screen,(200,100,0),((self.posX-20,self.posY-75,40,40)),5*math.pi/4,7*math.pi/4,5)
        pygame.draw.arc(screen,(200,100,0),((self.posX-20,self.posY-55,40,40)),5*math.pi/4,7*math.pi/4,5)
        pygame.draw.arc(screen,(200,100,0),((self.posX-20,self.posY-35,40,40)),5*math.pi/4,7*math.pi/4,5)
        pygame.draw.arc(screen,(200,100,0),((self.posX-20,self.posY-15,40,40)),5*math.pi/4,7*math.pi/4,5)
        pygame.draw.arc(screen,(200,100,0),((self.posX-20,self.posY+5,40,40)),5*math.pi/4,7*math.pi/4,5)


butterflynet = []
for i in range(3):
    x = random.randint(100,700)
    y = random.randint(100,700)
    butterflynet.append(Butterfly(x,y))

while not doExit:
   
    clock.tick(60)
   
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True
    
    screen.fill((0,0,255))
    for Butterfly in butterflynet:
        Butterfly.draw()
    pygame.display.flip()
    
pygame.quit()
