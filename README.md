# Recruitment-Intership-NM

## Task 1
Implementation of the "isColliding" function, whose task is to check whether two triangles collide with each other. The function works on the basis of cross product calculation.
The visualization was done using the SFML library version 2.5.1..

### How to use?
To change the position of the triangles all you need is a mouse. The left mouse button is responsible for the green triangle, and the right mouse button is responsible for the blue triangle. If the triangles are red it means that they collide with each other.

![GIFtask3](https://user-images.githubusercontent.com/100961127/237035718-9c7d9cce-8137-4a74-b296-6aa05bf97a00.gif)


## Task 2
The program moves the pixel along a predetermined path at a predetermined time. The current position of the pixel if determined by calculating the percentage of time elapsed since the last point.

![GIFtask2](https://user-images.githubusercontent.com/100961127/237036911-68d33119-0458-459e-980f-350e8a561818.gif)


## Task 3
The program truncates strings from the left and right according to the given predicate.
The following predicates have been created in the program:
- isWhitespace - which checks for whitespace characters
- isDigit - which checks digits
- isAlpha - which checks letters
- isUpperCase - which checks uppercase letters
- isLowerCase - checks lowercase letters

Tests based on doctest library version 2.4.11 were written for the program.
