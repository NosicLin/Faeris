
local scheduler=share:scheduler();
local director=share:director();
local render=share:render();

render:setClearColor(Color.BLACK)

scene2=Scene:create()
scene1=Scene:create();


scene2.data={
	onDraw=function(scene,render)
		render:drawLine(Vector3(0.0,0.0,0),Vector3(1.0,0.0,0),1,Color(0,255,0))
		render:drawLine(Vector3(0.0,0.0,0),Vector3(0.0,1.0,0),1,Color(255,0,0))
		render:rotate(Vector3(0,0,1),0.1)
		scene:draw(render);
	end,

	onTouchBegin=function(scene,x,y)
		print ("x:"..x.." y:"..y)
		director:run(scene1)
	end
}


scene1.data= {
	name="first Scene",
	onUpdate=function(scene,dt)
--		print("time:"..dt)
		scene:update(dt)
	end,
	onDraw=function(scene,render)
		render:drawLine(Vector3(0.0,0.0,0),Vector3(1.0,0.0,0),1,Color(255,0,0))
		render:drawLine(Vector3(0.0,0.0,0),Vector3(0.0,1.0,0),1,Color(0,255,0))
		render:rotate(Vector3(0,0,1),0.1)
		scene:draw(render);
	end,

	onEnter=function(scene)
		print(scene.data.name);
		scene:enter();
	end,
	onTouchBegin=function(scene,x,y)
		print ("x:"..x.." y:"..y)
		director:run(scene2)
	end

}
director:run(scene1);

