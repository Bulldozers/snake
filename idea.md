# The Idea

- Setting up a very rudimentary game engine that is:

	- Text-based

	- Live-action

	- Object-oriented

- Implementing a simple version of the game "Snake"

# The Engine

## The Display Loop

- The ‘screen’ would be updated a certain number of times per second, probably 10 or 15

- A screen update would constitute:

	- Printing enough newlines to fill the screen, ‘erasing’ the previous frame

	- Printing the current frame, line by line

- The frame would have a certain ‘resolution’, maybe about 50 by 20 characters

	- (Possibly) specified in parameters

	- These characters would be the ‘pixels’ of the screen

	- When the screen is printed, empty pixels would be printed as spaces

	- Any characters could be used to designate ‘full’ pixels

- This continuous output would hopefully look like animated motion of the characters on the screen

## The Object Model

- Most game engines have the idea of an ‘object’ in the code corresponding to a physical object on screen

- We would similarly have an Object class that includes:

	- Physical attributes such as position and size, in ‘pixels’

	- A Position data structure or class would be useful here

		- This is definitely where operator overloading could come in; adding, subtracting, and otherwise transforming pixel positions have intuitive meanings

	- Information on which character(s) to display at that position – a ball for example might be shown as the letter ‘O’

- Objects in the game would inherit this class

- Instances of the Screen class (of which there would presumably only be one in each game) would aggregate a list of objects to display

	- In the routine that occurs when each pixel is displayed, the screen would query all the objects about their display attributes

	- These objects would presumably be subclasses of Object, and this is where polymorphism would come in – each subclass would implement its display function differently

## User Input

- I haven’t looked into this, but I’m assuming that C++ has functionality similar to Java’s for detecting a single character input in the console

- This could be used for live key presses – in between frames, if the user presses a key, the program picks this up before displaying the next frame, and adjusts the next frame accordingly

	- This would involve sending the message that the key was pressed to all the objects, which would have listener functions that could be customized (more polymorphism)

# The Game

## The Objects

- Two main subclasses of the Object base class: Snake and Food

- Both have a clear position – the snake’s position would be its head

- The snake would store a direction of motion, and would update its position every frame based on that

- When the snake receives a message that the keys W, S, A or D have been pressed, it changes its direction of motion accordingly

- When the snake’s position (head) is equal to that of the food, the food moves to another random position

- The first step would be simply having the snake with length 1, and having it move around and eat food

- After this, we could figure out a good data structure for storing the snake’s previous X positions (with X being the current length of the snake) and making sure those are displayed, and – importantly – that no two of them are the same, or you lose!!

## The HUD

- ‘Drawing’ text in the HUD would obviously be very easy

- A Label class would probably be made, with a position and text
	- This would subclass the Object class

- The HUD would display the score and probably the highscore
