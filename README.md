项目简介
-------
国家大学生电子设计竞赛嵌入式邀请赛作品

该作品提供给使用者进行交互式的家居设计，利用手势交互指环对场景内的家具模型进行操控、摆放。

这部分代码是该系统的软件部分，类似于一个第一人称的3D游戏，基于irrlicht引擎，ARToolkit库。

![all](http://yikun.github.io/assets/pic/design/all.png)

系统环境
-------
Ubuntu 12.04 LTS(Desktop)
Linux Yocto(Embeded System)

安装依赖库
-------
sudo apt-get install build-essential freeglut3-dev qt4-dev-tools qt4-doc qt4-qtconfig qt4-demos qt4-designer qtcreator xorg-dev glutg3-dev libxxf86vm-dev libjpeg8 libjpeg8-dbg libjpeg8-dev

操作说明
-------
+ 虚拟现实场景 

![ar](http://yikun.github.io/assets/pic/design/ar.png)
虚拟现实场景可以将房屋的外景展示给使用者。

+ 室内设计场景
![scene](http://yikun.github.io/assets/pic/design/scene.png)
进入室内设计场景后，你也可以利用下面的键盘按键对家具进行操作。
	
	- 视角控制

	I : 向前移动视角
	K : 向后移动视角
	J : 向左移动视角
	L : 向右移动视角
	M : 向下移动视角
	U : 向上移动视角
	O : 恢复主视角

	家具操控

	N : 新建家具
	Y : 摆放家具
	W : 向前移动家具
	S : 向后移动家具
	A : 向左移动家具
	D : 向右移动家具
	Q : 向上移动家具
	Z : 向下移动家具
	'+' : 放大家具尺寸 
	'-' : 缩小家具尺寸
	X : 顺时针旋转家具
	C : 逆时针旋转家具
	E : 前一个家具
	R : 后一个家具

实际效果
---

![actual](yikun.github.io/assets/pic/design/actual.PNG)
