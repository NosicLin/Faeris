
g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")


g_render:setClearColor(Color(255,255,255))
g_render:clear(true)
g_render:swapBuffers()
g_render:setViewport(0,0,1024,800)
g_frame:setFPS(60)


gm=GeometryLoader:loadFromMgr("cube.gry");

local function onFrameEnd(diff)
	print("time "..diff.." FPS"..g_frame:getAvgFPS())
	g_render:clear(true)
	g_render:swapBuffers();
end


g_render:scale(Vector3(0.5,0.5,0.5))

local function onFrameUpdate(diff)
	local x_rotate=20*(diff/1000.0)
	local y_rotate=10*(diff/1000.0)
	local z_rotate=5*(diff/1000.0)
	g_render:rotate(Vector3(1,0,0),x_rotate)
	g_render:rotate(Vector3(0,1,0),y_rotate)
	g_render:rotate(Vector3(0,0,1),z_rotate)
end

frame_listener=FrameListener()


frame_listener:registerUpdateFunc(onFrameUpdate)
frame_listener:registerEndFunc(onFrameEnd)


g_frame:addListener(frame_listener);


