import pygame
import random
import winsound

pygame.init()

screen = pygame.display.set_mode((1000, 1000))
pygame.display.set_caption("Bubble Sort")

clock = pygame.time.Clock()

MyList = []

for x in range(0,100):
    MyList.append(x+1)

random.shuffle(MyList)

while True:
    for i in range(99):
        clock.tick(120)
        if MyList[i]>MyList[i+1]:
            temp = MyList[i]
            MyList[i]= MyList[i+1]
            MyList[i+1]=temp
            screen.fill((0,0,0))
            for k in range(100):
                Rcolor = 155+MyList[k-1]         
                Gcolor = 25+MyList[k-1]*1.5         
                Bcolor = 0         
                pygame.draw.rect(screen, ((Rcolor, Gcolor, Bcolor)), (k*10-10,((250)-(5+(MyList[k-1]*5))/2), 10, 5+(MyList[k-1]*5)))
            pygame.draw.rect(screen, (255,255,255), ((i+1)*10, ((250)-(5+(MyList[i+1]*5))/2), 10, 5+(MyList[i+1]*5)))
            winsound.Beep(i*10+37, 5)
            pygame.draw.rect(screen, (255,255,255), ((i)*10, ((250)-(5+(MyList[i]*5))/2), 10, 5+(MyList[i]*5)))
            pygame.display.flip()
    pygame.display.flip() #update graphics 

pygame.quit()
