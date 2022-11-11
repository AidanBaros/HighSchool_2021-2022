import pygame
import random
pygame.init()  
pygame.display.set_caption("easy platformer")  # sets the window title
screen = pygame.display.set_mode((800, 800))  # creates game screen
screen.fill((0,0,0))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop

#CONSTANTS
LEFT=0
RIGHT=1
UP = 2
DOWN = 3

offset = 0

class platform():
    def __init__(self,x,y,r,g,b):
        self.x = x
        self.y = y
        self.r = r
        self.g = g
        self.b = b

    def collide(self,px,py):
        if (px + 20 - offset > self.x and px - offset< (self.x + 100) and (py + 40) > self.y and py < (self.y + 20)):
            return self.y - 40
        else:
            return False

    def offScreen(self, keys):
        if keys[LEFT]:
            if self.x+offset > 950:
                self.x = random.randint(-50-offset-100, 0-offset-100)
                self.y = random.randint(100, 700)
                self.startY = self.y
        if keys[RIGHT]:
            if self.x+offset < -150:
                self.x = random.randint(850-offset, 900-offset)
                self.y = random.randint(100, 700)
                self.startY = self.y

    def draw(self):
        pygame.draw.rect(screen,(self.r,self.g,self.b),(self.x + offset,self.y,100,20))

#player variables
xpos = 500 #xpos of player
ypos = 200 #ypos of player
vx = 0 #x velocity of player
vy = 0 #y velocity of player
keys = [False, False, False, False] #this list holds whether each key has been pressed
isOnGround = False #this variable stops gravity from pulling you down more when on a platform

platbag = list()
for i in range(10):
    platbag.append(platform(random.randrange(-100,1000),random.randrange(100,700),random.randint(0,255),random.randint(0,255),random.randint(0,255)))

while not gameover: #GAME LOOP############################################################
    clock.tick(60) #FPS
   
    #Input Section------------------------------------------------------------
    for event in pygame.event.get(): #quit game if x is pressed in top corner
        if event.type == pygame.QUIT:
            gameover = True
     
        if event.type == pygame.KEYDOWN: #keyboard input
            if event.key == pygame.K_LEFT:
                keys[LEFT]=True

            elif event.key == pygame.K_UP:
                keys[UP]=True

            elif event.key == pygame.K_RIGHT:
                keys[RIGHT]=True

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                keys[LEFT]=False

            elif event.key == pygame.K_UP:
                keys[UP]=False

            elif event.key == pygame.K_RIGHT:
                keys[RIGHT]=False
         
    #physics section--------------------------------------------------------------------
    #LEFT MOVEMENT
    if keys[LEFT]==True:
        vx=-3
        direction = LEFT
        if xpos <= 200:
            offset += 3
            vx += 3

    #RIGHT MOVEMENT
    elif keys[RIGHT]==True:
        vx=3
        direction = RIGHT
        if xpos >= 600:
            offset -= 3
            vx -= 3

    #turn off velocity
    else:
        vx = 0
        #JUMPING
    if keys[UP] == True and isOnGround == True: #only jump when on the ground
        vy = -8
        isOnGround = False
        direction = UP
   
   
   
    isOnGround = False
    for platform in platbag:
        if platform.collide(xpos,ypos) != False:
            ypos = platform.collide(xpos,ypos)
            isOnGround = True
            vy = 0
   
    #stop falling if on bottom of game screen
    if ypos > 760:
        isOnGround = True
        vy = 0
        ypos = 760
   
    #gravity
    if isOnGround == False:
        vy+=.2 #notice this grows over time, aka ACCELERATION
    else:
        vy = 0

    #update player position
    xpos+=vx
    ypos+=vy
   
 
    # RENDER Section--------------------------------------------------------------------------------
           
    screen.fill((0,0,0)) #wipe screen so it doesn't smear
 
    pygame.draw.rect(screen, (100, 200, 100), (xpos, ypos, 20, 40))

    #pygame.draw.circle

    for platform in platbag:
        platform.offScreen(keys)
        platform.draw()
    #first platform
   

    pygame.display.flip()#this actually puts the pixel on the screen
   
#end game loop------------------------------------------------------------------------------
pygame.quit()
