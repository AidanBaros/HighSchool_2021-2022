import pygame
import random
pygame.init

#constants for colors
RED = (250,0,0)
ORANGE = (200, 100, 0)
GREEN = (0,150, 0)
BROWN = (165,42,42)


# parent class
class Plant( object ):    
          
        def __init__(self, x, y):   
            self.xpos = x
            self.ypos = y
            self.size = 10
            self.water = 0
            self.petal = 1
            
        def grow(self):
            if self.water>10:
                self.water-=10
                self.size +=20
                self.petal += 1
                print("growing!")
                
        def getWatered(self):
            self.water+=5

  
# child class
class Flower( Plant ):           
        def __init__(self, xpos, ypos, type, color):
                self.color = color
                self.type = type
  
                # invoking the __init__ of the parent class 
                Plant.__init__(self, xpos, ypos)
        
        def draw(self):
            pygame.draw.rect(screen, (GREEN), (self.xpos-10, self.ypos+20, 20, 100+self.size*10)) 
            pygame.draw.circle(screen, (0,0,0), (self.xpos-(20*self.petal), self.ypos+(20*self.petal)), 21+self.size, 5)
            pygame.draw.circle(screen, (0,0,0), (self.xpos+(20*self.petal), self.ypos+(20*self.petal)), 21+self.size, 5) 
            pygame.draw.circle(screen, (0,0,0), (self.xpos-(20*self.petal), self.ypos-(20*self.petal)), 21+self.size, 5)
            pygame.draw.circle(screen, (0,0,0), (self.xpos+(20*self.petal), self.ypos-(20*self.petal)), 21+self.size, 5)
            pygame.draw.circle(screen, (self.color), (self.xpos-(20*self.petal), self.ypos+(20*self.petal)), 20+self.size)
            pygame.draw.circle(screen, (self.color), (self.xpos+(20*self.petal), self.ypos+(20*self.petal)), 20+self.size)
            pygame.draw.circle(screen, (self.color), (self.xpos-(20*self.petal), self.ypos-(20*self.petal)), 20+self.size) 
            pygame.draw.circle(screen, (self.color), (self.xpos+(20*self.petal), self.ypos-(20*self.petal)), 20+self.size)
            
            pygame.draw.circle(screen, (ORANGE), (self.xpos, self.ypos), 20+self.size)         

class Tree( Plant ):

    def __init__(self, xpos, ypos, type, color):
                self.color = color
                self.type = type
  
                # invoking the __init__ of the parent class 
                Plant.__init__(self, xpos, ypos)

    def draw(self):
            pygame.draw.rect(screen, (BROWN), (self.xpos-10, self.ypos+20, 20, 100+self.size*10)) 
            pygame.draw.circle(screen, (GREEN), (self.xpos-(15*self.petal), self.ypos+(15*self.petal)), 20+self.size)
            pygame.draw.circle(screen, (GREEN), (self.xpos+(15*self.petal), self.ypos+(15*self.petal)), 20+self.size) 
            pygame.draw.circle(screen, (GREEN), (self.xpos-(15*self.petal), self.ypos-(15*self.petal)), 20+self.size)
            pygame.draw.circle(screen, (GREEN), (self.xpos+(15*self.petal), self.ypos-(15*self.petal)), 20+self.size)
            pygame.draw.circle(screen, (GREEN), (self.xpos, self.ypos+(20*self.petal)), 20+self.size)
            pygame.draw.circle(screen, (GREEN), (self.xpos+(20*self.petal), self.ypos), 20+self.size) 
            pygame.draw.circle(screen, (GREEN), (self.xpos-(20*self.petal), self.ypos), 20+self.size)
            pygame.draw.circle(screen, (GREEN), (self.xpos, self.ypos-(20*self.petal)), 20+self.size)
            
            pygame.draw.circle(screen, (GREEN), (self.xpos, self.ypos), 20+self.size)
                  
# creation of an object variable or an instance
f1 = Flower(random.randint(200,550), random.randint(200,550), "daisy", RED)   
f2 = Flower(random.randint(650,1000), random.randint(200,550), "daisy", RED) 
f3 = Flower(random.randint(200,550), random.randint(650,1000), "daisy", RED) 
f4 = Flower(random.randint(650,1000), random.randint(650,1000), "daisy", RED) 
t1 = Tree(600, 600, "Tree", GREEN)

#creates game screen and caption
screen = pygame.display.set_mode((1200, 1200))
pygame.display.set_caption("inheritance demo")

#game variables
doExit = False #variable to quit out of game loop
clock = pygame.time.Clock() #sets up a game clock to regulate game speed


#BEGIN GAME LOOP######################################################
while not doExit:
    
    clock.tick(60) #FPS (frames per second)
      
    #pygame's way of listening for events (key presses, mouse clicks, etc)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True #lets you quit program

    #keyboard input-----------------------------------
    print("press w to water, any other key to skip")
    answer = input()
    if answer == 'w':
        f1.getWatered()
        f2.getWatered()
        f3.getWatered()
        f4.getWatered()
        t1.getWatered()
        print("watering plant!")
     
    #render section-----------------------------------
 

    #draw class objects
    f1.grow()
    f1.draw()
    f2.grow()
    f2.draw()
    f3.grow()
    f3.draw()
    f4.grow()
    f4.draw()
    t1.grow()
    t1.draw()
    

    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
