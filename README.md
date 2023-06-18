# Missile-Command
Classic game with redesigned graphics that retain most of the original gameplay mechanics. Players defend a city from incoming bombs using a limited supply of ammunition. The game provides a fresh visual experience while preserving the core essence of the classic game.
<br><br>

![image](https://github.com/GottaWorkM8/Missile-Command/assets/74871534/c14f9496-e4c9-40e6-bf9e-6ef5c40d8ce2)
*Game menu*
<br><br>

The menu options are as follows: <br> 
"Continue" starts the game from the highest ever reached level, <br> 
"New Game" starts a fresh game, from the very first level, <br> 
"Help" provides information about game objects, <br> 
"Exit" allows you to leave the game. 
<br><br> 

![351693105_143223785394990_5016415596778798039_n](https://github.com/GottaWorkM8/Missile-Command/assets/74871534/08e7152f-3951-4048-bd6c-5e46d492994e)
*Level introduction*
<br><br>

![351757141_1429427944576513_6104141163336765603_n](https://github.com/GottaWorkM8/Missile-Command/assets/74871534/6cbafe52-6fab-419b-9646-96d14c134ab1)
*Gameplay*
<br><br>

Gameplay is based around shooting fast missiles at incoming bombs that create explosions damaging bombs. Bombs can be destroyed creating explosions and potentially damaging other bombs.
It is important to note that explosions are harmful to the city's infrastructure. If any structure on the surface gets destroyed player has his points cut by a significant amount, 
which can make winning the game difficult. Even if no structure gets damaged player still gains minus points for letting any bomb hit the ground. Destroying bombs in the air awards positive points.
<br><br>

![351963711_275261985157038_6617687931602139723_n](https://github.com/GottaWorkM8/Missile-Command/assets/74871534/b6768de6-0c58-4b45-be70-32b2445f6cb3)
*Paused game*
<br><br>

It is possible to pause the game at any time (after initial introduction) by pressing Esc key. Resuming the game is also done by pressing the same key. From the pause menu there is an option to go back to the menu (left button), replay the level from the beginning (middle button) or go to the next level, if it has been unlocked in the past by beating the current level (right button).
<br><br>

Threads used in the whole application: <br>
std::thread gameThread = std::thread(Game::Run, diff); - Handles the game loop <br>
std::thread thread = std::thread(AnimateButton, std::ref(topLeft), std::ref(hovered)); - Animates the button upon hovering <br>
std::thread missilesThread(HandleMissiles); - Handles missiles <br>
std::thread explosionsThread(HandleExplosions); - Handles explosions <br>
std::thread bombsThread(HandleBombs); - Handles bombs <br>
std::thread flashesThread(HandleFlashes); - Handles flashes after every missile shot <br>
std::thread destructionsThread(HandleDestructions); - Handles destructions (structure collapse) <br>
std::thread thread = std::thread(&Intro::AnimateIntro, this); - Animates the introduction at the start of every level <br>
std::thread soundThread(filepath() {PlaySoundA(filepath.c_str(), NULL, SND_FILENAME | SND_ASYNC);}); - Handles playing of the audio file <br>
std::thread waitingThread = std::thread(WaitForReady); - Waits for the value change <br>

Mutexes: <br>
std::mutex launcherMutex; - Locks the launcher object <br> 
std::mutex buildingsMutex; - Locks the list of buildings <br>
std::mutex missilesMutex; - Locks the list of missiles <br>
std::mutex bombsMutex; - Locks the list of bombs <br>
std::mutex explosionsMutex; - Locks the list of explosions <br>
std::mutex destructionsMutex; - Locks the list of destructions (structure collapse) <br>
std::mutex flashesMutex; - Locks the list of flashes after every missile shot <br>
