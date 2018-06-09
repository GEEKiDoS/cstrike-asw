@echo off

set GameDir=%~dp0
set GameDir=%GameDir:~0,-1%
"J:\SteamLibrary\steamapps\common\Alien Swarm\swarm.exe" -game %GameDir% -console -sw -h 900 -w 1600 -condebug