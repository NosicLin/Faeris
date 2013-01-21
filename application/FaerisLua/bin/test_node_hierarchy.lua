g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")

g_render:setClearColor(Color(0,0,0))
g_render:clear(true)
g_render:swapBuffers()
g_render:setViewport(0,0,1024,800)
g_frame:setFPS(60)

mat=Matrix4()
mat:makeOrthographic(-1000,1000,-1000,1000,1,10000);
--mat:makeFrustum(-1000,1000,-1000,1000,1,10000);
g_render:setProjectionMatrix(mat);


g_render:clear(true)
g_render:translate(Vector3(0,0,-1000))




function init()
	mesh=MeshLoader:loadFromMgr("cube.msh")
	group=SceneNode();
	for i=1,200 do 
		entity=Entity:new(mesh)
		x=Math.random(-1000,1000)
		y=Math.random(-1000,1000)
		z=Math.random(-1000,1000)
		entity:setPosition(x,y,z);
		entity:scale(80,80,80)

		x=Math.random(0,360)
		y=Math.random(0,360)
		z=Math.random(0,360)
		entity:setRotate(x,y,z)
		group:addChild(entity)
	end

	scene=SceneNode()
	scene:addChild(group)
end 


local function onFrameEnd(diff)
	print( "update"..diff.."FPS:"..g_frame:getAvgFPS())

	g_render:clear(true)
	scene:draw(g_render);
	g_render:swapBuffers();
end

init()

g_render:translate(Vector3(0,0,-4))

scale=1
scale_diff=0.001

local function onFrameUpdate(diff)

	if scale>1 then 
		scale_diff=-0.001
	elseif scale<0.3 then 
		scale_diff=0.001 
	end 
	scale=scale+scale_diff

	scene:rotate(0.1,0.2,0.3)
	scene:setScale(scale,scale,scale)

end

frame_listener=FrameListener()


frame_listener:registerUpdateFunc(onFrameUpdate)
frame_listener:registerEndFunc(onFrameEnd)


g_frame:addListener(frame_listener);

