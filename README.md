The code written for the Bunny Simulator project.

The code in the main meets all of the core requirements of the project, using a list of shared pointers pointing to bunny objects.
The bunnies can age, die, breed, spread an infection, and be culled, both automatically and by user input.
The code outputs a list of the bunnies each turn, sorted by age, as well as notifications for bunny births, deaths and cullings.
The code has been written to be as concise, robust, and efficient as possible, ensuring full randomness where appropriate.

In the manager class there are two versions of the aging function, of which aging_mk2() is in use. Both functions work equally well, but the second version is written in a more concise and sensible way.
There are also two versions of the cull function, of which cull_mk2() is in use. The original function is workable, but it does not produce a truely random culling. This is due to the correction step, where elements at the front of the array are changed to make the number of dead and surviving bunnies equal, which will result in an over or under dense region of deaths, unless the original distribution was perfect. The second version of the function uses a method inspired by the infect() function (which was written after the original cull() function), wherein a parallel vector of booleans of equal length to the list of bunnies is created, half filled with true and half with false, and then shuffled to ensure and used to pick which bunnies should be killed. This results in a far better random distribution, while still meeting the specification that exactly half die.


Additional features are contained in branches. At present, the active branches are:
FileOutput - Contains code in which all of the terminal outputs are stored to one file, and the turn totals are saved to another. (Uses an older version of the code as a base; some functions and visual outputs are not up to the standard found in the main. Proof of concept.)
RealTime - Changes the code to run in real time, where each turn there is a 2 second window for the user to enter commands, before it automatically moves on to the next turn. Delays have also been added to the culling, birth, and death outputs (replacing the system("pause") used previously) to allow the user to read them.
ManagerClass - Old branch used for developing the manager class, then merged into the main. Outdated and no longer in use.