# SME-Assignment

PART-2
**Bugs:**
1. first problem was to include all the headers file in include path settings of vs-code as the compiler is unable to locate those files.

2. In gameService.cpp  the GameService constructor, service_locator is not initialized to nullptr. This could potentially lead to undefined behavior if the destroy() method is called before ignite().

3. Inside ParticleService.cpp file  the getParticleSystemConfig() function, there is a missing default case in the switch statement. If particles_type does not match any of the cases, the function will not return a value, which will result in undefined behavior. It would be better to add a default case that throws an exception or returns a default value.

4. Inside ParticleSystem.cpp  the getParticleSystemConfig() function, there is a missing default case in the switch statement. If particles_type does not match any of the cases, the function will not return a value, which will result in undefined behavior. It would be better to add a default case that throws an exception or returns a default value.

Another bug  that is, the game has several modules (such as player, enemy, controller, and UI), but they are not interacting with each other. Additionally, there are no function calls or data flow between these modules. the possible causes of this issue can be:

Lack of Initialization: Ensure that all necessary components (player, enemy, controller, UI) are properly initialized before the game starts. If any module is missing initialization, it could prevent the game from launching.
Dependency Chain: Checking  if there is a dependency chain among the modules. For example:
The UI might depend on the controller to handle user input.

The controller might depend on the player and enemy modules for game logic.

The player and enemy modules might depend on each other for interactions.

Function Calls: Verify that essential functions (such as game loop, rendering, input handling) are being called. If any critical function is missing, it could lead to the game not starting.

Data Flow: Ensuring that data flows correctly between modules. For instance:
The player module should update its position and state based on user input.

The enemy module might need information from the player module (e.g., player position) to function properly.
Potential Fixes:
Here are some changes  that i did to address the issue:

Initialize All Modules: Make sure each module (player, enemy, controller, UI) is properly initialized during game startup. Checking for any missing initialization steps.

Establish Dependencies:
Defining clear dependencies between modules. For example:
The UI module depends on the controller.

The controller depends on the player and enemy modules.
Ensure that modules are aware of their dependencies and interact accordingly.

Implement Function Calls:
Set up a game loop that calls essential functions (e.g., update, render) for each module.
Verify that input handling functions are correctly linked to the controller.

Data Exchange:
Establish data exchange mechanisms:
Player module provides data (e.g., position, health) to other modules.

Enemy module receives relevant data from the player module.
Use appropriate data structures (e.g., structs, classes) to organize and share data.

PART-3
**In FireBullet.cpp**
With these changes, the player ship and each type of enemy (SubZero , ThunderSnake , and Zapper) will be able to fire their respective bullets with a short delay between each bullet. The bullets are stored in a vector for each entity.
