import pygame
pygame.init()  
pygame.display.set_caption("sprite sheet")  # sets the window title
screen = pygame.display.set_mode((800, 800))  # creates game screen
screen.fill((0,0,0))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop

#CONSTANTS
LEFT=0
RIGHT=1
UP = 2
DOWN = 3

#MAP: 1 is grass, 2 is brick
map = [[0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,4 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,4 ,0, 0,0],
       [0, 0, 0, 0, 4, 0, 0, 3, 3, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2 ,2 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2 ,2 ,0, 0,0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,0],
       [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 1,0],
       [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,1, 1,0],
       [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1, 1,0]]

brick = pygame.image.load('brick.png') #load your spritesheet
dirt = pygame.image.load('dirt.png') #load your spritesheet
simon = pygame.image.load('simon.png') #load your spritesheet
cloud = pygame.image.load('cloud.png')
Link2 = pygame.image.load('link.png')
cobblestone = pygame.image.load('CobbleStone.jpg')
simon.set_colorkey((0,0,0)) #this makes bright pink (255, 0, 255) transparent (sort of)

#player variables
xpos = 500 #xpos of player
ypos = 200 #ypos of player
vx = 0 #x velocity of player
vy = 0 #y velocity of player
keys = [False, False, False, False] #this list holds whether each key has been pressed
isOnGround = False #this variable stops gravity from pulling you down more when on a platform

#player2 variables
xpos2 = 500 #xpos of player
ypos2 = 200 #ypos of player
vx2 = 0 #x velocity of player
vy2 = 0 #y velocity of player
keys2 = [False, False, False, False] #this list holds whether each key has been pressed
isOnGround2 = False #this variable stops gravity from pulling you down more when on a platform

#animation variables variables
frameWidth = 36
frameHeight = 68
RowNum = 0 #for left animation, this will need to change for other animations
frameNum = 0
ticker = 0
direction = DOWN

#animation variables variables for p2
frameWidth2 = 32
frameHeight2 = 48
RowNum2 = 0 #for left animation, this will need to change for other animations
frameNum2 = 0
ticker2 = 0
direction2 = DOWN

while not gameover:
    clock.tick(60) #FPS
   
    for event in pygame.event.get(): #quit game if x is pressed in top corner
        if event.type == pygame.QUIT:
            gameover = True
     
        if event.type == pygame.KEYDOWN: #keyboard input
            if event.key == pygame.K_LEFT:
                keys[LEFT]=True
            elif event.key == pygame.K_RIGHT:
                keys[RIGHT]=True
            elif event.key == pygame.K_UP:
                keys[UP]=True
                #change to key2, change to a, d, w
            if event.key == pygame.K_a:
                keys2[LEFT]=True
            elif event.key == pygame.K_d:
                keys2[RIGHT]=True
            elif event.key == pygame.K_w:
                keys2[UP]=True
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                keys[LEFT]=False
            elif event.key == pygame.K_RIGHT:
                keys[RIGHT]=False
            elif event.key == pygame.K_UP:
                keys[UP]=False
                #change to key2, change to a, d, w
            if event.key == pygame.K_a:
                keys2[LEFT]=False
            elif event.key == pygame.K_d:
                keys2[RIGHT]=False
            elif event.key == pygame.K_w:
                keys2[UP]=False
         

    #p1 MOVEMENT--------------------------------------------------------------
    if keys[LEFT]==True:
        vx=-3
        RowNum = 1
        direction = LEFT
    #RIGHT MOVEMENT
    elif keys[RIGHT] == True:
        vx = 3
        RowNum = 0
        direction = RIGHT
    #turn off velocity
    else:
        vx = 0
        #JUMPING
    if keys[UP] == True and isOnGround == True: #only jump when on the ground
        vy = -8
        #RowNum = 4
        #frameNum = 0
        isOnGround = False
        direction = UP
         
    xpos+=vx #update player xpos
    ypos+=vy
   
   #p2 movement--------------------------------------------------------------
    #all of this stuff should have 2s
    if keys2[LEFT]==True:
        vx2=-3
        RowNum2 = 0
        direction2 = LEFT
    #RIGHT MOVEMENT
    elif keys2[RIGHT] == True:
        vx2 = 3
        RowNum2 = 1
        direction2 = RIGHT
    #turn off velocity
    else:
        vx2 = 0
        #JUMPING
    if keys2[UP] == True and isOnGround == True: #only jump when on the ground
        vy2 = -8
        RowNum2 = 2
        isOnGround2 = False
        direction2 = UP
         
    xpos2+=vx2 #update player xpos
    ypos2+=vy2
   
   
    #COLLISION
   
    #collision with feetsies
    if map[int((ypos+frameHeight)/50)][int((xpos+frameWidth/2)/50)]==1 or map[int((ypos+frameHeight)/50)][int((xpos+frameWidth/2)/50)]==2 or map[int((ypos+frameHeight)/50)][int((xpos+frameWidth/2)/50)]==3:
        isOnGround = True
        vy=0
       
    else:
        isOnGround = False
       
    #bump your head, ouch!
    if map[int((ypos)/50)][int((xpos+frameWidth/2)/50)]==1 or map[int((ypos)/50)][int((xpos+frameWidth/2)/50)]==2:
        vy=0
       
    #left collision (it's extra long because we check both head and feets(well, knees) for left collision
    if (map[int((ypos+frameHeight-10)/50)][int((xpos-10)/50)]==1 or map[int((ypos)/50)][int((xpos-10)/50)]==1 or map[int((ypos+frameHeight-10)/50)][int((xpos-10)/50)]==2 or map[int((ypos)/50)][int((xpos-10)/50)]==2 or map[int((ypos+frameHeight-10)/50)][int((xpos-10)/50)]==3 or map[int((ypos)/50)][int((xpos-10)/50)]==3 ) and direction == LEFT:
        xpos+=3
       
    #right collision needed here
    if (map[int((ypos+frameHeight-10)/50)][int((xpos+frameWidth-10)/50)]==1 or map[int((ypos)/50)][int((xpos+frameWidth-10)/50)]==1 or map[int((ypos+frameHeight-10)/50)][int((xpos+frameWidth-10)/50)]==2 or map[int((ypos)/50)][int((xpos+frameWidth-10)/50)]==2 or map[int((ypos+frameHeight-10)/50)][int((xpos+frameWidth-10)/50)]==3 or map[int((ypos)/50)][int((xpos+frameWidth-10)/50)]==3 ) and direction == RIGHT:    
        xpos-=3
   
    #stop moving if you hit edge of screen (will be removed for scrolling)
    if xpos+frameWidth > 800:
        xpos=800-frameWidth
    if xpos<0:
        xpos=0

   
    #stop falling if on bottom of game screen
    if ypos > 800-frameHeight:
        isOnGround = True
        vy = 0
        ypos = 800-frameHeight
   
    #gravity
    if isOnGround == False:
        vy+=.2 #notice this grows over time, aka ACCELERATION
   
   
    #p2 player gravity (put 2s in here)
    #stop falling if on bottom of game screen
    if ypos > 800-frameHeight:
        isOnGround = True
        vy = 0
        ypos = 800-frameHeight
   
    #gravity
    if isOnGround == False:
        vy+=.2 #notice this grows over time, aka ACCELERATION    
   

       
    #ANIMATION-------------------------------------------------------------------
       
    # Update Animation Information
#double this part, put 2s
    if vx != 0: #animate when moving
        ticker+=1
        if ticker%10==0: #only change frames every 10 ticks
          frameNum+=1
        if frameNum>2:
           frameNum = 0
 
    # RENDER--------------------------------------------------------------------------------
    # Once we've figured out what frame we're on and where we are, time to render.
           
    screen.fill((0,0,0)) #wipe screen so it doesn't smear
   
    #draw map
    for i in range (16):
        for j in range(16):
            if map[i][j]==1:
                screen.blit(dirt, (j*50, i*50), (0, 0, 50, 50))
            if map[i][j]==2:
                screen.blit(brick, (j*50, i*50), (0, 0, 50, 50))
            if map[i][j]==3:
                screen.blit(cobblestone, (j*50, i*50), (0, 0, 50, 50))
            if map[i][j]==4:
                screen.blit(cloud, (j*50, i*50), (0, 0, 50, 50))
       
   
    screen.blit(simon, (xpos, ypos), (frameWidth*frameNum, RowNum*frameHeight, frameWidth, frameHeight))
    screen.blit(Link2, (xpos2, ypos2), (frameWidth2*frameNum2, RowNum2*frameHeight2, frameWidth2, frameHeight2))
    pygame.display.flip()#this actually puts the pixel on the screen
   
#end game loop------------------------------------------------------------------------------
pygame.quit()
