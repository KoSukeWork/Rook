# Rook v 0.0.5
*"This is the journey into sound, sound sculpture in space"*
##Rook - Audio plugin for Unreal 4
Rook is simple audio plugin for Unreal 4 Engine which usese OpenAL Soft for 3D sounds and Unreal 4 Audio Component for multichannel.
Project itself will be develop over time and main focus on:
- Usebility - a KISS method (Keep It Simple Stupid). So every new feature can be access via C++ or Blueprints (no coding skill requierd)
- Optimization - memory and CPU usage is very imporatant
- Nowdays features

##Quick Setup
If You want to start working with Rook just grab latest version and under Your project place it under Plugins Folder (ex. MyProject/Plugins) - if You don't have one just create it. Thats it. Rook is already configurated to be enabled by default. 
######!Imporatant
- Rook comes only with OpenAL Soft version 1.17.2 for Win **64bit** version. If You want to used it on Win32, Linux or Mac grab source from [OpenAl Soft git](http://repo.or.cz/w/openal-soft.git).
- Remember: if You want to make it work in **Shipped** version of Your project, You need to place OpenAL Soft DLL under: *UE4\Engine\Binaries\ThirdParty\OpenAL\1.17.2* and proper folder for Win64, Win32, Linux or Mac

##Documentation
Documentation is included within project

##TODO

##ChangeLog

##Whats up with coding style
You may noticed that Rook code style is different than Epic one. I used to work with Epic code style, however while trying to improve me code style/standard I have encounter idSoftware Doom 3 source code break down and discussion on several web sites. So when it's better time to adapt it if not Your first public open source project, right ? I am still on my journey to improve myslef so it may change. 

## License
GNU GPLv3