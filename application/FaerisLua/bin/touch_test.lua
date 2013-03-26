
local scheduler=share:scheduler();
local director=share:director();
local render=share:render();
local window=share:window();
local width=window:getWidth()
local height=window:getHeight()


render:setViewport(0,0,width,height);
local proj_matrix=Matrix4()


print ("width:"..window:getWidth().." height:"..window:getHeight())
proj_matrix:makeOrthographic(0,1,0,1,0,100)
--proj_matrix:makeOrthographic(0,1024,0,800,0,100)
render:setProjectionMatrix(proj_matrix)

render:setClearColor(Color.BLACK)

scene2=Scene:create()
scene1=Scene:create();

touch_dispatcher=share:touchDispatcher();
sys_dipatcher=share:sysDispatcher();

sys_listener=SysEventListener:create();
sys_listener.data={
	onForeground=function(l)
		print("onForeground");
	end,

	onBackground=function(l)
		print("onBackground")
	end,

	onQuit=function(l)
		print("onQuit")
		scheduler:stop()
	end,

	onExit=function(l)
		print("onExit")
	end 
}
sys_dipatcher:addEventListener(sys_listener)



l=TouchEventListener:create();
l.data={
	onTouchBegin=function(listener,x,y)
		print ("listener begin :".."x:"..x.." y:"..y)
	--	touch_dispatcher:removeEventListener(l);
	end,
	onTouchMove=function(listener,x,y)
		print ("listener move :".."x:"..x.." y:"..y)
	end,
	onTouchEnd=function(listener,x,y)
		print ("listener end :".."x:"..x.." y:"..y)
		touch_dispatcher:removeEventListener(l);
	end
}

touch_dispatcher:addEventListener(l)






scene2.data={
	angle=0,
	onDraw=function(scene,render)

		render:pushMatrix();
		render:drawLine(Vector3(0.0,0.0,0),Vector3(width,0.0,0),1,Color(0,255,0))
		render:drawLine(Vector3(0.0,0.0,0),Vector3(0.0,height,0),1,Color(255,0,0))
		scene.data.angle=scene.data.angle+0.1
		render:rotate(Vector3(0,0,1),scene.data.angle)
		scene:draw(render);
		render:popMatrix();
	end,

	onTouchBegin=function(scene,x,y)
		print ("x:"..x.." y:"..y)
		director:run(scene1)
	end
}


scene1.data= {
	name="first Scene",
	line={},
	line_nu=0,

	onUpdate=function(scene,dt)
		--print("time:"..dt)
		scene:update(dt)
	end,

	onDraw=function(scene,render)
		--print("lines_nu:"..scene.data.line_nu)
		local lines=scene.data.line
		v1=Vector3();
		v2=Vector3();
		for i=1,scene.data.line_nu-1 do 
			local v_start=lines[i];
			local v_end=lines[i+1];
			v1:set(v_start[1],v_start[2],0);
			v2:set(v_end[1],v_end[2],0);
			render:drawLine(v1,v2,6,Color.RED)
		end
		--render:drawLine(Vector3(0,0,0),Vector3(width,height,0),1,Color(255,0,0));
		--collectgarbage()
	end,

	onEnter=function(scene)
		print(scene.data.name);
		scene:enter();
	end,

	onTouchBegin=function(scene,x,y)
		print("begin x:"..x.." y:"..y)
		scene.data.line_nu=0
		scene.data.line={}
	end,
	onTouchMove=function(scene,x,y)
		print("move x:"..x.." y:"..y)
		local line_nu=scene.data.line_nu
		scene.data.line[line_nu+1]={x,y}
		scene.data.line_nu=line_nu+1
	end,

	onTouchEnd=function(scene,x,y)
		print ("end x:"..x.." y:"..y)
	end

}
director:run(scene2);




