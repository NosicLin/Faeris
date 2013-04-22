
local scheduler=share:scheduler();
local director=share:director();
local render=share:render();
local window=share:window();

--local width=window:getWidth()
--local height=window:getHeight()
width=1025
height=800


--font=FontTTF:create("simsun.ttc",50)
--font=FontTTF:create("STXIHEI.TTF",50)
font=FontTTF:create("UbuntuMono-RI.ttf",18)
label1=LabelTTF:create("this is a good world",font);
label1:setPosition(200,300,0);
label1:rotateZ(30);
--label1:rotateX(90);
label1:setColor(Color(255,0,0))
--label1:setOpacity(0.5)

render:setViewport(0,0,width,height);
local proj_matrix=Matrix4()


print ("width:"..window:getWidth().." height:"..window:getHeight())
--proj_matrix:makeOrthographic(0,1,0,1,0,100)
--proj_matrix:makeOrthographic(0,1024,0,800,0,100)
--render:setProjectionMatrix(proj_matrix)

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

time=0;

str=0
scene1.data= {
	name="first Scene",
	line={},
	line_nu=0,

	onUpdate=function(scene,dt)
		--print("time:"..dt)
		scene:update(dt)
		time=time+1
		if time > 60 then 
			str=str+1
			--label1:setString(10);
			time=0
		end
	end,
}


touch_layer=ColorLayer:create()

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

fade_layer:setTouchEnabled(true);
--fade_layer:setVisible(false);


touch_layer.data={
	name="first Scene",
	line={},
	line_nu=0,
	onDraw=function(self,render)

		proj_matrix:makeOrthographic(0,1,0,1,0,100)
		render:setProjectionMatrix(proj_matrix)

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
touch_layer:setTouchEnabled(true);


entity_layer=Layer2D:create();
entity_layer:setViewArea(0,0,width,height);

cquad=ColorQuad2D:create(Rect2D(-10,-10,20,20),Color(255,255,0,255));
cquad2=ColorQuad2D:create(Rect2D(-200,-200,400,400),Color(0,255,255,30));
cquad2:setColor(Color(255,255,0),ColorQuad2D.VERTEX_A)
cquad2:setColor(Color(255,0,255),ColorQuad2D.VERTEX_B)
cquad2:setColor(Color(0,255,255),ColorQuad2D.VERTEX_C)
cquad2:setColor(Color(255,255,255),ColorQuad2D.VERTEX_D)

cquad:setOpacity(0.1)
cquad2:setOpacity(1.0);
cquad2.data={
	speed=0.1,
	onUpdate=function(self,dt) 
		self:rotateZ(self.data.speed)
	end
}
--cquad2:setPosition(0,300,0)

group=Entity:create();

group:addChild(cquad2);
group:addChild(cquad);


entity_layer.data={
	speed=0.1,
	onTouchBegin=function(self,x,y)
		x,y=self:toLayerCoord(x,y)
		group:setPosition(x,y,0)
		self.data.speed=0.1
		return false;
	end,
	onTouchMove=function(self,x,y)
		x,y=self:toLayerCoord(x,y)
		print ("x:"..x.." y:"..y)

		group:setPosition(x,y,0)
		self.data.speed=self.data.speed+0.1
		cquad2.data.speed=self.data.speed

		return false;
	end,
}
entity_layer:setTouchEnabled(true);
--cquad2:setPosition(120,200,0);

entity_layer:add(group);
entity_layer:add(label1);



print ("push");

scene1:push(touch_layer);
scene1:push(entity_layer);
scene1:push(fade_layer);


director:run(scene1);




