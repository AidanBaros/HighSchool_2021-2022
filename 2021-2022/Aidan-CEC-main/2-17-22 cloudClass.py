import pygame
import math

pygame.init


#creates game screen and caption
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("simple base code")
screen.fill((0,0,0))
clock = pygame.time.Clock()
#game variables
doExit = False #variable to quit out of game loop

class cloud:
    def __init__(self,posX,posY):
        self.posX = posX
        self.posY = posY
    def draw(self):
        pygame.draw.circle(screen,(255,255,255),((self.posX+25,self.posY)),20)
        pygame.draw.circle(screen,(255,255,255),((self.posX-25,self.posY)),20)
        pygame.draw.circle(screen,(255,255,255),((self.posX,self.posY-15)),30)
        pygame.draw.rect(screen,(255,255,255),((self.posX-20,self.posY),(40,20)))
        pygame.draw.rect(screen,(255,255,255),((self.posX-20,self.posY),(40,20)))
        pygame.draw.arc(screen,(0,0,255),((self.posX-20,self.posY-65,40,40)),7*math.pi/4,5*math.pi/4,5)
        pygame.draw.arc(screen,(0,255,0),((self.posX-25,self.posY-75,50,50)),7*math.pi/4,5*math.pi/4,5)
        pygame.draw.arc(screen,(255,255,0),((self.posX-30,self.posY-85,60,60)),7*math.pi/4,5*math.pi/4,5)
        pygame.draw.arc(screen,(255,0,0),((self.posX-35,self.posY-95,70,70)),7*math.pi/4,5*math.pi/4,5)



c1 = cloud(200,200)
c2 = cloud(600,200)
c3 = cloud(200,600)
c4 = cloud(600,600)
#BEGIN GAME LOOP######################################################
while not doExit:
   
    clock.tick(60) #FPS (frames per second)
   
    #pygame's way of listening for events (key presses, mouse clicks, etc)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True #lets you quit program
     
    #render section-----------------------------------
    
    screen.fill((0,0,0))
    c1.draw()
    c2.draw()
    c3.draw()
    c4.draw()
    #pygame.draw.circle(screen,(255,255,255),((400,400)),25)

    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
