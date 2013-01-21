mesh=MeshLoader:loadFromMgr("cube.msh");
scene=SceneNode();

entity1=Entity(mesh);
entity1:setPosition(1.0,0.5,-3)

entity2=Entity(mesh);
entity2:setPosition(-1.0,-1.15,-5)

entity3=Entity(mesh);
entity3:setPosition(-2.0,-0.3,0.1)

scene:addChild(entity1)
scene:addChild(entity2)

entity1:addChild(entity3)



angle_x=0;
angle_y=0;
angle_z=0;
--scene:scale(3.0,3.0,3.0)

function test_set_postion()
	angle_x=angle_x+0.1
	angle_y=angle_y+0.2
	angle_z=angle_z+0.3
	scene:setPosition(-2,2,0)
	scene:setRotateY(0)
	scene:draw(g_render);

	scene:setPosition(2,-2,0)
	scene:setRotateY(90)
	scene:draw(g_render);

	scene:setRotate(angle_x,angle_y,angle_z)

	entity1:setRotate(angle_y,angle_z,angle_x)
	entity2:setRotate(angle_z,angle_x,angle_y)
	
end

