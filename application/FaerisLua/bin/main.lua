local director=share:director();
local render=share:render();
render:setViewport(0,0,1024,800);


local render=share:render();
render:setClearColor(Color.BLACK)

scene= Scene:create();

layer=Layer2D:create();

layer:setViewArea(-400,-400,1024,800)


font=FontTTF:create("simsunb.ttf",50)
label1=LabelTTF:create("This Is A Good World",font);
label1:setPosition(200,300,0);


layer:add(label1);


sprite=Sprite2D:create("Boy.fst");
sprite:setPosition(100,100,0);
sprite:setAnimation("walk");
sprite:playAnimation();

layer:add(sprite);




scene:push(layer);
director:run(scene);

