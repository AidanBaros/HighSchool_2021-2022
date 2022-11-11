import pygame
import math
import random
pygame.init()

screen = pygame.display.set_mode((1000,800))

font = pygame.font.Font(None, 74)

pygame.display.set_caption("Pankin Breakout")

doExit = False

#auto play
autoPlay = False

#to do things every some loops
timer = 0

#player deaths
dead = 0

#counting dead pumpkins
deaths = 0

#player setup----------------------------------------------------------------------
playerX = 300
playerY = 780
#player velocity
pVelx = .0

#ball setup
bx = random.randrange(50,950)
by = 600
bVx = 5
bVy = 5

clock = pygame.time.Clock()

class pankin:
    def __init__(self,posX,posY,isDead):
        self.posX = posX
        self.posY = posY
        self.isDead = isDead
    def draw(self):
        pygame.draw.rect(screen, (0, 150, 0), ((self.posX - 10), (self.posY - 70), 20, 25))
        pygame.draw.circle(screen, (200, 100, 0), (self.posX, self.posY), 50)
        pygame.draw.arc(screen, (0, 0, 0), ((self.posX - 15), self.posY, 30, 20), math.pi, math.pi*2, 2)
        pygame.draw.arc(screen, (0, 0, 0), ((self.posX - 25), (self.posY - 20), 20, 20), 0, math.pi, 2)
        pygame.draw.arc(screen, (0, 0, 0), (self.posX, (self.posY - 20), 20, 20), 0, math.pi, 2)
    def CircleCollide(self, x, y):
         return math.sqrt(((self.posX-x) * (self.posX-x)) + ((self.posY-y) * (self.posY-y)))
    
    #def CircleCollide(self, x, y, r):
    #    if math.sqrt(((self.posX-x) * (self.posX-x)) + ((self.posY-y) * (self.posY-y))) < (r + 50):
    #        return True
    #    else:
    #        return False
    def kill(self):
        self.isDead = True
    def checkDead(self):
        return self.isDead
   



patch = []

for y in range(3):
    for x in range(10):
        patch.append(pankin(((x*100)+50),((y*100)+150), False))


#GAME LOOP------------------------------------------------------------------------------------------
while doExit == False:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True
    clock.tick(60)
    #player movement----------------------

    #wall check
    if playerX >= 800:
        pVelx *= -1
        playerX = 800.0
    if playerX <= 0:
        playerX = 0.0
        pVelx *= -1

    if bx >= 995:
        bVx *= -1
    if bx <= 0:
        bVx *= -1

    #cieling check
    if by-5 <= 0:
        bVy *= -1

    #floor check (really lose/die check)
    if by >= 790:
        bx = random.randrange(50,950)
        by = 600
        playerX = bx
        dead += 1

    #player check
    if bx-5 >= playerX and bx-5 <= playerX+200 and by >= playerY:
        bVy *= -1
        bVx += random.randint(-5,5)/5
        print(bVx)
    elif bx+5 >= playerX and bx+5 <= playerX+200 and by >= playerY:
        bVy *= -1
        bVx += random.randint(-5,5)/5
        print(bVx)
    #Player Input
    keys = pygame.key.get_pressed()
    if keys[pygame.K_d]:
        pVelx = 8
    if keys[pygame.K_a]:
        pVelx = -8
    
    if keys[pygame.K_SPACE] and timer == 0:
        timer = 60
        if autoPlay == False:
            autoPlay = True
        elif autoPlay == True:
            autoPlay = False
    if timer > 0:
        timer -= 1
    #friction
    pVelx *= .95

    for x in patch:
        if x.CircleCollide(bx, by) < (5 + 50) and x.checkDead() == False:
            x.kill()
            deaths += 1
            bVy *= -1

    #move things
    playerX += pVelx;
    by += bVy
    bx += bVx
    if autoPlay == True:
        playerX = bx - 100
   
   
           

    #render
    screen.fill((0,0,0))
    if deaths == 30:
        text = font.render("You Win!", 1, (255 ,255 ,255))
        screen.blit(text, (400,350))
    else:
        if autoPlay == True:
            text = font.render("AI On", 1, (255 ,255 ,255))
            screen.blit(text, (20,20))
    
        text = font.render(str(dead), 1, (255 ,255 ,255))
        screen.blit(text, (950,20))
        pygame.draw.rect(screen, (255,255,255), (playerX, playerY, 200,10))
        pygame.draw.circle(screen, (255,255,255), (bx,by), 5)
        for pankin in patch:
            if pankin.isDead == False:
                pankin.draw()
    pygame.display.flip()
