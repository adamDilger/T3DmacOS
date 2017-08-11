# T3DmacOS
An OSX XCode implementation of the T3D Graphics Engine

# Issues
1. No Sound (simple fix)
2. Not all keyboard keys work
3. Some lines of code regarding Transform need to be checked
   1. line 61 commented out : Bone.cpp <transform.setLocalRotation>
   2. line 30 edited : SweepPath.cpp <transform.setLocalRotation>
4. Resources have to have the absolute filepath in order to load correctly

# Installation
1. Move all contents of the Frameworks directory to /Library/Frameworks/ (use Ctrl+shift+G in finder to find this folder)
2. Add your resource directory path to the project
   1. In XCode, select Find->Find and replace in Project.
   2. Copy YOUR_RESOURCE_PATH into the find field and hit enter.
   3. Add your path to the /MacOSGLApplication/Resource directory. Make sure to add both the start and end slashes!
   4. Hit Replace All!

eg. I copied the resources directory to my home directory in order to make it easier to reference.
  
<img src="find_replace.jpeg" alt="Drawing" style="width: 50px"/>
