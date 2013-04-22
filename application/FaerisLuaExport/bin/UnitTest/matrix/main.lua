--void test translate 

dofile("draw_aux.lua");
g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")


g_render:setClearColor(Color(0,0,0))
g_render:clear(true)
g_render:swapBuffers()
g_render:setViewport(0,0,1024,800)
g_frame:setFPS(0)

mat=Matrix4()
mat:makeOrthographic(-100,100,-100,100,0,100);
g_render:setProjectionMatrix(mat);


g_render:clear(true)

local function onFrameEnd(diff)

	g_render:clear(true)
	--g_render:loadIdentity()

	--mat:makeIdentity();
	mat:scale(0.5,0.5,0.5);
--	g_render:setMatrix(mat);

	--g_render:scale(Vector3(0.5,0.5,0.5));

	draw_coord()
	g_render:swapBuffers();
end


g_render:translate(Vector3(0,0,-13))

local function onFrameUpdate(diff)
end

frame_listener=FrameListener()


frame_listener:registerUpdateFunc(onFrameUpdate)
frame_listener:registerEndFunc(onFrameEnd)


g_frame:addListener(frame_listener);


