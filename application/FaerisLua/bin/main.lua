local director=share:director();


local render=share:render();
render:setClearColor(Color.BLACK)

scene= Scene:create();

layer=Layer2D:create();

layer:setViewArea(0,0,1024,800)


font=FontTTF:create("UbuntuMono-RI.ttf",50)
label1=LabelTTF:create("This Is A Good World",font);
label1:setPosition(200,300,0);


layer:add(label1);


sprite=Sprite2D:create("Boy.fst");
sprite:setPosition(400,500,0);
sprite:setAnimation("walk");
sprite:playAnimation();

layer:add(sprite);




scene:push(layer);
director:run(scene);

