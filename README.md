# Missile-Command
Clasic game with redesigned graphics that retain the original gameplay mechanics. Players defend a city from incoming missiles using a limited supply of ammunition. The game provides a fresh visual experience while preserving the core essence of the classic game.

![image](https://github.com/GottaWorkM8/Missile-Command/assets/74871534/c14f9496-e4c9-40e6-bf9e-6ef5c40d8ce2)
Menu image

![image](https://github.com/GottaWorkM8/Missile-Command/assets/74871534/9a2dd863-c17a-4511-a672-2d93c3919d02)
Game image

Threads:
std::thread gameThread = std::thread(Game::Run, diff); - Thread which starts game.
std::thread thread = std::thread(AnimateButton, std::ref(topLeft), std::ref(hovered)); - Create animation thread. 
std::thread missilesThread(HandleMissiles); - Missiles thread.
std::thread explosionsThread(HandleExplosions); - Explosions thread.
std::thread bombsThread(HandleBombs); - Bombs thread.
std::thread flashesThread(HandleFlashes); - Flashes thread.
std::thread destructionsThread(HandleDestructions); - Desctructions thread;
thread = std::thread(&Intro::AnimateIntro, this); - Animation intro thread.
std::thread soundThread([filepath]() {PlaySoundA(filepath.c_str(), NULL, SND_FILENAME | SND_ASYNC);}); - Sound thread.
std::thread waitingThread = std::thread(WaitForReady); - Waiting thread.

Mutexs:
std::mutex launcherMutex;
std::mutex buildingsMutex;
std::mutex missilesMutex;
std::mutex bombsMutex;
std::mutex explosionsMutex;
std::mutex destructionsMutex;
std::mutex flashesMutex;
