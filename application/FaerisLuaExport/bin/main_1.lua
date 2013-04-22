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




scene=Scene:create();

layer=Layer2D:create();
layer:setViewArea(-200,-200,width,height);

layer2=Layer2D:create();
layer2:setViewArea(0,0,width,height);

ground=Quad2D:create("bg.png");
ground:setPosition(width/2,height/2,0);

tr1=Quad2D:create("tree.png");
tr1:setPosition(100,100,0);
tr1:setColor(Color(255,0,0));

tr1:setRect2D(Rect2D(-50,-50,100,100));


tr2=Quad2D:create("tree.png");
tr2:setPosition(200,200,0)
tr2:setColor(Color(0,255,0))
tr2.data={
	onUpdate=function(self,dt)
		self:rotateZ(0.5)
	end
}
rect=tr2:getRect2D();
rect.x=0;
rect.y=0;
tr2:setRect2D(rect);



tr3=Quad2D:create("tree.png");
tr3:setPosition(300,200,0)
tr3:setColor(Color(0,0,255));
tr3.data={
	onUpdate=function(self,dt)
		self:rotateZ(1)
	end
}


tr4=Quad2D:create("tree.png");
tr4:setPosition(500,100,0);
tr4:setOpacity(0.5)
tr4.data={
	onUpdate=function(self,dt)
		self:rotateZ(0.2)
	end
}

tr5=Quad2D:create("tree.png");
tr5:setPosition(400,400,0)
tr5:setColor(Color(255,0,255,100));


layer2:add(ground);
layer:add(tr1);
layer:add(tr2);
layer:add(tr3);
layer:add(tr4);
layer:add(tr5);

fade_layer=ColorLayer:create()
fade_layer.data={
	color=0;
	onUpdate=function(self,dt)
		self.data.color=self.data.color+dt/1000*60
		if self.data.color > 255 then 
			self.data.color =0
		end 
		c=self.data.color;
		fade_layer:setColor(Color(0,0,0,c));
	end,
}


scene:push(layer2);
scene:push(layer);
scene:push(fade_layer);

director:run(scene);




