local director=share:director();
local render=share:render();
local wind=share:window();

--wind:setSize(1025,800)
--render:setViewport(0,0,1024,800);


local render=share:render();
render:setClearColor(Color.BLACK)

scene= Scene:create();

layer=Layer2D:create();

layer:setViewArea(-400,-400,1024,800)


sprite=Sprite2D:create("interface.fst");
sprite:setPosition(100,100,0);
sprite:setAnimation("anim0");
sprite:playAnimation();

--sprite:setRotateX(180)

layer:add(sprite);

sprite2=Sprite2D:create("Boy.fst");
sprite2:setPosition(200,100,0);
sprite2:setAnimation("run");
sprite2:playAnimation();

sprite3=Sprite2D:create("dragon.fst");
sprite3:setPosition(-300,-400,0);
sprite3:setAnimation("default");
sprite3:playAnimation();
sprite3:setRotateY(180);
--sprite3:setColor(Color(255,0,255));
--sprite3:setOpacity(0.5);
--
--sprite3:setScale(0.5,0.5,1);

--sprite3:setRotateZ(90);
layer:add(sprite3);

sprite3:addChild(sprite2);

layer:setTouchEnabled(true);
layer.data={
	onTouchMove=function (self,x,y)
		x,y=self:toLayerCoord(x,y);
		sprite3:setPosition(x,y,0);
	end,
}


scene:push(layer);
director:run(scene);













