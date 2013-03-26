
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


scene1.data= {
	name="first Scene",
	line={},
	line_nu=0,

	onUpdate=function(scene,dt)
		--print("time:"..dt)
		scene:update(dt)
	end,
}


layer1=ColorLayer:create()
layer2=ColorLayer:create()

layer1.data={
	color=0;
	onUpdate=function(self,dt)
		self.data.color=self.data.color+dt/1000*60
		if self.data.color > 255 then 
			self.data.color =0
		end 
		c=self.data.color;
		layer1:setColor(Color(0,0,0,c));
	end,
}

layer1:setTouchEnabled(true);
--layer1:setVisible(false);


layer2.data={
	name="first Scene",
	line={},
	line_nu=0,
	onDraw=function(self,render)
		local lines=self.data.line
		v1=Vector3();
		v2=Vector3();
		for i=1,self.data.line_nu-1 do 
			local v_start=lines[i];
			local v_end=lines[i+1];
			v1:set(v_start[1],v_start[2],0);
			v2:set(v_end[1],v_end[2],0);
			render:drawLine(v1,v2,6,Color.RED)
		end
	end,
	onTouchBegin=function(self,x,y)
		self.data.line_nu=0
		self.data.line={}
	end,
	onTouchMove=function(self,x,y)
		local line_nu=self.data.line_nu
		self.data.line[line_nu+1]={x,y}
		self.data.line_nu=line_nu+1
	end,
}
layer2:setTouchEnabled(true);

scene1:push(layer2);
scene1:push(layer1);


director:run(scene1);




