local director =share:director();
local render=share:render()
local scheduler=share:scheduler()

local layer= Layer2D:create();
layer:setViewArea(0,0,1024,800)

local c_quad=ColorQuad2D:create(Rect2D(-100,-100,200,200),Color.RED)
c_quad:setPosition(500,400,0)

local c_quad1=ColorQuad2D:create(Rect2D(-100,-100,200,200),Color.RED)
c_quad1:setPosition(200,200)

local quad2d=Quad2D:create("tree2.png")
quad2d:setPosition(700,300)

layer:add(c_quad)
layer:add(c_quad1)
layer:add(quad2d)

local scene=Scene:create()


scene:push(layer)

director:run(scene);


