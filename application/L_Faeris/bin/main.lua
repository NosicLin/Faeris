local director =share:director();
local render=share:render()
local scheduler=share:scheduler()
--scheduler:setFps(60)

--director:setAutoSwapBuffers(false);


-- create layer */
local layer= Layer2D:create();
layer:setViewArea(0,0,960,640)


local quad2d= Quad2D:create("dog.png")
quad2d:setPosition(500,500,0)

quad2d:setScale(2,2,1)
quad2d.data={
	onUpdate=function(self,dt)
		self.x=self.x+6
		if self.x > 960 then 
			self.x =0 
		end 
		self:setPosition(self.x,480)
	end,
	x=0,
	speed=0.1
}

layer:add(quad2d)

local scene=Scene:create()
scene.data={
	onUpdate=function(self,dt) 
		self:update(16)
		if dt>18 or dt< 16 then 
			print("dt="..dt)
		end

	end
}



scene:push(layer)


director:run(scene);










