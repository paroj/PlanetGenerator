/* The MIT License (MIT)
 * 
 * Copyright (c) 2015 Giovanni Ortolani, Taneli Mikkonen, Pingjiang Li, Tommi Puolamaa, Mitra Vahida
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE. */

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <Ogre.h>
#include "ObjectInfo.h"
#include <vector>

struct CheckCollisionAnswer
{
	bool				collided;
	std::string			objectName;
	int					amount; //how many object have collided with this one
	std::vector<std::ObjectInfo>	collidedList;
};

class CollisionManager
{
public:
	CollisionManager(std::vector<std::ObjectInfo> *Obs,Ogre::Camera *cam);

	std::vector<std::ObjectInfo> *Objects;
	
	CheckCollisionAnswer checkCollisionAABB(std::ObjectInfo object);

	CheckCollisionAnswer checkCameraCollision();

private:
	Ogre::Camera            *camera;
};

#endif