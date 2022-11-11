import pygame
from pygame.locals import *
import math

pygame.init()  
pygame.display.set_caption("mandelbrot")  # sets the window title
screen = pygame.display.set_mode((1000, 1000))  # creates game screen
screen.fill((8,6,12))

doExit = False

multiplierX = 1
multiplierY = 1
movementX = 0
movementY = 0
resolution = .008

#mandelbrot function definition------------------------ 
def manCount(c):
    z = complex(0,0)
    count = 0
    while abs(z) < 2 and count < 80: 
        z = z * z + c
        count+=1
    return count

def manDraw(zooming =0, multiplierX =1, multiplierY =1, movementX =0, movementY =0, resolution =.008, upperBound =2, lowerBound =2):
    print(resolution)
    t = -lowerBound #lower bound for real axis
    while t<lowerBound: #upper bound for real (horizontal) axis
        t+=resolution #make this number SMALLER to increase picture resolution
    
        m = -upperBound #lower bound for imaginary axis
        while m<upperBound: #upper bound for imaginary (vertical) axis
            m+=resolution #make this number SMALLER to increase picture resolution

            if int(((t * 250 + 500) * multiplierX) + movementX) >= 0 and int(((t * 250 + 500) * multiplierX) + movementX) <= 1000 and int(((m * 250 + 500) * multiplierY) + movementY) >= 0 and int(((m * 250 + 500) * multiplierY) + movementY) <= 1000:
        
                c = complex(t, m) #create a complex number from iterators
                num = manCount(c); #call the function

                #these if statements are just to differentiate the colors more, not needed if you want black & white image
                if num < 20:
                    screen.set_at((int(((t * 250 + 500) * multiplierX) + movementX), int(((m * 250 + 500) * multiplierY) + movementY)), (num*8, num*6, num*12))
                elif num < 40:
                   screen.set_at((int(((t * 250 + 500) * multiplierX) + movementX), int(((m * 250 + 500) * multiplierY) + movementY)), (num*2, num/2, num*6))
                elif num is 80:
                   screen.set_at((int(((t * 250 + 500) * multiplierX) + movementX), int(((m * 250 + 500) * multiplierY) + movementY)), (255,255,255))
                else:
                   screen.set_at((int(((t * 250 + 500) * multiplierX) + movementX), int(((m * 250 + 500) * multiplierY) + movementY)), (num*3, num/2, num*2))

    pygame.display.flip()#this actually puts the pixel on the screen

#end function define--------------------------------

#-------------------------------------------------------
print("Please wait...")
manDraw()
print("Drawn!")
print()
while doExit == False:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True
        elif event.type == MOUSEWHEEL:
            screen.fill((8,6,12))
            print(event)
            print(event.x, event.y)
            if event.y == 1:
                resolution /= 1.5
                multiplierX *= 1.5
                multiplierY *= 1.5
                print("Please wait...")
                manDraw(1,multiplierX,multiplierY,movementX - (500 * multiplierX),movementY - (500 * multiplierY),resolution)
                print("Drawn!")
                print()
            elif event.y == -1:
                resolution *= 1.5
                multiplierX /= 1.5
                multiplierY /= 1.5
                print("Please wait...")
                manDraw(2,multiplierX,multiplierY,movementX - (500 * multiplierX),movementY - (500 * multiplierY),resolution)
                print("Drawn!")
                print()
        if pygame.mouse.get_pressed()[0]:
            screen.fill((8,6,12))
            print("Clicked!")
            movementX,movementY = pygame.mouse.get_pos ()
            manDraw(0,multiplierX,multiplierY,movementX - (500 * multiplierX),movementY - (500 * multiplierY),resolution)
            
pygame.quit()#quit pygame
