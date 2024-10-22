<img src="assets/images/banner.png">

# ploot
An absolutely barebones pngtuber tool.

---

# Usage
```shell
ploot.exe -c my_scene
```

```shell
ploot.exe -l "my_scene/my_scene.scene"
```
---

# Commands
```
-h, --help          |  displays this help page
-c, --create <NAME> |  creates a new scene
-l, --load <PATH>   |  loads a scene from a path
```

---

# Scene Configuration
```conf
sceneWidth=512
sceneHeight=512
sceneFramerate=10
sceneBackgroundColor=00FF00FF
```

---

# Sprite Configuration

```conf
spriteImagePath="my_image.png"
spritePosition=0.000000,0.000000

# Set spriteHeight to -1 if you want to preserve the image's aspect ratio
spriteSize=100.000000,-1

# Shake modes: smooth, noise
spriteShakeMode=noise

spriteShakeAmount=1.000000
spriteShakeKeyComboMultiplier=1.000000
spriteShakeLength=400.000000
spriteShakeRotationMinMax=-2.000000,2.000000
```