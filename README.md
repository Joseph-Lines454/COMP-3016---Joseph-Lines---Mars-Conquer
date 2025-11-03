Evil SpaceMan

GamePlay Description
The game starts of with the title screen. The user is then able to enter the next screen, providing some story on the game.
The aim of the game is for the player to defeat the planets hero/Alien three times, whilst the game gets continuously harder each round.
The player Can Kick, Punch and Croutch to dodge the Aliens Special attack. When the Alien's health gets low, that alien runs to the edge of the screen (retreats) and goes into defense mode.
The Alien then throws a fruit at the user which is designed to significantly decrease their health. The player is able to dodge this attack by croutching. The player is then able to attack the Alien, killing the alien.
If the user beats the Alien, the next round will commence where the Alien will get a bit harder (the amount of moves that they can throw is increased). The players Aim is to beat the Alien in all three rounds and if successfull,
they will have their score which is time based compared to the highest score. The highest score will be overwritten if the player scored higher than the highest score. If they player falters in any round, the Alien wins and the player loses.

Dependencies used

SDL_3 was used for the visuals of the game:

https://www.libsdl.org/

SDL_tff_devel_3.1.0-vc:

https://github.com/libsdl-org/SDL_ttf/releases

Use of AI description:

AI was used within the assigment of the generation of assets. AI was used for the AlienOne_PNG character, the Backgrounds, the Bullets as well as the player character itself. AI was not used for the font used within the game.
For the code aspect of the assigment AI was used for the debugging of code. Some examples include: error using SDL_Surface as a vector (game crashed during execution), AI suggested converting it to a SDL_Texture vector.
Conversion issue using the std::chrono libary for measuring the amount of time that had elapsed during the game. AI suggested a way to convert it to a integer allowing the times to be compared. AI was used for explanation of
concepts. For example, AI was used to ask certain questions about Game Programming Patterns, complementing the knowledge written by Robert Nystrom.

Pixel Lab was used for the generation of the AI assets:

https://www.pixellab.ai/

ChatGPT was used for the Debugging and explination of concepts.

AI was used in a assistive way through the assigment to allow for the expansion of knowledge as well as understanding of concepts. AI was also used for the generation of assets.

Game Programming Patterns:

Sequencing Patterns:

The game loop

This program has a need for a game loop. If a game loop was not implemented within this program, the game would be running at game time not real time, which would result in the game being to fast for the user to interact with.

The Game Loop Pattern has been applied to the game.The Gane Loop concept is to ensure that Game Time is able to catch up to real time. In the example below, we get the start of the loop, get duration of the frame (frameDuration). If the game runs quicker than the delay
we have defined (if the Delay is more than the frame duration), we delay the program, allowing for it to catchup to real time. Implementing the game loop pattern ensures that the game runs at the same speed for everyone. This is quite important for this game due to the scoring being time based. If the game runs at a faster pace on one machine compared to another, that could result in a difference between the high scores - leading to an unfair advantage. This implementation uses the fixed time step to allow for this to work correctly.

<img width="736" height="387" alt="image" src="https://github.com/user-attachments/assets/6640900b-da97-4ad8-a975-b858ee3fcdce" />

Sequencing Patterns

The Component Pattern has been implemented into this game. The idea of the component pattern is to split code across different domains leaving a character class with references to the different components of the player (for example, the screenshot below shows
a class that has a update method which updates these components, or passes them into another update method as a paramater. The gameobject class has a reference to the movment,graphics and health objects. Within the update method, the different objects are updated.
Implementing this pattern has a variety of benifits on the program. Readability was one of the main benifits of implementing this pattern. If this code used a typical OOP hierarchail appropach, the code would have been much more difficult to maintain. Another benifit is a clearer structure. One of the big benifits of implementing this pattern is allowing for the swaping of different components. For example, our Alien character has a different movement class compared to the players movement. We are able to swap this component out and still make use of the graphics and health component (The GameObject component was also swaped out due to the Alien needing the users current state to determine weather the bullet hit them). THis

<img width="742" height="277" alt="image" src="https://github.com/user-attachments/assets/5e54f309-9dd7-4bcb-888f-3f7cbd58ff6d" />
<img width="811" height="80" alt="image" src="https://github.com/user-attachments/assets/90ca85a7-3afa-49ec-bbcd-1afc707dced1" />



Game Mechanics:

Certain 

Movement Mechanics:

The player is allowed to move forwards or backwards within the game. When the player pressed the D key the player is able to move towards the Alien and Vice versa. Once the player reaches the alien, the player is unable to move forward.
The Alien is also follows this concept. The player can move backwards by pressing A however the Alien continues to attack the player. If the player/Alien hits the edge of the world, the player is no longer able to move in that direction.
The player is allowed to crouth when the Alien lanuches their special/defense attack. The aim is to avoid being hit by the fruit.

Combat Mechanics/ Round Based:

Different combat mechanics are present within the game. The user is able to hit the Alien. If the user hits the Alien, the other players health is reduced by 2. If the user kicks the alien, the alien's health is reduced by 5 points,
the same concept applies for the user. When the Aliens health drops below 40, the Alien retreats to the edge of the world, and throws na fruit at the enemy player. If the player is hit by the fruit, the player will lose 20 health points.
The frequency that the alien is able to deal damage to the player is limitied based on round. As the rounds increase, the frequency of the Aliens hits increase, dealing more health to the user making the game more competitive.

High Score:

High score has been implemented to drive competitiveness. The user should aim to beat their previous high score, which can provide a competitive nature to the game.



Origonality of Game Mechanics:

Some of the game mechanics have been able to provide some origonality. For example, increasing the aliens attack output as the rounds go along could be considered a mechanic which is more origonal instead of just increasing the damage that the alien does
to the other player. The player having to dodge fruit and ducking as some origonality to it (however it does build on previous game mechanics).


UML designs

<img width="1037" height="767" alt="image" src="https://github.com/user-attachments/assets/f7174386-ca2f-4d89-8839-5c31db1c59be" />

The UML design above is the less focused on the gameplay, but the surounding elements (Such as the instructions, high score screen, title screen). Game includes some of the definitions for the derived classes (for example, all of the classes use the render
font function).



Sample Screens



Test cases and expection

Main:

<img width="649" height="771" alt="image" src="https://github.com/user-attachments/assets/b01ffc48-c39d-40a1-a834-272bdafe4e95" />

Instructions/Story:

<img width="643" height="627" alt="image" src="https://github.com/user-attachments/assets/784940f1-25c1-4e9f-bc48-95bf1c98e2a5" />

Game Page:

<img width="498" height="709" alt="image" src="https://github.com/user-attachments/assets/1c754bc7-f791-426d-a505-442186b36333" />

Round Pages:

<img width="500" height="125" alt="image" src="https://github.com/user-attachments/assets/fdf2d260-a4dc-4657-90f5-dfe5e2b5e629" />

Game Over Pages:

<img width="647" height="569" alt="image" src="https://github.com/user-attachments/assets/1301a9cb-5eec-450f-abd0-4cbd1c90f6f2" />

Bullet:

<img width="552" height="776" alt="image" src="https://github.com/user-attachments/assets/3c9e9d04-1804-476a-95a6-8dacd7cdc38a" />




















































