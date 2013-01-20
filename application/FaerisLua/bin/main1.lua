
g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")


g_render:setClearColor(Color(0,0,0))
g_render:clear(true)
g_render:swapBuffers()
g_render:setViewport(0,0,1024,800)
g_frame:setFPS(0)

mat=Matrix4()
mat:makeFrustum(-5,5,-5,5,12,100);
g_render:setProjectionMatrix(mat);


mesh=MeshLoader:loadFromMgr("cube.msh");

g_render:clear(true)
mesh:draw(g_render);
g_render:swapBuffers();
local function onFrameEnd(diff)
	print( "update"..diff.."FPS:"..g_frame:getAvgFPS())

	g_render:clear(true)
	g_render:drawLine( Vector3(0,0,0), Vector3(10,10,10), 2, Color(255,255,0))
--	mesh:draw(g_render);
	g_render:swapBuffers();
end


g_render:translate(Vector3(0,0,-13))

local function onFrameUpdate(diff)

	local x_rotate=20*(diff/1000.0)
	local y_rotate=10*(diff/1000.0)
	local z_rotate=5*(diff/1000.0)

	mat=Matrix4();
	mat:makeRotateFromEuler(x_rotate,y_rotate,z_rotate,FS.EULER_XYZ);
	g_render:mulMatrix(mat);
end

frame_listener=FrameListener()


frame_listener:registerUpdateFunc(onFrameUpdate)
frame_listener:registerEndFunc(onFrameEnd)


g_frame:addListener(frame_listener);


