import pygame
import random
 
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

WIDTH = 1
HEIGHT = 1

MARGIN = 1

grid = []
for row in range(1000):
    grid.append([])
    for column in range(1000):
        grid[row].append(0)

grid[1][5] = 1

pygame.init()

WINDOW_SIZE = [1000, 1000]
screen = pygame.display.set_mode(WINDOW_SIZE)

pygame.display.set_caption("Array Backed Grid")

done = False

clock = pygame.time.Clock()

while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
        elif event.type == pygame.MOUSEBUTTONDOWN:

            pos = pygame.mouse.get_pos()

            column = pos[0] // (WIDTH + MARGIN)
            row = pos[1] // (HEIGHT + MARGIN)
            
            grid[row][column] = 1
            print("Click ", pos, "Grid coordinates: ", row, column)
 
    screen.fill(WHITE)

    for row in range(1000):
        for column in range(1000):
            color = BLACK
            if grid[row][column] == 1:
                color = GREEN
            pygame.draw.rect(screen,
                             color,
                             [(MARGIN + WIDTH) * column + MARGIN,
                              (MARGIN + HEIGHT) * row + MARGIN,
                              WIDTH,
                              HEIGHT])
 
    clock.tick(60)
 
    pygame.display.flip()

pygame.quit()
